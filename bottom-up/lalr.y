%output  "lalr.cxx"
%defines "lalr.hxx"

%skeleton "lalr1.cc"
%require "3.0"

%parse-param {yy::scanner* scanner}

%language "c++"

%locations
%define parse.error verbose
%define parse.assert

%define api.value.type variant

%code requires {
    #include "abstract_tree.h"
    #include "location.hh"

    namespace yy {
        class scanner;
    };
}

%code {
    #include <memory>
    #include <vector>
    #include <string>
    #include <iostream>     // cerr, endl
    #include <utility>      // move
    #include <sstream>

    #include "scanner.h"
    #include "code_generator.h"

    #undef yylex
    #define yylex scanner->lex

    Program root;
}

%type <DecList> decl_list
%type <VarDec> decl_stmt
%type <StmtList> body
%type <VarDec> parameter
%type <DecList> param_list
%type <DecList> super_param_list
%type <std::vector<std::string>> id_list
%type <Type> data_type
%type <Type> array_nont
%type <StmtList> stmt_list
%type <StmtPtr> super_stmt
%type <StmtPtr> label_stmt
%type <StmtPtr> stmt
%type <StmtPtr> attr_stmt
%type <StmtPtr> proc_stmt
%type <StmtPtr> if_stmt
%type <StmtList> else_stmt
%type <StmtPtr> stop_stmt
%type <StmtPtr> io_stmt
%type <StmtPtr> control_stmt
%type <StmtPtr> goto_stmt
%type <StmtPtr> loop_stmt
%type <StmtPtr> exit_stmt
%type <ExprPtr> expr
%type <ProList> proc_decl_list
%type <ProDec> proc_decl
%type <Literal> literal
%type <ExprList> array_access
%type <ExprList> expr_list
%type <bool> skip_stmt
%token START
%token END
%token DECLARE
%token PROCEDURE 
%token INT_TYPE
%token FLOAT_TYPE
%token CHAR_TYPE
%token ARRAY
%token OF 
%token <std::string> IDENTIFIER
%token <int> INTEGER
%token <double> FLOAT
%token <char> CHAR
%token IF
%token THEN
%token ENDIF
%token ELSE
%token GOTO 
%token LOOP
%token ENDLOOP
%token EXITWHEN
%token STOP 
%token GET
%token PUT
%token SKIP 
%token ATTR_SIGN
%token DIFF_SIGN
%token GREATER_EQ_SIGN
%token LESS_EQ_SIGN 
%left '&' '|'
%left '>' '<' '=' DIFF_SIGN LESS_EQ_SIGN GREATER_EQ_SIGN
%left '+' '-'
%left '*' '/' '%'
%nonassoc '!' 
%right UMINUS

%%
program: decl_list proc_decl_list body {
    root.var_dec = $1;
    root.pro_dec = $2;
    root.stmts = $3;
    std::cout << root << std::endl;
    generateCode(root);
}

body: START ';' stmt_list END ';' {
    $$ = $3;
}

decl_list: %empty { $$ = DecList(); } |
    decl_list decl_stmt ';' {
        DecList a = $1;
        a.push_back($2);

        $$ = a;
    } 
    | decl_list DECLARE error ';'
;

decl_stmt: DECLARE '(' id_list ')' data_type {
    VarDec vd;
    vd.ids = $3;
    vd.type = $5;
    $$ = vd;
};

proc_decl_list: %empty { $$ = ProList(); }
    | proc_decl_list proc_decl ';' {
        ProList pl = $1;
        pl.push_back($2);   
        $$ = pl;
    }
;

proc_decl: IDENTIFIER ':' PROCEDURE '(' super_param_list ')' ';' stmt_list END IDENTIFIER {
    ProDec pd;
    pd.id = $1;
    pd.params = $5;
    pd.stmts = $8;
    $$ = pd;
    } | IDENTIFIER error ';' stmt_list END IDENTIFIER {
        $$ = ProDec();
    }
    ;

data_type: INT_TYPE  {
        Type type;
        type.type = SimpleType::ST_INT;
        $$ = type;
    } 
    | FLOAT_TYPE {
        Type type;
        type.type = SimpleType::ST_FLOAT;
        $$ = type;
    }
    | CHAR_TYPE  {
        Type type;
        type.type = SimpleType::ST_CHAR;
        $$ = type;
    }
    | array_nont {
        $$ = $1;
    }
;

array_nont: ARRAY '[' expr ']' OF data_type {
    Type type;
    type.type = $6.type;
    type.dimensions = $6.dimensions;
    type.dimensions.push_front($3);
    $$ = type;
};

super_param_list: %empty {$$ = std::vector<VarDec>(); } 
    | param_list {$$ = $1;}
;

param_list: parameter {
        std::vector<VarDec> pl;
        pl.push_back($1);
        $$ = pl;
    }
    | param_list ',' parameter {
        auto pl = $1;
        pl.push_back($3);
        $$ = pl;
    }
;

parameter: '(' id_list ')' data_type {
        VarDec vd; 
        vd.ids = $2;
        vd.type = $4;
        $$ = vd;
    }
    | IDENTIFIER data_type {
        VarDec vd;
        vd.ids.push_back($1);
        vd.type = $2;
        $$ = vd;
    }
;

id_list: IDENTIFIER {
        std::vector<std::string> s;
        s.push_back($1);
        $$ = s;
    }
    | id_list ',' IDENTIFIER {
        std::vector<std::string> s = $1;
        s.push_back($3);
        $$ = s;
    };

stmt_list: %empty { $$ = StmtList(); }
	| stmt_list super_stmt ';' { 
		StmtList a = $1;
		a.push_back($2);
		$$ = a;
    }
	| stmt_list error ';'
	
super_stmt: label_stmt {$$ = $1;} | stmt {$$ = $1;} ;

label_stmt: IDENTIFIER ':' stmt {
	StmtPtr a = $3;
	a->label = $1;
	$$ = a;
};

stmt: attr_stmt {$$ = $1;} | proc_stmt {$$ = $1;} | stop_stmt {$$ = $1;} | io_stmt {$$ = $1;} | control_stmt {$$ = $1;} ;

attr_stmt: IDENTIFIER array_access ATTR_SIGN expr {
    AttrStmt attr;
    attr.id = $1;
    attr.lhsIndexes = $2;
    attr.rhs = $4;
    $$ = std::make_shared<AttrStmt>(attr);
};

control_stmt: if_stmt {$$ = $1;}
    | goto_stmt {$$ = $1;}
    | loop_stmt {$$ = $1;}
    | exit_stmt {$$ = $1;};

if_stmt: IF expr THEN stmt_list else_stmt ENDIF {
    IfStmt is;
    is.expr = $2;
    is.trueBlock = $4;
    is.falseBlock = $5;
    $$ = std::make_shared<IfStmt>(is);
};

else_stmt: ELSE stmt_list { $$ = $2; }
         | %empty { $$ = StmtList(); };

goto_stmt: GOTO IDENTIFIER {
    GotoStmt gs;
    gs.id = $2;
    $$ = std::make_shared<GotoStmt>(gs);
};

loop_stmt: LOOP ';' stmt_list ENDLOOP {
    LoopStmt ls;
    ls.block = $3;
    $$ = std::make_shared<LoopStmt>(ls);
};

exit_stmt: EXITWHEN expr {
    ExitStmt es;
    es.expr = $2;
    $$ = std::make_shared<ExitStmt>(es);
};

stop_stmt: STOP { $$ = std::make_shared<Stmt>(Stmt("Stop")); };

io_stmt: GET '(' id_list ')' {
        GetStmt gs;
        gs.ids = $3;
        $$ = std::make_shared<GetStmt>(gs);
    }
    | PUT skip_stmt '(' expr_list ')' {
        PutStmt ps;
        ps.skip = $2;
        ps.exprs = $4;
        $$ = std::make_shared<PutStmt>(ps);
    };

skip_stmt: SKIP { $$ = true; }
    | %empty { $$ = false; };

proc_stmt: IDENTIFIER '(' expr_list ')' {
    ProcStmt ps;
    ps.id = $1;
    ps.args = $3;
    $$ = std::make_shared<ProcStmt>(ps);
};

expr_list: %empty { $$ = ExprList(); }
       | expr_list ',' expr {
            ExprList el = $1;
            el.push_back($3);
            $$ = el;
        }
        | expr {
            ExprList el;
            el.push_back($1);
            $$ = el;
        };

literal: INTEGER {
        Literal lit;
        lit.i = $1;
        lit.type = SimpleType::ST_INT;
        $$ = lit;
    }
    | FLOAT {
        Literal lit;
        lit.f = $1;
        lit.type = SimpleType::ST_FLOAT;
        $$ = lit;
    }
    | CHAR {
        Literal lit;
        lit.c = $1;
        lit.type = SimpleType::ST_CHAR;
        $$ = lit;
    }
;

expr: expr '+' expr {auto operation = BinOp();
                     operation.op = '+';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '-' expr {auto operation = BinOp();
                     operation.op = '-';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '*' expr {auto operation = BinOp();
                     operation.op = '*';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '%' expr {auto operation = BinOp();
                     operation.op = '%';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '/' expr {auto operation = BinOp();
                     operation.op = '/';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '<' expr {auto operation = BinOp();
                     operation.op = '<';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '>' expr {auto operation = BinOp();
                     operation.op = '>';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '=' expr {auto operation = BinOp();
                     operation.op = '=';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr DIFF_SIGN expr {auto operation = BinOp();
                     operation.op = '!';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr GREATER_EQ_SIGN expr {auto operation = BinOp();
                     operation.op = 'g';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr LESS_EQ_SIGN expr  {auto operation = BinOp();
                     operation.op = 'l';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '&' expr  {auto operation = BinOp();
                     operation.op = '&';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | expr '|' expr {auto operation = BinOp();
                     operation.op = '|';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = std::make_shared<BinOp>(operation);}
    | '(' expr ')' {auto operation = UnOp();
        operation.op = 'p';
        operation.expr = $2;
        $$ = std::make_shared<UnOp>(operation);}
    | '!' expr {auto operation = UnOp();
        operation.op = '!';
        operation.expr = $2;
        $$ = std::make_shared<UnOp>(operation);}
    | '-' expr %prec UMINUS {auto operation = UnOp();
        operation.op = '-';
        operation.expr = $2;
        $$ = std::make_shared<UnOp>(operation);}
    | IDENTIFIER array_access {Access acc;
                acc.id = $1;
                acc.indexes = $2;
                $$ = std::make_shared<Access>(acc);
                }
    | literal { $$ = std::make_shared<Literal>($1); }
;

array_access: %empty { $$ = ExprList(); }
    | array_access '[' expr ']' { 
        ExprList el = $1;
        el.push_back($3);
        $$ = el;
    };
%%

void yy::parser::error(const parser::location_type& l, const std::string& m)
{
    throw yy::parser::syntax_error(l, m);
}

int main() {
    yy::scanner scanner;
    yy::parser parser(&scanner);
    try {
        int result = parser.parse();
        if (result != 0)
            throw std::runtime_error("Unknown parsing error");
    } catch (yy::parser::syntax_error& e) {
        int row = e.location.begin.line;
        int col = e.location.begin.column;

        std::ostringstream msg;
        msg << e.what()
            << " in row " << row
            << " col " << col << "\n";
        throw yy::parser::syntax_error(e.location, msg.str());
    }
}

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
    #include <stdio.h>
    #include <vector>
    #include <string>
    #include <memory>
    #include <iostream>     // cerr, endl
    #include <utility>      // move
    #include <sstream>

    #include "scanner.h"

    #undef yylex
    #define yylex scanner->lex

    Program root;
}

%type <DecList> decl_list
%type <VarDec> decl_stmt
%type <std::vector<std::string>> id_list
%type <SimpleType> data_type
%type <StmtList> stmt_list
%type <Expr> expr
%type <Literal> literal
%type <std::vector<Expr>> array_access
%type <AttrStmt> attr_stmt
%type <Post_Labelless_Stmt> post_labelless_stmt
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
program: decl_list proc_decl_list body { root.var_dec = $1; std::cout << root << std::endl; }

body: START ';' stmt_list END ';'

decl_list: %empty {} |
    decl_list decl_stmt ';' {
        DecList a = $1;
        a.push_back($2);

        $$ = a;
    } 
    | decl_list DECLARE error ';'
;

decl_stmt: DECLARE '(' id_list ')' data_type {
    auto vd = VarDec();
    vd.ids = $3;
    auto ty = Type();
    if($5 == SimpleType::ST_INT)
        ty.type = SimpleType::ST_INT;
    if($5 == SimpleType::ST_FLOAT)
        ty.type = SimpleType::ST_FLOAT;
    if($5 == SimpleType::ST_FLOAT)
        ty.type = SimpleType::ST_FLOAT;
    vd.type.push_back(ty);
    $$ = vd;
};

proc_decl_list: %empty {}
    | proc_decl_list proc_decl ';' 
;

proc_decl: IDENTIFIER ':' PROCEDURE '(' super_id_list ')' ';' stmt_list END IDENTIFIER
    | IDENTIFIER error ';' stmt_list END IDENTIFIER
    ;

data_type: INT_TYPE  {$$ = SimpleType::ST_INT;} 
    | FLOAT_TYPE {$$ = SimpleType::ST_FLOAT;}
    | CHAR_TYPE  {$$ = SimpleType::ST_CHAR;}
    | array_nont;

array_nont: ARRAY '[' expr ']' OF data_type;

super_id_list: %empty {} 
    | id_list;

id_list: IDENTIFIER { std::vector<std::string> s;
                 s.push_back($1);
                 $$ = s; }
    | id_list ',' IDENTIFIER {std::vector<std::string> s = $1;
                 s.push_back($3);
                         $$ = s; };

stmt_list: %empty {}
    | super_stmt ';' stmt_list
    | error ';' stmt_list
    ;

super_stmt: label_stmt 
    | idless_stmt
    ;

label_stmt: IDENTIFIER post_label_stmt;

post_label_stmt: ':' stmt 
    | attr_stmt 
    | proc_stmt ;

stmt: labelless_stmt | idless_stmt ;

labelless_stmt: IDENTIFIER post_labelless_stmt {
    Post_Labelless_Stmt p = $2;
    p.label = $1;
    p.print();
};

post_labelless_stmt: attr_stmt {$$ = $1;}
    | proc_stmt ;

attr_stmt: array_access ATTR_SIGN expr {
    AttrStmt attr;
    attr.lhs = $1;
    attr.rhs = $3;
    $$ = attr;
};

idless_stmt: stop_stmt 
    | io_stmt
    | control_stmt ;

control_stmt: if_stmt 
    | goto_stmt
    | loop_stmt 
    | exit_stmt;

if_stmt: IF expr THEN stmt_list else_stmt ENDIF;

else_stmt: ELSE stmt_list 
         | %empty {};

goto_stmt: GOTO IDENTIFIER;

loop_stmt: LOOP ';' stmt_list ENDLOOP;

exit_stmt: EXITWHEN expr;

stop_stmt: STOP;

io_stmt: GET '(' id_list ')'
    | PUT skip_stmt '(' expr_list ')';

skip_stmt: SKIP 
    | %empty {};

proc_stmt: '(' expr_list ')';

expr_list: %empty {}
       | expr expr_list_tail ;

expr_list_tail: ',' expr expr_list_tail
        | %empty {};
literal: INTEGER {auto lit = Literal(); lit.i = $1; $$ = lit;}
    | FLOAT {auto lit = Literal(); lit.f = $1; $$ = lit;}
    | CHAR {auto lit = Literal(); lit.c = $1; $$ = lit;};

expr: expr '+' expr {auto operation = BinOp();
                     operation.op = '+';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '-' expr {auto operation = BinOp();
                     operation.op = '-';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '*' expr {auto operation = BinOp();
                     operation.op = '*';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '%' expr {auto operation = BinOp();
                     operation.op = '%';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '/' expr {auto operation = BinOp();
                     operation.op = '/';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '<' expr {auto operation = BinOp();
                     operation.op = '<';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '>' expr {auto operation = BinOp();
                     operation.op = '>';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '=' expr {auto operation = BinOp();
                     operation.op = '=';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr DIFF_SIGN expr {auto operation = BinOp();
                     operation.op = '!';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr GREATER_EQ_SIGN expr {auto operation = BinOp();
                     operation.op = 'g';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr LESS_EQ_SIGN expr  {auto operation = BinOp();
                     operation.op = 'l';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '&' expr  {auto operation = BinOp();
                     operation.op = '&';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | expr '|' expr {auto operation = BinOp();
                     operation.op = '|';
             operation.lhs = $1;
             operation.rhs = $3;
             $$ = operation;}
    | '(' expr ')' {auto operation = UnOp();
        operation.op = 'p';
        operation.expr = $2;
        $$ = operation;}
    | '!' expr {auto operation = UnOp();
        operation.op = '!';
        operation.expr = $2;
        $$ = operation;}
    | '-' expr %prec UMINUS {auto operation = UnOp();
        operation.op = '-';
        operation.expr = $2;
        $$ = operation;}
    | IDENTIFIER array_access {Access acc;
                acc.id = $1;
                $$ = acc;
                }
    | literal { $$ = $1; } ;

array_access: %empty {}
    | '[' expr ']' array_access { 
        std::vector<Expr> indexes;
        indexes = std::vector<Expr>();
        indexes.push_back($2);
        $$ = indexes;
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


%{

#include <stdio.h>
#include <vector>
#include <string.h>
#include <memory>
#include "lex.yy.c"
#include "abstract_tree.h"

extern unsigned int line;
extern unsigned int col;
extern char* yytext; 

int yydebug = 1;
void yyerror(const char *str){
	fprintf(stderr, "error (line %d, col %d): %s\n", line, col, str);
}

Program root;

%}

%union {Node vdc; VarDec* var;DecList* dec_list; ProList* pro_list; StmtList* stmt_list; std::string* sg; SimpleType st;}
%type <dec_list> decl_list
%type <var> decl_stmt
%type <sg> id_list
%type <st> data_type
%type <sg> IDENTIFIER 
%token START
%token END
%token DECLARE
%token PROCEDURE 
%token INT_TYPE
%token FLOAT_TYPE
%token CHAR_TYPE
%token ARRAY
%token OF 
%token IDENTIFIER
%token INTEGER
%token FLOAT
%token CHAR
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
      					 root = Program();
					 root.var_dec = $1; 
					 root.print();
					 if(root.var_dec != NULL){
						for(auto i : *(root.var_dec)){
							i->print();
						}	
					 }
					}

body: START ';' stmt_list  END ';'

decl_list: /* '' */ {$$ = NULL;} |
	 decl_list decl_stmt ';' {
				    DecList* a = new DecList();
				    if($1 != NULL){
					a = $1;
				    }
				    if($2 != nullptr){
					a->push_back($2);
				    }
		                    
				    $$ = a; } 
	| decl_list DECLARE error ';'
	;

decl_stmt: DECLARE '(' id_list ')' data_type { VarDec* vd = new VarDec();
						vd->ids.push_back($3);
						Type* ty = new Type();
						if($5 == SimpleType::ST_INT)
							ty->type = SimpleType::ST_INT;
						if($5 == SimpleType::ST_FLOAT)
							ty->type = SimpleType::ST_FLOAT;
						if($5 == SimpleType::ST_FLOAT)
							ty->type = SimpleType::ST_FLOAT;
						vd->type.push_back(ty);
						$$ = vd;}
	;

proc_decl_list: /* '' */ 
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

super_id_list: /* '' */ 
	| id_list;

id_list: IDENTIFIER { std::string* s = new std::string(yytext);
       		     $$ = s; }
	| id_list ',' IDENTIFIER;

stmt_list: /* '' */ 
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

labelless_stmt: IDENTIFIER post_labelless_stmt;

post_labelless_stmt: attr_stmt
	| proc_stmt ;

attr_stmt: array_access ATTR_SIGN expr;

idless_stmt: stop_stmt 
	| io_stmt
	| control_stmt ;

control_stmt: if_stmt 
	| goto_stmt
	| loop_stmt 
	| exit_stmt;

if_stmt: IF expr THEN stmt_list else_stmt ENDIF;

else_stmt: ELSE stmt_list 
		 | /* '' */;

goto_stmt: GOTO IDENTIFIER;

loop_stmt: LOOP ';' stmt_list ENDLOOP;

exit_stmt: EXITWHEN expr;

stop_stmt: STOP;

io_stmt: GET '(' id_list ')'
	| PUT skip_stmt '(' expr_list ')';

skip_stmt: SKIP 
	| /* '' */;

proc_stmt: '(' expr_list ')';

expr_list: /* '' */
	   | expr expr_list_tail ;

expr_list_tail: ',' expr expr_list_tail
	 	| /* '' */ ;
literal: INTEGER 
	| FLOAT 
	| CHAR;

expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '%' expr
    | expr '/' expr
    | expr '<' expr
    | expr '>' expr
    | expr '=' expr
    | expr DIFF_SIGN expr 
    | expr GREATER_EQ_SIGN expr 
    | expr LESS_EQ_SIGN expr 
    | expr '&' expr 
    | expr '|' expr 
    | '(' expr ')' 
    | '!' expr 
    | '-' expr %prec UMINUS 
    | IDENTIFIER array_access 
    | literal ;

array_access: /* '' */ 
	| '[' expr ']' array_access;
%%

int main() {
	return(yyparse());
}


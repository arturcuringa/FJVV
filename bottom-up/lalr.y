
%{

#include <stdio.h>
#include <string.h>

void yyerror(const char *str){
	fprintf(stderr, "error: %s \n", str);
}

%}

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

%%
program : decl_list proc_decl_list START ';' stmt_list  END ';' ;
decl_list: /* '' */ | decl_stmt ';' decl_list
decl_stmt: DECLARE '(' id_list ')' data_type
proc_decl_list: /* '' */ | proc_decl proc_decl_list
proc_decl: IDENTIFIER ':' PROCEDURE '(' super_id_list ')' ';' stmt_list END IDENTIFIER ';'
data_type: INT_TYPE | FLOAT_TYPE | CHAR_TYPE | array_nont
array_nont: ARRAY '[' e ']' data_type
super_id_list: /* '' */ | id_list
id_list: IDENTIFIER id_list2
id_list2: ',' IDENTIFIER id_list2 | /* '' */
stmt_list: /* '' */ | super_stmt ';' stmt_list ;
super_stmt: label_stmt ;
label_stmt: IDENTIFIER post_label_stmt;
post_label_stmt: ':'stmt | attr_stmt ;
stmt: labelless_stmt ;
labelless_stmt: IDENTIFIER post_labelless_stmt;
post_labelless_stmt: attr_stmt ;
attr_stmt: array_access ATTR_SIGN e;
literal: INTEGER | FLOAT | CHAR;
e: literal;
array_access: /* '' */ | '[' e ']' array_access;

%%

main (){
	return(yyparse());
}



%{

#include <stdio.h>
#include <string.h>

void yyerror(const char *str){
	fprintf(stderr, "error: %s \n", str);
}

%}

%token START END DECLARE PROCEDURE 
%token INT_TYPE FLOAT_TYPE CHAR_TYPE ARRAY OF 
%token ID INTEGER FLOAT CHAR
%token IF THEN ENDIF ELSE
%token GOTO LOOP ENDLOOP EXITWHEN STOP 
%token GET PUT SKIP 
%token ATTR_SIGN DIFF_SIGN GREATER_EQ_SIGN LESS_EQ_SIGN
%left '&' '|'
%left '>' '<' '=' '!=' '<=' '>='
%left '*' '/' '%'
%left '+' '-'
%nonassoc '!' '-' 

%%
program : START ';' END ';' ;
%%

main (){
	return(yyparse());
}


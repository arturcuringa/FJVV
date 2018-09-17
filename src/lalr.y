
%{

#include <stdio.h>
#include <string.h>

void yyerror(const char *str){
	fprintf(stderr, "error: %s \n", str);
}

%}

%token start terminator end

%%
program : start terminator end terminator ;
%%

main (){
	return(yyparse());
}


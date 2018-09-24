%option noyywrap
%option nounput
%option noinput
%{

#include "y.tab.h" 

%}

%%

"start" return START;
";"	return ';';
"end" 	return END;
[\t\r\ \n] ;
%%


%option noyywrap
%option nounput
%option noinput
%{

#include "y.tab.h" 

%}

%%

"start" return start;
";"	return terminator;
"end" 	return end;
[\t\r\ \n] ;
%%


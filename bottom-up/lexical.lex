%option noyywrap
%option nounput
%option noinput

%{
#include "y.tab.h"
unsigned int line = 1;
unsigned int col = 1;
void update_cursor();
%}

whitespace 		[ \t\r\f]
comment  		 ~.*
letter 			[a-zA-Z\$@#]
digit 			[0-9]
alphanumeric 	({letter}|{digit})
identifier 		{letter}{alphanumeric}*
integer 		{digit}+
float 			{digit}*\.{digit}+|{digit}+\.{digit}*
char 			\'(.|"\n")\'


%%
{whitespace} 	{col++;}
{comment} 	{update_cursor();}
(?i:start) 	{update_cursor(); return START;}
(?i:end) 	{update_cursor(); return END;}
(?i:declare) 	{update_cursor(); return DECLARE;}
(?i:procedure) 	{update_cursor(); return PROCEDURE;}
(?i:integer)	{update_cursor(); return INT_TYPE;}
(?i:float) 	{update_cursor(); return FLOAT_TYPE;}
(?i:char) 	{update_cursor(); return CHAR_TYPE;}
(?i:array) 	{update_cursor(); return ARRAY;}
(?i:of) 	{update_cursor(); return OF;}
{integer} 	{update_cursor(); return INTEGER;}
{float} 	{update_cursor(); return FLOAT;}
{char} 	{update_cursor(); return CHAR;}
(?i:if) 	{update_cursor(); return IF;}
(?i:then) 	{update_cursor(); return THEN;}
(?i:endif) 	{update_cursor(); return ENDIF;}
(?i:else) 	{update_cursor(); return ELSE;}
(?i:goto) 	{update_cursor(); return GOTO;}
(?i:loop) 	{update_cursor(); return LOOP;}
(?i:endloop) 	{update_cursor(); return ENDLOOP;}
(?i:exitwhen) 	{update_cursor(); return EXITWHEN;}
(?i:stop) 	{update_cursor(); return STOP;}
(?i:get) 	{update_cursor(); return GET;}
(?i:put) 	{update_cursor(); return PUT;}
(?i:skip) 	{update_cursor(); return SKIP;}
"+" 	{update_cursor(); return '+';}
"-" 	{update_cursor(); return '-';}
"/" 	{update_cursor(); return '/';}
"%" 	{update_cursor(); return '%';}
"*" 	{update_cursor(); return '*';}
"(" 	{update_cursor(); return '(';}
")" 	{update_cursor(); return ')';}
":" 	{update_cursor(); return ':';}
";" 	{update_cursor(); return ';';}
"[" 	{update_cursor(); return '[';}
"]" 	{update_cursor(); return ']';}
"," 	{update_cursor(); return ',';}
"=" 	{update_cursor(); return '=';}
":=" 	{update_cursor(); return ATTR_SIGN;}
"<" 	{update_cursor(); return '<';}
"<=" 	{update_cursor(); return LESS_EQ_SIGN;}
">" 	{update_cursor(); return '>';}
">=" 	{update_cursor(); return GREATER_EQ_SIGN;}
"!=" 	{update_cursor(); return DIFF_SIGN;}
"|" 	{update_cursor(); return '|';}
"&" 	{update_cursor(); return '&';}
"!" 	{update_cursor(); return '!';}

{identifier} {
	if ((size_t)yyleng > 16)
		printf("Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n", yytext, (size_t)yyleng, line, col);
	update_cursor();
	return IDENTIFIER; 
}
\n {line++; col=1;}
. {printf("Error: %s\n", yytext); col++;}
%%

void update_cursor(){
	col += yyleng;
}
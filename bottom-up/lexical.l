%option outfile="lexical.cxx"
%option header-file="lexical.hxx"

%option c++
%option warn
%option nodefault
%option noyywrap

%{
#include <string>
#include "abstract_tree.h"
#include "lalr.hxx"
#include "scanner.h"

using token = yy::parser::token;


#define YY_USER_ACTION          yylloc->columns(yyleng);
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

%{
    yylloc->step();
%}

{whitespace} 	{ }
{comment} 	{ }
(?i:start) 	{return token::START;}
(?i:end) 	{return token::END;}
(?i:declare) 	{return token::DECLARE;}
(?i:procedure) 	{return token::PROCEDURE;}
(?i:integer)	{return token::INT_TYPE;}
(?i:float) 	{return token::FLOAT_TYPE;}
(?i:char) 	{return token::CHAR_TYPE;}
(?i:array) 	{return token::ARRAY;}
(?i:of) 	{return token::OF;}
{integer} 	{yylval->build<int>(std::atoi(yytext)); return token::INTEGER;}
{float} 	{yylval->build<double>(std::stod(yytext)); return token::FLOAT;}
{char} 		{yylval->build<char>(yytext); return token::CHAR;}
(?i:if) 	{return token::IF;}
(?i:then) 	{return token::THEN;}
(?i:endif) 	{return token::ENDIF;}
(?i:else) 	{return token::ELSE;}
(?i:goto) 	{return token::GOTO;}
(?i:loop) 	{return token::LOOP;}
(?i:endloop) 	{return token::ENDLOOP;}
(?i:exitwhen) 	{return token::EXITWHEN;}
(?i:stop) 	{return token::STOP;}
(?i:get) 	{return token::GET;}
(?i:put) 	{return token::PUT;}
(?i:skip) 	{return token::SKIP;}
"+" 	{return '+';}
"-" 	{return '-';}
"/" 	{return '/';}
"%" 	{return '%';}
"*" 	{return '*';}
"(" 	{return '(';}
")" 	{return ')';}
":" 	{return ':';}
";" 	{return ';';}
"[" 	{return '[';}
"]" 	{return ']';}
"," 	{return ',';}
"=" 	{return '=';}
":=" 	{return token::ATTR_SIGN;}
"<" 	{return '<';}
"<=" 	{return token::LESS_EQ_SIGN;}
">" 	{return '>';}
">=" 	{return token::GREATER_EQ_SIGN;}
"!=" 	{return token::DIFF_SIGN;}
"|" 	{return '|';}
"&" 	{return '&';}
"!" 	{return '!';}
{identifier} {
	yylval->build<std::string>(yytext);
	return token::IDENTIFIER;
}
\n {yylloc->lines(1);}
. {printf("Error: %s\n", yytext); return yytext[0];}

%%

yy::scanner::scanner(std::istream* in, std::ostream* out)
    : yyFlexLexer(in, out)
{
}

int yyFlexLexer::yylex()
{
    throw std::logic_error("yyFlexLexer::yylex() must not be used.");
}
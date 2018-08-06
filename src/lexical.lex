%option noyywrap
%option nounput
%option noinput

%{
    unsigned int line = 1;
    unsigned int col = 1;
    void lexema_status(const char * token_name, const  char * yytext, const  size_t yyleng);

%}

letter			 [a-zA-Z\$@#]
digit 			 [0-9]
integer			 {digit}+
alphanumeric		 ({letter}|{digit})
identifier		 {letter}{alphanumeric}*
comment  		 ~.*
plussign 		 "+"
minussign 		 "-"
divsign 		 "/"
multsign 		 "*"
lparen 			 "("
rparen 			 ")"
colon 			 ":"
terminator		 ";"
lbracket		 "["
rbracket		 "]"
datatype 		 CHAR|char|INTEGER|integer|FLOAT|float
keyword 		 DECLARE|declare|ARRAY|array|OF|of|START|start|END|end

%%
\s {col++;}

{plussign} {
	lexema_status("plussign", yytext, yyleng);
	col += yyleng;
}

{minussign} {
	lexema_status("minussign", yytext, yyleng);
	col += yyleng;
}

{divsign} {
	lexema_status("divsign", yytext, yyleng);
	col += yyleng;
}

{multsign} {
	lexema_status("multsign", yytext, yyleng);
	col += yyleng;
}

{lparen} {
	lexema_status("lparen", yytext, yyleng);
	col += yyleng;
}

{rparen} {
	lexema_status("rparen", yytext, yyleng);
	col += yyleng;
}

{lbracket} {
	lexema_status("lbracket", yytext, yyleng);
	col += yyleng;
}

{rbracket} {
	lexema_status("rbracket", yytext, yyleng);
	col += yyleng;
}

{colon} {
	lexema_status("colon", yytext, yyleng);
	col += yyleng;
}

{terminator} {
	lexema_status("terminator", yytext, yyleng);
	col += yyleng;
}

{comment} {
	lexema_status("comment", yytext, yyleng);
	col += yyleng;
}

{datatype} {

	lexema_status("datatype", yytext, yyleng);
	col += yyleng;
}

{keyword} {

	lexema_status("keyword",yytext, yyleng);
	col += yyleng;
}
{identifier} {
	if((size_t)yyleng > 16)
		printf("Warning: Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	lexema_status("identifier",yytext, yyleng);
	col += yyleng;
}
. {col++;}
\n {line++;col=1;}

%%
void lexema_status(const char * token_name, const  char * yytext, const  size_t yyleng){
	printf("%s %s (len %lu, line %u, col %u)\n",token_name, yytext, yyleng, line, col);
}

int main() {
	yylex();
	return 0;
}

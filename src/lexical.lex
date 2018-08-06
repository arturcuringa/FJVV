%option noyywrap
%option nounput
%option noinput

%{
    unsigned int line = 0;
    unsigned int col = 0;
%}

letter [a-zA-Z\$@#]
digit  [0-9]
integer {digit}+
alphanumeric ({letter}|{digit})
identifier {letter}{alphanumeric}*

datatype CHAR|char|INTEGER|integer|FLOAT|float
keyword DECLARE|declare|ARRAY|array|OF|of|START|start|END|end

%%
\s {col++;}
{datatype} {
	printf("datatype %s (len %lu, line %u, col %u)\n", 
		yytext, (size_t)yyleng, line, col);
	col += (size_t)yyleng;
}
{keyword} {
	printf("keyword %s (len %lu, line %u, col %u)\n", 
		yytext, (size_t)yyleng, line, col);
	col += (size_t)yyleng;
}
{identifier} {
	if((size_t)yyleng > 16)
		printf("Warning: Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	printf("identifier %s (len %lu, line %u, col %u)\n",yytext, (size_t)yyleng, line, col);
	col += (size_t)yyleng;
}
. {col++;}
\n {line++;col=0;}

%%

int main() {
	yylex();
	return 0;
}

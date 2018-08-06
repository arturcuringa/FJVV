%option noyywrap
%option nounput
%option noinput

%{
    unsigned int line = 1;
    unsigned int col = 1;
%}

letter [a-zA-Z\$@#]
digit  [0-9]
integer {digit}+
alphanumeric ({letter}|{digit})
identifier {letter}{alphanumeric}*
comment  ~.*
datatype CHAR|char|INTEGER|integer|FLOAT|float
keyword DECLARE|declare|ARRAY|array|OF|of|START|start|END|end

%%
\s {col++;}
{comment} {
	printf("comment %s (len %u, line %u, col %u)\n", 
		yytext, yyleng, line, col);
	col += yyleng;
}
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
\n {line++;col=1;}

%%

int main() {
	yylex();
	return 0;
}

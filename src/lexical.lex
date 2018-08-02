%option noyywrap

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
	printf("datatype %s (len %zu, line %u, col %u)\n", 
		yytext, yyleng, line, col);
	col += yyleng;
}
{keyword} {
	printf("keyword %s (len %zu, line %u, col %u)\n", 
		yytext, yyleng, line, col);
	col += yyleng;
}
{identifier} {
	printf("identifier %s (len %zu, line %u, col %u)\n", 
		yytext, yyleng, line, col);
	col += yyleng;
}
. {col++;}
\n {line++;col=0;}

%%

int main() {
	yylex();
}
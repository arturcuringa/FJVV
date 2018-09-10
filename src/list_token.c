#include "lex.yy.c"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	enum token tok;
	do {tok = yylex();} while (tok != END_OF_FILE);
	return 0;
}
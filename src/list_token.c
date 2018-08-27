#include "lex.yy.c"
#include <stdio.h>

int main(int argc, char const *argv[]) {
	while (yylex()) {}
	return 0;
}
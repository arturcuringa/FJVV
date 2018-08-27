#include "enum_token.h"
#include "lex.yy.c"
#include <stdio.h>

enum token tok;
void error() { printf("Erro no parsing!\n"); }
void advance() { tok = yylex(); }
void eat(enum token t) { if (tok == t) advance(); else error(); }

void SEMICOLON() {
	switch(tok){
		case TERMINATOR:
			eat(TERMINATOR);
			break;
		default:
			printf("faltou o ;\n");
	}
}

void ENDTOK() {
	eat(END);
}

void PROGRAM() {
	switch(tok) {
		case START:
			eat(START);
			SEMICOLON(); ENDTOK(); SEMICOLON();
			break;
		default:
			error();
	}
}

int main(int argc, char const *argv[]) {
	advance();
	PROGRAM();

	return 0;
}
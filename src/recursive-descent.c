#include "enum_token.h"
#include "lex.yy.c"
#include <stdio.h>

enum token tok;
void error() { printf("Parsing error on line %d and col %d!\n", line, col); }
void advance() { tok = yylex(); }
void eat(enum token t) { if (tok == t) advance(); else error(); }

void STARTTOK() {
	switch (tok) {
		case START:
			eat(START);
			break;
		default:
			printf("Missing 'START'\n");
	}
}

void TERMINATORTOK() {
	switch(tok){
		case TERMINATOR:
			eat(TERMINATOR);
			break;
		default:
			printf("missing ;\n");
	}
}

void LPARENTOK() {
	eat(LPAREN);
}

void RPARENTOK() {
	eat(RPAREN);
}

void DECLARETOK() {
	eat(DECLARE);
}

void ENDTOK() {
	eat(END);
}

void IDENTIFIERTOK() {
	eat(IDENTIFIER);
}

void COMMATOK() {
	eat(SEPARATOR);
}

void DATATYPETOK() {
	eat(DATATYPE);
}

void ARRAYTOK(){
	switch(tok){
		case ARRAY:
			eat(ARRAY);
			break;
		deafult:
			printf("Missing ARRAY declaration!\n");
	}
}

void DATATYPENONT() {
	switch (tok) {
		case DATATYPE:
			DATATYPETOK();
			break;
		case ARRAY:
			ARRAYTOK();
		default:
			break;
	}
}

void IDLIST2() {
	switch(tok) {
		case RPAREN:
			break;
		case SEPARATOR:
			COMMATOK();
			IDENTIFIERTOK();
			IDLIST2();
			break;
		default:
			break;
	}
}

void IDLIST() {
	IDENTIFIERTOK();
	IDLIST2();
}

void DECLSTMT() {
	DECLARETOK();
	LPARENTOK();
	IDLIST();
	RPARENTOK();
	DATATYPENONT();
}

void DECLSTMTLIST() {
	switch (tok) {
		case START:
		case IDENTIFIER:
			break;
		case DECLARE:
			DECLSTMT();
			TERMINATORTOK();
			DECLSTMTLIST();
			break;
		default:
			break;
	}
}

void PROCDECLLIST() {

}

void STMTLIST() {

}

void PROGRAM() {
	DECLSTMTLIST();
	PROCDECLLIST();
	STARTTOK();
	TERMINATORTOK();
	STMTLIST();
	ENDTOK();
	TERMINATORTOK();
}

int main(int argc, char const *argv[]) {
	advance();
	PROGRAM();

	return 0;
}
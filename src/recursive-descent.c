#include "enum_token.h"
#include "lex.yy.c"
#include "recursive-descent.h"
#include <stdio.h>

enum token tok;
void error() { printf("Parsing error on line %d and col %d!\n", line, col); }
void advance() { tok = yylex(); }
void eat(enum token t) { if (tok == t) advance(); else error(); }

void STOPSTMT(){
	switch (tok) {
		case STOP:
			STOPTOK();
			break;
		default:
			error();
	}
}

void SKIPSTMT(){
	switch (tok) {
		case STOP:
			SKIPTOK();
			break;
		default:
			error();
	}
}

void GOTOSTMT(){
	switch (tok) {
		case GOTO:
			GOTOTOK();
			break;
		default:
			error();
	}
}

void ELSESTMT(){
	switch (tok) {
		case ELSE:
			ELSETOK();
			break;
		default:
			error();
	}
}

void EXITSTMT() {
	switch(tok) {
		case EXITWHEN:
			eat(EXITWHENTOK);
			break;
		default:
			error();
	}
}

void ATTRSTMT() {
	switch(tok){
		case ATTR_SIGN:
			eat(ATTR_SIGN);
			E();
			break;
		default:
			error();
	}

}

void POSTLABELESSSTMT(){
	switch (tok){
		case ATTR_SIGN:
			ATTRSTMT();
			break;
		case LPAREN:
			PROCSTMT();
			break;
		default:
			error();
	}
}

void IDLESSSTMT(){
	switch (tok){
		case STOP:
			STOPSTMT();
			break;
		case PUT:
		case GET:
			IOSTMT();
			break;
		case GOTO:
		case IF:
		case LOOP:
		case EXITWHEN:
			CONTROLSTMT();
		default:
			erorr();
	}
}

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

void POSTLABELSTMT (){
	switch (tok){
		case COLON:
			eat(COLON);
			STMT();
			break;
		case ATTR_SIGN: 
			ATTRSTMT();
			break;
		case LPAREN:
			PROCSTMT();
			break;
		default:
			error();
	}
}

void LABELLESSTMT() {
	switch (tok){
		case IDENTIFIER:
			eat(IDENTIFIER);
			POSTLABELESSSTMT();
			break;
		default:
			error();
	}
}

void STMT() {
	switch (tok) {
		case IDENTIFIER:
			LABELLESSTMT();
			break;
		case STOP:
		case IF:
		case GOTO:
		case LOOP:
		case EXITWHEN:
		case PUT:
		case GET:
			IDLESSSTMT();
			break;
		default:
			error();
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

void PROCEDURETOK() {
	eat(PROCEDURE);
}

void EXPRLIST() {
	switch (tok) {
		case RPAREN:
			break;
		case LPAREN:
		case IDENTIFIER:
		case MINUS_SIGN:
		case NEG_SIGN:
		case INTEGER:
		case FLOAT:
			E();
			EXPRLISTTAIL();
			break;
		default:
			break;
	}
}

void EXPRLISTTAIL() {
	switch (tok) {
		case RPAREN:
			break;
		case SEPARATOR:
			SEPARATORTOK();
			E();
			EXPRLISTTAIL();
			break;
		default:
			break;
	}
}

void E() {
	switch (tok) {
		case LPAREN:
		case IDENTIFIER:
		case MINUS_SIGN:
		case NEG_SIGN:
		case INTEGER:
		case FLOAT:
			T();
			E_();
			break;
		default:
			printf("Expected an expression I think? Do you have one?\n");
	}
}

void E_() {
	switch (tok) {
		case TERMINATOR:
		case RPAREN:
		case RBRACKET:
		case THEN:
		case SEPARATOR:
			break;
		case AND_SIGN:
		case OR_SIGN:
			A();
			E();
			break;
		default:
			break;
	}
}

void A() {
	switch (tok) {
		case AND_SIGN:
			AND_SIGNTOK();
			break;
		case OR_SIGN:
			OR_SIGNTOK();
			break;
		default:
			printf("Something Terrible Befell This Parser\n");
	}
}

void T() {
	switch (tok) {
		case LPAREN:
		case IDENTIFIER:
		case MINUS_SIGN:
		case NEG_SIGN:
		case INTEGER:
		case FLOAT:
			T2();
			T_();
			break;
		default:
			printf("Invalid expression >:(\n");
	}
}

void T_() {
	switch (tok) {
		case TERMINATOR:
		case RPAREN:
		case RBRACKET:
		case THEN:
		case SEPARATOR:
		case AND_SIGN:
		case OR_SIGN:
			break;
		case GREATER_SIGN:
		case LESS_SIGN:
		case EQUAL_SIGN:
		case DIFF_SIGN:
		case LESS_EQ_SIGN:
		case GREATER_EQ_SIGN:
			B();
			T();
			break;
		default:
			break;
	}
}

void B() {
	switch (tok) {
		case GREATER_SIGN:
			GREATER_SIGNTOK();
			break;
		case LESS_SIGN:
			LESS_SIGNTOK();
			break;
		case EQUAL_SIGN:
			EQUAL_SIGNTOK();
			break;
		case DIFF_SIGN:
			DIFF_SIGNTOK();
			break;
		case LESS_EQ_SIGN:
			LESS_EQ_SIGNTOK();
			break;
		case GREATER_EQ_SIGN:
			GREATER_EQ_SIGNTOK();
			break;
		default:
			printf("whaaaaaaaaat\n");
	}
}

void T2() {
	switch (tok) {
		case LPAREN:
		case IDENTIFIER:
		case MINUS_SIGN:
		case NEG_SIGN:
		case INTEGER:
		case FLOAT:
			T3();
			T2_();
			break;
		default:
			printf("get outta my face with that expression\n");
	}
}

void ARRAYTOK(){
	switch(tok){
		case ARRAY:
			eat(ARRAY);
			break;
		default:
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
	switch (tok) {
		case START:
			break;
		case IDENTIFIER:
			PROCDECL();
			PROCDECLLIST();
			break;
		default:
			break;
	}
}

void PROCDECL() {
	switch (tok) {
		case IDENTIFIER:
			IDENTIFIERTOK();
			COLONTOK();
			PROCEDURETOK();
			LPARENTOK();
			SUPERIDLIST();
			RPARENTOK();
			TERMINATORTOK();
			STMTLIST();
			ENDTOK();
			IDENTIFIERTOK();
			break;
		default:
			printf("Something went wrong\n");
	}
}

void LABELSTMT() {
	switch (tok){
		case IDENTIFIER:
			eat(IDENTIFIER);
			POSTLABELSTMT();
			break;
		default:
			error();
	}
}

void SUPERSTMT() {
	switch (tok) {
		case IDENTIFIER:
			LABELSTMT();
			break;
		// case IOSTMT
		// case IF
		// case GOTO
		// case LOOP
		// case EXTIWHEN
		// case STOP
			//IDLESSSTMT();
			break;
		default:
			printf("Something happened\n");
			break;
	}
}

void STMTLIST() {
	switch (tok) {
		case IDENTIFIER:
		// iostmt
		// if
		// loop
		// goto
		// exitwhen
		// stop
			SUPERSTMT();
			STMTLIST();
		default:
		// lambda
			break;
	}
}

void IFTOK() {
	switch(tok) {
		case IF:
			eat(IF);
			break;
		default:
			error();
	}
}

void ELSETOK() {
	switch(tok) {
		case ELSE:
			eat(ELSE);
			break;
		default:
			error();
	}
}

void GOTOTOK() {
	switch(tok) {
		case GOTO:
			eat(GOTO);
			break;
		default:
			error();
	}
}

void LOOPTOK() {
	switch(tok) {
		case LOOP:
			eat(LOOP);
			break;
		default:
			error();
	}
}

void EXITWHENTOK() {
	switch(tok) {
		case EXITWHEN:
			eat(EXITWHEN);
			break;
		default:
			error();
	}
}

void STOPTOK() {
	switch(tok) {
		case STOP:
			eat(STOP);
			break;
		default:
			error();
	}
}

void SKIPTOK() {
	switch(tok) {
		case SKIP:
			eat(SKIP);
			break;
		default:
			error();
	}
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
#include "enum_token.h"
#include "lex.yy.c"
#include "recursive-descent.h"
#include <stdio.h>

enum token tok;
void error() { printf("Parsing error on line %d and col %d!\n", line, col); }
void advance() { tok = yylex(); }
void eat(enum token t) { if (tok == t) advance(); else error(); }

void CONTROLSTMT(){
	switch(tok){
		case IF:
			IFSTMT();
			break;
		case GOTO:
			GOTOSTMT();
			break;
		case LOOP:
			LOOPSTMT();
			break;
		case EXITWHEN:
			EXITWHENSTMT();
			break;	
		default:
			error();
	}

}

void LOOPSTMT(){
	switch(tok){
		case LOOP:
			LOOPTOK();
			TERMINATORTOK();
			STMTLIST();
			ENDLOOPTOK();
			break;
		default:
			error();	
	}
}

void IOSTMT(){
	switch(tok){
		case GET:
			GETTOK();
			LPARENTOK();
			IDLIST();
			RPARENTOK();
			break;
		case PUT:
			PUTTOK();
			SKIPSTMT();
			LPARENTOK();
			IDLIST();
			RPARENTOK();
			break;
		default:
			error();
	}
}

void PUTTOK(){
	switch(tok){
		case PUT:
			eat(PUT);
			break;
		default:
			error();
	}

}

void GETTOK(){
	switch(tok){
		case GET:
			eat(GET);
			break;
		default:
			error();	
	}
}

void IFSTMT(){
	switch(tok){
		case IF:
			IFTOK();
			E();
			THENTOK();
			STMTLIST();
			ELSESTMT();
			ENDIFTOK();
			break;
		default:
			error();
	}

}

void PROCSTMT(){
	switch(tok){
		case LPAREN:
			eat(LPAREN);
			EXPRLIST();
			eat(RPAREN);
			break;
		default:
			error();
			
	}
}

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
		case SKIP:
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
			IDENTIFIERTOK();
			break;
		default:
			error();
	}
}

void ELSESTMT(){
	switch (tok) {
		case ELSE:
			ELSETOK();
			STMTLIST();
			break;
		default:
			error();
	}
}

void EXITWHENSTMT() {
	switch(tok) {
		case EXITWHEN:
			EXITWHENTOK();
			E();
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

void CONTROLSTSMT() {
    switch(tok) {
        case IF:
            IFSTMT();
            break;
        case GOTO:
            GOTOSTMT();
            break;
        case LOOP:
            LOOPSTMT();
            break;
        case EXITWHEN:
            EXITWHENSTMT();
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
			break;
		default:
			error();
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
	switch (tok) {
		case TERMINATOR:
			eat(TERMINATOR);
			break;
		default:
			printf("missing ;\n");
	}
}

void SEPARATORTOK() {
	switch (tok) {
		case SEPARATOR:
			eat(SEPARATOR);
			break;
		default:
			printf("missing ,\n");
	}
}

void AND_SIGNTOK() {
	switch (tok) {
		case AND_SIGN:
			eat(AND_SIGN);
			break;
		default:
			printf("missing &\n");
	}
}

void OR_SIGNTOK() {
	switch (tok) {
		case OR_SIGN:
			eat(OR_SIGN);
			break;
		default:
			printf("missing |\n");
	}
}

void GREATER_SIGNTOK() {
	switch (tok) {
		case GREATER_SIGN:
			eat(GREATER_SIGN);
			break;
		default:
			printf("missing >\n");
	}
}

void LESS_SIGNTOK() {
	switch (tok) {
		case LESS_SIGN:
			eat(LESS_SIGN);
			break;
		default:
			printf("missing <\n");
	}
}

void EQUAL_SIGNTOK() {
	switch (tok) {
		case EQUAL_SIGN:
			eat(EQUAL_SIGN);
			break;
		default:
			printf("missing =\n");
	}
}

void DIFF_SIGNTOK() {
	switch (tok) {
		case DIFF_SIGN:
			eat(DIFF_SIGN);
			break;
		default:
			printf("missing !=\n");
	}
}

void LESS_EQ_SIGNTOK() {
	switch (tok) {
		case LESS_EQ_SIGN:
			eat(LESS_EQ_SIGN);
			break;
		default:
			printf("missing <=\n");
	}
}

void GREATER_EQ_SIGNTOK() {
	switch (tok) {
		case GREATER_EQ_SIGN:
			eat(GREATER_EQ_SIGN);
			break;
		default:
			printf("missing >=\n");
	}
}

void POSTLABELSTMT() {
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
	switch(tok){
		case LPAREN:	
			eat(LPAREN);
			break;
		default:
			error();
	}
}

void RPARENTOK() {
	switch(tok){
		case RPAREN:
			eat(RPAREN);
			break;
		default:
			error();
	}
}

void DECLARETOK() {
	switch(tok){
		case DECLARE:
			eat(DECLARE);
			break;
		default:
			error();
	}
}

void ENDTOK() {
	switch(tok){
		case END:
			eat(END);
			break;
		default:
			error();
	}
}

void IDENTIFIERTOK() {
	switch(tok){
		case IDENTIFIER:
			eat(IDENTIFIER);
			break;
		
		default:
			error();
	}
}

void COMMATOK() {
	switch(tok){
		case SEPARATOR:
			eat(SEPARATOR);
			break;
		default:
			error();
	}
}

void PROCEDURETOK() {
	switch(tok){
		case PROCEDURE:
			eat(PROCEDURE);
			break;
		default:
			error();
	}
}

void CHARTOK() {
	switch (tok) {
		case CHAR:
			eat(CHAR);
			break;
		default:
			error();
	}
}

void COLONTOK() {
	switch (tok) {
		case COLON:
			eat(COLON);
			break;
		default:
			error();
	}
}


void DIV_SIGNTOK() {
	switch (tok) {
		case DIV_SIGN:
			eat(DIV_SIGN);
			break;
		default:
			error();
	}
}

void FLOATTOK() {
	switch (tok) {
		case FLOAT:
			eat(FLOAT);
			break;
		default:
			error();
	}
}

void INTEGERTOK() {
	switch (tok) {
		case INTEGER:
			eat(INTEGER);
			break;
		default:
			error();
	}
}

void MINUS_SIGNTOK() {
	switch (tok) {
		case MINUS_SIGN:
			eat(MINUS_SIGN);
			break;
		default:
			error();
	}
}

void MOD_SIGNTOK() {
	switch (tok) {
		case MOD_SIGN:
			eat(MOD_SIGN);
			break;
		default:
			error();
	}
}

void MULT_SIGNTOK() {
	switch (tok) {
		case MULT_SIGN:
			eat(MULT_SIGN);
			break;
		default:
			error();
	}
}

void NEG_SIGNTOK() {
	switch (tok) {
		case NEG_SIGN:
			eat(NEG_SIGN);
			break;
		default:
			error();
	}
}

void PLUS_SIGNTOK() {
	switch (tok) {
		case PLUS_SIGN:
			eat(PLUS_SIGN);
			break;
		default:
			error();
	}
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

void T2_() {
	switch (tok) {
		case TERMINATOR:
		case RPAREN:
		case RBRACKET:
		case THEN:
		case SEPARATOR:
		case AND_SIGN:
		case OR_SIGN:
		case GREATER_SIGN:
		case LESS_SIGN:
		case EQUAL_SIGN:
		case DIFF_SIGN:
		case LESS_EQ_SIGN:
		case GREATER_EQ_SIGN:
			break;
		case PLUS_SIGN:
		case MINUS_SIGN:
			C();
			T2();
			break;
		default:
			break;
	}
}

void C() {
	switch (tok) {
		case PLUS_SIGN:
			PLUS_SIGNTOK();
			break;
		case MINUS_SIGN:
			MINUS_SIGNTOK();
			break;
		default:
			printf("nöööööö\n");
	}
}

void T3() {
	switch (tok) {
		case LPAREN:
		case IDENTIFIER:
		case MINUS_SIGN:
		case NEG_SIGN:
		case INTEGER:
		case FLOAT:
			F();
			T3();
			break;
		default:
			printf(":o\n");
	}
}

void T3_() {
	switch (tok) {
		case TERMINATOR:
		case RPAREN:
		case RBRACKET:
		case THEN:
		case SEPARATOR:
		case AND_SIGN:
		case OR_SIGN:
		case GREATER_SIGN:
		case LESS_SIGN:
		case EQUAL_SIGN:
		case DIFF_SIGN:
		case LESS_EQ_SIGN:
		case GREATER_EQ_SIGN:
		case PLUS_SIGN:
		case MINUS_SIGN:
			break;
		case MULT_SIGN:
		case DIV_SIGN:
		case MOD_SIGN:
			D();
			T3();
			break;
		default:
			break;
	}
}

void D() {
	switch (tok) {
		case MULT_SIGN:
			MULT_SIGNTOK();
			break;
		case DIV_SIGN:
			DIV_SIGNTOK();
			break;
		case MOD_SIGN:
			MOD_SIGNTOK();
			break;
		default:
			printf("*, /, or %% pwleeeease\n");
	}
}

void F() {
	switch (tok) {
		case LPAREN:
			LPARENTOK();
			F();
			RPARENTOK();
			break;
		case IDENTIFIER:
			IDENTIFIERTOK();
			break;
		case MINUS_SIGN:
			MINUS_SIGNTOK();
			F();
			break;
		case NEG_SIGN:
			NEG_SIGNTOK();
			F();
			break;
		case INTEGER:
		case FLOAT:
			LITERAL();
			break;
		default:
			break;
	}
}

void LITERAL() {
	switch (tok) {
		case INTEGER:
			INTEGERTOK();
			break;
		case FLOAT:
			FLOATTOK();
			break;
		case CHAR:
			CHARTOK();
			break;
		default:
			printf("i, literally, expected a literal......\n");
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

void DATATYPE() {
	switch (tok) {
		case INT_TYPE:
			INT_TYPETOK();
			break;
		case CHAR_TYPE:
			CHAR_TYPETOK();
			break;
		case FLOAT_TYPE:
			FLOAT_TYPETOK();
			break;
		case ARRAY:
			ARRAYTOK();
			break;
		default:
			error();
	}
}

void IDLIST2() {
	switch(tok) {
		case RPAREN:
			break;
		case SEPARATOR:
			SEPARATORTOK();
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
	DATATYPE();
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

void THENTOK() {
	switch(tok) {
		case THEN:
			eat(THEN);
			break;
		default:
			error();
	}
}

void ENDIFTOK() {
	switch(tok) {
		case ENDIF:
			eat(ENDIF);
			break;
		default:
			error();
	}
}

void ENDLOOPTOK() {
	switch(tok) {
		case ENDLOOP:
			eat(ENDLOOP);
			break;
		default:
			error();
	}
}

void CHAR_TYPETOK(){
	switch(tok){
		case CHAR_TYPE:
			eat(CHAR_TYPE);
			break;
		default:
			error();
	}

}

void INT_TYPETOK(){
	switch(tok){
		case INT_TYPE:
			eat(INT_TYPE);
			break;
		default:
			error();
	}

}

void FLOAT_TYPETOK(){
	switch(tok){
		case FLOAT_TYPE:
			eat(FLOAT_TYPE);
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

#include "enum_token.h"
#include "lex.yy.c"
#include "recursive-descent.h"
#include <stdio.h>

enum token tok;
int noError = 1;

void error() { 
	printf("Parsing error on line %d and col %d!\n", line, col);
	noError = 0;
}

void advance() { tok = yylex(); }
void eat(enum token t) {
	if (tok == t) {
		advance();
	} else {
		printf("Could not consume token %s, expected %s\n",
			tokenNames[tok], tokenNames[t]);
		noError = 0;
	}
}

void SUPERIDLIST() {
	switch (tok) {
		case IDENTIFIER:
			IDLIST();
			break;
		default:
			break;
	}
}

void CONTROLSTMT() {
	switch (tok) {
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

void LOOPSTMT() {
	switch (tok) {
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

void IOSTMT() {
	switch (tok) {
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
void LBRACKETTOK() {
	switch (tok) {
		case LBRACKET:
			eat(LBRACKET);
			break;
		default:
			error();
			printf("Expected '[', found %s\n", tokenNames[tok]);
	}
}

void RBRACKETTOK() {
	switch (tok) {
		case RBRACKET:
			eat(RBRACKET);
			break;
		default:
			error();
			printf("Expected ']', found %s\n", tokenNames[tok]);
	}
}

void OFTOK() {
	switch (tok) {
		case OF:
			eat(OF);
			break;
		default:
			error();
			printf("Expected 'OF', found %s\n", tokenNames[tok]);
	}
}

void PUTTOK() {
	switch (tok) {
		case PUT:
			eat(PUT);
			break;
		default:
			error();
			printf("Expected 'PUT', found %s\n", tokenNames[tok]);
	}

}

void GETTOK() {
	switch (tok) {
		case GET:
			eat(GET);
			break;
		default:
			error();
			printf("Expected 'GET', found %s\n", tokenNames[tok]);
	}
}

void IFSTMT() {
	switch (tok) {
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

void PROCSTMT() {
	switch (tok) {
		case LPAREN:
			eat(LPAREN);
			EXPRLIST();
			eat(RPAREN);
			break;
		default:
			error();
			
	}
}

void STOPSTMT() {
	switch (tok) {
		case STOP:
			STOPTOK();
			break;
		default:
			error();
	}
}

void SKIPSTMT() {
	switch (tok) {
		case SKIP:
			SKIPTOK();
			break;
		default:
			error();
	}
}

void GOTOSTMT() {
	switch (tok) {
		case GOTO:
			GOTOTOK();
			IDENTIFIERTOK();
			break;
		default:
			error();
	}
}

void ELSESTMT() {
	switch (tok) {
		case ELSE:
			ELSETOK();
			STMTLIST();
			break;
		default:
			break;
	}
}

void EXITWHENSTMT() {
	switch (tok) {
		case EXITWHEN:
			EXITWHENTOK();
			E();
			break;		
		default:
			error();
	}
}

void ATTRSTMT() {
	switch (tok) {
		case ATTR_SIGN:
		case TERMINATOR:
		case LBRACKET:
			ARRAYACCESS();
			eat(ATTR_SIGN);
			E();
			break;
		default:
			error();
	}

}

void POSTLABELESSSTMT() {
	switch (tok) {
		case ATTR_SIGN:
		case TERMINATOR:
		case LBRACKET:
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
    switch (tok) {
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

void IDLESSSTMT() {
	switch (tok) {
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
			error();
			printf("Expected 'START', found %s\n", tokenNames[tok]);
	}
}

void TERMINATORTOK() {
	switch (tok) {
		case TERMINATOR:
			eat(TERMINATOR);
			break;
		default:
			error();
			printf("Expected ';', found %s\n", tokenNames[tok]);
	}
}

void SEPARATORTOK() {
	switch (tok) {
		case SEPARATOR:
			eat(SEPARATOR);
			break;
		default:
			error();
			printf("Expected ',', found %s\n", tokenNames[tok]);
	}
}

void AND_SIGNTOK() {
	switch (tok) {
		case AND_SIGN:
			eat(AND_SIGN);
			break;
		default:
			error();
			printf("Expected '&', found %s\n", tokenNames[tok]);
	}
}

void OR_SIGNTOK() {
	switch (tok) {
		case OR_SIGN:
			eat(OR_SIGN);
			break;
		default:
			error();
			printf("Expected '|', found %s\n", tokenNames[tok]);
	}
}

void GREATER_SIGNTOK() {
	switch (tok) {
		case GREATER_SIGN:
			eat(GREATER_SIGN);
			break;
		default:
			error();
			printf("Expected '>', found %s\n", tokenNames[tok]);
	}
}

void LESS_SIGNTOK() {
	switch (tok) {
		case LESS_SIGN:
			eat(LESS_SIGN);
			break;
		default:
			error();
			printf("Expected '<', found %s\n", tokenNames[tok]);
	}
}

void EQUAL_SIGNTOK() {
	switch (tok) {
		case EQUAL_SIGN:
			eat(EQUAL_SIGN);
			break;
		default:
			error();
			printf("Expected '=', found %s\n", tokenNames[tok]);
	}
}

void DIFF_SIGNTOK() {
	switch (tok) {
		case DIFF_SIGN:
			eat(DIFF_SIGN);
			break;
		default:
			error();
			printf("Expected '!=', found %s\n", tokenNames[tok]);
	}
}

void LESS_EQ_SIGNTOK() {
	switch (tok) {
		case LESS_EQ_SIGN:
			eat(LESS_EQ_SIGN);
			break;
		default:
			error();
			printf("Expected '<=', found %s\n", tokenNames[tok]);
	}
}

void GREATER_EQ_SIGNTOK() {
	switch (tok) {
		case GREATER_EQ_SIGN:
			eat(GREATER_EQ_SIGN);
			break;
		default:
			error();
			printf("Expected '>=', found %s\n", tokenNames[tok]);
	}
}

void POSTLABELSTMT() {
	switch (tok) {
		case COLON:
			eat(COLON);
			STMT();
			break;
		case ATTR_SIGN: 
		case TERMINATOR:
		case LBRACKET:
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
	switch (tok) {
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
	switch (tok) {
		case LPAREN:	
			eat(LPAREN);
			break;
		default:
			error();
			printf("Expected '(', found %s\n", tokenNames[tok]);
	}
}

void RPARENTOK() {
	switch (tok) {
		case RPAREN:
			eat(RPAREN);
			break;
		default:
			error();
			printf("Expected ')', found %s\n", tokenNames[tok]);
	}
}

void DECLARETOK() {
	switch (tok) {
		case DECLARE:
			eat(DECLARE);
			break;
		default:
			error();
			printf("Expected 'DECLARE', found %s\n", tokenNames[tok]);
	}
}

void ENDTOK() {
	switch (tok) {
		case END:
			eat(END);
			break;
		default:
			error();
			printf("Expected 'END', found %s\n", tokenNames[tok]);
	}
}

void IDENTIFIERTOK() {
	switch (tok) {
		case IDENTIFIER:
			eat(IDENTIFIER);
			break;
		default:
			error();
			printf("Expected identifier, found %s\n", tokenNames[tok]);
	}
}

void PROCEDURETOK() {
	switch (tok) {
		case PROCEDURE:
			eat(PROCEDURE);
			break;
		default:
			error();
			printf("Expected 'PROCEDURE', found %s\n", tokenNames[tok]);
	}
}

void CHARTOK() {
	switch (tok) {
		case CHAR:
			eat(CHAR);
			break;
		default:
			error();
			printf("Expected char, found %s\n", tokenNames[tok]);
	}
}

void COLONTOK() {
	switch (tok) {
		case COLON:
			eat(COLON);
			break;
		default:
			error();
			printf("Expected ':', found %s\n", tokenNames[tok]);
	}
}


void DIV_SIGNTOK() {
	switch (tok) {
		case DIV_SIGN:
			eat(DIV_SIGN);
			break;
		default:
			error();
			printf("Expected '/', found %s\n", tokenNames[tok]);
	}
}

void FLOATTOK() {
	switch (tok) {
		case FLOAT:
			eat(FLOAT);
			break;
		default:
			error();
			printf("Expected float, found %s\n", tokenNames[tok]);
	}
}

void INTEGERTOK() {
	switch (tok) {
		case INTEGER:
			eat(INTEGER);
			break;
		default:
			error();
			printf("Expected integer, found %s\n", tokenNames[tok]);
	}
}

void MINUS_SIGNTOK() {
	switch (tok) {
		case MINUS_SIGN:
			eat(MINUS_SIGN);
			break;
		default:
			error();
			printf("Expected '-', found %s\n", tokenNames[tok]);
	}
}

void MOD_SIGNTOK() {
	switch (tok) {
		case MOD_SIGN:
			eat(MOD_SIGN);
			break;
		default:
			error();
			printf("Expected '%%', found %s\n", tokenNames[tok]);
	}
}

void MULT_SIGNTOK() {
	switch (tok) {
		case MULT_SIGN:
			eat(MULT_SIGN);
			break;
		default:
			error();
			printf("Expected '*', found %s\n", tokenNames[tok]);
	}
}

void NEG_SIGNTOK() {
	switch (tok) {
		case NEG_SIGN:
			eat(NEG_SIGN);
			break;
		default:
			error();
			printf("Expected '!', found %s\n", tokenNames[tok]);
	}
}

void PLUS_SIGNTOK() {
	switch (tok) {
		case PLUS_SIGN:
			eat(PLUS_SIGN);
			break;
		default:
			error();
			printf("Expected '+', found %s\n", tokenNames[tok]);
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
			error();
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
			error();
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
			error();
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
			error();
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
			error();
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
			error();
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
			T3_();
			break;
		default:
			error();
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
			error();
	}
}

void F() {
	switch (tok) {
		case LPAREN:
			LPARENTOK();
			E();
			RPARENTOK();
			break;
		case IDENTIFIER:
			IDENTIFIERTOK();
			ARRAYACCESS();
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


void ARRAYACCESS() {
	switch (tok) {
		case TERMINATOR:
		case RPAREN:
		case RBRACKET:
		case THEN:
		case ATTR_SIGN:
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
		case MULT_SIGN:
		case DIV_SIGN:
		case MOD_SIGN:
			break;
		case LBRACKET:
			LBRACKETTOK();
			E();
			RBRACKETTOK();
			ARRAYACCESS();
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
			error();
	}
}

void ARRAYTOK() {
	switch (tok) {
		case ARRAY:
			eat(ARRAY);
			break;
		default:
			error();
			printf("Expected 'ARRAY', found %s\n", tokenNames[tok]);
	}
}

void ARRAYTYPE() {
	switch(tok) {
		case ARRAY:
			ARRAYTOK();
			LBRACKETTOK();
			E();
			RBRACKETTOK();
			OFTOK();
			DATATYPE();
			break;
		default:
			error();
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
			ARRAYTYPE();
			break;
		default:
			error();
	}
}

void IDLIST2() {
	switch (tok) {
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
			TERMINATORTOK();
			break;
		default:
			error();
	}
}

void LABELSTMT() {
	switch (tok) {
		case IDENTIFIER:
			IDENTIFIERTOK();
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
		 case GET:
		 case PUT:
		 case IF:
		 case GOTO:
		 case LOOP:
		 case EXITWHEN:
		 case STOP:
			IDLESSSTMT();
			break;
		default:
			error();
	}
}

void STMTLIST() {
	switch (tok) {
		case IDENTIFIER:
		case GET:
		case PUT:
		case IF:
		case GOTO:
		case LOOP:
		case EXITWHEN:
		case STOP:
			SUPERSTMT();
			TERMINATORTOK();
			STMTLIST();
		default:
			break;
	}
}

void IFTOK() {
	switch (tok) {
		case IF:
			eat(IF);
			break;
		default:
			error();
			printf("Expected 'IF', found %s\n", tokenNames[tok]);
	}
}

void ELSETOK() {
	switch (tok) {
		case ELSE:
			eat(ELSE);
			break;
		default:
			error();
			printf("Expected 'ELSE', found %s\n", tokenNames[tok]);
	}
}

void GOTOTOK() {
	switch (tok) {
		case GOTO:
			eat(GOTO);
			break;
		default:
			error();
			printf("Expected 'GOTO', found %s\n", tokenNames[tok]);
	}
}

void LOOPTOK() {
	switch (tok) {
		case LOOP:
			eat(LOOP);
			break;
		default:
			error();
			printf("Expected 'LOOP', found %s\n", tokenNames[tok]);
	}
}

void EXITWHENTOK() {
	switch (tok) {
		case EXITWHEN:
			eat(EXITWHEN);
			break;
		default:
			error();
			printf("Expected 'EXITWHEN', found %s\n", tokenNames[tok]);
	}
}

void STOPTOK() {
	switch (tok) {
		case STOP:
			eat(STOP);
			break;
		default:
			error();
			printf("Expected 'STOP', found %s\n", tokenNames[tok]);
	}
}

void SKIPTOK() {
	switch (tok) {
		case SKIP:
			eat(SKIP);
			break;
		default:
			error();
			printf("Expected 'SKIP', found %s\n", tokenNames[tok]);
	}
}

void THENTOK() {
	switch (tok) {
		case THEN:
			eat(THEN);
			break;
		default:
			error();
			printf("Expected 'THEN', found %s\n", tokenNames[tok]);
	}
}

void ENDIFTOK() {
	switch (tok) {
		case ENDIF:
			eat(ENDIF);
			break;
		default:
			error();
			printf("Expected 'ENDIF', found %s\n", tokenNames[tok]);
	}
}

void ENDLOOPTOK() {
	switch (tok) {
		case ENDLOOP:
			eat(ENDLOOP);
			break;
		default:
			error();
			printf("Expected 'ENDLOOP', found %s\n", tokenNames[tok]);
	}
}

void CHAR_TYPETOK() {
	switch (tok) {
		case CHAR_TYPE:
			eat(CHAR_TYPE);
			break;
		default:
			error();
			printf("Expected 'CHAR', found %s\n", tokenNames[tok]);
	}
}

void INT_TYPETOK() {
	switch (tok) {
		case INT_TYPE:
			eat(INT_TYPE);
			break;
		default:
			error();
			printf("Expected 'INT', found %s\n", tokenNames[tok]);
	}
}

void FLOAT_TYPETOK() {
	switch (tok) {
		case FLOAT_TYPE:
			eat(FLOAT_TYPE);
			break;
		default:
			error();
			printf("Expected 'FLOAT', found %s\n", tokenNames[tok]);
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
	if (noError)
		printf("Successful parsing!\n");
	return 0;
}

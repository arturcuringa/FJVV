#ifndef __ENUM_TOKEN_H__
#define __ENUM_TOKEN_H__

enum token {
	INTEGER,
	FLOAT,
	CHAR,
	IDENTIFIER,
	COMMENT,
	SKIP, 
	PLUS_SIGN,
	MINUS_SIGN,
	DIV_SIGN,
	MOD_SIGN,
	MULT_SIGN,
	LPAREN,
	RPAREN,
	COLON,
	TERMINATOR,
	LBRACKET,
	RBRACKET,
	SEPARATOR,
	EQUAL_SIGN,
	ATTR_SIGN,
	LESS_SIGN,
	LESS_EQ_SIGN,
	GREATER_SIGN,
	GREATER_EQ_SIGN,
	DIFF_SIGN,
	OR_SIGN,
	AND_SIGN,
	NEG_SIGN,
	PLUSPLUS_SIGN,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	ARRAY,
	OF,
	START,
	END,
	PROCEDURE,
	DECLARE,
	GET, 	
	PUT,
	IF,
	ENDIF,
	ELSE,
	THEN,
	GOTO,
	LOOP,
	ENDLOOP,
	EXITWHEN,
	STOP,
	END_OF_FILE,
	TOKENENUMSIZE
};

const char* tokenNames[] = {
    "INTEGER",
    "FLOAT",
    "CHAR",
    "IDENTIFIER",
    "COMMENT",
    "SKIP",
    "PLUS_SIGN",
    "MINUS_SIGN",
    "DIV_SIGN",
    "MOD_SIGN",
    "MULT_SIGN",
    "LPAREN",
    "RPAREN",
    "COLON",
    "TERMINATOR",
    "LBRACKET",
    "RBRACKET",
    "SEPARATOR",
    "EQUAL_SIGN",
    "ATTR_SIGN",
    "LESS_SIGN",
    "LESS_EQ_SIGN",
    "GREATER_SIGN",
    "GREATER_EQ_SIGN",
    "DIFF_SIGN",
    "OR_SIGN",
    "AND_SIGN",
    "NEG_SIGN",
    "PLUSPLUS_SIGN",
    "CHAR_TYPE",
    "INT_TYPE",
    "FLOAT_TYPE",
    "ARRAY",
    "OF",
    "START",
    "END",
    "PROCEDURE",
    "DECLARE",
    "GET",
    "PUT",
    "IF",
    "ENDIF",
    "ELSE",
    "THEN",
    "GOTO",
    "LOOP",
    "ENDLOOP",
    "EXITWHEN",
    "STOP",
    "END_OF_FILE"
};

#endif

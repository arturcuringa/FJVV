%option noyywrap
%option nounput
%option noinput

%{
    #include "enum_token.h"
    unsigned int line = 1;
    unsigned int col = 1;
    void lexeme_status(const char * token_name);
    void update_cursor();
%}

whitespace		 [ \t\r\f]
letter			 [a-zA-Z\$@#]
digit 			 [0-9]
integer			 {digit}+
float			 {digit}*\.{digit}+|{digit}+\.{digit}*
char			 \'(.|"\n")\'
alphanumeric		 ({letter}|{digit})
identifier		 {letter}{alphanumeric}*
comment  		 ~.*
plus_sign 		 "+"
minus_sign 		 "-"
div_sign 		 "/"
mod_sign		 "%"
mult_sign 		 "*"
lparen 			 "("
rparen 			 ")"
colon 			 ":"
terminator		 ";"
lbracket		 "["
rbracket		 "]"
separator                ","
equal_sign               "="
attr_sign                ":="
less_sign		 "<"
less_eq_sign		 "<="
greater_sign		 ">"
greater_eq_sign		 ">="
diff_sign		 "!="
or_sign			 "|"
and_sign		 "&"
neg_sign		 "!"
plusplus_sign		 "++"
char_type     		(?i:char)
int_type		(?i:integer)
float_type		(?i:float)
array			(?i:array)
of			(?i:of)				
start			(?i:start)
end			(?i:end)
procedure               (?i:procedure)
declare 		(?i:declare)
get 			(?i:get)
put 			(?i:put)
if 			(?i:if)
endif 			(?i:endif)
else 			(?i:else)
then 			(?i:then)
goto 			(?i:goto)
loop 			(?i:loop)
endloop 		(?i:endloop)
exitwhen 		(?i:exitwhen)
stop 			(?i:stop)
skip  			(?i:skip)

%%
{whitespace} {col++;}

{char} {
	update_cursor();
	return CHAR;
}

{array} {
	update_cursor();
	return ARRAY;
}

{of} {
	update_cursor();
	return OF;
}

{start} {
	update_cursor();
	return START;
}

{end} {
	update_cursor();
	return END;
}

{procedure} {
	update_cursor();
	return PROCEDURE;
}

{declare} {
	update_cursor();
	return DECLARE;
}

{int_type} {
	update_cursor("int_type");
	return INT_TYPE;
}

{float_type} {
	update_cursor("float_type");
	return FLOAT_TYPE;
}

{char_type} {
	update_cursor("char_type");
	return CHAR_TYPE;
}

{plus_sign} {
	update_cursor("plus_sign");
	return PLUS_SIGN;
}

{minus_sign} {
	update_cursor("minus_sign");
	return MINUS_SIGN;
}

{mod_sign} {
	update_cursor("mod_sign");
	return MOD_SIGN;
}

{div_sign} {
	update_cursor("div_sign");
	return DIV_SIGN;
}

{mult_sign} {
	update_cursor("mult_sign");
	return MULT_SIGN;
}

{equal_sign} {
	update_cursor("equal_sign");
	return EQUAL_SIGN;
}

{attr_sign} {
	update_cursor("attr_sign");
	return ATTR_SIGN;
}

{less_sign} {
	update_cursor("less_sign");
	return LESS_SIGN;
}

{less_eq_sign} {
	update_cursor("less_sign");
	return LESS_EQ_SIGN;
}

{greater_sign} {
	update_cursor("greater_sign");
	return GREATER_SIGN;
}

{greater_eq_sign} {
	update_cursor("greater_sign");
	return GREATER_EQ_SIGN;
}

{diff_sign} {
	update_cursor("diff_sign");
	return DIFF_SIGN;
}

{or_sign} {
	update_cursor("or_sign");
	return OR_SIGN;
}

{and_sign} {
	update_cursor("and_sign");
	return AND_SIGN;
}

{neg_sign} {
	update_cursor("neg_sign");
	return NEG_SIGN;
}

{integer} {
	update_cursor();
	return INTEGER;
}

{float} {
	update_cursor();
	return FLOAT;
}

{separator} {
	update_cursor();
	return SEPARATOR;
}

{lparen} {
	update_cursor();
	return LPAREN;
}

{rparen} {
	update_cursor();
	return RPAREN; 
}

{lbracket} {
	update_cursor();
	return LBRACKET;
}

{rbracket} {
	update_cursor();
	return RBRACKET;
}

{colon} {
	update_cursor();
	return COLON;
}

{terminator} {
	update_cursor();
	return TERMINATOR;
}

{if} {
	update_cursor();
	return IF;
}

{endif} {
	update_cursor();
	return ENDIF;
}

{else} {
	update_cursor();
	return ELSE;
}

{then} {
	update_cursor();
	return THEN;
}

{goto} {
	update_cursor();
	return GOTO;
}

{loop} {
	update_cursor();
	return LOOP;
}

{endloop} {
	update_cursor();
	return ENDLOOP;
}

{exitwhen} {
	update_cursor();
	return EXITWHEN;
}

{stop} {
	update_cursor();
	return STOP;
}

{comment} {update_cursor();}

{identifier} {
	if((size_t)yyleng > 16)
		printf("Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	update_cursor();
	return IDENTIFIER; 
}
. {printf("Error :%s \n", yytext);col++;}

\n {line++;col=1;}

<<EOF>> {return END_OF_FILE;}

%%

void lexeme_status(const char * token_name){
	printf("%25s %25s   (len %zu, line %d, col %u)\n",token_name, yytext, yyleng, line, col);
}

void update_cursor(){
	col += yyleng;
}


%option noyywrap
%option nounput
%option noinput

%{
    #include "enum_token.h"
    unsigned int line = 1;
    unsigned int col = 1;
    void lexema_status(const char * token_name);
    void status_and_update_cursor(const char * token_name);
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
datatype 		{char_type}|{int_type}|{float_type}
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
	status_and_update_cursor("char");
	return CHAR;
}

{array} {
	status_and_update_cursor("array");
	return ARRAY;
}

{of} {
	status_and_update_cursor("of");
	return OF;
}

{start} {
	status_and_update_cursor("start");
	return START;
}

{end} {
	status_and_update_cursor("end");
	return END;
}

{procedure} {
	status_and_update_cursor("procedure");
	return PROCEDURE;
}

{declare} {
	status_and_update_cursor("declare");
	return DECLARE;
}

{datatype} {
	status_and_update_cursor("datatype");
	return DATATYPE;
}

{plus_sign} {
	status_and_update_cursor("plus_sign");
	return PLUS_SIGN;
}

{minus_sign} {
	status_and_update_cursor("minus_sign");
	return MINUS_SIGN;
}

{mod_sign} {
	status_and_update_cursor("mod_sign");
	return MOD_SIGN;
}

{div_sign} {
	status_and_update_cursor("div_sign");
	return DIV_SIGN;
}

{mult_sign} {
	status_and_update_cursor("mult_sign");
	return MULT_SIGN;
}

{equal_sign} {
	status_and_update_cursor("equal_sign");
	return EQUAL_SIGN;
}

{attr_sign} {
	status_and_update_cursor("attr_sign");
	return ATTR_SIGN;
}

{less_sign} {
	status_and_update_cursor("less_sign");
	return LESS_SIGN;
}

{less_eq_sign} {
	status_and_update_cursor("less_sign");
	return LESS_EQ_SIGN;
}

{greater_sign} {
	status_and_update_cursor("greater_sign");
	return GREATER_SIGN;
}

{greater_eq_sign} {
	status_and_update_cursor("greater_sign");
	return GREATER_EQ_SIGN;
}

{diff_sign} {
	status_and_update_cursor("diff_sign");
	return DIFF_SIGN;
}

{or_sign} {
	status_and_update_cursor("or_sign");
	return OR_SIGN;
}

{and_sign} {
	status_and_update_cursor("and_sign");
	return AND_SIGN;
}

{neg_sign} {
	status_and_update_cursor("neg_sign");
	return NEG_SIGN;
}

{integer} {
	status_and_update_cursor("integer");
	return INTEGER;
}

{float} {
	status_and_update_cursor("float");
	return FLOAT;
}

{separator} {
	status_and_update_cursor("separator");
	return SEPARATOR;
}

{lparen} {
	status_and_update_cursor("lparen");
	return LPAREN;
}

{rparen} {
	status_and_update_cursor("rparen");
	return RPAREN; 
}

{lbracket} {
	status_and_update_cursor("lbracket");
	return LBRACKET;
}

{rbracket} {
	status_and_update_cursor("rbracket");
	return RBRACKET;
}

{colon} {
	status_and_update_cursor("colon");
	return COLON;
}

{terminator} {
	status_and_update_cursor("terminator");
	return TERMINATOR;
}

{if} {
	status_and_update_cursor("if");
	return IF;
}

{endif} {
	status_and_update_cursor("endif");
	return ENDIF;
}

{else} {
	status_and_update_cursor("else");
	return ELSE;
}

{then} {
	status_and_update_cursor("then");
	return THEN;
}

{goto} {
	status_and_update_cursor("goto");
	return GOTO;
}

{loop} {
	status_and_update_cursor("loop");
	return LOOP;
}

{endloop} {
	status_and_update_cursor("endloop");
	return ENDLOOP;
}

{exitwhen} {
	status_and_update_cursor("exitwhen");
	return EXITWHEN;
}

{stop} {
	status_and_update_cursor("stop");
	return STOP;
}

{comment} {status_and_update_cursor("comment");}

{identifier} {
	if((size_t)yyleng > 16)
		printf("Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	status_and_update_cursor("identifier");
	return IDENTIFIER; 
}
. {printf("Error :%s \n", yytext);col++;}

\n {line++;col=1;}

%%

void lexema_status(const char * token_name){
	printf("%25s %25s   (len %lu, line %u, col %u)\n",token_name, yytext, yyleng, line, col);
}

void status_and_update_cursor(const char * token_name){
	lexema_status(token_name);
	col += yyleng;
}


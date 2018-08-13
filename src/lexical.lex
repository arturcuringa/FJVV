%option noyywrap
%option nounput
%option noinput

%{
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

%%
{whitespace} {col++;}

{char} {status_and_update_cursor("char");}

{array} {status_and_update_cursor("array");}

{of} {status_and_update_cursor("of");}

{start} {status_and_update_cursor("start");}

{end} {status_and_update_cursor("end");}

{procedure} {status_and_update_cursor("procedure");}

{declare} {status_and_update_cursor("declare");}

{datatype} {status_and_update_cursor("datatype");}

{plus_sign} {status_and_update_cursor("plus_sign");}

{plusplus_sign} {status_and_update_cursor("plusplus_sign");}

{minus_sign} {status_and_update_cursor("minus_sign");}

{mod_sign} {status_and_update_cursor("mod_sign");}

{div_sign} {status_and_update_cursor("div_sign");}

{mult_sign} {status_and_update_cursor("mult_sign");}

{equal_sign} {status_and_update_cursor("equal_sign");}

{attr_sign} {status_and_update_cursor("attr_sign");}

{less_sign} {status_and_update_cursor("less_sign");}

{less_eq_sign} {status_and_update_cursor("less_sign");}

{greater_sign} {status_and_update_cursor("greater_sign");}

{greater_eq_sign} {status_and_update_cursor("greater_sign");}

{diff_sign} {status_and_update_cursor("diff_sign");}

{or_sign} {status_and_update_cursor("or_sign");}

{and_sign} {status_and_update_cursor("and_sign");}

{neg_sign} {status_and_update_cursor("neg_sign");}

{integer} {status_and_update_cursor("integer");}

{float} {status_and_update_cursor("float");}

{separator} {status_and_update_cursor("separator");}

{lparen} {status_and_update_cursor("lparen");}

{rparen} {status_and_update_cursor("rparen");}

{lbracket} {status_and_update_cursor("lbracket");}

{rbracket} {status_and_update_cursor("rbracket");}

{colon} {status_and_update_cursor("colon");}

{terminator} {status_and_update_cursor("terminator");}

{comment} {status_and_update_cursor("comment");}

{identifier} {
	if((size_t)yyleng > 16)
		printf("Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	status_and_update_cursor("identifier");
	 
}
. {printf("Error :%s \n", yytext);col++;}

\n {line++;col=1;}

%%

void lexema_status(const char * token_name){
	printf("%25s %25s   (len %lu, line %u, col %u)\n",token_name, yytext, yyleng, line, col);
}
void status_and_update_cursor(const char * token_name){
	lexema_status(token_name);
	 
}
int main() {
	yylex();
	return 0;
}

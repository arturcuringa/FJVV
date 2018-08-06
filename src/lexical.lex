%option noyywrap
%option nounput
%option noinput

%{
    unsigned int line = 1;
    unsigned int col = 1;
    void lexema_status(const char * token_name);
%}

letter			 [a-zA-Z\$@#]
digit 			 [0-9]
integer			 {digit}+
float			 {digit}*\.{digit}+|{digit}+\.{digit}*
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
[ \t\r] {col++;}

{array} {
	lexema_status("array");
	col += yyleng;
}

{of} {
	lexema_status("of");
	col += yyleng;
}

{start} {
	lexema_status("start");
	col += yyleng;
}

{end} {
	lexema_status("end");
	col += yyleng;
}

{procedure} {
	lexema_status("procedure");
	col += yyleng;
}

{declare} {
	lexema_status("declare");
	col += yyleng;
}

{datatype} {
	lexema_status("datatype");
	col += yyleng;
}

{plus_sign} {
	lexema_status("plus_sign");
	col += yyleng;
}

{minus_sign} {
	lexema_status("minus_sign");
	col += yyleng;
}

{mod_sign} {
	lexema_status("mod_sign");
	col += yyleng;
}

{div_sign} {
	lexema_status("div_sign");
	col += yyleng;
}

{mult_sign} {
	lexema_status("mult_sign");
	col += yyleng;
}

{equal_sign} {
	lexema_status("equal_sign");
	col += yyleng;
}

{attr_sign} {
	lexema_status("attr_sign");
	col += yyleng;
}

{less_sign} {
	lexema_status("less_sign");
	col += yyleng;
}

{less_eq_sign} {
	lexema_status("less_sign");
	col += yyleng;
}

{greater_sign} {
	lexema_status("greater_sign");
	col += yyleng;
}

{greater_eq_sign} {
	lexema_status("greater_sign");
	col += yyleng;
}

{diff_sign} {
	lexema_status("diff_sign");
	col += yyleng;
}

{or_sign} {
	lexema_status("or_sign");
	col += yyleng;
}

{and_sign} {
	lexema_status("and_sign");
	col += yyleng;
}

{integer} {
	lexema_status("integer");
	col += yyleng;
}

{float} {
	lexema_status("float");
	col += yyleng;
}

{separator} {
	lexema_status("separator");
	col += yyleng;
}

{lparen} {
	lexema_status("lparen");
	col += yyleng;
}

{rparen} {
	lexema_status("rparen");
	col += yyleng;
}

{lbracket} {
	lexema_status("lbracket");
	col += yyleng;
}

{rbracket} {
	lexema_status("rbracket");
	col += yyleng;
}

{colon} {
	lexema_status("colon");
	col += yyleng;
}

{terminator} {
	lexema_status("terminator");
	col += yyleng;
}

{comment} {
	lexema_status("comment");
	col += yyleng;
}

{identifier} {
	if((size_t)yyleng > 16)
		printf("Warning: Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	lexema_status("identifier");
	col += yyleng;
}
. {printf("Error :%s", yytext);col++;}

\n {line++;col=1;}

%%

void lexema_status(const char * token_name){
	printf("%15s %15s (len %lu, line %u, col %u)\n",token_name, yytext, yyleng, line, col);
}
int main() {
	yylex();
	return 0;
}

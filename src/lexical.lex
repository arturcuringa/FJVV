%option noyywrap
%option nounput
%option noinput

%{
    unsigned int line = 1;
    unsigned int col = 1;
    void lexema_status(const char * token_name, const  char * yytext, const  size_t yyleng);
%}

letter			 [a-zA-Z\$@#]
digit 			 [0-9]
integer			 {digit}+
float 			{digit}*\.{digit}+|{digit}+\.{digit}*
alphanumeric		 ({letter}|{digit})
identifier		 {letter}{alphanumeric}*
comment  		 ~.*
plus_sign 		 "+"
minus_sign 		 "-"
div_sign 		 "/"
mod_sign			 "%"
mult_sign 		 "*"
lparen 			 "("
rparen 			 ")"
colon 			 ":"
terminator		 ";"
lbracket		 "["
rbracket		 "]"
separator                ","
equal_sign                "="
attr_sign                 ":="
less_sign		 "<"
less_eq_sign		 "<="
greater_sign		 ">"
greater_eq_sign		 ">="
diff_sign		 "!="
or_sign			 "|"
and_sign			 "&"
char_type		(?i:char)
int_type		(?i:integer)
float_type		(?i:float)
datatype 		 {char_type}|{int_type}|{float_type}

%%
\s {col++;}

(?i:array) {
	lexema_status("array", yytext, yyleng);
	col += yyleng;
}

(?i:of) {
	lexema_status("of", yytext, yyleng);
	col += yyleng;
}

(?i:start) {
	lexema_status("start", yytext, yyleng);
	col += yyleng;
}

(?i:end) {
	lexema_status("end", yytext, yyleng);
	col += yyleng;
}

(?i:procedure) {
	lexema_status("procedure", yytext, yyleng);
	col += yyleng;
}

(?i:declare) {
	lexema_status("declare", yytext, yyleng);
	col += yyleng;
}

{datatype} {
	lexema_status("datatype", yytext, yyleng);
	col += yyleng;
}

{plus_sign} {
	lexema_status("plus_sign", yytext, yyleng);
	col += yyleng;
}

{minus_sign} {
	lexema_status("minus_sign", yytext, yyleng);
	col += yyleng;
}

{mod_sign} {
	lexema_status("mod_sign", yytext, yyleng);
	col += yyleng;
}

{div_sign} {
	lexema_status("div_sign", yytext, yyleng);
	col += yyleng;
}

{mult_sign} {
	lexema_status("mult_sign", yytext, yyleng);
	col += yyleng;
}

{equal_sign} {
	lexema_status("equal_sign", yytext, yyleng);
	col += yyleng;
}

{attr_sign} {
	lexema_status("attr_sign", yytext, yyleng);
	col += yyleng;
}

{less_sign} {
	lexema_status("less_sign", yytext, yyleng);
	col += yyleng;
}

{less_eq_sign} {
	lexema_status("less_sign", yytext, yyleng);
	col += yyleng;
}

{greater_sign} {
	lexema_status("greater_sign", yytext, yyleng);
	col += yyleng;
}

{greater_eq_sign} {
	lexema_status("greater_sign", yytext, yyleng);
	col += yyleng;
}

{diff_sign} {
	lexema_status("diff_sign", yytext, yyleng);
	col += yyleng;
}

{or_sign} {
	lexema_status("or_sign", yytext, yyleng);
	col += yyleng;
}

{and_sign} {
	lexema_status("and_sign", yytext, yyleng);
	col += yyleng;
}

{integer} {
	lexema_status("integer", yytext, yyleng);
	col += yyleng;
}

{float} {
	lexema_status("float", yytext, yyleng);
	col += yyleng;
}

{separator} {
	lexema_status("separator", yytext, yyleng);
	col += yyleng;
}

{lparen} {
	lexema_status("lparen", yytext, yyleng);
	col += yyleng;
}

{rparen} {
	lexema_status("rparen", yytext, yyleng);
	col += yyleng;
}

{lbracket} {
	lexema_status("lbracket", yytext, yyleng);
	col += yyleng;
}

{rbracket} {
	lexema_status("rbracket", yytext, yyleng);
	col += yyleng;
}

{colon} {
	lexema_status("colon", yytext, yyleng);
	col += yyleng;
}

{terminator} {
	lexema_status("terminator", yytext, yyleng);
	col += yyleng;
}

{comment} {
	lexema_status("comment", yytext, yyleng);
	col += yyleng;
}

{datatype} {

	lexema_status("datatype", yytext, yyleng);
	col += yyleng;
}

{identifier} {
	if((size_t)yyleng > 16)
		printf("Warning: Identifier %s with more than 16 characters (len %lu, line %u, col %u) \n",yytext, (size_t)yyleng, line, col);
	lexema_status("identifier",yytext, yyleng);
	col += yyleng;
}
. {col++;}
\n {line++;col=1;}

%%
void lexema_status(const char * token_name, const  char * yytext, const  size_t yyleng){
	printf("%s %s (len %lu, line %u, col %u)\n",token_name, yytext, yyleng, line, col);
}

int main() {
	yylex();
	return 0;
}


letter [a-zA-Z\$@#]
digit  [0-9]
integer {digit}+
alphanumeric {letter}|{digit}
identifier {letter}({alphanumeric}){0,15}



%%
[\t] ;
{identifier} {printf("%s, %d: Identifier\n", yytext, yyleng);}

. | \n {ECHO;}

%%

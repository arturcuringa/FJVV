all: bin
	flex lexical.lex
	yacc -d --verbose lalr.y
	gcc lex.yy.c y.tab.c -o bin/bu
debug:
	flex lexical.lex
	yacc -d -t  lalr.y
	gcc lex.yy.c y.tab.c -o bin/bu

bin: 
	mkdir -p bin

all: bin
	lex lexical.lex
	yacc -d lalr.y
	gcc lex.yy.c y.tab.c -o bin/bu
bin: 
	mkdir -p bin

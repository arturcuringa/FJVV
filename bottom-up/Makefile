all: bin
	flex lexical.lex
	yacc -d --verbose lalr.y
	g++ -std=c++11  y.tab.c  -o bin/bu
debug:
	flex lexical.lex
	yacc -d -t  lalr.y
	g++ -std=c++11 y.tab.c -o bin/bu

bin: 
	mkdir -p bin

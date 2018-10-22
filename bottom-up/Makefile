all: bin
	flex lexical.lex
	bison -d --verbose lalr.y
	g++ -std=c++11 lalr.tab.c  -o bin/bu
debug:
	flex lexical.lex
	bison -d -t  lalr.y
	g++ -std=c++11 lalr.tab.c -o bin/bu

bin: 
	mkdir -p bin

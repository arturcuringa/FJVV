all: bin
	cd src/ && flex lexical.lex && cd ..
	gcc -Wall -I include/ src/list_token.c -o bin/list_token

recursive: bin
	gcc -Wall -I include/ src/recursive-descent.c -o bin/recursive

table: bin
	g++ -Wall -I include/ src/table.cpp -std=c++11 -o bin/table

bin:
	mkdir -p bin

clean: bin
	rm -f src/lex.yy.c
	rm -r bin/

lexical:
	./bin/lexical < $(input)

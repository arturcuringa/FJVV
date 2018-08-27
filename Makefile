all: bin
	cd src/ && flex lexical.lex && cd ..
	gcc -Wall -I include/ src/list_token.c -o bin/list_token

recursive: bin
	gcc -Wall -I include/ src/recursive-descent.c -o bin/recursive

bin:
	mkdir -p bin

clean:
	rm src/lex.yy.c 

lexical:
	./bin/lexical < $(input)

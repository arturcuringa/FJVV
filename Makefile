all: bin
	cd src/ && flex lexical.lex && cd ..
	gcc -Wall -I include/ src/lex.yy.c -o bin/lexical

bin:
	mkdir -p bin

clean:
	rm src/lex.yy.c 

lexical:
	./bin/lexical < $(input)

all: bin
	cd src/ && lex lexical.lex && cd ..
	gcc -Wall src/lex.yy.c -o bin/lexical

bin:
	mkdir -p bin

clean:
	rm src/lex.yy.c 

lexical:
	./bin/lexical < $(input)

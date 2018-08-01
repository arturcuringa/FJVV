all:
	cd src/ && lex lexical.lex && cd ..
	gcc src/lex.yy.c -o bin/lexical -lfl

clean:
	rm src/lex.yy.c 

lexical:
	./bin/lexical < $(input)

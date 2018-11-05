ifeq ($(USER), carlosv)
    CXX = g++-7
    FLAGS = -I/usr/local/opt/flex/include -L/usr/local/opt/flex/lib
else
    CXX = g++
endif

all: bin
	flex lexical.l
	bison lalr.y
	$(CXX) -std=c++11 $(FLAGS) lexical.cxx abstract_tree.cpp lalr.cxx code_generator.cpp -o bin/bu
debug: bin
	flex lexical.l
	bison lalr.y
	$(CXX) -std=c++11 $(FLAGS) lexical.cxx abstract_tree.cpp lalr.cxx code_generator.cpp -o bin/bu

bin: 
	mkdir -p bin

clean:
	rm -f bin/bu
	rm -f lalr.cxx
	rm -f lalr.hxx
	rm -f lexical.cxx
	rm -f lexical.hxx
	rm -f location.hh
	rm -f position.hh
	rm -f stack.hh


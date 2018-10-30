ifeq ($(USER), carlosv)
    CXX = g++-7
    FLAGS = -I/usr/local/opt/flex/include -L/usr/local/opt/flex/lib
else
    CXX = g++
endif

all: bin
	flex lexical.l
	bison lalr.y
	$(CXX) -std=c++11 $(FLAGS) lexical.cxx abstract_tree.cpp lalr.cxx -o bin/bu
debug:
	flex lexical.l
	bison lalr.y
	$(CXX) -std=c++11 $(FLAGS) lexical.cxx abstract_tree.cpp lalr.cxx -o bin/bu

bin: 
	mkdir -p bin

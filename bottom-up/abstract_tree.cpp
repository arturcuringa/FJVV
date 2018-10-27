#include "abstract_tree.h"

void Expr::print(){
	std::string nameStar = *(name);
	std::cout << "{\"" << nameStar << "\":";
	if(nameStar == "BinOp"){
	        BinOp* b = (BinOp*) this;
		std::cout << "{";
		std::cout << "\"op\": \'" <<  b->op << "\'";
		std::cout << ", ";
	        std::cout << "\"lhs\": " ;
		b->lhs->print();
		std::cout << ", ";
		std::cout << "\"rhs\":";
		b->rhs->print();
		std::cout << "}";
	}
	if(nameStar == "Literal"){
		Literal* l = (Literal*) this;
		std::cout << "{\"val\":";
		std::cout << l->i << "}";
	}
	std::cout << "}";
}

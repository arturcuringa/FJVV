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
	if(nameStar == "UnOp"){
		UnOp* u = (UnOp*) this;
		std::cout << "{";
		std::cout << "\"op\": \'" << u->op << "\'";
		std::cout << ", ";
		std::cout << "\"expr\": ";
	        u->expr->print();
		std::cout<< "}";	
	}
	if(nameStar == "Access"){
		Access* a = (Access*) this;
		std::cout << "{ \"id\": \"" << *(a->id) << "\"";
		if(!a->indexes.empty()){
			std::cout << ", \"indexes\": [";
			for(auto i = 0; i < a->indexes.size(); i++){
				a->indexes[i]->print();
				if(i != a->indexes.size() -1){
					std::cout << ", "; 
				}
			}
			std::cout << "]";
		}
		std::cout << "}";
	}
	std::cout << "}";
}

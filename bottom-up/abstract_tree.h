#ifndef __ABS_TREE__
#define __ABS_TREE__

#include <vector>
#include <string>
#include <iostream>

enum class  SimpleType {ST_INT, ST_FLOAT, ST_CHAR};

struct Type{
	SimpleType type;
	std::vector<int> sizes;
	
};

struct Node {
	std::string*  name;
	void print(){
		std::cout << "{ \"" << *(name) << "\":{ ";	
	};
};

struct VarDec : Node {
	VarDec(){
		name = new std::string( "VarDec");
	}
	void print(){
		std::cout << "{\"" << *(name) << "\":[";	
			for(int i = 0; i < ids.size(); i++){
				std::cout<< "\"" << *(ids[i]) << "\"";
				if(i != ids.size() -1){
					std::cout<<", ";
				}
			}
			std::cout << "]}";
	};
	std::vector<std::string*> ids;
	std::vector<Type*> type;
};

struct Stmt : Node {
	std::string label;	
};

struct ProDec : Node {
	std::string id;
	std::vector<std::string> params;
	std::vector<Stmt> stmts;
};

struct Program : Node {
	Program(){
		name =  new std::string("Program");
	}
	~Program(){
		delete name;
	}
	void print(){
	
		std::cout << "{ \"" << *(name) << "\": [";
		if(this->var_dec != nullptr){
                       for(auto i = 0; i < this->var_dec->size(); i++){
                               this->var_dec->operator[](i)->print();
			       if(i != this->var_dec->size() -1)
				       std::cout << ", ";
                       }
                }
		std::cout << "]}";


	}
	std::vector<VarDec*>* var_dec;
	std::vector<ProDec*>* pro_dec;
	std::vector<Stmt*>* stmts;
};

struct Expr : Node {
	Expr(){
		name = new std::string("Expr");
	}
	~Expr(){
		delete name;
	}
	void print();
	Type type;
};

struct BinOp : Expr {
	BinOp(){
		name = new std::string("BinOp");
	}
	~BinOp(){
		delete name;
	}
	char op;
	Expr* lhs;
	Expr* rhs;
};

struct Post_Labelless_Stmt : Node {
	Post_Labelless_Stmt(){
		name = new std::string("Post_Labelless_Stmt");
	}
	~Post_Labelless_Stmt(){
		delete name;
	}
	void print();
	std::string* label;

};

struct AttrStmt : Post_Labelless_Stmt {
	AttrStmt(){
		name = new std::string("AttrStmt");
	}
	~AttrStmt(){
		delete name;
	}
	void print(){
		std::cout << "{ \"" << *(this->name) << "\": {";
		std::cout << "\"lhs\":" << "\"" << this->label << "\"";
		std::cout << "[";
	        if(lhs != nullptr){
			for(auto i = 0; i < lhs->size(); i++){
				lhs->operator[](i)->print();
				if(i != lhs->size() - 1)
					std::cout << ", ";
			}
		}
		std::cout << "], \"rhs\": ";
	       	if(rhs != nullptr){
			rhs->print();
		}
	}
	std::vector<Expr*>* lhs;
	Expr* rhs;
};


struct UnOp : Expr {
	UnOp(){
		name = new std::string("UnOp");
	}
	~UnOp(){
		delete name;
	}
	int op;
	Expr* expr;
};

struct Access : Expr {
	Access(){
		name = new std::string("Access");
	}
	~Access(){
		delete name;
	}
	std::string* id;
	std::vector<Expr*> indexes;
};

struct Literal : Expr {
	Literal(){
		name = new std::string("Literal");
	}
	~Literal(){
		delete name;
	}
	union{
		int i;
		float f;
		char c;
	};
	SimpleType type;
};


using DecList = std::vector<VarDec*>;
using ProList = std::vector<ProDec>;
using StmtList = std::vector<Stmt>;

#endif

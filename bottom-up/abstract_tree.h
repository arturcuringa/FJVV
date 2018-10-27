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
		std::cout << *(name) << " ";	
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
	std::vector<VarDec*>* var_dec;
	std::vector<ProDec*>* pro_dec;
	std::vector<Stmt*>* stmts;
};

struct Expr : Node {
	Expr(){
		name = new std::string("Expr");
	}
	void print();
	Type type;
};

struct BinOp : Expr {
	BinOp(){
		name = new std::string("BinOp");
	}
	char op;
	Expr* lhs;
	Expr* rhs;
};

struct AttrStmt : Stmt {
	std::string lhs;
	Expr rhs;
};


struct UnOp : Expr {
	int op;
	Expr expr;
};

struct Access : Expr {
	std::string id;
	std::vector<int> indexes;
};

struct Literal : Expr {
	Literal(){
		name = new std::string("Literal");
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

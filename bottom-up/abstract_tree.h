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
	std::string name;
	void print(){
		std::cout << "{ \"" << name << "\":{ ";	
	};
};

struct VarDec : Node {
	VarDec(){
		name = std::string("VarDec");
	}
	void print(){
		std::cout << "{\"" << name << "\":[";	
			for(int i = 0; i < ids.size(); i++){
				std::cout<< "\"" << ids.operator[](i) << "\"";
				if(i != ids.size() -1){
					std::cout<<", ";
				}
			}
			std::cout << "]}";
	};
	std::vector<std::string> ids;
	std::vector<Type> type;
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
		name = std::string("Program");
	}
	~Program(){
	}
	void print(){
		std::cout << "{ \"" << name << "\": [";
       	for (auto i = 0; i < this->var_dec.size(); i++){
           	this->var_dec.operator[](i).print();
	       	if (i != this->var_dec.size() -1) {
		    	std::cout << ", ";
	       	}
        }
		std::cout << "]}";
	}

	std::vector<VarDec> var_dec;
	std::vector<ProDec> pro_dec;
	std::vector<Stmt> stmts;
};

struct Expr : Node {
	Expr(){
		name = std::string("Expr");
	}
	~Expr(){
	}
	void print();
	Type type;
};

struct BinOp : Expr {
	BinOp(){
		name = std::string("BinOp");
	}
	~BinOp(){
	}
	char op;
	Expr lhs;
	Expr rhs;
};

struct Post_Labelless_Stmt : Node {
	Post_Labelless_Stmt(){
		name = std::string("Post_Labelless_Stmt");
	}
	~Post_Labelless_Stmt(){
	}
	void print();
	std::string label;

};

struct AttrStmt : Post_Labelless_Stmt {
	AttrStmt(){
		name = std::string("AttrStmt");
	}
	~AttrStmt(){
	}
	void print(){
		std::cout << "{ \"" << name << "\": {";
		std::cout << "\"lhs\":" << "\"" << label << "\", ";
		std::cout << "\"indexes\": [";
		for (auto i = 0; i < lhs.size(); i++){
			lhs.operator[](i).print();
			if(i != lhs.size() - 1)
				std::cout << ", ";
		}
		std::cout << "], \"rhs\": ";
		rhs.print();
	}
	std::vector<Expr> lhs;
	Expr rhs;
};


struct UnOp : Expr {
	UnOp(){
		name = std::string("UnOp");
	}
	~UnOp(){
	}
	int op;
	Expr expr;
};

struct Access : Expr {
	Access(){
		name = std::string("Access");
	}
	~Access(){
	}
	std::string id;
	std::vector<Expr> indexes;
};

struct Literal : Expr {
	Literal(){
		name = std::string("Literal");
	}
	~Literal(){
	}
	union{
		int i;
		float f;
		char c;
	};
	SimpleType type;
};


using DecList = std::vector<VarDec>;
using ProList = std::vector<ProDec>;
using StmtList = std::vector<Stmt>;

#endif

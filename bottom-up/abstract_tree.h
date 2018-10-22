#ifndef __ABS_TREE__
#define __ABS_TREE__

#include <vector>
#include <string>

enum class  SimpleType {ST_INT, ST_FLOAT, ST_CHAR};



struct Type{
	SimpleType type;
	std::vector<int> sizes;
	
};

struct Node {
	int name;
};

struct VarDec : Node {
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
	std::vector<VarDec> var_dec;
	std::vector<ProDec> pro_dec;
	std::vector<Stmt> stmts;
};

struct Expr : Node {
	
};

struct AttrStmt : Stmt {
	std::string lhs;
	Expr rhs;
};

struct BinOp : Expr {
	int op;
	Expr lhs;
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
	union {
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

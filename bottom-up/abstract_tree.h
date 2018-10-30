#ifndef __ABS_TREE__
#define __ABS_TREE__

#include <vector>
#include <string>
#include <iostream>

enum struct  SimpleType {ST_INT, ST_FLOAT, ST_CHAR};

struct Type {
	SimpleType type;
	std::vector<int> sizes;
};

struct Node {
	Node() : name("") {}
	Node(std::string _n) : name(_n) {}

	std::string name;
	friend std::ostream& operator<<(std::ostream& out, const Node& n);
};

struct VarDec : Node {
	VarDec() : Node("VarDec") {}

	std::vector<std::string> ids;
	std::vector<Type> type;
	friend std::ostream& operator<<(std::ostream& out, const VarDec& vd);
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
	Program() : Node("Program") {}

	std::vector<VarDec> var_dec;
	std::vector<ProDec> pro_dec;
	std::vector<Stmt> stmts;
	friend std::ostream& operator<<(std::ostream& out, const Program& p);
};

struct Expr : Node {
	Expr() : Node("Expr") {}
	Expr(std::string _n) : Node(_n) {}

	Type type;
	friend std::ostream& operator<<(std::ostream& out, const Expr& e);
};

struct BinOp : Expr {
	BinOp() : Expr("BinOp") {}

	char op;
	Expr lhs;
	Expr rhs;
};

struct Post_Labelless_Stmt : Node {
	Post_Labelless_Stmt() : Node("PostLabellessStmt") {}
	Post_Labelless_Stmt(std::string _n) : Node(_n) {}

	std::string label;
	friend std::ostream& operator<<(std::ostream& out, const Post_Labelless_Stmt& pls);
};

struct AttrStmt : Post_Labelless_Stmt {
	AttrStmt() : Post_Labelless_Stmt("AttrStmt") {}

	std::vector<Expr> lhs;
	Expr rhs;
	friend std::ostream& operator<<(std::ostream& out, const AttrStmt& as);
};


struct UnOp : Expr {
	UnOp() : Expr("UnOp") {}

	int op;
	Expr expr;
};

struct Access : Expr {
	Access() : Expr("Access") {}

	std::string id;
	std::vector<Expr> indexes;
};

struct Literal : Expr {
	Literal() : Expr("Literal") {}
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

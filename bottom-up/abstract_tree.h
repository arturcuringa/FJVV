#ifndef __ABS_TREE__
#define __ABS_TREE__

#include <vector>
#include <string>
#include <iostream>
#include <memory>

enum struct SimpleType {ST_INT, ST_FLOAT, ST_CHAR};

struct Node {
	Node() : name("") {}
	Node(std::string _n) : name(_n) {}

	std::string name;
	friend std::ostream& operator<<(std::ostream& out, const Node& n);
};

struct Expr : Node {
	Expr() : Node("Expr") {}
	Expr(std::string _n) : Node(_n) {}

	SimpleType type;
	friend std::ostream& operator<<(std::ostream& out, const Expr& e);
};

struct Type {
	SimpleType type;
	std::vector<std::shared_ptr<Expr>> dimensions;
	friend std::ostream& operator<<(std::ostream& out, const Type& t);
};

struct VarDec : Node {
	VarDec() : Node("VarDec") {}

	std::vector<std::string> ids;
	Type type;
	friend std::ostream& operator<<(std::ostream& out, const VarDec& vd);
};

struct Stmt : Node {
	Stmt() : Node("Stmt") {}
	Stmt(std::string _n) : Node(_n) {}

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

struct BinOp : Expr {
	BinOp() : Expr("BinOp") {}

	char op;
	Expr lhs;
	Expr rhs;
};

struct AttrStmt : Stmt {
	AttrStmt() : Stmt("AttrStmt") {}

	std::vector<Expr> lhs;
	Expr rhs;
	friend std::ostream& operator<<(std::ostream& out, const AttrStmt& as);
};

struct ProcStmt : Stmt {
	ProcStmt() : Stmt("AttrStmt") {}

	std::string id;
	std::vector<std::shared_ptr<Expr>> args;
	friend std::ostream& operator<<(std::ostream& out, const ProcStmt& as);
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
using ExprList = std::vector<std::shared_ptr<Expr>>;

#endif

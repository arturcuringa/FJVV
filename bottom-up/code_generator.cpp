#include <iostream>
#include <sstream>
#include "code_generator.h"
#include "abstract_tree.h"

unsigned int if_counter   = 0;
unsigned int loop_counter = 0; 

std::string getIOType(std::string s) {
	if (s == "int") {
		return "%i";
	} else if (s == "float") {
		return "%f";
	} else if (s == "bool") {
		return "%d";
	} else if (s == "char") {
		return "%c";
	}
}

std::string getType(std::string id) {
	if(type == "int" || type == "float" || type == "bool" || type == "char") {
		return type;
	}
}

void generateCode(const Node& n) {
    std::cout << "// Not implemented\n";
}

void generateCode(const Program& p) {
    std::cout << "\n";

    generateCode(p.var_dec);
    generateCode(p.pro_dec);
    std::cout << "int main() {\n";
    generateCode(p.stmts, -1);
    std::cout << "}\n";
}

void generateCode(const VarDec& vd) {
    std::string type;

    if (vd.type.type == ST_INT) type = "int";
    if (vd.type.type == ST_FLOAT) type = "float";
    if (vd.type.type == ST_CHAR) type = "char";

    std::string dimensions;
    for (auto &dim : vd.type.dimensions) {
        dimensions += "[";
        dimensions += parseExpr(dim);
        dimensions += "]";
    }

    std::cout << type << " ";
    for (int i = 0; i < vd.ids.size(); i++) {
        if (i != 0) std::cout << ", ";
        std::cout << vd.ids[i] << dimensions;
    }
    std::cout << ";\n";
}

void generateCode(const std::shared_ptr<Stmt>& stmt, int loop_scope) {
	if (!stmt->label.empty()){
		std::cout << stmt->label << ": ";
	}
	if (stmt->name == "AttrStmt") {
		auto a = ( AttrStmt* ) stmt.get();
		std::cout << a->id << " = " << parseExpr(a->rhs);
	} else if (stmt->name == "IfStmt"){
		auto i       = ( IfStmt* ) stmt.get();
		auto counter = if_counter++;		
		auto expr    = parseExpr(i->expr);

		std::cout << "if ( "       << expr << " )"
			  << " goto  _if"  << counter << ";\n";
		
		generateCode(i->falseBlock, loop_scope);

		std::cout << "goto _endif" << counter << ";\n";	
		std::cout << "_if" << counter << ": ";

		generateCode(i->trueBlock, loop_scope);

		std::cout << "_endif" << counter << ": ";
		
				
	} else if (stmt->name == "LoopStmt"){
		auto l         = ( LoopStmt* ) stmt.get();
		auto counter   = loop_counter++;
		
		std::cout << "_loop" << counter << ":";
		
		generateCode(l->block, counter);

		std::cout << "goto _loop" << counter << ";\n";

		std::cout << "_endloop" << counter << ":";
   } else if (stmt->name == "ExitStmt") {
        auto e = (ExitStmt*) stmt.get();
        auto expr = parseExpr(e->expr);
        std::cout << "if ( "       << expr << " )"
            << " goto _endloop" << loop_scope;

	 } else if (stmt->name == "GotoStmt"){
		auto g = (GotoStmt*) stmt.get();
		
		std::cout << "goto " << g->id ;
	
	 } else if (stmt->name == "PutStmt"){
		auto p = (PutStmt*) stmt.get();
		std::cout << " skip ( " << expr << " ) ";		

	 } else if (stmt->name == "GetStmt") {
		auto g = (GetStmt*) stmt.get();
		std::cout << " scanf(\"" + getType(g) + "\", g->id); " ;
	} else
		std::cout << "//Not Implemented";

	std::cout << ";\n";
}

template <class T>
void generateCode(const std::vector<T>& list) {
    for (auto &e : list) {
        generateCode(e);
    }
}

void generateCode(const std::vector<std::shared_ptr<Stmt>>& list, int loop_scope) {
    for (auto &e : list) {
        generateCode(e, loop_scope);
    }
}

std::string parseExpr(const std::shared_ptr<Expr>& expr) {
    std::stringstream ss("");
    if (expr->name == "BinOp") {
        auto b = (BinOp*) expr.get();
        ss << parseExpr(b->lhs) << " " << b->op << " " << parseExpr(b->rhs);
    } else if (expr->name == "UnOp") {
        auto u = (UnOp*) expr.get();
        if (u->op == 'p') {
            ss << "(" << parseExpr(u->expr) << ")";
        } else {
            ss << u->op << parseExpr(u->expr);
        }
    } else if (expr->name == "Literal") {
        auto l = (Literal*) expr.get();
        if (l->type == SimpleType::ST_INT)
            ss << std::to_string(l->i);
        else if (l->type == SimpleType::ST_FLOAT)
            ss << std::to_string(l->f);
        else if (l->type == SimpleType::ST_CHAR) {
            ss << "\'";
            ss << l->c; 
            ss << "\'";
        }
    } else if (expr->name == "Access") {
        auto a = (Access*) expr.get();
	ss << a->id;
        for (auto i : a->indexes) {
            ss <<  "[" << parseExpr(i) << "]";
        }
    }
    return ss.str();
}

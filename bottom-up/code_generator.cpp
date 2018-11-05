#include <iostream>
#include "code_generator.h"
#include "abstract_tree.h"

void generateCode(const Node& n) {
    std::cout << "// Not implemented\n";
}

void generateCode(const Program& p) {
    std::cout << "\n";

    generateCode(p.var_dec);
    generateCode(p.pro_dec);
    std::cout << "int main() {\n";
    generateCode(p.stmts);
    std::cout << "}\n";
}

void generateCode(const VarDec& vd) {
    std::string type;

    if (vd.type.type == ST_INT) type = "int";
    if (vd.type.type == ST_FLOAT) type = "float";
    if (vd.type.type == ST_CHAR) type = "char";

    std::string dimensions;
    for (auto &dim : vd.type.dimensions) {
        dimensions += "[" + parseExpr(dim) + "]";
    }

    std::cout << type << " ";
    for (int i = 0; i < vd.ids.size(); i++) {
        if (i != 0) std::cout << ", ";
        std::cout << vd.ids[i] << dimensions;
    }
    std::cout << ";\n";
}

void generateCode(const std::shared_ptr<Stmt>& stmt) {
    std::cout << "// Not implemented\n";
}

template <class T>
void generateCode(const std::vector<T>& list) {
    for (auto &e : list) {
        generateCode(e);
    }
}

// TODO
std::string parseExpr(const std::shared_ptr<Expr>& expr) {
    return "4";
}
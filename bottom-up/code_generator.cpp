#include <iostream>
#include "code_generator.h"

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

void generateCode(const std::shared_ptr<Stmt>& stmt) {
    std::cout << "// Not implemented\n";
}

template <class T>
void generateCode(const std::vector<T>& list) {
    for (auto e : list) {
        generateCode(e);
    }
}
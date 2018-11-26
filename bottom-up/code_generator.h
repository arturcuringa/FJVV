#ifndef __GENERATOR__
#define __GENERATOR__

#include <memory>
#include <unordered_map>
#include "abstract_tree.h"
#include "symbol_table.h"

struct ActivationRegistry {
    std::unique_ptr<ActivationRegistry> parent;
    std::unique_ptr<ActivationRegistry> scopeParent;
    
    std::unordered_map<std::string, void*> memory;
};

extern SymbolTable sym_table;

void generateCode(const Node& node);
void generateCode(const Program& p);
void generateCode(const ProDec& pd);
void generateCode(const std::shared_ptr<Stmt>& stmt, int loop_counter);

template <class T>
void generateCode(const std::vector<T>& list);

template <>
void generateCode(const std::vector<ProDec>& list);

void generateCode(const std::vector<std::shared_ptr<Stmt>>& list, int loop_scope);

std::string parseExpr(const std::shared_ptr<Expr>& expr);

#endif

#ifndef __GENERATOR__
#define __GENERATOR__

#include <memory>
#include <unordered_map>
#include "abstract_tree.h"
#include "symbol_table.h"

struct ActivationRecord {
    std::shared_ptr<ActivationRecord> parent;
    std::shared_ptr<ActivationRecord> scopeParent;
    
    std::unordered_map<std::string, void*> memory;
    int _return;
};

extern SymbolTable sym_table;

void __instantiate(const std::string &name, void* ptr);
void* __allocate(const std::deque<std::shared_ptr<Expr>> &dimensions, int typeSize);
void __createNewActivationRecord();
void* __access(const std::string &name);
std::string generateAccessCode(const std::string &name);

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

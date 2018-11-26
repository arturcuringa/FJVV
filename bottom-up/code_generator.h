#ifndef __GENERATOR__
#define __GENERATOR__

#include <memory>
#include <unordered_map>
#include "abstract_tree.h"

struct ActivationRegistry {
    std::shared_ptr<ActivationRegistry> parent;
    std::shared_ptr<ActivationRegistry> scopeParent;
    
    std::unordered_map<std::string, void*> memory;
};

extern unsigned int if_counter;
extern unsigned int loop_counter;

void instantiate(const std::string &name, void* ptr);

void generateCode(const Node& node);
void generateCode(const Program& p);
void generateCode(const std::shared_ptr<Stmt>& stmt, int loop_counter);
void generateCode(const ProDec& p);

template <class T>
void generateCode(const std::vector<T>& list);

template <>
void generateCode(const std::vector<std::shared_ptr<Stmt>>& list);

std::string parseExpr(const std::shared_ptr<Expr>& expr);

#endif

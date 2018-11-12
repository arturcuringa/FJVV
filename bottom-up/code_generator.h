#ifndef __GENERATOR__
#define __GENERATOR__

#include <memory>
#include "abstract_tree.h"


extern unsigned int if_counter;
void generateCode(const Node& node);
void generateCode(const Program& p);
void generateCode(const std::shared_ptr<Stmt>& stmt);

template <class T>
void generateCode(const std::vector<T>& list);

std::string parseExpr(const std::shared_ptr<Expr>& expr);

#endif

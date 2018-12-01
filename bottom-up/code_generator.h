#ifndef __GENERATOR__
#define __GENERATOR__

#include <memory>
#include <unordered_map>
#include "abstract_tree.h"
#include "symbol_table.h"
#include "activationRecord.h"


extern SymbolTable sym_table;
using ParsedExpr = std::pair<SimpleType, std::string>;

std::string generateAccessCode(const std::string &name);
int getTypeSize(const std::deque<std::shared_ptr<Expr>> &dimensions, SimpleType type);

void generateCode(const Node& node);
void generateCode(const Program& p);

void generateCode(const ProDec& pd);
void generateCode(const std::shared_ptr<Stmt>& stmt, int loop_counter);

template <class T>
void generateCode(const std::vector<T>& list);

template <>
void generateCode(const std::vector<ProDec>& list);

void generateCode(const std::vector<std::shared_ptr<Stmt>>& list, int loop_scope);

SimpleType operateTypes(char op, SimpleType lhs, SimpleType rhs);

ParsedExpr parseExpr(const std::shared_ptr<Expr>& expr);

#endif

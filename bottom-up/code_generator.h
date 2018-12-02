#ifndef __GENERATOR__
#define __GENERATOR__

#include <memory>
#include <unordered_map>
#include "abstract_tree.h"
#include "symbol_table.h"
#include "activationRecord.h"


extern SymbolTable sym_table;
using ParsedExpr = std::pair<SimpleType, std::string>;

std::string generateAccessCode(const std::string &id, const std::vector<std::string>& indexes, bool onParent);
int getTypeSize(const std::deque<std::shared_ptr<Expr>> &dimensions, SimpleType type);

void prePopulateSymbolTable(const Program& program);

std::string generateCode(const Node& node);
std::string generateCode(const Program& p);

std::string generateCode(const ProDec& pd);
std::string generateCode(const std::shared_ptr<Stmt>& stmt, int loop_counter);

template <class T>
std::string generateCode(const std::vector<T>& list);

template <>
std::string  generateCode(const std::vector<ProDec>& list);
std::string  generateCode(const std::vector<std::shared_ptr<Stmt>>& list, int loop_scope);

SimpleType operateTypes(char op, SimpleType lhs, SimpleType rhs);

ParsedExpr parseExpr(const std::shared_ptr<Expr>& expr);
ParsedExpr parseExpr(const std::shared_ptr<Expr>& expr, bool onParent);

#endif

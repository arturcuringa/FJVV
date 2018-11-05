#pragma once

#include <memory>
#include "abstract_tree.h"


void generateCode(const Node& node);
void generateCode(const Program& p);
void generateCode(const std::shared_ptr<Stmt>& stmt);

template <class T>
void generateCode(const std::vector<T>& list);
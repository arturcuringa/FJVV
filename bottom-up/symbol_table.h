#ifndef __SYMBOL_TABLE__
#define __SYMBOL_TABLE__

#include "abstract_tree.h"
#include <stack>
#include <unordered_map>

class SymbolTable {
public:
	static const std::string scope_symbol;
	
	SymbolTable();
	void start_scope();
	void add_symbol(std::string id, Type type);
	Type get_symbol(std::string id);
	void end_scope();

	unsigned if_counter;
	unsigned loop_counter;
	std::unordered_map<std::string, unsigned> proc_counters;
	std::unordered_map<std::string, unsigned> proc_calls;
	std::unordered_map<std::string, ProDec> procedures;

	std::unordered_map<std::string, std::stack<Type>> symbol_table;
	std::stack<std::string> scope_stack;
};

#endif
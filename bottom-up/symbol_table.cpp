#include "symbol_table.h"

const std::string SymbolTable::scope_symbol = "_";

SymbolTable::SymbolTable() : if_counter(0), loop_counter(0) {}

void SymbolTable::start_scope() {
    this->scope_stack.push(SymbolTable::scope_symbol);
}

void SymbolTable::add_symbol(std::string id, Type type) {
    this->scope_stack.push(id);
    this->symbol_table[id].push(type);
}

Type SymbolTable::get_symbol(std::string id) {
    auto itSymbol = this->symbol_table.find(id);
    if (itSymbol != symbol_table.end())
        return itSymbol->second.top();

    std::cout << "Variable " << id << " is undeclared";
    return Type();
}

void SymbolTable::end_scope() {
    while (this->scope_stack.top() != SymbolTable::scope_symbol) {
        auto sym = this->scope_stack.top();
        this->scope_stack.pop();
        this->symbol_table[sym].pop();
    }

    this->scope_stack.pop();
}
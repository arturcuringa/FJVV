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

void SymbolTable::end_scope() {
    while (this->scope_stack.top() != SymbolTable::scope_symbol) {
        auto sym = this->scope_stack.top();
        this->scope_stack.pop();
        this->symbol_table[sym].pop();
    }

    this->scope_stack.pop();
}
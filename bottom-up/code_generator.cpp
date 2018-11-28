#include <iostream>
#include <sstream>
#include "code_generator.h"
#include "abstract_tree.h"

SymbolTable sym_table;

std::shared_ptr<ActivationRecord> currentActivationRegistry;
std::shared_ptr<ActivationRecord> mainActivationRegistry;

int getTypeSize(const std::deque<std::shared_ptr<Expr>> &dimensions, SimpleType type) {
    int size = 1;
    for (auto e : dimensions) {
        size *= ((Literal *) e.get())->i;
    }

    switch (type) {
        case ST_CHAR: return size * sizeof(char);
        case ST_FLOAT: return size * sizeof(float);
        case ST_INT: return size * sizeof(int);
    }
}

void __startActivationRecord() {
    __createNewActivationRecord();
    mainActivationRegistry = currentActivationRegistry;
}

void* __allocate(int typeSize) {
    return new void*[typeSize];
}

void __instantiate(const std::string &name, void* ptr) {
    currentActivationRegistry->memory.insert({name, ptr});
}

void __createNewActivationRecord() {
    std::shared_ptr<ActivationRecord> ar = std::shared_ptr<ActivationRecord>(new ActivationRecord());
    ar->parent = currentActivationRegistry;
    ar->scopeParent = mainActivationRegistry;
    currentActivationRegistry = ar;
}

void __destroyActivationRecord() {
    currentActivationRegistry = currentActivationRegistry->parent;
}

void* __access(const std::string &name) {
    return currentActivationRegistry->memory.find(name)->second;
}

std::string generateAccessCode(const std::string &id, const std::vector<std::string>& indexes) {
    std::stringstream indexStr;

    auto symbol = sym_table.get_symbol(id);

    for (int i = 0; i < symbol.dimensions.size(); i++) {
        indexStr << "+" << indexes[i];
        for (int j = i+1; j < symbol.dimensions.size(); j++) indexStr << "*" << symbol.dimensions[j];
    }

    std::stringstream ss;
    switch (symbol.type) {
        case ST_INT: 
            ss << "*(((int*) __access(\"" << id << "\"))";
            break;
        case ST_FLOAT:
            ss << "*(((float*) __access(\"" << id << "\"))";
            break;
        case ST_CHAR:
            ss << "*(((char*) __access(\"" << id << "\"))";
            break;
    }

    ss << indexStr.str() << ")";
    return ss.str();
}

void generateCode(const Node& n) {
    std::cout << "// Not implemented\n";
}

void generateCode(const ProDec& pd) {
    sym_table.proc_calls[pd.id] = sym_table.proc_counters[pd.id];
    std::cout << "proc_" << pd.id << ":\n";
    generateCode(pd.stmts, -1);
    std::cout << "switch ( __access(\"" << pd.id << "\"){\n";
    for(auto i = 0; i < sym_table.proc_calls[pd.id]; i++){
    	std::cout << "case " << i << ": goto return_" << pd.id << i << ";"; 
    }
    std::cout << "\n}\n";

    for (auto vd : pd.params) {
        for (auto id : vd.ids) {
            sym_table.add_symbol(id, vd.type);
        }
    }
}

void generateCode(const Program& p) {
    for (auto &pd : p.pro_dec) {
        sym_table.proc_counters[pd.id] = 0;
        sym_table.proc_calls[pd.id] = 0;
    }

    std::cout << "\n";

    sym_table.start_scope();
    generateCode(p.var_dec);
    std::cout << "int main() {\n";
    generateCode(p.stmts, -1);
    generateCode(p.pro_dec);
    std::cout << "}\n";
    sym_table.end_scope();
}

void generateCode(const VarDec& vd) {
    for (auto id : vd.ids) {
        sym_table.add_symbol(id, vd.type);
        std::cout << "__instantiate(\"" << id << "\", __allocate(" << getTypeSize(vd.type.dimensions, vd.type.type) << "));\n";
    }
}

void generateCode(const std::shared_ptr<Stmt>& stmt, int loop_scope) {
	if (!stmt->label.empty()){
		std::cout << stmt->label << ": ";
	}
	if (stmt->name == "AttrStmt") {
		auto a = ( AttrStmt* ) stmt.get();
        std::vector<std::string> indexes;
        for (auto i : a->lhsIndexes) indexes.push_back(parseExpr(i));

		std::cout << generateAccessCode(a->id, indexes) << " = " << parseExpr(a->rhs);
	} else if (stmt->name == "IfStmt"){
		auto i       = ( IfStmt* ) stmt.get();
		auto counter = sym_table.if_counter++;		
		auto expr    = parseExpr(i->expr);

		std::cout << "if ( "       << expr << " )"
			  << " goto  _if"  << counter << ";\n";
		
		generateCode(i->falseBlock, loop_scope);

		std::cout << "goto _endif" << counter << ";\n";	
		std::cout << "_if" << counter << ": ";

		generateCode(i->trueBlock, loop_scope);

		std::cout << "_endif" << counter << ": ";	
	} else if (stmt->name == "LoopStmt"){
		auto l         = ( LoopStmt* ) stmt.get();
		auto counter   = sym_table.loop_counter++;
		
		std::cout << "_loop" << counter << ":";
		
		generateCode(l->block, counter);

		std::cout << "goto _loop" << counter << ";\n";

		std::cout << "_endloop" << counter << ":";
        } else if (stmt->name == "ExitStmt") {
                auto e = (ExitStmt*) stmt.get();
                auto expr = parseExpr(e->expr);
                std::cout << "if ( "       << expr << " )"
                          << " goto _endloop" << loop_scope;

        } else if (stmt->name == "GotoStmt"){
		auto g = (GotoStmt*) stmt.get();
		
		std::cout << "goto " << g->id ;
	
	} else if(stmt->name == "ProcStmt"){
                
		auto p = (ProcStmt*) stmt.get();
		if(!sym_table.proc_counters[p->id])
			sym_table.proc_counters[p->id] = 1;
		else
			sym_table.proc_counters[p->id] += 1;
                std::cout << "currentActivationRecord.__return = " << sym_table.proc_counters[p->id] -1 << ";\n";
		std::cout << "goto proc_" << p->id << ";\n";
		std::cout << "return_" << p->id << sym_table.proc_counters[p->id] << ":";

	} else
		std::cout << "//Not Implemented";

	std::cout << ";\n";
}

template <class T>
void generateCode(const std::vector<T>& list) {
    for (auto &e : list) {
        generateCode(e);
    }
}

template <>
void generateCode(const std::vector<ProDec>& list) {
    for (auto &pd : list) {
        sym_table.start_scope();
        generateCode(pd);
        sym_table.end_scope();
    }
}

void generateCode(const std::vector<std::shared_ptr<Stmt>>& list, int loop_scope) {
    for (auto &e : list) {
        generateCode(e, loop_scope);
    }
}

std::string parseExpr(const std::shared_ptr<Expr>& expr) {
    std::stringstream ss("");
    if (expr->name == "BinOp") {
        auto b = (BinOp*) expr.get();
        ss << parseExpr(b->lhs) << " " << b->op << " " << parseExpr(b->rhs);
    } else if (expr->name == "UnOp") {
        auto u = (UnOp*) expr.get();
        if (u->op == 'p') {
            ss << "(" << parseExpr(u->expr) << ")";
        } else {
            ss << u->op << parseExpr(u->expr);
        }
    } else if (expr->name == "Literal") {
        auto l = (Literal*) expr.get();
        if (l->type == SimpleType::ST_INT)
            ss << std::to_string(l->i);
        else if (l->type == SimpleType::ST_FLOAT)
            ss << std::to_string(l->f);
        else if (l->type == SimpleType::ST_CHAR) {
            ss << "\'";
            ss << l->c; 
            ss << "\'";
        }
    } else if (expr->name == "Access") {
        auto a = (Access*) expr.get();
        std::vector<std::string> indexes;
        for (auto i : a->indexes) indexes.push_back(parseExpr(i));

        ss << generateAccessCode(a->id, indexes);
    }
    return ss.str();
}

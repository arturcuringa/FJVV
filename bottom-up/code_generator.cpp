#include <iostream>
#include <sstream>
#include "code_generator.h"
#include "abstract_tree.h"

SymbolTable sym_table;

int __getTypeSize(const std::deque<std::shared_ptr<Expr>> &dimensions, SimpleType type) {
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

void generateCode(const Node& n) {
    std::cout << "// Not implemented\n";
}

void generateCode(const ProDec& pd) {
    sym_table.proc_calls[pd.id] = sym_table.proc_counters[pd.id];
    std::cout << "proc_" << pd.id << ":\n";
    generateCode(pd.stmts, -1);
    std::cout << "switch ( currentActivationRecord->_return ){\n";
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
    std::cout << "#include \"activationRecord.h\"\n";
    //std::cout << "#incldue <memory>\n";
    std::cout << "extern std::shared_ptr<ActivationRecord>  currentActivationRecord; \n";
    sym_table.start_scope();
    std::cout << "int main() {\n";
    generateCode(p.var_dec);
    generateCode(p.stmts, -1);
    generateCode(p.pro_dec);
    std::cout << "}\n";
    sym_table.end_scope();
}

void generateCode(const VarDec& vd) {
    for (auto id : vd.ids) {
        sym_table.add_symbol(id, vd.type);
        std::cout << "__instantiate( \"" << id << "\", __allocate(" << __getTypeSize(vd.type.dimensions, vd.type.type) << "));\n";
    }
}

void generateCode(const std::shared_ptr<Stmt>& stmt, int loop_scope) {
	if (!stmt->label.empty()){
		std::cout << stmt->label << ": ";
	}
	if (stmt->name == "AttrStmt") {
		auto a = ( AttrStmt* ) stmt.get();
		std::cout << a->id << " = " << parseExpr(a->rhs);
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
                std::cout << "currentActivationRecord->_return = " << sym_table.proc_counters[p->id] -1 << ";\n";
		std::cout << "goto proc_" << p->id << ";\n";
		std::cout << "return_" << p->id << sym_table.proc_counters[p->id] -1 << ":";

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
	ss << a->id;
        for (auto i : a->indexes) {
            ss <<  "[" << parseExpr(i) << "]";
        }
    }
    return ss.str();
}

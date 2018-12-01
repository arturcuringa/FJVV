#include <iostream>
#include <sstream>
#include "code_generator.h"
#include "abstract_tree.h"

SymbolTable sym_table;

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

std::string getTypeFormat(SimpleType type) {
	switch (type) {
        case ST_INT:
            return "%d";
        case ST_FLOAT:
            return "%f";
        case ST_CHAR:
            return "%c";
        default:
            return "%s";
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
    std::cout << "std::shared_ptr<ActivationRecord>  currentActivationRecord; \n";
    std::cout << "std::shared_ptr<ActivationRecord>  mainActivationRecord; \n";
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
        for (auto i : a->lhsIndexes) indexes.push_back(parseExpr(i).second);

		std::cout << generateAccessCode(a->id, indexes) << " = " << parseExpr(a->rhs).second;
	} else if (stmt->name == "IfStmt"){
		auto i       = ( IfStmt* ) stmt.get();
		auto counter = sym_table.if_counter++;		
		auto expr    = parseExpr(i->expr).second;

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
                auto expr = parseExpr(e->expr).second;
                std::cout << "if ( "       << expr << " )"
                          << " goto _endloop" << loop_scope;

        } else if (stmt->name == "GotoStmt"){
		auto g = (GotoStmt*) stmt.get();
		
		std::cout << "goto " << g->id ;
	
	 } else if (stmt->name == "GetStmt") {
		auto g = (GetStmt*) stmt.get();
        for (auto id : g->ids) {
            auto type = sym_table.symbol_table[id].top();
            auto format_spec = getTypeFormat(type.type);

            auto access = generateAccessCode(id, {});
            if (access.front() == '*') access.erase(0);
            else access = "&" + access;

            std::cout << "scanf(\"" << format_spec;
            std::cout <<  "\", " << access << ");";
        }
	} else if (stmt->name == "PutStmt") {
        auto p = (PutStmt*) stmt.get();
    } else if(stmt->name == "ProcStmt"){
                
		auto p = (ProcStmt*) stmt.get();
		if(!sym_table.proc_counters[p->id])
			sym_table.proc_counters[p->id] = 1;
		else
			sym_table.proc_counters[p->id] += 1;
                std::cout << "currentActivationRecord.__return = " << sym_table.proc_counters[p->id] -1 << ";\n";
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

SimpleType operateTypes(char op, SimpleType lhs, SimpleType rhs) {
    if (op == '+' or op == '-' or op == '*' or op == '/') {
        if (lhs == ST_FLOAT or rhs == ST_FLOAT)
            return ST_FLOAT;
        else
            return lhs;
    } else if (op == '%') {
        return ST_INT;
    } else { // logic op
        return ST_INT;
    }
}

ParsedExpr parseExpr(const std::shared_ptr<Expr>& expr) {
    std::stringstream ss("");
    if (expr->name == "BinOp") {
        auto b = (BinOp*) expr.get();
        auto lhs_parsed = parseExpr(b->lhs);
        auto rhs_parsed = parseExpr(b->rhs);
        auto type = operateTypes(b->op, lhs_parsed.first, rhs_parsed.first);

        ss << lhs_parsed.second << " " << b->op << " " << rhs_parsed.second;
        return std::make_pair(type, ss.str());
    } else if (expr->name == "UnOp") {
        auto u = (UnOp*) expr.get();
        auto parsed = parseExpr(u->expr);
        if (u->op == 'p') {
            ss << "(" << parsed.second << ")";
        } else {
            ss << u->op << parsed.second;
        }
        return std::make_pair(parsed.first, ss.str());
    } else if (expr->name == "Literal") {
        auto l = (Literal*) expr.get();
        if (l->type == SimpleType::ST_INT) {
            ss << std::to_string(l->i);
        } else if (l->type == SimpleType::ST_FLOAT) {
            ss << std::to_string(l->f);
        } else if (l->type == SimpleType::ST_CHAR) {
            ss << "\'";
            ss << l->c;
            ss << "\'";
        }
        return std::make_pair(l->type, ss.str());
    } else if (expr->name == "Access") {
        auto a = (Access*) expr.get();
        auto type = sym_table.symbol_table[a->id].top();

        std::vector<std::string> indexes;
        for (auto i : a->indexes) indexes.push_back(parseExpr(i).second);

        ss << generateAccessCode(a->id, indexes);
        return std::make_pair(type.type, ss.str());
    }
}

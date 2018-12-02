#include <iostream>
#include <string>
#include <sstream>
#include "code_generator.h"
#include "abstract_tree.h"
#include <fstream>   

SymbolTable sym_table;

void iterateOverBlocks(const std::shared_ptr<Stmt>& stmt){
    if(stmt->name == "IfStmt"){
    	auto _if = (IfStmt *) stmt.get();
	if(!_if->trueBlock.empty() ){
	    for(auto &s : _if->trueBlock){
	    	iterateOverBlocks(s);
	    }
	}
	if(!_if->falseBlock.empty()){
	    for(auto &s : _if->falseBlock){
	        iterateOverBlocks(s);
	    }
	}
    }
    if(stmt->name == "LoopStmt"){
    	auto loop = (LoopStmt *) stmt.get();
	for(auto &s : loop->block){
	    iterateOverBlocks(s);
	}
    }
    if (stmt->name == "ProcStmt") {
        auto ps = (ProcStmt *) stmt.get();
        sym_table.incProcCounter(ps->id);
    }

}

void prePopulateSymbolTable(const Program& program) {
    // populate procedure list 

    for (auto &proDec: program.pro_dec){
        sym_table.procedures.insert({proDec.id, proDec});
    }
    // count number of procedure calls
    for (auto &proc: program.pro_dec) {
        for (auto &stmt: proc.stmts) {
           iterateOverBlocks(stmt); 
        }
    }

    for (auto &stmt: program.stmts) {
       iterateOverBlocks(stmt); 
    }

    // initialize calls on 0
    for (auto &counter: sym_table.proc_counters)
        sym_table.proc_calls.insert({counter.first, 0});
}

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

std::string generateAccessCode(const std::string &id, const std::vector<std::string>& indexes, bool onParent) {
    std::stringstream indexStr;

    auto symbol = sym_table.get_symbol(id);

    for (int i = 0; i < indexes.size(); i++) {
        indexStr << "+" << indexes[i];
        for (int j = i+1; j < symbol.dimensions.size(); j++) indexStr << "*" << symbol.dimensions[j];
    }

    std::stringstream ss;
    switch (symbol.type) {
        case ST_INT: 
            if (onParent) ss << "*(((int*) __accessOnRecord(currentActivationRecord->parent, \"" << id << "\"))";
            else ss << "*(((int*) __access(\"" << id << "\"))";
            break;
        case ST_FLOAT:
            if (onParent) ss << "*(((float*) __accessOnRecord(currentActivationRecord->parent,\"" << id << "\"))";
            else ss << "*(((float*) __access(\"" << id << "\"))";
            break;
        case ST_CHAR:
            if (onParent) ss << "*(((char*) __accessOnRecord(currentActivationRecord->parent,\"" << id << "\"))";
            else ss << "*(((char*) __access(\"" << id << "\"))";
            break;
    }

    ss << indexStr.str() << ")";
    return ss.str();
}

std::string generateParameterAccessCode(const std::string &id, SimpleType type) {
    std::stringstream ss;
    switch (type) {
        case ST_INT: 
            ss << "*((int*) __access(\"" << id << "\"))";
            break;
        case ST_FLOAT:
            ss << "*((float*) __access(\"" << id << "\"))";
            break;
        case ST_CHAR:
            ss << "*((char*) __access(\"" << id << "\"))";
            break;
    }

    return ss.str();
}

std::string generateParameterAccessCodeFromParent(const std::string &id, SimpleType type) {
    std::stringstream ss;
    switch (type) {
        case ST_INT:  
            ss << "*((int*) __accessOnRecord(currentActivationRecord->parent,\"" << id << "\"))";
            break;
        case ST_FLOAT:
            ss << "*((float*) __accessOnRecord(currentActivationRecord->parent,\"" << id << "\"))";
	    break;
        case ST_CHAR:
            ss << "*((char*) __accessOnRecord(currentActivationRecord->parent,\"" << id << "\"))";
            break;
    }

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

std::string generateCode(const Node& n) {
    return  "// Not implemented\n";
}

std::string  generateCode(const ProDec& pd) {
    std::ostringstream ss("");
    ss << "proc_" << pd.id << ":\n";

    ss << generateCode(pd.stmts, sym_table.loop_counter);
    ss << "switch ( currentActivationRecord->_return ){\n";

    for(auto i = 0; i < sym_table.proc_counters[pd.id]; i++){
    	ss << "case " << i << ": goto return_" << pd.id << i << ";\n"; 
    }
    ss << "\n}\n";

    return ss.str();
}

std::string generateCode(const Program& p) {
    std::stringstream ss;
    std::ofstream f;
    f.open("comp.cpp");

    prePopulateSymbolTable(p);
    f << "\n";
    f << "#include \"activationRecord.h\"\n";
    f << "#include <memory>\n";
    f << "#include <cstdio>\n";
    f << "extern std::shared_ptr<ActivationRecord>  currentActivationRecord; \n";
    f << "extern std::shared_ptr<ActivationRecord>  mainActivationRecord; \n";
    sym_table.start_scope();
    f << "int main() {\n";
    f << "__startActivationRecord();\n";
    f << generateCode(p.var_dec);
    f << generateCode(p.stmts, sym_table.loop_counter);
    f << "return 0;\n";
    f << generateCode(p.pro_dec);
    f << "}\n";
    sym_table.end_scope();
 
    f.close();
    return ss.str();
}

std::string generateCode(const VarDec& vd) {
    std::stringstream ss;
    for (auto id : vd.ids) {
        sym_table.add_symbol(id, vd.type);
        ss << "__instantiate(\"" << id << "\", __allocate(" << getTypeSize(vd.type.dimensions, vd.type.type) << "));\n";
    }
    return ss.str();
}

std::string generateCode(const std::shared_ptr<Stmt>& stmt, int loop_scope) {
    std::stringstream ss;	
    if (!stmt->label.empty()){
		ss << stmt->label << ": ";
	}
	if (stmt->name == "AttrStmt") {
		auto a = ( AttrStmt* ) stmt.get();
        std::vector<std::string> indexes;

        for (auto i : a->lhsIndexes) indexes.push_back(parseExpr(i).second);

		ss << generateAccessCode(a->id, indexes, false) << " = " << parseExpr(a->rhs).second;
	} else if (stmt->name == "IfStmt"){
		auto i       = ( IfStmt* ) stmt.get();
		auto counter = sym_table.if_counter++;		
		auto expr    = parseExpr(i->expr).second;

		ss << "if ( "       << expr << " )"
			  << " goto  _if"  << counter << ";\n";
		
		ss << generateCode(i->falseBlock, loop_scope);

		ss << "goto _endif" << counter << ";\n";	
		ss << "_if" << counter << ": ";

		ss << generateCode(i->trueBlock, loop_scope);

		ss << "_endif" << counter << ": ";	
	} else if (stmt->name == "LoopStmt"){
		auto l         = ( LoopStmt* ) stmt.get();
		auto counter   = sym_table.loop_counter++;
		
		ss << "_loop" << counter << ":";
		
		ss << generateCode(l->block, counter);

		ss << "goto _loop" << counter << ";\n";

		ss << "_endloop" << counter << ":";
    
    } else if (stmt->name == "GetStmt") {
		auto g = (GetStmt*) stmt.get();
        for (auto& id : g->ids) {
            auto type = sym_table.get_symbol(id);
            auto format_spec = getTypeFormat(type.type);

            auto access = generateAccessCode(id, {}, false);
            if (access.front() == '*') access.erase(access.begin());
            else access = "&" + access;

            ss << "scanf(\"" << format_spec;
            ss <<  "\", " << access << ")";

            if (&id != &(g->ids).back())
                ss << ";\n";
        }
	} else if (stmt->name == "PutStmt") {
        auto p = (PutStmt*) stmt.get();
        for (auto& expr : p->exprs) {
            auto parsed = parseExpr(expr);
            auto format_spec = getTypeFormat(parsed.first);
            ss << "printf(\"" << format_spec;
            if (p->skip) ss << "\\n";
            ss << "\", " << parsed.second << ")";

            if (&expr != &(p->exprs).back())
                ss << ";\n";
        }
    } else if (stmt->name == "ExitStmt") {
        auto e = (ExitStmt*) stmt.get();
        auto expr = parseExpr(e->expr);
        ss << "if ( "       << expr.second << " )"
                    << " goto _endloop" << loop_scope;

    } else if (stmt->name == "GotoStmt"){
        auto g = (GotoStmt*) stmt.get();	
        ss << "goto " << g->id ;

	} else if(stmt->name == "ProcStmt"){
	auto p = (ProcStmt*) stmt.get();
        ss << "__createNewActivationRecord();\n";

        ProDec procedure = sym_table.procedures[p->id];
        // unwrap params
        std::vector<VarDec> params;
        for (auto &param : procedure.params)
            for (auto &id: param.ids) {
                VarDec vd;
                vd.ids.push_back(id);
                vd.type = param.type;
                params.push_back(vd);
            }

        for (int i = 0; i < p->args.size(); i++) {
            ss << "__instantiate(\"" << params[i].ids[0] << "\", __allocate(" << getTypeSize(params[i].type.dimensions, params[i].type.type) << "));\n";
            ss << generateParameterAccessCode(params[i].ids[0], params[i].type.type) << " = " << parseExpr(p->args[i], true).second << ";\n";
        }

        ss << "currentActivationRecord->_return = " << sym_table.proc_calls[p->id] << ";\n";

        ss << "goto proc_" << p->id << ";\n";
        ss << "return_" << p->id << sym_table.proc_calls[p->id] << ": __destroyActivationRecord()";
        sym_table.proc_calls[p->id]++;

	} else if (stmt->name == "StopStmt"){
        ss << "return 0";
    } else {
		ss << "//Not Implemented";
    }

	ss << ";\n";
	return ss.str();
}

template <class T>
std::string generateCode(const std::vector<T>& list) {
    std::stringstream ss;
    for (auto &e : list) {
        ss << generateCode(e);
    }
    return ss.str();
}

template <>
std::string generateCode(const std::vector<ProDec>& list) {
    std::stringstream ss;
    for (auto &pd : list) {
        sym_table.procedures.insert({pd.id, pd});
        sym_table.start_scope();
        for (auto &par: pd.params)
            for (auto &id: par.ids)
                sym_table.add_symbol(id, par.type);
        
        ss << generateCode(pd);
        sym_table.end_scope();
    }
    return ss.str();
}

std::string generateCode(const std::vector<std::shared_ptr<Stmt>>& list, int loop_scope) {
    std::stringstream ss;
    for (auto &e : list) {
        ss << generateCode(e, loop_scope);
    }
    return ss.str();
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

std::string parseBinOp(const char op){
    std::stringstream ss("");
    switch(op){
        case '=':
            ss << "==";
            break;
        case '|':
            ss << "||";
            break;
        case '&':
            ss << "&&";
            break;
	default:
	    ss << op;
    }
    return ss.str();
}

ParsedExpr parseExpr(const std::shared_ptr<Expr>& expr) {
    return parseExpr(expr, false);
}

ParsedExpr parseExpr(const std::shared_ptr<Expr>& expr, bool onParent) {
    std::stringstream ss("");
    if (expr->name == "BinOp") {
        auto b = (BinOp*) expr.get();
        auto lhs_parsed = parseExpr(b->lhs, onParent);
        auto rhs_parsed = parseExpr(b->rhs, onParent);
        auto type = operateTypes(b->op, lhs_parsed.first, rhs_parsed.first);

        ss << lhs_parsed.second << " " << parseBinOp(b->op) << " " << rhs_parsed.second;
        return std::make_pair(type, ss.str());
    } else if (expr->name == "UnOp") {
        auto u = (UnOp*) expr.get();
        auto parsed = parseExpr(u->expr, onParent);
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
        auto type = sym_table.get_symbol(a->id);

        std::vector<std::string> indexes;
        for (auto i : a->indexes) indexes.push_back(parseExpr(i, onParent).second);

        ss << generateAccessCode(a->id, indexes, onParent);
        return std::make_pair(type.type, ss.str());
    }
}

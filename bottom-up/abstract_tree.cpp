#include "abstract_tree.h"

std::ostream& operator<<(std::ostream& out, const Node& n) {
    out << "{"
            << "\"name\":\"" << n.name << "\""
        << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Expr& e) {
    out << "{"
        << "\"name\": \"" << e.name << "\", ";
        if (e.name == "BinOp") {
            auto b = static_cast<const BinOp&>(e);
            out << "\"op\": \"" << b.op << "\"" << ", ";
            out << "\"lhs\": " << *b.lhs << ", ";
            out << "\"rhs\": " << *b.rhs;
        } else if (e.name == "Literal") {
            auto l = static_cast<const Literal&>(e);
            out << "\"Val\":";
            if (l.type == SimpleType::ST_INT)
                out << l.i;
            else if (l.type == SimpleType::ST_FLOAT)
                out << l.f;
            else if (l.type == SimpleType::ST_CHAR)
                out << "\"" << l.c << "\"";
            else
                out << "\"\"";
            out << ", ";
            out << "\"type\": " << l.type;
        } else if (e.name == "UnOp") {
            auto u = static_cast<const UnOp&>(e);
            out << "\"op\": \"" << u.op << "\"" << ", ";
            out << "\"expr\": " << *u.expr;
        } else if (e.name == "Access") {
            auto a = static_cast<const Access&>(e);
            out << "\"id\": \"" << a.id << "\"";
            if (!a.indexes.empty()) {
                out << ", \"indexes\": [";
                for (auto i = 0; i < a.indexes.size(); i++) {
                    out << *a.indexes[i];
                    if (i != a.indexes.size() - 1)
                        out << ", "; 
                }
                out << "]";
            }
        }
    out << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Type& t) {
    out << "{"
        << "\"Type\": " << t.type;
        if (!t.dimensions.empty()) {
            out << ", \"Dimensions\": [";
            for (auto i = 0; i < t.dimensions.size(); i++) {
                out << *t.dimensions[i];
                if (i != t.dimensions.size() - 1)
                    out << ", ";
            }
            out << "]";
        }
    out << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const SimpleType& st) {
    out << "{"
        << "\"Simple Type\": ";
        if (st == SimpleType::ST_INT)
            out << "\"INT\"";
        else if (st == SimpleType::ST_FLOAT)
            out << "\"FLOAT\"";
        else if (st == SimpleType::ST_CHAR)
            out << "\"CHAR\"";
        else
            out << "\"\"";
    out << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const VarDec& vd) {
    out << "{";
        out << "\"name\": \"" << vd.name << "\","
            << "\"ids\": [";  
        for (int i = 0; i < vd.ids.size(); i++) {
            out<< "\"" << vd.ids[i] << "\"";
            if (i != vd.ids.size() - 1)
                out << ", ";
        }
        out << "], ";
        out << "\"type\": " << vd.type;
    out << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Stmt>& stmt) {
    out << "{"
        << "\"name\": \"" << stmt->name << "\"";
        if (stmt->label != "")
            out << ", \"label\": \"" << stmt->label << "\"";

        if (stmt->name == "AttrStmt") {
            auto as = (AttrStmt*) stmt.get();
            out << ",\"id\":" << "\"" << as->id << "\"";
            if (!as->lhsIndexes.empty()) {
                out << ", \"indexes\": [";
                for (auto i = 0; i < as->lhsIndexes.size(); i++) {
                    out << *as->lhsIndexes[i];
                    if (i != as->lhsIndexes.size() - 1)
                        out << ", ";
                }
                out << "]";
            }
            out << ", \"rhs\": " << *as->rhs;    
        }
        else if (stmt->name == "ProcStmt") {
            auto ps = (ProcStmt*) stmt.get();
            out << ",\"id\":" << "\"" << ps->id << "\", ";
            out << "\"args\": [";
            for (auto i = 0; i < ps->args.size(); i++) {
                out << *ps->args[i];
                if (i != ps->args.size() - 1)
                    out << ", ";
            }
            out << "]";
        } else if (stmt->name == "IfStmt") {
            auto is = (IfStmt*) stmt.get();
            out << ",\"expr\": " << *is->expr << ",";
            
            out << "\"trueBlock\": [";
            for (auto i = 0; i < is->trueBlock.size(); i++) {
                out << is->trueBlock[i];
                if (i != is->trueBlock.size() - 1)
                    out << ", ";
            }
            out << "]";

            if (!is->falseBlock.empty()) {
                out << ", \"falseBlock\": [";
                for (auto i = 0; i < is->falseBlock.size(); i++) {
                    out << is->falseBlock[i];
                    if (i != is->falseBlock.size() - 1)
                        out << ", ";
                }
                out << "]";
            }
        } else if (stmt->name == "GotoStmt") {
            auto gs = (GotoStmt*) stmt.get();
            out << ",\"id\":" << "\"" << gs->id << "\"";
        } else if (stmt->name == "LoopStmt") {
            auto ls = (LoopStmt*) stmt.get();
            out << ", \"block\": [";
            for (auto i = 0; i < ls->block.size(); i++) {
                out << ls->block[i];
                if (i != ls->block.size() - 1)
                    out << ", ";
            }
            out << "]";
        } else if (stmt->name == "ExitStmt") {
            auto es = (ExitStmt*) stmt.get();
            out << ", \"expr\": " << *es->expr;
        } else if (stmt->name == "GetStmt") {
            auto gs = (GetStmt*) stmt.get();
            out << ", \"ids\": [";
            for (auto i = 0; i < gs->ids.size(); i++) {
                out << "\"" << gs->ids[i] << "\"";
                if (i != gs->ids.size() - 1)
                    out << ", ";
            }
            out << "]";
        } else if (stmt->name == "PutStmt") {
            auto ps = (PutStmt*) stmt.get();
            std::string skip = ps->skip ? "true" : "false";
            out << ", \"skip\": " << skip << ", ";
            out << "\"exprs\": [";
            for (auto i = 0; i < ps->exprs.size(); i++) {
                out << *ps->exprs[i];
                if (i != ps->exprs.size() - 1)
                    out << ", ";
            }
            out << "]";
        }
    out << "}";
}

std::ostream& operator<<(std::ostream& out, const ProDec& vd) {
    out << "{"
        << "\"name\": \"" << vd.name << "\","
        << "\"id\": \"" << vd.id << "\","
        << "\"params\": [";
        for (auto i = 0; i < vd.params.size(); i++) {
            out << vd.params[i];
            if (i != vd.params.size() - 1)
                out << ", ";
        }
        out << "],";
        out << "\"stmts\": [";
        for (auto i = 0; i < vd.stmts.size(); i++) {
            out << vd.stmts[i];
            if (i != vd.stmts.size() - 1)
                out << ", ";
        }
        out << "]";
    out << "}";
}

std::ostream& operator<<(std::ostream& out, const Program& p) {
    out << "{"
        << "\"name\": \"" << p.name << "\","
        << "\"var_dec\": [";
        for (auto i = 0; i < p.var_dec.size(); i++) {
            out << p.var_dec[i];
            if (i != p.var_dec.size() - 1)
                out << ", ";
        }
        out << "],";
        out << "\"pro_dec\": [";
        for (auto i = 0; i < p.pro_dec.size(); i++) {
            out << p.pro_dec[i];
            if (i != p.pro_dec.size() - 1)
                out << ", ";
        }
        out << "],";
        out << "\"stmts\": [";
        for (auto i = 0; i < p.stmts.size(); i++) {
            out << p.stmts[i];
            if (i != p.stmts.size() - 1)
                out << ", ";
        }
        out << "]";
    out << "}";
    return out;
}

#include "abstract_tree.h"

std::ostream& operator<<(std::ostream& out, const Node& n) {
    out << "{"
            << "\"name\":\"" << n.name << "\""
        << "}";
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

std::ostream& operator<<(std::ostream& out, const Type& t) {
    out << "{"
        << "\"Type\": " << t.type << ", "
        << "\"Dimensions\": [";
        for (auto i = 0; i < t.dimensions.size(); i++) {
            out << *t.dimensions[i];
            if (i != t.dimensions.size() - 1)
                out << ", ";
        }
        out << "]";
    out << "}";
    return out;
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
            out << *p.stmts[i];
            if (i != p.stmts.size() - 1)
                out << ", ";
        }
        out << "]";
    out << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Expr& e) {
    out << "\"" << e.name << "\":";
    if (e.name == "BinOp") {
        auto b = static_cast<const BinOp&>(e);
        out << "{";
        out << "\"op\": \'" <<  b.op << "\'";
        out << ", ";
            out << "\"lhs\": " ;
        out << b.lhs;
        out << ", ";
        out << "\"rhs\":";
        out << b.rhs;
        out << "}";
    }
    if (e.name == "Literal"){
        auto l = static_cast<const Literal&>(e);
        out << "{\"Val\":";
        if (l.type == SimpleType::ST_INT)
            out << l.i;
        else if (l.type == SimpleType::ST_FLOAT)
            out << l.f;
        else if (l.type == SimpleType::ST_CHAR)
            out << "\"" << l.c << "\"";
        else
            out << "\"\"";
        out << ", " << l.type << "}";
    }
    if (e.name == "UnOp"){
        auto u = static_cast<const UnOp&>(e);
        out << "{";
        out << "\"op\": \'" << u.op << "\'";
        out << ", ";
        out << "\"expr\": ";
        out << u.expr;
        out<< "}";    
    }
    if (e.name == "Access"){
        auto a = static_cast<const Access&>(e);
        out << "{ \"id\": \"" << a.id << "\"";
        if (!a.indexes.empty()) {
            out << ", \"indexes\": [";
            for (auto i = 0; i < a.indexes.size(); i++) {
                out << a.indexes[i];
                if (i != a.indexes.size() - 1)
                    out << ", "; 
            }
            out << "]";
        }
        out << "}";
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const AttrStmt& as) {
    out << "\"" << as.name << "\": {";
    out << "\"lhs\":" << "\"" << as.id << "\", ";
    out << "\"indexes\": [";
    for (auto i = 0; i < as.lhsIndexes.size(); i++) {
        out << as.lhsIndexes[i];
        if (i != as.lhsIndexes.size() - 1)
            out << ", ";
    }
    out << "], \"rhs\": ";
    out << as.rhs;
    return out;
}

// todo
std::ostream& operator<<(std::ostream& out, const ProcStmt& ps) {
    return out;
}

std::ostream& operator<<(std::ostream& out, const VarDec& vd) {
    out << "\"" << vd.name << "\": {\"Ids\": [";  
    for (int i = 0; i < vd.ids.size(); i++) {
        out<< "\"" << vd.ids[i] << "\"";
        if (i != vd.ids.size() - 1)
            out << ", ";
    }
    out << "], ";
    out << vd.type;
    out << "}";
    return out;
}

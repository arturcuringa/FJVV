#include "abstract_tree.h"

std::ostream& operator<<(std::ostream& out, const Node& n) {
    out << "\"" << n.name << "\":{ ";
    return out;
}

std::ostream& operator<<(std::ostream& out, const SimpleType& st) {
    out << "\"Simple Type\": ";
    if (st == SimpleType::ST_INT)
        out << "\"INT\"";
    else if (st == SimpleType::ST_FLOAT)
        out << "\"FLOAT\"";
    else if (st == SimpleType::ST_CHAR)
        out << "\"CHAR\"";
    else
        out << "\"\"";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Type& t) {
    out << "\"Type\": {";
    out << t.type;

    out << ", \"Dimensions\": [";
    for (auto i = 0; i < t.dimensions.size(); i++) {
        out << "{" << t.dimensions[i] << "}";
        if (i != t.dimensions.size() - 1)
            out << ", ";
    }
    out << "]}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Program& p) {
    out << "{\"" << p.name << "\": [";
    for (auto i = 0; i < p.var_dec.size(); i++) {
        out << "{" << p.var_dec[i] << "}";
        if (i != p.var_dec.size() - 1)
            out << ", ";
    }
    out << "]}";
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
        out << l.i << ", ";
        out << l.type;
        out << "}";
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

std::ostream& operator<<(std::ostream& out, const PostLabellessStmt& pls) {
    if (pls.name == "AttrStmt") {
        auto att = static_cast<const AttrStmt&>(pls);
        out << att;
    } else {
        out << "";
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const AttrStmt& as) {
    out << "\"" << as.name << "\": {";
    out << "\"lhs\":" << "\"" << as.label << "\", ";
    out << "\"indexes\": [";
    for (auto i = 0; i < as.lhs.size(); i++) {
        out << as.lhs[i];
        if (i != as.lhs.size() - 1)
            out << ", ";
    }
    out << "], \"rhs\": ";
    out << as.rhs;
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

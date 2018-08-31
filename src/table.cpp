#include <stack>
#include <vector>
#include "enum_token.h"
#include "nont.h"

struct Token {
    union {
        enum token terminal;
        int nont;
    };
    bool isTerminal;
};

Token makeToken(enum token _terminal) {
    Token t;
    t.terminal = _terminal;
    t.isTerminal = true;
}

Token makeNonTerminal(int _nont) {
    Token t;
    t.nont = _nont;
    t.isTerminal = false;
}

void populateM(std::vector<std::vector<std::vector<Token>*>> &M) {
    M.resize(NONTENUMSIZE);
    for (auto &v : M) v.resize(TOKENENUMSIZE);

    M[PROG][START] = M[PROG][DECLARE] = M[PROG][IDENTIFIER] = new std::vector({makeNonTerminal(DECLLIST), makeNonTerminal(PROCDECLLIST), makeToken(START), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(TERMINATOR)});
    //M[PROG][$] = new std::vector({makeNonTerminal(DECLLIST), makeNonTerminal(PROCDECLLIST), makeToken(START), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(TERMINATOR)});

    M[DECLLIST][START] = M[DECLLIST][IDENTIFIER] = new std::vector();
    M[DECLLIST][DECLARE] = new std::vector({makeNonTerminal(DECLSTMT), makeToken(TERMINATOR), makeNonTerminal(DECLLIST)});
    //M[DECLLIST][$] = new std::vector();

    M[DECLSTMT][DECLARE] = new std::vector({makeToken(DECLARE), makeToken(LPAREN), makeNonTerminal(IDLIST), makeToken(RPAREN), makeNonTerminal(DATATYPE)});

    M[PROCDECLLIST][START] = new std::vector();
    M[PROCDECLLIST][IDENTIFIER] = new std::vector({makeNonTerminal(PROCDECL), makeNonTerminal(PROCDECLLIST)});

    M[PROCDECL][IDENTIFIER] = new std::vector({makeToken(IDENTIFIER), makeToken(COLON), makeToken(PROCEDURE), makeToken(LPAREN), makeNonTerminal(SUPERIDLIST), makeToken(RPAREN), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(IDENTIFIER), makeToken(TERMINATOR)});

    M[DATATYPE][INTEGER] = new std::vector({makeToken(INTEGER)});
    M[DATATYPE][FLOAT] = new std::vector({makeToken(FLOAT)});
    M[DATATYPE][CHAR] = new std::vector({makeToken(CHAR)});
    M[DATATYPE][ARRAY] = new std::vector({makeNonTerminal(ARRAYTYPE)});

    M[ARRAYTYPE][ARRAY] = new std::vector({makeToken(ARRAY), makeToken(LBRACKET), makeNonTerminal(E), makeToken(RBRACKET), makeToken(OF), makeNonTerminal(DATATYPE)});

    M[STMTLIST][TERMINATOR] = M[STMTLIST][END] = M[STMTLIST][ENDIF] = M[STMTLIST][ELSE] = M[STMTLIST][ENDLOOP] = new std::vector();
    M[STMTLIST][IDENTIFIER] = new std::vector({makeNonTerminal(SUPERSTMT), makeToken(TERMINATOR), makeNonTerminal(STMTLIST)});
    M[STMTLIST][IF] = M[STMTLIST][GOTO] = M[STMTLIST][LOOP] = M[STMTLIST][EXITWHEN] = M[STMTLIST][STOP] = M[STMTLIST][GET] = M[STMTLIST][PUT] = new std::vector({makeNonTerminal(SUPERSTMT), makeToken(TERMINATOR), makeNonTerminal(STMTLIST)});

    M[SUPERSTMT][IDENTIFIER] = new std::vector({makeNonTerminal(LABELSTMT)});
    M[SUPERSTMT][IF] = M[SUPERSTMT][GOTO] = M[SUPERSTMT][LOOP] = M[SUPERSTMT][EXITWHEN] = M[SUPERSTMT][STOP] = M[SUPERSTMT][GET] = M[SUPERSTMT][PUT] = new std::vector({makeNonTerminal(IDLESSSTMT)});

    M[LABELSTMT][IDENTIFIER] = new std::vector({makeToken(IDENTIFIER), makeNonTerminal(POSTLABELSTMT)});

    M[POSTLABELSTMT][LBRACKET] = new std::vector({makeNonTerminal(PROCSTMT)});
    M[POSTLABELSTMT][COLON] = new std::vector({makeToken(COLON), makeNonTerminal(STMT)});
    M[POSTLABELSTMT][ATTR_SIGN] = new std::vector({makeNonTerminal(ATTRSTMT)});

    M[STMT][IDENTIFIER] = new std::vector({makeNonTerminal(LABELLESSSTMT)});
    M[STMT][IF] = M[STMT][GOTO] = M[STMT][LOOP] = M[STMT][EXITWHEN] = M[STMT][STOP] = M[STMT][GET] = M[STMT][PUT] = new std::vector({makeNonTerminal(IDLESSSTMT)});

    M[LABELLESSSTMT][IDENTIFIER] = new std::vector({makeToken(IDENTIFIER), makeNonTerminal(POSTLABELLESSSTMT)});

    M[POSTLABELLESSSTMT][LBRACKET] = new std::vector({makeNonTerminal(PROCSTMT)});
    M[POSTLABELLESSSTMT][ATTR_SIGN] = new std::vector({makeNonTerminal(ATTRSTMT)});

    M[IDLESSSTMT][IF] = M[IDLESSSTMT][GOTO] = M[IDLESSSTMT][LOOP] = M[IDLESSSTMT][EXITWHEN] = new std::vector({makeNonTerminal(CONTROLSTMT)});
    M[IDLESSSTMT][STOP] = new std::vector({makeNonTerminal(STOPSTMT)});
    M[IDLESSSTMT][GET] = M[IDLESSSTMT][PUT] = new std::vector({makeNonTerminal(IOSTMT)});

    M[CONTROLSTMT][IF] = new std::vector({makeNonTerminal(IFSTMT)});
    M[CONTROLSTMT][GOTO] = new std::vector({makeNonTerminal(GOTOSTMT)});
    M[CONTROLSTMT][LOOP] = new std::vector({makeNonTerminal(LOOPSTMT)});
    M[CONTROLSTMT][EXITWHEN] = new std::vector({makeNonTerminal(EXITSTMT)});

    M[IFSTMT][IF] = new std::vector({makeToken(IF), makeNonTerminal(E), makeToken(THEN), makeNonTerminal(STMTLIST), makeNonTerminal(ELSE1), makeToken(ENDIF)});

    M[ELSE1][ENDIF] = new std::vector();
    M[ELSE1][ELSE] = new std::vector({makeToken(ELSE), makeNonTerminal(STMTLIST)});

    M[GOTOSTMT][GOTO] = new std::vector({makeToken(GOTO), makeToken(IDENTIFIER)});

    M[LOOPSTMT][LOOP] = new std::vector({makeToken(LOOP), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(ENDLOOP)});

    M[EXITSTMT][EXITWHEN] = new std::vector({makeToken(EXITWHEN), makeNonTerminal(E)});

    M[STOPSTMT][STOP] = new std::vector({makeToken(STOP)});

    M[IOSTMT][GET] = new std::vector({makeToken(GET), makeToken(LPAREN), makeNonTerminal(IDLIST), makeToken(RPAREN)});
    M[IOSTMT][PUT] = new std::vector({makeToken(PUT), makeNonTerminal(SKIP), makeToken(LPAREN), makeNonTerminal(IDLIST), makeToken(RPAREN)});

    M[SKIP][LBRACKET] = new std::vector();
    M[SKIP][SKIPTOK] = new std::vector({makeToken(SKIPTOK)});

    M[ATTRSTMT][ATTR_SIGN] = new std::vector({makeToken(ATTR_SIGN), makeNonTerminal(E)});

    M[PROCSTMT][LBRACKET] = new std::vector({makeToken(LPAREN), makeNonTerminal(EXPRLIST), makeToken(RPAREN)});

    M[SUPERIDLIST][RPAREN] = new std::vector();
    M[SUPERIDLIST][IDENTIFIER] = new std::vector({makeNonTerminal(IDLIST)});

    M[IDLIST][IDENTIFIER] = new std::vector({makeToken(IDENTIFIER), makeNonTerminal(IDLIST2)});

    M[IDLIST2][RPAREN] = new std::vector();
    M[IDLIST2][SEPARATOR] = new std::vector({makeToken(SEPARATOR), makeToken(IDENTIFIER), makeNonTerminal(IDLIST2)});

    M[EXPRLIST][RPAREN] = new std::vector();
    M[EXPRLIST][LBRACKET] = M[EXPRLIST][IDENTIFIER] = M[EXPRLIST][MINUS_SIGN] = M[EXPRLIST][NEG_SIGN] = new std::vector({makeNonTerminal(E), makeNonTerminal(EXPRLISTTAIL)});

    M[EXPRLISTTAIL][RPAREN] = new std::vector();
    M[EXPRLISTTAIL][SEPARATOR] = new std::vector({makeToken(SEPARATOR), makeNonTerminal(E), makeNonTerminal(EXPRLISTTAIL)});

    M[E][LBRACKET] = M[E][IDENTIFIER] = M[E][MINUS_SIGN] = M[E][NEG_SIGN] = new std::vector({makeNonTerminal(T), makeNonTerminal(E_)});

    M[E_][TERMINATOR] = M[E_][RPAREN] = M[E_][RBRACKET] = M[E_][THEN] = M[E_][SEPARATOR] = new std::vector();
    M[E_][AND_SIGN] = M[E_][OR_SIGN] = new std::vector({makeNonTerminal(A), makeNonTerminal(E)});

    M[A][AND_SIGN] = new std::vector({makeToken(AND_SIGN)});
    M[A][OR_SIGN] = new std::vector({makeToken(OR_SIGN)});

    M[T][LBRACKET] = M[T][IDENTIFIER] = M[T][MINUS_SIGN] = M[T][NEG_SIGN] = new std::vector({makeNonTerminal(T2), makeNonTerminal(T_)});

    M[T_][TERMINATOR] = M[T_][RPAREN] = M[T_][RBRACKET] = M[T_][THEN] = M[T_][SEPARATOR] = M[T_][AND_SIGN] = M[T_][OR_SIGN] = new std::vector();
    M[T_][GREATER_SIGN] = M[T_][LESS_SIGN] = M[T_][EQUAL_SIGN] = M[T_][DIFF_SIGN] = M[T_][LESS_EQ_SIGN] = M[T_][GREATER_EQ_SIGN] = new std::vector({makeNonTerminal(B), makeNonTerminal(T)});

    M[B][GREATER_SIGN] = new std::vector({makeToken(GREATER_SIGN)});
    M[B][LESS_SIGN] = new std::vector({makeToken(LESS_SIGN)});
    M[B][EQUAL_SIGN] = new std::vector({makeToken(EQUAL_SIGN)});
    M[B][DIFF_SIGN] = new std::vector({makeToken(DIFF_SIGN)});
    M[B][LESS_EQ_SIGN] = new std::vector({makeToken(LESS_EQ_SIGN)});
    M[B][GREATER_EQ_SIGN] = new std::vector({makeToken(GREATER_EQ_SIGN)});

    M[T2][LBRACKET] = M[T2][IDENTIFIER] = M[T2][MINUS_SIGN] = M[T2][NEG_SIGN] = new std::vector({makeNonTerminal(T3), makeNonTerminal(T2_)});

    M[T2_][TERMINATOR] = M[T2_][RPAREN] = M[T2_][RBRACKET] = M[T2_][THEN] = M[T2_][SEPARATOR] = M[T2_][AND_SIGN] = M[T2_][OR_SIGN] = M[T2_][GREATER_SIGN] = M[T2_][LESS_SIGN] = M[T2_][EQUAL_SIGN] = M[T2_][DIFF_SIGN] = M[T2_][LESS_EQ_SIGN] = M[T2_][GREATER_EQ_SIGN] = new std::vector();
    M[T2_][PLUS_SIGN] = M[T2_][MINUS_SIGN] = new std::vector({makeNonTerminal(C), makeNonTerminal(T2)});

    M[C][PLUS_SIGN] = new std::vector({makeToken(PLUS_SIGN)});
    M[C][MINUS_SIGN] = new std::vector({makeToken(MINUS_SIGN)});

    M[T3][LBRACKET] = M[T3][IDENTIFIER] = M[T3][MINUS_SIGN] = M[T3][NEG_SIGN] = new std::vector({makeNonTerminal(F), makeNonTerminal(T3_)});

    M[T3_][TERMINATOR] = M[T3_][RPAREN] = M[T3_][RBRACKET] = M[T3_][THEN] = M[T3_][SEPARATOR] = M[T3_][AND_SIGN] = M[T3_][OR_SIGN] = M[T3_][GREATER_SIGN] = M[T3_][LESS_SIGN] = M[T3_][EQUAL_SIGN] = M[T3_][DIFF_SIGN] = M[T3_][LESS_EQ_SIGN] = M[T3_][GREATER_EQ_SIGN] = M[T3_][PLUS_SIGN] = M[T3_][MINUS_SIGN] = new std::vector();
    M[T3_][MULT_SIGN] = M[T3_][DIV_SIGN] = M[T3_][MOD_SIGN] = new std::vector({makeNonTerminal(D), makeNonTerminal(T3)});

    M[D][MULT_SIGN] = new std::vector({makeToken(MULT_SIGN)});
    M[D][DIV_SIGN] = new std::vector({makeToken(DIV_SIGN)});
    M[D][MOD_SIGN] = new std::vector({makeToken(MOD_SIGN)});

    M[F][LBRACKET] = new std::vector({makeToken(LPAREN), makeNonTerminal(F), makeToken(RPAREN)});
    M[F][IDENTIFIER] = new std::vector({makeToken(IDENTIFIER)});
    M[F][MINUS_SIGN] = new std::vector({makeToken(MINUS_SIGN), makeNonTerminal(F)});
    M[F][NEG_SIGN] = new std::vector({makeToken(NEG_SIGN), makeNonTerminal(F)});
}

main(int argc, char const *argv[]) {
    std::stack<Token> stack;
    enum token proximoDaFita;

    std::vector<std::vector<std::vector<Token>*>> M;

    populateM(M);

    while (!stack.empty()) {
        Token X = stack.top();
        if (X.isTerminal and X.terminal == proximoDaFita) {
            stack.pop();
            proximoDaFita = yylex();
        } else if (X.isTerminal) {
            return 0;
        } else if (M[X.nont][proximoDaFita] == nullptr) {
            return 0;
        } else {
            stack.pop();
            std::vector<Token> &production = *(M[X.nont][proximoDaFita]);
            for (auto it = production.rbegin(); it != production.rend(); it++) {
                stack.push(*it);
            }
        }
    }

    return 0;
}

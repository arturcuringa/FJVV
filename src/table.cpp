#include <iostream>
#include <stack>
#include <vector>
#include <memory>
#include "enum_token.h"
#include "nont.h"
#include "lex.yy.c"


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

    return t;
}

Token makeNonTerminal(int _nont) {
    Token t;
    t.nont = _nont;
    t.isTerminal = false;

    return t;
}

void populateM(std::vector<std::vector<std::shared_ptr<std::vector<Token>>>> &M) {
    M.resize(NONTENUMSIZE);
    for (auto &v : M) v.resize(TOKENENUMSIZE);

    M[PROG][START] = M[PROG][DECLARE] = M[PROG][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(DECLLIST), makeNonTerminal(PROCDECLLIST), makeToken(START), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(TERMINATOR)}));
    //M[PROG][$] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(DECLLIST), makeNonTerminal(PROCDECLLIST), makeToken(START), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(TERMINATOR)}));

    M[DECLLIST][START] = M[DECLLIST][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[DECLLIST][DECLARE] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(DECLSTMT), makeToken(TERMINATOR), makeNonTerminal(DECLLIST)}));
    //M[DECLLIST][$] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());

    M[DECLSTMT][DECLARE] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(DECLARE), makeToken(LPAREN), makeNonTerminal(IDLIST), makeToken(RPAREN), makeNonTerminal(DATATYPE)}));

    M[PROCDECLLIST][START] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[PROCDECLLIST][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(PROCDECL), makeNonTerminal(PROCDECLLIST)}));

    M[PROCDECL][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(IDENTIFIER), makeToken(COLON), makeToken(PROCEDURE), makeToken(LPAREN), makeNonTerminal(SUPERIDLIST), makeToken(RPAREN), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(IDENTIFIER), makeToken(TERMINATOR)}));

    M[DATATYPE][INT_TYPE] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(INT_TYPE)}));
    M[DATATYPE][FLOAT_TYPE] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(FLOAT_TYPE)}));
    M[DATATYPE][CHAR_TYPE] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(CHAR_TYPE)}));
    M[DATATYPE][ARRAY] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(ARRAYNONT)}));

    M[ARRAYNONT][ARRAY] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(ARRAY), makeToken(LBRACKET), makeNonTerminal(E), makeToken(RBRACKET), makeToken(OF), makeNonTerminal(DATATYPE)}));

    M[STMTLIST][TERMINATOR] = M[STMTLIST][END] = M[STMTLIST][ENDIF] = M[STMTLIST][ELSE] = M[STMTLIST][ENDLOOP] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[STMTLIST][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(SUPERSTMT), makeToken(TERMINATOR), makeNonTerminal(STMTLIST)}));
    M[STMTLIST][IF] = M[STMTLIST][GOTO] = M[STMTLIST][LOOP] = M[STMTLIST][EXITWHEN] = M[STMTLIST][STOP] = M[STMTLIST][GET] = M[STMTLIST][PUT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(SUPERSTMT), makeToken(TERMINATOR), makeNonTerminal(STMTLIST)}));

    M[SUPERSTMT][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(LABELSTMT)}));
    M[SUPERSTMT][IF] = M[SUPERSTMT][GOTO] = M[SUPERSTMT][LOOP] = M[SUPERSTMT][EXITWHEN] = M[SUPERSTMT][STOP] = M[SUPERSTMT][GET] = M[SUPERSTMT][PUT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(IDLESSSTMT)}));

    M[LABELSTMT][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(IDENTIFIER), makeNonTerminal(POSTLABELSTMT)}));

    M[POSTLABELSTMT][LPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(PROCSTMT)}));
    M[POSTLABELSTMT][COLON] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(COLON), makeNonTerminal(STMT)}));
    M[POSTLABELSTMT][ATTR_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(ATTRSTMT)}));

    M[STMT][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(LABELLESSSTMT)}));
    M[STMT][IF] = M[STMT][GOTO] = M[STMT][LOOP] = M[STMT][EXITWHEN] = M[STMT][STOP] = M[STMT][GET] = M[STMT][PUT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(IDLESSSTMT)}));

    M[LABELLESSSTMT][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(IDENTIFIER), makeNonTerminal(POSTLABELLESSSTMT)}));

    M[POSTLABELLESSSTMT][LPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(PROCSTMT)}));
    M[POSTLABELLESSSTMT][ATTR_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(ATTRSTMT)}));

    M[IDLESSSTMT][IF] = M[IDLESSSTMT][GOTO] = M[IDLESSSTMT][LOOP] = M[IDLESSSTMT][EXITWHEN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(CONTROLSTMT)}));
    M[IDLESSSTMT][STOP] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(STOPSTMT)}));
    M[IDLESSSTMT][GET] = M[IDLESSSTMT][PUT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(IOSTMT)}));

    M[CONTROLSTMT][IF] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(IFSTMT)}));
    M[CONTROLSTMT][GOTO] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(GOTOSTMT)}));
    M[CONTROLSTMT][LOOP] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(LOOPSTMT)}));
    M[CONTROLSTMT][EXITWHEN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(EXITSTMT)}));

    M[IFSTMT][IF] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(IF), makeNonTerminal(E), makeToken(THEN), makeNonTerminal(STMTLIST), makeNonTerminal(ELSE1), makeToken(ENDIF)}));

    M[ELSE1][ENDIF] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[ELSE1][ELSE] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(ELSE), makeNonTerminal(STMTLIST)}));

    M[GOTOSTMT][GOTO] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(GOTO), makeToken(IDENTIFIER)}));

    M[LOOPSTMT][LOOP] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(LOOP), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(ENDLOOP)}));

    M[EXITSTMT][EXITWHEN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(EXITWHEN), makeNonTerminal(E)}));

    M[STOPSTMT][STOP] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(STOP)}));

    M[IOSTMT][GET] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(GET), makeToken(LPAREN), makeNonTerminal(IDLIST), makeToken(RPAREN)}));
    M[IOSTMT][PUT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(PUT), makeNonTerminal(SKIPNONT), makeToken(LPAREN), makeNonTerminal(IDLIST), makeToken(RPAREN)}));

    M[SKIPNONT][LPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[SKIPNONT][SKIP] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(SKIP)}));

    M[ATTRSTMT][ATTR_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(ATTR_SIGN), makeNonTerminal(E)}));

    M[PROCSTMT][LPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(LPAREN), makeNonTerminal(EXPRLIST), makeToken(RPAREN)}));

    M[SUPERIDLIST][RPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[SUPERIDLIST][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(IDLIST)}));

    M[IDLIST][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(IDENTIFIER), makeNonTerminal(IDLIST2)}));

    M[IDLIST2][RPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[IDLIST2][SEPARATOR] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(SEPARATOR), makeToken(IDENTIFIER), makeNonTerminal(IDLIST2)}));

    M[EXPRLIST][RPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[EXPRLIST][FLOAT] = M[EXPRLIST][INTEGER] = M[EXPRLIST][LBRACKET] = M[EXPRLIST][IDENTIFIER] = M[EXPRLIST][MINUS_SIGN] = M[EXPRLIST][NEG_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(E), makeNonTerminal(EXPRLISTTAIL)}));

    M[EXPRLISTTAIL][RPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[EXPRLISTTAIL][SEPARATOR] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(SEPARATOR), makeNonTerminal(E), makeNonTerminal(EXPRLISTTAIL)}));

    M[E][INTEGER] = M[E][FLOAT] = M[E][LBRACKET] = M[E][IDENTIFIER] = M[E][MINUS_SIGN] = M[E][NEG_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(T), makeNonTerminal(E_)}));

    M[E_][TERMINATOR] = M[E_][RPAREN] = M[E_][RBRACKET] = M[E_][THEN] = M[E_][SEPARATOR] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[E_][AND_SIGN] = M[E_][OR_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(A), makeNonTerminal(E)}));

    M[A][AND_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(AND_SIGN)}));
    M[A][OR_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(OR_SIGN)}));

    M[T][INTEGER] = M[T][FLOAT] = M[T][LBRACKET] = M[T][IDENTIFIER] = M[T][MINUS_SIGN] = M[T][NEG_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(T2), makeNonTerminal(T_)}));

    M[T_][TERMINATOR] = M[T_][RPAREN] = M[T_][RBRACKET] = M[T_][THEN] = M[T_][SEPARATOR] = M[T_][AND_SIGN] = M[T_][OR_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[T_][GREATER_SIGN] = M[T_][LESS_SIGN] = M[T_][EQUAL_SIGN] = M[T_][DIFF_SIGN] = M[T_][LESS_EQ_SIGN] = M[T_][GREATER_EQ_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(B), makeNonTerminal(T)}));

    M[B][GREATER_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(GREATER_SIGN)}));
    M[B][LESS_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(LESS_SIGN)}));
    M[B][EQUAL_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(EQUAL_SIGN)}));
    M[B][DIFF_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(DIFF_SIGN)}));
    M[B][LESS_EQ_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(LESS_EQ_SIGN)}));
    M[B][GREATER_EQ_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(GREATER_EQ_SIGN)}));

    M[T2][INTEGER] = M[T2][FLOAT] = M[T2][LBRACKET] = M[T2][IDENTIFIER] = M[T2][MINUS_SIGN] = M[T2][NEG_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(T3), makeNonTerminal(T2_)}));

    M[T2_][TERMINATOR] = M[T2_][RPAREN] = M[T2_][RBRACKET] = M[T2_][THEN] = M[T2_][SEPARATOR] = M[T2_][AND_SIGN] = M[T2_][OR_SIGN] = M[T2_][GREATER_SIGN] = M[T2_][LESS_SIGN] = M[T2_][EQUAL_SIGN] = M[T2_][DIFF_SIGN] = M[T2_][LESS_EQ_SIGN] = M[T2_][GREATER_EQ_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[T2_][PLUS_SIGN] = M[T2_][MINUS_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(C), makeNonTerminal(T2)}));

    M[C][PLUS_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(PLUS_SIGN)}));
    M[C][MINUS_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(MINUS_SIGN)}));

    M[T3][INTEGER] = M[T3][FLOAT] = M[T3][LBRACKET] = M[T3][IDENTIFIER] = M[T3][MINUS_SIGN] = M[T3][NEG_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(F), makeNonTerminal(T3_)}));

    M[T3_][TERMINATOR] = M[T3_][RPAREN] = M[T3_][RBRACKET] = M[T3_][THEN] = M[T3_][SEPARATOR] = M[T3_][AND_SIGN] = M[T3_][OR_SIGN] = M[T3_][GREATER_SIGN] = M[T3_][LESS_SIGN] = M[T3_][EQUAL_SIGN] = M[T3_][DIFF_SIGN] = M[T3_][LESS_EQ_SIGN] = M[T3_][GREATER_EQ_SIGN] = M[T3_][PLUS_SIGN] = M[T3_][MINUS_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>());
    M[T3_][MULT_SIGN] = M[T3_][DIV_SIGN] = M[T3_][MOD_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(D), makeNonTerminal(T3)}));

    M[D][MULT_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(MULT_SIGN)}));
    M[D][DIV_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(DIV_SIGN)}));
    M[D][MOD_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(MOD_SIGN)}));

    M[F][LPAREN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(LPAREN), makeNonTerminal(F), makeToken(RPAREN)}));
    M[F][IDENTIFIER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(IDENTIFIER)}));
    M[F][MINUS_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(MINUS_SIGN), makeNonTerminal(F)}));
    M[F][NEG_SIGN] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(NEG_SIGN), makeNonTerminal(F)}));
    M[F][INTEGER] = M[F][FLOAT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeNonTerminal(LITERAL)}));

    M[LITERAL][INTEGER] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(INTEGER)}));
    M[LITERAL][FLOAT] = std::shared_ptr<std::vector<Token>>(new std::vector<Token>({makeToken(FLOAT)}));
}

int main(int argc, char const *argv[]) {
    std::stack<Token> stack;
    enum token proximoDaFita = (enum token) yylex();

    std::vector<std::vector<std::shared_ptr<std::vector<Token>>>> M;

    populateM(M);
    stack.push(makeNonTerminal(PROG));

    while (!stack.empty()) {
        Token X = stack.top();
        if (X.isTerminal) {
            if (X.terminal == proximoDaFita) {
                stack.pop();
                int yylexres = yylex();
                proximoDaFita = (enum token) yylexres;
            } else {
                std::cout << "Esperava encontrar terminal " << tokenNames[X.terminal] << ", encontrou " << tokenNames[proximoDaFita] << std::endl;
                return 0; // erro
            }
        } else {
            if (M[X.nont][proximoDaFita] == nullptr) {
                std::cout << "Token inesperado: \"" << tokenNames[proximoDaFita] << "\" para produção " << nontNames[X.nont] << std::endl;
                std::cout << "Regra da gramatica inexistente, saindo" << std::endl;
               return 0; // erro
            } else {
                stack.pop();
                std::vector<Token> &production = *(M[X.nont][proximoDaFita]);
                for (auto it = production.rbegin(); it != production.rend(); it++) {
                    stack.push(*it);
                }
            }
        }
    }

    return 0;
}

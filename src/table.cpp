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

    M[PROG][START] = M[PROG][DECLARE] = M[PROG][IDENTIFIER] = new std::vector<Token>({makeNonTerminal(DECLLIST), makeNonTerminal(PROCDECLLIST), makeToken(START), makeToken(TERMINATOR), makeNonTerminal(STMTLIST), makeToken(END), makeToken(TERMINATOR)});
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

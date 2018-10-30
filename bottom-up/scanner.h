#ifndef __SCANNER_H__
#define __SCANNER_H__

#undef yyFlexLexer
#include <FlexLexer.h>
#include "lalr.hxx"

// Tell flex which function to define
#undef YY_DECL
#define YY_DECL				int yy::scanner::lex(              \
                            yy::parser::semantic_type* yylval, \
                            yy::parser::location_type* yylloc)

namespace yy
{
    class scanner : public yyFlexLexer
    {
    public:
        explicit scanner(std::istream* in=0, std::ostream* out=0);

        int lex(parser::semantic_type* yylval,
                parser::location_type* yylloc);
    };
}

#endif
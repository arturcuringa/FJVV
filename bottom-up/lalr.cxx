// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "lalr.cxx" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "lalr.hxx"

// User implementation prologue.

#line 51 "lalr.cxx" // lalr1.cc:412
// Unqualified %code blocks.
#line 26 "lalr.y" // lalr1.cc:413

    #include <stdio.h>
    #include <vector>
    #include <string>
    #include <memory>
    #include <iostream>     // cerr, endl
    #include <utility>      // move
    #include <sstream>

    #include "scanner.h"

    #undef yylex
    #define yylex scanner->lex

    Program root;

#line 70 "lalr.cxx" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 156 "lalr.cxx" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (yy::scanner* scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 66: // attr_stmt
        value.copy< AttrStmt > (other.value);
        break;

      case 54: // decl_list
        value.copy< DecList > (other.value);
        break;

      case 80: // expr
        value.copy< Expr > (other.value);
        break;

      case 79: // literal
        value.copy< Literal > (other.value);
        break;

      case 58: // data_type
        value.copy< SimpleType > (other.value);
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        value.copy< Stmt > (other.value);
        break;

      case 62: // stmt_list
        value.copy< StmtList > (other.value);
        break;

      case 55: // decl_stmt
        value.copy< VarDec > (other.value);
        break;

      case 15: // CHAR
        value.copy< char > (other.value);
        break;

      case 14: // FLOAT
        value.copy< double > (other.value);
        break;

      case 13: // INTEGER
        value.copy< int > (other.value);
        break;

      case 12: // IDENTIFIER
        value.copy< std::string > (other.value);
        break;

      case 81: // array_access
        value.copy< std::vector<Expr> > (other.value);
        break;

      case 61: // id_list
        value.copy< std::vector<std::string> > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 66: // attr_stmt
        value.copy< AttrStmt > (v);
        break;

      case 54: // decl_list
        value.copy< DecList > (v);
        break;

      case 80: // expr
        value.copy< Expr > (v);
        break;

      case 79: // literal
        value.copy< Literal > (v);
        break;

      case 58: // data_type
        value.copy< SimpleType > (v);
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        value.copy< Stmt > (v);
        break;

      case 62: // stmt_list
        value.copy< StmtList > (v);
        break;

      case 55: // decl_stmt
        value.copy< VarDec > (v);
        break;

      case 15: // CHAR
        value.copy< char > (v);
        break;

      case 14: // FLOAT
        value.copy< double > (v);
        break;

      case 13: // INTEGER
        value.copy< int > (v);
        break;

      case 12: // IDENTIFIER
        value.copy< std::string > (v);
        break;

      case 81: // array_access
        value.copy< std::vector<Expr> > (v);
        break;

      case 61: // id_list
        value.copy< std::vector<std::string> > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AttrStmt v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const DecList v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Expr v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Literal v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const SimpleType v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Stmt v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const StmtList v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const VarDec v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<Expr> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<std::string> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 66: // attr_stmt
        value.template destroy< AttrStmt > ();
        break;

      case 54: // decl_list
        value.template destroy< DecList > ();
        break;

      case 80: // expr
        value.template destroy< Expr > ();
        break;

      case 79: // literal
        value.template destroy< Literal > ();
        break;

      case 58: // data_type
        value.template destroy< SimpleType > ();
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        value.template destroy< Stmt > ();
        break;

      case 62: // stmt_list
        value.template destroy< StmtList > ();
        break;

      case 55: // decl_stmt
        value.template destroy< VarDec > ();
        break;

      case 15: // CHAR
        value.template destroy< char > ();
        break;

      case 14: // FLOAT
        value.template destroy< double > ();
        break;

      case 13: // INTEGER
        value.template destroy< int > ();
        break;

      case 12: // IDENTIFIER
        value.template destroy< std::string > ();
        break;

      case 81: // array_access
        value.template destroy< std::vector<Expr> > ();
        break;

      case 61: // id_list
        value.template destroy< std::vector<std::string> > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 66: // attr_stmt
        value.move< AttrStmt > (s.value);
        break;

      case 54: // decl_list
        value.move< DecList > (s.value);
        break;

      case 80: // expr
        value.move< Expr > (s.value);
        break;

      case 79: // literal
        value.move< Literal > (s.value);
        break;

      case 58: // data_type
        value.move< SimpleType > (s.value);
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        value.move< Stmt > (s.value);
        break;

      case 62: // stmt_list
        value.move< StmtList > (s.value);
        break;

      case 55: // decl_stmt
        value.move< VarDec > (s.value);
        break;

      case 15: // CHAR
        value.move< char > (s.value);
        break;

      case 14: // FLOAT
        value.move< double > (s.value);
        break;

      case 13: // INTEGER
        value.move< int > (s.value);
        break;

      case 12: // IDENTIFIER
        value.move< std::string > (s.value);
        break;

      case 81: // array_access
        value.move< std::vector<Expr> > (s.value);
        break;

      case 61: // id_list
        value.move< std::vector<std::string> > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_START (const location_type& l)
  {
    return symbol_type (token::START, l);
  }

  parser::symbol_type
  parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  parser::symbol_type
  parser::make_DECLARE (const location_type& l)
  {
    return symbol_type (token::DECLARE, l);
  }

  parser::symbol_type
  parser::make_PROCEDURE (const location_type& l)
  {
    return symbol_type (token::PROCEDURE, l);
  }

  parser::symbol_type
  parser::make_INT_TYPE (const location_type& l)
  {
    return symbol_type (token::INT_TYPE, l);
  }

  parser::symbol_type
  parser::make_FLOAT_TYPE (const location_type& l)
  {
    return symbol_type (token::FLOAT_TYPE, l);
  }

  parser::symbol_type
  parser::make_CHAR_TYPE (const location_type& l)
  {
    return symbol_type (token::CHAR_TYPE, l);
  }

  parser::symbol_type
  parser::make_ARRAY (const location_type& l)
  {
    return symbol_type (token::ARRAY, l);
  }

  parser::symbol_type
  parser::make_OF (const location_type& l)
  {
    return symbol_type (token::OF, l);
  }

  parser::symbol_type
  parser::make_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IDENTIFIER, v, l);
  }

  parser::symbol_type
  parser::make_INTEGER (const int& v, const location_type& l)
  {
    return symbol_type (token::INTEGER, v, l);
  }

  parser::symbol_type
  parser::make_FLOAT (const double& v, const location_type& l)
  {
    return symbol_type (token::FLOAT, v, l);
  }

  parser::symbol_type
  parser::make_CHAR (const char& v, const location_type& l)
  {
    return symbol_type (token::CHAR, v, l);
  }

  parser::symbol_type
  parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  parser::symbol_type
  parser::make_THEN (const location_type& l)
  {
    return symbol_type (token::THEN, l);
  }

  parser::symbol_type
  parser::make_ENDIF (const location_type& l)
  {
    return symbol_type (token::ENDIF, l);
  }

  parser::symbol_type
  parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }

  parser::symbol_type
  parser::make_GOTO (const location_type& l)
  {
    return symbol_type (token::GOTO, l);
  }

  parser::symbol_type
  parser::make_LOOP (const location_type& l)
  {
    return symbol_type (token::LOOP, l);
  }

  parser::symbol_type
  parser::make_ENDLOOP (const location_type& l)
  {
    return symbol_type (token::ENDLOOP, l);
  }

  parser::symbol_type
  parser::make_EXITWHEN (const location_type& l)
  {
    return symbol_type (token::EXITWHEN, l);
  }

  parser::symbol_type
  parser::make_STOP (const location_type& l)
  {
    return symbol_type (token::STOP, l);
  }

  parser::symbol_type
  parser::make_GET (const location_type& l)
  {
    return symbol_type (token::GET, l);
  }

  parser::symbol_type
  parser::make_PUT (const location_type& l)
  {
    return symbol_type (token::PUT, l);
  }

  parser::symbol_type
  parser::make_SKIP (const location_type& l)
  {
    return symbol_type (token::SKIP, l);
  }

  parser::symbol_type
  parser::make_ATTR_SIGN (const location_type& l)
  {
    return symbol_type (token::ATTR_SIGN, l);
  }

  parser::symbol_type
  parser::make_DIFF_SIGN (const location_type& l)
  {
    return symbol_type (token::DIFF_SIGN, l);
  }

  parser::symbol_type
  parser::make_GREATER_EQ_SIGN (const location_type& l)
  {
    return symbol_type (token::GREATER_EQ_SIGN, l);
  }

  parser::symbol_type
  parser::make_LESS_EQ_SIGN (const location_type& l)
  {
    return symbol_type (token::LESS_EQ_SIGN, l);
  }

  parser::symbol_type
  parser::make_UMINUS (const location_type& l)
  {
    return symbol_type (token::UMINUS, l);
  }



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 66: // attr_stmt
        value.move< AttrStmt > (that.value);
        break;

      case 54: // decl_list
        value.move< DecList > (that.value);
        break;

      case 80: // expr
        value.move< Expr > (that.value);
        break;

      case 79: // literal
        value.move< Literal > (that.value);
        break;

      case 58: // data_type
        value.move< SimpleType > (that.value);
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        value.move< Stmt > (that.value);
        break;

      case 62: // stmt_list
        value.move< StmtList > (that.value);
        break;

      case 55: // decl_stmt
        value.move< VarDec > (that.value);
        break;

      case 15: // CHAR
        value.move< char > (that.value);
        break;

      case 14: // FLOAT
        value.move< double > (that.value);
        break;

      case 13: // INTEGER
        value.move< int > (that.value);
        break;

      case 12: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      case 81: // array_access
        value.move< std::vector<Expr> > (that.value);
        break;

      case 61: // id_list
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 66: // attr_stmt
        value.copy< AttrStmt > (that.value);
        break;

      case 54: // decl_list
        value.copy< DecList > (that.value);
        break;

      case 80: // expr
        value.copy< Expr > (that.value);
        break;

      case 79: // literal
        value.copy< Literal > (that.value);
        break;

      case 58: // data_type
        value.copy< SimpleType > (that.value);
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        value.copy< Stmt > (that.value);
        break;

      case 62: // stmt_list
        value.copy< StmtList > (that.value);
        break;

      case 55: // decl_stmt
        value.copy< VarDec > (that.value);
        break;

      case 15: // CHAR
        value.copy< char > (that.value);
        break;

      case 14: // FLOAT
        value.copy< double > (that.value);
        break;

      case 13: // INTEGER
        value.copy< int > (that.value);
        break;

      case 12: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      case 81: // array_access
        value.copy< std::vector<Expr> > (that.value);
        break;

      case 61: // id_list
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 66: // attr_stmt
        yylhs.value.build< AttrStmt > ();
        break;

      case 54: // decl_list
        yylhs.value.build< DecList > ();
        break;

      case 80: // expr
        yylhs.value.build< Expr > ();
        break;

      case 79: // literal
        yylhs.value.build< Literal > ();
        break;

      case 58: // data_type
        yylhs.value.build< SimpleType > ();
        break;

      case 63: // super_stmt
      case 64: // label_stmt
      case 65: // stmt
        yylhs.value.build< Stmt > ();
        break;

      case 62: // stmt_list
        yylhs.value.build< StmtList > ();
        break;

      case 55: // decl_stmt
        yylhs.value.build< VarDec > ();
        break;

      case 15: // CHAR
        yylhs.value.build< char > ();
        break;

      case 14: // FLOAT
        yylhs.value.build< double > ();
        break;

      case 13: // INTEGER
        yylhs.value.build< int > ();
        break;

      case 12: // IDENTIFIER
        yylhs.value.build< std::string > ();
        break;

      case 81: // array_access
        yylhs.value.build< std::vector<Expr> > ();
        break;

      case 61: // id_list
        yylhs.value.build< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 92 "lalr.y" // lalr1.cc:859
    { root.var_dec = yystack_[2].value.as< DecList > (); std::cout << root << std::endl; }
#line 1362 "lalr.cxx" // lalr1.cc:859
    break;

  case 4:
#line 96 "lalr.y" // lalr1.cc:859
    {}
#line 1368 "lalr.cxx" // lalr1.cc:859
    break;

  case 5:
#line 97 "lalr.y" // lalr1.cc:859
    {
        DecList a = yystack_[2].value.as< DecList > ();
        a.push_back(yystack_[1].value.as< VarDec > ());

        yylhs.value.as< DecList > () = a;
    }
#line 1379 "lalr.cxx" // lalr1.cc:859
    break;

  case 7:
#line 106 "lalr.y" // lalr1.cc:859
    {
    auto vd = VarDec();
    vd.ids = yystack_[2].value.as< std::vector<std::string> > ();
    auto ty = Type();
    if(yystack_[0].value.as< SimpleType > () == SimpleType::ST_INT)
        ty.type = SimpleType::ST_INT;
    if(yystack_[0].value.as< SimpleType > () == SimpleType::ST_FLOAT)
        ty.type = SimpleType::ST_FLOAT;
    if(yystack_[0].value.as< SimpleType > () == SimpleType::ST_FLOAT)
        ty.type = SimpleType::ST_FLOAT;
    vd.type.push_back(ty);
    yylhs.value.as< VarDec > () = vd;
}
#line 1397 "lalr.cxx" // lalr1.cc:859
    break;

  case 8:
#line 120 "lalr.y" // lalr1.cc:859
    {}
#line 1403 "lalr.cxx" // lalr1.cc:859
    break;

  case 12:
#line 128 "lalr.y" // lalr1.cc:859
    {yylhs.value.as< SimpleType > () = SimpleType::ST_INT;}
#line 1409 "lalr.cxx" // lalr1.cc:859
    break;

  case 13:
#line 129 "lalr.y" // lalr1.cc:859
    {yylhs.value.as< SimpleType > () = SimpleType::ST_FLOAT;}
#line 1415 "lalr.cxx" // lalr1.cc:859
    break;

  case 14:
#line 130 "lalr.y" // lalr1.cc:859
    {yylhs.value.as< SimpleType > () = SimpleType::ST_CHAR;}
#line 1421 "lalr.cxx" // lalr1.cc:859
    break;

  case 15:
#line 131 "lalr.y" // lalr1.cc:859
    {}
#line 1427 "lalr.cxx" // lalr1.cc:859
    break;

  case 17:
#line 135 "lalr.y" // lalr1.cc:859
    {}
#line 1433 "lalr.cxx" // lalr1.cc:859
    break;

  case 19:
#line 138 "lalr.y" // lalr1.cc:859
    { std::vector<std::string> s;
                 s.push_back(yystack_[0].value.as< std::string > ());
                 yylhs.value.as< std::vector<std::string> > () = s; }
#line 1441 "lalr.cxx" // lalr1.cc:859
    break;

  case 20:
#line 141 "lalr.y" // lalr1.cc:859
    {std::vector<std::string> s = yystack_[2].value.as< std::vector<std::string> > ();
                 s.push_back(yystack_[0].value.as< std::string > ());
                         yylhs.value.as< std::vector<std::string> > () = s; }
#line 1449 "lalr.cxx" // lalr1.cc:859
    break;

  case 21:
#line 145 "lalr.y" // lalr1.cc:859
    { yylhs.value.as< StmtList > () = StmtList(); }
#line 1455 "lalr.cxx" // lalr1.cc:859
    break;

  case 22:
#line 146 "lalr.y" // lalr1.cc:859
    { 
		StmtList a = yystack_[2].value.as< StmtList > ();
		a.push_back(yystack_[1].value.as< Stmt > ());
		yylhs.value.as< StmtList > () = a;
    }
#line 1465 "lalr.cxx" // lalr1.cc:859
    break;

  case 26:
#line 155 "lalr.y" // lalr1.cc:859
    {
	Stmt a = yystack_[0].value.as< Stmt > ();
	a.label = yystack_[2].value.as< std::string > ();
	yylhs.value.as< Stmt > () = a;
}
#line 1475 "lalr.cxx" // lalr1.cc:859
    break;

  case 32:
#line 163 "lalr.y" // lalr1.cc:859
    {
    AttrStmt attr;
    attr.lhs = yystack_[2].value.as< std::vector<Expr> > ();
    attr.rhs = yystack_[0].value.as< Expr > ();
    yylhs.value.as< AttrStmt > () = attr;
}
#line 1486 "lalr.cxx" // lalr1.cc:859
    break;

  case 39:
#line 178 "lalr.y" // lalr1.cc:859
    {}
#line 1492 "lalr.cxx" // lalr1.cc:859
    break;

  case 47:
#line 192 "lalr.y" // lalr1.cc:859
    {}
#line 1498 "lalr.cxx" // lalr1.cc:859
    break;

  case 49:
#line 196 "lalr.y" // lalr1.cc:859
    {}
#line 1504 "lalr.cxx" // lalr1.cc:859
    break;

  case 52:
#line 200 "lalr.y" // lalr1.cc:859
    {}
#line 1510 "lalr.cxx" // lalr1.cc:859
    break;

  case 53:
#line 202 "lalr.y" // lalr1.cc:859
    {auto lit = Literal(); lit.i = yystack_[0].value.as< int > (); yylhs.value.as< Literal > () = lit;}
#line 1516 "lalr.cxx" // lalr1.cc:859
    break;

  case 54:
#line 203 "lalr.y" // lalr1.cc:859
    {auto lit = Literal(); lit.f = yystack_[0].value.as< double > (); yylhs.value.as< Literal > () = lit;}
#line 1522 "lalr.cxx" // lalr1.cc:859
    break;

  case 55:
#line 204 "lalr.y" // lalr1.cc:859
    {auto lit = Literal(); lit.c = yystack_[0].value.as< char > (); yylhs.value.as< Literal > () = lit;}
#line 1528 "lalr.cxx" // lalr1.cc:859
    break;

  case 56:
#line 206 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '+';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1538 "lalr.cxx" // lalr1.cc:859
    break;

  case 57:
#line 211 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '-';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1548 "lalr.cxx" // lalr1.cc:859
    break;

  case 58:
#line 216 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '*';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1558 "lalr.cxx" // lalr1.cc:859
    break;

  case 59:
#line 221 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '%';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1568 "lalr.cxx" // lalr1.cc:859
    break;

  case 60:
#line 226 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '/';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1578 "lalr.cxx" // lalr1.cc:859
    break;

  case 61:
#line 231 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '<';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1588 "lalr.cxx" // lalr1.cc:859
    break;

  case 62:
#line 236 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '>';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1598 "lalr.cxx" // lalr1.cc:859
    break;

  case 63:
#line 241 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '=';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1608 "lalr.cxx" // lalr1.cc:859
    break;

  case 64:
#line 246 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '!';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1618 "lalr.cxx" // lalr1.cc:859
    break;

  case 65:
#line 251 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = 'g';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1628 "lalr.cxx" // lalr1.cc:859
    break;

  case 66:
#line 256 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = 'l';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1638 "lalr.cxx" // lalr1.cc:859
    break;

  case 67:
#line 261 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '&';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1648 "lalr.cxx" // lalr1.cc:859
    break;

  case 68:
#line 266 "lalr.y" // lalr1.cc:859
    {auto operation = BinOp();
                     operation.op = '|';
             operation.lhs = yystack_[2].value.as< Expr > ();
             operation.rhs = yystack_[0].value.as< Expr > ();
             yylhs.value.as< Expr > () = operation;}
#line 1658 "lalr.cxx" // lalr1.cc:859
    break;

  case 69:
#line 271 "lalr.y" // lalr1.cc:859
    {auto operation = UnOp();
        operation.op = 'p';
        operation.expr = yystack_[1].value.as< Expr > ();
        yylhs.value.as< Expr > () = operation;}
#line 1667 "lalr.cxx" // lalr1.cc:859
    break;

  case 70:
#line 275 "lalr.y" // lalr1.cc:859
    {auto operation = UnOp();
        operation.op = '!';
        operation.expr = yystack_[0].value.as< Expr > ();
        yylhs.value.as< Expr > () = operation;}
#line 1676 "lalr.cxx" // lalr1.cc:859
    break;

  case 71:
#line 279 "lalr.y" // lalr1.cc:859
    {auto operation = UnOp();
        operation.op = '-';
        operation.expr = yystack_[0].value.as< Expr > ();
        yylhs.value.as< Expr > () = operation;}
#line 1685 "lalr.cxx" // lalr1.cc:859
    break;

  case 72:
#line 283 "lalr.y" // lalr1.cc:859
    {Access acc;
                acc.id = yystack_[1].value.as< std::string > ();
                yylhs.value.as< Expr > () = acc;
                }
#line 1694 "lalr.cxx" // lalr1.cc:859
    break;

  case 73:
#line 287 "lalr.y" // lalr1.cc:859
    { yylhs.value.as< Expr > () = yystack_[0].value.as< Literal > (); }
#line 1700 "lalr.cxx" // lalr1.cc:859
    break;

  case 74:
#line 289 "lalr.y" // lalr1.cc:859
    {}
#line 1706 "lalr.cxx" // lalr1.cc:859
    break;

  case 75:
#line 290 "lalr.y" // lalr1.cc:859
    { 
        std::vector<Expr> indexes;
        indexes = std::vector<Expr>();
        indexes.push_back(yystack_[2].value.as< Expr > ());
        yylhs.value.as< std::vector<Expr> > () = indexes;
    }
#line 1717 "lalr.cxx" // lalr1.cc:859
    break;


#line 1721 "lalr.cxx" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -63;

  const signed char parser::yytable_ninf_ = -75;

  const short int
  parser::yypact_[] =
  {
     -63,    12,     9,   -63,     3,   -37,     8,   -29,     5,   -63,
     -22,     2,   -63,   -20,   -63,   -63,   -41,   -63,   -15,    28,
     -63,    49,    24,    83,   -63,    -2,   -63,   -63,   -63,    -4,
     -63,   -63,   -63,    10,    17,     6,    51,    50,    23,    51,
     -63,    25,    41,    51,    51,    42,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    57,   101,     5,
      51,   -63,   -63,   194,    43,   -63,   -63,   -63,    51,    51,
      51,   -63,   215,   -63,   -63,   310,     5,   -63,    45,    46,
     228,   250,   -63,    51,    82,    52,    47,   271,   -63,   -63,
     -63,   -63,   292,   -63,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,   131,   -40,    51,
     -63,    51,   -63,    43,   310,   -63,    56,    90,   -63,     7,
       1,     1,     1,   323,   323,     1,     1,     1,    79,    79,
     -63,   -63,   -63,   -63,   -63,    64,   228,   -63,   -63,    49,
     -63,    94,   -63,   -63,   157,   -63,   183,   -63,   103,   -63
  };

  const unsigned char
  parser::yydefact_[] =
  {
       4,     0,     8,     1,     0,     0,     0,     0,     0,     5,
       0,     0,     2,     0,     6,    19,     0,    21,     0,     0,
       9,     0,     0,     0,    21,     0,    12,    13,    14,     0,
       7,    15,    20,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    47,    49,     0,     0,    24,    25,    27,    31,
      33,    34,    35,    36,    29,    30,    28,     0,     0,    17,
       0,    23,     3,    74,    74,    53,    54,    55,     0,     0,
       0,    73,     0,    40,    21,    42,     0,    46,     0,     0,
      52,     0,    22,     0,     0,     0,    18,     0,    26,    72,
      71,    70,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      48,     0,    50,    74,    32,    11,     0,     0,    69,     0,
      64,    65,    66,    67,    68,    62,    61,    63,    56,    57,
      58,    60,    59,    41,    44,     0,    52,    75,    21,     0,
      21,     0,    45,    51,     0,    16,     0,    37,     0,    10
  };

  const signed char
  parser::yypgoto_[] =
  {
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -16,   -63,   -63,
     -58,   -24,   -63,   -63,    67,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,    26,    -3,   -63,   -23,
     -62
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    12,     2,     5,     6,    13,    30,    31,    85,
      16,    23,    45,    46,    47,    48,    49,    50,   141,    51,
      52,    53,    54,    55,    78,    56,    79,   112,    71,    80,
      57
  };

  const short int
  parser::yytable_[] =
  {
      58,    86,    89,    18,     7,    21,   134,     9,    33,    22,
      22,    10,     3,    72,     4,    14,    75,    15,   108,    35,
      11,    81,    17,    36,    20,   -39,   140,    37,    38,    24,
      39,    40,    41,    42,    25,   -74,    32,    87,   102,   103,
     104,   105,   106,    59,    60,    90,    91,    92,     8,    19,
     107,   137,    43,    63,    61,    44,    26,    27,    28,    29,
     114,    62,    73,    64,    65,    66,    67,    74,    77,   119,
      76,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    33,    83,    82,    34,   136,    68,
     109,    44,   110,    69,   115,    35,    70,    22,   116,    36,
     138,   139,    33,    37,    38,    84,    39,    40,    41,    42,
     142,   -74,   147,    35,   144,   149,   146,    36,   104,   105,
     106,    37,    38,   145,    39,    40,    41,    42,    43,   -74,
      88,    44,    33,   143,     0,   135,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,    43,    36,     0,    44,
       0,    37,    38,   133,    39,    40,    41,    42,    33,   -74,
       0,   148,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    43,    37,    38,    44,
      39,    40,    41,    42,    33,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,    36,
       0,   -38,    43,    37,    38,    44,    39,    40,    41,    42,
      36,   -74,     0,     0,    37,    38,     0,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,    43,     0,
       0,    44,    93,     0,     0,     0,     0,     0,     0,    43,
       0,     0,    44,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   111,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,   113,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
     117,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,   118,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    94,    95,    96,     0,     0,    99,   100,   101,
     102,   103,   104,   105,   106
  };

  const short int
  parser::yycheck_[] =
  {
      24,    59,    64,     1,     1,    46,    46,    44,     1,    50,
      50,     3,     0,    36,     5,    44,    39,    12,    76,    12,
      12,    44,    44,    16,    44,    18,    19,    20,    21,    44,
      23,    24,    25,    26,     6,    28,    12,    60,    37,    38,
      39,    40,    41,    45,    48,    68,    69,    70,    45,    47,
      74,   113,    45,    47,    44,    48,     7,     8,     9,    10,
      83,    44,    12,    12,    13,    14,    15,    44,    27,    93,
      45,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     1,    28,    44,     4,   111,    38,
      45,    48,    46,    42,    12,    12,    45,    50,    46,    16,
      44,    11,     1,    20,    21,     4,    23,    24,    25,    26,
      46,    28,    18,    12,   138,    12,   140,    16,    39,    40,
      41,    20,    21,   139,    23,    24,    25,    26,    45,    28,
      63,    48,     1,   136,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    45,    16,    -1,    48,
      -1,    20,    21,    22,    23,    24,    25,    26,     1,    28,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    45,    20,    21,    48,
      23,    24,    25,    26,     1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    18,    45,    20,    21,    48,    23,    24,    25,    26,
      16,    28,    -1,    -1,    20,    21,    -1,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    48,    17,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    29,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    52,    54,     0,     5,    55,    56,     1,    45,    44,
       3,    12,    53,    57,    44,    12,    61,    44,     1,    47,
      44,    46,    50,    62,    44,     6,     7,     8,     9,    10,
      58,    59,    12,     1,     4,    12,    16,    20,    21,    23,
      24,    25,    26,    45,    48,    63,    64,    65,    66,    67,
      68,    70,    71,    72,    73,    74,    76,    81,    62,    45,
      48,    44,    44,    47,    12,    13,    14,    15,    38,    42,
      45,    79,    80,    12,    44,    80,    45,    27,    75,    77,
      80,    80,    44,    28,     4,    60,    61,    80,    65,    81,
      80,    80,    80,    17,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    62,    61,    45,
      46,    50,    78,    49,    80,    12,    46,    49,    46,    62,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    22,    46,    77,    80,    81,    44,    11,
      19,    69,    46,    78,    62,    58,    62,    18,     4,    12
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    51,    52,    53,    54,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    64,    65,    65,    65,
      65,    65,    66,    67,    67,    67,    67,    68,    69,    69,
      70,    71,    72,    73,    74,    74,    75,    75,    76,    77,
      77,    78,    78,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    81
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     3,     5,     0,     3,     4,     5,     0,     3,
      10,     6,     1,     1,     1,     1,     6,     0,     1,     1,
       3,     0,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     6,     2,     0,
       2,     4,     2,     1,     4,     5,     1,     0,     3,     0,
       2,     3,     0,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     1,     0,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "START", "END", "DECLARE", "PROCEDURE",
  "INT_TYPE", "FLOAT_TYPE", "CHAR_TYPE", "ARRAY", "OF", "IDENTIFIER",
  "INTEGER", "FLOAT", "CHAR", "IF", "THEN", "ENDIF", "ELSE", "GOTO",
  "LOOP", "ENDLOOP", "EXITWHEN", "STOP", "GET", "PUT", "SKIP", "ATTR_SIGN",
  "DIFF_SIGN", "GREATER_EQ_SIGN", "LESS_EQ_SIGN", "'&'", "'|'", "'>'",
  "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "';'",
  "'('", "')'", "':'", "'['", "']'", "','", "$accept", "program", "body",
  "decl_list", "decl_stmt", "proc_decl_list", "proc_decl", "data_type",
  "array_nont", "super_id_list", "id_list", "stmt_list", "super_stmt",
  "label_stmt", "stmt", "attr_stmt", "control_stmt", "if_stmt",
  "else_stmt", "goto_stmt", "loop_stmt", "exit_stmt", "stop_stmt",
  "io_stmt", "skip_stmt", "proc_stmt", "expr_list", "expr_list_tail",
  "literal", "expr", "array_access", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    92,    92,    94,    96,    97,   103,   106,   120,   121,
     124,   125,   128,   129,   130,   131,   133,   135,   136,   138,
     141,   145,   146,   151,   153,   153,   155,   161,   161,   161,
     161,   161,   163,   170,   171,   172,   173,   175,   177,   178,
     180,   182,   184,   186,   188,   189,   191,   192,   194,   196,
     197,   199,   200,   202,   203,   204,   206,   211,   216,   221,
     226,   231,   236,   241,   246,   251,   256,   261,   266,   271,
     275,   279,   283,   287,   289,   290
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    41,    32,     2,
      45,    46,    39,    37,    50,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    44,
      35,    36,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    43
    };
    const unsigned int user_token_number_max_ = 287;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2285 "lalr.cxx" // lalr1.cc:1167
#line 296 "lalr.y" // lalr1.cc:1168


void yy::parser::error(const parser::location_type& l, const std::string& m)
{
    throw yy::parser::syntax_error(l, m);
}

int main() {
    yy::scanner scanner;
    yy::parser parser(&scanner);
    try {
        int result = parser.parse();
        if (result != 0)
            throw std::runtime_error("Unknown parsing error");
    } catch (yy::parser::syntax_error& e) {
        int row = e.location.begin.line;
        int col = e.location.begin.column;

        std::ostringstream msg;
        msg << e.what()
            << " in row " << row
            << " col " << col << "\n";
        throw yy::parser::syntax_error(e.location, msg.str());
    }
}

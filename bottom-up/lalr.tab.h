/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_LALR_TAB_H_INCLUDED
# define YY_YY_LALR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    START = 258,
    END = 259,
    DECLARE = 260,
    PROCEDURE = 261,
    INT_TYPE = 262,
    FLOAT_TYPE = 263,
    CHAR_TYPE = 264,
    ARRAY = 265,
    OF = 266,
    IDENTIFIER = 267,
    INTEGER = 268,
    FLOAT = 269,
    CHAR = 270,
    IF = 271,
    THEN = 272,
    ENDIF = 273,
    ELSE = 274,
    GOTO = 275,
    LOOP = 276,
    ENDLOOP = 277,
    EXITWHEN = 278,
    STOP = 279,
    GET = 280,
    PUT = 281,
    SKIP = 282,
    ATTR_SIGN = 283,
    DIFF_SIGN = 284,
    GREATER_EQ_SIGN = 285,
    LESS_EQ_SIGN = 286,
    UMINUS = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "lalr.y" /* yacc.c:1909  */
Node vdc; VarDec* var;DecList* dec_list; ProList* pro_list; StmtList* stmt_list; std::string* sg; SimpleType st;Expr* expr; int i; Literal* lit; std::vector<Expr*>* exprs; AttrStmt* att; Post_Labelless_Stmt* post; 

#line 90 "lalr.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LALR_TAB_H_INCLUDED  */

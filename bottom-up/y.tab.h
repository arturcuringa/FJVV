/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
/* Tokens.  */
#define START 258
#define END 259
#define DECLARE 260
#define PROCEDURE 261
#define INT_TYPE 262
#define FLOAT_TYPE 263
#define CHAR_TYPE 264
#define ARRAY 265
#define OF 266
#define IDENTIFIER 267
#define INTEGER 268
#define FLOAT 269
#define CHAR 270
#define IF 271
#define THEN 272
#define ENDIF 273
#define ELSE 274
#define GOTO 275
#define LOOP 276
#define ENDLOOP 277
#define EXITWHEN 278
#define STOP 279
#define GET 280
#define PUT 281
#define SKIP 282
#define ATTR_SIGN 283
#define DIFF_SIGN 284
#define GREATER_EQ_SIGN 285
#define LESS_EQ_SIGN 286
#define UMINUS 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

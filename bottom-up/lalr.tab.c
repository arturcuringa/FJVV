/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "lalr.y" /* yacc.c:339  */


#include <stdio.h>
#include <vector>
#include <string.h>
#include <memory>
#include "lex.yy.c"
#include "abstract_tree.h"

extern unsigned int line;
extern unsigned int col;
extern char* yytext; 
extern std::string id;

int yydebug = 1;
void yyerror(const char *str){
	fprintf(stderr, "error (line %d, col %d): %s\n", line, col, str);
}

Program root;


#line 89 "lalr.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "lalr.tab.h".  */
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
#line 25 "lalr.y" /* yacc.c:355  */
Node vdc; VarDec* var;DecList* dec_list; ProList* pro_list; StmtList* stmt_list; std::string* sg; SimpleType st;Expr* expr; int i; Literal* lit; std::vector<Expr*>* exprs; AttrStmt* att; Post_Labelless_Stmt* post; std::vector<std::string*>* vsg; Stmt* stmt;

#line 165 "lalr.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LALR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "lalr.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    83,    85,    86,   100,   103,   118,   119,
     122,   123,   126,   127,   128,   129,   131,   133,   134,   136,
     139,   143,   144,   151,   154,   155,   158,   164,   165,   166,
     168,   168,   170,   174,   175,   177,   183,   184,   185,   187,
     188,   189,   190,   192,   194,   195,   197,   199,   201,   203,
     205,   206,   208,   209,   211,   213,   214,   216,   217,   218,
     221,   224,   228,   233,   238,   243,   248,   253,   258,   263,
     268,   273,   278,   283,   288,   293,   297,   301,   305,   312,
     314,   315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
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
  "label_stmt", "post_label_stmt", "stmt", "labelless_stmt",
  "post_labelless_stmt", "attr_stmt", "idless_stmt", "control_stmt",
  "if_stmt", "else_stmt", "goto_stmt", "loop_stmt", "exit_stmt",
  "stop_stmt", "io_stmt", "skip_stmt", "proc_stmt", "expr_list",
  "expr_list_tail", "literal", "expr", "array_access", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    38,   124,    62,    60,    61,    43,    45,    42,
      47,    37,    33,   287,    59,    40,    41,    58,    91,    93,
      44
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    12,     0,   -65,     5,   -37,    27,   -11,    24,   -65,
      -1,     2,   -65,    14,   -65,   -65,   -32,   -65,    16,    34,
     -65,   192,    32,    41,   -65,    11,   -65,   -65,   -65,    15,
     -65,   -65,   -65,    30,    45,     7,    -4,    56,    46,    -4,
     -65,    47,    66,    50,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,    87,    24,    -4,   -65,   -65,    -4,   252,
      -4,   -65,   -65,   -65,    68,    49,   -65,   -65,   -65,    -4,
      -4,    -4,   -65,   144,   -65,   -65,   250,    24,   -65,    53,
     -65,    88,    55,    52,   179,    58,   157,   -28,   -65,   -65,
     -65,   200,    -4,   -65,   -65,   -65,   221,   -65,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,   104,   -15,    -4,   -65,    62,   103,   -65,    -4,   -65,
     -65,   -65,   -65,    49,   250,   -65,     3,    98,    98,    98,
     263,   263,    98,    98,    98,    31,    31,   -65,   -65,   -65,
     -65,   -65,    63,   -65,   192,   157,   -65,   -65,    97,   -65,
     130,   -65,   -65,   146,   -65,   105,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     8,     1,     0,     0,     0,     0,     0,     5,
       0,     0,     2,     0,     6,    19,     0,    21,     0,     0,
       9,     0,     0,     0,    21,     0,    12,    13,    14,     0,
       7,    15,    20,     0,     0,    80,     0,     0,     0,     0,
      49,     0,    53,     0,    24,    25,    38,    39,    40,    41,
      42,    36,    37,     0,    17,     0,    23,     3,    55,     0,
       0,    26,    28,    29,     0,    80,    59,    60,    61,     0,
       0,     0,    79,     0,    46,    21,    48,     0,    52,     0,
      22,     0,     0,    18,     0,     0,    58,    80,    27,    30,
      31,     0,     0,    78,    77,    76,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    11,     0,     0,    54,     0,    56,
      32,    33,    34,    80,    35,    75,     0,    70,    71,    72,
      73,    74,    68,    67,    69,    62,    63,    64,    66,    65,
      47,    50,     0,    21,     0,    58,    81,    21,     0,    51,
       0,    16,    57,     0,    43,     0,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -26,   -65,   -65,
     -52,   -24,   -65,   -65,   -65,   -65,   -65,   -65,    35,    73,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    54,
       8,   -12,   -65,   -23,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    12,     2,     5,     6,    13,    30,    31,    82,
      16,    23,    43,    44,    61,    88,    89,   120,    62,    45,
      46,    47,   148,    48,    49,    50,    51,    52,    79,    63,
      85,   119,    72,    86,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    93,    83,    18,    33,     4,     7,     9,    65,    66,
      67,    68,     3,    73,    21,    35,    76,    58,    22,    36,
      60,   -45,   147,    37,    38,   112,    39,    40,    41,    42,
      10,   141,    84,    14,    69,    22,    15,    91,    70,    11,
      25,    71,    33,    17,    32,    34,    94,    95,    96,    19,
       8,   111,    58,    35,    59,    60,    54,    36,    20,   146,
      24,    37,    38,    55,    39,    40,    41,    42,    74,   124,
     108,   109,   110,   126,    56,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    33,    57,
      75,    81,    77,    78,    80,   145,    92,    60,   113,    35,
     114,   115,    22,    36,   117,    33,   143,    37,    38,   149,
      39,    40,    41,    42,   144,   154,    35,   156,   151,   150,
      36,   142,   121,   153,    37,    38,   140,    39,    40,    41,
      42,    33,    90,   152,   155,   106,   107,   108,   109,   110,
       0,   122,    35,     0,     0,     0,    36,    33,     0,     0,
      37,    38,     0,    39,    40,    41,    42,     0,    35,     0,
       0,    97,    36,     0,   -44,     0,    37,    38,     0,    39,
      40,    41,    42,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    26,
      27,    28,    29,     0,     0,     0,     0,   118,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   116,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   123,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,    87,     0,     0,   125,    36,     0,
       0,     0,    37,    38,     0,    39,    40,    41,    42,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    98,    99,   100,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      24,    65,    54,     1,     1,     5,     1,    44,    12,    13,
      14,    15,     0,    36,    46,    12,    39,    45,    50,    16,
      48,    18,    19,    20,    21,    77,    23,    24,    25,    26,
       3,    46,    55,    44,    38,    50,    12,    60,    42,    12,
       6,    45,     1,    44,    12,     4,    69,    70,    71,    47,
      45,    75,    45,    12,    47,    48,    45,    16,    44,   123,
      44,    20,    21,    48,    23,    24,    25,    26,    12,    92,
      39,    40,    41,    97,    44,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     1,    44,
      44,     4,    45,    27,    44,   118,    28,    48,    45,    12,
      12,    46,    50,    16,    46,     1,    44,    20,    21,    46,
      23,    24,    25,    26,    11,    18,    12,    12,   144,   143,
      16,   113,    87,   147,    20,    21,    22,    23,    24,    25,
      26,     1,    59,   145,     4,    37,    38,    39,    40,    41,
      -1,    87,    12,    -1,    -1,    -1,    16,     1,    -1,    -1,
      20,    21,    -1,    23,    24,    25,    26,    -1,    12,    -1,
      -1,    17,    16,    -1,    18,    -1,    20,    21,    -1,    23,
      24,    25,    26,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    50,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    12,    -1,    -1,    46,    16,    -1,
      -1,    -1,    20,    21,    -1,    23,    24,    25,    26,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    29,    30,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    54,     0,     5,    55,    56,     1,    45,    44,
       3,    12,    53,    57,    44,    12,    61,    44,     1,    47,
      44,    46,    50,    62,    44,     6,     7,     8,     9,    10,
      58,    59,    12,     1,     4,    12,    16,    20,    21,    23,
      24,    25,    26,    63,    64,    70,    71,    72,    74,    75,
      76,    77,    78,    62,    45,    48,    44,    44,    45,    47,
      48,    65,    69,    80,    85,    12,    13,    14,    15,    38,
      42,    45,    83,    84,    12,    44,    84,    45,    27,    79,
      44,     4,    60,    61,    84,    81,    84,    12,    66,    67,
      70,    84,    28,    85,    84,    84,    84,    17,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    62,    61,    45,    12,    46,    49,    46,    50,    82,
      68,    69,    80,    49,    84,    46,    62,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      22,    46,    81,    44,    11,    84,    85,    19,    73,    46,
      62,    58,    82,    62,    18,     4,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    54,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    64,    65,    65,    65,
      66,    66,    67,    68,    68,    69,    70,    70,    70,    71,
      71,    71,    71,    72,    73,    73,    74,    75,    76,    77,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     5,     0,     3,     4,     5,     0,     3,
      10,     6,     1,     1,     1,     1,     6,     0,     1,     1,
       3,     0,     3,     3,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     2,     0,     2,     4,     2,     1,
       4,     5,     1,     0,     3,     0,     2,     3,     0,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "lalr.y" /* yacc.c:1646  */
    { root.var_dec = (yyvsp[-2].dec_list); 
					 root.print();
					}
#line 1404 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "lalr.y" /* yacc.c:1646  */
    {(yyval.dec_list) = NULL;}
#line 1410 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "lalr.y" /* yacc.c:1646  */
    {
				    DecList* a;
				    
					if((yyvsp[-2].dec_list) != NULL){
						a = (yyvsp[-2].dec_list);
				    } else {
						a = new DecList();
					}

				    if((yyvsp[-1].var) != nullptr){
						a->push_back((yyvsp[-1].var));
				    }
		                    
				    (yyval.dec_list) = a; }
#line 1429 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 103 "lalr.y" /* yacc.c:1646  */
    {
		VarDec* vd = new VarDec();
		vd->ids = (yyvsp[-2].vsg);
		Type* ty = new Type();
		if((yyvsp[0].st) == SimpleType::ST_INT)
			ty->type = SimpleType::ST_INT;
		if((yyvsp[0].st) == SimpleType::ST_FLOAT)
			ty->type = SimpleType::ST_FLOAT;
		if((yyvsp[0].st) == SimpleType::ST_FLOAT)
			ty->type = SimpleType::ST_FLOAT;
		vd->type.push_back(ty);
		(yyval.var) = vd;
	}
#line 1447 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "lalr.y" /* yacc.c:1646  */
    {(yyval.st) = SimpleType::ST_INT;}
#line 1453 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "lalr.y" /* yacc.c:1646  */
    {(yyval.st) = SimpleType::ST_FLOAT;}
#line 1459 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "lalr.y" /* yacc.c:1646  */
    {(yyval.st) = SimpleType::ST_CHAR;}
#line 1465 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "lalr.y" /* yacc.c:1646  */
    { std::vector<std::string*>* s = new std::vector<std::string*>();
       		     s->push_back(new std::string(id));
       		     (yyval.vsg) = s; }
#line 1473 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "lalr.y" /* yacc.c:1646  */
    {std::vector<std::string*>* s = (yyvsp[-2].vsg);
				 s->push_back(new std::string(id));
       		     		 (yyval.vsg) = s; }
#line 1481 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 143 "lalr.y" /* yacc.c:1646  */
    {(yyval.stmt_list) = NULL;}
#line 1487 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 144 "lalr.y" /* yacc.c:1646  */
    { 
		StmtList* a = (yyvsp[-2].stmt_list);
		if (a == NULL)
			a = new StmtList();
		a->push_back((yyvsp[-1].stmt));
		(yyval.stmt_list) = a;
		}
#line 1499 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "lalr.y" /* yacc.c:1646  */
    {
	Stmt* a = (yyvsp[0].stmt);
	a->label = (yyvsp[-1].sg);
	(yyval.stmt) = a;
}
#line 1509 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 170 "lalr.y" /* yacc.c:1646  */
    {Post_Labelless_Stmt* p = (yyvsp[0].post);
						p->label = new std::string(id);
						p->print();}
#line 1517 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 174 "lalr.y" /* yacc.c:1646  */
    {(yyval.post) = (yyvsp[0].att);}
#line 1523 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 177 "lalr.y" /* yacc.c:1646  */
    {AttrStmt* attr = new AttrStmt();
	 				attr->lhs = (yyvsp[-2].exprs);
					attr->rhs = (yyvsp[0].expr);
					(yyval.att) = attr;
					}
#line 1533 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 218 "lalr.y" /* yacc.c:1646  */
    {Literal* lit = new Literal();
       		 lit->i = {std::stoi(yytext)};
		 (yyval.lit) = lit;}
#line 1541 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 221 "lalr.y" /* yacc.c:1646  */
    {Literal* lit = new Literal();
       		 lit->f = {std::stof(yytext)};
		 (yyval.lit) = lit;}
#line 1549 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 224 "lalr.y" /* yacc.c:1646  */
    {Literal* lit = new Literal();
       		 lit->c = {yytext[0]};
		 (yyval.lit) = lit;}
#line 1557 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 228 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '+';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1567 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 233 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '-';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1577 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 238 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '*';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1587 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '%';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1597 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 248 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '/';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1607 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 253 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '<';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1617 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 258 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '>';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1627 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 263 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '=';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1637 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 268 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '!';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1647 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 273 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = 'g';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1657 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 278 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = 'l';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1667 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 283 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '&';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1677 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 288 "lalr.y" /* yacc.c:1646  */
    {BinOp* operation = new BinOp();
    	             operation->op = '|';
		     operation->lhs = (yyvsp[-2].expr);
		     operation->rhs = (yyvsp[0].expr);
		     (yyval.expr) = operation;}
#line 1687 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 293 "lalr.y" /* yacc.c:1646  */
    {UnOp* operation = new UnOp();
		operation->op = 'p';
		operation->expr = (yyvsp[-1].expr);
		(yyval.expr) = operation;}
#line 1696 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 297 "lalr.y" /* yacc.c:1646  */
    {UnOp* operation = new UnOp();
		operation->op = '!';
		operation->expr = (yyvsp[0].expr);
		(yyval.expr) = operation;}
#line 1705 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 301 "lalr.y" /* yacc.c:1646  */
    {UnOp* operation = new UnOp();
		operation->op = '-';
		operation->expr = (yyvsp[0].expr);
		(yyval.expr) = operation;}
#line 1714 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 305 "lalr.y" /* yacc.c:1646  */
    {Access* acc = new Access();
				acc->id = new std::string(id);
				if((yyvsp[0].exprs) != NULL){
					acc->indexes = *((yyvsp[0].exprs));	
				}
				(yyval.expr) = acc;
				}
#line 1726 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 312 "lalr.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].lit); }
#line 1732 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 314 "lalr.y" /* yacc.c:1646  */
    {(yyval.exprs) = NULL;}
#line 1738 "lalr.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 315 "lalr.y" /* yacc.c:1646  */
    { std::vector<Expr*>* indexes;
				      if((yyvsp[0].exprs) != NULL)
					indexes	 = (yyvsp[0].exprs);
				      else indexes = new std::vector<Expr*>();
				      indexes->push_back((yyvsp[-2].expr));
				      (yyval.exprs) = indexes;
					}
#line 1750 "lalr.tab.c" /* yacc.c:1646  */
    break;


#line 1754 "lalr.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 323 "lalr.y" /* yacc.c:1906  */


int main() {
	return(yyparse());
}


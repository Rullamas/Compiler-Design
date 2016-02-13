
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

// Dummy parser for scanner project.

#include "lyutils.h"
#include "astree.h"
#include "assert.h"



/* Line 189 of yacc.c  */
#line 83 "yyparse.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_VOID = 258,
     TOK_BOOL = 259,
     TOK_CHAR = 260,
     TOK_INT = 261,
     TOK_STRING = 262,
     TOK_IF = 263,
     TOK_ELSE = 264,
     TOK_WHILE = 265,
     TOK_RETURN = 266,
     TOK_STRUCT = 267,
     TOK_FALSE = 268,
     TOK_TRUE = 269,
     TOK_NULL = 270,
     TOK_NEW = 271,
     TOK_ARRAY = 272,
     TOK_EQ = 273,
     TOK_NE = 274,
     TOK_LT = 275,
     TOK_LE = 276,
     TOK_GT = 277,
     TOK_GE = 278,
     TOK_IDENT = 279,
     TOK_INTCON = 280,
     TOK_CHARCON = 281,
     TOK_STRINGCON = 282,
     TOK_BLOCK = 283,
     TOK_CALL = 284,
     TOK_IFELSE = 285,
     TOK_INITDECL = 286,
     TOK_POS = 287,
     TOK_NEG = 288,
     TOK_NEWARRAY = 289,
     TOK_TYPEID = 290,
     TOK_FIELD = 291,
     TOK_ORD = 292,
     TOK_CHR = 293,
     TOK_ROOT = 294,
     vardecl = 295,
     type = 296,
     basetype = 297,
     constant = 298,
     program = 299,
     decl = 300,
     struct_ = 301,
     function = 302,
     block = 303,
     while_ = 304,
     return_ = 305,
     call = 306,
     unop = 307,
     binop = 308,
     allocator_ = 309,
     variable = 310,
     if_ = 311,
     else_ = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 182 "yyparse.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   642

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,     2,     2,    63,     2,     2,
      70,    71,    61,    59,    72,    60,    66,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    69,
       2,    58,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    68,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    15,    21,    25,
      26,    29,    32,    34,    36,    38,    40,    42,    44,    46,
      53,    59,    63,    65,    69,    71,    74,    75,    77,    79,
      81,    83,    85,    88,    94,   100,   106,   114,   118,   121,
     123,   125,   129,   131,   133,   135,   137,   140,   143,   146,
     149,   152,   156,   160,   164,   168,   172,   176,   180,   184,
     188,   192,   196,   200,   206,   211,   217,   222,   226,   230,
     232,   237,   241,   243,   245,   247,   249,   251,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    76,    -1,    76,    77,    -1,    76,    82,
      -1,    76,    86,    -1,    -1,    12,    24,    67,    78,    68,
      -1,    78,    79,    69,    -1,    -1,    80,    24,    -1,    81,
      17,    -1,    81,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,     7,    -1,    24,    -1,    80,    24,    70,    83,
      71,    84,    -1,    80,    24,    70,    71,    84,    -1,    83,
      72,    79,    -1,    79,    -1,    67,    85,    68,    -1,    69,
      -1,    85,    86,    -1,    -1,    84,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,    91,    69,    -1,    80,    24,
      58,    91,    69,    -1,    10,    70,    91,    71,    86,    -1,
       8,    70,    91,    71,    86,    -1,     8,    70,    91,    71,
      86,     9,    86,    -1,    11,    91,    69,    -1,    11,    69,
      -1,    92,    -1,    93,    -1,    70,    91,    71,    -1,    94,
      -1,    95,    -1,    97,    -1,    98,    -1,    59,    91,    -1,
      60,    91,    -1,    64,    91,    -1,    37,    91,    -1,    38,
      91,    -1,    91,    58,    91,    -1,    91,    18,    91,    -1,
      91,    19,    91,    -1,    91,    21,    91,    -1,    91,    20,
      91,    -1,    91,    22,    91,    -1,    91,    23,    91,    -1,
      91,    59,    91,    -1,    91,    60,    91,    -1,    91,    61,
      91,    -1,    91,    62,    91,    -1,    91,    63,    91,    -1,
      16,    81,    70,    91,    71,    -1,    16,    81,    70,    71,
      -1,    16,    81,    65,    91,    73,    -1,    24,    70,    96,
      71,    -1,    24,    70,    71,    -1,    96,    72,    91,    -1,
      91,    -1,    91,    65,    91,    73,    -1,    91,    66,    24,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    13,
      -1,    14,    -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    44,    45,    46,    47,    50,    53,    54,
      57,    60,    61,    64,    65,    66,    67,    68,    69,    72,
      73,    76,    77,    80,    81,    84,    85,    88,    89,    90,
      91,    92,    93,    96,   100,   103,   104,   107,   108,   111,
     112,   113,   114,   115,   116,   117,   120,   121,   122,   123,
     124,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   144,   145,   146,   149,   150,   153,   154,
     157,   158,   159,   162,   163,   164,   165,   166,   167
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_BOOL", "TOK_CHAR",
  "TOK_INT", "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE", "TOK_NULL", "TOK_NEW",
  "TOK_ARRAY", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE",
  "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON", "TOK_BLOCK",
  "TOK_CALL", "TOK_IFELSE", "TOK_INITDECL", "TOK_POS", "TOK_NEG",
  "TOK_NEWARRAY", "TOK_TYPEID", "TOK_FIELD", "TOK_ORD", "TOK_CHR",
  "TOK_ROOT", "vardecl", "type", "basetype", "constant", "program", "decl",
  "struct_", "function", "block", "while_", "return_", "call", "unop",
  "binop", "allocator_", "variable", "if_", "else_", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'['", "'.'", "'{'", "'}'", "';'", "'('",
  "')'", "','", "']'", "$accept", "program1", "stmtseq", "structdef",
  "declgroup", "decl1", "type1", "basetype1", "function1", "comdecl",
  "block1", "blockstmt", "statement", "vardecl1", "while1", "ifelse",
  "return1", "expr", "unop1", "binop1", "allocator1", "call1", "comexpr",
  "variable1", "constant1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    61,    43,
      45,    42,    47,    37,    33,    91,    46,   123,   125,    59,
      40,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    76,    77,    78,    78,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     5,     3,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     6,
       5,     3,     1,     3,     1,     2,     0,     1,     1,     1,
       1,     1,     2,     5,     5,     5,     7,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     5,     4,     3,     3,     1,
       4,     3,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,    13,    14,    15,    16,    17,     0,
       0,     0,     0,    76,    77,    78,     0,    72,    73,    74,
      75,     0,     0,     0,     0,     0,    26,    24,     0,     3,
       0,    12,     4,    27,     5,    28,    29,    30,    31,     0,
      39,    40,    42,    43,    44,    45,     0,     0,    72,    38,
       0,     0,    18,     0,     0,    49,    50,    46,    47,    48,
       0,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,    37,     9,     0,     0,    67,    69,     0,    23,     0,
      25,    41,     0,     0,    52,    53,    55,    54,    56,    57,
      51,    58,    59,    60,    61,    62,     0,    71,     0,     0,
       0,     0,    64,     0,    66,     0,     0,     0,     0,    22,
       0,     0,    70,    35,    34,     7,     0,    65,    63,    68,
      33,    20,    10,     0,     0,     0,     8,    19,    21,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    29,   110,   119,    89,    31,    32,   121,
      33,    60,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    87,    44,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
    -103,    17,   109,  -103,  -103,  -103,  -103,  -103,  -103,   -35,
     -31,   327,    21,  -103,  -103,  -103,    23,     8,  -103,  -103,
    -103,   342,   342,   342,   342,   342,  -103,  -103,   342,  -103,
      43,    51,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   500,
    -103,  -103,  -103,  -103,  -103,  -103,   342,   342,    -1,  -103,
     552,     3,  -103,   -27,   260,   -17,   -17,   -17,   -17,   -17,
     177,   404,   -24,  -103,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,    48,  -103,   418,
     472,  -103,  -103,   342,   312,  -103,   576,   -30,  -103,    52,
    -103,  -103,   342,     0,    27,    27,    27,    27,    27,    27,
     576,    65,    65,   -17,   -17,   -17,    79,  -103,   245,   245,
      16,   395,  -103,   486,  -103,   342,    22,   564,   -59,  -103,
      55,   -19,  -103,    66,  -103,  -103,    12,  -103,  -103,   576,
    -103,  -103,  -103,   -59,    23,   245,  -103,  -103,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,  -103,  -103,  -103,  -101,    -2,    67,  -103,  -103,
    -102,  -103,   -58,  -103,  -103,  -103,  -103,   -10,  -103,  -103,
    -103,  -103,  -103,  -103,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -19
static const yytype_int16 yytable[] =
{
      30,    50,    90,     4,     5,     6,     7,     8,    26,   126,
      27,    55,    56,    57,    58,    59,   131,     3,    61,     4,
       5,     6,     7,     8,    52,   -18,     4,     5,     6,     7,
       8,   137,   -18,   138,    92,    46,    79,    80,    83,    47,
      52,   114,   115,    84,    86,    51,    93,    52,    76,    77,
     123,   124,   133,   134,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    62,    63,    54,
      82,   118,   107,   111,   113,   135,   116,   139,    54,   132,
      92,   136,   117,    53,   125,     0,    71,    72,    73,    74,
      75,   120,    76,    77,     0,     0,     0,    64,    65,    66,
      67,    68,    69,     0,     0,   129,     0,     0,   120,     0,
       0,     0,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    73,    74,    75,     0,
      76,    77,   120,    17,    18,    19,    20,    70,    71,    72,
      73,    74,    75,     0,    76,    77,    21,    22,     0,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
       0,     0,     0,    25,     0,     0,    26,     0,    27,    28,
       4,     5,     6,     7,     8,     9,     0,    10,    11,     0,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,     0,     0,
       0,    25,     0,     0,    26,    88,    27,    28,     4,     5,
       6,     7,     8,     9,     0,    10,    11,     0,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    13,    14,    15,    16,     0,     0,     0,
       0,     0,    21,    22,    48,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,     0,    23,    24,     0,     0,     0,    25,
       0,     0,    26,     0,    27,    28,     0,     0,     0,    23,
      24,     0,     0,     0,    25,    13,    14,    15,    16,     0,
      28,    85,     0,     0,     0,     0,    48,    18,    19,    20,
      13,    14,    15,    16,     0,     0,     0,     0,     0,    21,
      22,    48,    18,    19,    20,    13,    14,    15,    16,     0,
       0,     0,     0,     0,    21,    22,    48,    18,    19,    20,
       0,    23,    24,     0,     0,     0,    25,     0,     0,    21,
      22,     0,    28,   112,     0,     0,    23,    24,     0,     0,
       0,    25,     0,     0,     0,     0,    49,    28,     0,     0,
       0,    23,    24,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    28,    64,    65,    66,    67,    68,    69,     0,
       0,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,     0,
      76,    77,    70,    71,    72,    73,    74,    75,   127,    76,
      77,     0,     0,     0,     0,    91,    70,    71,    72,    73,
      74,    75,     0,    76,    77,     0,     0,     0,     0,   108,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,     0,    76,    77,     0,
       0,     0,     0,   109,    70,    71,    72,    73,    74,    75,
       0,    76,    77,     0,     0,     0,     0,   128,    70,    71,
      72,    73,    74,    75,     0,    76,    77,     0,     0,    78,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,    75,     0,    76,    77,     0,
       0,    81,    70,    71,    72,    73,    74,    75,     0,    76,
      77,     0,     0,   130,    70,    71,    72,    73,    74,    75,
       0,    76,    77
};

static const yytype_int16 yycheck[] =
{
       2,    11,    60,     3,     4,     5,     6,     7,    67,   110,
      69,    21,    22,    23,    24,    25,   118,     0,    28,     3,
       4,     5,     6,     7,    24,    17,     3,     4,     5,     6,
       7,   133,    24,   134,    58,    70,    46,    47,    65,    70,
      24,    71,    72,    70,    54,    24,    70,    24,    65,    66,
     108,   109,    71,    72,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    24,    17,    70,
      67,    71,    24,    83,    84,     9,    24,   135,    70,    24,
      58,    69,    92,    16,    68,    -1,    59,    60,    61,    62,
      63,    93,    65,    66,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,   115,    -1,    -1,   110,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    61,    62,    63,    -1,
      65,    66,   134,    24,    25,    26,    27,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    37,    38,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    64,    -1,    -1,    67,    -1,    69,    70,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    -1,    -1,    67,    68,    69,    70,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    37,    38,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    64,
      -1,    -1,    67,    -1,    69,    70,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    64,    13,    14,    15,    16,    -1,
      70,    71,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    37,
      38,    24,    25,    26,    27,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    37,    38,    24,    25,    26,    27,
      -1,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,    37,
      38,    -1,    70,    71,    -1,    -1,    59,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    70,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    58,    59,    60,    61,    62,    63,    73,    65,
      66,    -1,    -1,    -1,    -1,    71,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    71,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    71,    58,    59,    60,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    71,    58,    59,
      60,    61,    62,    63,    -1,    65,    66,    -1,    -1,    69,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    69,    58,    59,    60,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    69,    58,    59,    60,    61,    62,    63,
      -1,    65,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    76,     0,     3,     4,     5,     6,     7,     8,
      10,    11,    12,    13,    14,    15,    16,    24,    25,    26,
      27,    37,    38,    59,    60,    64,    67,    69,    70,    77,
      80,    81,    82,    84,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    97,    98,    70,    70,    24,    69,
      91,    24,    24,    81,    70,    91,    91,    91,    91,    91,
      85,    91,    24,    17,    18,    19,    20,    21,    22,    23,
      58,    59,    60,    61,    62,    63,    65,    66,    69,    91,
      91,    69,    67,    65,    70,    71,    91,    96,    68,    80,
      86,    71,    58,    70,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    24,    71,    71,
      78,    91,    71,    91,    71,    72,    24,    91,    71,    79,
      80,    83,    73,    86,    86,    68,    79,    73,    71,    91,
      69,    84,    24,    71,    72,     9,    69,    84,    79,    86
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 41 "parser.y"
    { (yyval) = (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 44 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 45 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 46 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 47 "parser.y"
    { (yyval) = new_parseroot(); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 50 "parser.y"
    { (yyval) = adopt1((yyvsp[(4) - (5)]), (yyvsp[(2) - (5)])); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 53 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)])); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 54 "parser.y"
    { (yyval) = new_astree(struct_,0,0,0,""); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 57 "parser.y"
    { (yyval) = adopt2(new_astree(decl,0,0,0,""), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 60 "parser.y"
    { (yyval) = adopt2(new_astree(type,0,0,0,""), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    { (yyval) = adopt1(new_astree(type,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    { (yyval) = adopt1(new_astree(basetype,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    { (yyval) = adopt1(new_astree(basetype,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = adopt1(new_astree(basetype,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    { (yyval) = adopt1(new_astree(basetype,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { (yyval) = adopt1(new_astree(basetype,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    { (yyval) = adopt1(new_astree(basetype,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { (yyval) = adopt1(adopt2((yyvsp[(4) - (6)]), (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)])),(yyvsp[(6) - (6)])); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(function,0,0,0,""), (yyvsp[(1) - (5)]), (yyvsp[(2) - (5)])),(yyvsp[(5) - (5)])); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { (yyval) = adopt1(new_astree(function,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyval) = new_astree(block,0,0,0,""); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {(yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {(yyval) = new_astree(block,0,0,0,""); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(vardecl,0,0,0,""), (yyvsp[(1) - (5)]), (yyvsp[(2) - (5)])), (yyvsp[(4) - (5)])); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    { (yyval) = adopt2(new_astree(while_,0,0,0,""), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyval) = adopt2(new_astree(if_,0,0,0,""), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(if_,0,0,0,""), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)])), (yyvsp[(7) - (7)])); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyval) = adopt1(new_astree(return_,0,0,0,""), (yyvsp[(2) - (3)])); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { (yyval) = new_astree(return_,0,0,0,""); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { (yyval) = adopt1(new_astree(unop,0,0,0,""),adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_POS)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval) = adopt1(new_astree(unop,0,0,0,""),adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_NEG)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { (yyval) = adopt1(new_astree(unop,0,0,0,""),adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),'!')); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { (yyval) = adopt1(new_astree(unop,0,0,0,""),adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_ORD)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    { (yyval) = adopt1(new_astree(unop,0,0,0,""),adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_CHR)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval) = adopt1(adopt2(new_astree(binop,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(3) - (3)])); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval) = adopt2(adopt2(new_astree(allocator_,0,0,0,""),(yyvsp[(1) - (5)]),(yyvsp[(2) - (5)])),(yyvsp[(4) - (5)]),(yyvsp[(3) - (5)])); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval) = adopt2(new_astree(allocator_,0,0,0,""),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)])); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval) = adopt2(adopt2(new_astree(allocator_,0,0,0,""),(yyvsp[(1) - (5)]),(yyvsp[(2) - (5)])),(yyvsp[(4) - (5)]),(yyvsp[(3) - (5)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval) = adopt1((yyvsp[(3) - (4)]), (yyvsp[(1) - (4)])); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval) = adopt1(new_astree(call,0,0,0,""), (yyvsp[(1) - (3)])); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval) = adopt1(new_astree(call,0,0,0,""),(yyvsp[(1) - (1)])); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { (yyval) = adopt2(new_astree(variable,0,0,0,""), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { (yyval) = adopt2(new_astree(variable,0,0,0,""), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { (yyval) = adopt1(new_astree(variable,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { (yyval) = adopt1(new_astree(constant,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval) = adopt1(new_astree(constant,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval) = adopt1(new_astree(constant,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval) = adopt1(new_astree(constant,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = adopt1(new_astree(constant,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { (yyval) = adopt1(new_astree(constant,0,0,0,""), (yyvsp[(1) - (1)])); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2149 "yyparse.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 173 "parser.y"


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}



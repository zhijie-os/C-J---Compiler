/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "parser.h"

#line 76 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    NUMBER = 258,
    STRING = 259,
    TRUE = 260,
    FALSE = 261,
    BOOLEAN = 262,
    INT = 263,
    ID = 264,
    VOID = 265,
    BREAK = 266,
    RETURN = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    LE = 271,
    GE = 272,
    NE = 273,
    EQ = 274,
    AND = 275,
    OR = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef struct ast* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

#define YYUNDEFTOK  2
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,     2,     2,    32,     2,     2,
      23,    24,    30,    33,    25,    28,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
      34,    36,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    16,    16,    18,    19,    22,    23,    24,    25,    28,
      29,    32,    33,    36,    37,    38,    41,    44,    47,    50,
      51,    54,    55,    58,    59,    62,    65,    68,    71,    72,
      75,    76,    79,    80,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    97,    98,   101,   102,   103,   106,   107,
     110,   111,   114,   115,   118,   119,   120,   123,   124,   125,
     126,   129,   130,   131,   134,   135,   136,   137,   138,   141,
     142,   143,   146,   147,   150,   151,   156,   157,   160,   163
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STRING", "TRUE", "FALSE",
  "BOOLEAN", "INT", "ID", "VOID", "BREAK", "RETURN", "IF", "ELSE", "WHILE",
  "LE", "GE", "NE", "EQ", "AND", "OR", "';'", "'('", "')'", "','", "'{'",
  "'}'", "'-'", "'!'", "'*'", "'/'", "'%'", "'+'", "'<'", "'>'", "'='",
  "$accept", "dummy_start", "start", "literal", "type",
  "globaldeclarations", "globaldeclaration", "variabledeclaration",
  "identifier", "functiondeclaration", "functionheader",
  "functiondeclarator", "formalparameterlist", "formalparameter",
  "mainfunctiondeclaration", "mainfunctiondeclarator", "block",
  "blockstatements", "blockstatement", "statement", "statementexpression",
  "primary", "argumentlist", "functioninvocation", "postfixexpression",
  "unaryexpression", "multiplicativeexpression", "additiveexpression",
  "relationalexpression", "equalityexpression", "conditionalandexpression",
  "conditionalorexpression", "assignmentexpression", "assignment",
  "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    59,    40,    41,    44,   123,   125,    45,    33,
      42,    47,    37,    43,    60,    62,    61
};
# endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      77,   -91,   -91,   -91,    18,    41,   -91,    18,    77,   -91,
     -91,     9,   -91,    33,   -91,    33,    38,   -91,   -91,   -11,
     -91,   -91,    44,    45,   -91,   -91,    13,   -91,   -91,    53,
      60,    47,    67,   -91,   -91,    18,   -91,   -10,   -91,   120,
     -91,   -91,    78,   -91,   -91,   -91,    18,    20,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   116,   116,   116,   -91,   -10,
     -91,   -91,   -91,   -91,    48,   -19,     8,    32,    87,    94,
     -91,   -91,    96,   116,   116,   112,    88,   116,   -91,   -91,
     -91,   -91,   -91,    91,    85,   113,   -91,   -91,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   -91,   114,   117,   -91,    71,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,    48,    48,   -19,   -19,   -19,   -19,     8,
       8,    32,    87,   139,   139,   -91,   116,   123,   -91,   -91,
     139,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     9,    10,    17,     0,     0,     2,     0,     4,    11,
      13,     0,    14,     0,    15,     0,     0,    20,     1,     0,
      19,    12,     0,     0,    18,    26,     0,    16,    27,     0,
       0,     0,     0,    35,    29,     0,    32,     0,    34,     0,
      30,    33,     0,    44,    43,    22,     0,     0,    23,    37,
       5,     6,     7,     8,    39,     0,     0,     0,    45,    53,
      52,    47,    56,    57,    61,    64,    69,    72,    74,    76,
      79,    77,     0,     0,     0,     0,     0,     0,    28,    31,
      36,    25,    21,     0,     0,    53,    54,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,    51,     0,    48,    78,    24,    46,
      58,    59,    60,    63,    62,    67,    68,    65,    66,    71,
      70,    73,    75,     0,     0,    50,     0,    40,    42,    49,
       0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -21,   -91,   132,   -17,     0,   -91,
     -91,   136,   -91,    66,   -91,   -91,    23,   -91,   121,   -90,
     -91,   -91,   -91,   -22,   -91,   -41,    14,    62,    16,    54,
      59,   -91,    86,   -20,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,    58,     7,     8,     9,    10,    85,    12,
      13,    17,    47,    48,    14,    15,    38,    39,    40,    41,
      42,    60,   105,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    43,    35,    44,    16,    46,    36,    19,    11,    91,
      84,    27,    26,    76,    92,    86,    87,    43,    35,    44,
       1,     2,    36,    37,    93,    94,    77,     3,   102,   103,
      59,   106,    22,   127,   128,    75,    24,    45,    25,    37,
     131,    18,    95,    96,    82,    83,    81,   110,   111,   112,
      97,    98,     1,     2,     3,    59,    29,    30,    31,    23,
      32,    26,    46,    50,    51,    52,    53,    33,    28,     3,
      73,    23,    34,    59,    59,    49,    59,    59,    88,    89,
      90,   129,    54,    55,     1,     2,     3,     4,    56,    57,
      74,    50,    51,    52,    53,   125,   126,     3,     1,     2,
      80,    43,    43,    44,    44,   113,   114,    99,    43,   109,
      44,    55,   104,   119,   120,   100,    56,    57,   101,    50,
      51,    52,    53,    37,    37,     3,    59,     1,     2,     3,
      37,    29,    30,    31,    27,    32,    76,   130,   123,    55,
      21,   124,    33,    20,    56,    57,    23,    78,     3,   108,
      29,    30,    31,   121,    32,   115,   116,   117,   118,   122,
      79,    33,     0,   107,     0,    23
};

static const yytype_int16 yycheck[] =
{
       0,    23,    23,    23,     4,    26,    23,     7,     8,    28,
      55,    22,    23,    23,    33,    56,    57,    39,    39,    39,
       7,     8,    39,    23,    16,    17,    36,     9,    73,    74,
      30,    76,    23,   123,   124,    35,    13,    24,    15,    39,
     130,     0,    34,    35,    24,    25,    46,    88,    89,    90,
      18,    19,     7,     8,     9,    55,    11,    12,    13,    26,
      15,    23,    83,     3,     4,     5,     6,    22,    24,     9,
      23,    26,    27,    73,    74,    22,    76,    77,    30,    31,
      32,   126,    22,    23,     7,     8,     9,    10,    28,    29,
      23,     3,     4,     5,     6,    24,    25,     9,     7,     8,
      22,   123,   124,   123,   124,    91,    92,    20,   130,    24,
     130,    23,    24,    97,    98,    21,    28,    29,    22,     3,
       4,     5,     6,   123,   124,     9,   126,     7,     8,     9,
     130,    11,    12,    13,    22,    15,    23,    14,    24,    23,
       8,    24,    22,     7,    28,    29,    26,    27,     9,    83,
      11,    12,    13,    99,    15,    93,    94,    95,    96,   100,
      39,    22,    -1,    77,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    38,    39,    41,    42,    43,
      44,    45,    46,    47,    51,    52,    45,    48,     0,    45,
      48,    43,    23,    26,    53,    53,    23,    22,    24,    11,
      12,    13,    15,    22,    27,    41,    44,    45,    53,    54,
      55,    56,    57,    60,    70,    24,    41,    49,    50,    22,
       3,     4,     5,     6,    22,    23,    28,    29,    40,    45,
      58,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    23,    23,    45,    23,    36,    27,    55,
      22,    45,    24,    25,    71,    45,    62,    62,    30,    31,
      32,    28,    33,    16,    17,    34,    35,    18,    19,    20,
      21,    22,    71,    71,    24,    59,    71,    69,    50,    24,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    65,
      65,    66,    67,    24,    24,    24,    25,    56,    56,    71,
      14,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    43,    43,    43,    44,    45,    46,    47,
      47,    48,    48,    49,    49,    50,    51,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    65,    65,    65,    65,    65,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     3,     1,     2,     2,
       2,     4,     3,     1,     3,     2,     2,     3,     3,     2,
       1,     2,     1,     1,     1,     1,     2,     2,     3,     2,
       5,     7,     5,     1,     1,     1,     3,     1,     1,     3,
       4,     3,     1,     1,     2,     2,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 16 "parser.y"
                                        {print_tree(yyvsp[0],0);}
#line 1423 "parser.tab.c"
    break;

  case 4:
#line 19 "parser.y"
                                        {yyval=new_ast("PROGRAM:",1,yyvsp[0]);}
#line 1429 "parser.tab.c"
    break;

  case 5:
#line 22 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1435 "parser.tab.c"
    break;

  case 6:
#line 23 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1441 "parser.tab.c"
    break;

  case 7:
#line 24 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1447 "parser.tab.c"
    break;

  case 8:
#line 25 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1453 "parser.tab.c"
    break;

  case 9:
#line 28 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1459 "parser.tab.c"
    break;

  case 10:
#line 29 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1465 "parser.tab.c"
    break;

  case 11:
#line 32 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1471 "parser.tab.c"
    break;

  case 12:
#line 33 "parser.y"
                                                                        {yyval=new_ast("GLOBALDECLARATIONS:",2,yyvsp[-1], yyvsp[0]);}
#line 1477 "parser.tab.c"
    break;

  case 13:
#line 36 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1483 "parser.tab.c"
    break;

  case 14:
#line 37 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1489 "parser.tab.c"
    break;

  case 15:
#line 38 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1495 "parser.tab.c"
    break;

  case 16:
#line 41 "parser.y"
                                                                        {yyval=new_ast("VARIABLEDECLARATION:", 2,yyvsp[-2],yyvsp[-1]);}
#line 1501 "parser.tab.c"
    break;

  case 17:
#line 44 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1507 "parser.tab.c"
    break;

  case 18:
#line 47 "parser.y"
                                                                        {yyval=new_ast("FUNCTIONDECLARATION:",2,yyvsp[-1],yyvsp[0]);}
#line 1513 "parser.tab.c"
    break;

  case 19:
#line 50 "parser.y"
                                                                        {yyval=new_ast("FUNCTIONHEADER:", 2, yyvsp[-1], yyvsp[0]);}
#line 1519 "parser.tab.c"
    break;

  case 20:
#line 51 "parser.y"
                                                                        {yyval=new_ast("FUNCTIONHEADER:", 2, yyvsp[-1], yyvsp[0]);}
#line 1525 "parser.tab.c"
    break;

  case 21:
#line 54 "parser.y"
                                                                        {yyval=new_ast("FUNCTIONDECLARATOR:", 2, yyvsp[-3],yyvsp[-1]);}
#line 1531 "parser.tab.c"
    break;

  case 22:
#line 55 "parser.y"
                                                                        {yyval=yyvsp[-2];}
#line 1537 "parser.tab.c"
    break;

  case 23:
#line 58 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1543 "parser.tab.c"
    break;

  case 24:
#line 59 "parser.y"
                                                                        {yyval=new_ast("FORMALPARAMETERLIST:", 2, yyvsp[-2],yyvsp[0]);}
#line 1549 "parser.tab.c"
    break;

  case 25:
#line 62 "parser.y"
                                                                        {yyval=new_ast("FORMALPARAMETER:", 2, yyvsp[-1], yyvsp[0]);}
#line 1555 "parser.tab.c"
    break;

  case 26:
#line 65 "parser.y"
                                                                        {yyval=new_ast("MAINFUNCTIONDECLARATION:", 2, yyvsp[-1], yyvsp[0]);}
#line 1561 "parser.tab.c"
    break;

  case 27:
#line 68 "parser.y"
                                                                        {yyval=yyvsp[-2];}
#line 1567 "parser.tab.c"
    break;

  case 28:
#line 71 "parser.y"
                                                                        {yyval=new_ast("BLOCK:",1,yyvsp[-1]);}
#line 1573 "parser.tab.c"
    break;

  case 29:
#line 72 "parser.y"
                                                                        {yyval=new_ast("BLOCK:",0);}
#line 1579 "parser.tab.c"
    break;

  case 30:
#line 75 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1585 "parser.tab.c"
    break;

  case 31:
#line 76 "parser.y"
                                                                        {yyval=new_ast("BLOCKSTATEMENTS:", 2, yyvsp[-1], yyvsp[0]);}
#line 1591 "parser.tab.c"
    break;

  case 32:
#line 79 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1597 "parser.tab.c"
    break;

  case 33:
#line 80 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1603 "parser.tab.c"
    break;

  case 34:
#line 83 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1609 "parser.tab.c"
    break;

  case 35:
#line 84 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1615 "parser.tab.c"
    break;

  case 36:
#line 85 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1621 "parser.tab.c"
    break;

  case 37:
#line 86 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1627 "parser.tab.c"
    break;

  case 38:
#line 87 "parser.y"
                                                                            {yyval=new_ast("statement", 2, yyvsp[-2], yyvsp[-1]);}
#line 1633 "parser.tab.c"
    break;

  case 39:
#line 88 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1639 "parser.tab.c"
    break;

  case 40:
#line 89 "parser.y"
                                                                            {yyval=new_ast("if", 2, yyvsp[-2], yyvsp[0]);}
#line 1645 "parser.tab.c"
    break;

  case 41:
#line 90 "parser.y"
                                                                            {yyval=new_ast("ifElse", 3, yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1651 "parser.tab.c"
    break;

  case 42:
#line 91 "parser.y"
                                                                            {yyval=new_ast("while", 2, yyvsp[-2], yyvsp[0]); }
#line 1657 "parser.tab.c"
    break;

  case 43:
#line 97 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1663 "parser.tab.c"
    break;

  case 44:
#line 98 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1669 "parser.tab.c"
    break;

  case 45:
#line 101 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1675 "parser.tab.c"
    break;

  case 46:
#line 102 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1681 "parser.tab.c"
    break;

  case 47:
#line 103 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1687 "parser.tab.c"
    break;

  case 48:
#line 106 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1693 "parser.tab.c"
    break;

  case 49:
#line 107 "parser.y"
                                                                            {yyval=new_ast("ARGUMENTLIST:", 2, yyvsp[-2], yyvsp[0]);}
#line 1699 "parser.tab.c"
    break;

  case 50:
#line 110 "parser.y"
                                                                            {yyval=new_ast("FUNCTIONINVOCATION:", 2, yyvsp[-3], yyvsp[-1]);}
#line 1705 "parser.tab.c"
    break;

  case 51:
#line 111 "parser.y"
                                                                            {yyval=yyvsp[-2];}
#line 1711 "parser.tab.c"
    break;

  case 52:
#line 114 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1717 "parser.tab.c"
    break;

  case 53:
#line 115 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1723 "parser.tab.c"
    break;

  case 54:
#line 118 "parser.y"
                                                                            {yyval=new_ast("UNARYEXPRESSION", 2, yyvsp[-1], yyvsp[0]);}
#line 1729 "parser.tab.c"
    break;

  case 55:
#line 119 "parser.y"
                                                                            {yyval=new_ast("UNARYEXPRESSION", 2, yyvsp[-1], yyvsp[0]);}
#line 1735 "parser.tab.c"
    break;

  case 56:
#line 120 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1741 "parser.tab.c"
    break;

  case 57:
#line 123 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1747 "parser.tab.c"
    break;

  case 58:
#line 124 "parser.y"
                                                                            {yyval=new_ast("MULTIPLICATIVEEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1753 "parser.tab.c"
    break;

  case 59:
#line 125 "parser.y"
                                                                            {yyval=new_ast("MULTIPLICATIVEEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1759 "parser.tab.c"
    break;

  case 60:
#line 126 "parser.y"
                                                                            {yyval=new_ast("MULTIPLICATIVEEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1765 "parser.tab.c"
    break;

  case 61:
#line 129 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1771 "parser.tab.c"
    break;

  case 62:
#line 130 "parser.y"
                                                                            {yyval=new_ast("ADDITIVEEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1777 "parser.tab.c"
    break;

  case 63:
#line 131 "parser.y"
                                                                            {yyval=new_ast("ADDITIVEEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1783 "parser.tab.c"
    break;

  case 64:
#line 134 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1789 "parser.tab.c"
    break;

  case 65:
#line 135 "parser.y"
                                                                            {yyval=new_ast("RELATIONALEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1795 "parser.tab.c"
    break;

  case 66:
#line 136 "parser.y"
                                                                            {yyval=new_ast("RELATIONALEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1801 "parser.tab.c"
    break;

  case 67:
#line 137 "parser.y"
                                                                            {yyval=new_ast("RELATIONALEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1807 "parser.tab.c"
    break;

  case 68:
#line 138 "parser.y"
                                                                            {yyval=new_ast("RELATIONALEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1813 "parser.tab.c"
    break;

  case 69:
#line 141 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1819 "parser.tab.c"
    break;

  case 70:
#line 142 "parser.y"
                                                                            {yyval=new_ast("EQUALITYEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1825 "parser.tab.c"
    break;

  case 71:
#line 143 "parser.y"
                                                                            {yyval=new_ast("EQUALITYEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1831 "parser.tab.c"
    break;

  case 72:
#line 146 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1837 "parser.tab.c"
    break;

  case 73:
#line 147 "parser.y"
                                                                            {yyval=new_ast("CONDITIONALANDEXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1843 "parser.tab.c"
    break;

  case 74:
#line 150 "parser.y"
                                                                                {yyval=yyvsp[0];}
#line 1849 "parser.tab.c"
    break;

  case 75:
#line 151 "parser.y"
                                                                                {yyval=new_ast("CONDITIONALOREXPRESSION:", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1855 "parser.tab.c"
    break;

  case 76:
#line 156 "parser.y"
                                                            {yyval=yyvsp[0];}
#line 1861 "parser.tab.c"
    break;

  case 77:
#line 157 "parser.y"
                                                            {yyval=yyvsp[0];}
#line 1867 "parser.tab.c"
    break;

  case 78:
#line 160 "parser.y"
                                                                {yyval=new_ast("ASSIGNMENT:", 3, yyvsp[-2], yyvsp[-1],  yyvsp[0]);}
#line 1873 "parser.tab.c"
    break;

  case 79:
#line 163 "parser.y"
                                                            {yyval=yyvsp[0];}
#line 1879 "parser.tab.c"
    break;


#line 1883 "parser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 167 "parser.y"

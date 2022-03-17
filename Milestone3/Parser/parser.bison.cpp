/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
    #include "AST.h"
    #include "STab.h"


#line 80 "parser.bison.cpp"

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

#include "parser.bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_STRING_Y = 4,                   /* STRING_Y  */
  YYSYMBOL_TRUE = 5,                       /* TRUE  */
  YYSYMBOL_FALSE = 6,                      /* FALSE  */
  YYSYMBOL_BOOLEAN = 7,                    /* BOOLEAN  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_start = 38,                     /* start  */
  YYSYMBOL_literal = 39,                   /* literal  */
  YYSYMBOL_type = 40,                      /* type  */
  YYSYMBOL_globaldeclarations = 41,        /* globaldeclarations  */
  YYSYMBOL_globaldeclaration = 42,         /* globaldeclaration  */
  YYSYMBOL_variabledeclaration = 43,       /* variabledeclaration  */
  YYSYMBOL_identifier = 44,                /* identifier  */
  YYSYMBOL_functiondeclaration = 45,       /* functiondeclaration  */
  YYSYMBOL_functionheader = 46,            /* functionheader  */
  YYSYMBOL_functiondeclarator = 47,        /* functiondeclarator  */
  YYSYMBOL_formalparameterlist = 48,       /* formalparameterlist  */
  YYSYMBOL_formalparameter = 49,           /* formalparameter  */
  YYSYMBOL_mainfunctiondeclaration = 50,   /* mainfunctiondeclaration  */
  YYSYMBOL_mainfunctiondeclarator = 51,    /* mainfunctiondeclarator  */
  YYSYMBOL_block = 52,                     /* block  */
  YYSYMBOL_blockstatements = 53,           /* blockstatements  */
  YYSYMBOL_blockstatement = 54,            /* blockstatement  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_statementexpression = 56,       /* statementexpression  */
  YYSYMBOL_primary = 57,                   /* primary  */
  YYSYMBOL_argumentlist = 58,              /* argumentlist  */
  YYSYMBOL_functioninvocation = 59,        /* functioninvocation  */
  YYSYMBOL_postfixexpression = 60,         /* postfixexpression  */
  YYSYMBOL_unaryexpression = 61,           /* unaryexpression  */
  YYSYMBOL_multiplicativeexpression = 62,  /* multiplicativeexpression  */
  YYSYMBOL_additiveexpression = 63,        /* additiveexpression  */
  YYSYMBOL_relationalexpression = 64,      /* relationalexpression  */
  YYSYMBOL_equalityexpression = 65,        /* equalityexpression  */
  YYSYMBOL_conditionalandexpression = 66,  /* conditionalandexpression  */
  YYSYMBOL_conditionalorexpression = 67,   /* conditionalorexpression  */
  YYSYMBOL_assignmentexpression = 68,      /* assignmentexpression  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_expression = 70                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,    24,    24,    25,    28,    29,    30,    31,    34,    35,
      38,    39,    42,    43,    44,    47,    50,    53,    56,    57,
      60,    61,    64,    65,    68,    71,    74,    77,    78,    81,
      82,    85,    86,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   103,   104,   107,   108,   109,   112,   113,   116,
     117,   120,   121,   124,   125,   126,   129,   130,   131,   132,
     135,   136,   137,   140,   141,   142,   143,   144,   147,   148,
     149,   152,   153,   156,   157,   162,   163,   166,   169
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "STRING_Y",
  "TRUE", "FALSE", "BOOLEAN", "INT", "ID", "VOID", "BREAK", "RETURN", "IF",
  "ELSE", "WHILE", "LE", "GE", "NE", "EQ", "AND", "OR", "';'", "'('",
  "')'", "','", "'{'", "'}'", "'-'", "'!'", "'*'", "'/'", "'%'", "'+'",
  "'<'", "'>'", "'='", "$accept", "start", "literal", "type",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

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
      42,   -91,   -91,   -91,    -1,    31,    -1,    42,   -91,   -91,
     -10,   -91,    14,   -91,    14,    30,   -91,   -91,    47,   -91,
     -91,    39,   119,   -91,   -91,    13,   -91,   -91,    52,    55,
      59,    66,   -91,   -91,    -1,   -91,   -11,   -91,   140,   -91,
     -91,    83,   -91,   -91,   -91,    -1,    11,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,    89,    89,    89,   -91,   -11,   -91,
     -91,   -91,   -91,    25,   -17,     7,    69,    91,    88,   -91,
     -91,    97,    89,    89,    98,    62,    89,   -91,   -91,   -91,
     -91,   -91,    36,   100,   110,   -91,   -91,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
     -91,   111,   112,   -91,    72,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,    25,    25,   -17,   -17,   -17,   -17,     7,     7,
      69,    91,   148,   148,   -91,    89,   107,   -91,   -91,   148,
     -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     8,     9,    16,     0,     0,     0,     3,    10,    12,
       0,    13,     0,    14,     0,     0,    19,     1,     0,    18,
      11,     0,     0,    17,    25,     0,    15,    26,     0,     0,
       0,     0,    34,    28,     0,    31,     0,    33,     0,    29,
      32,     0,    43,    42,    21,     0,     0,    22,    36,     4,
       5,     6,     7,    38,     0,     0,     0,    44,    52,    51,
      46,    55,    56,    60,    63,    68,    71,    73,    75,    78,
      76,     0,     0,     0,     0,     0,     0,    27,    30,    35,
      24,    20,     0,     0,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,    50,     0,    47,    77,    23,    45,    57,
      58,    59,    62,    61,    66,    67,    64,    65,    70,    69,
      72,    74,     0,     0,    49,     0,    39,    41,    48,     0,
      40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -20,   -91,   130,   -12,     0,   -91,   -91,
     132,   -91,    57,   -91,   -91,    67,   -91,   102,   -90,   -91,
     -91,   -91,   -21,   -91,   -41,     9,    21,    10,    44,    45,
     -91,    74,   -19,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,    57,     6,     7,     8,     9,    84,    11,    12,
      16,    46,    47,    13,    14,    37,    38,    39,    40,    41,
      59,   104,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    42,    34,    43,    15,    45,    18,    10,     3,    83,
      35,    90,    75,    21,    85,    86,    91,    42,    34,    43,
       1,     2,    36,    92,    93,    76,    35,   101,   102,    58,
     105,    17,   126,   127,    74,    81,    82,    44,    36,   130,
      22,    94,    95,     1,     2,    80,   109,   110,   111,     1,
       2,     3,     4,    25,    58,    87,    88,    89,    49,    50,
      51,    52,    45,    27,     3,    49,    50,    51,    52,    26,
      25,     3,    58,    58,    48,    58,    58,    53,    54,    23,
     128,    24,    72,    55,    56,    54,   103,    96,    97,    73,
      55,    56,    49,    50,    51,    52,   124,   125,     3,   112,
     113,    42,    42,    43,    43,    79,   118,   119,    42,    99,
      43,    98,    54,   114,   115,   116,   117,    55,    56,   100,
      26,   129,    36,    36,   108,    58,     1,     2,     3,    36,
      28,    29,    30,    75,    31,   122,   123,    20,    19,   107,
      78,    32,   120,     0,   121,    22,    33,     1,     2,     3,
     106,    28,    29,    30,     0,    31,     0,     3,     0,    28,
      29,    30,    32,    31,     0,     0,    22,    77,     0,     0,
      32,     0,     0,     0,    22
};

static const yytype_int16 yycheck[] =
{
       0,    22,    22,    22,     4,    25,     6,     7,     9,    54,
      22,    28,    23,    23,    55,    56,    33,    38,    38,    38,
       7,     8,    22,    16,    17,    36,    38,    72,    73,    29,
      75,     0,   122,   123,    34,    24,    25,    24,    38,   129,
      26,    34,    35,     7,     8,    45,    87,    88,    89,     7,
       8,     9,    10,    23,    54,    30,    31,    32,     3,     4,
       5,     6,    82,    24,     9,     3,     4,     5,     6,    22,
      23,     9,    72,    73,    22,    75,    76,    22,    23,    12,
     125,    14,    23,    28,    29,    23,    24,    18,    19,    23,
      28,    29,     3,     4,     5,     6,    24,    25,     9,    90,
      91,   122,   123,   122,   123,    22,    96,    97,   129,    21,
     129,    20,    23,    92,    93,    94,    95,    28,    29,    22,
      22,    14,   122,   123,    24,   125,     7,     8,     9,   129,
      11,    12,    13,    23,    15,    24,    24,     7,     6,    82,
      38,    22,    98,    -1,    99,    26,    27,     7,     8,     9,
      76,    11,    12,    13,    -1,    15,    -1,     9,    -1,    11,
      12,    13,    22,    15,    -1,    -1,    26,    27,    -1,    -1,
      22,    -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    38,    40,    41,    42,    43,
      44,    45,    46,    50,    51,    44,    47,     0,    44,    47,
      42,    23,    26,    52,    52,    23,    22,    24,    11,    12,
      13,    15,    22,    27,    40,    43,    44,    52,    53,    54,
      55,    56,    59,    69,    24,    40,    48,    49,    22,     3,
       4,     5,     6,    22,    23,    28,    29,    39,    44,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    23,    23,    44,    23,    36,    27,    54,    22,
      44,    24,    25,    70,    44,    61,    61,    30,    31,    32,
      28,    33,    16,    17,    34,    35,    18,    19,    20,    21,
      22,    70,    70,    24,    58,    70,    68,    49,    24,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      65,    66,    24,    24,    24,    25,    55,    55,    70,    14,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    39,    39,    40,    40,
      41,    41,    42,    42,    42,    43,    44,    45,    46,    46,
      47,    47,    48,    48,    49,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     3,     1,     2,     2,     2,
       4,     3,     1,     3,     2,     2,     3,     3,     2,     1,
       2,     1,     1,     1,     1,     2,     2,     3,     2,     5,
       7,     5,     1,     1,     1,     3,     1,     1,     3,     4,
       3,     1,     1,     2,     2,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 3: /* start: globaldeclarations  */
#line 25 "parser.y"
                                        {yyval=yyvsp[0];CollectGlobal(yyval);dummy_break_point();BuildSymbolTable(yyval,""); TypeCheck(yyval,"");}
#line 1238 "parser.bison.cpp"
    break;

  case 4: /* literal: NUMBER  */
#line 28 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1244 "parser.bison.cpp"
    break;

  case 5: /* literal: STRING_Y  */
#line 29 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1250 "parser.bison.cpp"
    break;

  case 6: /* literal: TRUE  */
#line 30 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1256 "parser.bison.cpp"
    break;

  case 7: /* literal: FALSE  */
#line 31 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1262 "parser.bison.cpp"
    break;

  case 8: /* type: BOOLEAN  */
#line 34 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1268 "parser.bison.cpp"
    break;

  case 9: /* type: INT  */
#line 35 "parser.y"
                                        {yyval=yyvsp[0];}
#line 1274 "parser.bison.cpp"
    break;

  case 10: /* globaldeclarations: globaldeclaration  */
#line 38 "parser.y"
                                                                        {yyval=new AST(NodeType::PROGRAM, "PROGRAM",yyvsp[0]);}
#line 1280 "parser.bison.cpp"
    break;

  case 11: /* globaldeclarations: globaldeclarations globaldeclaration  */
#line 39 "parser.y"
                                                                        {yyvsp[-1]->AttachChildren(yyvsp[0]);yyval=yyvsp[-1];}
#line 1286 "parser.bison.cpp"
    break;

  case 12: /* globaldeclaration: variabledeclaration  */
#line 42 "parser.y"
                                                                        {yyvsp[0]->type=NodeType::GLOBAL_VAR_DEC;yyvsp[0]->symbol="GLOBAL_VAR_DEC";yyval=yyvsp[0];}
#line 1292 "parser.bison.cpp"
    break;

  case 13: /* globaldeclaration: functiondeclaration  */
#line 43 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1298 "parser.bison.cpp"
    break;

  case 14: /* globaldeclaration: mainfunctiondeclaration  */
#line 44 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1304 "parser.bison.cpp"
    break;

  case 15: /* variabledeclaration: type identifier ';'  */
#line 47 "parser.y"
                                                                        {yyval=new AST(NodeType::VAR_DEC,"VAR_DEC",yyvsp[-2],yyvsp[-1]);}
#line 1310 "parser.bison.cpp"
    break;

  case 16: /* identifier: ID  */
#line 50 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1316 "parser.bison.cpp"
    break;

  case 17: /* functiondeclaration: functionheader block  */
#line 53 "parser.y"
                                                                        {yyvsp[-1]->AttachChildren(yyvsp[0]);yyval=yyvsp[-1];}
#line 1322 "parser.bison.cpp"
    break;

  case 18: /* functionheader: type functiondeclarator  */
#line 56 "parser.y"
                                                                        {yyvsp[0]->children.insert(yyvsp[0]->children.begin(),yyvsp[-1]);yyval=yyvsp[0];}
#line 1328 "parser.bison.cpp"
    break;

  case 19: /* functionheader: VOID functiondeclarator  */
#line 57 "parser.y"
                                                                        {yyvsp[0]->children.insert(yyvsp[0]->children.begin(), new AST(NodeType::VOID,"VOID"));yyval=yyvsp[0];}
#line 1334 "parser.bison.cpp"
    break;

  case 20: /* functiondeclarator: identifier '(' formalparameterlist ')'  */
#line 60 "parser.y"
                                                                        {yyval=new AST(NodeType::FUNC_DEC, "FUNC_DEC",  yyvsp[-3], yyvsp[-1]);}
#line 1340 "parser.bison.cpp"
    break;

  case 21: /* functiondeclarator: identifier '(' ')'  */
#line 61 "parser.y"
                                                                        {yyval=new AST(NodeType::FUNC_DEC, "FUNC_DEC",  yyvsp[-2], new AST(NodeType::FORMALS,"FORMALS"));}
#line 1346 "parser.bison.cpp"
    break;

  case 22: /* formalparameterlist: formalparameter  */
#line 64 "parser.y"
                                                                        {yyval=new AST(NodeType::FORMALS,"FORMALS",yyvsp[0]);}
#line 1352 "parser.bison.cpp"
    break;

  case 23: /* formalparameterlist: formalparameterlist ',' formalparameter  */
#line 65 "parser.y"
                                                                        {yyvsp[-2]->AttachChildren(yyvsp[0]);yyval=yyvsp[-2];}
#line 1358 "parser.bison.cpp"
    break;

  case 24: /* formalparameter: type identifier  */
#line 68 "parser.y"
                                                                        {yyval=new AST(NodeType::FORMAL, "FORMAL",yyvsp[-1], yyvsp[0]);}
#line 1364 "parser.bison.cpp"
    break;

  case 25: /* mainfunctiondeclaration: mainfunctiondeclarator block  */
#line 71 "parser.y"
                                                                        {yyval=new AST(NodeType::MAIN_DEC, "MAIN_DEC", new AST(NodeType::VOID, "VOID"),yyvsp[-1],new AST(NodeType::FORMALS,"FORMALS"),yyvsp[0]);}
#line 1370 "parser.bison.cpp"
    break;

  case 26: /* mainfunctiondeclarator: identifier '(' ')'  */
#line 74 "parser.y"
                                                                        {yyval=yyvsp[-2];}
#line 1376 "parser.bison.cpp"
    break;

  case 27: /* block: '{' blockstatements '}'  */
#line 77 "parser.y"
                                                                        {yyval=yyvsp[-1];}
#line 1382 "parser.bison.cpp"
    break;

  case 28: /* block: '{' '}'  */
#line 78 "parser.y"
                                                                        {yyval=new AST(NodeType::BLOCK,"BLOCK");}
#line 1388 "parser.bison.cpp"
    break;

  case 29: /* blockstatements: blockstatement  */
#line 81 "parser.y"
                                                                        {yyval=new AST(NodeType::BLOCK, "BLOCK",yyvsp[0]);}
#line 1394 "parser.bison.cpp"
    break;

  case 30: /* blockstatements: blockstatements blockstatement  */
#line 82 "parser.y"
                                                                        {yyvsp[-1]->AttachChildren(yyvsp[0]);yyval=yyvsp[-1];}
#line 1400 "parser.bison.cpp"
    break;

  case 31: /* blockstatement: variabledeclaration  */
#line 85 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1406 "parser.bison.cpp"
    break;

  case 32: /* blockstatement: statement  */
#line 86 "parser.y"
                                                                        {yyval=yyvsp[0];}
#line 1412 "parser.bison.cpp"
    break;

  case 33: /* statement: block  */
#line 89 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1418 "parser.bison.cpp"
    break;

  case 34: /* statement: ';'  */
#line 90 "parser.y"
                                                                            {yyval=new AST(NodeType::NULL_STMT,"nullStmt");}
#line 1424 "parser.bison.cpp"
    break;

  case 35: /* statement: statementexpression ';'  */
#line 91 "parser.y"
                                                                            {yyval=new AST(NodeType::STMT_EXPR,"STMTEXPR",yyvsp[-1]);}
#line 1430 "parser.bison.cpp"
    break;

  case 36: /* statement: BREAK ';'  */
#line 92 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1436 "parser.bison.cpp"
    break;

  case 37: /* statement: RETURN expression ';'  */
#line 93 "parser.y"
                                                                            {yyvsp[-2]->AttachChildren(yyvsp[-1]); yyval=yyvsp[-2];}
#line 1442 "parser.bison.cpp"
    break;

  case 38: /* statement: RETURN ';'  */
#line 94 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1448 "parser.bison.cpp"
    break;

  case 39: /* statement: IF '(' expression ')' statement  */
#line 95 "parser.y"
                                                                            {yyval=new AST(NodeType::IF, "IF",new ATR(yyvsp[-2]->line), yyvsp[-2], yyvsp[0]);}
#line 1454 "parser.bison.cpp"
    break;

  case 40: /* statement: IF '(' expression ')' statement ELSE statement  */
#line 96 "parser.y"
                                                                            {yyval=new AST(NodeType::IF_ELSE,"IF_ELSE",new ATR(yyvsp[-4]->line),yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 1460 "parser.bison.cpp"
    break;

  case 41: /* statement: WHILE '(' expression ')' statement  */
#line 97 "parser.y"
                                                                            {yyval=new AST(NodeType::WHILE,"WHILE", yyvsp[-2], yyvsp[0]); }
#line 1466 "parser.bison.cpp"
    break;

  case 42: /* statementexpression: assignment  */
#line 103 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1472 "parser.bison.cpp"
    break;

  case 43: /* statementexpression: functioninvocation  */
#line 104 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1478 "parser.bison.cpp"
    break;

  case 44: /* primary: literal  */
#line 107 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1484 "parser.bison.cpp"
    break;

  case 45: /* primary: '(' expression ')'  */
#line 108 "parser.y"
                                                                            {yyval=yyvsp[-1];}
#line 1490 "parser.bison.cpp"
    break;

  case 46: /* primary: functioninvocation  */
#line 109 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1496 "parser.bison.cpp"
    break;

  case 47: /* argumentlist: expression  */
#line 112 "parser.y"
                                                                            {yyval=new AST(NodeType::ACTUALS,"ACTUALS",yyvsp[0]);}
#line 1502 "parser.bison.cpp"
    break;

  case 48: /* argumentlist: argumentlist ',' expression  */
#line 113 "parser.y"
                                                                            {yyvsp[-2]->AttachChildren(yyvsp[0]);yyval=yyvsp[-2];}
#line 1508 "parser.bison.cpp"
    break;

  case 49: /* functioninvocation: identifier '(' argumentlist ')'  */
#line 116 "parser.y"
                                                                            {yyval=new AST(NodeType::FUNC_CALL, "FUNC_CALL",yyvsp[-3], yyvsp[-1]);;}
#line 1514 "parser.bison.cpp"
    break;

  case 50: /* functioninvocation: identifier '(' ')'  */
#line 117 "parser.y"
                                                                            {yyval=new AST(NodeType::FUNC_CALL, "FUNC_CALL",yyvsp[-2], new AST(NodeType::ACTUALS,"ACTUALS"));}
#line 1520 "parser.bison.cpp"
    break;

  case 51: /* postfixexpression: primary  */
#line 120 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1526 "parser.bison.cpp"
    break;

  case 52: /* postfixexpression: identifier  */
#line 121 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1532 "parser.bison.cpp"
    break;

  case 53: /* unaryexpression: '-' unaryexpression  */
#line 124 "parser.y"
                                                                            {yyvsp[-1]->type=NodeType::UN_ARITHMETIC;yyvsp[-1]->AttachChildren(yyvsp[0]);yyval=yyvsp[-1];}
#line 1538 "parser.bison.cpp"
    break;

  case 54: /* unaryexpression: '!' unaryexpression  */
#line 125 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[0]);yyval=yyvsp[-1];}
#line 1544 "parser.bison.cpp"
    break;

  case 55: /* unaryexpression: postfixexpression  */
#line 126 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1550 "parser.bison.cpp"
    break;

  case 56: /* multiplicativeexpression: unaryexpression  */
#line 129 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1556 "parser.bison.cpp"
    break;

  case 57: /* multiplicativeexpression: multiplicativeexpression '*' unaryexpression  */
#line 130 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1562 "parser.bison.cpp"
    break;

  case 58: /* multiplicativeexpression: multiplicativeexpression '/' unaryexpression  */
#line 131 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1568 "parser.bison.cpp"
    break;

  case 59: /* multiplicativeexpression: multiplicativeexpression '%' unaryexpression  */
#line 132 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1574 "parser.bison.cpp"
    break;

  case 60: /* additiveexpression: multiplicativeexpression  */
#line 135 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1580 "parser.bison.cpp"
    break;

  case 61: /* additiveexpression: additiveexpression '+' multiplicativeexpression  */
#line 136 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1586 "parser.bison.cpp"
    break;

  case 62: /* additiveexpression: additiveexpression '-' multiplicativeexpression  */
#line 137 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1592 "parser.bison.cpp"
    break;

  case 63: /* relationalexpression: additiveexpression  */
#line 140 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1598 "parser.bison.cpp"
    break;

  case 64: /* relationalexpression: relationalexpression '<' additiveexpression  */
#line 141 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1604 "parser.bison.cpp"
    break;

  case 65: /* relationalexpression: relationalexpression '>' additiveexpression  */
#line 142 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1610 "parser.bison.cpp"
    break;

  case 66: /* relationalexpression: relationalexpression LE additiveexpression  */
#line 143 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1616 "parser.bison.cpp"
    break;

  case 67: /* relationalexpression: relationalexpression GE additiveexpression  */
#line 144 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1622 "parser.bison.cpp"
    break;

  case 68: /* equalityexpression: relationalexpression  */
#line 147 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1628 "parser.bison.cpp"
    break;

  case 69: /* equalityexpression: equalityexpression EQ relationalexpression  */
#line 148 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1634 "parser.bison.cpp"
    break;

  case 70: /* equalityexpression: equalityexpression NE relationalexpression  */
#line 149 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1640 "parser.bison.cpp"
    break;

  case 71: /* conditionalandexpression: equalityexpression  */
#line 152 "parser.y"
                                                                            {yyval=yyvsp[0];}
#line 1646 "parser.bison.cpp"
    break;

  case 72: /* conditionalandexpression: conditionalandexpression AND equalityexpression  */
#line 153 "parser.y"
                                                                            {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1652 "parser.bison.cpp"
    break;

  case 73: /* conditionalorexpression: conditionalandexpression  */
#line 156 "parser.y"
                                                                                {yyval=yyvsp[0];}
#line 1658 "parser.bison.cpp"
    break;

  case 74: /* conditionalorexpression: conditionalorexpression OR conditionalandexpression  */
#line 157 "parser.y"
                                                                                {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1664 "parser.bison.cpp"
    break;

  case 75: /* assignmentexpression: conditionalorexpression  */
#line 162 "parser.y"
                                                            {yyval=yyvsp[0];}
#line 1670 "parser.bison.cpp"
    break;

  case 76: /* assignmentexpression: assignment  */
#line 163 "parser.y"
                                                            {yyval=yyvsp[0];}
#line 1676 "parser.bison.cpp"
    break;

  case 77: /* assignment: identifier '=' assignmentexpression  */
#line 166 "parser.y"
                                                                {yyvsp[-1]->AttachChildren(yyvsp[-2],yyvsp[0]);yyval=yyvsp[-1];}
#line 1682 "parser.bison.cpp"
    break;

  case 78: /* expression: assignmentexpression  */
#line 169 "parser.y"
                                                            {yyval=yyvsp[0];}
#line 1688 "parser.bison.cpp"
    break;


#line 1692 "parser.bison.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 173 "parser.y"



// define yyerror for bison
void yyerror(char const *s)
{
    // print out the token that cannot be shifted or reduced and its line number
    fprintf(stderr, "Syntax Error around:  %s, at or near %d", yytext, yylineno);
}

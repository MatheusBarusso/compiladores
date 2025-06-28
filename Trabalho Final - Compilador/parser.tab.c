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
#line 6 "parser.y"

#include <cstdio>
#include <cstdarg>
#include <map>
#include "parser.tab.h"

extern FILE *out;
extern std::string newTemp();
extern std::string newLabel();
extern std::string regOf(const std::string &);
extern void declareVar(const std::string &);
extern void declareArray(const std::string &, int);
extern void emit(const char *, ...);
extern std::string exprResult(const std::string &, int, const std::string &);
extern std::string condText(const std::string &);
extern FILE *yyin;
extern int yylex();
extern int yyparse();
int yyerror(const char *);

#line 92 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_READ = 9,                       /* READ  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_MAIN = 11,                      /* MAIN  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_TIMES = 14,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 15,                    /* DIVIDE  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_MOD = 21,                       /* MOD  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_NUMBER = 25,                    /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 26,                /* IDENTIFIER  */
  YYSYMBOL_STRING_TYPE = 27,               /* STRING_TYPE  */
  YYSYMBOL_STRING_LITERAL = 28,            /* STRING_LITERAL  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_external_decl = 42,             /* external_decl  */
  YYSYMBOL_block = 43,                     /* block  */
  YYSYMBOL_statement_list = 44,            /* statement_list  */
  YYSYMBOL_for_init = 45,                  /* for_init  */
  YYSYMBOL_for_update = 46,                /* for_update  */
  YYSYMBOL_argument_list = 47,             /* argument_list  */
  YYSYMBOL_expression_list = 48,           /* expression_list  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_matched_stmt = 50,              /* matched_stmt  */
  YYSYMBOL_unmatched_stmt = 51,            /* unmatched_stmt  */
  YYSYMBOL_expression = 52                 /* expression  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      29,     2,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    55,    59,    60,    61,    65,    68,    69,
      72,    73,    76,    77,    81,    82,    86,    87,    91,    92,
      96,    97,    98,    99,   107,   108,   112,   113,   114,   119,
     124,   133,   142,   151,   159,   162,   169,   175,   186,   187,
     188,   189,   190,   195,   200,   205,   210,   215,   220,   225,
     230,   235,   240,   245,   250,   255,   260
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "INT", "PRINT", "READ", "RETURN", "MAIN", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "ASSIGN", "LE", "GE", "EQ", "NE", "MOD", "AND", "OR",
  "NOT", "NUMBER", "IDENTIFIER", "STRING_TYPE", "STRING_LITERAL", "'<'",
  "'>'", "LOWER_THAN_ELSE", "'('", "')'", "'{'", "'}'", "','", "';'",
  "'['", "']'", "$accept", "program", "external_decl", "block",
  "statement_list", "for_init", "for_update", "argument_list",
  "expression_list", "statement", "matched_stmt", "unmatched_stmt",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -66,    54,   -66,   -13,    -8,     1,     0,     5,    26,   347,
      45,   -11,     3,   -66,   -66,   -66,   -66,   -66,   -66,   347,
     347,    52,    -6,   347,    53,   347,   -66,    44,   -66,   347,
     166,    50,   347,    89,   347,    -7,    66,   250,   272,    75,
      57,   -66,    70,   -29,   316,    65,   316,   347,   294,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   -66,    68,   187,   -20,   -18,   120,    71,   -66,
     -10,   -66,   -66,   102,    68,   347,   347,    64,    79,   347,
      82,   143,   -66,    67,    67,   330,   330,    13,    13,    13,
      13,   330,    81,   -66,    13,    13,   -66,   -66,   -66,   -66,
      86,   108,    88,   337,   -66,   122,   -66,   316,   208,    -3,
     -66,   316,   -66,   -66,   -66,   347,   -66,    93,   102,   105,
     110,   -66,   229,   -66,   -66,   129,   113,   347,   -66,   347,
      68,    20,   316,   316,   -66,   111,   347,   -66,   316
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     3,    20,     6,    18,    19,     0,
       0,    10,     0,     0,     0,     0,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,    14,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,    24,
       0,     7,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    43,    44,    45,    46,    50,    51,    52,
      53,    47,    54,    55,    48,    49,     4,    26,    27,     5,
       0,     0,     0,     0,    36,    18,    31,    11,     0,     0,
      33,    15,    34,    42,    29,     0,    25,     0,     0,    12,
       0,    22,     0,    30,    37,     0,     0,     0,    28,     0,
       0,     0,    16,    13,    32,     0,     0,    23,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   -62,   -66,   -66,   -66,   124,   -66,   -34,
     -65,    33,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    14,    15,    36,    40,   126,    66,   131,    16,
      17,    18,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      30,    96,    72,    99,    78,    32,    32,    79,   105,    68,
      37,    38,   106,   120,    13,   100,    46,    98,    79,    19,
      48,    33,   103,    64,    20,    67,    22,    34,    34,    35,
      69,    41,    42,    21,   121,    58,    59,    23,    81,   104,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   123,     2,   135,   136,     3,    24,     4,
       5,     6,     7,     8,     9,    10,   107,   108,   134,     3,
     111,     4,     5,     6,     7,     8,     9,    31,    39,    45,
      11,    12,    47,    63,    53,    54,    55,    56,    13,    58,
      59,    75,    70,    12,    76,    77,    60,    61,    80,   102,
      13,    71,    13,   109,    59,     3,   122,     4,     5,     6,
       7,     8,     9,    25,    26,    27,   110,    28,   132,   112,
     133,    29,    65,   114,   115,   116,   118,   138,    70,    12,
      98,   125,    49,    50,    51,    52,    13,    53,    54,    55,
      56,    57,    58,    59,   127,   129,   130,    43,   137,    60,
      61,   124,     0,     0,     0,    49,    50,    51,    52,   101,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,    60,    61,     0,     0,     0,     0,    49,    50,
      51,    52,   113,    53,    54,    55,    56,    57,    58,    59,
       0,     0,     0,     0,     0,    60,    61,     0,     0,    49,
      50,    51,    52,    62,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,    60,    61,     0,     0,
      49,    50,    51,    52,    97,    53,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,    60,    61,     0,
       0,    49,    50,    51,    52,   119,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,    60,    61,
       0,     0,    49,    50,    51,    52,   128,    53,    54,    55,
      56,    57,    58,    59,     0,     0,     0,     0,     0,    60,
      61,     0,     0,    73,    49,    50,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
       0,    60,    61,     0,     0,    74,    49,    50,    51,    52,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,    60,    61,     0,     0,    82,    49,    50,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    49,    50,     0,    60,    61,    53,    54,    55,
      56,     0,    58,    59,     0,     0,     0,     0,     0,    60,
      61,    25,    26,    27,     0,    28,     0,     0,     0,    29,
     117,    25,    26,    27,     0,    28,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
       9,    63,    36,    65,    33,    16,    16,    36,    73,    16,
      19,    20,    74,    16,    34,    33,    25,    37,    36,    32,
      29,    32,    32,    32,    32,    34,    26,    38,    38,    26,
      37,    37,    38,    32,    37,    22,    23,    32,    47,    73,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   118,     0,    35,    36,     3,    32,     5,
       6,     7,     8,     9,    10,    11,    75,    76,   130,     3,
      79,     5,     6,     7,     8,     9,    10,    32,    26,    26,
      26,    27,    38,    33,    17,    18,    19,    20,    34,    22,
      23,    16,    26,    27,    37,    25,    29,    30,    33,    28,
      34,    35,    34,    39,    23,     3,   115,     5,     6,     7,
       8,     9,    10,    24,    25,    26,    37,    28,   127,    37,
     129,    32,    33,    37,    16,    37,     4,   136,    26,    27,
      37,    26,    12,    13,    14,    15,    34,    17,    18,    19,
      20,    21,    22,    23,    34,    16,    33,    23,    37,    29,
      30,   118,    -1,    -1,    -1,    12,    13,    14,    15,    39,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    39,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    12,
      13,    14,    15,    37,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      12,    13,    14,    15,    37,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    12,    13,    14,    15,    37,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    12,    13,    14,    15,    37,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    33,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    12,    13,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    12,    13,    -1,    29,    30,    17,    18,    19,
      20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      30,    24,    25,    26,    -1,    28,    -1,    -1,    -1,    32,
      33,    24,    25,    26,    -1,    28,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    41,     0,     3,     5,     6,     7,     8,     9,    10,
      11,    26,    27,    34,    42,    43,    49,    50,    51,    32,
      32,    32,    26,    32,    32,    24,    25,    26,    28,    32,
      52,    32,    16,    32,    38,    26,    44,    52,    52,    26,
      45,    37,    38,    47,    52,    26,    52,    38,    52,    12,
      13,    14,    15,    17,    18,    19,    20,    21,    22,    23,
      29,    30,    37,    33,    52,    33,    47,    52,    16,    37,
      26,    35,    49,    33,    33,    16,    37,    25,    33,    36,
      33,    52,    33,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    43,    37,    37,    43,
      33,    39,    28,    32,    49,    50,    43,    52,    52,    39,
      37,    52,    37,    39,    37,    16,    37,    33,     4,    37,
      16,    37,    52,    50,    51,    26,    46,    34,    37,    16,
      33,    48,    52,    52,    43,    35,    36,    37,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     4,     4,     1,     3,     0,     2,
       0,     3,     0,     3,     1,     3,     1,     3,     1,     1,
       1,     3,     6,    10,     3,     5,     4,     4,     7,     5,
       7,     5,     9,     5,     5,     3,     5,     7,     1,     1,
       1,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2
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
  case 11: /* for_init: IDENTIFIER ASSIGN expression  */
#line 73 "parser.y"
                                   { emit("mov %s %s 0", regOf((yyvsp[-2].id)).c_str(), (*(yyvsp[0].str)).c_str()); }
#line 1257 "parser.tab.c"
    break;

  case 13: /* for_update: IDENTIFIER ASSIGN expression  */
#line 77 "parser.y"
                                   { emit("mov %s %s 0", regOf((yyvsp[-2].id)).c_str(), (*(yyvsp[0].str)).c_str()); }
#line 1263 "parser.tab.c"
    break;

  case 14: /* argument_list: expression  */
#line 81 "parser.y"
                 { (yyval.strlist) = new std::vector<std::string>(); (yyval.strlist)->push_back(*(yyvsp[0].str)); }
#line 1269 "parser.tab.c"
    break;

  case 15: /* argument_list: argument_list ',' expression  */
#line 82 "parser.y"
                                   { (yyvsp[-2].strlist)->push_back(*(yyvsp[0].str)); (yyval.strlist) = (yyvsp[-2].strlist); }
#line 1275 "parser.tab.c"
    break;

  case 16: /* expression_list: expression  */
#line 86 "parser.y"
                 { (yyval.strlist) = new std::vector<std::string>(); (yyval.strlist)->push_back(*(yyvsp[0].str)); }
#line 1281 "parser.tab.c"
    break;

  case 17: /* expression_list: expression_list ',' expression  */
#line 87 "parser.y"
                                     { (yyvsp[-2].strlist)->push_back(*(yyvsp[0].str)); (yyval.strlist) = (yyvsp[-2].strlist); }
#line 1287 "parser.tab.c"
    break;

  case 21: /* matched_stmt: INT IDENTIFIER ';'  */
#line 97 "parser.y"
                                                                          { declareVar((yyvsp[-1].id)); }
#line 1293 "parser.tab.c"
    break;

  case 22: /* matched_stmt: INT IDENTIFIER '[' NUMBER ']' ';'  */
#line 98 "parser.y"
                                                                           { declareArray((yyvsp[-4].id), (yyvsp[-2].num)); }
#line 1299 "parser.tab.c"
    break;

  case 23: /* matched_stmt: INT IDENTIFIER '[' NUMBER ']' ASSIGN '{' expression_list '}' ';'  */
#line 99 "parser.y"
                                                                           {
        declareArray((yyvsp[-8].id), (yyvsp[-6].num));
        int idx = 0;
        for (auto &e : *(yyvsp[-2].strlist)) {
            std::string name = std::string((yyvsp[-8].id)) + "[" + std::to_string(idx++) + "]";
            emit("mov %s %s 0", regOf(name).c_str(), e.c_str());
        }
    }
#line 1312 "parser.tab.c"
    break;

  case 24: /* matched_stmt: STRING_TYPE IDENTIFIER ';'  */
#line 107 "parser.y"
                                                                           { declareVar((yyvsp[-1].id)); }
#line 1318 "parser.tab.c"
    break;

  case 25: /* matched_stmt: STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL ';'  */
#line 108 "parser.y"
                                                                           {
        declareVar((yyvsp[-3].id));
        emit("printf %s 0 0", (yyvsp[-1].id));
    }
#line 1327 "parser.tab.c"
    break;

  case 26: /* matched_stmt: IDENTIFIER ASSIGN expression ';'  */
#line 112 "parser.y"
                                                                           { emit("mov %s %s 0", regOf((yyvsp[-3].id)).c_str(), (*(yyvsp[-1].str)).c_str()); }
#line 1333 "parser.tab.c"
    break;

  case 27: /* matched_stmt: IDENTIFIER '(' ')' ';'  */
#line 113 "parser.y"
                                                                           { emit("call %s 0 0", (yyvsp[-3].id)); }
#line 1339 "parser.tab.c"
    break;

  case 28: /* matched_stmt: IDENTIFIER '[' expression ']' ASSIGN expression ';'  */
#line 114 "parser.y"
                                                                           {
        std::string idx = *(yyvsp[-4].str);
        std::string name = std::string((yyvsp[-6].id)) + "[" + idx + "]";
        emit("mov %s %s 0", regOf(name).c_str(), (*(yyvsp[-1].str)).c_str());
    }
#line 1349 "parser.tab.c"
    break;

  case 29: /* matched_stmt: IDENTIFIER '(' argument_list ')' ';'  */
#line 119 "parser.y"
                                                                           {
        for (auto &a : *(yyvsp[-2].strlist)) emit("push %s 0 0", a.c_str());
        emit("call %s 0 0", (yyvsp[-4].id));
        emit("popargs 0 0 0");
    }
#line 1359 "parser.tab.c"
    break;

  case 30: /* matched_stmt: IF '(' expression ')' matched_stmt ELSE matched_stmt  */
#line 124 "parser.y"
                                                                            {
        std::string cond = *(yyvsp[-4].str);
        std::string Lelse = newLabel();
        std::string Lend  = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lelse.c_str());
        emit("jump %s 0 0", Lend.c_str());
        emit("label %s 0 0", Lelse.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1373 "parser.tab.c"
    break;

  case 31: /* matched_stmt: WHILE '(' expression ')' block  */
#line 133 "parser.y"
                                                                            {
        std::string Lstart = newLabel();
        std::string Lend   = newLabel();
        std::string cond   = *(yyvsp[-2].str);
        emit("label %s 0 0", Lstart.c_str());
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("jump %s 0 0", Lstart.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1387 "parser.tab.c"
    break;

  case 32: /* matched_stmt: FOR '(' for_init ';' expression ';' for_update ')' block  */
#line 142 "parser.y"
                                                                            {
        std::string Lstart = newLabel();
        std::string Lend   = newLabel();
        std::string cond   = *(yyvsp[-4].str);
        emit("label %s 0 0", Lstart.c_str());
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("jump %s 0 0", Lstart.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1401 "parser.tab.c"
    break;

  case 33: /* matched_stmt: PRINT '(' argument_list ')' ';'  */
#line 151 "parser.y"
                                                                            {
        for (auto &e : *(yyvsp[-2].strlist)) {
            if (e.size() >= 2 && e.front() == '"' && e.back() == '"')
                emit("printf %s 0 0", e.c_str());
            else
                emit("printv %s 0 0", e.c_str());
        }
    }
#line 1414 "parser.tab.c"
    break;

  case 34: /* matched_stmt: READ '(' IDENTIFIER ')' ';'  */
#line 159 "parser.y"
                                                                           {
        emit("read %s 0 0", regOf((yyvsp[-2].id)).c_str());
    }
#line 1422 "parser.tab.c"
    break;

  case 35: /* matched_stmt: RETURN expression ';'  */
#line 162 "parser.y"
                                                                            {
        std::string r = *(yyvsp[-1].str);
        emit("mov %ret %s 0", r.c_str());
    }
#line 1431 "parser.tab.c"
    break;

  case 36: /* unmatched_stmt: IF '(' expression ')' statement  */
#line 169 "parser.y"
                                                                             {
        std::string cond = *(yyvsp[-2].str);
        std::string Lend = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1442 "parser.tab.c"
    break;

  case 37: /* unmatched_stmt: IF '(' expression ')' matched_stmt ELSE unmatched_stmt  */
#line 175 "parser.y"
                                                                            {
        std::string cond  = *(yyvsp[-4].str);
        std::string Lelse = newLabel();
        std::string Lend  = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lelse.c_str());
        emit("jump %s 0 0", Lend.c_str());
        emit("label %s 0 0", Lelse.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1456 "parser.tab.c"
    break;

  case 38: /* expression: NUMBER  */
#line 186 "parser.y"
                                                                           { (yyval.str) = new std::string(std::to_string((yyvsp[0].num))); }
#line 1462 "parser.tab.c"
    break;

  case 39: /* expression: IDENTIFIER  */
#line 187 "parser.y"
                                                                         { (yyval.str) = new std::string(regOf((yyvsp[0].id))); }
#line 1468 "parser.tab.c"
    break;

  case 40: /* expression: STRING_LITERAL  */
#line 188 "parser.y"
                                                                         { (yyval.str) = new std::string((yyvsp[0].id)); }
#line 1474 "parser.tab.c"
    break;

  case 41: /* expression: '(' expression ')'  */
#line 189 "parser.y"
                                                                         { (yyval.str) = (yyvsp[-1].str); }
#line 1480 "parser.tab.c"
    break;

  case 42: /* expression: IDENTIFIER '[' expression ']'  */
#line 190 "parser.y"
                                                                         {
        std::string idx = *(yyvsp[-1].str);
        std::string name = std::string((yyvsp[-3].id)) + "[" + idx + "]";
        (yyval.str) = new std::string(regOf(name));
    }
#line 1490 "parser.tab.c"
    break;

  case 43: /* expression: expression PLUS expression  */
#line 195 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("add %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1500 "parser.tab.c"
    break;

  case 44: /* expression: expression MINUS expression  */
#line 200 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("sub %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1510 "parser.tab.c"
    break;

  case 45: /* expression: expression TIMES expression  */
#line 205 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("mult %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1520 "parser.tab.c"
    break;

  case 46: /* expression: expression DIVIDE expression  */
#line 210 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("div %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1530 "parser.tab.c"
    break;

  case 47: /* expression: expression MOD expression  */
#line 215 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("mod %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1540 "parser.tab.c"
    break;

  case 48: /* expression: expression '<' expression  */
#line 220 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("less %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1550 "parser.tab.c"
    break;

  case 49: /* expression: expression '>' expression  */
#line 225 "parser.y"
                                                                         {
        std::string tmp = newTemp();
        emit("greater %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1560 "parser.tab.c"
    break;

  case 50: /* expression: expression LE expression  */
#line 230 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("lesseq %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1570 "parser.tab.c"
    break;

  case 51: /* expression: expression GE expression  */
#line 235 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("greatereq %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1580 "parser.tab.c"
    break;

  case 52: /* expression: expression EQ expression  */
#line 240 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("equal %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1590 "parser.tab.c"
    break;

  case 53: /* expression: expression NE expression  */
#line 245 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("diff %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1600 "parser.tab.c"
    break;

  case 54: /* expression: expression AND expression  */
#line 250 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("and %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1610 "parser.tab.c"
    break;

  case 55: /* expression: expression OR expression  */
#line 255 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("or %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1620 "parser.tab.c"
    break;

  case 56: /* expression: NOT expression  */
#line 260 "parser.y"
                                                                          {
        std::string tmp = newTemp();
        emit("not %s %s 0", tmp.c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1630 "parser.tab.c"
    break;


#line 1634 "parser.tab.c"

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

#line 267 "parser.y"


int yyerror(const char *s){
    fprintf(stderr,"Erro sintatico: %s\n",s);
    return 0;
}

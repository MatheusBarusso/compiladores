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
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_external_decl = 41,             /* external_decl  */
  YYSYMBOL_block = 42,                     /* block  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_for_init = 44,                  /* for_init  */
  YYSYMBOL_for_update = 45,                /* for_update  */
  YYSYMBOL_argument_list = 46,             /* argument_list  */
  YYSYMBOL_expression_list = 47,           /* expression_list  */
  YYSYMBOL_statement = 48,                 /* statement  */
  YYSYMBOL_expression = 49                 /* expression  */
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
#define YYLAST   312

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      31,    32,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      29,     2,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    58,    59,    60,    64,    67,    68,
      71,    72,    77,    78,    84,    88,    95,    99,   106,   109,
     112,   121,   124,   128,   131,   134,   139,   146,   155,   164,
     173,   182,   187,   190,   197,   200,   203,   206,   209,   214,
     219,   224,   229,   234,   239,   244,   249,   254,   259,   264,
     269,   274
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
  "'>'", "'('", "')'", "'{'", "'}'", "','", "';'", "'['", "']'", "$accept",
  "program", "external_decl", "block", "statement_list", "for_init",
  "for_update", "argument_list", "expression_list", "statement",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -57,    63,   -57,   -21,     1,    18,    -6,    20,    31,   281,
      33,   -14,    -4,   -57,   -57,   281,   281,    41,    55,   281,
      49,   281,   -57,   -57,   -57,   281,   103,    48,   281,    28,
     281,   -11,   183,   204,    80,    74,   -57,    75,   -31,   246,
      82,   246,   225,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   -57,    94,   123,   -22,
     -17,    64,   100,   -57,    94,    94,   281,   281,    91,    95,
     281,    98,   -57,   274,   274,   260,   260,    84,    84,    84,
      84,   260,   107,   -57,    84,    84,   -57,   -57,   -57,   -57,
     -57,   111,   132,   113,   146,   -57,   246,   143,    -3,   -57,
     246,   -57,    21,   -57,   281,   -57,    94,   125,   121,   -57,
      72,   -57,   -57,   163,   -57,   151,   136,   281,    73,   -57,
     281,    94,    78,   246,   133,   246,   -57,   134,   281,   -57,
     246
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     6,     0,     0,    10,     0,     0,
       0,     0,    34,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,    14,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    45,    46,    47,
      48,    42,    49,    50,    43,    44,     8,     4,    23,    24,
       5,     0,     0,     0,    27,    30,    11,     0,     0,    31,
      15,    32,     0,    26,     0,    22,     0,    12,     0,    19,
       0,     7,     9,     0,    28,     0,     0,     0,     0,    25,
       0,     0,     0,    16,     0,    13,    29,     0,     0,    20,
      17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -56,   -57,   -57,   -57,   152,   -57,    85,
      -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    87,   102,    35,   116,    60,   122,    14,
      39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    69,    28,    90,    70,    62,    32,    33,    94,    95,
      15,    86,    41,   108,    89,    91,    42,    29,    70,    58,
      18,    61,    31,    30,     3,    63,     4,     5,     6,     7,
       8,     9,    16,   109,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   110,    12,    17,
     114,    19,    21,    22,    23,   111,    24,    96,    97,    25,
      59,   100,    20,     2,    27,   126,     3,    34,     4,     5,
       6,     7,     8,     9,    10,    40,    43,    44,    45,    46,
      57,    47,    48,    49,    50,    51,    52,    53,    28,    11,
      12,    36,    37,    54,    55,   113,    66,    21,    22,    23,
      68,    24,    92,   118,    25,   124,    52,    53,   123,    30,
      67,   125,   127,   128,    71,    43,    44,    45,    46,   130,
      47,    48,    49,    50,    51,    52,    53,    86,    93,    98,
      53,    99,    54,    55,   101,    43,    44,    45,    46,    56,
      47,    48,    49,    50,    51,    52,    53,   103,   104,   105,
     106,   115,    54,    55,   117,    43,    44,    45,    46,    88,
      47,    48,    49,    50,    51,    52,    53,   120,   121,    89,
     129,    38,    54,    55,     0,    43,    44,    45,    46,   107,
      47,    48,    49,    50,    51,    52,    53,   112,     0,     0,
       0,     0,    54,    55,     0,    43,    44,    45,    46,   119,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,    54,    55,     0,    64,    43,    44,    45,    46,
       0,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,    54,    55,     0,    65,    43,    44,    45,
      46,     0,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,     0,    54,    55,     0,    72,    43,    44,
      45,    46,     0,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    43,    44,     0,    54,    55,    47,    48,    49,
      50,     0,    52,    53,     0,     0,     0,     0,     0,    54,
      55,    47,    48,    49,    50,     0,    52,    53,     0,     0,
       0,     0,     0,    54,    55,    21,    22,    23,     0,    24,
       0,     0,    25
};

static const yytype_int16 yycheck[] =
{
       9,    32,    16,    59,    35,    16,    15,    16,    64,    65,
      31,    33,    21,    16,    36,    32,    25,    31,    35,    28,
      26,    30,    26,    37,     3,    36,     5,     6,     7,     8,
       9,    10,    31,    36,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    26,    27,    31,
     106,    31,    24,    25,    26,    34,    28,    66,    67,    31,
      32,    70,    31,     0,    31,   121,     3,    26,     5,     6,
       7,     8,     9,    10,    11,    26,    12,    13,    14,    15,
      32,    17,    18,    19,    20,    21,    22,    23,    16,    26,
      27,    36,    37,    29,    30,   104,    16,    24,    25,    26,
      25,    28,    38,    31,    31,    32,    22,    23,   117,    37,
      36,   120,    34,    35,    32,    12,    13,    14,    15,   128,
      17,    18,    19,    20,    21,    22,    23,    33,    28,    38,
      23,    36,    29,    30,    36,    12,    13,    14,    15,    36,
      17,    18,    19,    20,    21,    22,    23,    36,    16,    36,
       4,    26,    29,    30,    33,    12,    13,    14,    15,    36,
      17,    18,    19,    20,    21,    22,    23,    16,    32,    36,
      36,    19,    29,    30,    -1,    12,    13,    14,    15,    36,
      17,    18,    19,    20,    21,    22,    23,   102,    -1,    -1,
      -1,    -1,    29,    30,    -1,    12,    13,    14,    15,    36,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    32,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    32,    12,    13,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    12,    13,    -1,    29,    30,    17,    18,    19,
      20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      30,    17,    18,    19,    20,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    30,    24,    25,    26,    -1,    28,
      -1,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,     0,     3,     5,     6,     7,     8,     9,    10,
      11,    26,    27,    41,    48,    31,    31,    31,    26,    31,
      31,    24,    25,    26,    28,    31,    49,    31,    16,    31,
      37,    26,    49,    49,    26,    44,    36,    37,    46,    49,
      26,    49,    49,    12,    13,    14,    15,    17,    18,    19,
      20,    21,    22,    23,    29,    30,    36,    32,    49,    32,
      46,    49,    16,    36,    32,    32,    16,    36,    25,    32,
      35,    32,    32,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    33,    42,    36,    36,
      42,    32,    38,    28,    42,    42,    49,    49,    38,    36,
      49,    36,    43,    36,    16,    36,     4,    36,    16,    36,
      26,    34,    48,    49,    42,    26,    45,    33,    31,    36,
      16,    32,    47,    49,    32,    49,    42,    34,    35,    36,
      49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    42,    43,    43,
      44,    44,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     4,     4,     1,     3,     0,     2,
       0,     3,     0,     3,     1,     3,     1,     3,     3,     6,
      10,     3,     5,     4,     4,     7,     5,     5,     7,     9,
       5,     5,     5,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2
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
#line 72 "parser.y"
                                 {
      emit("mov %s %s 0", regOf((yyvsp[-2].id)).c_str(), (*(yyvsp[0].str)).c_str());
  }
#line 1243 "parser.tab.c"
    break;

  case 13: /* for_update: IDENTIFIER ASSIGN expression  */
#line 78 "parser.y"
                                 {
      emit("mov %s %s 0", regOf((yyvsp[-2].id)).c_str(), (*(yyvsp[0].str)).c_str());
  }
#line 1251 "parser.tab.c"
    break;

  case 14: /* argument_list: expression  */
#line 84 "parser.y"
                 {
          (yyval.strlist) = new std::vector<std::string>();
          (yyval.strlist)->push_back(*(yyvsp[0].str));
      }
#line 1260 "parser.tab.c"
    break;

  case 15: /* argument_list: argument_list ',' expression  */
#line 88 "parser.y"
                                   {
          (yyvsp[-2].strlist)->push_back(*(yyvsp[0].str));
          (yyval.strlist) = (yyvsp[-2].strlist);
      }
#line 1269 "parser.tab.c"
    break;

  case 16: /* expression_list: expression  */
#line 95 "parser.y"
                 {
          (yyval.strlist) = new std::vector<std::string>();
          (yyval.strlist)->push_back(*(yyvsp[0].str));
      }
#line 1278 "parser.tab.c"
    break;

  case 17: /* expression_list: expression_list ',' expression  */
#line 99 "parser.y"
                                     {
          (yyvsp[-2].strlist)->push_back(*(yyvsp[0].str));
          (yyval.strlist) = (yyvsp[-2].strlist);
      }
#line 1287 "parser.tab.c"
    break;

  case 18: /* statement: INT IDENTIFIER ';'  */
#line 106 "parser.y"
                       {
        declareVar((yyvsp[-1].id));
    }
#line 1295 "parser.tab.c"
    break;

  case 19: /* statement: INT IDENTIFIER '[' NUMBER ']' ';'  */
#line 109 "parser.y"
                                      {
        declareArray((yyvsp[-4].id), (yyvsp[-2].num));
    }
#line 1303 "parser.tab.c"
    break;

  case 20: /* statement: INT IDENTIFIER '[' NUMBER ']' ASSIGN '{' expression_list '}' ';'  */
#line 112 "parser.y"
                                                                     {
        declareArray((yyvsp[-8].id), (yyvsp[-6].num));
        int idx = 0;
        for (auto &e : *(yyvsp[-2].strlist)) {
            std::string name = std::string((yyvsp[-8].id)) + "[" + std::to_string(idx) + "]";
            emit("mov %s %s 0", regOf(name).c_str(), e.c_str());
            idx++;
        }
    }
#line 1317 "parser.tab.c"
    break;

  case 21: /* statement: STRING_TYPE IDENTIFIER ';'  */
#line 121 "parser.y"
                               {
        declareVar((yyvsp[-1].id));
    }
#line 1325 "parser.tab.c"
    break;

  case 22: /* statement: STRING_TYPE IDENTIFIER ASSIGN STRING_LITERAL ';'  */
#line 124 "parser.y"
                                                     {
        declareVar((yyvsp[-3].id));
        emit("printf %s 0 0", (yyvsp[-1].id));
    }
#line 1334 "parser.tab.c"
    break;

  case 23: /* statement: IDENTIFIER ASSIGN expression ';'  */
#line 128 "parser.y"
                                     {
        emit("mov %s %s 0", regOf((yyvsp[-3].id)).c_str(), (*(yyvsp[-1].str)).c_str());
    }
#line 1342 "parser.tab.c"
    break;

  case 24: /* statement: IDENTIFIER '(' ')' ';'  */
#line 131 "parser.y"
                           {
        emit("call %s 0 0", (yyvsp[-3].id));
    }
#line 1350 "parser.tab.c"
    break;

  case 25: /* statement: IDENTIFIER '[' expression ']' ASSIGN expression ';'  */
#line 134 "parser.y"
                                                        {
        std::string idx = *(yyvsp[-4].str);
        std::string name = std::string((yyvsp[-6].id)) + "[" + idx + "]";
        emit("mov %s %s 0", regOf(name).c_str(), (*(yyvsp[-1].str)).c_str());
    }
#line 1360 "parser.tab.c"
    break;

  case 26: /* statement: IDENTIFIER '(' argument_list ')' ';'  */
#line 139 "parser.y"
                                         {
        for (auto &a : *(yyvsp[-2].strlist)) {
            emit("push %s 0 0", a.c_str());
        }
        emit("call %s 0 0", (yyvsp[-4].id));
        emit("popargs 0 0 0");
    }
#line 1372 "parser.tab.c"
    break;

  case 27: /* statement: IF '(' expression ')' block  */
#line 146 "parser.y"
                                {
        std::string cond = *(yyvsp[-2].str);
        std::string Lelse = newLabel();
        std::string Lend  = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lelse.c_str());
        emit("jump %s 0 0", Lend.c_str());
        emit("label %s 0 0", Lelse.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1386 "parser.tab.c"
    break;

  case 28: /* statement: IF '(' expression ')' block ELSE block  */
#line 155 "parser.y"
                                           {
        std::string cond = *(yyvsp[-4].str);
        std::string Lelse = newLabel();
        std::string Lend  = newLabel();
        emit("jf %s %s 0", cond.c_str(), Lelse.c_str());
        emit("jump %s 0 0", Lend.c_str());
        emit("label %s 0 0", Lelse.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1400 "parser.tab.c"
    break;

  case 29: /* statement: FOR '(' for_init ';' expression ';' for_update ')' block  */
#line 164 "parser.y"
                                                             {
        std::string Lstart = newLabel();
        std::string Lend   = newLabel();
        std::string cond   = *(yyvsp[-4].str);
        emit("label %s 0 0", Lstart.c_str());
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("jump %s 0 0", Lstart.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1414 "parser.tab.c"
    break;

  case 30: /* statement: WHILE '(' expression ')' block  */
#line 173 "parser.y"
                                   {
        std::string Lstart = newLabel();
        std::string Lend   = newLabel();
        std::string cond   = *(yyvsp[-2].str);
        emit("label %s 0 0", Lstart.c_str());
        emit("jf %s %s 0", cond.c_str(), Lend.c_str());
        emit("jump %s 0 0", Lstart.c_str());
        emit("label %s 0 0", Lend.c_str());
    }
#line 1428 "parser.tab.c"
    break;

  case 31: /* statement: PRINT '(' argument_list ')' ';'  */
#line 182 "parser.y"
                                    {
        for (auto &e : *(yyvsp[-2].strlist)) {
            emit("printf %s 0 0", e.c_str());
        }
    }
#line 1438 "parser.tab.c"
    break;

  case 32: /* statement: READ '(' IDENTIFIER ')' ';'  */
#line 187 "parser.y"
                                {
        emit("read %s 0 0", regOf((yyvsp[-2].id)).c_str());
    }
#line 1446 "parser.tab.c"
    break;

  case 33: /* statement: RETURN expression ';'  */
#line 190 "parser.y"
                          {
        std::string r = *(yyvsp[-1].str);
        emit("mov %ret %s 0", r.c_str());
    }
#line 1455 "parser.tab.c"
    break;

  case 34: /* expression: NUMBER  */
#line 197 "parser.y"
           {
        (yyval.str) = new std::string(std::to_string((yyvsp[0].num)));
    }
#line 1463 "parser.tab.c"
    break;

  case 35: /* expression: IDENTIFIER  */
#line 200 "parser.y"
               {
        (yyval.str) = new std::string((yyvsp[0].id));
    }
#line 1471 "parser.tab.c"
    break;

  case 36: /* expression: STRING_LITERAL  */
#line 203 "parser.y"
                   {
        (yyval.str) = new std::string((yyvsp[0].id));
    }
#line 1479 "parser.tab.c"
    break;

  case 37: /* expression: '(' expression ')'  */
#line 206 "parser.y"
                       {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 1487 "parser.tab.c"
    break;

  case 38: /* expression: expression PLUS expression  */
#line 209 "parser.y"
                               {
        std::string tmp = newTemp();
        emit("add %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1497 "parser.tab.c"
    break;

  case 39: /* expression: expression MINUS expression  */
#line 214 "parser.y"
                                {
        std::string tmp = newTemp();
        emit("sub %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1507 "parser.tab.c"
    break;

  case 40: /* expression: expression TIMES expression  */
#line 219 "parser.y"
                                {
        std::string tmp = newTemp();
        emit("mult %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1517 "parser.tab.c"
    break;

  case 41: /* expression: expression DIVIDE expression  */
#line 224 "parser.y"
                                 {
        std::string tmp = newTemp();
        emit("div %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1527 "parser.tab.c"
    break;

  case 42: /* expression: expression MOD expression  */
#line 229 "parser.y"
                              {
        std::string tmp = newTemp();
        emit("mod %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1537 "parser.tab.c"
    break;

  case 43: /* expression: expression '<' expression  */
#line 234 "parser.y"
                              {
        std::string tmp = newTemp();
        emit("less %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1547 "parser.tab.c"
    break;

  case 44: /* expression: expression '>' expression  */
#line 239 "parser.y"
                              {
        std::string tmp = newTemp();
        emit("greater %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1557 "parser.tab.c"
    break;

  case 45: /* expression: expression LE expression  */
#line 244 "parser.y"
                             {
        std::string tmp = newTemp();
        emit("lesseq %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1567 "parser.tab.c"
    break;

  case 46: /* expression: expression GE expression  */
#line 249 "parser.y"
                             {
        std::string tmp = newTemp();
        emit("greatereq %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1577 "parser.tab.c"
    break;

  case 47: /* expression: expression EQ expression  */
#line 254 "parser.y"
                             {
        std::string tmp = newTemp();
        emit("equal %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1587 "parser.tab.c"
    break;

  case 48: /* expression: expression NE expression  */
#line 259 "parser.y"
                             {
        std::string tmp = newTemp();
        emit("diff %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1597 "parser.tab.c"
    break;

  case 49: /* expression: expression AND expression  */
#line 264 "parser.y"
                              {
        std::string tmp = newTemp();
        emit("and %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1607 "parser.tab.c"
    break;

  case 50: /* expression: expression OR expression  */
#line 269 "parser.y"
                             {
        std::string tmp = newTemp();
        emit("or %s %s %s", tmp.c_str(), (*(yyvsp[-2].str)).c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1617 "parser.tab.c"
    break;

  case 51: /* expression: NOT expression  */
#line 274 "parser.y"
                   {
        std::string tmp = newTemp();
        emit("not %s %s 0", tmp.c_str(), (*(yyvsp[0].str)).c_str());
        (yyval.str) = new std::string(tmp);
    }
#line 1627 "parser.tab.c"
    break;


#line 1631 "parser.tab.c"

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

#line 281 "parser.y"


int yyerror(const char *s){
    fprintf(stderr,"Erro sintatico: %s\n",s);
    return 0;
}

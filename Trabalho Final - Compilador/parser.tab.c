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
#include <string.h>
extern FILE *yyout;
#define emit(fmt, ...) fprintf(yyout, fmt, __VA_ARGS__)
typedef struct {
    char *id;
    int end;
} simbolo;

typedef struct {
    char *id;
    int t1;
    int t2;
    int t3;
} expressao;

expressao tabela[1000];
simbolo tabsimb[10000];
int nsimbs = 0;
int endereco = 0;
int topo_tabela = 0;

// Vazio verifica se a expressão de comparação tem ou não tem AND ou OR 

int vazio = -1;

int pilha[200];
int topo = 0;

// Mesma linha de raciocino para as expressões com parenteses

int expre[200];
int topo_expre = 0;

// contagem_jf é a variavel para mostrar os numeros de jf

int contagem_jf = 0;
int T = 0;
int rotulo = 0;

// Esse vetor armazenar os pop's() do else para mostrar no final

int finalDoElse[100];
int fina_else = 0;

// Mostra o AND ou OR e a expressão que está com ele

void pop_tabela(int t1)
{
 
 printf("%s %%t%d, %%t%d, %%t%d \n",tabela[topo_tabela].id,t1+1,tabela[topo_tabela].t2,t1);

}


int getendereco(char *id) { 
	for (int i=0;i<nsimbs;i++)
	    if(!strcmp(tabsimb[i].id,id))
	    	return tabsimb[i].end;
	return -1;
}

// Armazena as variaveis para as expressoes com parenteses

void push_expre(int x)
{
	if(topo_expre >= 200) {
	   printf("Pilha cheia \n");
	   return 0;
	}
	expre[topo_expre] = x;
	topo_expre++;
}

// Mostra a variavel

int pop_expre(void) 
{
  topo_expre--;
  if(expre < 0)
  {
  	return 0;
  }
  
  return expre[topo_expre];
}

// Essa a pilha utilizada para os numeros utilizados dos FOR, WHILE e IF

void push(int x)
{
	if(topo >= 200) {
	   printf("Pilha cheia \n");
	   return 0;
	}
	pilha[topo] = x;
	topo++;
}

int pop(void) 
{
  topo--;
  if(topo < 0)
  {
  	return 0;
  }
  return pilha[topo];
}


#line 183 "parser.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_ATRIB = 4,                      /* ATRIB  */
  YYSYMBOL_PEV = 5,                        /* PEV  */
  YYSYMBOL_VETOR = 6,                      /* VETOR  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_PRINTF = 12,                    /* PRINTF  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_SCANF = 14,                     /* SCANF  */
  YYSYMBOL_COMENT = 15,                    /* COMENT  */
  YYSYMBOL_ERRO = 16,                      /* ERRO  */
  YYSYMBOL_COMENTARIO = 17,                /* COMENTARIO  */
  YYSYMBOL_NUM = 18,                       /* NUM  */
  YYSYMBOL_MAISMAIS = 19,                  /* MAISMAIS  */
  YYSYMBOL_MENOR = 20,                     /* MENOR  */
  YYSYMBOL_IGUAL = 21,                     /* IGUAL  */
  YYSYMBOL_MAIOR = 22,                     /* MAIOR  */
  YYSYMBOL_DIFERENTE = 23,                 /* DIFERENTE  */
  YYSYMBOL_MAIORIGUAL = 24,                /* MAIORIGUAL  */
  YYSYMBOL_MENORIGUAL = 25,                /* MENORIGUAL  */
  YYSYMBOL_MENOSMENOS = 26,                /* MENOSMENOS  */
  YYSYMBOL_LPAR = 27,                      /* LPAR  */
  YYSYMBOL_RPAR = 28,                      /* RPAR  */
  YYSYMBOL_LCHAVE = 29,                    /* LCHAVE  */
  YYSYMBOL_RCHAVE = 30,                    /* RCHAVE  */
  YYSYMBOL_LCOL = 31,                      /* LCOL  */
  YYSYMBOL_RCOL = 32,                      /* RCOL  */
  YYSYMBOL_MAIS = 33,                      /* MAIS  */
  YYSYMBOL_MENOS = 34,                     /* MENOS  */
  YYSYMBOL_MULT = 35,                      /* MULT  */
  YYSYMBOL_DIVINT = 36,                    /* DIVINT  */
  YYSYMBOL_MOD = 37,                       /* MOD  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_APOST = 39,                     /* APOST  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_linhaDeCodigo = 44,             /* linhaDeCodigo  */
  YYSYMBOL_receber = 45,                   /* receber  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_mostrar = 48,                   /* mostrar  */
  YYSYMBOL_printf = 49,                    /* printf  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_atrib = 52,                     /* atrib  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_lacofor = 55,                   /* lacofor  */
  YYSYMBOL_56_7 = 56,                      /* $@7  */
  YYSYMBOL_for = 57,                       /* for  */
  YYSYMBOL_dentrofor = 58,                 /* dentrofor  */
  YYSYMBOL_lacowhile = 59,                 /* lacowhile  */
  YYSYMBOL_60_8 = 60,                      /* $@8  */
  YYSYMBOL_61_9 = 61,                      /* $@9  */
  YYSYMBOL_62_10 = 62,                     /* $@10  */
  YYSYMBOL_se = 63,                        /* se  */
  YYSYMBOL_64_11 = 64,                     /* $@11  */
  YYSYMBOL_65_12 = 65,                     /* $@12  */
  YYSYMBOL_else = 66,                      /* else  */
  YYSYMBOL_67_13 = 67,                     /* $@13  */
  YYSYMBOL_expressoes = 68,                /* expressoes  */
  YYSYMBOL_69_14 = 69,                     /* $@14  */
  YYSYMBOL_operacao = 70,                  /* operacao  */
  YYSYMBOL_jv = 71,                        /* jv  */
  YYSYMBOL_contagem = 72,                  /* contagem  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_expr2 = 74,                     /* expr2  */
  YYSYMBOL_termo = 75                      /* termo  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   134,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   146,   146,   147,   147,   149,   153,   153,   154,   154,
     155,   156,   161,   162,   163,   164,   164,   165,   165,   169,
     169,   173,   177,   178,   182,   182,   182,   182,   186,   186,
     186,   190,   190,   191,   195,   195,   196,   197,   198,   202,
     203,   204,   205,   206,   207,   211,   212,   216,   217,   221,
     222,   223,   225,   226,   227,   228,   232,   233,   234,   235,
     236,   237
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "ATRIB", "PEV",
  "VETOR", "FOR", "WHILE", "IF", "ELSE", "INT", "PRINTF", "STRING",
  "SCANF", "COMENT", "ERRO", "COMENTARIO", "NUM", "MAISMAIS", "MENOR",
  "IGUAL", "MAIOR", "DIFERENTE", "MAIORIGUAL", "MENORIGUAL", "MENOSMENOS",
  "LPAR", "RPAR", "LCHAVE", "RCHAVE", "LCOL", "RCOL", "MAIS", "MENOS",
  "MULT", "DIVINT", "MOD", "DIV", "APOST", "AND", "OR", "BREAK", "$accept",
  "linhaDeCodigo", "receber", "$@1", "$@2", "mostrar", "printf", "$@3",
  "$@4", "atrib", "$@5", "$@6", "lacofor", "$@7", "for", "dentrofor",
  "lacowhile", "$@8", "$@9", "$@10", "se", "$@11", "$@12", "else", "$@13",
  "expressoes", "$@14", "operacao", "jv", "contagem", "expr", "expr2",
  "termo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    28,    -4,   -38,   -38,    31,    10,    37,   -38,    41,
      86,     5,     5,     5,     5,     5,     5,     4,     4,    47,
      51,    68,    25,    15,    94,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,    82,   -38,     4,    42,     6,    63,   -38,
      78,   -38,    17,    17,     4,   -38,    97,   106,   107,    29,
      44,     4,    60,   -38,   -38,   -38,     4,     4,     4,     4,
       4,   132,   134,    17,   -38,    84,   -38,    19,   -38,   123,
     135,   126,   -38,     4,    93,   -38,    63,    63,   -38,   -38,
     -38,     4,    99,   137,   115,    46,   116,   -38,   -38,   -38,
     -38,   -38,   -38,     4,   117,   -38,   114,    15,   -38,    15,
     142,    48,   -38,    48,     4,    22,    62,   119,    43,   120,
     145,   -38,   -38,   -38,   121,   146,    48,    35,   -38,   -38,
     124,   151,   -38,   -38,    17,     5,   -38,     5,   -38,   127,
     -38,   -38,   128,   -38,   -38,   -38,    17,   129,   153,     5,
     130,   -38,   152,   -38,   131,   -38,   -38,   -38,   -38,   136,
       5,   133,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,     0,     0,    34,    38,     0,     0,     0,     9,     0,
       0,    10,    10,    10,    10,    10,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     1,     7,     5,     2,
       3,     4,     6,    66,    67,     0,     0,     0,    61,    65,
       0,    29,     0,     0,     0,    23,     0,    18,     0,    16,
       0,     0,     0,    69,    70,    24,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,    39,     0,    25,     0,
       0,     0,    11,     0,     0,    68,    59,    60,    63,    64,
      62,     0,     0,     0,     0,     0,     0,    50,    51,    49,
      52,    54,    53,     0,     0,    22,     0,     0,    15,     0,
       0,    13,    71,    27,     0,     0,    48,     0,    46,     0,
       0,    19,    17,    12,     0,     0,    31,     0,    57,    58,
       0,     0,    55,    56,     0,    10,    44,    10,    26,     0,
      28,    33,     0,    32,    47,    36,     0,     0,     0,    10,
       0,    45,    43,    14,     0,    37,    41,    40,    30,     0,
      10,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -11,   -38,   -38,   -38,   -38,    -7,   -38,   -38,   147,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -37,   -38,    74,    56,    50,
      -8,    76,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,   100,   114,    12,    48,    71,    69,    13,
      96,   115,    14,    62,    83,   120,    15,    20,    86,   140,
      16,    21,    94,   147,   149,    64,   136,    93,   124,   121,
      65,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    28,    29,    30,    31,    32,    66,    33,     1,    37,
      40,    55,     2,     3,     4,    49,     5,     6,    33,     7,
      33,     8,    34,    19,    95,   117,    84,    52,    47,    44,
      45,    35,    17,    34,    22,    34,    67,    23,    36,    56,
      57,   118,    35,    74,    63,    53,    25,     9,   119,    36,
       1,    36,    56,    57,   118,    85,    46,   -20,     5,    18,
      54,   119,    56,    57,    24,   101,    87,    88,    89,    90,
      91,    92,    72,   103,    75,    73,    56,    57,    42,    56,
      57,    56,    57,   122,   123,   108,    26,   134,    75,    49,
     111,    49,   112,    56,    57,    43,   116,    50,    58,   141,
      59,    60,   122,   123,    87,    88,    89,    90,    91,    92,
      61,    56,    57,    51,   135,    68,   137,    56,    57,    87,
      88,    89,    90,    91,    92,   102,    56,    57,   144,    78,
      79,    80,    76,    77,   -21,    70,    81,    82,    97,   151,
      98,    99,   105,   106,   107,   109,   110,   113,   125,   127,
     128,   130,   132,   129,   133,   138,   104,   139,   143,   142,
     145,   148,   146,   152,   126,   150,    41,   131
};

static const yytype_uint8 yycheck[] =
{
      11,    12,    13,    14,    15,    16,    43,     3,     3,    17,
      18,     5,     7,     8,     9,    23,    11,    12,     3,    14,
       3,    16,    18,    27,     5,     3,    63,    35,    13,     4,
       5,    27,     4,    18,     3,    18,    44,    27,    34,    33,
      34,    19,    27,    51,    27,     3,     5,    42,    26,    34,
       3,    34,    33,    34,    19,    63,    31,    28,    11,    31,
      18,    26,    33,    34,    27,    73,    20,    21,    22,    23,
      24,    25,    28,    81,    28,    31,    33,    34,    27,    33,
      34,    33,    34,    40,    41,    93,     0,   124,    28,    97,
      97,    99,    99,    33,    34,    27,   104,     3,    35,   136,
      37,    38,    40,    41,    20,    21,    22,    23,    24,    25,
      32,    33,    34,    31,   125,    18,   127,    33,    34,    20,
      21,    22,    23,    24,    25,    32,    33,    34,   139,    58,
      59,    60,    56,    57,    28,    28,     4,     3,    15,   150,
       5,    15,     5,    28,    28,    28,    32,     5,    29,    29,
       5,     5,    28,    32,     3,    28,    82,    29,     5,    30,
      30,    30,    10,    30,   108,    29,    19,   117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     7,     8,     9,    11,    12,    14,    16,    42,
      44,    45,    48,    52,    55,    59,    63,     4,    31,    27,
      60,    64,     3,    27,    27,     5,     0,    44,    44,    44,
      44,    44,    44,     3,    18,    27,    34,    73,    74,    75,
      73,    52,    27,    27,     4,     5,    31,    13,    49,    73,
       3,    31,    73,     3,    18,     5,    33,    34,    35,    37,
      38,    32,    56,    27,    68,    73,    68,    73,    18,    51,
      28,    50,    28,    31,    73,    28,    74,    74,    75,    75,
      75,     4,     3,    57,    68,    73,    61,    20,    21,    22,
      23,    24,    25,    70,    65,     5,    53,    15,     5,    15,
      46,    73,    32,    73,    70,     5,    28,    28,    73,    28,
      32,    49,    49,     5,    47,    54,    73,     3,    19,    26,
      58,    72,    40,    41,    71,    29,    71,    29,     5,    32,
       5,    72,    28,     3,    68,    44,    69,    44,    28,    29,
      62,    68,    30,     5,    44,    30,    10,    66,    30,    67,
      29,    44,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    46,    45,    47,    45,    48,    50,    49,    51,    49,
      49,    49,    52,    52,    52,    53,    52,    54,    52,    56,
      55,    57,    58,    58,    60,    61,    62,    59,    64,    65,
      63,    67,    66,    66,    69,    68,    68,    68,    68,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       0,     0,     6,     0,     9,     5,     0,     4,     0,     4,
       1,     1,     5,     3,     4,     0,     7,     0,     8,     0,
      11,     3,     2,     2,     0,     0,     0,    10,     0,     0,
      10,     0,     5,     0,     0,     6,     3,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     3,     2,
       2,     4
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 8: /* linhaDeCodigo: BREAK PEV  */
#line 140 "parser.y"
                          { printf("jump R0%d\n", pilha[topo - 1]); }
#line 1618 "parser.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 146 "parser.y"
                             {int end = getendereco((yyvsp[-1].str_val));printf("read %%r%d\n",end);}
#line 1624 "parser.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 147 "parser.y"
                                  {int end = getendereco((yyvsp[-2].str_val));printf("read %%t%d\nstore %%t%d, %%t%d(%d)\n", T, T,(yyvsp[0].int_val),end);T++;}
#line 1630 "parser.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 153 "parser.y"
              {printf("printv %%t%d \n",(yyvsp[0].int_val));}
#line 1636 "parser.tab.c"
    break;

  case 18: /* $@4: %empty  */
#line 154 "parser.y"
                {printf("printf %s\n",(yyvsp[0].str_val));}
#line 1642 "parser.tab.c"
    break;

  case 20: /* printf: expr  */
#line 155 "parser.y"
              {printf("printv %%t%d \n",(yyvsp[0].int_val));}
#line 1648 "parser.tab.c"
    break;

  case 21: /* printf: STRING  */
#line 156 "parser.y"
                {printf("printf %s\n",(yyvsp[0].str_val));}
#line 1654 "parser.tab.c"
    break;

  case 22: /* atrib: INT ID ATRIB expr PEV  */
#line 161 "parser.y"
                              {printf("mov %%r%d, %%t%d\n", getendereco((yyvsp[-3].str_val)), (yyvsp[-1].int_val));}
#line 1660 "parser.tab.c"
    break;

  case 23: /* atrib: INT ID PEV  */
#line 162 "parser.y"
                   {tabsimb[nsimbs] = (simbolo){(yyvsp[-1].str_val), endereco}; nsimbs++;endereco++;}
#line 1666 "parser.tab.c"
    break;

  case 24: /* atrib: ID ATRIB expr PEV  */
#line 163 "parser.y"
                          {printf("mov %%r%d, %%t%d\n", getendereco((yyvsp[-3].str_val)), (yyvsp[-1].int_val));}
#line 1672 "parser.tab.c"
    break;

  case 25: /* $@5: %empty  */
#line 164 "parser.y"
                        {tabsimb[nsimbs] = (simbolo){(yyvsp[-2].str_val), endereco}; nsimbs++;endereco = (yyvsp[0].int_val) ;}
#line 1678 "parser.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 165 "parser.y"
                                     {int x = getendereco((yyvsp[-5].str_val));printf("store %%t%d, %%t%d(%d)\n",T-1,(yyvsp[-3].int_val),x);}
#line 1684 "parser.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 169 "parser.y"
                         {contagem_jf = rotulo+1;printf("label R0%d\n",rotulo); push(rotulo++); push(rotulo++);}
#line 1690 "parser.tab.c"
    break;

  case 30: /* lacofor: FOR LPAR atrib $@7 for PEV dentrofor RPAR LCHAVE linhaDeCodigo RCHAVE  */
#line 169 "parser.y"
                                                                                                                                                                    {int end = getendereco((yyvsp[-6].str_val));printf("add %%r%d, %%r%d, 1\n",end,end); printf("jump R0%d\nlabel R0%d\n",pop(),pop());}
#line 1696 "parser.tab.c"
    break;

  case 31: /* for: ID operacao expr  */
#line 173 "parser.y"
                       {int end = getendereco((yyvsp[-2].str_val)); printf("%s %%t%d, %%r%d, %%t%d\njf %%t%d, R0%d\n",(yyvsp[-1].str_val),T,end,(yyvsp[0].int_val), T, contagem_jf);(yyval.str_val)=(yyvsp[-2].str_val);T++;}
#line 1702 "parser.tab.c"
    break;

  case 32: /* dentrofor: contagem ID  */
#line 177 "parser.y"
                        {(yyval.str_val) = (yyvsp[0].str_val);}
#line 1708 "parser.tab.c"
    break;

  case 33: /* dentrofor: ID contagem  */
#line 178 "parser.y"
                        {(yyval.str_val) = (yyvsp[-1].str_val);}
#line 1714 "parser.tab.c"
    break;

  case 34: /* $@8: %empty  */
#line 182 "parser.y"
                  {contagem_jf = rotulo+1;printf("label R0%d \n",rotulo); push(rotulo++); push(rotulo++);}
#line 1720 "parser.tab.c"
    break;

  case 35: /* $@9: %empty  */
#line 182 "parser.y"
                                                                                                                           {printf("jf %%t%d, R0%d\n",T,contagem_jf);T++;}
#line 1726 "parser.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 182 "parser.y"
                                                                                                                                                                                                    { }
#line 1732 "parser.tab.c"
    break;

  case 37: /* lacowhile: WHILE $@8 LPAR expressoes $@9 RPAR LCHAVE linhaDeCodigo $@10 RCHAVE  */
#line 182 "parser.y"
                                                                                                                                                                                                               {printf("jump R0%d\nlabel R0%d\n",pop(),pop());}
#line 1738 "parser.tab.c"
    break;

  case 38: /* $@11: %empty  */
#line 186 "parser.y"
         { contagem_jf=rotulo;push(rotulo++); push(rotulo++);}
#line 1744 "parser.tab.c"
    break;

  case 39: /* $@12: %empty  */
#line 186 "parser.y"
                                                                               {printf("jf %%t%d, R0%d\n",T, contagem_jf);T++;}
#line 1750 "parser.tab.c"
    break;

  case 41: /* $@13: %empty  */
#line 190 "parser.y"
            {finalDoElse[fina_else++]=pop();printf("jump R0%d\n",finalDoElse[fina_else-1]);printf("label R0%d\n",pop());}
#line 1756 "parser.tab.c"
    break;

  case 42: /* else: ELSE $@13 LCHAVE linhaDeCodigo RCHAVE  */
#line 190 "parser.y"
                                                                                                                                                      {printf("label R0%d\n",finalDoElse[--fina_else]); }
#line 1762 "parser.tab.c"
    break;

  case 43: /* else: %empty  */
#line 191 "parser.y"
       { int x = pop();printf("jump R0%d\n",x);printf("label R0%d\nlabel R0%d\n",pop(),x);}
#line 1768 "parser.tab.c"
    break;

  case 44: /* $@14: %empty  */
#line 195 "parser.y"
                                   {printf("%s %%t%d, %%t%d, %%t%d\n", (yyvsp[-2].str_val) ,T, (yyvsp[-3].int_val), (yyvsp[-1].int_val));tabela[topo_tabela].t2 = T;T++;tabela[topo_tabela].id = (yyvsp[0].str_val);vazio=0;}
#line 1774 "parser.tab.c"
    break;

  case 46: /* expressoes: expr operacao expr  */
#line 196 "parser.y"
                                {printf("%s %%t%d, %%t%d, %%t%d\n", (yyvsp[-1].str_val) ,T, (yyvsp[-2].int_val), (yyvsp[0].int_val));push_expre(T);if(vazio!=-1){pop_tabela(T);T++;};vazio!=-1;}
#line 1780 "parser.tab.c"
    break;

  case 47: /* expressoes: LPAR expressoes RPAR jv expressoes  */
#line 197 "parser.y"
                                                {printf("%s %%t%d, %%t%d, %%t%d \n",(yyvsp[-1].str_val),T,pop_expre(),pop_expre());(yyval.int_val) = (yyvsp[-3].int_val);}
#line 1786 "parser.tab.c"
    break;

  case 48: /* expressoes: LPAR expressoes RPAR  */
#line 198 "parser.y"
                                  {(yyval.int_val) = (yyvsp[-1].int_val);}
#line 1792 "parser.tab.c"
    break;

  case 49: /* operacao: MAIOR  */
#line 202 "parser.y"
                 {(yyval.str_val) = "greater";}
#line 1798 "parser.tab.c"
    break;

  case 50: /* operacao: MENOR  */
#line 203 "parser.y"
                 {(yyval.str_val) = "less";}
#line 1804 "parser.tab.c"
    break;

  case 51: /* operacao: IGUAL  */
#line 204 "parser.y"
                 {(yyval.str_val) = "equal";}
#line 1810 "parser.tab.c"
    break;

  case 52: /* operacao: DIFERENTE  */
#line 205 "parser.y"
                     {(yyval.str_val) = "diff";}
#line 1816 "parser.tab.c"
    break;

  case 53: /* operacao: MENORIGUAL  */
#line 206 "parser.y"
                      {(yyval.str_val) = "lesseq";}
#line 1822 "parser.tab.c"
    break;

  case 54: /* operacao: MAIORIGUAL  */
#line 207 "parser.y"
                      {(yyval.str_val) = "greatereq";}
#line 1828 "parser.tab.c"
    break;

  case 55: /* jv: AND  */
#line 211 "parser.y"
         {(yyval.str_val) = "and";}
#line 1834 "parser.tab.c"
    break;

  case 56: /* jv: OR  */
#line 212 "parser.y"
        {(yyval.str_val) = "or";}
#line 1840 "parser.tab.c"
    break;

  case 57: /* contagem: MAISMAIS  */
#line 216 "parser.y"
                    {(yyval.str_val) = "add";}
#line 1846 "parser.tab.c"
    break;

  case 58: /* contagem: MENOSMENOS  */
#line 217 "parser.y"
                      {(yyval.str_val) = "sub";}
#line 1852 "parser.tab.c"
    break;

  case 59: /* expr: expr MAIS expr2  */
#line 221 "parser.y"
                       {printf("add %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val)); (yyval.int_val) = T++;}
#line 1858 "parser.tab.c"
    break;

  case 60: /* expr: expr MENOS expr2  */
#line 222 "parser.y"
                        {printf("sub %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val)); (yyval.int_val) = T++;}
#line 1864 "parser.tab.c"
    break;

  case 61: /* expr: expr2  */
#line 223 "parser.y"
             {(yyval.int_val) = (yyvsp[0].int_val);}
#line 1870 "parser.tab.c"
    break;

  case 62: /* expr2: expr2 DIV termo  */
#line 225 "parser.y"
                        {printf("div %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val)); (yyval.int_val) = T++;}
#line 1876 "parser.tab.c"
    break;

  case 63: /* expr2: expr2 MULT termo  */
#line 226 "parser.y"
                         {printf("mult %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val)); (yyval.int_val) = T++;}
#line 1882 "parser.tab.c"
    break;

  case 64: /* expr2: expr2 MOD termo  */
#line 227 "parser.y"
                         {printf("mod %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val)); (yyval.int_val) = T++;}
#line 1888 "parser.tab.c"
    break;

  case 65: /* expr2: termo  */
#line 228 "parser.y"
              {(yyval.int_val) = (yyvsp[0].int_val);}
#line 1894 "parser.tab.c"
    break;

  case 66: /* termo: ID  */
#line 232 "parser.y"
           { int end = getendereco((yyvsp[0].str_val)); printf("mov %%t%d, %%r%d\n", T, end); (yyval.int_val) = T++;}
#line 1900 "parser.tab.c"
    break;

  case 67: /* termo: NUM  */
#line 233 "parser.y"
             { printf("mov %%t%d, %d\n", T, (yyvsp[0].int_val)); (yyval.int_val) = T++; }
#line 1906 "parser.tab.c"
    break;

  case 68: /* termo: LPAR expr RPAR  */
#line 234 "parser.y"
                       { (yyval.int_val) = (yyvsp[-1].int_val); }
#line 1912 "parser.tab.c"
    break;

  case 69: /* termo: MENOS ID  */
#line 235 "parser.y"
                  { int end = getendereco((yyvsp[0].str_val)); printf("mov %%t%d, %%r%d\n", T, end); (yyval.int_val) = T++;}
#line 1918 "parser.tab.c"
    break;

  case 70: /* termo: MENOS NUM  */
#line 236 "parser.y"
                  { printf("mov %%t%d, %d\n", T, (yyvsp[0].int_val)); (yyval.int_val) = T++; }
#line 1924 "parser.tab.c"
    break;

  case 71: /* termo: ID LCOL expr RCOL  */
#line 237 "parser.y"
                          { int end = getendereco((yyvsp[-3].str_val));printf("load %%t%d, %%t%d(%d) \n",T,(yyvsp[-1].int_val),end); (yyval.int_val) = T++;}
#line 1930 "parser.tab.c"
    break;


#line 1934 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 239 "parser.y"


extern FILE *yyin;                   

void yyerror(char *s) { fprintf(stderr,"ERRO SINTATICO : %s\n", s) ;}

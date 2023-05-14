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
#line 66 "yacc.y"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"

#define trace(t) printf(">> Grammar: %s\n", t);

extern int yylineno;
extern FILE* yyin;
extern FILE* yyout;

int yylex();
void yyerror(char *s);
int yywrap();
void exitProgram();
int main(int argc, char *argv[]);

#line 92 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEWLINE = 258,                 /* NEWLINE  */
    ARRAY = 259,                   /* ARRAY  */
    BEGIN_ = 260,                  /* BEGIN_  */
    BOOL = 261,                    /* BOOL  */
    CONST = 262,                   /* CONST  */
    DECREASING = 263,              /* DECREASING  */
    DEFAULT = 264,                 /* DEFAULT  */
    DO = 265,                      /* DO  */
    ELSE = 266,                    /* ELSE  */
    END = 267,                     /* END  */
    EXIT = 268,                    /* EXIT  */
    FOR = 269,                     /* FOR  */
    FUNCTION = 270,                /* FUNCTION  */
    GET = 271,                     /* GET  */
    IF = 272,                      /* IF  */
    INT = 273,                     /* INT  */
    LOOP = 274,                    /* LOOP  */
    OF = 275,                      /* OF  */
    PUT = 276,                     /* PUT  */
    PROCEDURE = 277,               /* PROCEDURE  */
    REAL = 278,                    /* REAL  */
    RESULT = 279,                  /* RESULT  */
    RETURN = 280,                  /* RETURN  */
    SKIP = 281,                    /* SKIP  */
    STRING = 282,                  /* STRING  */
    THEN = 283,                    /* THEN  */
    VAR = 284,                     /* VAR  */
    WHEN = 285,                    /* WHEN  */
    PLUS = 286,                    /* PLUS  */
    MINUS = 287,                   /* MINUS  */
    MULTI = 288,                   /* MULTI  */
    DIVIDE = 289,                  /* DIVIDE  */
    LESS = 290,                    /* LESS  */
    MORE = 291,                    /* MORE  */
    EQUAL = 292,                   /* EQUAL  */
    TRUE = 293,                    /* TRUE  */
    FALSE = 294,                   /* FALSE  */
    NUM_REAL = 295,                /* NUM_REAL  */
    NUM_INT = 296,                 /* NUM_INT  */
    IDENT = 297,                   /* IDENT  */
    SCONST = 298,                  /* SCONST  */
    ASSIGN = 299,                  /* ASSIGN  */
    OR = 300,                      /* OR  */
    AND = 301,                     /* AND  */
    NOTEQ = 302,                   /* NOTEQ  */
    LESSEQ = 303,                  /* LESSEQ  */
    MOREEQ = 304,                  /* MOREEQ  */
    MOD = 305,                     /* MOD  */
    UMINUS = 306,                  /* UMINUS  */
    NOT = 307                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NEWLINE 258
#define ARRAY 259
#define BEGIN_ 260
#define BOOL 261
#define CONST 262
#define DECREASING 263
#define DEFAULT 264
#define DO 265
#define ELSE 266
#define END 267
#define EXIT 268
#define FOR 269
#define FUNCTION 270
#define GET 271
#define IF 272
#define INT 273
#define LOOP 274
#define OF 275
#define PUT 276
#define PROCEDURE 277
#define REAL 278
#define RESULT 279
#define RETURN 280
#define SKIP 281
#define STRING 282
#define THEN 283
#define VAR 284
#define WHEN 285
#define PLUS 286
#define MINUS 287
#define MULTI 288
#define DIVIDE 289
#define LESS 290
#define MORE 291
#define EQUAL 292
#define TRUE 293
#define FALSE 294
#define NUM_REAL 295
#define NUM_INT 296
#define IDENT 297
#define SCONST 298
#define ASSIGN 299
#define OR 300
#define AND 301
#define NOTEQ 302
#define LESSEQ 303
#define MOREEQ 304
#define MOD 305
#define UMINUS 306
#define NOT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 89 "yacc.y"

    bool b;
    double d;
    int i;
    char* s;
    symbol sy;
    ssymbol ssy;
    argument a;
    function f;

#line 260 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEWLINE = 3,                    /* NEWLINE  */
  YYSYMBOL_ARRAY = 4,                      /* ARRAY  */
  YYSYMBOL_BEGIN_ = 5,                     /* BEGIN_  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_DECREASING = 8,                 /* DECREASING  */
  YYSYMBOL_DEFAULT = 9,                    /* DEFAULT  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_END = 12,                       /* END  */
  YYSYMBOL_EXIT = 13,                      /* EXIT  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_FUNCTION = 15,                  /* FUNCTION  */
  YYSYMBOL_GET = 16,                       /* GET  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_LOOP = 19,                      /* LOOP  */
  YYSYMBOL_OF = 20,                        /* OF  */
  YYSYMBOL_PUT = 21,                       /* PUT  */
  YYSYMBOL_PROCEDURE = 22,                 /* PROCEDURE  */
  YYSYMBOL_REAL = 23,                      /* REAL  */
  YYSYMBOL_RESULT = 24,                    /* RESULT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_SKIP = 26,                      /* SKIP  */
  YYSYMBOL_STRING = 27,                    /* STRING  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_VAR = 29,                       /* VAR  */
  YYSYMBOL_WHEN = 30,                      /* WHEN  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_MULTI = 33,                     /* MULTI  */
  YYSYMBOL_DIVIDE = 34,                    /* DIVIDE  */
  YYSYMBOL_LESS = 35,                      /* LESS  */
  YYSYMBOL_MORE = 36,                      /* MORE  */
  YYSYMBOL_EQUAL = 37,                     /* EQUAL  */
  YYSYMBOL_TRUE = 38,                      /* TRUE  */
  YYSYMBOL_FALSE = 39,                     /* FALSE  */
  YYSYMBOL_NUM_REAL = 40,                  /* NUM_REAL  */
  YYSYMBOL_NUM_INT = 41,                   /* NUM_INT  */
  YYSYMBOL_IDENT = 42,                     /* IDENT  */
  YYSYMBOL_SCONST = 43,                    /* SCONST  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_ASSIGN = 45,                    /* ASSIGN  */
  YYSYMBOL_OR = 46,                        /* OR  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_NOTEQ = 48,                     /* NOTEQ  */
  YYSYMBOL_LESSEQ = 49,                    /* LESSEQ  */
  YYSYMBOL_MOREEQ = 50,                    /* MOREEQ  */
  YYSYMBOL_MOD = 51,                       /* MOD  */
  YYSYMBOL_UMINUS = 52,                    /* UMINUS  */
  YYSYMBOL_NOT = 53,                       /* NOT  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_progdecl = 62,                  /* progdecl  */
  YYSYMBOL_statement_part = 63,            /* statement_part  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_block = 65,                     /* block  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_67_2 = 67,                      /* $@2  */
  YYSYMBOL_simple = 68,                    /* simple  */
  YYSYMBOL_conditional = 69,               /* conditional  */
  YYSYMBOL_70_3 = 70,                      /* $@3  */
  YYSYMBOL_71_4 = 71,                      /* $@4  */
  YYSYMBOL_if_front = 72,                  /* if_front  */
  YYSYMBOL_73_5 = 73,                      /* $@5  */
  YYSYMBOL_loop = 74,                      /* loop  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_77_8 = 77,                      /* $@8  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_for_option = 79,                /* for_option  */
  YYSYMBOL_body = 80,                      /* body  */
  YYSYMBOL_constdec = 81,                  /* constdec  */
  YYSYMBOL_vardec = 82,                    /* vardec  */
  YYSYMBOL_decopt = 83,                    /* decopt  */
  YYSYMBOL_arrdec = 84,                    /* arrdec  */
  YYSYMBOL_funcdec = 85,                   /* funcdec  */
  YYSYMBOL_86_10 = 86,                     /* $@10  */
  YYSYMBOL_87_11 = 87,                     /* $@11  */
  YYSYMBOL_88_12 = 88,                     /* $@12  */
  YYSYMBOL_procdec = 89,                   /* procdec  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_91_14 = 91,                     /* $@14  */
  YYSYMBOL_92_15 = 92,                     /* $@15  */
  YYSYMBOL_arguments = 93,                 /* arguments  */
  YYSYMBOL_argument_list = 94,             /* argument_list  */
  YYSYMBOL_argument = 95,                  /* argument  */
  YYSYMBOL_vtype = 96,                     /* vtype  */
  YYSYMBOL_expr = 97,                      /* expr  */
  YYSYMBOL_term = 98,                      /* term  */
  YYSYMBOL_arr_ref = 99,                   /* arr_ref  */
  YYSYMBOL_call = 100,                     /* call  */
  YYSYMBOL_cargs = 101,                    /* cargs  */
  YYSYMBOL_carg_list = 102                 /* carg_list  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      54,    55,     2,     2,    44,     2,    59,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    45,
      46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   131,   132,   133,   134,   135,   136,   137,
     140,   141,   142,   146,   147,   148,   149,   150,   154,   154,
     154,   158,   181,   193,   194,   195,   200,   201,   202,   210,
     214,   215,   213,   217,   220,   220,   230,   231,   230,   233,
     252,   233,   255,   255,   259,   260,   261,   262,   263,   264,
     268,   297,   323,   344,   345,   348,   368,   381,   391,   368,
     405,   418,   427,   405,   440,   450,   457,   467,   474,   497,
     530,   531,   532,   533,   539,   545,   551,   557,   563,   569,
     575,   581,   587,   593,   611,   629,   640,   651,   655,   656,
     662,   668,   672,   673,   691,   692,   693,   694,   695,   698,
     722,   741,   761,   779
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
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "ARRAY",
  "BEGIN_", "BOOL", "CONST", "DECREASING", "DEFAULT", "DO", "ELSE", "END",
  "EXIT", "FOR", "FUNCTION", "GET", "IF", "INT", "LOOP", "OF", "PUT",
  "PROCEDURE", "REAL", "RESULT", "RETURN", "SKIP", "STRING", "THEN", "VAR",
  "WHEN", "PLUS", "MINUS", "MULTI", "DIVIDE", "LESS", "MORE", "EQUAL",
  "TRUE", "FALSE", "NUM_REAL", "NUM_INT", "IDENT", "SCONST", "','",
  "ASSIGN", "OR", "AND", "NOTEQ", "LESSEQ", "MOREEQ", "MOD", "UMINUS",
  "NOT", "'('", "')'", "'['", "']'", "':'", "'.'", "$accept", "program",
  "progdecl", "statement_part", "statement", "block", "$@1", "$@2",
  "simple", "conditional", "$@3", "$@4", "if_front", "$@5", "loop", "$@6",
  "$@7", "$@8", "$@9", "for_option", "body", "constdec", "vardec",
  "decopt", "arrdec", "funcdec", "$@10", "$@11", "$@12", "procdec", "$@13",
  "$@14", "$@15", "arguments", "argument_list", "argument", "vtype",
  "expr", "term", "arr_ref", "call", "cargs", "carg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -62,     5,    11,   -62,   -62,   -11,     6,     8,    12,   106,
      72,    82,    86,    93,   100,   -49,   -62,   -62,    15,   -62,
     -62,    74,    97,    64,   262,   -62,   262,   262,   -62,   -62,
     262,   -62,   -62,   -62,   -62,   -33,   -62,   262,   262,   104,
     -62,   -62,   -62,    41,   -62,   275,   -62,    63,   -62,   -62,
     -62,   -62,   -62,   -62,    70,    69,    58,    58,     7,    79,
     -62,   262,   -62,    71,   -62,   -17,   242,   -62,   -62,   275,
     275,   -62,   262,   -62,   262,   -62,   -62,   217,   -62,   -62,
      98,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   -62,   -62,   -62,   -62,   -62,
     262,   -62,    59,   123,    87,    90,   262,     3,   275,    78,
     -62,     3,   275,   262,   165,   -62,   -62,   -62,    67,    67,
     -62,   -62,    48,    48,    48,   296,   303,    48,    48,    48,
     -62,   275,   275,    95,    70,   -62,    80,   275,   -62,   138,
     139,   140,   147,   150,   262,   -62,   142,   192,   -62,     3,
     111,    -8,   152,   -62,    99,   -62,   -62,   -62,   -62,   -62,
     158,     3,   137,   -62,   -62,   159,    68,   -62,   -62,   -62,
       3,   129,   113,   -62,   156,   134,   -62,   -62,   164,   163,
     262,   -62,   125,     3,   143,    70,   131,   127,   175,   -62,
     -62,   -62,   162,   168,   -62,   198,   -62,     3,    70,   207,
     -62,   206,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       9,     0,    12,     1,     8,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,    54,    56,    60,    54,    11,
      18,    27,    43,     0,     0,    36,     0,     0,    26,    29,
       0,    97,    98,    95,    94,    93,    96,     0,     0,     0,
      13,    14,    16,     0,    17,    15,    87,    91,    92,     3,
       4,     5,     6,     7,     0,     0,    65,    65,     0,     0,
      49,     0,    42,     0,    24,    93,     0,    91,    49,    23,
      25,    89,     0,   103,     0,   100,    90,     0,    10,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    72,    71,    73,    53,
       0,    67,     0,     0,     0,    52,     0,    19,    28,     0,
      34,    37,    21,     0,     0,    88,    49,    33,    75,    74,
      76,    77,    79,    80,    83,    86,    85,    84,    81,    82,
      78,    22,    50,     0,     0,    61,     0,    51,    48,     0,
       0,     0,     0,     0,     0,    49,     0,     0,    99,    31,
       0,     0,     0,    49,     0,    47,    20,    44,    45,    46,
       0,    35,     0,   102,   101,     0,     0,    66,    64,    57,
      62,     0,     0,    38,     0,     0,    68,    49,     0,     0,
       0,    32,     0,    58,     0,     0,     0,     0,     0,    63,
      55,    39,     0,     0,    49,     0,    59,    40,     0,     0,
      69,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   -62,   212,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -61,   228,   229,   214,   231,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   177,   -62,   -62,   -56,   -23,    57,    -9,
     -62,   -62,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     9,   139,    40,    60,   140,    41,    42,
     116,   165,    43,   145,    44,    68,   146,   194,   199,    63,
     107,   141,   142,    55,   143,    13,    56,   177,   188,    14,
      57,   153,   178,   102,   133,   151,    99,    45,    46,    67,
      48,    75,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    66,   105,    69,    70,     3,   138,   111,    20,    54,
       5,   104,    72,    95,     4,    77,    21,    22,     5,    23,
      24,    73,    25,    74,    26,    96,     6,    27,    28,    29,
      97,    15,     8,     7,    98,    30,   167,    73,   108,    74,
       8,    31,    32,    33,    34,    35,    36,   168,    16,   112,
      17,   114,    79,    80,    18,   149,    37,    38,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   175,    58,    95,    49,    95,   132,   152,    81,
      82,    83,    84,   137,   161,    50,    96,    71,    96,    51,
     147,    97,   170,    97,    76,    98,    52,    98,    47,    93,
      83,    84,    47,    53,    61,    62,    64,    78,    94,    19,
     176,    20,   101,   109,   100,   117,   183,   134,    93,    21,
      22,   160,    23,    24,   106,    25,   135,    26,   136,   190,
      27,    28,    29,   197,   191,   -53,   144,   150,    30,   154,
      47,   155,   200,   157,    31,    32,    33,    34,    35,    36,
     158,   156,    47,   159,   162,   169,   173,   186,   171,    37,
      38,    47,    81,    82,    83,    84,    85,    86,    87,   166,
     179,   174,   180,   181,    47,   182,   184,    88,    89,    90,
      91,    92,    93,   185,   187,   189,   192,   193,    47,    81,
      82,    83,    84,    85,    86,    87,    81,    82,    83,    84,
      85,    86,    87,   195,    88,    89,    90,    91,    92,    93,
     196,    88,    89,    90,    91,    92,    93,   172,   198,   201,
     202,    39,   148,    81,    82,    83,    84,    85,    86,    87,
      10,    11,    59,    12,   103,     0,   163,     0,    88,    89,
      90,    91,    92,    93,     0,     0,     0,   164,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,     0,
     110,     0,   115,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    30,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    65,    36,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    37,    38,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,    81,    82,    83,
      84,    85,    86,    87,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    89,    90,    91,    92,    93,     0,     0,
       0,    90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
       9,    24,    58,    26,    27,     0,     3,    68,     5,    58,
       7,     4,    45,     6,     3,    38,    13,    14,     7,    16,
      17,    54,    19,    56,    21,    18,    15,    24,    25,    26,
      23,    42,    29,    22,    27,    32,    44,    54,    61,    56,
      29,    38,    39,    40,    41,    42,    43,    55,    42,    72,
      42,    74,    11,    12,    42,   116,    53,    54,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     4,    58,     6,     3,     6,   100,   134,    31,
      32,    33,    34,   106,   145,     3,    18,    30,    18,     3,
     113,    23,   153,    23,    37,    27,     3,    27,   107,    51,
      33,    34,   111,     3,    30,     8,    42,     3,    45,     3,
     166,     5,    54,    42,    45,    17,   177,    58,    51,    13,
      14,   144,    16,    17,    45,    19,     3,    21,    41,   185,
      24,    25,    26,   194,     3,    45,    58,    42,    32,    59,
     149,     3,   198,     3,    38,    39,    40,    41,    42,    43,
       3,    12,   161,     3,    12,     3,    19,   180,    59,    53,
      54,   170,    31,    32,    33,    34,    35,    36,    37,    58,
      41,    12,    59,    17,   183,    41,    12,    46,    47,    48,
      49,    50,    51,    20,    59,    42,    59,    12,   197,    31,
      32,    33,    34,    35,    36,    37,    31,    32,    33,    34,
      35,    36,    37,    41,    46,    47,    48,    49,    50,    51,
      42,    46,    47,    48,    49,    50,    51,    59,    20,    12,
      14,     9,    57,    31,    32,    33,    34,    35,    36,    37,
       2,     2,    18,     2,    57,    -1,    44,    -1,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    55,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    -1,
      28,    -1,    55,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    31,    32,    33,
      34,    35,    36,    37,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    48,    49,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,    62,     0,     3,     7,    15,    22,    29,    63,
      81,    82,    84,    85,    89,    42,    42,    42,    42,     3,
       5,    13,    14,    16,    17,    19,    21,    24,    25,    26,
      32,    38,    39,    40,    41,    42,    43,    53,    54,    64,
      65,    68,    69,    72,    74,    97,    98,    99,   100,     3,
       3,     3,     3,     3,    58,    83,    86,    90,    58,    83,
      66,    30,     8,    79,    42,    42,    97,    99,    75,    97,
      97,    98,    45,    54,    56,   101,    98,    97,     3,    11,
      12,    31,    32,    33,    34,    35,    36,    37,    46,    47,
      48,    49,    50,    51,    45,     6,    18,    23,    27,    96,
      45,    54,    93,    93,     4,    96,    45,    80,    97,    42,
      28,    80,    97,   102,    97,    55,    70,    17,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    94,    58,     3,    41,    97,     3,    64,
      67,    81,    82,    84,    58,    73,    76,    97,    57,    80,
      42,    95,    96,    91,    59,     3,    12,     3,     3,     3,
      97,    80,    12,    44,    55,    71,    58,    44,    55,     3,
      80,    59,    59,    19,    12,     4,    96,    87,    92,    41,
      59,    17,    41,    80,    12,    20,    97,    59,    88,    42,
      96,     3,    59,    12,    77,    41,    42,    80,    20,    78,
      96,    12,    14
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    64,    66,    67,
      65,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      70,    71,    69,    69,    73,    72,    75,    76,    74,    77,
      78,    74,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    82,    82,    83,    83,    84,    86,    87,    88,    85,
      90,    91,    92,    89,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
     100,   101,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     3,     2,     0,
       3,     2,     0,     1,     1,     1,     1,     1,     0,     0,
       5,     3,     3,     2,     2,     2,     1,     1,     3,     1,
       0,     0,     7,     3,     0,     5,     0,     0,     6,     0,
       0,    14,     1,     0,     3,     3,     3,     3,     2,     0,
       5,     5,     4,     2,     0,    10,     0,     0,     0,    12,
       0,     0,     0,    10,     4,     0,     3,     0,     3,     9,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     4,     3,     0
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
  case 13: /* statement: block  */
#line 146 "yacc.y"
                  { (yyval.i) = tNull; }
#line 1512 "y.tab.c"
    break;

  case 14: /* statement: simple  */
#line 147 "yacc.y"
                   { (yyval.i) = (yyvsp[0].i); }
#line 1518 "y.tab.c"
    break;

  case 15: /* statement: expr  */
#line 148 "yacc.y"
                 { (yyval.i) = tNull; }
#line 1524 "y.tab.c"
    break;

  case 16: /* statement: conditional  */
#line 149 "yacc.y"
                        { (yyval.i) = tNull; }
#line 1530 "y.tab.c"
    break;

  case 17: /* statement: loop  */
#line 150 "yacc.y"
                 { (yyval.i) = tNull; }
#line 1536 "y.tab.c"
    break;

  case 18: /* $@1: %empty  */
#line 154 "yacc.y"
               { addScope(); }
#line 1542 "y.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 154 "yacc.y"
                                    { deleteScope(); }
#line 1548 "y.tab.c"
    break;

  case 21: /* simple: IDENT ASSIGN expr  */
#line 158 "yacc.y"
                           {
            char* name = (yyvsp[-2].s);
            ssymbol ssy = (yyvsp[0].ssy);

            symbol* sy = lookup(name);

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            
            if (sy->type != tVar)
                yyerror("Trying to assign a value to a non-variable");
            
            if (sy->isConst)
                yyerror("Trying to assign a value to a constant");
            
            if (ssy.type == tArr)
                yyerror("Trying to assign an array to a variable");
            
            if (sy->valType != ssy.valType)
                yyerror("Conflicting assignment types");
            
            (yyval.i) = tNull;
       }
#line 1576 "y.tab.c"
    break;

  case 22: /* simple: arr_ref ASSIGN expr  */
#line 181 "yacc.y"
                             {
            symbol sy = (yyvsp[-2].sy);
            ssymbol ssy = (yyvsp[0].ssy);

            if (ssy.type == tArr)
                yyerror("Trying to assign an array to a variable");

            if (sy.valType != ssy.valType)
                yyerror("Conflicting assignment types");
            
            (yyval.i) = tNull;
       }
#line 1593 "y.tab.c"
    break;

  case 23: /* simple: PUT expr  */
#line 193 "yacc.y"
                  { (yyval.i) = tNull; }
#line 1599 "y.tab.c"
    break;

  case 24: /* simple: GET IDENT  */
#line 194 "yacc.y"
                   { (yyval.i) = tNull; }
#line 1605 "y.tab.c"
    break;

  case 25: /* simple: RESULT expr  */
#line 195 "yacc.y"
                     {
            if ((yyvsp[0].ssy).type == tArr)
                yyerror("Invalid result expression: array");
            (yyval.i) = (yyvsp[0].ssy).valType;
       }
#line 1615 "y.tab.c"
    break;

  case 26: /* simple: RETURN  */
#line 200 "yacc.y"
                { (yyval.i) = tNull; }
#line 1621 "y.tab.c"
    break;

  case 27: /* simple: EXIT  */
#line 201 "yacc.y"
              { (yyval.i) = tNull; }
#line 1627 "y.tab.c"
    break;

  case 28: /* simple: EXIT WHEN expr  */
#line 202 "yacc.y"
                        {
            if ((yyvsp[0].ssy).type == tArr)
                yyerror("Trying to assign an array to a conditional");
            if ((yyvsp[0].ssy).valType != tBool)
                yyerror("Trying to assign a non-boolean expression to a conditional");
            
            (yyval.i) = tNull;
       }
#line 1640 "y.tab.c"
    break;

  case 29: /* simple: SKIP  */
#line 210 "yacc.y"
              { (yyval.i) = tNull; }
#line 1646 "y.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 214 "yacc.y"
                   { addScope(); }
#line 1652 "y.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 215 "yacc.y"
                   { deleteScope(); }
#line 1658 "y.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 220 "yacc.y"
                        {
                addScope();
                if ((yyvsp[-1].ssy).type == tArr)
                    yyerror("Trying to assign an array to a conditional");
                if ((yyvsp[-1].ssy).valType != tBool)
                    yyerror("Trying to assign a non-boolean expression to a conditional");
           }
#line 1670 "y.tab.c"
    break;

  case 35: /* if_front: IF expr THEN $@5 body  */
#line 227 "yacc.y"
                { deleteScope(); }
#line 1676 "y.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 230 "yacc.y"
            { addScope(); }
#line 1682 "y.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 231 "yacc.y"
            { deleteScope(); }
#line 1688 "y.tab.c"
    break;

  case 39: /* $@8: %empty  */
#line 233 "yacc.y"
                                                          {
            if ((yyvsp[-4].ssy).valType != tInt || (yyvsp[-1].ssy).valType != tInt ||
                !(yyvsp[-4].ssy).isConst || !(yyvsp[-1].ssy).isConst ||
                (yyvsp[-4].ssy).type == tArr || (yyvsp[-1].ssy).type == tArr)
                yyerror("Invalid for loop range, perhaps it's not numeric or constant?");
            
            char* name = (yyvsp[-6].s);

            symbol* sy = lookup(name);

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            if (sy->isConst)
                yyerror("Iterator cannot be constant");
            if (sy->type != tVar || !(sy->type == tInt || sy->type == tReal))
                yyerror("Iterator must be a numeric variable");

            addScope();
       }
#line 1712 "y.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 252 "yacc.y"
            { deleteScope(); }
#line 1718 "y.tab.c"
    break;

  case 44: /* body: body constdec NEWLINE  */
#line 259 "yacc.y"
                              { (yyval.i) = (yyvsp[-2].i); }
#line 1724 "y.tab.c"
    break;

  case 45: /* body: body vardec NEWLINE  */
#line 260 "yacc.y"
                            { (yyval.i) = (yyvsp[-2].i); }
#line 1730 "y.tab.c"
    break;

  case 46: /* body: body arrdec NEWLINE  */
#line 261 "yacc.y"
                            { (yyval.i) = (yyvsp[-2].i); }
#line 1736 "y.tab.c"
    break;

  case 47: /* body: body statement NEWLINE  */
#line 262 "yacc.y"
                               { (yyval.i) = (yyvsp[-1].i); }
#line 1742 "y.tab.c"
    break;

  case 48: /* body: body NEWLINE  */
#line 263 "yacc.y"
                     { (yyval.i) = (yyvsp[-1].i); }
#line 1748 "y.tab.c"
    break;

  case 49: /* body: %empty  */
#line 264 "yacc.y"
       { (yyval.i) = tNull; }
#line 1754 "y.tab.c"
    break;

  case 50: /* constdec: CONST IDENT decopt ASSIGN expr  */
#line 268 "yacc.y"
                                          {
            char* name = (yyvsp[-3].s);
            int valType = (yyvsp[-2].i);
            ssymbol ssy = (yyvsp[0].ssy);

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            if (valType == tImplicit)
                valType = ssy.valType;
            else if (valType != ssy.valType) {
                if (!isBothNumber(valType, ssy.valType))
                    yyerror("Mismatching declaration type and value type");
            }

            if (!ssy.isConst)
                yyerror("Trying to assign non-constant expression to a constant declaration");

            symbol sy = createSymbol(name, tVar, ssy);
            sy.isConst = true;

            insertSymbol(sy, idx);
        }
#line 1785 "y.tab.c"
    break;

  case 51: /* vardec: VAR IDENT decopt ASSIGN expr  */
#line 297 "yacc.y"
                                      {
            char* name = (yyvsp[-3].s);
            int valType = (yyvsp[-2].i);
            ssymbol ssy = (yyvsp[0].ssy);

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            if (valType == tImplicit)
                valType = ssy.valType;
            else if (valType != ssy.valType) {
                if (!isBothNumber(valType, ssy.valType))
                    yyerror("Mismatching declaration type and value type");
            }

            if (!ssy.isConst)
                yyerror("Trying to assign non-constant expression to a variable declaration");

            symbol sy = createSymbol(name, tVar, ssy);
            sy.isConst = false;

            insertSymbol(sy, idx);
       }
#line 1816 "y.tab.c"
    break;

  case 52: /* vardec: VAR IDENT ':' vtype  */
#line 323 "yacc.y"
                             {
            char* name = (yyvsp[-2].s);
            int valType = (yyvsp[0].i);

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            ssymbol ssy;
            ssy.valType = valType;

            symbol sy = createSymbol(name, tVar, ssy);
            sy.isConst = false;

            insertSymbol(sy, idx);
       }
#line 1839 "y.tab.c"
    break;

  case 53: /* decopt: ':' vtype  */
#line 344 "yacc.y"
                   { (yyval.i) = (yyvsp[0].i); }
#line 1845 "y.tab.c"
    break;

  case 54: /* decopt: %empty  */
#line 345 "yacc.y"
         { (yyval.i) = tImplicit; }
#line 1851 "y.tab.c"
    break;

  case 55: /* arrdec: VAR IDENT ':' ARRAY NUM_INT '.' '.' NUM_INT OF vtype  */
#line 348 "yacc.y"
                                                              {
            char* name = (yyvsp[-8].s);
            int first = (yyvsp[-5].i), last = (yyvsp[-2].i);
            int valType = (yyvsp[0].i);

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            if (first >= last)
                yyerror("Attempted to create an array of invalid size");

            symbol sy = createArray(name, valType, first, last);

            insertSymbol(sy, idx);
       }
#line 1874 "y.tab.c"
    break;

  case 56: /* $@10: %empty  */
#line 368 "yacc.y"
                         {
            char* name = (yyvsp[0].s);
            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            symbol sy = createEmptyFunction(name, false);
            insertSymbol(sy, idx);

            addScope();

          }
#line 1893 "y.tab.c"
    break;

  case 57: /* $@11: %empty  */
#line 381 "yacc.y"
                                        {
            function f = (yyvsp[-3].f);
            int valType = (yyvsp[-1].i);

            symbol* sy = lookup((yyvsp[-5].s));
            sy->valType = valType;
            copyFunction(f, sy->val.f);

            addScope(); 
          }
#line 1908 "y.tab.c"
    break;

  case 58: /* $@12: %empty  */
#line 391 "yacc.y"
               {
            int valType = (yyvsp[-3].i);
            int returnType = (yyvsp[0].i);
            if (valType != returnType)
                yyerror("Function must have correct result type");

            deleteScope(); deleteScope();
          }
#line 1921 "y.tab.c"
    break;

  case 59: /* funcdec: FUNCTION IDENT $@10 arguments ':' vtype NEWLINE $@11 body $@12 END IDENT  */
#line 399 "yacc.y"
                    {
                if (strcmp((yyvsp[-10].s), (yyvsp[0].s)) != 0)
                    yyerror("End function name does not match");
          }
#line 1930 "y.tab.c"
    break;

  case 60: /* $@13: %empty  */
#line 405 "yacc.y"
                          {
            char* name = (yyvsp[0].s);
            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            symbol sy = createEmptyFunction(name, true);
            insertSymbol(sy, idx);

            addScope();

          }
#line 1949 "y.tab.c"
    break;

  case 61: /* $@14: %empty  */
#line 418 "yacc.y"
                              {
            function f = (yyvsp[-1].f);

            symbol* sy = lookup((yyvsp[-3].s));
            sy->valType = tNull;
            copyFunction(f, sy->val.f);

            addScope(); 
          }
#line 1963 "y.tab.c"
    break;

  case 62: /* $@15: %empty  */
#line 427 "yacc.y"
               {
            int returnType = (yyvsp[0].i);
            if (returnType != tNull)
                yyerror("Procedure cannot have result type");

            deleteScope(); deleteScope();
          }
#line 1975 "y.tab.c"
    break;

  case 63: /* procdec: PROCEDURE IDENT $@13 arguments NEWLINE $@14 body $@15 END IDENT  */
#line 434 "yacc.y"
                    {
                if (strcmp((yyvsp[-8].s), (yyvsp[0].s)) != 0)
                    yyerror("End function name does not match");
          }
#line 1984 "y.tab.c"
    break;

  case 64: /* arguments: '(' argument_list argument ')'  */
#line 440 "yacc.y"
                                           {
                function f = (yyvsp[-2].f);
                f.argsize++;
                if (f.argsize == 1)
                    f.args = malloc(sizeof(argument));
                else
                    f.args = realloc(f.args, f.argsize * sizeof(argument));
                f.args[f.argsize - 1] = (yyvsp[-1].a);
                (yyval.f) = f;
          }
#line 1999 "y.tab.c"
    break;

  case 65: /* arguments: %empty  */
#line 450 "yacc.y"
            {
                function f;
                f.argsize = 0;
                (yyval.f) = f;
          }
#line 2009 "y.tab.c"
    break;

  case 66: /* argument_list: argument_list argument ','  */
#line 457 "yacc.y"
                                           {
                    function f = (yyvsp[-2].f);
                    f.argsize++;
                    if (f.argsize == 1)
                        f.args = malloc(sizeof(argument));
                    else
                        f.args = realloc(f.args, f.argsize * sizeof(argument));
                    f.args[f.argsize - 1] = (yyvsp[-1].a);
                    (yyval.f) = f;
              }
#line 2024 "y.tab.c"
    break;

  case 67: /* argument_list: %empty  */
#line 467 "yacc.y"
                {
                    function f;
                    f.argsize = 0;
                    (yyval.f) = f;
              }
#line 2034 "y.tab.c"
    break;

  case 68: /* argument: IDENT ':' vtype  */
#line 474 "yacc.y"
                           {
            char* name = (yyvsp[-2].s);
            int valType = (yyvsp[0].i);

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            argument a;
            a.type = tVar;
            a.valType = valType;       
            
            ssymbol ssy;
            ssy.valType = valType;
            ssy.isConst = false;

            symbol sy = createSymbol(name, tVar, ssy);
            insertSymbol(sy, idx);

            (yyval.a) = a;
         }
#line 2062 "y.tab.c"
    break;

  case 69: /* argument: IDENT ':' ARRAY NUM_INT '.' '.' NUM_INT OF vtype  */
#line 497 "yacc.y"
                                                            {
            char* name = (yyvsp[-8].s);
            int first = (yyvsp[-5].i), last = (yyvsp[-2].i);
            int valType = (yyvsp[0].i);

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            argument a;
            a.type = tArr;
            a.valType = valType;
            a.val.a = malloc(sizeof(array));

            a.val.a->first = first;
            a.val.a->last = last;
            a.val.a->size = last - first + 1;
            
            ssymbol ssy;
            ssy.type = a.type;
            ssy.valType = valType;
            ssy.isConst = false;
            ssy.val.a = a.val.a;

            symbol sy = createSymbol(name, tArr, ssy);
            insertSymbol(sy, idx);

            (yyval.a) = a;
         }
#line 2098 "y.tab.c"
    break;

  case 70: /* vtype: BOOL  */
#line 530 "yacc.y"
             { (yyval.i) = tBool; }
#line 2104 "y.tab.c"
    break;

  case 71: /* vtype: REAL  */
#line 531 "yacc.y"
             { (yyval.i) = tReal; }
#line 2110 "y.tab.c"
    break;

  case 72: /* vtype: INT  */
#line 532 "yacc.y"
            { (yyval.i) = tInt; }
#line 2116 "y.tab.c"
    break;

  case 73: /* vtype: STRING  */
#line 533 "yacc.y"
                { (yyval.i) = tString; }
#line 2122 "y.tab.c"
    break;

  case 74: /* expr: expr MINUS expr  */
#line 539 "yacc.y"
                       {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oMin);
     }
#line 2133 "y.tab.c"
    break;

  case 75: /* expr: expr PLUS expr  */
#line 545 "yacc.y"
                      {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oPlus);
     }
#line 2144 "y.tab.c"
    break;

  case 76: /* expr: expr MULTI expr  */
#line 551 "yacc.y"
                       {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oMul);
     }
#line 2155 "y.tab.c"
    break;

  case 77: /* expr: expr DIVIDE expr  */
#line 557 "yacc.y"
                        {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oDiv);
     }
#line 2166 "y.tab.c"
    break;

  case 78: /* expr: expr MOD expr  */
#line 563 "yacc.y"
                     {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oMod);
     }
#line 2177 "y.tab.c"
    break;

  case 79: /* expr: expr LESS expr  */
#line 569 "yacc.y"
                      {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oLess);
     }
#line 2188 "y.tab.c"
    break;

  case 80: /* expr: expr MORE expr  */
#line 575 "yacc.y"
                      {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oMore);
     }
#line 2199 "y.tab.c"
    break;

  case 81: /* expr: expr LESSEQ expr  */
#line 581 "yacc.y"
                        {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oLessEq);
     }
#line 2210 "y.tab.c"
    break;

  case 82: /* expr: expr MOREEQ expr  */
#line 587 "yacc.y"
                        {
        if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType) || (yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oMoreEq);
     }
#line 2221 "y.tab.c"
    break;

  case 83: /* expr: expr EQUAL expr  */
#line 593 "yacc.y"
                       {
        if ((yyvsp[-2].ssy).valType != (yyvsp[0].ssy).valType) {
            if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType))
                yyerror("Illegal comparison, both operands have different value types");
        }
        if ((yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is an array");

        if (isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType))
            (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oEqual);
        else {
            (yyval.ssy) = (yyvsp[-2].ssy);
            (yyval.ssy).valType = tBool;
        }

        if (!(yyvsp[-2].ssy).isConst || !(yyvsp[0].ssy).isConst)
            (yyval.ssy).isConst = false;
     }
#line 2244 "y.tab.c"
    break;

  case 84: /* expr: expr NOTEQ expr  */
#line 611 "yacc.y"
                       {
        if ((yyvsp[-2].ssy).valType != (yyvsp[0].ssy).valType) {
            if (!isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType))
                yyerror("Illegal comparison, both operands have different value types");
        }
        if ((yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is an array");

        if (isBothNumber((yyvsp[-2].ssy).valType, (yyvsp[0].ssy).valType))
            (yyval.ssy) = opNumber((yyvsp[-2].ssy), (yyvsp[0].ssy), oNotEq);
        else {
            (yyval.ssy) = (yyvsp[-2].ssy);
            (yyval.ssy).valType = tBool;
        }

        if (!(yyvsp[-2].ssy).isConst || !(yyvsp[0].ssy).isConst)
            (yyval.ssy).isConst = false;
     }
#line 2267 "y.tab.c"
    break;

  case 85: /* expr: expr AND expr  */
#line 629 "yacc.y"
                     {
        if ((yyvsp[-2].ssy).valType != tBool || (yyvsp[0].ssy).valType != tBool)
            yyerror("Illegal boolean operation, an operand is not a boolean");
        if ((yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is an array");
        
        (yyval.ssy) = (yyvsp[-2].ssy);

        if (!(yyvsp[-2].ssy).isConst || !(yyvsp[0].ssy).isConst)
            (yyval.ssy).isConst = false;
     }
#line 2283 "y.tab.c"
    break;

  case 86: /* expr: expr OR expr  */
#line 640 "yacc.y"
                    {
        if ((yyvsp[-2].ssy).valType != tBool || (yyvsp[0].ssy).valType != tBool)
            yyerror("Illegal boolean operation, an operand is not a boolean");
        if ((yyvsp[-2].ssy).type == tArr || (yyvsp[0].ssy).type == tArr)
            yyerror("Illegal comparison, an operand is an array");
        
        (yyval.ssy) = (yyvsp[-2].ssy);

        if (!(yyvsp[-2].ssy).isConst || !(yyvsp[0].ssy).isConst)
            (yyval.ssy).isConst = false;
     }
#line 2299 "y.tab.c"
    break;

  case 87: /* expr: term  */
#line 651 "yacc.y"
            { (yyval.ssy) = (yyvsp[0].ssy); }
#line 2305 "y.tab.c"
    break;

  case 88: /* term: '(' expr ')'  */
#line 655 "yacc.y"
                    { (yyval.ssy) = (yyvsp[-1].ssy); }
#line 2311 "y.tab.c"
    break;

  case 89: /* term: MINUS term  */
#line 656 "yacc.y"
                               {
        if ((yyvsp[0].ssy).valType != tInt && (yyvsp[0].ssy).valType != tReal)
            yyerror("Illegal unary operation, attempted to negate a non-integer");
        
        (yyval.ssy) = (yyvsp[0].ssy);
     }
#line 2322 "y.tab.c"
    break;

  case 90: /* term: NOT term  */
#line 662 "yacc.y"
                {
        if ((yyvsp[0].ssy).valType != tBool)
            yyerror("Illegal unary operation, attempted to negate a non-boolean");
        
        (yyval.ssy) = (yyvsp[0].ssy);
     }
#line 2333 "y.tab.c"
    break;

  case 91: /* term: arr_ref  */
#line 668 "yacc.y"
               { 
        (yyval.ssy) = symbolToSmall((yyvsp[0].sy));
        (yyval.ssy).type = tVar;
     }
#line 2342 "y.tab.c"
    break;

  case 92: /* term: call  */
#line 672 "yacc.y"
            { (yyval.ssy) = (yyvsp[0].ssy); }
#line 2348 "y.tab.c"
    break;

  case 93: /* term: IDENT  */
#line 673 "yacc.y"
             {
        symbol* sy = lookup((yyvsp[0].s));

        if (sy == NULL)
            yyerror("Unrecognized identifier");
        
        if (sy->type == tProc)
            yyerror("Illegal expression, identifier has no return type");
        
        if (sy->type == tFunc) {
            if (sy->val.f->argsize > 0) {
                fprintf(stderr, "Syntax error in line %d: Invalid function invocation, expected %d arguments but called with %d\n", yylineno, sy->val.f->argsize, 0);
                exitProgram();
            }
        }

        (yyval.ssy) = symbolToSmall(*sy);
     }
#line 2371 "y.tab.c"
    break;

  case 94: /* term: NUM_INT  */
#line 691 "yacc.y"
                { (yyval.ssy) = createInt((yyvsp[0].i), true); }
#line 2377 "y.tab.c"
    break;

  case 95: /* term: NUM_REAL  */
#line 692 "yacc.y"
                 { (yyval.ssy) = createInt((yyvsp[0].d), true); }
#line 2383 "y.tab.c"
    break;

  case 96: /* term: SCONST  */
#line 693 "yacc.y"
               { (yyval.ssy) = createString((yyvsp[0].s), true); }
#line 2389 "y.tab.c"
    break;

  case 97: /* term: TRUE  */
#line 694 "yacc.y"
            { (yyval.ssy) = createBool((yyvsp[0].b), true); }
#line 2395 "y.tab.c"
    break;

  case 98: /* term: FALSE  */
#line 695 "yacc.y"
             { (yyval.ssy) = createBool((yyvsp[0].b), true); }
#line 2401 "y.tab.c"
    break;

  case 99: /* arr_ref: IDENT '[' expr ']'  */
#line 698 "yacc.y"
                             {
            symbol* sy = lookup((yyvsp[-3].s));

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            
            if (sy->type != tArr)
                yyerror("Illegal operation, trying to access a non-array as an array");
            
            ssymbol ssy = (yyvsp[-1].ssy);

            if (ssy.type == tArr || ssy.valType != tInt)
                yyerror("Illegal array reference, expression inside [] must be an integer");

            // Temporary closed, this HW does not store value
            //if (idx < sy->val.a->first || idx > sy->val.a->last)
            //    yyerror("Illegal access, array index out of bounds");
            
            // Temporary
            (yyval.sy) = *sy;
            (yyval.sy).type = tVar;
        }
#line 2428 "y.tab.c"
    break;

  case 100: /* call: IDENT cargs  */
#line 722 "yacc.y"
                   {
            symbol* sy = lookup((yyvsp[-1].s));

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            
            if (sy->type != tFunc && sy->type != tProc)
                yyerror("Trying to call a non-function identifier");

            function originalF = *(sy->val.f);
            function passedF = (yyvsp[0].f);

            if (!isFuncEqual(originalF, passedF))
                yyerror("Invalid function invocation, possible reasons are invalid argument size, type, or array bounds");
            
            (yyval.ssy) = symbolToSmall(*sy);
     }
#line 2450 "y.tab.c"
    break;

  case 101: /* cargs: '(' carg_list expr ')'  */
#line 741 "yacc.y"
                               {
            function f = (yyvsp[-2].f);
            f.argsize++;
            if (f.argsize == 1)
                f.args = malloc(sizeof(argument));
            else
                f.args = realloc(f.args, f.argsize * sizeof(argument));

            ssymbol ssy = (yyvsp[-1].ssy);

            argument a;
            a.type = ssy.type;
            a.valType = ssy.valType;
            a.val = ssy.val;

            f.args[f.argsize - 1] = a;
            (yyval.f) = f;
      }
#line 2473 "y.tab.c"
    break;

  case 102: /* carg_list: carg_list expr ','  */
#line 761 "yacc.y"
                               {
                function f = (yyvsp[-2].f);
                f.argsize++;
                if (f.argsize == 1)
                    f.args = malloc(sizeof(argument));
                else
                    f.args = realloc(f.args, f.argsize * sizeof(argument));

                ssymbol ssy = (yyvsp[-1].ssy);

                argument a;
                a.type = ssy.type;
                a.valType = ssy.valType;
                a.val = ssy.val;

                f.args[f.argsize - 1] = a;
                (yyval.f) = f;
          }
#line 2496 "y.tab.c"
    break;

  case 103: /* carg_list: %empty  */
#line 779 "yacc.y"
            {
                function f;
                f.argsize = 0;
                (yyval.f) = f;
          }
#line 2506 "y.tab.c"
    break;


#line 2510 "y.tab.c"

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

#line 785 "yacc.y"


int yywrap() {
    return 1;
}

void yyerror(char* s) {
    fprintf(stderr, "Syntax error in line %d: %s\n", yylineno, s);
    exitProgram();
}

void exitProgram() {
    // Free memory pointers before exiting
    fflush(yyout);

    dump();

    exit(1);
}

int main(int argc, char *argv[]) {
    // Create symbol table
    create();

    // Open the source program file
    if (argc != 2) {
        printf("Usage: ./prog <filename>\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");

    // Perform parsing
    int parse = yyparse();
    
    // Free memory (pointers)
    fflush(yyout);

    dump();

    return parse;
}

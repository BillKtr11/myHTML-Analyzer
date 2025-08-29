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
#include <ctype.h>
#include <string.h>
#define SIZE 1000
extern int yylex();
void yyerror(const char *s);
char id_holder[SIZE][SIZE];
int line_num = 1;
int i,id_counter=0;
char input_types[SIZE][SIZE];
int input_type_counter = 0;
int submit_count = 0;
char input_ids[SIZE][SIZE];      // Για να κρατάμε όλα τα input id
int input_id_counter = 0;

char used_in_for[SIZE][SIZE];    // Για να κρατάμε τα id που έχουν ήδη χρησιμοποιηθεί σε for
int for_id_counter = 0;
int checkbox_expected = 0;
int checkbox_count_in_form = 0;
int checkbox_count_set = 0;

int is_valid_src(const char* s) {
    if (strncmp(s, "http://", 7) == 0 || strncmp(s, "https://", 8) == 0)
        return 1;
    if (s[0] == '/')
        return 1;
    return 0;
}
int is_valid_href(const char* s) {
    if (strncmp(s, "http://", 7) == 0 || strncmp(s, "https://", 8) == 0)
        return 1;
    if (s[0] == '/')
        return 1;
    if (strncmp(s, "#", 1) == 0){
         char *newS = s + 1;
         for(i=0;i<id_counter;i++){
             if (strcmp(id_holder[i],newS)==0)
               return 1;
         }
    }
    return 0;
}

int is_valid_style(const char *s) {
    char tmp[SIZE];
    strncpy(tmp, s, SIZE-1); tmp[SIZE-1] = '\0';
    
    char *token = strtok(tmp, ";");
    char seen[10][20];
    int seen_cnt = 0;

    while (token) {
        char *colon = strchr(token, ':');
        if (!colon) return 0;

        *colon = '\0';
        char *prop = token;
        char *val = colon + 1;

        while (*prop==' ') prop++;
        while (*val==' ') val++;
        
        int prop_ok = strcmp(prop,"background_color")==0 ||
                      strcmp(prop,"color")==0 ||
                      strcmp(prop,"font_family")==0 ||
                      strcmp(prop,"font_size")==0;
        if (!prop_ok) return 0;

        if (strcmp(prop,"font_size")==0) {
            int n = atoi(val);
            int L = strlen(val);
            if (n<=0 || !((val[L-1]=='%' && isdigit(val[L-2])) || ((val[L-2]=='p' && val[L-1]=='x') && isdigit(val[L-3])))) return 0;
        } else {
            if (strlen(val)==0) return 0;
        }

        for(int i=0;i<seen_cnt;i++)
            if (strcmp(seen[i], prop)==0) return 0;
        strcpy(seen[seen_cnt++], prop);
        
        token = strtok(NULL, ";");
    }
    
    return 1;
}


#line 161 "parser.tab.c"

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
  YYSYMBOL_MYHTML = 3,                     /* MYHTML  */
  YYSYMBOL_MYHTML_CLOSE = 4,               /* MYHTML_CLOSE  */
  YYSYMBOL_HEAD = 5,                       /* HEAD  */
  YYSYMBOL_HEAD_CLOSE = 6,                 /* HEAD_CLOSE  */
  YYSYMBOL_BODY = 7,                       /* BODY  */
  YYSYMBOL_BODY_CLOSE = 8,                 /* BODY_CLOSE  */
  YYSYMBOL_TITLE = 9,                      /* TITLE  */
  YYSYMBOL_TITLE_CLOSE = 10,               /* TITLE_CLOSE  */
  YYSYMBOL_META = 11,                      /* META  */
  YYSYMBOL_P = 12,                         /* P  */
  YYSYMBOL_P_CLOSE = 13,                   /* P_CLOSE  */
  YYSYMBOL_A = 14,                         /* A  */
  YYSYMBOL_A_CLOSE = 15,                   /* A_CLOSE  */
  YYSYMBOL_IMG = 16,                       /* IMG  */
  YYSYMBOL_IMG_CLOSE = 17,                 /* IMG_CLOSE  */
  YYSYMBOL_FORM = 18,                      /* FORM  */
  YYSYMBOL_FORM_CLOSE = 19,                /* FORM_CLOSE  */
  YYSYMBOL_INPUT = 20,                     /* INPUT  */
  YYSYMBOL_LABEL = 21,                     /* LABEL  */
  YYSYMBOL_LABEL_CLOSE = 22,               /* LABEL_CLOSE  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_DIV_CLOSE = 24,                 /* DIV_CLOSE  */
  YYSYMBOL_CHARSET = 25,                   /* CHARSET  */
  YYSYMBOL_NAME = 26,                      /* NAME  */
  YYSYMBOL_CONTENT = 27,                   /* CONTENT  */
  YYSYMBOL_STYLE = 28,                     /* STYLE  */
  YYSYMBOL_HREF = 29,                      /* HREF  */
  YYSYMBOL_SRC = 30,                       /* SRC  */
  YYSYMBOL_ALT = 31,                       /* ALT  */
  YYSYMBOL_WIDTH = 32,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 33,                    /* HEIGHT  */
  YYSYMBOL_TYPE = 34,                      /* TYPE  */
  YYSYMBOL_VALUE = 35,                     /* VALUE  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_EQUAL = 37,                     /* EQUAL  */
  YYSYMBOL_TAG_CLOSE = 38,                 /* TAG_CLOSE  */
  YYSYMBOL_IDENTIFIER = 39,                /* IDENTIFIER  */
  YYSYMBOL_STRING = 40,                    /* STRING  */
  YYSYMBOL_TEXT = 41,                      /* TEXT  */
  YYSYMBOL_NUMBER = 42,                    /* NUMBER  */
  YYSYMBOL_ID = 43,                        /* ID  */
  YYSYMBOL_COMMENT = 44,                   /* COMMENT  */
  YYSYMBOL_CHECKBOX_COUNT = 45,            /* CHECKBOX_COUNT  */
  YYSYMBOL_EOL = 46,                       /* EOL  */
  YYSYMBOL_T_EOF = 47,                     /* T_EOF  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_myhtml = 49,                    /* myhtml  */
  YYSYMBOL_comment_opt = 50,               /* comment_opt  */
  YYSYMBOL_head_opt = 51,                  /* head_opt  */
  YYSYMBOL_head = 52,                      /* head  */
  YYSYMBOL_meta_list = 53,                 /* meta_list  */
  YYSYMBOL_body = 54,                      /* body  */
  YYSYMBOL_elements = 55,                  /* elements  */
  YYSYMBOL_element = 56,                   /* element  */
  YYSYMBOL_p = 57,                         /* p  */
  YYSYMBOL_p_attributes = 58,              /* p_attributes  */
  YYSYMBOL_id = 59,                        /* id  */
  YYSYMBOL_style = 60,                     /* style  */
  YYSYMBOL_a = 61,                         /* a  */
  YYSYMBOL_a_attributes = 62,              /* a_attributes  */
  YYSYMBOL_a_content = 63,                 /* a_content  */
  YYSYMBOL_href = 64,                      /* href  */
  YYSYMBOL_img = 65,                       /* img  */
  YYSYMBOL_img_attributes = 66,            /* img_attributes  */
  YYSYMBOL_img_required = 67,              /* img_required  */
  YYSYMBOL_img_optional = 68,              /* img_optional  */
  YYSYMBOL_src = 69,                       /* src  */
  YYSYMBOL_alt = 70,                       /* alt  */
  YYSYMBOL_width = 71,                     /* width  */
  YYSYMBOL_height = 72,                    /* height  */
  YYSYMBOL_form = 73,                      /* form  */
  YYSYMBOL_form_attributes = 74,           /* form_attributes  */
  YYSYMBOL_checkbox_count = 75,            /* checkbox_count  */
  YYSYMBOL_form_content = 76,              /* form_content  */
  YYSYMBOL_form_required = 77,             /* form_required  */
  YYSYMBOL_form_optional = 78,             /* form_optional  */
  YYSYMBOL_input = 79,                     /* input  */
  YYSYMBOL_input_attributes = 80,          /* input_attributes  */
  YYSYMBOL_input_required = 81,            /* input_required  */
  YYSYMBOL_input_optional = 82,            /* input_optional  */
  YYSYMBOL_type = 83,                      /* type  */
  YYSYMBOL_value = 84,                     /* value  */
  YYSYMBOL_div = 85,                       /* div  */
  YYSYMBOL_div_attributes = 86,            /* div_attributes  */
  YYSYMBOL_div_content = 87,               /* div_content  */
  YYSYMBOL_div_element = 88,               /* div_element  */
  YYSYMBOL_label = 89,                     /* label  */
  YYSYMBOL_label_attributes = 90,          /* label_attributes  */
  YYSYMBOL_label_required = 91,            /* label_required  */
  YYSYMBOL_label_optional = 92,            /* label_optional  */
  YYSYMBOL_text_opt = 93,                  /* text_opt  */
  YYSYMBOL_for = 94,                       /* for  */
  YYSYMBOL_title = 95,                     /* title  */
  YYSYMBOL_meta = 96,                      /* meta  */
  YYSYMBOL_meta_attributes = 97,           /* meta_attributes  */
  YYSYMBOL_charset = 98,                   /* charset  */
  YYSYMBOL_name = 99,                      /* name  */
  YYSYMBOL_content = 100                   /* content  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   149,   149,   149,   150,   150,   151,   152,
     152,   154,   156,   156,   157,   157,   157,   157,   157,   157,
     159,   160,   160,   160,   162,   181,   188,   189,   189,   190,
     190,   190,   190,   190,   192,   200,   201,   201,   202,   202,
     202,   202,   202,   202,   203,   203,   203,   203,   203,   205,
     211,   212,   213,   215,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   255,   260,   261,   261,   262,   262,   262,
     262,   262,   264,   271,   271,   272,   273,   277,   277,   277,
     277,   277,   279,   293,   295,   296,   296,   296,   297,   297,
     298,   298,   298,   298,   298,   300,   301,   301,   302,   302,
     303,   303,   305,   306,   310,   311,   315,   339,   346,   347,
     347,   347,   347,   349,   350,   351
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
  "\"end of file\"", "error", "\"invalid token\"", "MYHTML",
  "MYHTML_CLOSE", "HEAD", "HEAD_CLOSE", "BODY", "BODY_CLOSE", "TITLE",
  "TITLE_CLOSE", "META", "P", "P_CLOSE", "A", "A_CLOSE", "IMG",
  "IMG_CLOSE", "FORM", "FORM_CLOSE", "INPUT", "LABEL", "LABEL_CLOSE",
  "DIV", "DIV_CLOSE", "CHARSET", "NAME", "CONTENT", "STYLE", "HREF", "SRC",
  "ALT", "WIDTH", "HEIGHT", "TYPE", "VALUE", "FOR", "EQUAL", "TAG_CLOSE",
  "IDENTIFIER", "STRING", "TEXT", "NUMBER", "ID", "COMMENT",
  "CHECKBOX_COUNT", "EOL", "T_EOF", "$accept", "myhtml", "comment_opt",
  "head_opt", "head", "meta_list", "body", "elements", "element", "p",
  "p_attributes", "id", "style", "a", "a_attributes", "a_content", "href",
  "img", "img_attributes", "img_required", "img_optional", "src", "alt",
  "width", "height", "form", "form_attributes", "checkbox_count",
  "form_content", "form_required", "form_optional", "input",
  "input_attributes", "input_required", "input_optional", "type", "value",
  "div", "div_attributes", "div_content", "div_element", "label",
  "label_attributes", "label_required", "label_optional", "text_opt",
  "for", "title", "meta", "meta_attributes", "charset", "name", "content", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,   -25,    30,   -25,    71,  -141,  -141,   -25,   -25,  -141,
      51,    63,   -25,   -25,    29,   -25,    82,    89,    44,    -4,
      62,    41,    44,  -141,    98,    29,  -141,  -141,  -141,  -141,
    -141,   117,    82,    82,   -25,    28,   -25,    89,    88,   100,
      97,   110,    96,   103,   112,   105,    96,   107,   108,   109,
     114,    79,   115,    95,    58,    -5,    16,   116,   122,   118,
      23,    73,   120,    44,   110,    96,   123,  -141,  -141,  -141,
    -141,  -141,   132,   125,   126,   104,   127,    96,   121,   141,
    -141,   128,   129,   -25,  -141,  -141,   130,  -141,   -25,  -141,
     131,   133,   124,   134,   136,   144,  -141,  -141,  -141,   136,
      96,   144,    96,  -141,  -141,   135,   139,  -141,   139,    96,
     -25,  -141,    96,  -141,  -141,   -25,  -141,   138,   140,  -141,
     121,  -141,  -141,   142,    96,  -141,  -141,  -141,    82,  -141,
      -1,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,   111,  -141,   101,  -141,  -141,
    -141,   145,  -141,   -25,    -1,   -25,    -1,    47,    55,   -25,
     111,  -141,  -141,  -141,  -141,  -141,  -141,   -25,   101,  -141,
     162,  -141,   166,  -141,   149,   150,   154,   157,   155,    68,
      65,    96,   110,   158,   161,  -141,   156,   110,     6,    96,
     179,  -141,   111,   111,   175,  -141,  -141,  -141,   160,   163,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,   164,  -141,   -25,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
      82,   -25,   180,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     0,     3,     7,     1,     4,     5,     5,     6,
       0,     0,     5,     5,    13,     5,     0,     9,     0,     0,
       0,     0,     0,    19,     0,    13,    14,    15,    16,    17,
      18,     0,   102,   103,     5,     0,     5,     9,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,    46,    47,     0,
      54,     0,     0,     0,    85,     0,     0,    11,    12,     2,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     5,    22,    23,     0,    27,     5,    28,
       0,     0,     0,     0,     0,     0,    35,    36,    37,     0,
       0,     0,     0,    44,    45,     0,    55,    57,    56,     0,
       5,    58,     0,    86,    87,     5,   107,     0,     0,   109,
       0,   108,   110,     0,     0,     8,    25,    24,     0,    34,
      33,    49,    50,    51,    52,    38,    39,    43,    42,    40,
      41,    63,    60,    59,    61,     0,    62,    89,   113,   114,
     111,     0,   112,     5,    30,     5,    29,     0,     0,     5,
      71,    65,    66,    90,    91,    92,    93,     5,    89,   115,
       0,    32,     0,    31,     0,     0,     0,    78,     0,    81,
       0,     0,    77,     0,     0,   100,     0,   101,     0,     0,
       0,    64,    67,    68,     0,    88,    20,    26,     0,     0,
      75,    80,    72,    73,    74,    76,    79,     0,    98,     5,
      96,    97,    99,    53,    69,    70,    84,    82,    83,   106,
       0,     5,     0,    95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,    -3,  -141,  -141,   168,  -141,   182,  -141,  -140,
    -141,     2,    14,  -139,  -141,   -34,   165,   -11,  -141,   159,
     167,   -45,   -33,   152,   151,  -134,  -141,   -44,  -141,  -141,
     -59,    66,  -141,    32,    35,    39,    40,  -141,  -141,    48,
    -141,    74,  -141,    33,    36,   -31,    38,  -141,  -141,  -141,
     153,   169,   106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     4,     8,     9,    36,    15,    24,    25,    26,
      40,    51,   177,    27,    45,   155,    46,   156,    52,    53,
      54,    55,    56,    57,    58,    29,    62,    63,   159,   160,
     191,   192,   178,   179,   180,   181,   182,    30,    66,   167,
     168,   193,   186,   187,   188,    34,   189,    13,    37,    76,
      77,    78,   124
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,    70,    71,    28,    10,    11,    94,   163,   164,    16,
      17,   102,    31,   166,    28,    20,   107,   109,    95,     3,
      41,    44,   100,    60,    64,    43,    48,     1,   163,   164,
       5,    72,    42,    79,   166,    61,    65,    75,    39,    39,
     154,    18,   183,    19,    85,    20,    47,    21,    89,    39,
     136,    38,    22,    73,    74,    84,   139,    99,   101,    39,
      12,   135,   142,   108,   143,   111,   137,   114,    59,    38,
      14,    39,    38,    23,   106,    38,     7,   112,   113,   122,
     128,   174,   175,    38,    39,   130,    59,    39,    47,    48,
      39,   183,    47,    48,    49,    50,    38,   153,    39,   174,
      35,    39,   138,   175,   140,    39,    67,   145,    39,    47,
      48,   144,   147,    18,   146,    19,    39,    20,    59,    21,
     171,    69,   173,    32,    33,    81,   152,    49,    50,    73,
      74,   157,   158,   214,   215,    83,   165,    82,    38,    39,
      86,    43,   116,    88,    90,    91,    92,   125,   123,    50,
     170,    93,   172,    96,    49,   105,   190,   165,   110,   176,
     184,   115,   117,   118,   194,   121,   133,    48,   126,   127,
     129,   131,   185,   132,    47,   196,   134,   141,   148,   151,
     149,   197,   176,   205,    59,   169,   198,   199,   174,   221,
     184,   212,   175,   202,   209,   207,   206,   183,   213,   216,
     217,   185,   223,   218,   219,    80,   220,    68,   103,    87,
     104,   161,   204,    98,   203,   200,   195,   201,   222,   162,
      97,   211,   208,   210,     0,     0,   150,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
       3,    32,    33,    14,     7,     8,    51,   147,   147,    12,
      13,    56,    15,   147,    25,    16,    60,    61,    51,    44,
      18,    19,    55,    21,    22,    29,    31,     3,   168,   168,
       0,    34,    18,    36,   168,    21,    22,    35,    43,    43,
      41,    12,    36,    14,    42,    16,    30,    18,    46,    43,
      95,    28,    23,    25,    26,    41,   101,    55,    56,    43,
       9,    94,   106,    61,   108,    63,    99,    65,    45,    28,
       7,    43,    28,    44,    60,    28,     5,    63,    64,    77,
      83,    34,    35,    28,    43,    88,    45,    43,    30,    31,
      43,    36,    30,    31,    32,    33,    28,   128,    43,    34,
      11,    43,   100,    35,   102,    43,     8,   110,    43,    30,
      31,   109,   115,    12,   112,    14,    43,    16,    45,    18,
     154,     4,   156,    41,    42,    37,   124,    32,    33,    25,
      26,    20,    21,   192,   193,    38,   147,    37,    28,    43,
      37,    29,    10,    38,    37,    37,    37,     6,    27,    33,
     153,    37,   155,    38,    32,    37,   159,   168,    38,   157,
     158,    38,    37,    37,   167,    38,    42,    31,    40,    40,
      40,    40,   158,    40,    30,    13,    42,    42,    40,    37,
      40,    15,   180,   181,    45,    40,    37,    37,    34,   220,
     188,   189,    35,    38,    38,    37,   182,    36,    19,    24,
      40,   187,    22,    40,    40,    37,   209,    25,    57,    44,
      58,   145,   180,    54,   179,   176,   168,   177,   221,   145,
      53,   188,   184,   187,    -1,    -1,   120,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    44,    50,     0,    50,     5,    51,    52,
      50,    50,     9,    95,     7,    54,    50,    50,    12,    14,
      16,    18,    23,    44,    55,    56,    57,    61,    65,    73,
      85,    50,    41,    42,    93,    11,    53,    96,    28,    43,
      58,    59,    60,    29,    59,    62,    64,    30,    31,    32,
      33,    59,    66,    67,    68,    69,    70,    71,    72,    45,
      59,    60,    74,    75,    59,    60,    86,     8,    55,     4,
      93,    93,    50,    25,    26,    59,    97,    98,    99,    50,
      53,    37,    37,    38,    60,    59,    37,    64,    38,    59,
      37,    37,    37,    37,    69,    70,    38,    68,    67,    59,
      70,    59,    69,    72,    71,    37,    60,    75,    59,    75,
      38,    59,    60,    60,    59,    38,    10,    37,    37,    98,
      99,    38,    59,    27,   100,     6,    40,    40,    50,    40,
      50,    40,    40,    42,    42,    70,    69,    70,    59,    69,
      59,    42,    75,    75,    59,    50,    59,    50,    40,    40,
     100,    37,    59,    93,    41,    63,    65,    20,    21,    76,
      77,    79,    89,    57,    61,    65,    73,    87,    88,    40,
      50,    63,    50,    63,    34,    35,    59,    60,    80,    81,
      82,    83,    84,    36,    59,    60,    90,    91,    92,    94,
      50,    78,    79,    89,    50,    87,    13,    15,    37,    37,
      83,    84,    38,    82,    81,    59,    60,    37,    94,    38,
      92,    91,    59,    19,    78,    78,    24,    40,    40,    40,
      50,    93,    50,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    51,    52,    53,
      53,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    58,    59,    60,    61,    62,    62,    63,
      63,    63,    63,    63,    64,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    69,
      70,    71,    72,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    77,    77,    78,    78,    78,
      78,    78,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    83,    84,    85,    86,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    93,    93,    94,    95,    96,    97,
      97,    97,    97,    98,    99,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     2,     0,     1,     0,     7,     0,
       2,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       7,     1,     2,     2,     3,     3,     7,     2,     2,     1,
       1,     2,     2,     0,     3,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     0,     3,
       3,     3,     3,     7,     1,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     2,
       2,     0,     3,     2,     2,     2,     2,     1,     1,     2,
       2,     0,     3,     3,     7,     1,     2,     2,     2,     0,
       1,     1,     1,     1,     0,     7,     2,     2,     2,     2,
       1,     0,     1,     1,     2,     2,     3,     5,     3,     2,
       2,     3,     3,     3,     3,     3
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
  case 24: /* id: ID EQUAL STRING  */
#line 162 "parser.y"
                    {

  for(i=0;i<id_counter;i++){
  if(strcmp(id_holder[i],(yyvsp[0].str))==0){
  fprintf(stderr,"Error at line %d: Elements id's must be different\n",line_num);
  YYABORT;
}
}

if(id_counter>=SIZE){
  fprintf(stderr,"Error at line %d: Too many id's defined\n",line_num); 
  YYABORT;
}
strcpy(id_holder[id_counter++],(yyvsp[0].str));
(yyval.str) = (yyvsp[0].str);


}
#line 1428 "parser.tab.c"
    break;

  case 25: /* style: STYLE EQUAL STRING  */
#line 181 "parser.y"
                         {
    if (!is_valid_style((yyvsp[0].str))) {
        fprintf(stderr, "Error at line %d: Invalid style attribute '%s'\n",line_num, (yyvsp[0].str));
        YYABORT;
    }
}
#line 1439 "parser.tab.c"
    break;

  case 34: /* href: HREF EQUAL STRING  */
#line 192 "parser.y"
                        { 
        if (!is_valid_href((yyvsp[0].str))) {
        fprintf(stderr, "Error at line %d: Invalid href URL '%s'\n",line_num, (yyvsp[0].str));
        YYABORT;
        (yyval.str) = (yyvsp[0].str);
        }
}
#line 1451 "parser.tab.c"
    break;

  case 49: /* src: SRC EQUAL STRING  */
#line 205 "parser.y"
                     {
    if (!is_valid_src((yyvsp[0].str))) {
        fprintf(stderr, "Error at line %d: Invalid src URL '%s'\n",line_num, (yyvsp[0].str));
        YYABORT;
    }
}
#line 1462 "parser.tab.c"
    break;

  case 53: /* form: FORM form_attributes TAG_CLOSE comment_opt form_content comment_opt FORM_CLOSE  */
#line 215 "parser.y"
                                                                                     {
    if (submit_count > 1) {
        fprintf(stderr, "Error at line %d: Multiple submit inputs in a single form\n",line_num);
        YYABORT;
    }

    if (submit_count == 1 &&
        strcmp(input_types[input_type_counter - 1], "submit") != 0) {
        fprintf(stderr, "Error at  line %d: Submit input must be the last in the form\n",line_num);
        YYABORT;
    }

    if (checkbox_count_set) {
        if (checkbox_count_in_form == 0) {
            fprintf(stderr, "Error at line %d: Checkbox_count set, but no checkbox inputs found in form.\n",line_num);
            YYABORT;
        }
        if (checkbox_expected != checkbox_count_in_form) {
            fprintf(stderr, "Error at line %d: Expected %d checkbox/es, but found %d.\n",line_num, checkbox_expected, checkbox_count_in_form);
            YYABORT;
        }
    }

    submit_count = 0;
    input_type_counter = 0;
    checkbox_expected = 0;
    checkbox_count_in_form = 0;
    checkbox_count_set = 0;
}
#line 1496 "parser.tab.c"
    break;

  case 63: /* checkbox_count: CHECKBOX_COUNT EQUAL NUMBER  */
#line 255 "parser.y"
                                            {
    checkbox_expected = (yyvsp[0].num);
    checkbox_count_in_form = 0;
    checkbox_count_set = 1;
}
#line 1506 "parser.tab.c"
    break;

  case 72: /* input: INPUT input_attributes TAG_CLOSE  */
#line 264 "parser.y"
                                       {
    if (strcmp((yyvsp[-1].str), "submit") == 0)
        submit_count++;
    else if (strcmp((yyvsp[-1].str), "checkbox") == 0)
        checkbox_count_in_form++;
}
#line 1517 "parser.tab.c"
    break;

  case 73: /* input_attributes: input_required input_optional  */
#line 271 "parser.y"
                                               {(yyval.str) = (yyvsp[-1].str);}
#line 1523 "parser.tab.c"
    break;

  case 74: /* input_attributes: input_optional input_required  */
#line 271 "parser.y"
                                                                                         {(yyval.str) = (yyvsp[0].str);}
#line 1529 "parser.tab.c"
    break;

  case 75: /* input_required: id type  */
#line 272 "parser.y"
                        {strcpy(input_ids[input_id_counter++], (yyvsp[-1].str));(yyval.str) = (yyvsp[0].str);}
#line 1535 "parser.tab.c"
    break;

  case 76: /* input_required: type id  */
#line 273 "parser.y"
                          {strcpy(input_ids[input_id_counter++], (yyvsp[0].str)); (yyval.str) = (yyvsp[-1].str);}
#line 1541 "parser.tab.c"
    break;

  case 82: /* type: TYPE EQUAL STRING  */
#line 279 "parser.y"
                        {
    if (strcmp((yyvsp[0].str), "text") != 0 &&
        strcmp((yyvsp[0].str), "checkbox") != 0 &&
        strcmp((yyvsp[0].str), "radio") != 0 &&
        strcmp((yyvsp[0].str), "submit") != 0) {

        fprintf(stderr, "Error at line %d: Invalid input type '%s'\n",line_num, (yyvsp[0].str));
        YYABORT;
    }

    strcpy(input_types[input_type_counter++], (yyvsp[0].str));
    (yyval.str) = (yyvsp[0].str);
}
#line 1559 "parser.tab.c"
    break;

  case 102: /* text_opt: TEXT  */
#line 305 "parser.y"
                       { (yyval.num) = (int)strlen((yyvsp[0].str));}
#line 1565 "parser.tab.c"
    break;

  case 103: /* text_opt: NUMBER  */
#line 306 "parser.y"
                       {
                char buffer[20];    
                sprintf(buffer, "%d", abs((yyvsp[0].num))); 
                (yyval.num) = strlen(buffer);}
#line 1574 "parser.tab.c"
    break;

  case 104: /* text_opt: TEXT text_opt  */
#line 310 "parser.y"
                       { (yyval.num) = strlen((yyvsp[-1].str)) + 1 + (yyvsp[0].num);free((yyvsp[-1].str));}
#line 1580 "parser.tab.c"
    break;

  case 105: /* text_opt: NUMBER text_opt  */
#line 311 "parser.y"
                       {
                char buffer[20];    
                sprintf(buffer, "%d", abs((yyvsp[-1].num))); 
                (yyval.num) = strlen(buffer) + 1 + (yyvsp[0].num);}
#line 1589 "parser.tab.c"
    break;

  case 106: /* for: FOR EQUAL STRING  */
#line 315 "parser.y"
                     {
    int found = 0;
    for (int j = 0; j < input_id_counter; j++) {
        if (strcmp(input_ids[j], (yyvsp[0].str)) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        fprintf(stderr, "Error at line %d: for=\"%s\" does not match any input id\n",line_num, (yyvsp[0].str));
        YYABORT;
    }

    for (int j = 0; j < for_id_counter; j++) {
        if (strcmp(used_in_for[j], (yyvsp[0].str)) == 0) {
            fprintf(stderr, "Error at line %d: Input id \"%s\" used in multiple <label> for attributes\n",line_num, (yyvsp[0].str));
            YYABORT;
        }
    }

    strcpy(used_in_for[for_id_counter++], (yyvsp[0].str));
}
#line 1617 "parser.tab.c"
    break;

  case 107: /* title: TITLE comment_opt text_opt comment_opt TITLE_CLOSE  */
#line 339 "parser.y"
                                                         {
        if ((yyvsp[-2].num) > 60) {
            fprintf(stderr, "Error at line %d: Title exceeds 60 characters (%d)\n",line_num, (yyvsp[-2].num));
            YYABORT;
    }
}
#line 1628 "parser.tab.c"
    break;


#line 1632 "parser.tab.c"

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

#line 355 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s at line %d\n",s,  line_num);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }

    extern FILE *yyin;
    yyin = f;

    if (yyparse() == 0)
        printf("Valid myHTML document.\n");
    else
        printf("Invalid myHTML document.\n");

    fclose(f);
    return 0;
}




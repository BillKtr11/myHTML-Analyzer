/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    MYHTML = 258,                  /* MYHTML  */
    MYHTML_CLOSE = 259,            /* MYHTML_CLOSE  */
    HEAD = 260,                    /* HEAD  */
    HEAD_CLOSE = 261,              /* HEAD_CLOSE  */
    BODY = 262,                    /* BODY  */
    BODY_CLOSE = 263,              /* BODY_CLOSE  */
    TITLE = 264,                   /* TITLE  */
    TITLE_CLOSE = 265,             /* TITLE_CLOSE  */
    META = 266,                    /* META  */
    P = 267,                       /* P  */
    P_CLOSE = 268,                 /* P_CLOSE  */
    A = 269,                       /* A  */
    A_CLOSE = 270,                 /* A_CLOSE  */
    IMG = 271,                     /* IMG  */
    IMG_CLOSE = 272,               /* IMG_CLOSE  */
    FORM = 273,                    /* FORM  */
    FORM_CLOSE = 274,              /* FORM_CLOSE  */
    INPUT = 275,                   /* INPUT  */
    LABEL = 276,                   /* LABEL  */
    LABEL_CLOSE = 277,             /* LABEL_CLOSE  */
    DIV = 278,                     /* DIV  */
    DIV_CLOSE = 279,               /* DIV_CLOSE  */
    CHARSET = 280,                 /* CHARSET  */
    NAME = 281,                    /* NAME  */
    CONTENT = 282,                 /* CONTENT  */
    STYLE = 283,                   /* STYLE  */
    HREF = 284,                    /* HREF  */
    SRC = 285,                     /* SRC  */
    ALT = 286,                     /* ALT  */
    WIDTH = 287,                   /* WIDTH  */
    HEIGHT = 288,                  /* HEIGHT  */
    TYPE = 289,                    /* TYPE  */
    VALUE = 290,                   /* VALUE  */
    FOR = 291,                     /* FOR  */
    ID = 292,                      /* ID  */
    EQUAL = 293,                   /* EQUAL  */
    TAG_CLOSE = 294,               /* TAG_CLOSE  */
    IDENTIFIER = 295,              /* IDENTIFIER  */
    STRING = 296,                  /* STRING  */
    TEXT = 297,                    /* TEXT  */
    NUMBER = 298,                  /* NUMBER  */
    COMMENT = 299,                 /* COMMENT  */
    EOL = 300,                     /* EOL  */
    T_EOF = 301                    /* T_EOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    char* str;   // For IDENTIFIERs or strings
    int   num;   // For numeric tokens, if needed

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

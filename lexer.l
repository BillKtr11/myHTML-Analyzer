%{
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
%}

%option case-insensitive
%option yylineno
%option noyywrap

LETTER      [a-zA-Z]
DIGIT       [0-9]
CHARACTER   {LETTER}|{DIGIT}
NZNUMBER    [1-9]{DIGIT}*|0

ID          _?{LETTER}({LETTER}|{DIGIT}|_)*
ICONST      {NZNUMBER}
FCONST      {NZNUMBER}\.{DIGIT}*
CCONST      \'.\'
WHITESPACE  [ \t]

%%

"<MYHTML>" { printf("KEYWORD -> myHTML\n"); return MYHTML; }
"<\/MYHTML>"  { printf("KEYWORD -> myHTML_close\n"); return MYHTML_CLOSE; }

"<head>" { printf("KEYWORD -> HEAD\n"); return HEAD;}
"<\/head>" { printf("KEYWORD -> HEAD_CLOSE\n"); return HEAD_CLOSE;}
"<meta>" { printf("KEYWORD -> META\n"); return META;}
"<title>" { printf("KEYWORD -> TITLE\n"); return TITLE;}
"<\/title>" { printf("KEYWORD -> TITLE_CLOSE\n"); return TITLE_CLOSE;}

"<body>" { printf("KEYWORD -> BODY\n"); return BODY;}
"<\/body>" { printf("KEYWORD -> BODY_CLOSE\n"); return BODY_CLOSE;}
"<p>" { printf("KEYWORD -> P\n"); return P;}
"<\/p>" { printf("KEYWORD -> P_CLOSE\n"); return P_CLOSE;}
"<a>" { printf("KEYWORD -> A\n"); return A;}
"<\/a>" { printf("KEYWORD -> A_CLOSE\n"); return A_CLOSE;}
"<IMG>" { printf("KEYWORD -> IMG\n"); return IMG;}
"<\/IMG>" { printf("KEYWORD -> IMG_CLOSE\n"); return IMG_CLOSE;}
"<a>" { printf("KEYWORD -> A\n"); return A;}
"<\/a>" { printf("KEYWORD -> A_CLOSE\n"); return A_CLOSE;}
"<a>" { printf("KEYWORD -> A\n"); return A;}
"<\/a>" { printf("KEYWORD -> A_CLOSE\n"); return A_CLOSE;}
%%

int main(int argc, char* argv[]) {

    int token; 

    yyin = fopen("test.c", "r"); // Το yyin είναι ειδική μεταβλητή του Flex.
                                // Ισοδυναμεί με ένα FILE Pointer για να διαβάζει το αρχείο ο Flex

    if (yyin == NULL) {
        printf("File not found\n");
        return 1;
    }

    do { // Μέχρι να φτάσουμε στο EOF διαβάζουμε κάθε Token μέσα απο το αρχείο.
        token = yylex();
    } while (token != T_EOF);

    return 0;
}

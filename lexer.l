%{
#include "parser.tab.h"
extern int line_num;

%}
%option yylineno
%option noyywrap

%%

[ \t\r]+             ;
\n                   { line_num++; }

"<MYHTML>" { return MYHTML; }
"<\/MYHTML>"  { return MYHTML_CLOSE; }
"<head>" {return HEAD;}
"<\/head>" { return HEAD_CLOSE;}
"<meta" {return META;}
"<title>" {return TITLE;}
"<\/title>" {return TITLE_CLOSE;}
"<body>" {return BODY;}
"<\/body>" { return BODY_CLOSE;}
"<p" {return P; }
"<\/p>" {return P_CLOSE;}
"<a" {return A;}
"<\/a>" { return A_CLOSE;}
"<img" {return IMG;}
"<\/img>" { return IMG_CLOSE;}
"<form" { return FORM;}
"<\/form>" { return FORM_CLOSE;}
"<input" {return INPUT;}
"<label" {return LABEL;}
"<\/label>" {return LABEL_CLOSE;}
"<div" {return DIV;}
"<\/div>" {  return DIV_CLOSE;}
"charset"[ ]* {return CHARSET;}
"name"[ ]* {return NAME;}
"content"[ ]* {return CONTENT;}
"style"[ ]* {return STYLE;}
"href"[ ]* {return HREF;}
"src"[ ]* {return SRC;}
"alt"[ ]* {return ALT;}
"width"[ ]* {return WIDTH;}
"height"[ ]* {return HEIGHT;}
"type"[ ]* {return TYPE;}
"value" {return VALUE;}
"for"[ ]* {return FOR;}
"id"[ ]* {return ID;}
"checkbox_count"[ ]* {return CHECKBOX_COUNT;}
"=" {return EQUAL;}
">" {return TAG_CLOSE;}

[1-9][0-9]*|0 {
    yylval.num = atoi(yytext);  
    return NUMBER;
}
\"[^\"]*\" {
    int len = yyleng;
    char* raw = strdup(yytext + 1);  
    raw[len - 2] = '\0';             
    yylval.str = raw;
    return STRING;
}
"<!--"([^-]|"-"[^-])*"-->"[ ]* {return COMMENT;}
[^<>\n"=\t\r ][^<>\n"=\t\r ]* { 
  yylval.str = strdup(yytext);
  return TEXT; 
}


%%

%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
void yyerror(const char *s);
int line_num = 1;
%}

%union {
    char* str;   // For IDENTIFIERs or strings
    int   num;   // For numeric tokens, if needed
}

%token MYHTML
%token MYHTML_CLOSE
%token HEAD
%token HEAD_CLOSE
%token BODY
%token BODY_CLOSE

%token TITLE
%token TITLE_CLOSE
%token META

%token P
%token P_CLOSE
%token A
%token A_CLOSE
%token IMG
%token IMG_CLOSE
%token FORM
%token FORM_CLOSE
%token INPUT
%token LABEL
%token LABEL_CLOSE
%token DIV
%token DIV_CLOSE

%token CHARSET
%token NAME
%token CONTENT
%token STYLE
%token HREF
%token SRC
%token ALT
%token WIDTH
%token HEIGHT
%token TYPE
%token VALUE
%token FOR
%token ID

%token EQUAL
%token TAG_CLOSE
%token IDENTIFIER
%token STRING
%token <str> TEXT
%token NUMBER

%token COMMENT

%token EOL
%token T_EOF

%%

myhtml: MYHTML head_opt body MYHTML_CLOSE;

head_opt: head |  ;
head: HEAD title meta_list HEAD_CLOSE;
meta_list: | meta meta_list;

body: BODY elements BODY_CLOSE;

elements: element elements | ;
element: p | a | img | form | div | COMMENT ;

p: P p_attributes TAG_CLOSE text_opt P_CLOSE;
p_attributes: id | id style | style id;

id: ID EQUAL STRING ;
style: STYLE EQUAL STRING;

a: A a_attributes TAG_CLOSE a_content A_CLOSE;
a_attributes: id href | href id ;
a_content: img | TEXT | ;

href: HREF EQUAL STRING;

img: IMG img_attributes TAG_CLOSE; 
img_attributes: img_required img_optional | img_optional img_required;
img_required: id src alt | id alt src | alt id src | alt src id | src alt id| src id alt ;
img_optional: width height | height width | width | height | ;

src: SRC EQUAL STRING;
alt: ALT EQUAL STRING;
width: WIDTH EQUAL NUMBER;
height: HEIGHT EQUAL NUMBER;

form: FORM form_attributes TAG_CLOSE form_content FORM_CLOSE;
form_attributes: id | id style | style id ;
form_content: form_required form_optional;
form_required: input | label ;
form_optional: input | label | input form_optional | label form_optional |  ;

input: INPUT input_attributes TAG_CLOSE;
input_attributes: input_required input_optional | input_optional input_required;
input_required: id type | type id;
input_optional: value | style | value style | style value | ;

type: TYPE EQUAL STRING;
value: VALUE EQUAL STRING;

div: DIV div_attributes TAG_CLOSE div_content DIV_CLOSE ;
div_attributes: id | id style | style id ;
div_content: div_element div_content | ;
div_element: p | a | img | form | ;

label: LABEL label_attributes TAG_CLOSE text_opt LABEL_CLOSE;
label_attributes: label_required label_optional | label_optional label_required;
label_required: id for | for id;
label_optional:  style | ;
text_opt: TEXT | ;

for: FOR EQUAL STRING;

title: TITLE text_opt TITLE_CLOSE;

meta: META meta_attributes TAG_CLOSE;
meta_attributes: id charset | charset id | id name content | name content id;

charset: CHARSET EQUAL STRING;
name: NAME EQUAL STRING;
content: CONTENT EQUAL STRING;


%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s at line %d\n", s, line_num);
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

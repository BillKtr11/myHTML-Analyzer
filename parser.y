%{
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
int input_attribute_counter = 0;
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
    /* Σχετικό URL (π.χ. ξεκινάει με γράμμα ή αριθμό) */
//    if (isalnum((unsigned char)s[0]))
//        return 1;
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

        // Trim spaces (προαιρετικό)
        while (*prop==' ') prop++;
        while (*val==' ') val++;
        
        // Έλεγχος property
        int prop_ok = strcmp(prop,"background_color")==0 ||
                      strcmp(prop,"color")==0 ||
                      strcmp(prop,"font_family")==0 ||
                      strcmp(prop,"font_size")==0;
        if (!prop_ok) return 0;

        // Έλεγχος τιμής
        if (strcmp(prop,"font_size")==0) {
            int n = atoi(val);
            int L = strlen(val);
            if (n<=0 || !((val[L-1]=='%' && isdigit(val[L-2])) || ((val[L-2]=='p' && val[L-1]=='x') && isdigit(val[L-3])))) return 0;
        } else {
            if (strlen(val)==0) return 0;
        }

        // Μοναδικότητα
        for(int i=0;i<seen_cnt;i++)
            if (strcmp(seen[i], prop)==0) return 0;
        strcpy(seen[seen_cnt++], prop);
        
        token = strtok(NULL, ";");
    }
    
    return 1;
}
//int href_check(const char* val){  
//    if (!is_valid_href(val)) {
//        fprintf(stderr, "Error at line %d: Invalid href format '%s'\n",line_num, val);
//        return 0;
//    }
//    if (val[0] == '#') {
//        const char* target = val + 1;
//        int found = 0;
//        for (int j = 0; j < id_counter; j++) {
//            if (strcmp(id_holder[j], target) == 0) {
//                found = 1;
//                return found;
//            }
//        }
//        if (!found) {
//            fprintf(stderr, "Error at line %d: Href '%s' references unknown id\n",line_num, val);
//            return 0;
//        }
//    }
//}
%}
%type <str> id type
%type <str> href
%type <str> text_opt 
%start myhtml

%union {
    char* str;   // For IDENTIFIERs or strings
    int   num;   // For numeric tokens, if needed
}

%token MYHTML MYHTML_CLOSE HEAD HEAD_CLOSE BODY BODY_CLOSE

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


%token EQUAL TAG_CLOSE IDENTIFIER <str> STRING <str> TEXT <num> NUMBER
%token ID
%token COMMENT

%token CHECKBOX_COUNT

%token EOL
%token T_EOF

%%

myhtml: MYHTML comment_opt head_opt comment_opt body comment_opt MYHTML_CLOSE;

comment_opt : COMMENT | COMMENT comment_opt |  ;
head_opt: head | ;
head: HEAD comment_opt title comment_opt meta_list comment_opt HEAD_CLOSE;
meta_list: | meta meta_list;

body: BODY elements BODY_CLOSE;

elements: element elements | ;
element: p | a | img | form | div | COMMENT ;

p: P p_attributes TAG_CLOSE comment_opt text_opt comment_opt P_CLOSE;
p_attributes: id | id style | style id;

id: ID EQUAL STRING {

  for(i=0;i<id_counter;i++){
  if(strcmp(id_holder[i],$3)==0){
  fprintf(stderr,"Error at line %d: Elements id's must be different\n",line_num);
  YYABORT;
}
}

if(id_counter>=SIZE){
  fprintf(stderr,"Error at line %d: Too many id's defined\n",line_num); 
  YYABORT;
}
strcpy(id_holder[id_counter++],$3);
$$ = $3;


};

style: STYLE EQUAL STRING{
    if (!is_valid_style($3)) {
        fprintf(stderr, "Error at line %d: Invalid style attribute '%s'\n",line_num, $3);
        YYABORT;
    }
};

a: A a_attributes TAG_CLOSE comment_opt a_content comment_opt A_CLOSE;
a_attributes: id href | href id ;
a_content: img | TEXT |  ;

href: HREF EQUAL STRING { 
        if (!is_valid_href($3)) {
        fprintf(stderr, "Error at line %d: Invalid src URL '%s'\n",line_num, $3);
        YYABORT;
        $$ = $3;
        }
};

img: IMG img_attributes TAG_CLOSE; 
img_attributes: img_required img_optional | img_optional img_required;
img_required: id src alt | id alt src | alt id src | alt src id | src alt id| src id alt ;
img_optional: width height | height width | width | height | ;

src: SRC EQUAL STRING{
    if (!is_valid_src($3)) {
        fprintf(stderr, "Error at line %d: Invalid src URL '%s'\n",line_num, $3);
        YYABORT;
    }
};
alt: ALT EQUAL STRING;
width: WIDTH EQUAL NUMBER;
height: HEIGHT EQUAL NUMBER;

form: FORM form_attributes TAG_CLOSE comment_opt form_content comment_opt FORM_CLOSE {
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

    // reset for next form
    submit_count = 0;
    input_type_counter = 0;
    checkbox_expected = 0;
    checkbox_count_in_form = 0;
    checkbox_count_set = 0;
};

form_attributes: id
               | id style
               | style id
               | id checkbox_count
               | checkbox_count id
               | style id checkbox_count
               | id style checkbox_count
               | style checkbox_count id
               | checkbox_count style id;

checkbox_count: CHECKBOX_COUNT EQUAL NUMBER {
    checkbox_expected = $3;
    checkbox_count_in_form = 0;
    checkbox_count_set = 1;
};
form_content: form_required form_optional;
form_required: input | label ;
form_optional: input | label | input form_optional | label form_optional |  ;

input: INPUT input_attributes TAG_CLOSE{
    // έλεγχος τύπου input
    for (int j = 0; j < input_attribute_counter; j++) {
        if (strcmp(input_types[j], "submit") == 0)
            submit_count++;
        else if (strcmp(input_types[j], "checkbox") == 0)
            checkbox_count_in_form++;
    }
    input_attribute_counter = 0; // reset
};

input_attributes: input_required input_optional | input_optional input_required;
input_required: id type {strcpy(input_ids[input_id_counter++], $1);}
                | type id {strcpy(input_ids[input_id_counter++], $2);};



input_optional: value | style | value style | style value | ;

type: TYPE EQUAL STRING {
    // Ελέγχει αν είναι έγκυρη τιμή τύπου
    if (strcmp($3, "text") != 0 &&
        strcmp($3, "checkbox") != 0 &&
        strcmp($3, "radio") != 0 &&
        strcmp($3, "submit") != 0) {

        fprintf(stderr, "Error at line %d: Invalid input type '%s'\n",line_num, $3);
        YYABORT;
    }

    // Φυλάσσει τους τύπους input για μελλοντικό έλεγχο
    strcpy(input_types[input_type_counter], $3);

    // Αν είναι submit, αύξησε counter
//    if (strcmp($3, "submit") == 0)
//        submit_count++;

    input_type_counter++;

    strcpy(input_types[input_attribute_counter++], $3);
};

value: VALUE EQUAL STRING;

div: DIV div_attributes TAG_CLOSE comment_opt div_content comment_opt DIV_CLOSE ;
div_attributes: id | id style | style id ;
div_content: div_element div_content | ;
div_element: p | a | img | form | ;

label: LABEL label_attributes TAG_CLOSE comment_opt text_opt comment_opt LABEL_CLOSE;
label_attributes: label_required label_optional | label_optional label_required;
label_required: id for | for id;
label_optional:  style | ;
text_opt:
    TEXT               { $$ = strlen($1);}
  | NUMBER             {
                char buffer[20];    
                sprintf(buffer, "%d", abs($1)); 
                $$ = strlen(buffer);}
  | TEXT text_opt      { $$ = strlen($1) + 1 + $2;free($1);}   // +1 for space
  | NUMBER text_opt    {
                char buffer[20];    
                sprintf(buffer, "%d", abs($1)); 
                $$ = strlen(buffer) + 1 + $2;}
for: FOR EQUAL STRING{
    int found = 0;
    for (int j = 0; j < input_id_counter; j++) {
        if (strcmp(input_ids[j], $3) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        fprintf(stderr, "Error at line %d: for=\"%s\" does not match any input id\n",line_num, $3);
        YYABORT;
    }

    // Εξασφάλιση μοναδικότητας for-id
    for (int j = 0; j < for_id_counter; j++) {
        if (strcmp(used_in_for[j], $3) == 0) {
            fprintf(stderr, "Error at line %d: Input id \"%s\" used in multiple <label> for attributes\n",line_num, $3);
            YYABORT;
        }
    }

    strcpy(used_in_for[for_id_counter++], $3);
};

title: TITLE comment_opt text_opt comment_opt TITLE_CLOSE{
        if ($3 > 60) {
            fprintf(stderr, "Error at line %d: Title exceeds 60 characters (%d)\n",line_num, $3);
            YYABORT;
    }
};

meta: META meta_attributes TAG_CLOSE;
meta_attributes: id charset | charset id | id name content | name content id;

charset: CHARSET EQUAL STRING;
name: NAME EQUAL STRING;
content: CONTENT EQUAL STRING;



%%

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

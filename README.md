Lexical and syntax analyzer for myHTML, an HTML-like language using Flex and Bison.

Build: flex lexer.l && bison -d parser.y && gcc lex.yy.c parser.tab.c -o myParser

Run: ./myParser test.myhtml

%{
#include "token.h"
#include <stdio.h>
%}

%option yylineno

DIGIT      [0-9]
LETTER     [a-zA-Z]
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*{0,31}
OPERATOR   [+\-*/=<>!&|^%]
STRING     \"(\\.|[^\\"])*\"
SINGLE_LINE_COMMENT "//".*
MULTI_LINE_COMMENT  [\/\*]([^*]|\*+[^*/])*\*\/

%%

[ \t\n]                  /* Skip whitespace */
{OPERATOR}               { return TOKEN_OPERATOR; }
"int"                    { return TOKEN_INT; }
"long"                   { return TOKEN_LONG; }
"short"                  { return TOKEN_SHORT; }
"long long"              { return TOKEN_LONG_LONG; }
"for"                    { return TOKEN_FOR; }
"if"                     { return TOKEN_IF; }
"else"                   { return TOKEN_ELSE; }
"return"                 { return TOKEN_RETURN; }
"break"                  { return TOKEN_BREAK; }
"continue"               { return TOKEN_CONTINUE; }
{IDENTIFIER}             { return TOKEN_IDENT; }
{DIGIT}+                 { return TOKEN_NUMBER; }
{STRING}                 { return TOKEN_STRING; }
{SINGLE_LINE_COMMENT}    { ; }
{MULTI_LINE_COMMENT}     { ; }
"#".*                    { return TOKEN_PREPROCESSOR; }
"("                      { return TOKEN_LPAREN; }
")"                      { return TOKEN_RPAREN; }
"{"                      { return TOKEN_LBRACE; }
"}"                      { return TOKEN_RBRACE; }
";"                      { return TOKEN_SEMICOLON; }
.                        { return TOKEN_ERROR; }
%%

int yywrap() { return 1; }
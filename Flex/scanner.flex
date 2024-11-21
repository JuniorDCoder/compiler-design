%{
#include "token.h"
#include <stdio.h>
%}

DIGIT      [0-9]
LETTER     [a-zA-Z]

%%
[ \t\n]                  /* Skip whitespace */
\+                       { return TOKEN_ADD; }
while                    { return TOKEN_WHILE; }
{LETTER}+                { return TOKEN_IDENT; }
{DIGIT}+                 { return TOKEN_NUMBER; }
.                        { return TOKEN_ERROR; }
%%

int yywrap() { return 1; }

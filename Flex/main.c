#include "token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern int yylineno;
extern char *yytext;

const char *token_to_string(token_t token)
{
    switch (token)
    {
    case TOKEN_EOF:
        return "EOF";
    case TOKEN_WHILE:
        return "WHILE";
    case TOKEN_ADD:
        return "ADD";
    case TOKEN_IDENT:
        return "IDENTIFIER";
    case TOKEN_NUMBER:
        return "NUMBER";
    case TOKEN_ERROR:
        return "ERROR";
    case TOKEN_OPERATOR:
        return "OPERATOR";
    case TOKEN_KEYWORD:
        return "KEYWORD";
    case TOKEN_COMMENT:
        return "COMMENT";
    case TOKEN_STRING:
        return "STRING";
    case TOKEN_PREPROCESSOR:
        return "PREPROCESSOR";
    case TOKEN_IF:
        return "IF";
    case TOKEN_ELSE:
        return "ELSE";
    case TOKEN_FOR:
        return "FOR";
    case TOKEN_RETURN:
        return "RETURN";
    case TOKEN_BREAK:
        return "BREAK";
    case TOKEN_CONTINUE:
        return "CONTINUE";
    case TOKEN_INT:
        return "INT";
    case TOKEN_LONG:
        return "LONG";
    case TOKEN_SHORT:
        return "SHORT";
    case TOKEN_LONG_LONG:
        return "LONG LONG";
    case TOKEN_LPAREN:
        return "LEFT PARENTHESIS";
    case TOKEN_RPAREN:
        return "RIGHT PARENTHESIS";
    case TOKEN_LBRACE:
        return "LEFT BRACE";
    case TOKEN_RBRACE:
        return "RIGHT BRACE";
    case TOKEN_SEMICOLON:
        return "SEMICOLON";
    default:
        return "UNKNOWN";
    }
}

int main()
{
    yyin = fopen("program.c", "r");
    if (!yyin)
    {
        printf("Could not open program.c!\n");
        return 1;
    }

    while (1)
    {
        token_t t = yylex();
        if (t == TOKEN_EOF)
            break;
        printf("token: %s, text: %s, line: %d\n", token_to_string(t), yytext, yylineno);
    }

    fclose(yyin);
    return 0;
}
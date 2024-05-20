#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {
    Token_PLUS, Token_MINUS, Token_STAR, Token_INTLIT, Token_FSLASH, Token_SEMI, Token_BSLASH, Token_PERCENT, Token_LPAREN, Token_RPAREN, Token_RETURN, Token_INT, Token_LBRACE, Token_RBRACE    
};

struct {
    int token;
    int intvalue;
};


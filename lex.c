#include "defs.h"
#include "data.h"
#include "decl.h"

static int chrpos(char *string, int c){
    char *e;
    int index;

    e = strchr(string, c);
    index = (int)(e - string);

    return (e ? index : -1);

}

static int nextchr(void){
    int c;

    c = fgetc(Infile);    

    ungetc(c, Infile);

    if ('\n' == c)
        Line++;
    return c;
}

static int skipchr(void){
    int c;

    c = nextchr();

    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c){
        c = nextchr();
    }

    return c;
}

static int scanint(int c){
    int k, val = 0;

    while ((k = chrpos("0123456789", c)) >= 0){
        val = val * 10 +k;
        c = next(); 
    }
    ungetc(c, Infile);

    return val;
}

int scan (struct token *t){
    int c;
    
    c = skip();

    //state machine for lexing
    switch (c){
    case EOF:
        return 0;
    case '+':
        t -> token = Token_PLUS;
        break;
    case '-':
        t -> token = Token_MINUS;
        break;
    case '/':
        t -> token = Token_FSLASH;
        break;
    case '*':
        t -> token = Token_STAR;
        break;
    case ';':
        t -> token = Token_SEMI;
        break;
    case '\\':
        t -> token = Token_BSLASH;
        break;
    case '%':
        t -> token = Token_PERCENT;
        break;
    case '(':
        t -> token = Token_RPAREN;
        break;
    case ')':
        t -> token = Token_LPAREN;
        break;
    case '{':
        t -> token = Token_RBRACE;
        break;
    case '}':
        t -> token = Token_LBRACE;
        break;
    case "return":
        t -> token = Token_RETURN;
        break;
    default:
        if (isdigit(c)){
            t -> intvalue = scanint(c);
            t -> token = T_INTLIT; 
            break;
        }
    printf("Unrecognized character %c on line %d\n", c, Line);

    exit(1);

    }
    return (1);
}

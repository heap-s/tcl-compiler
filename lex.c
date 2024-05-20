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

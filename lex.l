%{
#define YYSTYPE int
extern YYSTYPE yyltype;

#define LIST     strcat(buf, yytext)
#define token(t) {LIST; printf("<%s>\n", t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n", t, i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n", t, s);}

#define MAX_IDENT_LENG 16
#define MAX_LINE_LENG 256

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linenum = 1;
char buf[MAX_LINE_LENG];
bool incomment = false;

typedef struct Symbol {
        char* name;
} symbol;
int tablelen = 256;
char empty[1] = { '\0' };
symbol* table;

void create() {
        table = malloc(tablelen * sizeof(symbol));
        for (int i = 0; i < tablelen; i++) {
                table[i].name = malloc(MAX_IDENT_LENG * sizeof(char));
        }
}

int hash(char* s) {
        int idx = 0;
        for(char* c = s; *c; c++) {
                idx = (*c + (*c * *c) % tablelen) % tablelen;
        }
        return idx;
}

int getIdx(char* s, char* compare, char* negative) {
        int idx = hash(s);
        if (strcmp(table[idx].name, compare) == 0) {
                return idx;
        } else if (strcmp(table[idx].name, negative) == 0) {
                return -1;
        } else {
                for (int i = 0; i < tablelen; i++) {
                        idx = (idx + 1) % tablelen;
                        if (strcmp(table[idx].name, compare) == 0)
                                return idx;
                }
                return -1;
        }
}

int lookup(char* s) {
        return getIdx(s, s, empty);
}

void insert(char* s) {
        int idx = lookup(s);
        if (idx == -1)
                idx = getIdx(s, empty, s);
        if (idx != -1)
                strncpy(table[idx].name, s, MAX_IDENT_LENG);
}

void dump() {
        printf("Symbol table:\n");
        for (int i = 0; i < tablelen; i++) {
                if (strcmp(table[i].name, empty) == 0)
                        continue;
                printf("%s\n", table[i].name);
        }
}

%}

delimiter       [.,:;()\[\]\{\}]
op              (mod)|(and)|(or)|(:=)|(<=)|(>=)|(not)=?|[\+\-\*\/\<\>\=]
keyword         (array)|(begin)|(bool)|(char)|(const)|(decreasing)|(default)|(do)|(else)|(end)|(exit)|(false)|(for)|(function)|(get)|(if)|(int)|(loop)|(of)|(put)|(procedure)|(real)|(result)|(return)|(skip)|(string)|(then)|(true)|(var)|(when)|(then)
ident           [a-zA-Z][a-zA-Z0-9]*
nconst          ([0-9]+("."[0-9]+)?)
sconst          \"([^\"]|\"\")*\"

%Start COMMENT

%%

"{%" {
        incomment = true;
        LIST;
        BEGIN COMMENT;
}

<COMMENT>"%}" {
        incomment = false;
        LIST;
        BEGIN 0;
}

<COMMENT>"%"+/[^}] {
        LIST;
}

<COMMENT>[^\%\n]* {
        LIST;
}

"%}".*$ {
        if (incomment)
                REJECT;
        LIST;
}

"%"[^}].*$ {
        if (incomment)
                REJECT;
        LIST;
}

{delimiter} {
        token(yytext);
}

{op} {
        LIST;
        char *s = yytext;
        while(*s) {
                *s = toupper((unsigned char) *s);
                s++;
        }
        printf("<%s>\n", yytext);
}

{keyword} {
        LIST;
        char *s = yytext;
        while(*s) {
                *s = toupper((unsigned char) *s);
                s++;
        }
        printf("<%s>\n", yytext);
}

{ident} {
        tokenString("identifier", yytext);
        insert(yytext);
}

{nconst} {
        tokenInteger("integer", atoi(yytext));
}

{sconst} {
        tokenString("string", yytext);
}

[ \t]* {LIST;}

\n {
        LIST;
        printf("%d:%s", linenum++, buf);
        buf[0] = '\0';
}

. {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
}

%%

int main(int argc, char *argv[]) {
        create();

        yylex();
        fflush(yyout);

        printf("\n");
        dump();

        exit(0);
}
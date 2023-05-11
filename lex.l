%option noinput nounput
%option yylineno

%{
#define LIST     strcat(buf, yytext)
#define token(t) {LIST; printf("<%s>\n", t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n", t, i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n", t, s);}

#define MAX_LINE_LENG 256

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"
#include "y.tab.h"

int linenum = 1;
char buf[MAX_LINE_LENG];
bool incomment = false;

extern void exitProgram();

void printCaps() {
        LIST;
        char *s = yytext;
        while(*s) {
                *s = toupper((unsigned char) *s);
                s++;
        }
        printf("<%s>\n", yytext);
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
        return yytext[0];
}

(mod) {
        printCaps();
        return MOD;
}

(and) {
        printCaps();
        return AND;
}

(or) {
        printCaps();
        return OR;
}

(:=) {
        token(yytext);
        return ASSIGN;
}

(<=) {
        token(yytext);
        return LESSEQ;
}

(>=) {
        token(yytext);
        return MOREEQ;
}

(not)=? {
        printCaps();
        return NOTEQ;
}

(not)/[^=] {
        printCaps();
        return NOT;
}

[\+\-\*\/\<\>\=] {
        token(yytext);
        if (yytext[0] == '+') return PLUS;
        if (yytext[0] == '-') return MINUS;
        if (yytext[0] == '*') return MULTI;
        if (yytext[0] == '/') return DIVIDE;
        if (yytext[0] == '<') return LESS;
        if (yytext[0] == '>') return MORE;
        if (yytext[0] == '=') return EQUAL;
}

(array) {
        printCaps();
        return ARRAY;
}

(begin) {
        printCaps();
        return BEGIN_;
}

(bool) {
        printCaps();
        return BOOL;
}

(const) {
        printCaps();
        return CONST;
}

(decreasing) {
        printCaps();
        return DECREASING;
}

(default) {
        printCaps();
        return DEFAULT;
}

(do) {
        printCaps();
        return DO;
}

(else) {
        printCaps();
        return ELSE;
}

(end) {
        printCaps();
        return END;
}

(exit) {
        printCaps();
        return EXIT;
}

(false) {
        printCaps();
        yylval.b = false;
        return FALSE;
}

(for) {
        printCaps();
        return FOR;
}

(function) {
        printCaps();
        return FUNCTION;
}

(get) {
        printCaps();
        return GET;
}

(if) {
        printCaps();
        return IF;
}

(int) {
        printCaps();
        return INT;
}

(loop) {
        printCaps();
        return LOOP;
}

(of) {
        printCaps();
        return OF;
}

(put) {
        printCaps();
        return PUT;
}

(procedure) {
        printCaps();
        return PROCEDURE;
}

(real) {
        printCaps();
        return REAL;
}

(result) {
        printCaps();
        return RESULT;
}

(return) {
        printCaps();
        return RETURN;
}

(skip) {
        printCaps();
        return SKIP;
}

(string) {
        printCaps();
        return STRING;
}

(then) {
        printCaps();
        return THEN;
}

(true) {
        printCaps();
        yylval.b = true;
        return TRUE;
}

(var) {
        printCaps();
        return VAR;
}

(when) {
        printCaps();
        return WHEN;
}

(then) {
        printCaps();
        return THEN;
}

{ident} {
        tokenString("identifier", yytext);
        yylval.s = strdup(yytext);
        return IDENT;
}

{nconst} {
        double d = strtod(yytext, NULL);
        int i = atoi(yytext);
        
        if (d - (double)i == 0) {
                tokenInteger("integer", i);
                yylval.i = i;
                return NUM_INT;
        }
        else {
                tokenString("number", yytext);
                yylval.d = d;
                return NUM_REAL;
        }
}

{sconst} {
        tokenString("string", yytext);
        yylval.s = strdup(yytext);
        return SCONST;
}

[ \t]* {LIST;}

\r {}

\n {
        LIST;
        printf("%d:%s", linenum++, buf);
        buf[0] = '\0';
        return NEWLINE;
}

<<EOF>> {
        LIST;
        if (buf[0] != '\0')
                printf("%d:%s\n", linenum++, buf);
        buf[0] = '\0';
        exitProgram();
}

. {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
}

%%

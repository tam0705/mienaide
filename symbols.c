#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"

void freeArray(array* a);
void freeArguments(argument* args, int size);
void freeFunction(function* f);
void freeSymbol(symbol sy);
void freeTable(symbol* table);
int getIdx(symbol* table, char* s, char* compare, char* negative);
int hash(char* s);

typedef struct Tables {
    symbol* table;
    struct Tables* next;
} tables;

const int tablelen = 16;
char empty[1] = { '\0' };

// Symbol table is a linked list
tables* memory;

void create() {
    memory = malloc(sizeof(tables));
    memory->table = malloc(tablelen * sizeof(symbol));
    for (int i = 0; i < tablelen; i++)
        initName(&(memory->table[i].name), empty);
}

void addScope() {
    tables* newScope = malloc(sizeof(tables));
    newScope->table = malloc(tablelen * sizeof(symbol));
    for (int i = 0; i < tablelen; i++)
        initName(&(newScope->table[i].name), empty);

    // Insert at beginning
    newScope->next = memory;
    memory = newScope;
}

void deleteScope() {
    // Delete from beginning
    tables* temp = memory;
    memory = memory->next;

    // Free memory
    freeTable(temp->table);
    free(temp);
}

void dump() {
    // Delete all scopes
    while(memory)
        deleteScope();
}

void freeArray(array* a) {
    free(a);
}

void freeArguments(argument* args, int size) {
    for (int i = 0; i < size; i++) {
        if (args[i].type == tArr)
            freeArray(args[i].val.a);
    }

    free(args);
}

void freeFunction(function* f) {
    if (f->argsize > 0)
        freeArguments(f->args, f->argsize);
    free(f);
}

void freeSymbol(symbol sy) {
    free(sy.name);
    switch (sy.type) {
        case tProc:
        case tFunc: freeFunction(sy.val.f); break;
        case tArr: freeArray(sy.val.a); break;
    }
}

void freeTable(symbol* table) {
    for (int i = 0; i < tablelen; i++) {
        freeSymbol(table[i]);
    }

    free(table);
}

symbol createSymbol(char* name, int type, ssymbol ssy) {
    symbol sy;

    initName(&sy.name, name);
    sy.isConst = ssy.isConst;
    sy.type = type;
    sy.valType = ssy.valType;
    sy.val = ssy.val;

    return sy;
}

symbol createArray(char* name, int valType, int firstIndex, int lastIndex) {
    symbol sy;

    initName(&sy.name, name);
    sy.isConst = false;
    sy.type = tArr;
    sy.valType = valType;
    sy.val.a = malloc(sizeof(array));

    sy.val.a->first = firstIndex;
    sy.val.a->last = lastIndex;
    sy.val.a->size = lastIndex - firstIndex + 1;

    return sy;
}

symbol createEmptyFunction(char* name, bool isProcedure) {
    symbol sy;

    initName(&sy.name, name);
    sy.isConst = false;
    sy.type = (isProcedure) ? tProc : tFunc;
    sy.val.f = malloc(sizeof(function));

    return sy;
}

ssymbol createBool(bool val, bool isConst) {
    ssymbol ssy;

    ssy.isConst = isConst;
    ssy.type = tVar;
    ssy.valType = tBool;

    return ssy;
}

ssymbol createInt(int val, bool isConst) {
    ssymbol ssy;

    ssy.isConst = isConst;
    ssy.type = tVar;
    ssy.valType = tInt;

    return ssy;
}

ssymbol createReal(double val, bool isConst) {
    ssymbol ssy;

    ssy.isConst = isConst;
    ssy.type = tVar;
    ssy.valType = tReal;

    return ssy;
}

ssymbol createString(char* val, bool isConst) {
    ssymbol ssy;

    ssy.isConst = isConst;
    ssy.type = tVar;
    ssy.valType = tString;

    return ssy;
}

ssymbol symbolToSmall(symbol sy) {
    ssymbol ssy;

    ssy.isConst = sy.isConst;
    ssy.type = sy.type;
    ssy.valType = sy.valType;
    ssy.val = sy.val;

    return ssy;
}

symbol* lookup(char* s) {
    // Find symbol from most local scope to most global scope
    tables* it = memory;
    while(it) {
        int idx = getIdx(it->table, s, s, empty);
        if (idx != -1)
            return &it->table[idx];
        it = it->next;
    }
    return NULL;
}

int hash(char* s) {
        int idx = 0;
        for(char* c = s; *c; c++) {
                idx = (*c + (*c * *c) % tablelen) % tablelen;
        }
        return idx;
}

int getIdx(symbol* table, char* s, char* compare, char* negative) {
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

int insertLookup(char* s) {
    // Find whether this symbol name exists in CURRENT scope
    // And if not, return a vacant index
    
    int idx = getIdx(memory->table, s, s, empty);
    if (idx == -1)
        idx = getIdx(memory->table, s, empty, s);
    else
        return ERR_ALREADY_EXISTS;

    if (idx == -1)
        return ERR_TABLE_FULL;

    return idx; 
}

void insertSymbol(symbol sy, int idx) {
    free(memory->table[idx].name);
    memory->table[idx] = sy;
}

void initName(char** var, char* val) {
    *var = malloc(MAX_IDENT_LENG * sizeof(char));
    strncpy(*var, val, MAX_IDENT_LENG);
}

void initString(char** var, char* val) {
    *var = malloc(MAX_STRING_LENG * sizeof(char));
    strncpy(*var, val, MAX_STRING_LENG);
}

bool isBothNumber(int type1, int type2) {
        return (type1 == tInt || type1 == tReal) && (type2 == tInt || type2 == tReal);
}

ssymbol opNumber(ssymbol n1, ssymbol n2, int op) {
    if (op >= oLess)
        return createBool(true, !n1.isConst || !n2.isConst); // Temporary
    return n1;
}

bool isFuncEqual(function f1, function f2) {
    if (f1.argsize != f2.argsize) return false;

    for (int i = 0; i < f1.argsize; i++) {
        if (f1.args[i].type != f2.args[i].type) return false;
        if (f1.args[i].valType != f2.args[i].valType) return false;
        if (f1.args[i].type == tArr) {
            if (f1.args[i].val.a->size != f2.args[i].val.a->size) return false;
        }
    }

    return true;
}
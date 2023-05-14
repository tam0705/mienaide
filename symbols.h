#ifndef SYMBOLS_H
#define SYMBOLS_H
#define MAX_IDENT_LENG 32
#define MAX_STRING_LENG 64

enum SymbolType { tVar, tArr, tProc, tFunc };
enum ValueType { tInt, tReal, tBool, tString, tImplicit, tError, tNull };
enum Operator { oPlus, oMin, oMul, oDiv, oMod, oLess, oMore, oLessEq, oMoreEq, oEqual, oNotEq };
enum LookupError { ERR_ALREADY_EXISTS = -1, ERR_TABLE_FULL = -2 };

typedef struct Array array;
typedef struct Function function;
typedef struct Argument argument;
typedef struct ArgumentList argList;
typedef struct Symbol symbol;
typedef struct SmallSymbol ssymbol;

typedef union Value value;

union Value {
	array* a;
	function* f;
};

struct Array {
	int first, last;
	int size;
};

struct Function {
	argument* args;
	int argsize;
};

struct Argument {
	int type;
	int valType;
	value val;
};

struct Symbol {
    char* name;
	int type;
    int valType;
    bool isConst;
	value val;
};

struct SmallSymbol {
	int type;
    int valType;
    bool isConst;
	value val;
};

void create();
void addScope();
void deleteScope();
void dump();

symbol createSymbol(char* name, int type, ssymbol ssy);
symbol createArray(char* name, int valType, int firstIndex, int lastIndex);
symbol createEmptyFunction(char* name, bool isProcedure);
ssymbol createBool(bool val, bool isConst);
ssymbol createInt(int val, bool isConst);
ssymbol createReal(double val, bool isConst);
ssymbol createString(char* val, bool isConst);

ssymbol symbolToSmall(symbol sy);

symbol* lookup(char* s);
symbol* lookupSkip(char* s, int skipScope);

int insertLookup(char* s);
void insertSymbol(symbol sy, int idx);

void initName(char** var, char* val);
void initString(char** var, char* val);

bool isBothNumber(int type1, int type2);
ssymbol opNumber(ssymbol n1, ssymbol n2, int op);

void copyFunction(function from, function* to);
bool isFuncEqual(function f1, function f2);

#endif
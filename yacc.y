/* 
    B10915013 Compiler Project 2

    This is the YACC file for Project 2: Syntax Analysis (Parser).
    This comment is written in order to help TA giving grades to me ;)

    First of all, to check what parser errors I have implemented, please do Ctrl+F and find for 'yyerror' and 'fprintf'.
    To check all explanations I've written for my statements, please find for '//'.

    Furthermore, I've implemented symbol table and other utilities in the files symbols.h and symbols.c.
    These files contain the symbol table, the structures, and the utility functions I used.

    My symbol table is a linked list.
    When there is a new scope, I add a table in the beginning of the list.
    When I want to delete a scope, I simply remove the head of the list.

    Symbol lookups are started from the beginning of the list, i.e. the most local scope.
    That means if there are two variables i in local and global scope, it would return the local i first.

    Currently, there are some restrictions:
    - The maximum identifier name length is 32
    - The maximum string length is 64
    - Each scope has a symbol table of maximum 24 symbols
    These restrictions are applied to consider the memory.

    The structures that I use are:
    - Symbol. To be put into symbol table.
        It has a union called Value, which contains pointers to
        - Function. Stores arguments.
        - Array. Stores its first and last index. And its size.
    - Small symbol. Similar to symbol, except it has no name.
        Typically used in my grammar to check value types and symbol type (variable, array, or etc.)
        Small symbols are not stored into the symbol table.
    
    In this assigment, I do not store the values of symbols, but rather just their value types.
    However, call-by-value parameter passing mechanism is still implemented.
    Everytime I look up for a pointer to a symbol, I pass its values rather than its address to the grammar.
    For reference, please Ctrl+F 'symbolToSmall', a function used to convert symbols to small symbols.
    
    The enumerations that I use are:
    - Symbol type. There are four:
        - tVar for variables and constants
        - tArr for arrays
        - tFunc for functions
        - tProc for procedures
    - Value type:
        - tInt, tReal, tBool, and tString. You know what these are.
        - tImplicit
            Used in implicit variable declarations.
            This tells the parser to decide the variable type by looking at the expression.
        - tError
            Currently has no use.
        - tNull
            Typically used to propagate return type to procedure,
            indicating that there is no 'result' statement in its body.
    - Operator types. Used to translate operator tokens to enums, enabling my symbols files to recognize them.
    - Lookup errors. There are currently two:
        - ERR_ALREADY_EXISTS: When you want to insert a symbol into the table, but a symbol with the same name in current scope already exists.
        - ERR_TABLE_FULL: When you want to insert a symbol into the table, but the table of current scope is already full.

    Regarding numbers, I've allowed mixed operations between integers and reals.
    When there is a real number in an expression, the whole expression will have value type real.
    Assignment of a real to an integer and vice versa are also allowed.
*/

%{
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.h"

#define trace(t) printf(">> Grammar: %s\n", t);

extern int yylineno;
extern FILE* yyin;
extern FILE* yyout;

int yylex();
void yyerror(char *s);
int yywrap();
void exitProgram();
int main(int argc, char *argv[]);
%}

%start program

%union {
    bool b;
    double d;
    int i;
    char* s;
    symbol sy;
    ssymbol ssy;
    argument a;
    function f;
}

%token NEWLINE
%token ARRAY BEGIN_ BOOL CONST DECREASING DEFAULT DO ELSE END EXIT FOR FUNCTION GET IF INT LOOP OF PUT PROCEDURE REAL RESULT RETURN SKIP STRING THEN VAR WHEN
%token PLUS MINUS MULTI DIVIDE LESS MORE EQUAL
%token <b> TRUE FALSE
%token <d> NUM_REAL
%token <i> NUM_INT
%token <s> IDENT SCONST

%type <i> decopt vtype body statement simple
%type <a> argument
%type <sy> arr_ref
%type <ssy> expr term call
%type <f> arguments argument_list cargs carg_list

%left ','
%right ASSIGN
%left OR
%left AND
%left LESS MORE EQUAL NOTEQ LESSEQ MOREEQ
%left MINUS PLUS
%left MULTI DIVIDE MOD
%nonassoc UMINUS
%right NOT
%left '(' ')' '[' ']'

%%

// Main program
program: progdecl statement_part;

// First part of program: constant, variable, array, function, or procedure declarations
progdecl : progdecl constdec NEWLINE
         | progdecl vardec NEWLINE
         | progdecl arrdec NEWLINE
         | progdecl funcdec NEWLINE
         | progdecl procdec NEWLINE
         | progdecl NEWLINE
         | ;

// Second part of program: statements
statement_part: statement_part statement NEWLINE
              | statement_part NEWLINE
              | ;

// Types of statements
// $$ stores return type, is used to check function and procedure return type
statement : block { $$ = tNull; }
          | simple { $$ = $1; }
          | expr { $$ = tNull; }
          | conditional { $$ = tNull; }
          | loop { $$ = tNull; };

// Begin - end block
// Add scope when entering, remove scope when leaving
block : BEGIN_ { addScope(); } body { deleteScope(); } END;

// Simple statements
// $$ stores return type, is used to check function and procedure return type
simple : IDENT ASSIGN expr {
            char* name = $1;
            ssymbol ssy = $3;

            symbol* sy = lookup(name);

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            
            if (sy->type != tVar)
                yyerror("Trying to assign a value to a non-variable");
            
            if (sy->isConst)
                yyerror("Trying to assign a value to a constant");
            
            if (ssy.type == tArr)
                yyerror("Trying to assign an array to a variable");
            
            if (sy->valType != ssy.valType)
                yyerror("Conflicting assignment types");
            
            $$ = tNull;
       }
       | arr_ref ASSIGN expr {
            symbol sy = $1;
            ssymbol ssy = $3;

            if (ssy.type == tArr)
                yyerror("Trying to assign an array to a variable");

            if (sy.valType != ssy.valType)
                yyerror("Conflicting assignment types");
            
            $$ = tNull;
       }
       | PUT expr { $$ = tNull; }
       | GET IDENT { $$ = tNull; }
       | GET arr_ref { $$ = tNull; }
       | RESULT expr {
            if ($2.type == tArr)
                yyerror("Invalid result expression: array");
            $$ = $2.valType;
       }
       | RETURN { $$ = tNull; }
       | EXIT { $$ = tNull; }
       | EXIT WHEN expr {
            if ($3.type == tArr)
                yyerror("Trying to assign an array to a conditional");
            if ($3.valType != tBool)
                yyerror("Trying to assign a non-boolean expression to a conditional");
            
            $$ = tNull;
       }
       | SKIP { $$ = tNull; };

// Conditionals have their own scopes
conditional : if_front
              ELSE { addScope(); }
              body { deleteScope(); }
              END IF
            | if_front
              END IF;

if_front : IF expr THEN {
                addScope();
                if ($2.type == tArr)
                    yyerror("Trying to assign an array to a conditional");
                if ($2.valType != tBool)
                    yyerror("Trying to assign a non-boolean expression to a conditional");
           }
           body { deleteScope(); };

// Loops have their own scopes
loop : LOOP { addScope(); }
       body { deleteScope(); }
       END LOOP
     | FOR for_option IDENT ':' expr '.' '.' expr NEWLINE {
            if ($5.valType != tInt || $8.valType != tInt ||
                !$5.isConst || !$8.isConst ||
                $5.type == tArr || $8.type == tArr)
                yyerror("Invalid for loop range, perhaps it's not numeric or constant?");
            
            char* name = $3;

            symbol* sy = lookup(name);

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            if (sy->isConst)
                yyerror("Iterator cannot be constant");
            if (sy->type != tVar || !(sy->type == tInt || sy->type == tReal))
                yyerror("Iterator must be a numeric variable");

            addScope();
       }
       body { deleteScope(); }
       END FOR;

for_option : DECREASING | ;

// Body of a block, conditional, etc.
// $$ stores return type, is used to check function and procedure return type
body : body constdec NEWLINE  { $$ = $1; }
     | body vardec NEWLINE  { $$ = $1; }
     | body arrdec NEWLINE  { $$ = $1; }
     | body statement NEWLINE  { $$ = $2; }
     | body NEWLINE  { $$ = $1; }
     | { $$ = tNull; };

// Constant declaration
// expr must be a constant expression (is checked using boolean isConst)
constdec : CONST IDENT decopt ASSIGN expr {
            char* name = $2;
            int valType = $3;
            ssymbol ssy = $5;

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            if (valType == tImplicit)
                valType = ssy.valType;
            else if (valType != ssy.valType) {
                if (!isBothNumber(valType, ssy.valType))
                    yyerror("Mismatching declaration type and value type");
            }

            if (!ssy.isConst)
                yyerror("Trying to assign non-constant expression to a constant declaration");

            symbol sy = createSymbol(name, tVar, ssy);
            sy.isConst = true;

            insertSymbol(sy, idx);
        };

// Variable declaration
// expr must be a constant expression (is checked using boolean isConst)
vardec : VAR IDENT decopt ASSIGN expr {
            char* name = $2;
            int valType = $3;
            ssymbol ssy = $5;

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            if (valType == tImplicit)
                valType = ssy.valType;
            else if (valType != ssy.valType) {
                if (!isBothNumber(valType, ssy.valType))
                    yyerror("Mismatching declaration type and value type");
            }

            if (!ssy.isConst)
                yyerror("Trying to assign non-constant expression to a variable declaration");

            symbol sy = createSymbol(name, tVar, ssy);
            sy.isConst = false;

            insertSymbol(sy, idx);
       }
       | VAR IDENT ':' vtype {
            char* name = $2;
            int valType = $4;

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            ssymbol ssy;
            ssy.valType = valType;

            symbol sy = createSymbol(name, tVar, ssy);
            sy.isConst = false;

            insertSymbol(sy, idx);
       };

// Declaration type which can be omitted
// When omitted $$ will be tImplicit
decopt : ':' vtype { $$ = $2; }
       | { $$ = tImplicit; };

// Array declaration
arrdec : VAR IDENT ':' ARRAY NUM_INT '.' '.' NUM_INT OF vtype {
            char* name = $2;
            int first = $5, last = $8;
            int valType = $10;

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            if (first >= last)
                yyerror("Attempted to create an array of invalid size");

            symbol sy = createArray(name, valType, first, last);

            insertSymbol(sy, idx);
       };

// Function declaration
funcdec : FUNCTION IDENT {
            char* name = $2;
            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            symbol sy = createEmptyFunction(name, false);
            insertSymbol(sy, idx);

            addScope();

          } '(' arguments ')' ':' vtype NEWLINE {
            function f = $5;
            int valType = $8;

            symbol* sy = lookup($2);
            sy->valType = valType;
            copyFunction(f, sy->val.f);

            addScope(); 
          }
          body {
            int valType = $8;
            int returnType = $11;
            if (valType != returnType)
                yyerror("Function must have correct result type");

            deleteScope(); deleteScope();
          }
          END IDENT {
                if (strcmp($2, $14) != 0)
                    yyerror("End function name does not match");
          };

// Procedure declaration
procdec : PROCEDURE IDENT {
            char* name = $2;
            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            symbol sy = createEmptyFunction(name, true);
            insertSymbol(sy, idx);

            addScope();

          } '(' arguments ')' NEWLINE {
            function f = $5;

            symbol* sy = lookup($2);
            sy->valType = tNull;
            copyFunction(f, sy->val.f);

            addScope(); 
          }
          body {
            int returnType = $9;
            if (returnType != tNull)
                yyerror("Procedure cannot have result type");

            deleteScope(); deleteScope();
          }
          END IDENT {
                if (strcmp($2, $12) != 0)
                    yyerror("End function name does not match");
          };;

// Arguments for function and procedure
arguments : argument_list argument {
                function f = $1;
                f.argsize++;
                if (f.argsize == 1)
                    f.args = malloc(sizeof(argument));
                else
                    f.args = realloc(f.args, f.argsize * sizeof(argument));
                f.args[f.argsize - 1] = $2;
                $$ = f;
          }
          | {
                function f;
                f.argsize = 0;
                $$ = f;
          };

// Recursive statement for arguments
argument_list : argument_list argument ',' {
                    function f = $1;
                    f.argsize++;
                    if (f.argsize == 1)
                        f.args = malloc(sizeof(argument));
                    else
                        f.args = realloc(f.args, f.argsize * sizeof(argument));
                    f.args[f.argsize - 1] = $2;
                    $$ = f;
              }
              | {
                    function f;
                    f.argsize = 0;
                    $$ = f;
              };

// Recursive component for arguments
argument : IDENT ':' vtype {
            char* name = $1;
            int valType = $3;

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            argument a;
            a.type = tVar;
            a.valType = valType;       
            
            ssymbol ssy;
            ssy.valType = valType;
            ssy.isConst = false;

            symbol sy = createSymbol(name, tVar, ssy);
            insertSymbol(sy, idx);

            $$ = a;
         }
         | IDENT ':' ARRAY NUM_INT '.' '.' NUM_INT OF vtype {
            char* name = $1;
            int first = $4, last = $7;
            int valType = $9;

            int idx = insertLookup(name);
            if (idx == ERR_ALREADY_EXISTS)
                yyerror("Identifier already declared in this scope");
            else if (idx == ERR_TABLE_FULL)
                yyerror("Current scope's symbol table is full");

            argument a;
            a.type = tArr;
            a.valType = valType;
            a.val.a = malloc(sizeof(array));

            a.val.a->first = first;
            a.val.a->last = last;
            a.val.a->size = last - first + 1;
            
            ssymbol ssy;
            ssy.type = a.type;
            ssy.valType = valType;
            ssy.isConst = false;
            ssy.val.a = a.val.a;

            symbol sy = createSymbol(name, tArr, ssy);
            insertSymbol(sy, idx);

            $$ = a;
         };

// Value types. Stored as int in $$
vtype : BOOL { $$ = tBool; }
      | REAL { $$ = tReal; }
      | INT { $$ = tInt; }
      | STRING  { $$ = tString; };

// Expressions
// All types of expressions involving all types of values are declared here
// To check what type of expression it is, (whether it is numeric, boolean, constant, etc.),
// it will return a structure storing these important values
expr : expr MINUS expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        $$ = opNumber($1, $3, oMin);
     }
     | expr PLUS expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        $$ = opNumber($1, $3, oPlus);
     }
     | expr MULTI expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        $$ = opNumber($1, $3, oMul);
     }
     | expr DIVIDE expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        $$ = opNumber($1, $3, oDiv);
     }
     | expr MOD expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal numeric operation, an operand is not numeric");
        
        $$ = opNumber($1, $3, oMod);
     }
     | expr LESS expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        $$ = opNumber($1, $3, oLess);
     }
     | expr MORE expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        $$ = opNumber($1, $3, oMore);
     }
     | expr LESSEQ expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        $$ = opNumber($1, $3, oLessEq);
     }
     | expr MOREEQ expr {
        if (!isBothNumber($1.valType, $3.valType) || $1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is not numeric");
        
        $$ = opNumber($1, $3, oMoreEq);
     }
     | expr EQUAL expr {
        if ($1.valType != $3.valType) {
            if (!isBothNumber($1.valType, $3.valType))
                yyerror("Illegal comparison, both operands have different value types");
        }
        if ($1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is an array");

        if (isBothNumber($1.valType, $3.valType))
            $$ = opNumber($1, $3, oEqual);
        else {
            $$ = $1;
            $$.valType = tBool;
        }

        if (!$1.isConst || !$3.isConst)
            $$.isConst = false;
     }
     | expr NOTEQ expr {
        if ($1.valType != $3.valType) {
            if (!isBothNumber($1.valType, $3.valType))
                yyerror("Illegal comparison, both operands have different value types");
        }
        if ($1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is an array");

        if (isBothNumber($1.valType, $3.valType))
            $$ = opNumber($1, $3, oNotEq);
        else {
            $$ = $1;
            $$.valType = tBool;
        }

        if (!$1.isConst || !$3.isConst)
            $$.isConst = false;
     }
     | expr AND expr {
        if ($1.valType != tBool || $3.valType != tBool)
            yyerror("Illegal boolean operation, an operand is not a boolean");
        if ($1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is an array");
        
        $$ = $1;

        if (!$1.isConst || !$3.isConst)
            $$.isConst = false;
     }
     | expr OR expr {
        if ($1.valType != tBool || $3.valType != tBool)
            yyerror("Illegal boolean operation, an operand is not a boolean");
        if ($1.type == tArr || $3.type == tArr)
            yyerror("Illegal comparison, an operand is an array");
        
        $$ = $1;

        if (!$1.isConst || !$3.isConst)
            $$.isConst = false;
     }
     | term { $$ = $1; };

// A component for expression
// Includes number, boolean, string, function invocation, array reference, variables, etc.
term : '(' expr ')' { $$ = $2; }
     | MINUS term %prec UMINUS {
        if ($2.valType != tInt && $2.valType != tReal)
            yyerror("Illegal unary operation, attempted to negate a non-integer");
        
        $$ = $2;
     }
     | NOT term {
        if ($2.valType != tBool)
            yyerror("Illegal unary operation, attempted to negate a non-boolean");
        
        $$ = $2;
     }
     | arr_ref { 
        $$ = symbolToSmall($1);
        $$.type = tVar;
     }
     | call { $$ = $1; }
     | IDENT {
        symbol* sy = lookup($1);

        if (sy == NULL)
            yyerror("Unrecognized identifier");
        
        if (sy->type == tProc || sy->type == tFunc)
            yyerror("Attempted to invoke a function/procedure without brackets '()'");
        
        if (sy->type == tFunc) {
            if (sy->val.f->argsize > 0) {
                fprintf(stderr, "Syntax error in line %d: Invalid function invocation, expected %d arguments but called with %d\n", yylineno, sy->val.f->argsize, 0);
                exitProgram();
            }
        }

        $$ = symbolToSmall(*sy);
     }
     | NUM_INT  { $$ = createInt($1, true); }
     | NUM_REAL  { $$ = createInt($1, true); }
     | SCONST  { $$ = createString($1, true); }
     | TRUE { $$ = createBool($1, true); }
     | FALSE { $$ = createBool($1, true); };

// Array reference
arr_ref : IDENT '[' expr ']' {
            symbol* sy = lookup($1);

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            
            if (sy->type != tArr)
                yyerror("Illegal operation, trying to access a non-array as an array");
            
            ssymbol ssy = $3;

            if (ssy.type == tArr || ssy.valType != tInt)
                yyerror("Illegal array reference, expression inside [] must be an integer");

            // Temporary closed, this HW does not store value
            //if (idx < sy->val.a->first || idx > sy->val.a->last)
            //    yyerror("Illegal access, array index out of bounds");
            
            // Temporary
            $$ = *sy;
            $$.type = tVar;
        };

// Function/procedure invocation that HAS arguments
call : IDENT '(' cargs ')' {
            symbol* sy = lookup($1);

            if (sy == NULL)
                yyerror("Unrecognized identifier");
            
            if (sy->type != tFunc && sy->type != tProc)
                yyerror("Trying to call a non-function identifier");

            function originalF = *(sy->val.f);
            function passedF = $3;

            if (!isFuncEqual(originalF, passedF))
                yyerror("Invalid function invocation, possible reasons are invalid argument size, type, or array bounds");
            
            $$ = symbolToSmall(*sy);
     };

// Arguments just for function invocation
cargs : carg_list expr {
            function f = $1;
            f.argsize++;
            if (f.argsize == 1)
                f.args = malloc(sizeof(argument));
            else
                f.args = realloc(f.args, f.argsize * sizeof(argument));

            ssymbol ssy = $2;

            argument a;
            a.type = ssy.type;
            a.valType = ssy.valType;
            a.val = ssy.val;

            f.args[f.argsize - 1] = a;
            $$ = f;
      }
      | carg_list { $$ = $1; };

// Recursive part for arguments for invocation
carg_list : carg_list expr ',' {
                function f = $1;
                f.argsize++;
                if (f.argsize == 1)
                    f.args = malloc(sizeof(argument));
                else
                    f.args = realloc(f.args, f.argsize * sizeof(argument));

                ssymbol ssy = $2;

                argument a;
                a.type = ssy.type;
                a.valType = ssy.valType;
                a.val = ssy.val;

                f.args[f.argsize - 1] = a;
                $$ = f;
          }
          | {
                function f;
                f.argsize = 0;
                $$ = f;
          };

%%

int yywrap() {
    return 1;
}

void yyerror(char* s) {
    fprintf(stderr, "Syntax error in line %d: %s\n", yylineno, s);
    exitProgram();
}

void exitProgram() {
    // Free memory pointers before exiting
    fflush(yyout);

    dump();

    exit(1);
}

int main(int argc, char *argv[]) {
    // Create symbol table
    create();

    // Open the source program file
    if (argc != 2) {
        printf("Usage: ./prog <filename>\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");

    // Perform parsing
    int parse = yyparse();
    
    // Free memory (pointers)
    fflush(yyout);

    dump();

    return parse;
}

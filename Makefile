prog: y.tab.c lex.yy.c symbols.h symbols.c
	gcc -Wall -o prog y.tab.c lex.yy.c symbols.c -ll

lex.yy.c: lex.l y.tab.h
	lex lex.l

y.tab.c: yacc.y
	yacc -d -v -Wother yacc.y

clean:
	rm -f lex.yy.c y.tab.c
LEX=flex
YACC=bison
CC=g++

bc:	calc.tab.o lex.yy.o symTable.o
	$(CC) -o bc symTable.o calc.tab.o lex.yy.o -lfl -lm

lex.yy.o:				lex.yy.cc calc.tab.hpp

lex.yy.o calc.tab.o:			general.h

calc.tab.cpp calc.tab.hpp:		calc.ypp
				$(YACC) -d calc.ypp

lex.yy.cc:				calc.l
				$(LEX) -+ calc.l

symTable.o:				symTable.cpp symTable.h general.h
			$(CC) -c symTable.cpp

clean:
	rm bc lex.yy.* calc.tab.* symTable.o

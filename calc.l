%{
#include"symTable.h"
#include"calc.tab.hpp" /*this will be created by lex*/

extern Symbol_table table;

yyFlexLexer lexer;
int yylex(void){
	return lexer.yylex();
}

%}

%option noyywrap
delim	[ \t]
ws	{delim}+
letter	[a-z]
id	{letter}({letter}|{digit})*
digit	[0-9]
number	{digit}+

%%
"dump"		{return(DUMP);}
"quit"		{return(QUIT);}
{ws}		{/* no action */}
{id}		{yylval.symbol_ptr=table.insert(yytext);return(ID);}
{number}	{yylval.val.ivalue=atoi(yytext);return(NUMBER);}
"\n"		{return(NEWLINE);}
"+"		{return(PLUS);}
"-"		{return(MINUS);}
"*"		{return(MULT);}
"/"		{return(DIV);}
"%"		{return(MOD);}
"^"		{return(CARROT);}
"("		{return(LPAREN);}
")"		{return(RPAREN);}
"="		{return(EQUAL);}
%%

%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "model/tree.h"
#include "grammar.tab.hpp"
#include "model/token.h"
#include "model/scopeMan.h"
#include "model/scope.h"
#include "model/node.h"

void echo(char *);
%}

ident [a-zA-z][a-zA-Z0-9]*
num [0-9]+
whitespace [ \t]+

%%

"program" {echo("PROGRAM"); return PROGRAM; }
"id" {echo("ID"); return ID; }
"var" {echo("VAR"); return VAR; }
"array" {echo("ARRAY"); return ARRAY; }
"of" {echo("OF"); return OF; }
"num" {echo("NUM"); return NUM; }
".." {echo("DOTDOT"); return DOTDOT; }
":=" {echo("ASSIGNOP"); return ASSIGNOP;}
"integer" {echo("INTEGER"); return INTEGER; }
"real" {echo("REAL"); return REAL; }
"function" {echo("FUNCTION"); return FUNCTION; }
"procedure" {echo("PROCEDURE"); return PROCEDURE; }
"begin" {echo("BBEGIN"); return BBEGIN; }
"end" {echo("END"); return END; }
"assignop" {echo("ASSIGNOP"); return ASSIGNOP; }
"if" {echo("IF"); return IF; }
"then" {echo("THEN"); return THEN; }
"else" {echo("ELSE"); return ELSE; }
"while" {echo("WHILE"); return WHILE; }
"do" {echo("DO"); return DO; }
"relop" {echo("RELOP"); return RELOP; }
"addop" {echo("ADDOP"); return ADDOP; }
"mulop" {echo("MULOP"); return MULOP; }
"not" {echo("NOT"); return NOT; }

"="  {fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = EQ; return RELOP; }
"<>" {fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = NE; return RELOP; }
"<"  {fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = LT; return RELOP; }
"<=" {fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = LE; return RELOP; }
">"  {fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = GT; return RELOP; }
">=" {fprintf(stderr, "RELOP[%s]", yytext); yylval.opval = GE; return RELOP; }

"or" {fprintf(stderr, "ADDOP[%s]", yytext); yylval.opval = OR; return ADDOP; }
"+"  {fprintf(stderr, "ADDOP[%s]", yytext); yylval.opval = PLUS; return ADDOP; }
"-"  {fprintf(stderr, "ADDOP[%s]", yytext); yylval.opval = MINUS; return ADDOP; }

"and"  {fprintf(stderr, "MULOP[%s]", yytext); yylval.opval = AND; return MULOP; }
"*"    {fprintf(stderr, "MULOP[%s]", yytext); yylval.opval = STAR; return MULOP; }
"/"    {fprintf(stderr, "MULOP[%s]", yytext); yylval.opval = SLASH; return MULOP; }

{num} {fprintf(stderr, "INTEGER[%d]", atoi(yytext)); yylval.ival = atoi(yytext); return INTEGER; }
{num}"."{num} {fprintf(stderr, "INTEGER[%f]", atof(yytext)); yylval.rval = atof(yytext); return REAL;}
{ident} {fprintf(stderr, "ID[%s]", yytext); yylval.sval = strdup(yytext); return ID; }

{whitespace} { ; }
\n {echo(yytext);}
. {fprintf(stderr, "<%c>", yytext[0]); return yytext[0]; }

%%

void echo(char *message)
{
	fprintf(stderr, "%s", message);
}

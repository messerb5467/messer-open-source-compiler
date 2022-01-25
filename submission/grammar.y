%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "model/token.h"
#include "model/tree.h"
#include "model/node.h"
#include "model/scope.h"
#include "model/scopeMan.h"

extern void yyerror(char *);
extern int yylex();
extern int yyparse();

extern ScopeManager *sman;
extern Scope *s;
extern Node *n;
extern Tree *treeVal;
%}

%union
{
	/*Scanner connection*/
	int ival;
	float rval;
	char *sval;
	int opval;

	/*Semantic evaluation connection and gencode connection*/
	Tree *tval;
}

%token <opval> ADDOP
%token AND
%token ARRAY
%token ASSIGNOP
%token BBEGIN
%token DO
%token DOTDOT
%token ELSE
%token END
%token EQ
%token FUNCTION
%token GE
%token GT
%token <sval> ID
%token IF
%token <ival> INTEGER
%token LE
%token LIST
%token LT
%token MINUS
%token <opval> MULOP
%token NE
%token NOT
%token NUM
%token OF
%token OR
%token PLUS
%token PROCEDURE
%token PROGRAM
%token <rval> REAL
%token <opval> RELOP
%token SLASH
%token STAR
%token THEN
%token VAR
%token WHILE

%type <tval> expression
%type <tval> expression_list
%type <tval> simple_expression
%type <tval> term
%type <tval> factor

%%

program:
	{
		sman = new ScopeManager();
		s = new Scope();
		sman->push(s);
	}
	PROGRAM ID '(' identifier_list ')'';'
	declarations
	subprogram_declarations
	compound_statement
	'.'
	{
		sman->pop();
		s = NULL;
		sman = NULL;
	}
	;

identifier_list
	: ID
		{
			s->insert($1);
		
			//$$ = new Tree(Token(ID, $1), NULL, NULL); 
		}
	| identifier_list ',' ID
		{s->insert($3); }
	;

declarations
	: declarations VAR identifier_list ':' type ';'
	| /* empty */
	;

type
	: standard_type
	| ARRAY '[' NUM DOTDOT NUM ']' OF standard_type
	;

standard_type
	: INTEGER
	| REAL
	;


subprogram_declarations
	: subprogram_declarations subprogram_declaration ';'
	| /* empty */
	;

subprogram_declaration
	: subprogram_head declarations subprogram_declarations compound_statement
		{sman->pop(); }
	;

subprogram_head
	: FUNCTION ID 
		{
			s->insert($2);
			s = NULL;
			s = new Scope();
			sman->push(s);
		}
		arguments ':' standard_type ';'

	| PROCEDURE ID 
		{
			s->insert($2);
			s = NULL;
			s = new Scope();
			sman->push(s);
		}
		arguments ';'
	;

arguments
	: '(' parameter_list ')'
	;

parameter_list
	: identifier_list ':' type
		{
			/*Build an association between the type and generated parameters
				Here, the parameter type will need to be inserted for each parameter
				placed into the table.
			*/
		}
	| parameter_list ';' identifier_list ':' type
		{
			//Build an association between the type and generated parameters
		}
	;

/*Statement*/
compound_statement
	: BBEGIN optional_statements END
	;

optional_statements
	: statement_list
	| /*empty*/
	;

statement_list
	: statement
	| statement_list ';' statement
	;

statement
	: variable ASSIGNOP expression
		{
			fprintf(stderr, "\n\nPrinting Tree:\n");
			$3->print(0);
			fprintf(stderr, "\n\n");
			//$$ = new Tree(Token(ASSIGNOP, $2), $1, $3); 
		}
	| procedure_statement
	| compound_statement
	| IF expression THEN statement ELSE statement
	| WHILE expression DO statement
	;

variable
	: ID
		{//$$ = new Tree(Token(ID, $1), NULL, NULL); 
		}
	| ID '[' expression ']'
	;

procedure_statement
	: ID
	| ID '(' expression_list ')'
	;

/*expressions*/

expression_list
	: expression
		{$$ = $1; }
	| expression_list ',' expression
		{$$ = new Tree(Token(LIST), $1, $3); }
	;

expression
	: simple_expression
		{$$ = $1; }
	| simple_expression RELOP simple_expression
		{$$ = new Tree(Token(RELOP, $2), $1, $3); }
	;

simple_expression
	: term
		{$$ = $1; }
	| ADDOP term
		{$$ = new Tree(Token(ADDOP, $1), NULL, $2); }
	| simple_expression ADDOP term
		{$$ = new Tree(Token(ADDOP, $2), $1, $3); }
	;

term
	: factor
		{$$ = $1; }
	| term MULOP factor
		{$$ = new Tree(Token(MULOP, $2), $1, $3); }
	;

factor
	: ID
		{$$ = new Tree(Token(ID, $1), NULL, NULL); }
	| ID '(' expression_list ')'
		{$$ = new Tree(Token(ID, $1), NULL, $3); }
	| INTEGER
		{$$ = new Tree(Token(INTEGER, $1), NULL, NULL); }
	| REAL
		{$$ = new Tree(Token(REAL, $1), NULL, NULL); }
	| '(' expression ')'
		{$$ = $2; }
	| NOT factor
		{$$ = new Tree(Token(NOT), NULL, $2); }
	;

%%
ScopeManager *sman;
Scope *s;
Node *n;

int main()
{
	sman = NULL;
	s = NULL;
	n = NULL;

	yyparse();
}

void yyerror(char *msg)
{
	fprintf(stderr, "%s", msg);
	exit(1);
}

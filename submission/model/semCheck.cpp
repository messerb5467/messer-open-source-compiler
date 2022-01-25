#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scopeMan.h"
#include "semCheck.h"
#include "tree.h"

SemanticChecker::SemanticChecker(ScopeManager *s)
{
	symbTable = s;
}

SemanticChecker::~SemanticChecker()
{
	symbTable = NULL;
}

void SemanticChecker::verify(Tree *t)
{
	assert(t != NULL);

	switch( (t->getValue()).getType())
	{
		case PROGRAM:
			
		case ID:
		case VAR:
		case ARRAY:
		case OF:
		case NUM:
		case DOTDOT:
		case INTEGER:
		case REAL:
		case FUNCTION:
		case PROCEDURE:
		case BBEGIN:
		case END:
		case ASSIGNOP:
		case IF:
		case THEN:
		case WHILE:
		case DO:
		case RELOP:
		case ADDOP:
		case MULOP:
		case NOT:
		default:
			yyerror("Error: getAttribute: Unknown token type.");
			break;
	}

}

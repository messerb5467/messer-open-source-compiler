#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

//NOTE: Be careful of breaks due to relative path changes as
//the project continues.
#include "token.h"
#include "tree.h"
#include "../grammar.tab.hpp"

using namespace std;

extern void yyerror(char *);

Token::Token(int t)
{
	type = t;
}

Token::Token(int t, int v)
{
	type = t;
	this->setAttribute(t, v);
}

Token::Token(int t, float v)
{
	type = t;
	this->setAttribute(t,v);
}

Token::Token(int t, char *sval)
{
	type = t;
	
	if(sval != NULL)
	{
		strcpy(attribute.svalue, sval);
	}
}

int Token::getType()
{
	return type;
}

int Token::getAttribute(int token_type)
{
	switch(token_type)
	{
		case PROGRAM:
			return attribute.opval;
		case ID:
			return attribute.opval;	
		case VAR:
			return attribute.opval;
		case ARRAY:
			return attribute.opval;
		case OF:
			return attribute.opval;
		case NUM:
			return attribute.opval;
		case DOTDOT:
			return attribute.opval;
		case INTEGER:
			return attribute.integerVal;
		case REAL:
			return attribute.realVal;
		case FUNCTION:
			return attribute.opval;
		case PROCEDURE:
			return attribute.opval;
		case BBEGIN:
			return attribute.opval;
		case END:
			return attribute.opval;
		case ASSIGNOP:
			return attribute.opval;
		case IF:
			return attribute.opval;
		case THEN:
			return attribute.opval;
		case WHILE:
			return attribute.opval;
		case DO:
			return attribute.opval;
		case RELOP:
			return attribute.opval;
		case ADDOP:
			return attribute.opval;
		case MULOP:
			return attribute.opval;
		case NOT:
			return attribute.opval;
		default:
			yyerror("Error: getAttribute: Unknown token type.");
			break;	
	}
}

int Token::setAttribute(int token_type, int token_value)
{
	switch(token_type)
	{
		case PROGRAM:
			attribute.opval = token_value;
			break;
		case ID:
			attribute.opval = token_value;
			break;
		case VAR:
			attribute.opval = token_value;
			break;
		case ARRAY:
			attribute.opval = token_value;
			break;
		case OF:
			attribute.opval = token_value;
			break;
		case NUM:
			attribute.opval = token_value;
			break;
		case DOTDOT:
			attribute.opval = token_value;
			break;
		case INTEGER:
			attribute.integerVal = token_value;
			break;
		case REAL:
			fprintf(stderr, "Error: Inappropriate Function Call, Real: Please call other setAttribute");
			break;
		case FUNCTION:
			attribute.opval = token_value;
			break;
		case PROCEDURE:
			attribute.opval = token_value;
			break;
		case BBEGIN:
			attribute.opval = token_value;
			break;
		case END:
			attribute.opval = token_value;
			break;
		case ASSIGNOP:
			attribute.opval = token_value;
			break;
		case IF:
			attribute.opval = token_value;
			break;
		case THEN:
			attribute.opval = token_value;
			break;
		case WHILE:
			attribute.opval = token_value;
			break;
		case DO:
			attribute.opval = token_value;
			break;
		case RELOP:
			attribute.opval = token_value;
			break;
		case ADDOP:
			attribute.opval = token_value;
			break;
		case MULOP:
			attribute.opval = token_value;
			break;
		case NOT:
			attribute.opval = token_value;
			break;
		default:
			yyerror("Error: setAttribute, Int: Unknown token type.");
			break;
	}
}

int Token::setAttribute(int token_type, float token_value)
{
	switch(token_type)
	{
		case PROGRAM:
			fprintf(stderr, "Error: Inappropriate Function Call, Program: Please call other setAttribute");
			break;
		case ID:
			fprintf(stderr, "Error: Inappropriate Function Call, Id: Please call other setAttribute");
			break;
		case VAR:
			fprintf(stderr, "Error: Inappropriate Function Call, Var: Please call other setAttribute");
			break;
		case ARRAY:
			fprintf(stderr, "Error: Inappropriate Function Call, Array: Please call other setAttribute");
			break;
		case OF:
			fprintf(stderr, "Error: Inappropriate Function Call, Of: Please call other setAttribute");
			break;
		case NUM:
			fprintf(stderr, "Error: Inappropriate Function Call, Num: Please call other setAttribute");
			break;
		case DOTDOT:
			fprintf(stderr, "Error: Inappropriate Function Call, Dotdot: Please call other setAttribute");
			break;
		case INTEGER:
			fprintf(stderr, "Error: Inappropriate Function Call, Integer: Please call other setAttribute");
			break;
		case REAL:
			attribute.realVal = token_value;
			break;
		case FUNCTION:
			fprintf(stderr, "Error: Inappropriate Function Call, Function: Please call other setAttribute");
			break;
		case PROCEDURE:
			fprintf(stderr, "Error: Inappropriate Function Call, Procedure: Please call other setAttribute");
			break;
		case BBEGIN:
			fprintf(stderr, "Error: Inappropriate Function Call, Bbegin: Please call other setAttribute");
			break;
		case END:
			fprintf(stderr, "Error: Inappropriate Function Call, End: Please call other setAttribute");
			break;
		case ASSIGNOP:
			fprintf(stderr, "Error: Inappropriate Function Call, Assignop: Please call other setAttribute");
			break;
		case IF:
			fprintf(stderr, "Error: Inappropriate Function Call, If: Please call other setAttribute");
			break;
		case THEN:
			fprintf(stderr, "Error: Inappropriate Function Call, Then: Please call other setAttribute");
			break;
		case WHILE:
			fprintf(stderr, "Error: Inappropriate Function Call, While: Please call other setAttribute");
			break;
		case DO:
			fprintf(stderr, "Error: Inappropriate Function Call, Do: Please call other setAttribute");
			break;
		case RELOP:
			fprintf(stderr, "Error: Inappropriate Function Call, Relop: Please call other setAttribute");
			break;
		case ADDOP:
			fprintf(stderr, "Error: Inappropriate Function Call, Addop: Please call other setAttribute");
			break;
		case MULOP:
			fprintf(stderr, "Error: Inappropriate Function Call, Mulop: Please call other setAttribute");
			break;
		case NOT:
			fprintf(stderr, "Error: Inappropriate Function Call, Not: Please call other setAttribute");
			break;
		default:
			yyerror("Error: setAttribute, Float: Unknown token type.");
			break;
	}
}

void Token::show()
{
	switch(type)
	{
		case PROGRAM:
			fprintf(stderr, "PROGRAM\n");
			break;
		case ID:
			fprintf(stderr, "ID\n");
			break;
		case VAR:
			fprintf(stderr, "VAR\n");
			break;
		case ARRAY:
			fprintf(stderr, "ARRAY\n");
			break;
		case OF:
			fprintf(stderr, "OF\n");
			break;
		case NUM:
			fprintf(stderr, "NUM\n");
			break;
		case DOTDOT:
			fprintf(stderr, "DOTDOT\n");
			break;
		case INTEGER:
			fprintf(stderr, "INTEGER[%d]", attribute.integerVal);
			break;
		case REAL:
			fprintf(stderr, "REAL[%f]", attribute.realVal);
			break;
		case FUNCTION:
			fprintf(stderr, "FUNCTION\n");
			break;
		case PROCEDURE:
			fprintf(stderr, "PROCEDURE\n");
			break;
		case BBEGIN:
			fprintf(stderr, "BBEGIN\n");
			break;
		case END:
			fprintf(stderr, "END\n");
			break;
		case ASSIGNOP:
			fprintf(stderr, "ASSIGNOP\n");
			break;
		case IF:
			fprintf(stderr, "IF\n");
			break;
		case THEN:
			fprintf(stderr, "THEN\n");
			break;
		case WHILE:
			fprintf(stderr, "WHILE\n");
			break;
		case DO:
			fprintf(stderr, "DO\n");
			break;
		case RELOP:
			fprintf(stderr, "RELOP[%d]\n", attribute.opval);
			break;
		case ADDOP:
			fprintf(stderr, "ADDOP[%d]\n", attribute.opval);
			break;
		case MULOP:
			fprintf(stderr, "MULOP[%d]\n", attribute.opval);
			break;
		case NOT:
			fprintf(stderr, "NOT\n");
			break;
		default:
			yyerror("Error: show: Unknown token type.");
			break;
	}
}

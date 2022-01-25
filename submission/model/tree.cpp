#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "token.h"

Tree::Tree(Token v, Tree *l, Tree *r) : value(v), left(l), right(r) 
{
}

Tree::~Tree()
{
	left = NULL;
	right = NULL;
}

//May have to fix so that a pointer to the token is returned.
Token Tree::getValue()
{
	return value;
}

Tree* Tree::getLeft()
{
	return left;
}

Tree* Tree::getRight()
{
	return right;
}

void Tree::setValue(Token v)
{
	value = v;
}

void Tree::setLeft(Tree *l)
{
	left = l;
}

void Tree::setRight(Tree *r)
{
	right = r;
}

void Tree::setTableEntry(Node* te)
{
	tableEntry = te;
}

void Tree::print()
{
	Tree::print(0);
}

void Tree::print(int spaces)
{
	for(int i = 0; i < spaces; i++)
	{
		fprintf(stderr, " ");
	}

	value.show();

	if(left != NULL)
	{
		print(spaces + 4);
	}

	if(left != NULL)
	{
		print(spaces + 4);
	}
}

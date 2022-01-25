#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "node.h"

Node::Node()
{
	name = NULL;
}

Node::Node(char *n)
{
	assert(strlen(n) < 50);
	name = (char *) malloc(50 * sizeof(char));
	strcpy(name, n, 50);
}

Node::~Node()
{
	name = NULL;
}

char *Node::getName()
{
	return name;
}

Type getType()
{
	return type;
}

int Node::getClassType()
{
	return classType;
}

void Node::setName(char *n)
{
	assert(n != NULL);
	strcpy(name, n, 50);
}

void Node::setClassType(int t)
{
	classType = t;
}

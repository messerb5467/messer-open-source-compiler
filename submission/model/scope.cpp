#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scope.h"

Scope::Scope()
{
	for(int i = 0; i < HASH_SIZE; i++)
	{
		table[i] = new std::list<Node>();
	}	
}

Scope::~Scope()
{
	for(int i = 0; i < HASH_SIZE; i++)
	{
		table[i] = NULL;
	}
}

void Scope::insert(char *name)
{
	if(Scope::notin(name))
	{
		int index = Scope::hashpjw(name);
		table[index]->push_back(*(new Node(name)));
	}
}

Node *Scope::search(char *name)
{
	int index = Scope::hashpjw(name);
	Node *result = NULL;

	for(std::list<Node>::iterator itr = table[index]->begin(); itr != table[index]->end(); itr++)
	{
		if(!strcmp(itr->getName(), name))
		{
			result = &(*itr);
			return result;
		}
	}

	return NULL;
}

bool Scope::notin(char *name)
{
	int index = Scope::hashpjw(name);

	for(std::list<Node>::iterator itr = table[index]->begin(); itr != table[index]->end(); itr++)
	{
		if(!strcmp(itr->getName(), name))
		{
			return false;
		}
	}

	return true;
}
int Scope::hashpjw(char *s)
{
	char *p;
	unsigned h = 0, g;

	for(p = s; *p != EOS; p++)
	{
		h = (h << 4) + (*p);
		
		if ( (g = h&0xf0000000) ) 
		{
			h = h ^ (g >> 24);
			h = h ^ g;
		}
	}

	return h % HASH_SIZE;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scopeMan.h"
#include "node.h"

ScopeManager::ScopeManager() : stack()
{
}

ScopeManager::~ScopeManager()
{
	stack.clear();
}

void ScopeManager::push(Scope *s)
{
	stack.push_front(*s);
}

void ScopeManager::pop()
{
	if(!stack.empty())
	{
		stack.pop_front();		
	}
}

Node *ScopeManager::search(char *name)
{
	Node *result;

	for(std::list<Scope>::iterator itr = stack.begin(); itr != stack.end(); itr++)
	{
		result = itr->search(name);
		
		if(result != NULL)
		{
			return result;
		}		
	}

	return NULL;
}

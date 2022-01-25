#ifndef SCOPEMAN_H
#define SCOPEMAN_H

#include <list>
#include "scope.h"

class ScopeManager
{
	private:
		std::list<Scope> stack;

	public:
		ScopeManager();
		~ScopeManager();

		void push(Scope *s);
		void pop();

		Node *search(char *name);		
};
#endif

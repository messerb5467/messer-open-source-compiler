#ifndef SEMCHECK_H
#define SEMCHECK_H

#include "scopeMan.h"

class SemanticChecker
{
	private:
		ScopeManager *symbTable;

	public:
		SemanticChecker(ScopeManager *s);
		~SemanticChecker();

		void verify(Tree *check);
}
#endif 

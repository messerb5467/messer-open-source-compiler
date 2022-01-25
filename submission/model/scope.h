#ifndef SCOPE_H
#define SCOPE_H

#include <list>
#include "node.h"

#define HASH_SIZE 211
#define EOS       '\0'

class Scope
{
	private:
		std::list<Node> *table[HASH_SIZE];

	public:
		Scope();
		~Scope();

		void insert(char *name);
		Node *search(char *name);			

		bool notin(char *name);		
		int hashpjw(char *s);
};
#endif

#ifndef NODE_H
#define NODE_H

#include "type.h"

class Node
{
	private:
		char *name;
		Type t;
		ClassType ctype;

	public:
		Node();
		Node(char *n);
		~Node();

		char *getName();
		Type getType();
		int getClassType();
		
		void setName(char *n);
		void setClassType(int t);
};
#endif

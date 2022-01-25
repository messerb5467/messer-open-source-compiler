#ifndef TREE_H
#define TREE_H

#include "token.h"
#include "node.h"

class Tree
{
	private:
		Token value;
		Tree *left;
		Tree *right;
		Node *tableEntry;

	public:
		Tree(Token v, Tree *l, Tree *r);
		~Tree();

		Token getValue();
		Tree* getLeft();
		Tree* getRight();

		void setValue(Token v);
		void setLeft(Tree *l);
		void setRight(Tree *r);
		void setTableEntry(Node* te);

		void print();
		void print(int spaces);
};
#endif

#include <stdio.h>
#include <stdlib.h>
#include "../model/node.h"
#include "../model/scope.h"

int main()
{
	int choice;
	char buffer[32];

	Scope *s = new Scope();

	Node *tmp = new Node();

	while(1)
	{
		fprintf(stderr, "0.Search\n 1. Insert\n 2.Exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				scanf("%s", buffer);
				
				tmp = s->search(buffer);

				if(tmp != NULL)
				{
					fprintf(stderr, "Found[%s]\n", tmp->getName());
					tmp = NULL;
				}
				else
				{
					fprintf(stderr, "Not found[%s]\n", buffer);
				}

				break;

			case 1:
				scanf("%s", buffer);
				s->insert(buffer);
				break;


			case 2:
				return 0;	
				break;

		}
	}
}

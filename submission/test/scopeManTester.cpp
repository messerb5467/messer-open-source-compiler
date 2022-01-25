#include <stdio.h>
#include <stdlib.h>
#include "../model/scope.h"
#include "../model/scopeMan.h"

int main()
{
	int choice;
	char buffer[32];

	ScopeManager *sman = new ScopeManager();
	Scope *s;
	Node *tmp;

	while(1)
	{
		fprintf(stderr, "0.Search\n 1.Push\n 2.Pop\n 3.Exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				scanf("%s", buffer);
				tmp = sman->search(buffer);

				if(tmp != NULL)
				{
					fprintf(stderr, "Found with global search[%s].", tmp->getName());
					tmp = NULL;
				}
				else
				{
					fprintf(stderr, "Not found within global search[%s].", buffer);
				}

				break;
		
			case 1:
				scanf("%s", buffer);
				s = new Scope();
				s->insert(buffer);
				sman->push(s);
				s = NULL;
	
				break;

			case 2:
				sman->pop();
				break;

			case 3: 
				return 0;
				break;
		}
	}
	
}

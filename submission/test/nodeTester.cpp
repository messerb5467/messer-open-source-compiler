#include <stdio.h>
#include <stdlib.h>
#include <list>
#include "../model/node.h"

int main()
{
	int choice;
	char *buffer = (char *) malloc(32 * sizeof(char));

	std::list<Node> nameList;
	char *tmp;

	Node *nodetmp;

	while(1)
	{
		fprintf(stderr, "0.Search\n 1.Insert\n 2.Delete Element\n 3.Delete All\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				scanf("%s", buffer);
				
				for(std::list<Node>::iterator itr = nameList.begin(); itr != nameList.end(); itr++)
				{
					if(!strcmp(itr->getName(), buffer))
					{
						tmp = itr->getName();						
					}
				}

				if(tmp != NULL)
				{
					fprintf(stderr, "Found[%s]\n", tmp);
					tmp = NULL;
				}
				else
				{
					fprintf(stderr, "Not Found[%s]\n", buffer);
				}

				break;

			case 1:
				scanf("%s", buffer);
				nameList.push_back(*(new Node(buffer)));
			
				break;

			case 2:
				scanf("%s", buffer);
				
				for(std::list<Node>::iterator itr = nameList.begin(); itr != nameList.end(); itr++)
				{
					if(!strcmp(itr->getName(), buffer))
					{
						tmp = itr->getName();
						itr->~Node();
						nameList.erase(itr);
					}
				}
		
				if(tmp != NULL)
				{
					fprintf(stderr, "Element Deleted[%s]\n", tmp);
					tmp = NULL;
				}
				else if(nameList.empty())
				{
					fprintf(stderr, "The list is empty.\n");
				}
				else
				{
					fprintf(stderr, "Element not within list[%s]\n", buffer);
				}

				break;

			case 3:
				nameList.erase(nameList.begin(), nameList.end());
				
				if(nameList.empty())
				{
					fprintf(stderr, "Emptying of list successful!\n");
				}
				else
				{
					fprintf(stderr, "Emptying of list failed.\n");
				}

				break;
		}
	}
}

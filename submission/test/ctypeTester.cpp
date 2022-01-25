#include <stdlib.h>
#include <stdio.h>
#include "../model/ctype.h"

int main()
{
	int choice, ctype, index;
	bool locality;

	ClassType c = ClassType(171, true);
	while(1)
	{
		fprintf(stderr, "0.GetCType\n 1.GetLocality\n 2.AddArg\n 3.MatchArg\n 4.Exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				ctype = c.getCType();
				fprintf(stderr, "The type is [%d].\n", ctype);
				ctype = 0;
				break;

			case 1:
				locality = c.getLocality();
				if(false == locality)
				{
					fprintf(stderr, "This is a parameter.\n");
				}
				else if(true == locality)
				{
					fprintf(stderr, "This is a local variable.\n");
				}

				break;

			case 2:
				scanf("%d", &ctype);
				c.addArg(ctype);
				break;
			case 3:
				scanf("%d", &ctype);
				scanf("%d", &index);
				c.matchArg(ctype, index);
				break;
			case 4:
				exit(0);
				break;
		}
	}
}

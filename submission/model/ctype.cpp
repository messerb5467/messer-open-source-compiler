#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ctype.h"

ClassType::ClassType() : ctype(), islocal(), argTypes()
{
}

ClassType::ClassType(int t, bool locality): ctype(t), islocal(locality), argTypes()
{
}

ClassType::~ClassType()
{
	argTypes.clear();
}

int ClassType::getCType()
{
	return ctype;
}

bool ClassType::getLocality()
{
	return islocal;
}

void ClassType::addArg(int type)
{
	argTypes.push_back(type);
}

bool ClassType::matchArg(int type, int index)
{
	int argIndex = 0;

	for(std::list<int>::iterator itr = argTypes.begin(); itr != argTypes.end(); itr++)
	{
		if( (type == *itr) && (argIndex == index) )
		{
			return true;
		}		

		argIndex++;
	}

	return false;
}

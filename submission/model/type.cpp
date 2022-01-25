#include <stdlib.h>
#include "type.h"

Type::Type()
{
	type = 0;
	lbound = 0;
	hbound = 0;
	rlbound = 0.0;
	rhbound = 0.0;
}

Type::Type(int t)
{
	type = t;
	lbound = 0;
	hbound = 0;
	rlbound = 0.0;
	rhbound = 0.0;
}

Type::Type(int t, int lowBound, int highBound)
{
	type = t;
	lbound = lowBound;
	hbound = highBound;
	rlbound = 0.0;
	rhbound = 0.0;
}

Type::Type(int t, float lowBound, float highBound)
{
	type = t;
	lbound = 0;
	hbound = 0;
	rlbound = lowBound;
	rhbound = highBound;
}

Type::~Type()
{
	type = 0;
	lbound = 0;
	hbound = 0;
	rlbound = 0.0;
	rhbound = 0.0;
}

int getType()
{
	return type;
}

int getLowBound()
{
	return lbound;
}

int getRHighBound()
{
	return hbound;
}

float getRLowBound()
{
	return rlbound;
}

float getRHighBound()
{
	return rhbound;
}

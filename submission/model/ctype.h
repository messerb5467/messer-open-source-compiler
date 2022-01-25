#ifndef CTYPE_H
#define CTYPE_H

#include <list>

class ClassType
{
	private:
		int ctype;
		bool islocal;
		std::list<int> argTypes;

	public:
		ClassType();
		ClassType(int t, bool locality);
		~ClassType();

		int getCType();
		bool getLocality();
		void addArg(int type);
		bool matchArg(int type, int index);
};
#endif

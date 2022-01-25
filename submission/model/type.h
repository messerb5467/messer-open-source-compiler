#ifndef TYPE_H
#define TYPE_H

class Type
{
	private:
		int type, lbound, hbound;
		float rlbound, rhbound;

	public:
		Type();
		Type(int t);
		Type(int t, int lowBound, int highBound);
		Type(int t, float lowBound, float highBound);
		~Type();
		
		int getType();
		int getLowBound();
		int getHighBound();
		float getRLowBound();
		float getRHighBound();
};
#endif


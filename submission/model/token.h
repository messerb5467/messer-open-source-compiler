#ifndef TOKEN_H
#define TOKEN_H

class Token
{
	private:
		/*Integer, Real, Addop, Mulop, Relop*/
		int type;
	
		union
		{
			/*Integer*/
			int integerVal;

			/*Real*/
			float realVal;

			/*ID */
			char *svalue;

			/*Addop, Mulop, Relop*/
			int opval;
		} attribute;


	public:
		Token(int t);
		Token(int t, int v);
		Token(int t, float v);
		Token(int t, char *sval);

		int getType();
		int getAttribute(int token_type);
		int setAttribute(int token_type, int token_value);
		int setAttribute(int token_type, float token_value);
		void show();
};
#endif

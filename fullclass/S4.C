// s4.C - String class substrings
#include <iostream.h>
#include "String3.h"

void f(const String & s1, const String & s2) {
	cout << s2 << endl;
	cout << s1(5, 3) << endl;				// rvalue, substring "bet"
	cout << s1[0] << s2[1] << s2[2] << endl;
	cout << s1(10, 2) << endl;				// rvalue - error (illegal position) 
	//cout << s1(6, 5) << endl;				// rvalue - error (count too large)
	//s1(5, 3) = "abc";							// lvalue - error
}

int main()
{
	try {
		 String s1 = "alphabet";
		 String s2 = s1(0, 5);					// rvalue, substring "alpha"
		 f(s1, s2);
	}
	catch (const StringError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ s4 
alpha
bet
alp
String: Illegal substring for "alphabet": pos = 10, count = 2

*/

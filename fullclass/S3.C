// s3.C - String class substrings
#include <iostream.h>
#include "String.h"

int main()
{
	try {
		 String s1 = "alphabet";
		 String s2 = s1(0, 5);					// rvalue, substring "alpha"
		 cout << s2 << endl;
		 cout << s1(5, 3) << endl;				// rvalue, substring "bet"
		 cout << s1(10, 2) << endl;			// rvalue - error (illegal position) 
		 //cout << s1(6, 5) << endl;				// rvalue - error (count too large)
		 //s1(5, 3) = "abc";						// lvalue - error
	}
	catch (const StringError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ s3 
alpha
bet
String: Illegal substring for "alphabet": pos = 10, count = 2

*/

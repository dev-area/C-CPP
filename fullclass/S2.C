// s2.C - C++ strings with operator overloading (Part Two)
#include <iostream.h>
#include <stdlib.h>
#include "String.h"

int main()
{
	try {
		 String s1("alpha");
		 String s2("bet");
		 String s3("duck");
		 String s4("soup");
		 String s5;

		 cout << "Input a string: ";
		 cin >> s5;                                       // String input
		 cout << s5 << endl;

		 if (s1 == "alpha")                               // String compare
			 cout << s1 + "bet" << endl;

		 if ("duck" == s3)                                // String compare
			 cout << "duck" - s4 << endl;
	}
	catch (const StringError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ s2 
Input a string: alpha
alpha
alphabet
duck soup

*/

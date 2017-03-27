// lvrv.C - String class substrings, lvalues and rvalues
#include <iostream.h>
#include "String.h"

int main()
{
	 try {
		  String s1 = "duck soup";
		  cout << s1 << endl;
		  String s2 = s1(0, 4);				// rvalue
		  cout << s2 << endl;
		  s1(0, 4) = "hunt";					// lvalue assignment
		  cout << s1 << endl;
		  s1(5, 4) = s2(0, 4);				// lvalue assignment and rvalue
		  cout << s1 << endl;
		  s1(5, 5) = "walk";					// error, substring too large
	 }
	catch (const StringError & e) {
		e.response();
		return 1;
	}
	 return 0;
}

/*******************************************************************

$ lvrv
duck soup
duck
hunt soup
hunt duck
String: Illegal substring for "hunt duck": pos = 5, count = 5

*/

// sfriend.C - C++ strings with friends, objects as return values
#include <iostream.h>
#include "String2.h"

int main()
{
	try {
		String s1("alpha");
		String s2("bet");
		String s3("duck");
		String s4("soup");
		cout << s1 + s2 << endl;
		cout << s1 + s2 - s3 + s4 << endl;
	}
	catch (const StringError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ sfriend 
alphabet
alphabet ducksoup

*/

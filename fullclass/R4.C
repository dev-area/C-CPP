// r4.C - pre/post incr/decr with range objects
#include <iostream.h>
#include <math.h>
#include "Rint.h"

int main()
{
	try {
		 Rint a(0, 0, 10);
		 Rint b(0, 0, 10);
		 Rint c;
		 a++;								// OK - a set to 1
		 cout << a << endl;
		 b--;								// error - not within b's range, b remains 0
		 cout << b << endl;
		 c = (int)a++;					// OK - c set to 1, a set to 2
		 cout << c << a << endl;
		 c = (int)++a;					// OK - c set to 3, a set to 3
		 cout << c << a << endl;
		 c = (int)--b;					// error - not within b's range, b remains 0, c set to 0
		 cout << c << b << endl;
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ r4 
(1, 0, 10)
Rint: Integer out of range (value = -1, min = 0, max = 10)

*/

// r3.C - assignments with range objects
#include <iostream.h>
#include <math.h>
#include "Rint.h"

int main()
{
	try {
		 Rint k(15, -10, 20);
		 Rint w(10, 0, 100);

		 w = 20;												// OK
		 cout << w << endl;
		 w = (int)k;										// OK
		 cout << w << endl;
		 w = 500;											// error - outside of w's range
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ r3 
(20, 0, 100)
(15, 0, 100)
Rint: Integer out of range (value = 500, min = 0, max = 100)

*/

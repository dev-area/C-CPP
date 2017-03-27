// r2.C - conversions with range objects
#include <iostream.h>
#include <math.h>
#include "Rint.h"

int main()
{
	try {
		 Rint i = 100, k = 25;

		 cout << sqrt(k) << endl;				// sqrt( (int)k )
		 cout << (i + k) << endl;				// (int)k + (int)k
		 cout << (i * 5) << endl;				// (int)k * 5
		 if (i > k)									// if ( (int)i > (int)k )
			 cout << "yes" << endl;
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ r2 
5
125
500
yes

*/

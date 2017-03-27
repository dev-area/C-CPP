// r1.C - build range objects
#include <iostream.h>
#include "Rint.h"

int main()
{
	try {
		 Rint i;									// value=0, min=INT_MIN, max=INT_MAX
		 cout << i << endl;

		 Rint j = 30;							// value=30, min=INT_MIN, max=INT_MAX
		 cout << j << endl;

		 Rint k = j;							// value=30, min=INT_MIN, max=INT_MAX
		 cout << k << endl;

		 Rint m(5, -10, 10);					// value=5, min=-10, max=10
		 cout << m << endl;

		 Rint n(15, 20, 10);					// error - minimum greater than maximum
		 Rint p(-10, 0, 100);				// error - initial value out of range
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ r1
(0, -32768, 32767)
(30, -32768, 32767)
(30, -32768, 32767)
(5, -10, 10)
Rint: Integer out of range (value = 15, min = 20, max = 10)

*/

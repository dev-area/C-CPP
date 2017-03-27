// nt.c - range integer nineties
#include <iostream.h>
#include "Rint.h"

int main()
{
	try {
		 Rint nineties(1995, 1990, 1999);
		 cout << nineties << endl;
		 nineties = 1996;
		 cout << nineties << endl;
		 nineties = 2000;
		 cout << nineties << endl;
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ nt 
(1995, 1990, 1999)
(1996, 1990, 1999)
Rint: Integer out of range (value = 2000, min = 1990, max = 1999)

*/

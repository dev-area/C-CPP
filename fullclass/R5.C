// r5.C - iostreams with range integers
#include <iostream.h>
#include "Rint.h"

int main()
{
	try {
		 Rint g(1, 1, 10);								// value=1, min=1, max=10
		 cout << "Input an integer between 1 and 10: ";
		 cin >> g;										// istream input
		 cout << g << endl;							// ostream output
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ r5 
Input an integer between 1 and 10: 5
(5, 1, 10)

*/

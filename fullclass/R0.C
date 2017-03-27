// rint.C - range int program
#include <iostream.h>
#include "Rint.h"

int main()
{
	try {
		 Rint i(100, -1000, 1000);
		 Rint j;
		 Rint k(1985, 1980, 1990);
		 //Rint w(33, -10, -5);								// illegal declaration

		 cout << "Input a range int: ";
		 cin >> j;
		 cout << "i = " << i << endl;
		 cout << "j = " << j << endl;
		 cout << "k = " << k << endl;
		 //cout << "w = " << w << endl;

		 cout << "i = " << i++ << ' ' << "k = " << k++ << endl;		// postfix
		 cout << "i = " << ++i << ' ' << "k = " << ++k << endl;		//prefix

		 Rint m(0, 0, 3000);
		 m = i + k;
		 if (m > 2000) cout << "m = " << m << endl;
		 if (m == 2089) cout << "same" << endl;
		 cout << "m = " << (m += i) << endl;
		 if (m > k) cout << "m = " << m << endl;
		 cout << "m % 100 = " << (m % 100) << endl;
		 cout << "m % k = " << (m % k) << endl;
		 cout << "m %= k = " << (m %= k) << endl;
	}
	catch (const RintError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ r0 
Input a range int: 33
i = (100, -1000, 1000)
j = (33, -32768, 32767)
k = (1985, 1980, 1990)
i = (100, -1000, 1000) k = (1985, 1980, 1990)
i = (102, -1000, 1000) k = (1987, 1980, 1990)
m = (2089, 0, 3000)
same
m = (2191, 0, 3000)
m = (2191, 0, 3000)
m % 100 = 91
m % k = 204
m %= k = (204, 0, 3000)

*/

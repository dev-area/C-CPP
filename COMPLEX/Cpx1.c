// cpx.C - Complex numbers
#include <iostream.h>
#include "Complex.h"

int main()
{
	Complex c1(2.3, 5.6), c2(1.2, 3.4);
	Complex c3 = -c1;
	c3.print();

	c3 = c1 - c2;
	c3.print();

	c1 -= c2;
	c1.print();
	return 0;
}

/**********************************************************************

$ cpx 
(-2.3, -5.6)
(1.1, 2.2)
(1.1, 2.2)

*/

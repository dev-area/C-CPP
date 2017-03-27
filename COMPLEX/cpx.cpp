// cpx.C - test program for C++ Complex numbers
#include <iostream.h>
#include "Complex.h"

int main()
{
	Complex a(1.1, 3.1);
	Complex b(1.2, 2.2);
	Complex c, d, e, f;

	c = d = a;										// default assignment		

	e = c += b;										// complex add
	e.print();
	c.print();

	f = d *= a;										// complex multiply
	f.print();
	d.print();

	Complex d5 = -7.8;
	Complex d6 = +d5;								// unary +
	d6.print();

	Complex d7 = -d5;								// unary -
	d7.print();
	return 0;
}

/********************************************************************

$ cpx
(2.3, 5.3)
(2.3, 5.3)
(-8.4, 6.82)
(-8.4, 6.82)
(-7.8, 0)
(7.8, 0)

NOTES:
1. The binary += and *= operators should be member functions because 
	symmetry is not necessary for conversions; i.e.,

			3.5 += c1		and 3.5 *= c1		are illegal

	The unary - operator should be a member function since it is a unary
	operator.

2. The Complex class does not have an overloaded cast operator because
 	you cannot convert a Complex to a single double value (Complex numbers
	have separate real and imaginary values).

*/

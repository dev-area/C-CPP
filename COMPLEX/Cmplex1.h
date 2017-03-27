#ifndef COMPLEXH
#define COMPLEXH
// Complex.h - Complex class interface 
#include <iostream.h>

class Complex {
private:
	double realp;											// real part 
	double imagp;											// imaginary part
public:
	Complex(double r = 0, double i = 0) : /***/, /***/ { }
	Complex operator-() const;							// unary negation
	Complex & operator-=(const Complex &);			// subtraction update
	double real() const { /***/ }
	double imag() const { /***/ }
	void print() const;									// display Complex
};

inline Complex operator-(const Complex & c1, const Complex & c2) {
	return Complex(/***/, /***/);
}

inline Complex Complex::operator-() const {			// unary negation
	return /***/;						// return Complex object 
}

inline Complex & Complex::operator-=(const Complex & c1) {
	return *this = /***/;
}

inline void Complex::print() const {
	cout << '(' << /***/ << ", " << /***/ << ')' << endl;
}
#endif

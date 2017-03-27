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
// Modifiers
	Complex & operator+=(const Complex &);			// addition update
	Complex & operator-=(const Complex &);			// subtraction update
	Complex & operator*=(const Complex &);			// multiply update
	void real(double r) { /***/ }
	void imag(double i) { /***/ }
// Selectors
	Complex operator-() const;							// unary negation
	Complex operator+() const;							// unary +
	double real() const { /***/ }
	double imag() const { /***/ }
	void print() const;									// display a Complex
};

inline int operator==(const Complex & c1, const Complex & c2) { 
	return (/***/);
}

inline int operator!=(const Complex & c1, const Complex & c2) { 
	return (/***/);
}

inline Complex Complex::operator+() const {				// unary +
	return Complex(realp, imagp); 
}

inline Complex Complex::operator-() const {				// unary -
	return /***/; 
}

inline Complex operator+(const Complex & c1, const Complex & c2) {
	return /***/;
}

inline Complex operator-(const Complex & c1, const Complex & c2) {
	return /***/;
}

inline Complex operator*(const Complex & c1, const Complex & c2) {
	return /***/;
}

inline Complex & Complex::operator+=(const Complex & c) {
	return *this = /***/;
}

inline Complex & Complex::operator-=(const Complex & c) {
	return /***/;
}

inline Complex & Complex::operator*=(const Complex & c) {
	return /***/;
}

inline ostream & operator<<(ostream & s, const Complex & z) {
	return /***/;
}

inline void Complex::print() const {
	/***/
}
#endif

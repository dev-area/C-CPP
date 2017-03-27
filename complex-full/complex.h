#ifndef __COMPLEX_H__	
#define __COMPLEX_H__	
#include <iostream.h>
#include <math.h>

	// An example of building a simple class (complex)
	// A better one will be a template, see
	//	t2:	/usr/local/gcc/lib/g++-include/std/complext.h
	//	csd:	/usr/local/lib/g++-include/std/complext.h
	// More sophisticated floating-point arithmetic will use EPSILON
	// though for NICE_PRINT I do have to use epsilons of size .1E+k

class complex {
  double re,
	 im;
  static bool equal(double object, double other, int);
  void im_print(ostream& os) const;
  ostream& stnd_print(ostream& os) const;
  ostream& gnrl_print(ostream& os) const;

public:
	// Constructor (0 - 2 arguments)
  complex(double x = 0, double y = 0): re(x), im(y) {}
	// Extracting basic data
  double real() const { return re;}
  double imag() const { return im;}
	// Simple manipulations (unary functions)
  double rsq()  const { return re*re + im*im;}	// r^2; i.e, norm-square
  double abs()  const { return sqrt(rsq());}
  double arg()  const { return atan2(im,re);}	// atan2(0,0) is 0
  complex  cnj() const { return complex(re, -im);}	// Conjugate
  complex  inv() const
    { double tmp = rsq();
      return complex(re/tmp, -im/tmp);	// Division by 0 will break
    }

		// Unary operators (member)
	complex  operator-() const { return complex(-re, -im);}
  const complex& operator+() const { return *this;} // No copy, no alteration

		// Binary operators 
	// Assignment operators (always members), default operator= is o.k.
  complex& operator+=(const complex& c) {re += c.re; im += c.im; return *this;}
  complex& operator-=(const complex& c) {re -= c.re; im -= c.im; return *this;}
  complex& operator*=(const complex& c)
    { double tmpr = re*c.re - im*c.im;
      im = re*c.im + im*c.re;
      re = tmpr;
      return *this;
    }
  complex& operator/=(const complex& c) {return (*this *= c.inv());}

	// Friend operators
  friend bool     operator==(const complex&, const complex&);
  friend istream& operator>>(istream& is, complex& c);
  friend ostream& operator<<(ostream& os, const complex& c);
};
	// Friend operators 

inline bool
operator==(const complex& c0, const complex& c1)
{ return c0.re == c1.re && c0.im == c1.im;
}

inline bool	// This one is non-friend
operator!=(const complex& c0, const complex& c1)
{ return !(c0 == c1);
}


inline istream& operator>>(istream& is, complex& c)
{ is >> c.re >> c.im ;		// Two consequtive numbers "are" a complex
  return is;
}


inline ostream& operator<<(ostream& os, const complex& c)
{ return c.gnrl_print(os);
}


	// Non-friend operators (using public-member operators)

inline complex
operator+(const complex& c0, const complex& c1)
{ complex c  = c0;
  return  c += c1;
}

inline complex
operator-(const complex& c0, const complex& c1)
{ complex c  = c0;
  return  c -= c1;
}

inline complex
operator*(const complex& c0, const complex& c1)
{ complex c  = c0;
  return  c *= c1;
}

inline complex
operator/(const complex& c0, const complex& c1)
{ return  c0 * c1.inv();
}

#endif	// __COMPLEX_H__ '}'

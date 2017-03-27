// File from page 406 in "Thinking in C++" by Bruce Eckel
//////////////////////////////////////////////////
// From the compressed package ECKELT02.ZIP 4/11/95
// (Original ECKELT01.ZIP dated 2/21/95)
// Copyright (c) Bruce Eckel, 1995 
// Source code file from the book "Thinking in C++", 
// Prentice Hall, 1995, ISBN: 0-13-917709-4
// All rights reserved EXCEPT as allowed by the following 
// statements: You may freely use this file for your own 
// work, including modifications and distribution in 
// executable form only. You may copy and distribute this 
// file, as long as it is only distributed in the complete 
// (compressed) package with the other files from this 
// book and you do not remove this copyright and notice. 
// You may not distribute modified versions of the source 
// code in this package. This package may be freely placed 
// on bulletin boards, internet nodes, shareware disks and 
// product vendor disks. You may not use this file in 
// printed media without the express permission of the 
// author. Bruce Eckel makes no 
// representation about the suitability of this software 
// for any purpose. It is provided "as is" without express 
// or implied warranty of any kind. The entire risk as to 
// the quality and performance of the software is with 
// you. Should the software prove defective, you assume 
// the cost of all necessary servicing, repair, or 
// correction. 
// If you think you've found an error, please 
// email all modified files with loudly commented changes 
// to: eckel@aol.com (please use the same 
// address for non-code errors found in the book).
//////////////////////////////////////////////////

//: BINARY.CPP -- Overloading binary operators
#include <fstream.h>
#include "allege.h"
ofstream out("binary.out");

class integer { // Combine this with UNARY.CPP
  long i;
public:
  integer(long I = 0) : i(I) {}
  // Operators that create new, modified value:
  friend const integer
    operator+(const integer& left,
              const integer& right);
  friend const integer
    operator-(const integer& left,
              const integer& right);
  friend const integer
    operator*(const integer& left,
              const integer& right);
  friend const integer
    operator/(const integer& left,
              const integer& right);
  friend const integer
    operator%(const integer& left,
              const integer& right);
  friend const integer
    operator^(const integer& left,
              const integer& right);
  friend const integer
    operator&(const integer& left,
              const integer& right);
  friend const integer
    operator|(const integer& left,
              const integer& right);
  friend const integer
    operator<<(const integer& left,
               const integer& right);
  friend const integer
    operator>>(const integer& left,
               const integer& right);
  // Assignments modify & return lvalue:
  friend integer&
    operator+=(integer& left,
               const integer& right);
  friend integer&
    operator-=(integer& left,
               const integer& right);
  friend integer&
    operator*=(integer& left,
               const integer& right);
  friend integer&
    operator/=(integer& left,
               const integer& right);
  friend integer&
    operator%=(integer& left,
               const integer& right);
  friend integer&
    operator^=(integer& left,
               const integer& right);
  friend integer&
    operator&=(integer& left,
               const integer& right);
  friend integer&
    operator|=(integer& left,
               const integer& right);
  friend integer&
    operator>>=(integer& left,
                const integer& right);
  friend integer&
    operator<<=(integer& left,
                const integer& right);
  // Conditional operators return true/false:
  friend int
    operator==(const integer& left,
               const integer& right);
  friend int
    operator!=(const integer& left,
               const integer& right);
  friend int
    operator<(const integer& left,
              const integer& right);
  friend int
    operator>(const integer& left,
              const integer& right);
  friend int
    operator<=(const integer& left,
               const integer& right);
  friend int
    operator>=(const integer& left,
               const integer& right);
  friend int
    operator&&(const integer& left,
               const integer& right);
  friend int
    operator||(const integer& left,
               const integer& right);
  // Write the contents to an ostream:
  void print(ostream& os) const { os << i; }
};

const integer
  operator+(const integer& left,
            const integer& right) {
  return integer(left.i + right.i);
}
const integer
  operator-(const integer& left,
            const integer& right) {
  return integer(left.i - right.i);
}
const integer
  operator*(const integer& left,
            const integer& right) {
  return integer(left.i * right.i);
}
const integer
  operator/(const integer& left,
            const integer& right) {
  allege(right.i != 0, "divide by zero");
  return integer(left.i / right.i);
}
const integer
  operator%(const integer& left,
            const integer& right) {
  allege(right.i != 0, "modulo by zero");
  return integer(left.i % right.i);
}
const integer
  operator^(const integer& left,
            const integer& right) {
  return integer(left.i ^ right.i);
}
const integer
  operator&(const integer& left,
            const integer& right) {
  return integer(left.i & right.i);
}
const integer
  operator|(const integer& left,
            const integer& right) {
  return integer(left.i | right.i);
}
const integer
  operator<<(const integer& left,
             const integer& right) {
  return integer(left.i << right.i);
}
const integer
  operator>>(const integer& left,
             const integer& right) {
  return integer(left.i >> right.i);
}
// Assignments modify & return lvalue:
integer& operator+=(integer& left,
                    const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i += right.i;
   return left;
}
integer& operator-=(integer& left,
                    const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i -= right.i;
   return left;
}
integer& operator*=(integer& left,
                    const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i *= right.i;
   return left;
}
integer& operator/=(integer& left,
                    const integer& right) {
   allege(right.i != 0, "divide by zero");
   if(&left == &right) {/* self-assignment */}
   left.i /= right.i;
   return left;
}
integer& operator%=(integer& left,
                    const integer& right) {
   allege(right.i != 0, "modulo by zero");
   if(&left == &right) {/* self-assignment */}
   left.i %= right.i;
   return left;
}
integer& operator^=(integer& left,
                    const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i ^= right.i;
   return left;
}
integer& operator&=(integer& left,
                    const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i &= right.i;
   return left;
}
integer& operator|=(integer& left,
                    const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i |= right.i;
   return left;
}
integer& operator>>=(integer& left,
                     const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i >>= right.i;
   return left;
}
integer& operator<<=(integer& left,
                     const integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i <<= right.i;
   return left;
}
// Conditional operators return true/false:
int operator==(const integer& left,
               const integer& right) {
    return left.i == right.i;
}
int operator!=(const integer& left,
               const integer& right) {
    return left.i != right.i;
}
int operator<(const integer& left,
              const integer& right) {
    return left.i < right.i;
}
int operator>(const integer& left,
              const integer& right) {
    return left.i > right.i;
}
int operator<=(const integer& left,
               const integer& right) {
    return left.i <= right.i;
}
int operator>=(const integer& left,
               const integer& right) {
    return left.i >= right.i;
}
int operator&&(const integer& left,
               const integer& right) {
    return left.i && right.i;
}
int operator||(const integer& left,
               const integer& right) {
    return left.i || right.i;
}

void h(integer& c1, integer& c2) {
  // A complex expression:
  c1 += c1 * c2 + c2 % c1;
  #define TRY(op) \
  out << "c1 = "; c1.print(out); \
  out << ", c2 = "; c2.print(out); \
  out << ";  c1 " #op " c2 produces ";\
  (c1 op c2).print(out); \
  out << endl;
  TRY(+) TRY(-) TRY(*) TRY(/)
  TRY(%) TRY(^) TRY(&) TRY(|)
  TRY(<<) TRY(>>) TRY(+=) TRY(-=)
  TRY(*=) TRY(/=) TRY(%=) TRY(^=)
  TRY(&=) TRY(|=) TRY(>>=) TRY(<<=)
  // Conditionals:
  #define TRYC(op) \
  out << "c1 = "; c1.print(out); \
  out << ", c2 = "; c2.print(out); \
  out << ";  c1 " #op " c2 produces ";\
  out << (c1 op c2); \
  out << endl;
  TRYC(<) TRYC(>) TRYC(==) TRYC(!=) TRYC(<=)
  TRYC(>=) TRYC(&&) TRYC(||)
}

// Member operators (implicit "this"):
class byte { // Combine this with UNARY.CPP
  unsigned char b;
public:
  byte(unsigned char B = 0) : b(B) {}
  // No side effects: const member function:
  const byte
    operator+(const byte& right) const {
    return byte(b + right.b);
  }
  const byte
    operator-(const byte& right) const {
    return byte(b - right.b);
  }
  const byte
    operator*(const byte& right) const {
    return byte(b * right.b);
  }
  const byte
    operator/(const byte& right) const {
    allege(right.b != 0, "divide by zero");
    return byte(b / right.b);
  }
  const byte
    operator%(const byte& right) const {
    allege(right.b != 0, "modulo by zero");
    return byte(b % right.b);
  }
  const byte
    operator^(const byte& right) const {
    return byte(b ^ right.b);
  }
  const byte
    operator&(const byte& right) const {
    return byte(b & right.b);
  }
  const byte
    operator|(const byte& right) const {
    return byte(b | right.b);
  }
  const byte
    operator<<(const byte& right) const {
    return byte(b << right.b);
  }
  const byte
    operator>>(const byte& right) const {
    return byte(b >> right.b);
  }
  // Assignments modify & return lvalue.
  // operator= can only be a member function:
  byte& operator=(const byte& right) {
    // Handle self-assignment:
    if(this == &right) return *this;
    b = right.b;
    return *this;
  }
  byte& operator+=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b += right.b;
    return *this;
  }
  byte& operator-=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b -= right.b;
    return *this;
  }
  byte& operator*=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b *= right.b;
    return *this;
  }
  byte& operator/=(const byte& right) {
    allege(right.b != 0, "divide by zero");
    if(this == &right) {/* self-assignment */}
    b /= right.b;
    return *this;
  }
  byte& operator%=(const byte& right) {
    allege(right.b != 0, "modulo by zero");
    if(this == &right) {/* self-assignment */}
    b %= right.b;
    return *this;
  }
  byte& operator^=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b ^= right.b;
    return *this;
  }
  byte& operator&=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b &= right.b;
    return *this;
  }
  byte& operator|=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b |= right.b;
    return *this;
  }
  byte& operator>>=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b >>= right.b;
    return *this;
  }
  byte& operator<<=(const byte& right) {
    if(this == &right) {/* self-assignment */}
    b <<= right.b;
    return *this;
  }
  // Conditional operators return true/false:
  int operator==(const byte& right) const {
      return b == right.b;
  }
  int operator!=(const byte& right) const {
      return b != right.b;
  }
  int operator<(const byte& right) const {
      return b < right.b;
  }
  int operator>(const byte& right) const {
      return b > right.b;
  }
  int operator<=(const byte& right) const {
      return b <= right.b;
  }
  int operator>=(const byte& right) const {
      return b >= right.b;
  }
  int operator&&(const byte& right) const {
      return b && right.b;
  }
  int operator||(const byte& right) const {
      return b || right.b;
  }
  // Write the contents to an ostream:
  void print(ostream& os) const {
    os << "0x" << hex << int(b) << dec;
  }
};

void k(byte& b1, byte& b2) {
  b1 = b1 * b2 + b2 % b1;

  #define TRY2(op) \
  out << "b1 = "; b1.print(out); \
  out << ", b2 = "; b2.print(out); \
  out << ";  b1 " #op " b2 produces ";\
  (b1 op b2).print(out); \
  out << endl;

  b1 = 9; b2 = 47;
  TRY2(+) TRY2(-) TRY2(*) TRY2(/)
  TRY2(%) TRY2(^) TRY2(&) TRY2(|)
  TRY2(<<) TRY2(>>) TRY2(+=) TRY2(-=)
  TRY2(*=) TRY2(/=) TRY2(%=) TRY2(^=)
  TRY2(&=) TRY2(|=) TRY2(>>=) TRY2(<<=)
  TRY2(=) // Assignment operator

  // Conditionals:
  #define TRYC2(op) \
  out << "b1 = "; b1.print(out); \
  out << ", b2 = "; b2.print(out); \
  out << ";  b1 " #op " b2 produces ";\
  out << (b1 op b2); \
  out << endl;

  b1 = 9; b2 = 47;
  TRYC2(<) TRYC2(>) TRYC2(==) TRYC2(!=) TRYC2(<=)
  TRYC2(>=) TRYC2(&&) TRYC2(||)

  // Chained assignment:
  byte b3 = 92;
  b1 = b2 = b3;
}

main() {
  integer c1(47), c2(9);
  h(c1, c2);
  out << "\n member functions:" << endl;
  byte b1(47), b2(9);
  k(b1, b2);
}

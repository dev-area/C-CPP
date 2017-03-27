// countpp1.cpp
// increment counter variable with ++ operator
#include <iostream.h>

class Counter
   {
   private:
      unsigned int count;                  // count
   public:
      Counter()         { count = 0; }     // constructor
      int get_count()   { return count; }  // return count
      Counter operator ++ ()  { ++count; return *this;}	 // increment (prefix)
	  Counter operator ++ (int) {Counter tmp=*this;	//increment(postfix)
								 ++count;
								 return tmp;}
   };

void main()
   {
   Counter c1, c2,c3;                     // define and initialize

   cout << "\nc1=" << c1.get_count();  // display
   cout << "\nc2=" << c2.get_count();

   ++c1;			       // increment c1
   ++c2;			       // increment c2
   c3=c2++;			       // increment c2

   cout << "\nc1=" << c1.get_count();  // display again
   cout << "\nc2=" << c2.get_count();
   cout << "\nc3=" << c3.get_count();
}

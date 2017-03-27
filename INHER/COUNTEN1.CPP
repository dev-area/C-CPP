// counten.cpp
// inheritance with Counter class
#include <iostream.h>

class Counter                   // base class
   {
   /***/:                            
      unsigned int count;                
   public:
      Counter()        { /***/ }    // constructor, no args
      Counter(int c)   { /***/ }    // constructor, one arg
      int get_count()  { /***/ } 
      Counter operator ++ ()		 // incr count (prefix)
	{ return /***/; }
   };

class CountDn : /***/		 // derived class
   {
   public:
      Counter operator -- ()		 // decr count (prefix)
	{ /***/ }
   };

void main()
   {
   CountDn c1;                          // c1 of class CountDn

   cout << "\nc1=" << c1.get_count();   // display c1

   ++c1; ++c1; ++c1;		        // increment c1
   cout << "\nc1=" << c1.get_count();   // display it

   --c1; --c1;			        // decrement c1
   cout << "\nc1=" << c1.get_count();   // display it
   }

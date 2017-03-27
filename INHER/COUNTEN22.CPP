// counten2.cpp
// constructors in derived class
#include <iostream.h>

class Counter
   {
   /***/:                            
      unsigned int count;                
   public:
      Counter()        { /***/ }    // constructor, no args
      Counter(int c)   { /***/ }    // constructor, one arg
      int get_count()  { /***/ } 
      Counter operator ++ ()		 // incr count (prefix)
	{ return /***/ }
   };

class CountDn : /***/
   {
   public:
      CountDn() : /***/              
	{ }
      CountDn(int c) : /***/        
	{ }
      CountDn operator -- ()		 // decr count (prefix)
	{ return /***/; }
   };

void main()
   {
   CountDn c1;                         // class CountDn
   CountDn c2(100);

   cout << "\nc1=" << c1.get_count();  // display
   cout << "\nc2=" << c2.get_count();  // display

   ++c1; ++c1; ++c1;		       // increment c1
   cout << "\nc1=" << c1.get_count();  // display it

   --c2; --c2;			       // decrement c2
   cout << "\nc2=" << c2.get_count();  // display it

   CountDn c3 = --c2;		       // create c3 from c2
   cout << "\nc3=" << c3.get_count();  // display c3
   }

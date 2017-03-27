// pubpriv.cpp
// tests publicly- and privately-derived classes
#include <iostream.h>

class A                 // base class
   {
   private:
      int privdataA;    // (functions have the same access
   protected:           // rules as the data shown here)
      int protdataA;
   public:
      int pubdataA;
   };

class B : public A      // publicly-derived class
   {
   public:
      void funct()
	 {
         int a;
	 a = privdataA;        // error: not accessible
	 a = protdataA;        // ok
	 a = pubdataA;         // ok
	 }
   };

class C : private A     // privately-derived class
   {
   public:
      void funct()
	 {
	 int a;
	 a = privdataA;        // error: not accessible
	 a = protdataA;        // ok
	 a = pubdataA;         // ok
	 }
   };

void main()             // main()
   int a;

   B objB;
   a = objB.privdataA;  // error: not accessible
   a = objB.protdataA;  // error: not accessible
   a = objB.pubdataA;   // ok                    (A public to B)

   C objC;
   a = objC.privdataA;  // error: not accessible
   a = objC.protdataA;  // error: not accessible
   a = objC.pubdataA;   // error: not accessible (A private to C)
   }
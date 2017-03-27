// ambigu.cpp
// demonstrates ambiguity in multiple inheritance
#include <iostream.h>

class A
   {
   public:
      void show()  { cout << "\nClass A"; }
   };
class B
   {
   public:
      void show()  { cout << "\nClass B"; }
   };
class C : public A, public B
   {
   };

void main()
   {
   C objC;            // object of class C
   objC.show();       // ambiguous--will not compile
   objC.A::show();    // ok
   objC.B::show();    // ok
   }
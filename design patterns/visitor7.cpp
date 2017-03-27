#include <iostream>
using namespace std;

class Base { public:
   virtual void process1( Base& ) = 0;
   virtual void process2( class A& ) = 0;
   virtual void process2( class B& ) = 0;
   virtual void process2( class C& ) = 0;
};

class A : public Base { public:
   /*virtual*/ void process1( Base& second ) { second.process2( *this ); }
   /*virtual*/ void process2( class A& first ) {
      cout << "first is A, second is A\n"; }
   /*virtual*/ void process2( class B& first ) {
      cout << "first is B, second is A\n"; }
   /*virtual*/ void process2( class C& first ) {
      cout << "first is C, second is A\n"; }
};

class B : public Base { public:
   /*virtual*/ void process1( Base& second ) { second.process2( *this ); }
   /*virtual*/ void process2( class A& first ) {
      cout << "first is A, second is B\n"; }
   /*virtual*/ void process2( class B& first ) {
      cout << "first is B, second is B\n"; }
   /*virtual*/ void process2( class C& first ) {
      cout << "first is C, second is B\n"; }
};

class C : public Base { public:
   /*virtual*/ void process1( Base& second ) { second.process2( *this ); }
   /*virtual*/ void process2( class A& first ) {
      cout << "first is A, second is C\n"; }
   /*virtual*/ void process2( class B& first ) {
      cout << "first is B, second is C\n"; }
   /*virtual*/ void process2( class C& first ) {
      cout << "first is C, second is C\n"; }
};

void main( void ) {
   Base* array[] = { &A(), &B(), &C() };
   for (int i=0; i < 3; i++)
      for (int j=0; j < 3; j++)
         array[i]->process1( *array[j] );
}

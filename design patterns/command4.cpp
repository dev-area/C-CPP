#include <iostream>
#include <string>
using namespace std;

class A {
   int divisor;
public:
   A( int div ) { divisor = div; }
   int divide( int in ) { return in / divisor; }
   int modulus( int in ) { return in % divisor; }
};

class B {
   string str;
public:
   B( string s ) { str = s; }
   string prepend(  string in ) { return in + str; }
   string postpend( string in ) { return str + in; }
};

template <typename CLS, typename ARG>
class Command {
public:
   typedef ARG (CLS::*Action)( ARG );
   Command( CLS* o, Action m, ARG a ) {
      object = o;
      method = m;
      argument = a;
   }
   ARG execute() { return (object->*method)( argument ); }
private:
   CLS*   object;
   Action method;
   ARG    argument;
};

void main( void ) {
   Command<A,int>* list1[4] = {
      &Command<A,int>( &A(3), &A::divide,  16 ),
      &Command<A,int>( &A(3), &A::modulus, 16 ),
      &Command<A,int>( &A(4), &A::divide,  16 ),
      &Command<A,int>( &A(4), &A::modulus, 16 ) };
   for (int i=0; i < 4; i++)
      cout << "numbers are " << list1[i]->execute() << '\n';

   B obj("abc");
   Command<B,string>* list2[4] = {
      new Command<B,string>( &obj, &B::prepend,  "123" ),
      new Command<B,string>( &obj, &B::prepend,  "xyz" ),
      new Command<B,string>( &obj, &B::postpend, "123" ),
      new Command<B,string>( &obj, &B::postpend, "xyz" ) };
   for (i=0; i < 4; i++)
      cout << "strings are " << list2[i]->execute() << '\n';
}

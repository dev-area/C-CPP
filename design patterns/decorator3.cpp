#include <iostream>
using namespace std;

class I { public:
   virtual ~I() { }
   virtual void doIt() = 0;
};

class A : public I { public:
   ~A() { cout << "A dtor" << '\n'; }
   /*virtual*/ void doIt() { cout << 'A'; }
};

class D : public I {
   I* wrappee;
public:
   D( I* inner )           { wrappee = inner; }
   ~D()                    { delete wrappee; }
   /*virtual*/ void doIt() { wrappee->doIt(); }
};

class X : public D { public:
   X( I* core ) : D(core) { }
   ~X() { cout << "X dtor" << "   "; }
   /*virtual*/ void doIt() { D::doIt();  cout << 'X'; }
};

class Y : public D { public:
   Y( I* core ) : D(core) { }
   ~Y() { cout << "Y dtor" << "   "; }
   /*virtual*/ void doIt() { D::doIt();  cout << 'Y'; }
};

class Z : public D { public:
   Z( I* core ) : D(core) { }
   ~Z() { cout << "Z dtor" << "   "; }
   /*virtual*/ void doIt() { D::doIt();  cout << 'Z'; }
};

void main( void ) {
   I* anX = new X( new A );
   I* anXY = new Y( new X( new A ) );
   I* anXYZ = new Z( new Y( new X( new A ) ) );
   anX->doIt();    cout << '\n';
   anXY->doIt();   cout << '\n';
   anXYZ->doIt();  cout << '\n';
   delete anX;   delete anXY;   delete anXYZ;
}
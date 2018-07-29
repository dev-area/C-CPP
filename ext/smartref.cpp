#include <iostream>
using namespace std;


class A {
public:
    virtual A & operator++() = 0;
    virtual A & operator++(int) = 0;
};

class B:public A{
    int x,y;
public:
    B(int x1,int y1):x(x1),y(y1){}
    virtual B &operator++(){
        return *new B(10,20);
    }
    virtual B &operator++(int){
        return *new B(100,200);
     }
    void print(){
        cout << x << " " << y  << endl;
    }
};

class C{
    int x,y;
public:
    C(int r):x(r),y(r){}
    C() = default;
    const C * operator&() const {return this;}
    C * operator&() {cout << "op &\n"; return this;}
};

int main2( void ) {
    C c1;
    auto p = &c1;
    B b1(2,3);
    (b1++).print();

}


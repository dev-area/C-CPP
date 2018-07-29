#include <iostream>
using namespace std;

class A{
    int x,y;
public:
    virtual void f1() = 0;
    virtual void f3() = 0;
    virtual void f2(){
        f1();
    }
    virtual void f4(){
        f3();
    }
    virtual ~A() = 0;
};

A::~A(){}

void A::f1() {
    cout << "A\n";
}

class B: public A{
    int z,w;
    void f3(){cout << "B f3\n";}
public:
    virtual void f1(){cout << "B f1\n"; A::f1();}
};


class C: public A{
    int z,w;
    void f3(){cout << "C f3\n";}
public:
    virtual void f1(){cout << "C f1\n";}
};



int main1() {
    A *arr[4];
    arr[0] = new B();
    arr[1] = new C();
    arr[2] = new C();
    arr[3] = new B();
    for (int i=0;i<4;i++)
        arr[i]->f4();
    return 0;
}
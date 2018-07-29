#include <iostream>

using namespace std;


template <typename T>
struct A {
  void fn() {
    (static_cast<T*>(this))->fn();
  }
};

struct B : public A<B> {
  void fn() {
    cout << "B foo" << endl;
  }
};

struct C : public A<C> {
  void fn() {
    cout << "C foo" << endl;
  }
};

template<typename T>
void ProcessFoo(A<T>* b) {
  b->fn();
}


int main3()
{
    B d1;
    C d2;
    ProcessFoo(&d1);
    ProcessFoo(&d2);
    return 0;
}
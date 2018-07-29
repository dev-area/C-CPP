#include <iostream>
using namespace std;
class A{
        int r,u;
public:
        A(int y):r(y){}
        A(int g,int h):A(g){}
        A operator+(const A &a1){
            A res(this->r + a1.r,this->u + a1.u);
            return res;
        }
};

void foo(int& x)  // lvalue reference overload
{
    cout << "lvalue\n";
    x=90;
}
void foo(int&& x) // rvalue reference overload
{
    cout << "rvalue\n";
}

template<typename T1, typename T2>
 auto my_make_pair (T1 a, T2 b) -> pair<T1,T2>{
    return pair<T1,T2> {a,b};
}

template<class T, class U>
auto add(T t, U u) { return t + u; } // the return type is the type of operator+(T, U)

// perfect forwarding of a function call must use decltype(auto)
// in case the function it calls returns by reference
template<class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args)
{
    return fun(std::forward<Args>(args)...);
}

int main10() {
    int s=9;
    foo(s);
    foo(100);


//    A&  a_ref3 = A(3);  // Error!
    A&& a_ref4 = A(4);


    auto pr=my_make_pair(10,"hello");
    cout << pr.first << endl;

    auto d1=PerfectForward(add<int,int>,10,20);
    cout << d1 << endl;

    return 0;
}
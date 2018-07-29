#include <functional>  
#include <iostream>  
using namespace std;


auto getfn(int x){
    auto fn = [=](int y){return x+y;};
    return fn;
}

template<typename T1,typename T2>
auto mul(T1 a, T2 b) -> decltype(a*b){
    return a*b;
}


int main()
{  
   int i = 3;
    auto b=5min;
    auto b2=67min;
    b--;
    b+=b2;
    cout << b.count() << endl;
   int j = 5;  
    cout << mul(24,6.8) << endl;

   // The following lambda expression captures i by value and  
   // j by reference.  
   function<int (void)> f = [i, &j] { return i + j; };
  
   // Change the values of i and j.  
   i = 22;  
   j = 44;  
  
   // Call f and print its result.  
   cout << f() << endl;

    auto f1 = getfn(1000);

    cout << f1(20) << endl;
}  
#include <iostream>
using namespace std;

class Sdemo{
    int x,y;
public:
    Sdemo(int x1=0,int y1=0):x(x1),y(y1){}
    void fn(){
        cout << "fn:" << x << endl;
    }
    void reset(){x=y=0;}
    ~Sdemo(){cout << "del\n";}
};

void fn(shared_ptr<Sdemo> p)
{
    p->fn();
    cout << p.use_count() << endl;
}


int main8() {
    weak_ptr<Sdemo> wk1;


    {
        auto p2 = make_shared<Sdemo>(1);

        fn(p2);
        cout << p2.use_count() << endl;


        shared_ptr<Sdemo> p1 = p2;

        cout << p2.use_count() << endl;

        wk1 = weak_ptr<Sdemo>(p2);
        if(auto tmp = wk1.lock()){
            tmp->fn();
        }
    }
    if(auto tmp = wk1.lock()){
        tmp->fn();
    }

    return 0;
}
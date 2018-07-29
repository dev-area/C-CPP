#include <iostream>
using namespace std;


class Pdemo{
    int x,y;
public:
    Pdemo(int x1=0,int y1=0):x(x1),y(y1){}
    void fn(){
        cout << "fn:" << x << endl;
    }
    void reset(){x=y=0;}
    ~Pdemo(){cout << "del\n";}
};

int main7(){
    unique_ptr<Pdemo> up1(new Pdemo(1));
    up1->fn();

}



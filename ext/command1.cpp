#include <iostream>
using namespace std;

namespace dp {
    class ExecuteInterface {
    public:
        virtual ~ExecuteInterface() {}

        virtual void execute() = 0;
    };

    template<typename TYPE>
    class ExecuteAdapter : public ExecuteInterface {
    public:
        ExecuteAdapter(TYPE *o, void (TYPE::*m)()) {
            object = o;
            method = m;
        }

        ~ExecuteAdapter() { delete object; }

        void execute() {
            (object->*method)();
        }

    private:
        TYPE *object;

        void (TYPE::*method)();
    };

    class A {
    public:
        ~A() { cout << "A::dtor" << endl; }

        void doThis() { cout << "A::doThis()" << endl; }
    };

    class B {
    public:
        ~B() { cout << "B::dtor" << endl; }

        void doThat() { cout << "B::doThat()" << endl; }
    };

    class C {
    public:
        ~C() { cout << "C::dtor" << endl; }

        void doTheOther() { cout << "C::doTheOther()" << endl; }
    };

    ExecuteInterface **initialize() {
        ExecuteInterface **array = new ExecuteInterface *[3];
        array[0] = new ExecuteAdapter<A>(new A(), &A::doThis);
        array[1] = new ExecuteAdapter<B>(new B(), &B::doThat);
        array[2] = new ExecuteAdapter<C>(new C(), &C::doTheOther);
        return array;
    }
}
using namespace dp;

    int main__(void) {
        ExecuteInterface **objects = initialize();

        for (int i = 0; i < 3; i++)
            objects[i]->execute();

        for (int i = 0; i < 3; i++)
            delete objects[i];
        delete objects;
        return 0;
    }

#include <iostream>
using namespace std;

class Instrument { public: virtual ~Instrument() { } };

class IOU : public Instrument {
   int amount;
public:
   IOU( int in ) { amount = in; }
   int payUp() { return amount; }
};

class Check : public Instrument {
   int amount;
public:
   Check( int in ) { amount = in; }
   int cash() { return amount; }
};

class Stock : public Instrument {
   int amount;
public:
   Stock( int in ) { amount = in; }
   int redeem() { return amount; }
};

class Command {
public:
   typedef int (Instrument::*Action)();
   Command( Instrument* o, Action m ) {
      object = o;
      method = m;
   }
   int execute() { return (object->*method)(); }
private:
   Instrument* object;
   Action      method;
};

void main( void ) {
   Command* portfolio[] = {  // old C cast, or new RTTI is required
      &Command( &IOU(100),   (int(Instrument::*)())&IOU::payUp ),
      &Command( &Check(200), static_cast<int(Instrument::*)()>(&Check::cash) ),
      &Command( &Stock(300), static_cast<int(Instrument::*)()>(&Stock::redeem) ) };
   for (int netWorth=0, i=0; i < 3; i++)
      netWorth += portfolio[i]->execute();
   cout << "net worth is now " << netWorth << '\n';
}

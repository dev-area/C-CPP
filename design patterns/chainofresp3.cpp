#include <iostream>
#include <ctime>
using namespace std;

class Link {
   int   id;
   Link* next;                       // 1. "next" pointer
   static int   theBid;              // 4. Current bid and bidder
   static Link* bidder;
public:
   Link( int num ) { id = num;  next = 0; }
   void addLast( Link* l ) {
      if (next) next->addLast( l );  // 2. Handle and/or pass on
      else      next = l; 
   }
   void bid() {
      int num = rand() % 9;
      cout << id << '-' << num << "  ";
      if (num < theBid) {
         theBid = num;               // 4. Current bid and bidder
         bidder = this;
      }
      if (next) next->bid();         // 2. Handle and/or pass on
      else      bidder->execute();   // 5. The last 1 assigns the job
   }
   void execute() {
      cout << id << " is executing\n";
      theBid = 999;
}  };
int   Link::theBid = 999;            // 4. Current bid and bidder
Link* Link::bidder = 0;

void main( void ) {
   Link chain( 1 );
   for (int i=2; i < 7; i++)
      chain.addLast( new Link( i ) );
   srand( time( 0 ) );
   for (i=0; i < 10; i++)
      chain.bid();                   // 3. Client "launches & leaves"
}

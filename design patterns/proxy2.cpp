#include <iostream>
#include <string>
using namespace std;


class RealImage {
   int  id;
public:
   RealImage( int i ) { id = i;  cout << "   $$ ctor: "<< id << '\n'; }
   ~RealImage()                { cout << "   dtor: " << id << '\n'; }
   void draw()                 { cout << "   drawing image " << id << '\n'; }
};

// 1. Design an "extra level of indirection" wrapper class
class Image {
   // 2. The wrapper class holds a pointer to the real class
   RealImage* theRealThing;
   int        id;
   static int next;
public:
   Image()  { id = next++;  theRealThing = 0; }  // 3. Initialized to null
   ~Image() { delete theRealThing; }
   void draw() {
      // 4. When a request comes in, the real object is created "on first use"
      if ( ! theRealThing) theRealThing = new RealImage( id );
      // 5. The request is always delegated
      theRealThing->draw();
}  };
int Image::next = 1;

void main( void ) {
   Image images[5];
   int   i;

   cout << "Exit[0], Image[1-5]: ";
   cin >> i;
   while (i) {
      images[i-1].draw();
      cout << "Exit[0], Image[1-5]: ";
      cin >> i;
}  }


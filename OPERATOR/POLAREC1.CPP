// polarec1.cpp
// converts from Polar to Rec using routines in Polar (source)
#include <iostream.h>
#include <math.h>            // for sin(), cos(), etc.

class Rec
   {
   private:
      double xco;                    // x coordinate
      double yco;                    // y coordinate
   public:
      Rec()                          // constructor 0, no args
	 { xco = 0.0; yco = 0.0; }
      Rec(double x, double y)        // constructor 2, two args
	 { xco = x; yco = y; }
      void display()                 // display
	 { cout << "("  << xco
		<< ", " << yco << ")"; }
   };

class Polar
   {
   private:
      double radius;
      double angle;          
   public:
      Polar()                        // constructor 0, no args
	 { radius=0.0; angle=0.0; }
      Polar(double r, double a)      // constructor 2, two args
	 { radius=r; angle=a; }
      void display()                 // display
	 { cout << "("  << radius
		<< ", " << angle << ")"; }
      operator Rec()                 // conversion function
	 {                           // Polar to Rect
	 double x = radius * cos(angle);  // find x and y to
	 double y = radius * sin(angle);  // initialize nameless
	 return Rec(x, y);                // Rec for return
	 }
   };

void main()                                 
   {                                    
   Rec rec;                          // Rec using constructor 0
   Polar pol(10.0, 0.785398);        // Polar using constructor 2

   rec = pol;                        // convert Polar to Rec
				     // using conversion function
				     // or use rec = Rec(pol);

   cout << "\npol="; pol.display();  // display original Polar
   cout << "\nrec="; rec.display();  // display equivalent Rect
   }
// polarec2.cpp
// converts Polar to Rec using routine in Rec (destination)
#include <iostream.h>
#include <math.h>                    // for sin(), cos(), etc.

class Polar                          // point, polar coordinates
   {
   private:
      double radius;                 // radius coord
      double angle;                  // angle coord (radians)
   public:
      Polar()                        // constructor, no args
	 { radius=0.0; angle=0.0; }
      Polar(double r, double a)      // constructor, two args
	 { radius=r; angle=a; }
      void display()                 // display
	 { cout << "("  << radius
		<< ", " << angle << ")"; }
      double getr()                  // these routines allow
	 { return radius; }          // radius and angle to be
      double geta()                  // accessed from outside
	 { return angle; }           // the class
   };

class Rec                            // point, rectangular coords
   {
   private:
      double xco;                    // x coordinate
      double yco;                    // y coordinte
   public:
      Rec()                          // constructor 0, no args
	 { xco = 0.0; yco = 0.0; }
      Rec(double x, double y)        // constructor 2, two args
	 { xco = x; yco = y; }
      Rec(Polar p)                   // constructor 1, one arg
	 {                           //    Polar to Rec
	 double r = p.getr();
	 double a = p.geta();        // get r and a from Polar
	 xco = r * cos(a);           // using getr() and geta()
	 yco = r * sin(a);           // change to our xco and yco
	 }
      void display()                 // display
	 { cout << "("  << xco
		<< ", " << yco << ")"; }
   };

void main()                                 
   {                                    
   Rec rec;                          // Rec using constructor 1
   Polar pol(10.0, 0.785398);        // Polar using constructor 2

   rec = pol;                        // convert Polar to Rec

   cout << "\npol="; pol.display();  // display original Polar
   cout << "\nrec="; rec.display();  // display converted Rec
   }
// polaplus.cpp
// operator '+' with polar coordinates
#include <iostream.h>
#include <math.h>            // for sin(), cos(), etc.

class Polar
   {
   private:
      double radius;                     // distance
      double angle;                      // angle in radians

      double getx()                      // these two functions
	 { return radius*cos(angle); }   // convert this Polar
      double gety()                      // object into x and y
	 { return radius*sin(angle); }   // rectangular coords
   public:
      Polar()                            // constructor, no args
	 { radius=0.0; angle=0.0; }
      Polar(double r, double a)          // constructor, two args
	 { radius=r; angle=a; }
      void display()                     // display
	 { cout << "("  << radius
		<< ", " << angle << ")"; }
      Polar operator + (Polar p2)        // add two Polars
	 {
	 double x = getx() + p2.getx();  // add x and y coords
	 double y = gety() + p2.gety();  // for this and p2
	 double r = sqrt(x*x + y*y);     // convert new x and y
	 double a = atan(y/x);           // to Polar
	 return Polar(r, a);             // return temp Polar
	 }
   };

void main()
   {
   Polar p1(10.0, 0.0);            // line to the right
   Polar p2(10.0, 1.570796325);    // line straight up
   Polar p3;                       // uninitialized Polar

   p3 = p1 + p2;                   // add two Polars

   cout << "\np1="; p1.display();  // display all Polars
   cout << "\np2="; p2.display();
   cout << "\np3="; p3.display();
   }
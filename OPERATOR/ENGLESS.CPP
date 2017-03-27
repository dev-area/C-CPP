// engless.cpp
// overloaded '<' operator compares two Distances
#include <iostream.h>

enum boolean { false, true };

class Distance                    // English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      Distance()                  // constructor (no args)
	 { feet = 0; inches = 0.0; }
      Distance(int ft, float in)  // constructor (two args)
	 { feet = ft; inches = in; }
      void getdist()              // get length from user
	 {
	 cout << "\nEnter feet: ";  cin >> feet;
	 cout << "Enter inches: ";  cin >> inches;
	 }
      void showdist()             // display distance
	 { cout << feet << "\'-" << inches << '\"'; }
      boolean operator < (Distance);  // compare distances
   };
				 // compare this distance with d2
boolean Distance::operator < (Distance d2)   // return the sum
   {
   float bf1 = feet + inches/12;
   float bf2 = d2.feet + d2.inches/12;
   return (bf1 < bf2) ? true : false;
   }

void main()
   {
   Distance dist1;                 // define Distance dist1
   dist1.getdist();                // get dist1 from user

   Distance dist2(6, 2.5);         // define and initialize dist2
				   // display distances
   cout << "\ndist1 = ";  dist1.showdist();
   cout << "\ndist2 = ";  dist2.showdist();

   if( dist1 < dist2 )             // overloaded '<' operator
      cout << "\ndist1 is less than dist2";
   else
      cout << "\ndist1 is greater than dist2";
   }

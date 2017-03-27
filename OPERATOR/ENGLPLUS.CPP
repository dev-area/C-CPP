// englplus.cpp
// overloaded '+' operator adds two Distances
#include <iostream.h>

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

      Distance operator + ( Distance );  // add two distances
   };
				  // add this distance to d2
Distance Distance::operator + (Distance d2)   // return the sum
   {
   int f = feet + d2.feet;        // add the feet
   float i = inches + d2.inches;  // add the inches
   if(i >= 12.0)                  // if total exceeds 12.0,
      {                           // then decrease inches
      i -= 12.0;                  // by 12.0 and
      f++;                        // increase feet by 1
      }                           // return a temporary Distance
   return Distance(f,i);          // initialized to sum
   }

void main()
   {
   Distance dist1, dist3, dist4;   // define distances
   dist1.getdist();                // get dist1 from user
			  
   Distance dist2(11, 6.25);       // define, initialize dist2

   dist3 = dist1 + dist2;          // single '+' operator

   dist4 = dist1 + dist2 + dist3;  // multiple '+' operators

				   // display all lengths
   cout << "\ndist1 = ";  dist1.showdist();
   cout << "\ndist2 = ";  dist2.showdist();
   cout << "\ndist3 = ";  dist3.showdist();
   cout << "\ndist4 = ";  dist4.showdist();
   }

// englconv.cpp
// conversions: Distance to meters, meters to Distance
#include <iostream.h>

const float MTF = 3.280833;       // meters to feet

class Distance                    // English Distance class
   {
   private:
      int feet;
      float inches;
   public:
      Distance()                  // constructor (no args)
	 { feet = 0; inches = 0.0; }
      Distance( float meters )    // constructor (one arg)
	 {                        // convert meters to Distance
	 float fltfeet = MTF * meters;  // convert to float feet
	 feet = int(fltfeet);           // feet is integer part
	 inches = 12*(fltfeet-feet);    // inches is what's left
	 }
      Distance(int ft, float in)  // constructor (two args)
	 { feet = ft; inches = in; }
      void getdist()              // get length from user
	 {
	 cout << "\nEnter feet: ";  cin >> feet;
	 cout << "Enter inches: ";  cin >> inches;
	 }
      void showdist()             // display distance
	 { cout << feet << "\'-" << inches << '\"'; }

      operator float()            // conversion function
	 {                        // converts Distance to meters
	 float fracfeet = inches/12;  // convert the inches
	 fracfeet += float(feet);     // add the feet
	 return fracfeet/MTF;         // convert to meters
	 }
   };

void main()
   {
   Distance dist1 = 2.35;          // uses 1-arg constructor to
				   // convert meters to Distance
   cout << "\ndist1 = "; dist1.showdist();

   dist1 = 1.00;                   // this form also uses
				   // 1-arg constructor
   cout << "\ndist1 = ";  dist1.showdist();


   Distance dist2(5, 10.25);       // uses 2-arg constructor

   float mtrs = float(dist2);      // uses conversion function to
				   // convert Distance to meters
   cout << "\ndist2 = " << mtrs << " meters";

   mtrs = dist1;                   // this form also uses
				   // conversion function
   cout << "\ndist1 = " << mtrs << " meters";
   }

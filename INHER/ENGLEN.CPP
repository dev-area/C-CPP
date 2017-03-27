// englen.cpp
// inheritance using English Distances
#include <iostream.h>

class Distance                    // English Distance class
   {
   protected:                     // NOTE: can't be private
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
   };

enum posneg { pos, neg };  // for sign in DistSign

class DistSign : public Distance  // adds sign to Distance
   {
   private:
      posneg sign;                // sign is pos or neg
   public:
			          // constructor  (no args)
      DistSign() : Distance()     // call base constructor
	 { sign = pos; }          // set the sign to +

			          // constructor (2 or 3 args)
      DistSign(int ft, float in, posneg sg=pos) :
              Distance(ft, in)    // call base constructor
	 { sign = sg; }           // set the sign

      void getdist()              // get length from user
	 {
	 Distance::getdist();     // call base getdist()
	 char ch;                 // get sign from user
	 cout << "Enter sign (+ or -): ";  cin >> ch;
	 sign = (ch=='+') ? pos : neg;
	 }

      void showdist()             // display distance
	 {
	 cout << ( (sign==pos) ? "(+)" : "(-)" );  // show sign
	 Distance::showdist();                     // ft and in
	 }
   };

void main()
   {
   DistSign alpha;                  // no-arg constructor
   alpha.getdist();                 // get alpha from user

   DistSign beta(11, 6.25);         // 2-arg constructor

   DistSign gamma(100, 5.5, neg);   // 3-arg constructor

				     // display all distances
   cout << "\nalpha = ";  alpha.showdist();
   cout << "\nbeta = ";  beta.showdist();
   cout << "\ngamma = ";  gamma.showdist();
   }

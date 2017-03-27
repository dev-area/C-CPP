// englmult.cpp
// multiple inheritance with English Distances
#include <iostream.h>
#include <string.h>       // for strcpy()

const int LEN = 40;       // maximum length of strings

class Type                // type of lumber
   {
   private:
      char dimensions[LEN];
      char grade[LEN];
   public:
      Type()                      // constructor (no args)
	 { strcpy(dimensions, "N/A"); strcpy(grade, "N/A"); }

      Type(char di[], char gr[])  // constructor (two args)
	 { strcpy(dimensions, di); strcpy(grade, gr); }

      void gettype()              // get type from user
	 {
	 cout << "   Enter nominal dimensions (2x4 etc.): ";
	 cin >> dimensions;
	 cout << "   Enter grade (rough, const, etc.): ";
	 cin >> grade;
	 }
      void showtype()             // display type
	 {
	 cout << "\n   Dimensions: " << dimensions;
	 cout << "\n   Grade: " << grade;
	 }
   };

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
	 cout << "   Enter feet: ";  cin >> feet;
	 cout << "   Enter inches: ";  cin >> inches;
	 }
      void showdist()             // display distance
	 { cout  << feet << "\'-" << inches << '\"'; }
   };

class Lumber : public Type, public Distance
   {
   private:
      int quantity;                      // number of pieces
      float price;                       // price of each piece
   public:
      Lumber() : Type(), Distance()      // constructor (no args)
	 { quantity = 0; price = 0.0; }
					 // constructor (6 args)
      Lumber( char di[], char gr[],      // args for Type
	      int ft, float in,          // args for Distance
	      int qu, float prc ) :      // our own args
	      Type(di, gr),              // call Type constructor
	      Distance(ft, in)           // call Distance constr
	 {
	 quantity = qu; price = prc;     // use our own args
	 }
      void getlumber()
	 {
	 Type::gettype();
	 Distance::getdist();
	 cout << "   Enter quantity: "; cin >> quantity;
	 cout << "   Enter price per piece: "; cin >> price;
	 }
      void showlumber()
	 {
	 Type::showtype();
	 cout << "\n   Length: ";
	 Distance::showdist();
	 cout << "\n   Price for " << quantity
	      << " pieces: $" << price * quantity;
	 }
   };

void main()
   {
   Lumber siding;                   // constructor (no args)

   cout << "\nSiding data:\n";
   siding.getlumber();              // get siding from user

				    // constructor (6 args)
   Lumber studs( "2x4", "const", 8, 0.0, 200, 4.45 );

				    // display lumber data
   cout << "\nSiding";  siding.showlumber();
   cout << "\nStuds";     studs.showlumber();
   }

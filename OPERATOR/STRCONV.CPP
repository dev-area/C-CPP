// strconv.cpp
// convert between ordinary strings and class String
#include <iostream.h>
#include <string.h>      // for strcpy(), etc.

const int SZ = 80;       // size of all String objects

class String             // user-defined string type
   {
   private:
      char str[SZ];               // holds a string
   public:
      String()                    // constructor 0, no args
	 { str[0] = '\0'; }

      String( char s[] )          // constructor 1, one arg
	 { strcpy(str, s); }      // convert string to String

      void display()              // display the String
	 { cout << str; }

      operator char*()            // conversion function
	 { return str; }          // convert String to string
   };

void main()
   {
   String s1;                     // use constructor 0
   char xstr[] =                  // create and initialize string
	    "\nJoyeux Noel! ";
   s1 = xstr;                     // use constructor 1
				  // to convert string to String
   s1.display();                  // display String

   String s2 = "Bonne Annee!";    // uses constructor 1
				  // to initialize String

   cout << (char*)s2;             // use conversion function
				  // to convert String to string
				  // before sending to << op
   }

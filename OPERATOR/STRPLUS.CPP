// strplus.cpp
// overloaded '+' operator concatenates strings
#include <iostream.h>
#include <string.h>	 // for strcpy(), strcat()
#include <stdlib.h>	 // for exit()

const int SZ = 80;       // size of all String objects

class String             // user-defined string type
   {
   private:
      char str[SZ];                  // holds a string
   public:
      String()                       // constructor, no args
	 { strcpy(str, ""); }
      String( char s[] )             // constructor, one arg
	 { strcpy(str, s); }
      void display()                 // display the String
	 { cout << str; }
      String operator + (String ss)  // add a String to another
	 {
	 String temp;		     // make a temporary String
	 if( strlen(str) + strlen(ss.str) < SZ )
	    {
	    strcpy(temp.str, str);   // copy this string to temp
	    strcat(temp.str, ss.str);  // add the argument string
	    }
	 else
	    { cout << "\nString overflow"; exit(1); }
	 return temp;			// return temp String
	 }
   };

void main()
   {
   String s1 = "\nhave a   ";   // uses constructor 2
   String s2 = "good day!";        // uses constructor 2
   String s3;                            // uses constructor 1

   s1.display();         // display strings
   s2.display();
   s3.display();

   s3 = s1 + s2;         // add s2 to s1, assign to s3

   s3.display();         // display s3
   }

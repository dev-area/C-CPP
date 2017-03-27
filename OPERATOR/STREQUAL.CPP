// strequal.cpp
// overloaded '==' operator compares strings
#include <iostream.h>
#include <string.h>      // for strcmp()

const int SZ = 80;       // size of all String objects
enum boolean { false, true };

class String             // user-defined string type
   {
   private:
      char str[SZ];                    // holds a string
   public:
      String()                         // constructor, no args
	 { strcpy(str, ""); }
      String( char s[] )               // constructor, one arg
	 { strcpy(str, s); }
      void display()                   // display a String
	 { cout << str; }
      void getstr()                    // read a string
	 { cin.get(str, SZ); }
      boolean operator == (String ss)  // check for equality
	 {
	 return ( strcmp(str, ss.str)==0 ) ? true : false;
	 }
   };

void main()
   {
   String s1 = "yes";
   String s2 = "no";
   String s3;

   cout << "\nEnter 'yes' or 'no': ";
   s3.getstr();                          // get String from user

   if(s3==s1)                            // compare with "yes"
      cout << "You typed yes\n";
   else if(s3==s2)                       // compare with "no"
      cout << "You typed no\n";
   else
      cout << "You didn't follow instructions\n";
   }

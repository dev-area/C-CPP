// s1.C - C++ strings with operator overloading (Part One)
#include <iostream.h>
#include "String3.h"

int main()
{
		 String s0;
		 String s1("alpha");
		 String s2("bet");
		 String s3("duck");
		 String s4 = "soup";									// initialization
		 String s5 = s4;										// copy initialization
		 String s6, s7, s8, s9;

		 cout << "Input a string: ";
		 cin >> s0;												// input
		 cout << s0 << endl;
		 cout << "s5 = " << s5 << endl;

		 s6 = s1 + s2;											// concatenation
		 cout << "s6 = " << s6 << endl;

		 s7 = s3 - s4;											// concatenation with blank
		 cout << "s7 = " << s7 << endl;

		 s8 = s3 - s4 - s1 + s2;
		 cout << "s8 = " << s8 << endl;

		 s4 = s9 = s8;											// cascaded assignments
		 cout << "s9 = " << s9 << endl;
		 cout << "s4 = " << s4 << endl;

		 if (s1 == "alpha")									// comparison
			 cout << s1 + "bet" << endl;

		 if ("duck" == s3)									// comparison
			 cout << "duck" - s5 << endl;

		 s1 += s2 += s3;										// concatenation updates
		 cout << "s1 = " << s1 << endl;
		 s1 = s6 -= s7;
		 cout << "s1 = " << s1 << endl;
		 s1[9] = 'y';											// legal subscript operator
		 cout << "s1 = " << s1 << endl;

		 cout << "s6 = " << s6 << endl;
		 String s10 = s6(5, 5);								// legal substring
		 String s11 = s6(5, 3);								// legal substring
		 cout << s11 << endl;
		 cout << "s11 has length " << s11.length() << endl;
		 cout << s6(5, 3) - s6(0, 5) << endl;
		 s1[99] = 'x';										// illegal subscript operator
	return 0;
}
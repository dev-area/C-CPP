//      Example C++ program to show the use of class and object
//	and Dynamic memory
//
//
//      Requires a project file which contains the following :-
//
//      contact3.cpp    
//      example5.cpp    
//
//      Compile the project by using F9 key
//      Run the program by using Ctrl+F9 keys
//
//

#include <conio.h>
#include "contact5.h"


void main() {

	clrscr();

	Contact *contacts = new Contact[4];  // declares an array of contact objects
				   // with default constructor
	{
	 Contact *cptr = contacts; // need a copy of the pointer for
				   // access to each contact in the array
	 for(int i=0;  i<4; i++)
		{cout << "Please enter Contact " << i+1 << "'s details\n";
		 cptr -> getContactDetails();
		 cptr++;}}

	{
	 Contact *cptr = contacts; // need a copy of the pointer for
				   // access to each contact in the array
	 for(int i=0;i<4;i++)
		{cout << "Contact " << i+1 << "'s details are\n";
		 cptr->displayContactDetails();
		 cout << "Press any key to continue ... ";
		 getch();
		 cout << "\n";
		 cptr ++;}}

//
//      Delete the Contacts array from Dynamic Memory. Destructor called
//	once for each object in the array
//

	delete [] contacts;
	getch();
}


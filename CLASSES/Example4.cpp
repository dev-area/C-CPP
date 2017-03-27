//      Example C++ program to show the use of class and object
//
//
//      Requires a project file which contains the following :-
//
//      contact.cpp     
//      example4.cpp    
//
//      Compile the project by using F9 key
//      Run the program by using Ctrl+F9 keys
//
//

#include <conio.h>
#include "contact3.h"

void main() {

	clrscr();
	Contact aContact;       // declares a contact object with
				// default constructor
				// NOTE do NOT put in brackets
				// Contact aContact(); is WRONG!!

	aContact.displayContactDetails();

	cout << "Press any key to continue ...\n";
	getch();

	{ // block to show object scope
	 Contact bContact("Phillip","Line 1","Line 2","Line 3",
			  "Phillip's district","2792-4183","2792-8374");
//
//	Create object using other constructor
//

	 bContact.displayContactDetails();  // send message to method

	 cout << "\nPress any key to continue ...\n";
	 getch();

	} // bContact goes out of scope ... destructor called

	cout << "bContact out of scope and has been destroyed\n";
	cout << "Now aContact goes out of scope and will be destroyed\n";

	cout << "\nPress any key to continue ... \n";
	getch();
	cout << "\n";

//
//	Destructor is automatically called for aContact
//

}


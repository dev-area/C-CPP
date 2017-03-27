//      Example C++ program to show the use of class and object
//
//
//      Requires a project file which contains the following :-
//
//      contact1.cpp          
//      example2.cpp     
//
//      Compile the project by using F9 key
//      Run the program by using Ctrl+F9 keys
//
//

#include <conio.h>
#include "contact1.h"

void main() {

	Contact aContact;       // declares a contact object

	clrscr();
	aContact.getContactDetails();      // send message to method
	aContact.displayContactDetails();  // send message to method
	getch();
}


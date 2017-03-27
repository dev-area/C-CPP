//
//      Example C++ program to show the use of class and object
//      and static class member
//
//
//      Requires a project file which contains the following :-
//
//      contact.cpp          
//      example2.cpp    
//
//      Compile the project by using F9 key
//      Run the program by using Ctrl+F9 keys
//
//

#include <conio.h>
#include "contact2.h"

void main() {

	Contact aContact, bContact;        // declares two contact objects

	clrscr();
	cout << "\nContact 1\n=======\n\n";
	aContact.getContactDetails();      // send message to method

	cout << "\nContact 2\n=======\n\n";
	bContact.getContactDetails();      // send message to method

	cout << "\nContact 1\n=======\n\nDefault iddCode\n";
	aContact.displayContactDetails();  // send message to method

	cout << "Press any key to continue ...";
	getch();

	cout << "\nContact 2\n=======\n\nDefault iddCode\n";
	bContact.displayContactDetails();  // send message to method

	cout << "Press any key to continue ...";
	getch();

//      Now change the value of iddCode and it will affect both objects!

	Contact::setIDDCode("44"); // use class as static member function is called

	cout << "\nContact 1\n=======\n\nChanged iddCode\n";
	aContact.displayContactDetails();  // send message to method

	cout << "Press any key to continue...";
	getch();

	cout << "\nContact 2\n=======\n\nChanged iddCode\n";
	bContact.displayContactDetails();  // send message to method

	cout << "Press any key to continue...";
	getch();
	cout << "\n";
}


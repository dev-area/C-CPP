//	Example C++ program to show the use of class and object
//	Objects as class members
//
//
//      Requires a project file which contains the following :-
//
//	contact3.cpp	 
//      supplier.cpp     
//      example6.cpp     
//
//      Compile the project by using F9 key
//      Run the program by using Ctrl+F9 keys
//
//

#include <conio.h>
#include "supplier.h"
#include "contact3.h"

void main() {

	clrscr();
	Supplier aSupplier("Frographics","Phillip");
//
//	Declares a supplier object with supplier name Frographics
//	contact name Phillip. All other data members of contact are set
//	to their defaults by the contact's other constructor.
//	Note the order of construction.
//

	cout << "Press any key to continue ... \n";
	getch();

	aSupplier.displaySupplierDetails();

	cout << "Press any key to continue ...\n";
	getch();

	Contact aContact; 		// default constructor used
	aContact.getContactDetails();

	Supplier bSupplier("ABC Limited",aContact);

//
//	Creates a supplier object with name ABC Limited. Calls the contact
//	default constructor for the contact data member, then copies aContact
//	to it.
//
	bSupplier.getSupplierContact().displayContactDetails();

//
//	Two tier message. First, find the contact object contained within
//	supplier bSupplier, then send it a message to display the details.
//

	cout << "Press any key to continue ...\n";
	getch();

//	Now all objects (including those as class members) destroyed
//	Switch to output window (use F6 key) to see order of destruction
//
}




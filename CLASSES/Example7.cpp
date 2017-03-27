//      Example C++ program to show the use of class and object
//
//
//      Requires a project file which contains the following :-
//
//      contact4.cpp    
//      example7.cpp    
//
//      Compile the project by using F9 key
//      Run the program by using Ctrl+F9 keys
//
//

#include <conio.h>
#include "contact4.h"


void main() {

	clrscr();

	Contact contacts[4];       // declares an array of contact objects
				   // with default constructor
	{
	 for(int i=0;i<4;i++)
		{cout << "Please enter Contact " << i+1 << "'s details\n";
		 contacts[i].getContactDetails();}}

	{
	 for(int i=0;i<4;i++)
		{cout << "Contact " << i+1 << "'s details are\n"
		      << contacts[i];
		 cout << "Press any key to continue ... ";
		 getch();
		 cout << "\n";}}

//
//      All contacts now go out of scope. Destructor called once
//      per object in the array
//

}


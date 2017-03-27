//	C++ Case Study 1
//	----------------
//
//	Program to implement a database of contacts
//
//
//	Requires a project file which contains the following :-
//
//	contact3.cpp	
//	cfile.cpp	
//	cdbase1.cpp	
//	menu.cpp	
//	case1.cpp	
//	main1.cpp	
//
//	Compile the project by using F9 key
//	Run the project by using Ctrl+F9 key
//
//

#include "case1.h"

void main()
{
	Menu theMenu;

	initialiseMenu(theMenu);

	int choice = 0;
	while (choice != 9)
	{
	   choice = theMenu.processMenu();
	   processChoice(choice);
	}
}

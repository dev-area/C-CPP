//	menu.cpp
//
//	Implementation of menu class
//
//	A very simple menu system that just uses C++ stream I/O
//	without any regard to screen positioning.
//
//	For ease of use, each menu choice is associated with an
//	integer 1 -> 8, 9 being reserved for exit. This allows
//	the menu choice to be processed by inspecting a single
//	key press.
//
//	Seven lines in a menu is the recommened maximum for good
//	interfaces.
//

#include "menu.h"

//	Constructor

Menu::Menu()
{
	for (unsigned i = 0; i < MENUSIZE; i++)
	    strcpy(menuLine[i], "");
	strcpy(menuLine[MENUSIZE], "9. Exit");
	numberOfItems = 0;
}

//	Access functions

void Menu::setMenuItem(int index, char *menuString)
{
	strncpy(menuLine[index-1], menuString, MAXLINELEN);

//	array starts at 0

	numberOfItems++;
}

//	Manipulator functions

void Menu::displayMenu()

//	Only invoked from processMenu() and defined to be private
//	Only display lines that have been set

{
	clrscr();
	for (unsigned i = 0; i < getNumberOfItems(); i++)
	cout << i+1 << ". "	// so that numbering displays from 1
	     << menuLine[i]
	     << '\n';
	cout << "\n\n" << menuLine[MENUSIZE] << '\n';
	cout << "\n\nPress keys 1 -> "
	     << getNumberOfItems()
	     << " for menu choice. Or press key 9 to exit";
}

int Menu::processMenu()

//	Displays menu, prompts for and validates user's choice
//	Loops until valid choice is entered.
//	Returns user's choice as an int

{
	int choice;

	while (1)
	{
	 displayMenu();
	 choice = int(getch()) - 48;	// C++ functional notation for cast
					// subtract 48 to get range 1 -> 9
	 if ((choice >= 1 && choice <= getNumberOfItems()) || choice == 9)
	    break;	// choice OK
	 getch();
	}
	return choice;
}





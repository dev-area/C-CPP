//	menu.h
//
//	Class header file for menu
//

#ifndef MENU_H
#define MENU_H

#include <iostream.h>	// basic stream I/O for menu
#include <conio.h>
#include <string.h>

const	MENUSIZE = 8;	// excludes exit option
const	MAXLINELEN = 26; // menu line limited to 25 chars
			 // one extra for \0 terminator character

class	Menu {
public:

//	Constructor

	Menu();

//	Access functions

	void setMenuItem(int index, char *menuString);
	int getNumberOfItems() {return numberOfItems;}

//	Manipulator functions

	int processMenu();

private:
	char menuLine[MENUSIZE+1][MAXLINELEN];	// allow for exit option
	int  numberOfItems;

	void displayMenu();	// private since only used by processMenu()

};

#endif


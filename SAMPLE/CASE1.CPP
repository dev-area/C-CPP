//	case1.cpp
//
//	Implementation of functions called by main program

#include <ctype.h>	// for toupper()
#include "case1.h"

char *fileName = "contacts.txt";   // cannot be array of char!

	ContactDatabase theDatabase(fileName);
// 	global to all functions
//	fixed filename, file must be in the same directory as project
//	files

void	initialiseMenu(Menu &inMenu)
{
	inMenu.setMenuItem(1, "Load database");
	inMenu.setMenuItem(2, "Add a contact");
	inMenu.setMenuItem(3, "Change a contact");
	inMenu.setMenuItem(4, "Delete a contact");
	inMenu.setMenuItem(5, "Display all contacts");
	inMenu.setMenuItem(6, "Display one contact");
	inMenu.setMenuItem(7, "Save database");
}
void	processChoice(int inChoice)
{
	switch (inChoice)
	{
	   case 1 : openDatabase(); break;
	   case 2 : addContact(); break;
	   case 3 : break;
	   case 4 : break;
	   case 5 : theDatabase.displayAllContacts(); break;
	   case 6 : displayAContact(); break;
	   case 7 : closeDatabase(); break;
	}
}

void	openDatabase()

//	Attempts to open the database "contacts.txt" which must be
//	stored in the same directory as the executable program.
//
//	If the open fails then the user is offered the choice of
//	creating a new, empty database.
//
//	The first time the program is run, it will fail since the
//	database has not yet been created. After that it should
//	be OK unless the file is deleted or moved to another location.

{
	clrscr();
	cout << "Opening database: "
	     << theDatabase.getFileName() << "\n\n";

	if (theDatabase.openDatabase())	// open OK
	{
	   cout << "Press any key to continue ... ";
	   getch();
	}
	else	// error
	{
	   cout << "Database could not be opened:\n"
		<< "Probably does not exist, or has been deleted"
		<< " or moved\n\n"
		<< "Create a new empty database? (Y/N)\n";

	   char reply = toupper(getch());
	   if (reply == 'Y')	// any key other than Y is treated as N
	   {
	      theDatabase.newDatabase();
	      cout << "Press any key to continue ... ";
	      getch();
	   }
	}
}

void	addContact()
{
	Contact aContact;

	clrscr();
	aContact.getContactDetails();
	theDatabase.addContact(aContact);
	cout << "Press any key to continue ... ";
	getch();
}

void	displayAContact()

//	First we have to get which contact the user wishes to display.
//	This is done the simple way by requesting an integer in the
//	range from 1 -> the number of contacts in the database

{
	int index = 0;

	while (index < 1 || index > theDatabase.getNumberOfContacts())
	{
	 clrscr();
	 cout << "Which contact do you wish to display the details of?\n\n";
	 cout << "Enter a number between 1 and "
	      << theDatabase.getNumberOfContacts() << " ";
	 cin >> index;
	}

//	We must not execute the following line with an invalid value of
//	index! (Actually no harm will be done, but as the array of
//	contacts is created with a defualt constructor, the values of
//	these contacts will be undefined, and so rubbish will appear.
//	But to send the message with an invalid value of index is not
//	good programming practice. If index had a value greater than the
//	size of the array, then it would be harmful and the program would
//	hang or crash!)


	theDatabase.getContact(index).displayContactDetails();

	cout << "Press any key to continue ...";
	getch();
}
void	closeDatabase()

{
	clrscr();
	if (!theDatabase.closeDatabase())	// error in closing
	{
	   cout << "The database could not be saved\n\n"
		<< "Probable reasons for failure :\n\n"
		<< "Disk full\n"
		<< "Disk write protected\n"
		<< "Diskette is not in the drive\n\n";
	}
	cout << "Press any key to continue ...";
	getch();
}

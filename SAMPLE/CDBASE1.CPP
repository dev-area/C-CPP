//	cdbase1.cpp
//
//	Implementation of ContactDatabase class
//
//	Uses fixed size array loaded from a text file.
//

#include "cdbase1.h"

//	Constructor

ContactDatabase::ContactDatabase(char *inFileName)
		: theDatabase(inFileName)
{
	resetNumberOfContacts();
}

//	Access functions

void ContactDatabase::displayAllContacts()
{
	for (unsigned i = 0; i < getNumberOfContacts(); i++)
	   {
	    clrscr();
	    cout << "CONTACT " << i+1 << '\n'
		 << "-------\n";
	    theContacts[i].displayContactDetails();
	    cout << "Press any key to continue ...\n";
	    getch();
	   }
}

//	Manipulator functions

int ContactDatabase::openDatabase()

//	Attempts to open the textfile and load contact records to
//	an array. The name of the text file has been specified in
//	the ContactDatabase constructor and passed to the Cfile
//	constructor
//
//	Returns 0 is error in opening text file
//	Returns 1 for success
//

{
	if (!theDatabase.openFileRead())
	    return 0;	// error in opening

//	All OK here - we have an file open for reading

	do
	{
	 theDatabase.readContactRecord(theContacts[getNumberOfContacts()]);
	 if (!theDatabase.endOfFile())
	    incNumberOfContacts();
	} while (!theDatabase.endOfFile());

	cout << "Database contains " << getNumberOfContacts();
	if (getNumberOfContacts() == 1)
	   cout << " contact\n";
	else
	   cout << " contacts\n";

	theDatabase.closeFile();
	return 1;

}

int ContactDatabase::closeDatabase()

//	Attempts to open the textfile and write contact records from
//	an array. The name of the text file has been specified in
//	the ContactDatabase constructor and passed to the Cfile
//	constructor
//
//	Returns 0 is error in opening text file
//	Returns 1 for success
//

{
	if (!theDatabase.openFileWrite())
	   return 0;	// error in opening

//	All OK here - we have an file open for writing

	for (unsigned i = 0; i < getNumberOfContacts(); i++)
	    theDatabase.writeContactRecord(theContacts[i]);

	cout << "Database saved successfully\n";

	resetNumberOfContacts();

//	If we do set the number of contacts back to 0, the next open
//	database will append to the current array and not start at the
//	beginning of the array.

	theDatabase.closeFile();
	return 1;
}

int ContactDatabase::newDatabase()


//	Attempts to create a new textfile. The name of the text file
//	has been specified in the ContactDatabase constructor and
//	passed to the Cfile constructor
//
//	Returns 0 is error in opening text file
//	Returns 1 for success
//

{
	if (!theDatabase.openFileWrite())
	   return 1;	// error in opening

//	All OK here - we have create a new text file

	cout << "New Database created\n";

	theDatabase.closeFile();
	return 1;
}

void ContactDatabase::addContact(Contact &inContact)

//	Attempts to add a new contact referenced by inContact to the
//	array of contacts

{
	if (getNumberOfContacts() == DATABASESIZE)
	   cout << "The database is full and no more contacts can be added\n";
	else
	   {
	    theContacts[getNumberOfContacts()] = inContact; // copy constructor
	    incNumberOfContacts();
	   }
}

//	All other functions are left as dummy and are to be completed
//	as part of assignment 1

void ContactDatabase::deleteContact(int index)
{}

void ContactDatabase::updateContact(int index, Contact &inContact)
{}

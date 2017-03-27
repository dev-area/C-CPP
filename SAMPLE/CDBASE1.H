//	cdbase1.h
//
//	class header file for database of contacts
//
//	Implemented as a fixed size array which is loaded from text file
//

#ifndef CDBASE1_H
#define CDBASE1_H

#include <iostream.h>
#include <conio.h>
#include "cfile.h"	// also includes contact3.h

const	DATABASESIZE = 100;

class	ContactDatabase {
public:

//	Constructor

	ContactDatabase(char *inFileName);

//	Access functions

	void displayAllContacts();
	Contact &getContact(int index) {return theContacts[index-1];}
//	index argument will be passed starting from 1, so in the return
//	statement 1 is subtracted since C++ array subscripts start at 0

	int getNumberOfContacts() {return numberOfContacts;}
	char *getFileName() {return theDatabase.getFileName();}

//	Manipluator functions

	int openDatabase();
	int closeDatabase();
	int newDatabase();
	void addContact(Contact &inContact);
	void deleteContact(int index);
	void updateContact(int index, Contact &inContact);

private:
	ContactFile theDatabase;
	Contact     theContacts[DATABASESIZE];
	int         numberOfContacts;

	void resetNumberOfContacts() {numberOfContacts = 0;}
	void incNumberOfContacts() {numberOfContacts++;}
	// only accessed by access and manipulator functions
	// hence private

};

#endif

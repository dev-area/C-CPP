// Person.h
//
// Base class definition This is an abstract class so NO objects of this
// type may be declared.
//
// Just for fun we will use dynamic memory allocation for the data members

#ifndef PERSON_H
#define PERSON_H

#include <iostream.h>
#include <conio.h>
#include <string.h>

const NAMELEN = 30;
const ADDRLEN = 40;

class Person
{
   public:
	   // Constructors
	   Person();
	   Person(char *inName, char *inAddr1, char *inAddr2,
		  char *inAddr3, char *inAddr4, char *inDOB);

	   // Destructor is virtual as this is a base class
	   virtual ~Person();

	   // Access functions
	   void setName(char *inName) { name = new char[NAMELEN+1];
					strcpy(name,inName);}
	   char *getName()            { return name;}
	   void setAddress(char *inAddr, int line)
		{ address[line] = new char[ADDRLEN];
		  strcpy(address[line],inAddr); }
	   char *getAddress(int line) { return address[line]; }
	   void setDateOfBirth(char *inDOB) { dateOfBirth = new char[9];
					      strcpy(dateOfBirth,inDOB); }
	   char *getDateOfBirth() { return dateOfBirth; }

	   // Manipulator functions virtual since this is a base class

	   virtual void getDetails();
	   virtual void printDetails() = 0;

	   // Pure virtual function makes Person an abstract base class

   private:
	   char *name;
	   char *address[4];
	   char *dateOfBirth;
};

#endif

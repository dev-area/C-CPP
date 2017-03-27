// Person.cpp
// Implementation of base class Person

#include "Person.h"

// Default constructor

Person::Person()
{
   cout << "Person default constructor\n";

   setName("");
   setAddress("",0);
   setAddress("",1);
   setAddress("",2);
   setAddress("",3);
   setDateOfBirth("");
}

// Initialiser constructor

Person::Person(char *inName, char *inAddr1, char *inAddr2, char *inAddr3,
	       char *inAddr4, char *inDOB)

{
   cout << "Person initialiser constructor\n";

   setName(inName);
   setAddress(inAddr1,0);
   setAddress(inAddr2,1);
   setAddress(inAddr3,2);
   setAddress(inAddr4,3);
   setDateOfBirth(inDOB);
}

// Destructor has deallocate the memory allocated when the object is
// constructed

Person::~Person()
{
   cout << "Person destructor called\n";

   delete name;
   delete address;
   delete dateOfBirth;
}

// Manipulator functions

void Person::getDetails()
{
   char  inName[NAMELEN];
   char  inAddress[ADDRLEN];
   char  inDOB[9];

   cout << "Enter the Person's name: ";
   cin.get(inName,NAMELEN);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');
   setName(inName);

   for (int i=0; i<4; i++)
   {
      cout << "Enter line " << i+1 << " of the address: ";
      cin.get(inAddress,ADDRLEN);
      // Ignore the newline still left in the input stream
      cin.ignore(255,'\n');
      setAddress(inAddress,i);
   }

   cout << "Enter the Person's date of birth (dd/mm/yy): ";
   cin.get(inDOB,9);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');
   setDateOfBirth(inDOB);
}

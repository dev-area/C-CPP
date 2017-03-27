// Staff.cpp
// Implementation of derived class Staff

#include "Staff.h"

// Default constructor will also use default constructor for the
// base class person

Staff::Staff()
{
   cout << "Staff default constructor\n";

   setDepartment("");
   setGrade("");
}

// Initialiser constructor will use the initialiser constructor
// for the base class Person

Staff::Staff(char *inName, char *inAddr1, char *inAddr2, char *inAddr3,
	     char *inAddr4, char *inDOB, int inID, char *inDept,
	     char *inGrade)
	: Person(inName, inAddr1, inAddr2, inAddr3, inAddr4, inDOB),
	  staff_ID(inID)
//
//	We MUST call the base class constructor using an initialiser list
//

{
   cout << "Staff initialiser constructor\n";
   setDepartment(inDept);
   setGrade(inGrade);
}

// Destructor must deallocate memory allocated when the object is
// created

Staff::~Staff()
{
   cout << "Staff destructor called\n";
   delete department;
   delete grade;
}

// Manipulator functions

void Staff::getDetails()
{
   int   inID;
   char  inDept[DEPTLEN];
   char  inGrade[3];

// First get the details for the inherited datamembers by calling the
// base class function getDetails()

   Person::getDetails();
   cout << "Enter the Staff's ID (numeric): ";
   cin >> inID;
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

   cout << "Enter the Staff's department: ";
   cin.get(inDept, DEPTLEN);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

   cout << "Enter the Staff's grade: ";
   cin.get(inGrade,3);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

// Use access functions to store values in data members
   setID(inID);
   setDepartment(inDept);
   setGrade(inGrade);
}

void Staff::printDetails()
{

// As printdetails is a pure virtual function we call the inherited
// access functions for output

   cout << "The details of the Staff are:\n";
   cout << "==============================\n\n";
   cout << "Name:\t\t" << getName() << '\n';
   cout << "Address:\t" << getAddress(0) << '\n';
   for (int i=1; i<4; i++)
      cout << "\t\t" << getAddress(i) << '\n';
   cout << "Date of birth:\t" << getDateOfBirth() << '\n';
   cout << "Staff ID:\t" << getID() << '\n';
   cout << "Department:\t" << getDepartment() << '\n';
   cout << "Grade:\t\t" << getGrade() << '\n';
}
// Student.cpp
// Implementation of derived class Student

#include "Student.h"

// Default constructor will also use default constructor for the
// base class person

Student::Student()
{
   cout << "Student default constructor\n";

   setID(0);
   setGPA(0.0);
   setYear(0);
}

// Initialiser constructor will use the initialiser constructor
// for the base class Person

Student::Student(char *inName, char *inAddr1, char *inAddr2, char *inAddr3,
		 char *inAddr4, char *inDOB,int inID, float inGPA,
		 int inYear)
	: Person(inName, inAddr1, inAddr2, inAddr3, inAddr4, inDOB),
	  student_ID(inID), gpa(inGPA), year(inYear)
//
//	We MUST call the base class constructor using an initialiser list
//

{
   cout << "Student initialiser constructor\n";
}

// Destructor not needed in the class, but added so you can see when
// it is called

Student::~Student()
{
   cout << "Student destructor called\n";
}

// Manipulator functions

void Student::getDetails()
{
   int   inID;
   char  inName[NAMELEN];
   float inGPA;
   int   inYear;

// First get the details for the inherited datamembers by calling the
// base class function getDetails()

   Person::getDetails();
   cout << "Enter the student's ID (numeric): ";
   cin >> inID;

   cout << "Enter the student's GPA (decimal): ";
   cin >> inGPA;

   cout << "Enter the student's year of study: ";
   cin >> inYear;
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

// set the values in data members
   setID(inID);
   setGPA(inGPA);
   setYear(inYear);
}

void Student::printDetails()
{

// As printdetails is a pure virtual function we call the inherited
// access functions for output

   cout << "The details of the student are:\n";
   cout << "==============================\n\n";
   cout << "Name:\t\t" << getName() << '\n';
   cout << "Address:\t" << getAddress(0) << '\n';
   for (int i=1; i<4; i++)
      cout << "\t\t" << getAddress(i) << '\n';
   cout << "Date of birth:\t" << getDateOfBirth() << '\n';
   cout << "Student ID:\t" << getID() << '\n';
   cout.precision(1);
   cout << "GPA:\t\t" <<  getGPA() << '\n';
   cout << "Year:\t\t" << getYear() << '\n';
}
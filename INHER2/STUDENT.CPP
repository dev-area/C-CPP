// Student.cpp
// Implementation of base class Student

#include "student.h"

// Default constructor

Student::Student()
{
   cout << "Student default constructor\n";

   setID(0);
   setName("");
   setGPA(0.0);
   setYear(0);
}

// Initialiser constructor

Student::Student(int inID, char *inName, float inGPA, int inYear)
	: student_ID(inID), gpa(inGPA), year(inYear)

// Although an initialiser list can be used here you MUST note that
// the data member type MUST be assignment compatable. This includes
// the types int, float, double, char etc and objects. BEWARE of objects
// as a copy constructor is needed.
//
// A more flexible approach would be to use the access functions as in the
// default constructor, but I show this as an alternative.

{
   cout << "Student initialiser constructor\n";

   setName(inName); // Have to use access function, since arrays of char
		    // are not assignment compatable and so cannot appear
		    // in an initialiser list.
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

   cout << "Enter the student's ID (numeric): ";
   cin >> inID;

// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

   cout << "Enter the student's name: ";
   cin.get(inName,NAMELEN);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

   cout << "Enter the student's GPA (decimal): ";
   cin >> inGPA;

   cout << "Enter the student's year of study: ";
   cin >> inYear;
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

// set the values in data members
   setID(inID);
   setName(inName);
   setGPA(inGPA);
   setYear(inYear);
}

void Student::printDetails()
{
   cout << "The details of the student are:\n";
   cout << "==============================\n\n";
   cout << "ID:\t" << getID() << '\n';
   cout << "Name:\t" << getName() << '\n';
   cout.precision(1);
   cout << "GPA:\t" <<  getGPA() << '\n';
   cout << "Year:\t" << getYear() << '\n';
}
// GStudent.cpp
// Implementation of derived class grad_Student

#include "gstudent.h"

// Default constructor

grad_Student::grad_Student()
	     :Student()

//
// ALWAYS call the base class constructor using an initialiser list!
//

{
   cout << "Graduate student default constructor\n";

   setDept("");
   setThesis("");
}

// Initialiser constructor

grad_Student::grad_Student(int inID, char *inName, float inGPA, int inYear,
			   char *inDept, char *inThesis)
	     : Student(inID,inName,inGPA,inYear)

//
// ALWAYS call the base class constructor using an initialiser list!
//

{
   cout << "Graduate student initialiser constructor\n";

   setDept(inDept);
   setThesis(inThesis);
}

// Destructor not needed in the class, but added so you can see when
// it is called

grad_Student::~grad_Student()
{
   cout << "Graduate Student destructor called\n";
}

// Manipulator functions

void grad_Student::getDetails()

// This function overiden the base class getDetails
// BUT we can still access it to get data for the inherited data members

{
   char  inDept[DEPTLEN];
   char  inThesis[THESISLEN];

   Student::getDetails();	// call member function in base class
				// to get data for inherited data members

   cout << "Enter the student's department: ";
   cin.get(inDept,DEPTLEN);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

   cout << "Enter the student's thesis title: ";
   cin.get(inThesis,THESISLEN);
// Ignore the newline still left in the input stream
   cin.ignore(255,'\n');

// set the values in data members
   setDept(inDept);
   setThesis(inThesis);
}

void grad_Student::printDetails()

// This function overiden the base class function printDetails()
// BUT we can still access it to print data for the inherited data members

{
   Student::printDetails();	// access base class member function
				// to print data for inherited data members
   cout << "Department:\t " << getDept() << '\n';
   cout << "Thesis:\t" << getThesis() << '\n';
}
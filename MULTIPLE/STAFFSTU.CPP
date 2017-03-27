// StaffStu.cpp
// Implementation of derived class StaffStu

#include "StaffStu.h"

// Default constructor will also use default constructor for the
// base classes Student and Staff

StaffStudent::StaffStudent()
{
   cout << "StaffStudent default constructor\n";

   setThesis("");
}

// Initialiser constructor will use the initialiser constructor
// for the base classes Student and Staff

StaffStudent::StaffStudent(char *inName, char *inAddr1, char *inAddr2,
			   char *inAddr3, char *inAddr4, char *inDOB,
			   int inID1, float inGPA, int inYear, int inID2,
			   char *inDept, char *inGrade, char *inThesis)
	: Person(inName, inAddr1, inAddr2, inAddr3, inAddr4, inDOB),
	  Student(inName, inAddr1, inAddr2, inAddr3, inAddr4, inDOB,
		  inID1, inGPA, inYear),
	  Staff(inName, inAddr1, inAddr2, inAddr3, inAddr4, inDOB,
		inID2, inDept, inGrade)
//
// We MUST call the three base class constructor using an initialiser list
// We need to call Person constructor due to virtual inheritance
//

{
   cout << "StaffStu initialiser constructor\n";

   setThesis(inThesis);
}

// Destructor must deallocate memory allocated when object is created

StaffStudent::~StaffStudent()
{
   cout << "StaffStu destructor called\n";

   delete thesis;
}

// Manipulator functions

void StaffStudent::getDetails()
{
   int   inID;
   char  inDept[DEPTLEN];
   char  inGrade[3];
   char  inThesis[THESISLEN];

// First get the details for the inherited datamembers by calling the
// Student base class function getDetails()

   Student::getDetails();  // could also have used Staff::getDetails()

// Now get the details for the inherited data members by calling
// access functions for Staff

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
   Staff::setID(inID);
   setDepartment(inDept);
   setGrade(inGrade);

   cout << "Enter the thesis title : ";
   cin.get(inThesis, THESISLEN);
   cin.ignore(255,'\n');
   setThesis(inThesis);
}

void StaffStudent::printDetails()
{

// As we are using mulitple inheritance calling the base class
// printDetails would result in some information being displayed
// twice, so we use the inherited access functions

   cout << "The details of the StaffStudent are:\n";
   cout << "==============================\n\n";
   cout << "Name:\t\t" << getName() << '\n';
   cout << "Address:\t" << getAddress(0) << '\n';
   for (int i=1; i<4; i++)
      cout << "\t\t" << getAddress(i) << '\n';
   cout << "Date of birth:\t" << getDateOfBirth() << '\n';
   cout << "Student ID:\t" << Student::getID() << '\n';
   cout.precision(1);
   cout << "GPA:\t\t" <<  getGPA() << '\n';
   cout << "Year:\t\t" << getYear() << '\n';
   cout << "Staff ID:\t" << Staff::getID() << '\n';
   cout << "Department:\t" << getDepartment() << '\n';
   cout << "Grade:\t\t" << getGrade() << '\n';
   cout << "Thesis:\t\t" << getThesis() << '\n';

// NOTE in the above we must use the class name on the access function
// getID(). This is because the same name is used in both the Student
// and Staff classes, and by using multiple inheritance we get two
// function of the same name! Using the class name resolves this ambiguity.

}
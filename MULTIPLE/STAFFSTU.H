// StaffStu.h
//
// Derived class definition

#ifndef StaffStu_H
#define StaffStu_H

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include "Student.h"
#include "Staff.h"

// Derived from base classes Student and Staff.

const THESISLEN = 80;

class StaffStudent : public Student, public Staff

{
   public:
	   // Constructors
	   StaffStudent();
	   StaffStudent(char *inName, char *inAddr1, char *inAddr2,
			char *inAddr3, char *inAddr4, char *inDOB,
			int inID1,  float inGPA, int inYear, int inID2,
			char *inDept, char *inGrade,
			char *inThesis);
	   // We must supply arguments for the inherited data members

	   // Destructor
	   ~StaffStudent();

	   // Access functions
	   void setThesis(char *inThesis) { thesis = new char[THESISLEN];
					    strcpy(thesis, inThesis); }
	   char *getThesis() { return thesis; }

	   // Manipulator functions
	   virtual void getDetails();
	   virtual void printDetails();
   private:
	   char *thesis;
};

#endif

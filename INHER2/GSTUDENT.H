// GStudent.h
//
// Derived class definition inherits from Student

#ifndef GSTUDENT_H
#define GSTUDENT_H

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include "student.h"

const DEPTLEN = 10;
const THESISLEN = 80;

class grad_Student : public Student
{
   public:
	   // Constructors
	   grad_Student();
	   grad_Student(int inID, char *inName, float inGPA, int inYear,
			char *,char *);
	   // Must include paramters for inherited data members as well
	   // as for new data members

	   // Destructor
	   ~grad_Student();

	   // Access functions only need for new data members
	   void setDept(char *inDept)     { strcpy(dept,inDept);}
	   char *getDept()                { return dept;}
	   void setThesis(char *inThesis) { strcpy(thesis,inThesis);}
	   char *getThesis()              { return thesis;}

	   // Manipulator functions, these override the inherited
	   // data functions

	   void getDetails();
	   void printDetails();
   private:
	   char  dept[DEPTLEN+1];	// allow for null terminator
	   char  thesis[THESISLEN+1];
};

#endif
// Student.h
//
// Derived class definition

#ifndef Student_H
#define Student_H

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include "Person.h"

// Derived from base class Person. We use virtual inheritance so that
// if any class is derived from Student using multiple inheritance
// then Person will only be inherited once.

class Student : virtual public Person

{
   public:
	   // Constructors
	   Student();
	   Student(char *inName, char *inAddr1, char *inAddr2,
		   char *inAddr3, char *inAddr4, char *inDOB,
		   int inID,  float inGPA, int inYear);
	   // We must supply arguments for the inherited data members

	   // Destructor
	   ~Student();

	   // Access functions
	   void setID(int inID)       { student_ID = inID;}
	   int  getID()               { return student_ID;}
	   void setGPA(float inGPA)   { gpa = inGPA;}
	   float getGPA()             { return gpa;}
	   void setYear(int inYear)   { year = inYear;}
	   int  getYear()             { return year;}

	   // Manipulator functions
	   virtual void getDetails();
	   virtual void printDetails();
   private:
	   int   student_ID;
	   float gpa;
	   int   year;
};

#endif

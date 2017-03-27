// Staff.h
//
// Derived class definition

#ifndef Staff_H
#define Staff_H

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include "Person.h"

// Derived from base class Person. We use virtual inheritance so that
// if any class is derived from Staff using multiple inheritance
// then Person will only be inherited once.

const DEPTLEN = 20;

class Staff : virtual public Person

{
   public:
	   // Constructors
	   Staff();
	   Staff(char *inName, char *inAddr1, char *inAddr2,
		 char *inAddr3, char *inAddr4, char *inDOB,
		 int inID,  char *inDept, char *inGrade);
	   // We must supply arguments for the inherited data members

	   // Destructor
	   ~Staff();

	   // Access functions
	   void setID(int inID)       { staff_ID = inID;}
	   int  getID()               { return staff_ID;}
	   void setDepartment(char *inDept)
		{ department = new char[DEPTLEN+1];
		  strcpy(department, inDept); }
	   char *getDepartment() { return department; }
	   void setGrade(char *inGrade)
		{ grade = new char[3];
		  strcpy(grade, inGrade); }
	   char *getGrade() { return grade; }

	   // Manipulator functions
	   virtual void getDetails();
	   virtual void printDetails();
   private:
	   int   staff_ID;
	   char *department;
	   char *grade;
};

#endif

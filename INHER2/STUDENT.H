// Student.h
//
// Base class definition

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream.h>
#include <conio.h>
#include <string.h>

const NAMELEN = 30;

class Student
{
   public:
	   // Constructors
	   Student();
	   Student(int inID, char *inName, float inGPA, int inYear);

	   // Destructor
	   ~Student();

	   // Access functions
	   void setID(int inID)       { student_ID = inID;}
	   int  getID()               { return student_ID;}
	   void setName(char *inName) { strcpy(name,inName);}
	   char *getName()            { return name;}
	   void setGPA(float inGPA)   { gpa = inGPA;}
	   float getGPA()             { return gpa;}
	   void setYear(int inYear)   { year = inYear;}
	   int  getYear()             { return year;}

	   // Manipulator functions
	   void getDetails();
	   void printDetails();
   private:
	   int   student_ID;
	   char  name[NAMELEN+1];	// allow for null terminator
	   float gpa;
	   int   year;
};

#endif

// Example9.cpp
//
//
// Requires a project of the following files:
//
// student.cpp
// gstudent.cpp
// example9.cpp
//

#include <conio.h>
#include "student.h"
#include "gstudent.h"

void main()
{
   clrscr();

//   Test default constructor

   Student aStudent;
   grad_Student aGradStudent;

   getch();	// so you can see the constructors
   clrscr();

   aStudent.getDetails();
   aStudent.printDetails();

   getch();
   clrscr();

   aGradStudent.getDetails();
   aGradStudent.printDetails();

   getch();
   clrscr();

// Test the initialiser constructors

   Student bStudent(1721,"Fred Bloggs",2.6,1);
   grad_Student bGradStudent(1759,"Phillip Chudley",5.50,4,"Computing",
			     "Formal Specification in Commercial Systems");

   getch();	// to see constructor calls
   clrscr();

   bStudent.printDetails();
   getch();
   clrscr();

   bGradStudent.printDetails();
   getch();
   clrscr();

// Now let's have some fun!
//
// By using pointers we can select the base class object or the derived
// object using one pointer!

// First declare two pointers

   Student *ptrStudent = &bStudent; 	// points to last student object
   grad_Student *ptrGradStudent = &bGradStudent; // points to last gstudent

// Use the pointer to send a message

   cout << "Using pointer of type Pointer to Student\n\n";

   ptrStudent->printDetails();
   getch();
   clrscr();

   cout << "Using pointer of type Pointer to grad_Student\n\n";

   ptrGradStudent->printDetails();
   getch();
   clrscr();

// Now change ptrStudent to point to a graduate Student

   ptrStudent = ptrGradStudent;

// ... and send a message. What is output?

   cout << "Using a point of type Pointer to Student, \nbut pointing "
	<< "to a Graduate student object!\n\n";

   ptrStudent->printDetails();

// or which printDetails() is used? The one in Student or the one
// in grad_Student?

    getch();
    clrscr();
}


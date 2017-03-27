// Ex12.cpp
//
// Illustrates multiple inheritance 
// Requires a project of the following files:
//
// person.cpp
// student.cpp
// staff.cpp
// staffstu.cpp
// ex12.cpp
//

#include <conio.h>
#include "student.h"
#include "staff.h"
#include "staffstu.h"

void main()
{
   clrscr();

//   Test default constructor

   Student aStudent;
   Staff   aStaff;
   StaffStudent aStaffStudent;

   getch();	// so you can see the constructors
   clrscr();

   aStudent.getDetails();
   aStudent.printDetails();

   getch();
   clrscr();

   aStaff.getDetails();
   aStaff.printDetails();

   getch();
   clrscr();

   aStaffStudent.getDetails();
   aStaffStudent.printDetails();

   getch();
   clrscr();

// Test the initialiser constructors

   Student bStudent("Fred Bloggs","Line 1","Line 2","","",
		    "02/02/66",1721,2.6,1);
   Staff bStaff("Phillip Chudley","1/F & 2/F",
		"18 Wong Chuk Shan","DD222 Lot1366","Sai Kung",
		"28/12/75",1759,"DOC","SL");
   StaffStudent bStaffStudent("Linda Fan","Room 1709",
		"Wing Hing House","Hak King Wong Estate","Tsuen Mun",
		"08/08/77", 86001,4.5,3,14532,"CS","AP","Program Development");

   getch();	// to see constructor calls
   clrscr();

   bStudent.printDetails();
   getch();
   clrscr();

   bStaff.printDetails();
   getch();
   clrscr();

   bStaffStudent.printDetails();
   getch();
   clrscr();

}


// empcont.cpp
// containership with employees and degrees
#include <iostream.h>

const int LEN = 80;           // maximum length of names


//////////////////////////////////////////////////////////////////////
//class student - no change
//////////////////////////////////////////////////////////////////////
class student                 // educational background
   {
   private:
      char school[LEN];  // name of school or university
      char degree[LEN];  // highest degree earned
   public:
      void getedu()
	 {
	 cout << "   Enter name of school or university: ";
	 cin >> school;
	 cout << "   Enter highest degree earned \n";
	 cout << "   (Highschool, Bachelor's, Master's, PhD): ";
	 cin >> degree;
	 }
      void putedu()
	 {
	 cout << "\n   School or university: " << school;
	 cout << "\n   Highest degree earned: " << degree;
	 }
   };

class employee
   {
   private:
      char name[LEN];         // employee name
      unsigned long number;   // employee number
   public:
      void getdata()
	 {
	 cout << "\n   Enter last name: "; cin >> name;
	 cout << "   Enter number: ";      cin >> number;
	 }
      void putdata()
	 {
	 cout << "\n   Name: " << name;
	 cout << "\n   Number: " << number;
	 }
   };

class manager:private employee,private student
   {
   private:
      char title[LEN];  // "vice-president" etc.
      double dues;      // golf club dues
      employee emp;     /******* change *********/
      student stu;      /******* change *********/
   public:
      void getdata()
	 {
	 emp.getdata();  /******* change *********/
	 cout << "   Enter title: ";          cin >> title;
	 cout << "   Enter golf club dues: "; cin >> dues;
	 stu.getedu();     /******* change *********/    
	 }
      void putdata()
	 {
	 emp.putdata();  /******* change *********/
	 cout << "\n   Title: " << title;
	 cout << "\n   Golf club dues: " << dues;
	 stu.putedu();  /******* change *********/
	 }
   };
class scientist         /******* change *********/
   {
   private:
      int pubs;         // number of publications
      employee emp;     /******* change *********/
      student stu;      /******* change *********/
   public:
      void getdata()
	 {
	 emp.getdata();    /******* change *********/
	 cout << "   Enter number of pubs: "; cin >> pubs;
	 stu.getedu();    /******* change *********/
	 }
      void putdata()
	 {
	 emp.putdata();   /******* change *********/
	 cout << "\n   Number of publications: " << pubs;
	 stu.putedu();    /******* change *********/
	 }
   };

class laborer        /******* change *********/
   {
   private:
      employee emp;  /******* change *********/
   public:
      void getdata()/******* change *********/
	 { emp.getdata(); }/******* change *********/
      void putdata()/******* change *********/
	 { emp.putdata(); }/******* change *********/
   };

void main()
   {
   manager m1;
   scientist s1, s2;
   laborer l1;

   cout << endl;
   cout << "\nEnter data for manager 1";    // get data for
   m1.getdata();                            // several employees

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for scientist 2";
   s2.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

   cout << "\nData on manager 1";           // display data for
   m1.putdata();                            // several employees

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on scientist 2";
   s2.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();
   }


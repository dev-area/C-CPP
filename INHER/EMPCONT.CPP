// empcont.cpp
// containership with employees and degrees
#include <iostream.h>

const int LEN = 80;           // maximum length of names

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

class manager           // management
   {
   private:
      char title[LEN];  // "vice-president" etc.
      double dues;      // golf club dues
      employee emp;     // object of class employee
      student stu;      // object of class student
   public:
      void getdata()
	 {
	 emp.getdata();
	 cout << "   Enter title: ";          cin >> title;
	 cout << "   Enter golf club dues: "; cin >> dues;
	 stu.getedu();
	 }
      void putdata()
	 {
	 emp.putdata();
	 cout << "\n   Title: " << title;
	 cout << "\n   Golf club dues: " << dues;
	 stu.putedu();
	 }
   };
class scientist         // scientist
   {
   private:
      int pubs;         // number of publications
      employee emp;     // object of class employee
      student stu;      // object of class student
   public:
      void getdata()
	 {
	 emp.getdata();
	 cout << "   Enter number of pubs: "; cin >> pubs;
	 stu.getedu();
	 }
      void putdata()
	 {
	 emp.putdata();
	 cout << "\n   Number of publications: " << pubs;
	 stu.putedu();
	 }
   };

class laborer        // laborer
   {
   private:
      employee emp;  // object of class employee
   public:
      void getdata()
	 { emp.getdata(); }
      void putdata()
	 { emp.putdata(); }
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


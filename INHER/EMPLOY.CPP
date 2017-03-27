// employ.cpp
// models employee database using inheritance
#include <iostream.h>

const int LEN = 80;           // maximum length of names

class employee                // employee class
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

class manager : public employee     // management class
   {
   private:
      char title[LEN];  // "vice-president" etc.
      double dues;      // golf club dues
   public:
      void getdata()
	 {
         employee::getdata();
	 cout << "   Enter title: ";          cin >> title;
	 cout << "   Enter golf club dues: "; cin >> dues;
	 }
      void putdata()
	 {
	 employee::putdata();
	 cout << "\n   Title: " << title;
	 cout << "\n   Golf club dues: " << dues;
	 }
   };
class scientist : public employee      // scientist class
   {
   private:
      int pubs;     // number of publications
   public:
      void getdata()
	 {
	 employee::getdata();
	 cout << "   Enter number of pubs: "; cin >> pubs;
	 }
      void putdata()
	 {
	 employee::putdata();
	 cout << "\n   Number of publications: " << pubs;
	 }
   };

class laborer : public employee        // laborer class
   {
   };

void main()
   {
   manager m1, m2;
   scientist s1;
   laborer l1;

   cout << endl;
   cout << "\nEnter data for manager 1";    // get data for
   m1.getdata();                            // several employees

   cout << "\nEnter data for manager 2";
   m2.getdata();

   cout << "\nEnter data for scientist 1";
   s1.getdata();

   cout << "\nEnter data for laborer 1";
   l1.getdata();

   cout << "\nData on manager 1";           // display data for
   m1.putdata();                            // several employees

   cout << "\nData on manager 2";
   m2.putdata();

   cout << "\nData on scientist 1";
   s1.putdata();

   cout << "\nData on laborer 1";
   l1.putdata();
   }


//      contact5.cpp
//
//      implementation of contact class methods with static class members
//      constructors and destructors and pointers as data members

#include "contact5.h"

//	MUST have this line to initialise static data member

char	Contact::IDDCode[4] = "852";	// all contacts have IDD code for Hong Kong

//	Constructors

Contact::Contact()
{
	cout << "Contact default constructor ... \n";
	setName("");
	setAddress1("");
	setAddress2("");
	setAddress3("");
	setDistrict("");
	setPhone("");
	setFax("");

//	Allocate age in Dynamic Memory

	int *initPtr = new int;
	age = initPtr;
	setAge(0);	// represents no age set
}

Contact::Contact(char *inName,char *inAddr1,char *inAddr2,
		 char *inAddr3,char *inDistr,char* inPhone,
		 char *inFax, int inAge)
{
	cout << "Contact other constructor ... \n";
	setName(inName);
	setAddress1(inAddr1);
	setAddress2(inAddr2);
	setAddress3(inAddr3);
	setDistrict(inDistr);
	setPhone(inPhone);
	setFax(inFax);

//	Allocate age in Dynamic Memory

	int *initPtr = new int;
	age = initPtr;
	setAge(inAge);
}

//	Destructor

Contact::~Contact()
{
	cout << "Contact destructor called ... \n";
//
//	A common use of a destructor is to put debug output here
//	or to deallocate memory dynamically allocated in a construtor
//

//	Deallocate pointer to age;
}

void Contact::getContactDetails() {

//
//      Class function to read and the attributes of the class
//
	char buffer[255];
	int  inAge;

//
//      Prompt for, and read data for class. No validation!

	cout << "\nEnter the contact's name (max "
	     << NAMELEN << " characters) :\n";
	cin.get(buffer, NAMELEN);
	cin.ignore(255, '\n');
	setName(buffer);
	cout << "Enter the first line of the contact's address (max "
	     << ADDRLEN << " characters) :\n";
	cin.get(buffer, ADDRLEN);
	cin.ignore(255, '\n');
	setAddress1(buffer);
	cout << "Enter the second line of the contact's address (max "
	     << ADDRLEN << " characters) :\n";
	cin.get(buffer,ADDRLEN);
	cin.ignore(255, '\n');
	setAddress2(buffer);
	cout << "Enter the third line of the contact's address (max "
	     << ADDRLEN << " characters) :\n";
	cin.get(buffer, ADDRLEN);
	cin.ignore(255, '\n');
	setAddress3(buffer);
	cout << "Enter the district of the contact's address (max "
	     << ADDRLEN << " characters) :\n";
	cin.get(buffer, ADDRLEN);
	cin.ignore(255, '\n');
	setDistrict(buffer);
	cout << "Enter the contact's telephone number (max "
	     << PHONELEN << " characters) :\n";
	cin.get(buffer, PHONELEN);
	cin.ignore(255, '\n');
	setPhone(buffer);
	cout << "Enter the contact's fax number (max "
	     << PHONELEN << " characters) :\n";
	cin.get(buffer, PHONELEN);
	cin.ignore(255, '\n');
	setFax(buffer);
	cout << "Enter the contact's age ";
	cin >> inAge;
	setAge(inAge);
	cin.ignore(255, '\n');
	cout << "\n\n";
}

void Contact::displayContactDetails() {

//
//      class function to read the values of the attributes and
//      display the values. Does not ignore null length strings
//
	cout << "\n" << getName();
	cout << "\n" << getAddress1();
	cout << "\n" << getAddress2();
	cout << "\n" << getAddress3();
	cout << "\n" << getDistrict();
	cout << "\n\nTelephone : (+" << getIDDCode() << ") " << getPhone();
	cout << "\nFax       : (+" << getIDDCode() << ") "  << getFax();
//
//	Check for null pointer
//
	if (!getAge())
	   cout << "\nNo age has been set for this contact";
	else
	   cout << "\nAge : " << getAge();
	cout << "\n\n";
}



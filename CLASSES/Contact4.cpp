//      contact4.cpp
//
//      implementation of contact class methods with static class members
//      constructors and destructors

#include "contact4.h"

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
}

Contact::Contact(char *inName,char *inAddr1,char *inAddr2,
		 char *inAddr3,char *inDistr,char* inPhone,
		 char *inFax)
{
	cout << "Contact other constructor ... \n";
	setName(inName);
	setAddress1(inAddr1);
	setAddress2(inAddr2);
	setAddress3(inAddr3);
	setDistrict(inDistr);
	setPhone(inPhone);
	setFax(inFax);
}

//	Destructor

Contact::~Contact()
{
	cout << "Contact destructor called ... \n";
//
//	A common use of a destructor is to put debug output here
//	or to deallocate memory dynamically allocated in a construtor
//
}

void Contact::getContactDetails() {

//
//      Class function to read and the attributes of the class
//
	char buffer[255];

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
	cout << "\n\n";
}

//	Note this function is NOT part of the Contact class
//	but, as a friend has access to the private members of
//	the Contact class

ostream &operator << (ostream &os, Contact &aContact)
{
	return os << "\n" << aContact.name
		  << "\n" << aContact.address1
		  << "\n" << aContact.address2
		  << "\n" << aContact.address3
		  << "\n" << aContact.district
		  << "\n\nTelephone : (+" << Contact::IDDCode << ") "
		  << aContact.phone
		  << "\nFax       : (+" << Contact::IDDCode << ") "
		  << aContact.fax
		  << "\n\n";
}
//	Supplier.cpp
//
//	Class implementation file for supplier
//

#include "supplier.h"

//	Constructor for supplier name and contact name only
//	Uses initialiser list for initialising contact name

Supplier::Supplier(char *inSupplierName, char *inContactName)
	 : theContact(inContactName,"","","","","","")
{
	setSupplierName(inSupplierName);
	cout << "Supplier constructed with supplier and contact name\n";
}

//	Constructor for supplier name and exisiting contact object
//	Uses initialiser lists for initialising contact

Supplier::Supplier(char *inSupplierName, const Contact &inContact)
	 : theContact(inContact)  // copy constructor supplied by complier
{
	setSupplierName(inSupplierName);
	cout << "Supplier constructed with supplier and contact object\n";
}

//	Destructor

Supplier::~Supplier()
{
	cout << "Supplier destroyed\n";
}

//	Access method

void	Supplier::displaySupplierDetails()
{
	cout << "Supplier Name\n"
	     << "=============\n"
	     << getSupplierName() << "\n\n";
	cout << "Contact Details\n"
	     << "===============\n";
	theContact.displayContactDetails();
}



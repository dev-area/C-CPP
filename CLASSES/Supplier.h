//	Supplier.h
//
//	Class header file for supplier
//

#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <iostream.h>
#include <string.h>
#include "contact3.h"

const	SUPPLIERNAMELEN = 20;

class	Supplier {
public:
//	Constructors

	Supplier(char *inSupplierName, char *inContactName);
	// construct using supplier and contact names only

	Supplier(char *inSupplierName, const Contact &inContact);
	// construct using supplier name and an exisitng contact object
	// const prevents modification, and call by reference for
	// efficiency

//	Destructor

	~Supplier();

//	Access methods

	void setSupplierName(char *inSupplierName)
	     { strcpy(supplierName, inSupplierName);}
	char *getSupplierName() { return supplierName;}
	const Contact &getSupplierContact() { return theContact;}

	// const since it prevents the caller changing the contained
	// object theContact

	void displaySupplierDetails();

private:
	char supplierName[SUPPLIERNAMELEN];
	Contact theContact;	// contact object;
};

#endif



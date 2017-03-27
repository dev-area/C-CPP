//      contact2.h
//
//      class header file for contacts
//

#ifndef CONTACT2_H
#define CONTACT2_H

#include <iostream.h>	// for cin & cout in implementor functions
#include <string.h>


const   NAMELEN = 25;   // max length of name
const   ADDRLEN = 40;   // max length of each line of address
const   PHONELEN = 10;  // max length of phone and fax numbers

class   Contact {
public:

//      access methods : inline functions

	void setName(char initName[])
	   {strcpy(name, initName);}
	void setAddress1(char initAddr1[]) 
           {strcpy(address1, initAddr1);}
	void setAddress2(char initAddr2[]) 
           {strcpy(address2, initAddr2);}
	void setAddress3(char initAddr3[]) 
           {strcpy(address3, initAddr3);}
	void setDistrict(char initDistr[]) 
           {strcpy(district, initDistr);}
	void setPhone(char initPhone[])    
           {strcpy(phone, initPhone);}
	void setFax(char initFax[])        
           {strcpy(fax, initFax);}

	static void setIDDCode(char initIDD[])
		  {strcpy(IDDCode, initIDD);}	// access static data members with
						// static member functions

	char *getName()       {return name;}
	char *getAddress1()   {return address1;}
	char *getAddress2()   {return address2;}
	char *getAddress3()   {return address3;}
	char *getDistrict()   {return district;}
	char *getPhone()      {return phone;}
	char *getFax()        {return fax;}

	static char *getIDDCode()  {return IDDCode;}

//      Implementor methods : function prototypes

	void getContactDetails();
	void displayContactDetails();

private:
	char name[NAMELEN];     // name of contact
	char address1[ADDRLEN]; // first line of address
	char address2[ADDRLEN]; // second line of address
	char address3[ADDRLEN]; // third line of address
	char district[ADDRLEN]; // district of address
	char phone[PHONELEN];   // phone number of contact
	char fax[PHONELEN];     // fax number of contact

	static char IDDCode[4];	// international IDD code for all contacts

};

#endif

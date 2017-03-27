//	cfile.cpp
//
//	Implementation of cfile class
//
//	Uses variable length records where each field (except the last)
//	is terminated by a delimiter character. The character used for
//	this is held in a constant. Remember constants have internal
//	linkage and so this cannot be seen outside this file. This allows
//	enforcement of the information hiding principle.
//

#include "cfile.h"

//	Access functions

void ContactFile::readContactRecord(Contact &inContact)

//	Reads contact details from one line of the file and stores
//	then in the contact object referenced by inContact.
//
//	As the file was originally written by writeContactRecord()
//	we know that each field will fit into its respective inContact
//	data member. This saves us checking the length of each string
//	read from the file.

{
	char ch;		// for skipping each delimiter
	char buffer[256];	// for storing each string read from file

//	the constants for the length of the data members are in scope
//	due to the #include "cfile.h" which includes contact3.h

	theFile.get(buffer, NAMELEN, '*');
	inContact.setName(buffer);
	theFile.get(ch);	// skip the delimiter

	theFile.get(buffer, ADDRLEN, '*');
	inContact.setAddress1(buffer);
	theFile.get(ch);	// skip the delimiter

	theFile.get(buffer, ADDRLEN, '*');
	inContact.setAddress2(buffer);
	theFile.get(ch);	// skip the delimiter

	theFile.get(buffer, ADDRLEN, '*');
	inContact.setAddress3(buffer);
	theFile.get(ch);	// skip the delimiter

	theFile.get(buffer, ADDRLEN, '*');
	inContact.setDistrict(buffer);
	theFile.get(ch);	// skip the delimiter

	theFile.get(buffer, PHONELEN, '*');
	inContact.setPhone(buffer);
	theFile.get(ch);	// skip the delimiter

//	last field has newline as delimiter

	theFile.get(buffer, PHONELEN, '\n');
	inContact.setFax(buffer);
	theFile.get(ch);	// skip the newline

	}

void ContactFile::writeContactRecord(Contact &outContact)

//	Writes details of a contact referenced by outContact to a
//	single line in the text file. Each data member is delimited
//	by the character '*' except the last which is
//	delimited by a newline.
//
//	Note we do not output the IDDCode data member since this is
//	defined to be static and hence is the same for all contacts
//

{
	theFile << outContact.getName() << "*"
		<< outContact.getAddress1() << "*"
		<< outContact.getAddress2() << "*"
		<< outContact.getAddress3() << "*"
		<< outContact.getDistrict() << "*"
		<< outContact.getPhone() << "*"
		<< outContact.getFax() << '\n';
}

//      Manipulator functions

int ContactFile::openFileRead()

//	Opens the file for reading only.
//	Returns 1 for success 0 for failure

{
	theFile.open(fileName, ios::in);
	if (!theFile)
	  return 0;	// failure
	return 1;	// success
}

int ContactFile::openFileWrite()

//	Opens the file for writing only.
//	Returns 1 for success 0 for failure

{
	theFile.open(fileName, ios::out);
	if (!theFile) return 0;	// failure
	return 1;		// success
}

int ContactFile::closeFile()

//	Closes the file.
//	Returns 1 for success 0 for failure

{
	theFile.close();
	if (!theFile) return 0;	// failure
	return 1;		// success
}

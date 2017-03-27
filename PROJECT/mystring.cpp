/*
===========================================================================
File Name	:MyString.cpp
Project		:Films Lib
File Type	:Source Code
Last Updated:1.4.98
Portability	:C++
===========================================================================
Contains:

	All the Class String implementations 	

*/

#include "mystring.h"
#include "userint.h"

String& String::operator =(const String& right)
{
	if (this == &right)
		return *this;
	(void) strcpy(str,right.str);
	return *this;
}

String operator +(const String& left,const String& right)
{
	String result = left;
	result += right;
	return result;
}




void String::read_pi(char* mes)  // Function to read a positive number as string
								 // (using the two function below)
{
	while(1){
		read_int(mes);
		if ( (int)str > 0) return;
		cout << "Value should be a positive number\n";
	}
}

void String::read_int(char* mes)
{
	while(1){
		*this = (DialogBox(mes));
		if ( is_num() )
			return;
		cout << "Request should be a number\n";
	}
}


bool String::is_num() const
{
	for ( const char* s = str; *s!= '\0' ; s++)
		if (!isdigit(*s)) return false;
	return true;
}

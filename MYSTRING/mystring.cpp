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
	delete [] str;
	str = new char[strlen(right.str) +1];
	(void) strcpy(str,right.str);
	return *this;
}

String operator +(const String& left,const String& right)
{
	String result;
	delete []result.str;
	result.str = new char [strlen(left.str) + strlen(right.str)+1];
	(void) strcpy(result.str,left.str);
	(void) strcat(result.str,right.str);
	return result;
}





/*
===========================================================================
File Name	:MyString.h
Project		:Films Lib
File Type	:Header File
Last Updated:1.4.98
Portability	:C++
===========================================================================
Contains:

		The Class String (for Text using)
						

*/


#ifndef STRING
#define STRING

#include <string.h>
#include <iostream.h>
#include <stdlib.h>
#include <ctype.h>

class String{
	enum {size=256};
	char* str;
public:
	String (char *s=""):str(strcpy(new char[strlen(s)+1],s)) {}
	String (const String& s) : str(strcpy(new char[strlen(s.str)+1],s.str))
	{}
	String& operator=(const String&);
	friend String operator +(const String& s1,const String& s2);
	String& operator += (const String&);
	friend bool operator==(const String& s1,const String& s2);
	friend bool operator>(const String& s1,const String& s2);
	friend bool operator<(const String& s1,const String& s2);
	friend bool operator>=(const String& s1,const String& s2);
	friend bool operator<=(const String& s1,const String& s2);
	friend bool operator!=(const String& s1,const String& s2);
	friend ostream& operator<<(ostream& out,const String& s1);
	friend istream& operator>>(istream& in,String& s1);
	operator int() const { return atoi(str); }
	operator double () const {return atof(str); }
	~String() { delete []str;}
};

inline String& String::operator+= (const String& s1)
{
	return (*this = *this + s1);
}

inline bool operator <= (const String& left,const String& right)
{
	return strcmp(left.str,right.str) <= 0;
}

inline bool operator == (const String& left,const String& right)
{
	return left <= right && right<=left ;
}


inline bool operator != (const String& left,const String& right)
{
	return ! (left == right);
}

inline bool operator >= (const String& left,const String& right)
{
	return right <= left;
}

inline bool operator < (const String& left,const String& right)
{
	return left <= right && left != right;
}

inline bool operator > (const String& left,const String& right)
{
	return right < left ;
}


inline ostream& operator<<(ostream& out,const String& s1)
{
	return out << s1.str;
}

inline istream& operator>>(istream& in,String& s1)
{	
	char buffer[String::size];
	in >> buffer;
	s1 = buffer;
	return in;

}

#endif


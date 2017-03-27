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
		the class contains all the operator overloadings you'll need
			

*/


#ifndef STRING
#define STRING

#include <string.h>
#include <iostream.h>
#include <stdlib.h>
#include <ctype.h>

class String{
	enum {size=32};
	char str[size];
public:
	String (char *s="") {strncpy(str,s,size-1);}
	String (const String& s) {strcpy(str,s.str);}
	String& operator=(const String&);
	String& operator += (const String&);
	friend bool operator<=(const String& s1,const String& s2);
	friend ostream& operator<<(ostream& out,const String& s1);
	friend istream& operator>>(istream& in,String& s1);
	operator int() const { return atoi(str); }
	operator double () const {return atof(str); }
	void read_pi(char *);
	void read_int(char *);
	bool is_num() const;
};

inline String& String::operator+= (const String& s1)
{
	String result;
	(void) strcat(str,s1.str);
	return *this;
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
	char buf[String::size];
	in >> buf;
	s1 = buf;
	return in;
}
String operator +(const String& left,const String& right);
#endif


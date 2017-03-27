// String.C - String class implementation, lvalue/rvalue for substrings
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

String::String(int size) {							// private constructor
	len = size; s = new char[len+1];
	s[len] = '\0'; 
}

String::String(const char *p) { 					// char string constructor
	len = strlen(p);  s = new char[len+1];  
	strcpy(s, p);
}

void String::copy(const String & s1) { 
	s = new char[(len = s1.len) + 1];
	strcpy(s, s1.s);								// copy String data 
}

void String::free() {
	delete [] s;									// free String data
}

String operator+(const String & s1, const String & s2) {
	String result(s1);							// copy constructor
	result += s2;									// call operator+=()
	return result;									// return result by value
}

String operator-(const String & s1, const String & s2) {
	String result(s1);							// copy constructor
	result -= s2;									// call operator-()=
	return result;									// return result by value
}

String operator-(const char * s1, const String & s2) {
	return static_cast<String>(s1) - s2;
}

String operator-(const String & s1, const char * s2) {
	return s1 - static_cast<String>(s2);
}

String operator+(const char * s1, const String & s2) {
	return static_cast<String>(s1) + s2;
}

String operator+(const String & s1, const char * s2) {
	return s1 + static_cast<String>(s2);
}

String & String::operator+=(const String & s1) { 
	int newlen = len + s1.len;						// new length
	char *newp = new char [newlen + 1];			// allocate new memory
	strcpy(newp, s);						// copy first String to memory
	strcpy(newp + len, s1.s);			// copy second String after first
	free();									// free old memory
	s = newp;								// reassign pointer to new memory
	len = newlen;							// set new length 
	return *this;							// return updated String
}

String & String::operator-=(const String & s1) {
	int newlen = len + s1.len + 1;				// new length plus blank
	char *newp = new char [newlen + 1];			// allocate new memory
	strcpy(newp, s);						// copy first String to memory
	newp[len] = ' ';						// put in blank
	strcpy(newp + len + 1, s1.s);		// copy second String after blank
	free();									// free old memory
	s = newp;								// reassign pointer to new memory
	len = newlen;							// set new length 
	return *this;							// return updated String
}

void String::range(int index) const {
	if (index < 0 || index >= length())			// out of bounds?
		throw StringError(index);					// range error
}

char & String::operator[](int index) { 
	range(index);							// range check 
	return s[index];						// return character reference
}

const char & String::operator[](int index) const {
	range(index);							// range check 
	return s[index];						// return const character reference
}

ostream & operator<<(ostream & os, const String & s1) {
	return os << static_cast<const char *>(s1);
}

istream & operator>>(istream & is, String & s1) {
	const int bufmax = 256;						// maximum length
	static char buffer[bufmax];				// array buffer
	is.getline(buffer, bufmax);				// input into buffer
	s1 = buffer;									// String assignment
	return is;										// return istream
}

String & SubString::operator=(const String & s1) {					// lvalue
	int len = (s1.length() < count) ? s1.length() : count;
	strncpy(str.s + pos, s1.s, len);
	return str;
}

String & SubString::operator=(const SubString & s1) {				// lvalue
	int len = (s1.count < count) ? s1.count : count;
	strncpy(str.s + pos, s1.str.s + s1.pos, len);
	return str;
}

SubString::operator String () const {					// rvalue
	String result(count);									// private String constructor
	strncpy(result.s, str.s + pos, count);
	return result;
}

void String::poscount(int pos, int count) const {
	if (pos < 0 || pos > length() - 1 || 
			count <= 0 || count + pos > length())
		throw StringError(pos, count, *this);
}

SubString String::operator()(int pos, int count) {			// Substrings
	poscount(pos, count);									// check position, count
	return SubString(*this, pos, count);				// create SubString
}

const String String::operator()(int pos, int count) const {			// Substrings
	poscount(pos, count);						// check position, count
	String snew(count);							// private String constructor
	strncpy(snew.s, s + pos, count);			// copy substrinig
	return snew;									// return const substring value
}

bool operator==(const String & s1, const String & s2) { 
	return strcmp(s1, s2) == 0; 
}
bool operator==(const char *s1, const String & s2) { 
	return strcmp(s1, s2) == 0; 
}
bool operator==(const String & s1, const char *s2) { 
	return strcmp(s1, s2) == 0; 
}
bool operator!=(const String & s1, const String & s2) { 
	return strcmp(s1, s2) != 0; 
}
bool operator!=(const char *s1, const String & s2) { 
	return strcmp(s1, s2) != 0; 
}
bool operator!=(const String & s1, const char *s2) { 
	return strcmp(s1, s2) != 0; 
}
bool operator>(const String & s1, const String & s2) { 
	return strcmp(s1, s2) > 0; 
}
bool operator>(const char *s1, const String & s2) { 
	return strcmp(s1, s2) > 0; 
}
bool operator>(const String & s1, const char *s2) { 
	return strcmp(s1, s2) > 0; 
}
bool operator>=(const String & s1, const String & s2) { 
	return strcmp(s1, s2) >= 0; 
}
bool operator>=(const char *s1, const String & s2) { 
	return strcmp(s1, s2) >= 0; 
}
bool operator>=(const String & s1, const char *s2) { 
	return strcmp(s1, s2) >= 0; 
}
bool operator<(const String & s1, const String & s2) { 
	return strcmp(s1, s2) < 0; 
}
bool operator<(const char *s1, const String & s2) { 
	return strcmp(s1, s2) < 0; 
}
bool operator<(const String & s1, const char *s2) { 
	return strcmp(s1, s2) < 0; 
}
bool operator<=(const String & s1, const String & s2) { 
	return strcmp(s1, s2) <= 0; 
}
bool operator<=(const char *s1, const String & s2) { 
	return strcmp(s1, s2) <= 0; 
}
bool operator<=(const String & s1, const char *s2) { 
	return strcmp(s1, s2) <= 0; 
}

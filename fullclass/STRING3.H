#ifndef STRINGH
#define STRINGH
// String2.h - String class interface, lv/rv substrings, friends
#include <iostream.h>
#include <stdio.h>
#include <string.h>

class String {		// String class
private:
	char *s;
	int len;
	void copy(const String &);
	void free();
	String(int);		// private constructor
	void range(int) const;	// subscript range check
	enum join { join_op };	// join operation
	enum joinb { joinb_op };// join with blank operation
	String(const String & s1, const String & s2, join) {	// s1 + s2
		s = new char [(len = s1.len + s2.len) + 1];  
		strcpy(s, s1.s);
		strcpy(s + s1.len, s2.s);
	}
	String(const String & s1, const String & s2, joinb) {	// s1 - s2
		s = new char [(len = s1.len + s2.len + 1) + 1];  
		strcpy(s, s1.s);
		s[s1.len] = ' ';										// insert blank
		strcpy(s + s1.len + 1, s2.s);
	}
public:
// Constructors
	String(const char * = "");		// char string constructor
	String(const String & a) { copy(a); }	// copy constructor
// Destructor
	~String() { free(); }
// Modifiers
	String & operator=(const String & a) {	// assignment
		if (this != &a) {
			free();  
			copy(a); 
		}
		return *this;
	}
	String & operator+=(const String &);	// concatenation
	String & operator-=(const String &);	// concatenate with ' '
	char & operator[](int);			// non-const subscripts
// Selectors
	const char & operator[](int) const;	// const subscripts
	const String operator()(int, int) const;// substrings
	operator const char * () const { return s; }	// conversion
	int length() const { return len; }
// Friends
	friend String operator+(const String & s1, const String & s2) {
		return String(s1, s2, s1.join_op);
	}
	friend String operator-(const String & s1, const String & s2) {
		return String(s1, s2, s1.joinb_op);
	}
};


ostream & operator<<(ostream &, const String &);
istream & operator>>(istream &, String &);

String operator+(const String &, const String &);
String operator+(const char *, const String &);
String operator+(const String &, const char *);
String operator-(const String &, const String &);
String operator-(const char *, const String &);
String operator-(const String &, const char *);

bool operator==(const String & s1, const String & s2);
bool operator==(const char *s1, const String & s2); 
bool operator==(const String & s1, const char *s2);
bool operator!=(const String & s1, const String & s2);
bool operator!=(const char *s1, const String & s2);
bool operator!=(const String & s1, const char *s2);
bool operator>(const String & s1, const String & s2);
bool operator>(const char *s1, const String & s2);
bool operator>(const String & s1, const char *s2);
bool operator>=(const String & s1, const String & s2);
bool operator>=(const char *s1, const String & s2);
bool operator>=(const String & s1, const char *s2);
bool operator<(const String & s1, const String & s2);
bool operator<(const char *s1, const String & s2);
bool operator<(const String & s1, const char *s2);
bool operator<=(const String & s1, const String & s2);
bool operator<=(const char *s1, const String & s2);
bool operator<=(const String & s1, const char *s2);
#endif

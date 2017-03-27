/*
===========================================================================
File Name	:UserInt.h
Project		:Films Lib
File Type	:Header File
Last Updated:1.4.98
Portability	:C++
===========================================================================
		
*/


#ifndef USERINT
#define USERINT

#include "mystring.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h>

#define SIZEOF(array) (sizeof(array) / sizeof(array[0]))

typedef void (*functionPtr)(); // a pointer to a void function

struct MenuEntry {
	char* str;
	functionPtr CallMethod;
};

class Menu {
	MenuEntry* entries;
	int nEntries;
	String name;
public:
	Menu(MenuEntry* ent,String na,int num):entries(ent),name(na),nEntries(num)
	{}
	void selection();
};


// fuction diplay the request and get a value for String.str field

inline String DialogBox(char* request)
{
	cout << request << endl;
	String input;
	cin >> input;
	return input;
}


// functions for sub menus

void customer_menu();
void film_menu();
void query_menu();


// fuction that should operate the library options

void add_customer();
void rm_customer();
void show_customer();
void print_customers();

void add_film();
void rm_film();
void show_film();
void print_films();
void add_film_copies();

void add_borrow();
void remove_borrow();
void show_cust_film();
void show_film_cust();
void print_borrows();

#endif

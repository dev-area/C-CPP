/*
===========================================================================
File Name	:User.cpp
Project		:Films Lib
File Type	:Source Code
Last Updated:1.4.98
Portability	:C++
===========================================================================
Contains:
	
	  The  "" user interface "" ...
		classes and functions to deal with the user and
		startup all the operations of the projrct

		
*/

#include <iostream.h>
#include "mystring.h"
#include "userint.h"

bool quit_program;
bool quit_menu;


// defenitions of all the menus object


MenuEntry CustomerMenu[] = { "Add a new customer"      ,&add_customer,
							 "Remove customer"         ,&rm_customer,
							 "Print customer's details",&show_customer,
						     "Customers list"          ,&print_customers
							};
MenuEntry FilmsMenu[] = { "Add a new film"             ,&add_film,
						  "Remove a film"              ,&rm_film,
						  "Print film's details"       ,&show_film,
						  "Films list"				   ,&print_films
						};

MenuEntry QueryMenu[]={"Customer's borrowed film"      ,&show_cust_film,
                       "Who borrowed the film"         ,&show_film_cust,
					   "Print borrowed films"          ,&print_borrows
						};


MenuEntry MainMenu[]={"Costumers Options" , &customer_menu,
					  "Films Options"     , &film_menu,
					  "Queries"	          , &query_menu
						};




void Menu::selection()  //Display the enteries of each menu
{
	quit_menu=false;
	int i;
	while (!(quit_menu)&&(!quit_program)){
		cout << name << endl;
		for(i=0;i<nEntries;i++) 
			cout << i+1 << " " << entries[i].str << endl;
		cout << "p " << "go to Parent menu" << endl;
		while(1){
			String choice;
			cin >> choice;
			if (choice == "q") {quit_program = true;break;}
			if (choice == "p") {quit_menu = true;break;}
			if ( choice.is_num()&& ((i=choice) > 0 ) && (i<=nEntries)){
				(*(entries[i-1].CallMethod))();
				 break;
			}
			cout << "Pleas, enter p , q or number of entry" << endl;
		}
	}
}


Menu cust(CustomerMenu,"Customet Menu",SIZEOF(CustomerMenu));
Menu film(FilmsMenu,"Films Menu",SIZEOF(FilmsMenu));
Menu query(QueryMenu,"Queries Menu",SIZEOF(QueryMenu));
Menu mainMenu(MainMenu,"Main Menu",SIZEOF(MainMenu));


// function for sub menus

void customer_menu() 
{
	cust.selection();
}

void film_menu() 
{
	film.selection();
}

void query_menu() 
{
	query.selection();
}


// all the function to deal with the library

void add_customer()
{
	String s;
	s.read_pi("Enter Cutomer id num:");
	
	cout << "invoke : add_customer for customer "<< (int)s << endl;
}

void rm_customer()
{
	cout << "invoke : remove customer\n";

}

void show_customer()
{
	cout << "invoke : show customer details\n";

}

void print_customers()
{
	cout << "invoke : show customers list\n";

}

void add_film()
{
	cout << "invoke : add film\n";

}

void rm_film()
{
	cout << "invoke : remove film\n";

}

void show_film()
{
	cout << "invoke : print film details\n";

}

void print_films()
{
	cout << "invoke : print films list\n";

}

void show_cust_film()
{
	cout << "invoke : print films that customer borrowed\n";

}

void show_film_cust()
{
	cout << "invoke : show how is got the film\n";

}

void print_borrows()
{
	cout << "invoke : show borrow list\n";

}


main()
{
	quit_program = false;
	while(!quit_program) mainMenu.selection();
	return 0;
}

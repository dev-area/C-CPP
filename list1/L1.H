#ifndef LISTMAIN
#define LISTMAIN

#include "list.h"
#include "mystring.h"
#include <iostream.h>
#include <stdlib.h>

class Car{
	String name;
	int eng;
	int price;
public:
	Car(String s="",int e=0,int p=0):name(s),eng(e),price(p){}

	friend ostream& operator<<(ostream& out,const Car& c)
	{
		return out << "Car Name: "<< c.name << endl <<
			"Eng : " << c.eng << " cc" << endl <<
			"Value : " << c.price << " nis."<< endl;
	}
	String get_name() {return name;}
};

class Student{
	int id;
	String name;
public:
	Student(int i=0,String str=""):id(i),name(str) { }
	Student(istream& std);
	friend ostream& operator<<(ostream& out,const Student& st)
	{
		return out << "Student id : " << st.id << endl <<
				      "Student name : " << st.name <<endl;
	}
	int get_id() {return id;}
};

#endif
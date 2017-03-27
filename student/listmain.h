
#ifndef LISTMAIN
#define LISTMAIN

#include "list.h"
#include "mystring.h"

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>


#define STUDENTSFILE "students.dat"


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



class StudentList {
public:
	bool add_student();
	bool remove_student();
	Student* find_student(int &sid);
	friend ostream& operator<<(ostream& output,const StudentList& sl);
	StudentList (ifstream& std);
	~StudentList ();
private:

	List<Student*,int>  students;

};






#endif
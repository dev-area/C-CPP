#include "listmain.h"

StudentList::StudentList(ifstream& std)
{
	Student* stp;
	while(std){
		stp = new Student;
		std.read( (char*)stp,sizeof(Student));
		if (std.good())
			students.add_data(stp->get_id(),stp);
	}
	std.close();
}


bool StudentList::add_student()
{
		int id;
		String name;
		Student* stp;
		cout << "Enter student id and name\n";
		cin >> id;
		cin >> name;
		stp = new Student(id,name);
		return (students.add_data(id,stp));
}


bool StudentList::remove_student()
{
	int i;
	Student* stp;
	
	cout << "Enter id :\n";
	cin >> i;
	if(students.get_data(i,stp)){
		cout <<"Data for students with id" << i << ": \n"<< *stp << "\n\n";
		students.remove_data(i);
		return true;
	}
	else
		cout <<"No such a student !\n";
	return false;
}


ostream& operator<<(ostream& output,const StudentList& sl)
{
	return (output << sl.students);
}


StudentList::~StudentList()
{
	ofstream students_file(STUDENTSFILE);
	for(List<Student*,int>::ConstIterator it(students); it ; it++){
			students_file.write( (const char*)(*it),sizeof(Student));
			delete (*it);
	}
	students_file.close();
}


main()

{
	/* Define the following lists: 
								   students - Data : Student object (Student)
											  Key  : student's id (int)

  */

	int j;

	ifstream students_file(STUDENTSFILE);
	StudentList my_students(students_file);

	cout << "Please enter 3 new students\n";
	for(j=1;j<=3;j++)
		if(!my_students.add_student())
			cout << "Student is already exists !\n";
	my_students.remove_student();



	// print the lists to the screen


	cout << my_students;


	return 0;
}

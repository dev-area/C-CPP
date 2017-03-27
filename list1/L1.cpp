
#include "l1.h"

main()

{
	/* Define the following lists: cars	     - Data : Car object (Car)
															 Key : car's name (String)
								   		 students -  Data : Student object (Student)
                                   				 Key  : student's id (int)



  */
	List<Student*,int>  students;
	List<Car*,String> cars;

	int j,value,eng,id;
	String  name;
	Car* carp;
	Student* stp;

	//Read ne data for the two lists

	cout << "Please enter 3 new cars\n";
	for(j=1;j<=3;j++){
	   cout << "Enter: car's name eng and prise\n";
		cin >> name;
		cin >> eng;
		cin >> value;
		carp = new Car(name,eng,value);
		cars.add_data(name,carp);
	}

	cout << "Please enter 3 new students\n";
	for(j=1;j<=3;j++){
		cout << "Enter student id and name\n";
		cin >> id;
		cin >> name;
		stp = new Student(id,name);
		students.add_data(id,stp);
	}

	cout << "Removing stuendts with id : 2\n";
	students.remove_data(2);

	if(students.get_data(2,stp))
		cout <<"Data for students with id 2: \n"<< *stp << "\n\n";
	else
		cout <<"No such a student !\n";


   cout << cars;
	cout << students;

   for(List<Student*,int>::ConstIterator it1(students); it1 ; it1++)
		 delete(*it1);

   for(List<Car*,String>::ConstIterator it2(cars); it2 ; it2++)
		 delete(*it2);


	return 0;
}


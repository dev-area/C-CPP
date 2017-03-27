// square.C - const data members, assignment
#include <iostream.h>

class Square {
private:
	const double side;
	const double areav;
	const double perim;
public:
	Square(double s = 1) : side(s), areav(s * s), perim(4 * s) { }
	double area() const { return areav; }
	double perimeter() const { return perim; }
};

int main()
{
	Square s1(10);
	cout << s1.area() << endl;
	cout << s1.perimeter() << endl;
	Square s2 = s1;							// compiles side = 10
	Square s3;									// side = 1
	//s3 = s1;										// illegal
	return 0;
}

/**********************************************************************

$ square 
100
40

*/

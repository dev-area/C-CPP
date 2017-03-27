// circle.cpp
// Implementation file for Circle class

#include "circle.h"

// Default constructor, uses default constructor of base class

Circle::Circle()
{
   cout << "Circle default constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Initialiser constructor, uses initialiser constructor of base class			//Constructor with arguments

Circle::Circle(shapeColour inColour, Point &inPoint, int inRadius)
       : Ellipse(inColour, inPoint, inRadius, inRadius)
{
   cout << "Circle initialiser constrcutor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Destructor

Circle::~Circle()
{
   cout << "Circle destructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which destructor is
// called
}

// Overidden virtual method draw()
// In this example we simple output the attributes of our rectangle
// rather than actually drawing it!

void Circle::draw()
{
   cout << "Circle Drawn!\n"
	<< "============\n\n";
   cout << "Starts at:\t" << getPosition() << '\n';
   cout << "Has colour:\t" << getColour() << '\n';
   cout << "Radius is:\t" << getRadius() << " units\n";

}

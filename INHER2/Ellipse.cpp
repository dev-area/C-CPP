// ellipse.cpp
// Implementation file for Ellipse class

#include "ellipse.h"

// Default constructor, uses default constructor of base class

Ellipse::Ellipse()
	: height(0), width(0)
{
   cout << "Ellipse default constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Initialiser constructor, uses initialiser constructor of base class			//Constructor with arguments

Ellipse::Ellipse(shapeColour inColour, Point &inPoint, int inHeight, int inWidth)
	: Shape(inColour, inPoint), height(inHeight), width(inWidth)
{
   cout << "Ellipse initialiser constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Destructor

Ellipse::~Ellipse()
{
   cout << "Ellipse destructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which destructor is
// called
}

// Overidden virtual method draw()
// In this example we simple output the attributes of our Ellipse
// rather than actually drawing it!

void Ellipse::draw()
{
   cout << "Ellipse Drawn!\n"
	<< "=============\n\n";
   cout << "Starts at:\t" << getPosition() << '\n';
   cout << "Has colour:\t" << getColour() << '\n';
   cout << "and is:\t" << getHeight() << " units high\n";
   cout << "and is:\t" << getWidth() << " units wide\n";
}

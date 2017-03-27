// rect.cpp
// Implementation file for Rectangle class

#include "rect.h"

// Default constructor, uses default constructor of base class

Rectangle::Rectangle()
	  : height(0), width(0)
{
   cout << "Rectangle default constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Initialiser constructor, uses initialiser constructor of base class

Rectangle::Rectangle(shapeColour inColour, Point &inPoint, int inHeight, int inWidth)
	  : Shape(inColour, inPoint), height(inHeight), width(inWidth)
{
   cout << "Rectangle initialiser constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Destructor

Rectangle::~Rectangle()
{
   cout << "Rectangle destructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which destructor is
// called
}

// Overidden virtual method draw()
// In this example we simple output the attributes of our rectangle
// rather than actually drawing it!

void Rectangle::draw()
{
   cout << "Rectangle Drawn!\n"
	<< "===============\n\n";
   cout << "Starts at:\t" << getPosition() << '\n';
   cout << "Has colour:\t" << getColour() << '\n';
   cout << "and is:\t" << getHeight() << " units high\n";
   cout << "and is:\t" << getWidth() << " units wide\n";
}

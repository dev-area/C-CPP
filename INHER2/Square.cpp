// square.cpp
// Implementation file for Square class

#include "square.h"

// Default constructor, uses default constructor of base class

Square::Square()
{
   cout << "Square default constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Initialiser constructor, uses initialiser constructor of base class
// Which in this case is Rectangle

Square::Square(shapeColour inColour, Point &inPoint, int inSize)
       : Rectangle(inColour, inPoint, inSize, inSize)
{
   cout << "Square initialiser constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Destructor

Square::~Square()
{
   cout << "Square destructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which destructor is
// called
}

// Overidden virtual method draw()
// In this example we simple output the attributes of our Square
// rather than actually drawing it!

void Square::draw()
{
   cout << "Square Drawn!\n"
	<< "===============\n\n";
   cout << "Starts at:\t" << getPosition() << '\n';
   cout << "Has colour:\t" << getColour() << '\n';
   cout << "Each side is:\t" << getSize() << " units long\n";

}

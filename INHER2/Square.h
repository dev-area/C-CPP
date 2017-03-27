// square.h
// Class defintion for Square class - derived from Rectangle

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream.h>
#include "rect.h"

class Square  : public Rectangle
{
public:

// Default constructor, uses default constructor of base class

   Square();

// Initialiser constructor, uses initialiser constructor of base class
// Which in this case is Rectangle

   Square(shapeColour inColour, Point &inPoint, int inSize);

// Destructor will be virtual as base class destructor is virtual

   ~Square();

// Access functions for data members, these set values in the
// inherited data members, which are private and we do not have
// direct access. So, we have to use inherited access functions

   void setSize(const int inSize) { setHeight(inSize);
				    setWidth(inSize); }
   int  getSize() const { return getHeight(); }

// Overidden virtual method
// NOTE this method is also defined virtual so as to allow this class
// to be a base class and so classed derived from Square can also
// overide draw()

   virtual void draw();

private:

// No new attributes are needed!
};

#endif

// circle.h
// Class defintion for Circle class - derived from Ellipse

#ifndef circle_H
#define circle_H

#include <iostream.h>
#include "ellipse.h"

class Circle  : public Ellipse
{
public:

// Default constructor, uses default constructor of base class

   Circle();

// Initialiser constructor, uses initialiser constructor of base class			//Constructor with arguments

   Circle(shapeColour inColour, Point &inPoint, int inRadius);

// Destructor will be virtual as base class destructor is virtual

   ~Circle();

// Access functions for data members, these set values in the
// inherited data members, which are private and we do not have
// direct access. So, we have to use inherited access functions

   void setRadius(const int inRadius) { setHeight(inRadius);
					setWidth(inRadius); }
   int  getRadius() const { return getHeight(); }

// Overidden virtual method
// NOTE this method is also defined virtual so as to allow this class
// to be a base class and so classed derived from Circle can also
// overide draw()

   virtual void draw();

private:

// No additional attributes are needed
};

#endif

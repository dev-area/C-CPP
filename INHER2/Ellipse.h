// ellipse.h
// Class defintion for Ellipse class - derived from Shape

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream.h>
#include "shape.h"

class Ellipse  : public Shape
{
public:

// Default constructor, uses default constructor of base class

   Ellipse();

// Initialiser constructor, uses initialiser constructor of base class			//Constructor with arguments

   Ellipse(shapeColour inColour, Point &inPoint, int inHeight, int inWidth);

// Destructor will be virtual as base class destructor is virtual

   ~Ellipse();

// Access functions for data members

   void setHeight(const int inHeight) { height = inHeight; }
   int  getHeight() const { return height; }
   void setWidth(const int inWidth) { width = inWidth; }
   int  getWidth() const { return width; }

// Overidden virtual method
// NOTE this method is also defined virtual so as to allow this class
// to be a base class and so classed derived from Ellipse can also
// overide draw()

   virtual void draw();

private:
   int height;	// height of Ellipse
   int width;	// width of Ellipse

};

#endif

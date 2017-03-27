// rect.h
// Class defintion for Rectangle class - derived from Shape

#ifndef RECT_H
#define RECT_H

#include <iostream.h>
#include "shape.h"

class Rectangle  : public Shape
{
public:

// Default constructor, uses default constructor of base class

   Rectangle();

// Initialiser constructor, uses initialiser constructor of base class

   Rectangle(shapeColour inColour, Point &inPoint, int inHeight, int inWidth);

// Destructor will be virtual as base class destructor is virtual

   ~Rectangle();

// Access functions for data members

   void setHeight(const int inHeight) { height = inHeight; }
   int  getHeight() const { return height; }
   void setWidth(const int inWidth) { width = inWidth; }
   int  getWidth() const { return width; }

// Overidden virtual method
// NOTE this method is also defined virtual so as to allow this class
// to be a base class and so classed derived from Rectangle can also
// overide draw()

   virtual void draw();

private:
   int height;	// height of rectangle
   int width;	// width of rectangle

};

#endif

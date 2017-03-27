// shape.h
// Class definition file for base class shape
//

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream.h>
#include "point.h"	// needed for Point object data member

class Shape
{
public:
   enum shapeColour { BLACK,BLUE,RED,YELLOW,GREEN,PURPLE,WHITE };

// Default Constructor

   Shape();

// Initialiser Constructor

   Shape(shapeColour inColour, Point inPoint);

// Destructor MUST be virtual for correct destructor to be called

   virtual ~Shape();

// Non static data member access functions

   void setcolour (const shapeColour inColour) { colour = inColour; }
   shapeColour getColour() const { return colour; }
   void setposition (const Point &inPoint) { position = inPoint; }
   Point &getPosition() { return position; }

// Static data member access functions

   static int getNumberOfShapes() { return numberOfShapes; }

// Static data manipulator function

   static  void incNumberOfShapes() { numberOfShapes++; }

// Virtual draw manipulator function. Does nothing and designed
// to be overridden

   virtual void draw() {}

private:

   shapeColour colour; 		// colour of shape
   Point position; 		// position of shape
   static int numberOfShapes; 	// Class data member, number of shapes

};

#endif

// point.h
// Class definition for Point class

#ifndef POINT_H
#define POINT_H

#include <iostream.h>

class Point      
{
public:

// Default Constructor
   Point()
	 : x(0), y(0)
   {
   }

// Initialiser Constructor
   Point(int inX, int inY)
	: x(inX), y(inY)
   {
   }

   friend ostream &operator << (ostream &os, Point &aPoint);

private:
   int x;	// x coordinate
   int y;	// y coordinate

};

#endif

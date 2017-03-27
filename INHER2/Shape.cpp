// shape.cpp
// Implementation file for base class shape
//
//
// REMEMBER to initialise the static class data member, so we do it
// here so that we do not forget it!

#include "shape.h"

int Shape::numberOfShapes = 0; //Static data member initialization

// Default constructor

Shape::Shape()
      : colour(BLACK), position(0,0)
{
   cout << "Shape default constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called

}

// Initialiser Constructor

Shape::Shape(shapeColour inColour, Point inPoint)
      : colour(inColour), position(inPoint)
{
   cout << "Shape initialiser constructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which constructor is
// called
}

// Destructor

Shape::~Shape()
{
   cout << "Shape destructor called\n";

// Of course we would not normally put this statement in a program
// but I put it in so that you can see when and which destructor is
// called
}


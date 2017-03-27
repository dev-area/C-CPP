// Ex11.cpp - Example 11 to show the power of virtual functions
//
// Requires a project containing the files
//
// shape.cpp
// point.cpp
// rect.cpp
// square.cpp
// ellipse.cpp
// circle.cpp
// ex11.cpp
//

#include <iostream.h>
#include <conio.h>
#include <stdlib.h>	// for randomize() & rand()
#include <ctype.h>	// for toupper()
#include <dos.h>	// for delay()

// Need to include all header file for shapes.

#include "shape.h"
#include "point.h"
#include "rect.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"


// We will ask the user for the type of shape to be drawn, but the colour
// position, size (radius) etc will be decided by random numbers.
//

void main()
{
   Shape::shapeColour colours[7] = { Shape::BLACK,
				     Shape::BLUE,
				     Shape::RED,
				     Shape::YELLOW,
				     Shape::GREEN,
				     Shape::PURPLE,
				     Shape::WHITE };
   int colour;
   int xPos, yPos;
   int height, width;

// Array of pointer to Shape to hold the types of shapes user has selected

   Shape *drawnShape[100];

   char choice = ' ';

   randomize(); 	// initialise random number generator;

   do {

// Generate random values for the shape

      colour = rand() % 6;		// between 0 and 6
      xPos   = (rand() % 79) + 1;	// between 1 and 80
      yPos   = (rand() % 24) + 1;	// between 1 and 25
      height = (rand() % 19) + 1;	// between 1 and 20
      width  = (rand() % 39) + 1;	// between 1 and 40

      clrscr();

// Present and ask user for a choice

      cout << "What shape would you like to draw?\n\n"
	   << "R - rectangle\n"
	   << "S - square\n"
	   << "E - ellipse\n"
	   << "C - circle\n\n"
	   << "Q - quit\n\n"
	   << "Enter the character corressponding to your choice ";
      choice = toupper(getche());
      cout << '\n';
// Decide which shape and create it

      if (choice != 'Q')
      {
	 int numberOfShapes = Shape::getNumberOfShapes();
	 switch (choice)
	 {
	    case 'R' : drawnShape[numberOfShapes] = new Rectangle(colours[colour],
							     Point(xPos,yPos),
							     height, width);
		       Shape::incNumberOfShapes();
		       break;
	    case 'S' : drawnShape[numberOfShapes] = new Square(colours[colour],
							  Point(xPos,yPos),
							  height);
		       Shape::incNumberOfShapes();
		       break;
	    case 'E' : drawnShape[numberOfShapes] = new Ellipse(colours[colour],
							   Point(xPos,yPos),
							   height, width);
		       Shape::incNumberOfShapes();
		       break;
	    case 'C' : drawnShape[numberOfShapes] = new Circle(colours[colour],
							  Point(xPos,yPos),
							  height);
		       Shape::incNumberOfShapes();
		       break;
	 }
      delay(2000); // wait for 2 secs so that user can see constructor
      }
   } while (choice != 'Q');

   clrscr();

   cout << "You have drawn " << Shape::getNumberOfShapes() << " shapes "
	<< "these are:\n\n";

   for (int i=0; i<Shape::getNumberOfShapes(); i++)
   {
      drawnShape[i]->draw();
      cout << "\nPress any key to see next shape\n\n";
      getch();
   }

// Now destroy all shapes
// NOTE We CANNOT simply delete the array  drawnShape since this is NOT
// allocated space in Dynamic memory! It just contains the pointers to
// the objects which ARE allocated in Dynamic memory. We simply loop
// through drawnShape and delete each object individually.

   for (i=0; i<Shape::getNumberOfShapes(); i++)
       delete drawnShape[i];
}
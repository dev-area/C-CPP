// point.cpp
// Implementation file for Point class

#include "point.h"

// Friend function for direct output of data members for a Point
// Outputs as (x,y) with no newline

ostream &operator<< (ostream &os, Point &aPoint)
{
  os << '(' << aPoint.x << ',' << aPoint.y << ')';
  return os;
}

                                  // Chapter 8 - Program 6
#include <iostream.h>

class vehicle {
protected:
   int wheels;
   float weight;
public:
   vehicle(void) {wheels = 7; weight = 11111.0;}
   void initialize(int in_wheels, float in_weight);
   int get_wheels(void) {return wheels;}
   float get_weight(void) {return weight;}
   float wheel_loading(void) {return weight/wheels;}
};




class car : public vehicle {
   int passenger_load;
public:
   car(void) {passenger_load = 4;}
   void initialize(int in_wheels, float in_weight, int people = 4);
   int passengers(void) {return passenger_load;}
};




class truck : public vehicle {
   int passenger_load;
   float payload;
public:
   truck(void) {passenger_load = 3; payload = 22222.0;}
   void init_truck(int how_many = 2, float max_load = 24000.0);
   float efficiency(void);
   int passengers(void) {return passenger_load;}
};




main()
{
vehicle unicycle;

// unicycle.initialize(1, 12.5);
   cout << "The unicycle has " <<
                                unicycle.get_wheels() << " wheel.\n";
   cout << "The unicycle's wheel loading is " <<
         unicycle.wheel_loading() << " pounds on the single tire.\n";
   cout << "The unicycle weighs " <<
                             unicycle.get_weight() << " pounds.\n\n";

car sedan;

// sedan.initialize(4, 3500.0, 5);
   cout << "The sedan carries " << sedan.passengers() <<
                                                    " passengers.\n";
   cout << "The sedan weighs " << sedan.get_weight() << " pounds.\n";
   cout << "The sedan's wheel loading is " <<
                    sedan.wheel_loading() << " pounds per tire.\n\n";

truck semi;

// semi.initialize(18, 12500.0);
// semi.init_truck(1, 33675.0);
   cout << "The semi weighs " << semi.get_weight() << " pounds.\n";
   cout << "The semi's efficiency is " <<
                          100.0 * semi.efficiency() << " percent.\n";
}




              // initialize to any data desired
void
vehicle::initialize(int in_wheels, float in_weight)
{
   wheels = in_wheels;
   weight = in_weight;
}



void
car::initialize(int in_wheels, float in_weight, int people)
{
   passenger_load = people;
   wheels = in_wheels;
   weight = in_weight;
}




void
truck::init_truck(int how_many, float max_load)
{
   passenger_load = how_many;
   payload = max_load;
}



float
truck::efficiency(void)
{
   return payload / (payload + weight);
}




// Result of execution
//
// The unicycle has 7 wheel.
// The unicycle's wheel loading is 1587.285767 pounds on the single tire.
// The unicycle weighs 11111 pounds.
//
// The sedan carries 4 passengers.
// The sedan weighs 11111 pounds.
// The sedan's wheel loading is 1587.285767 pounds per tire.
//
// The semi weighs 11111 pounds.
// The semi's efficiency is 66.666667 percent.

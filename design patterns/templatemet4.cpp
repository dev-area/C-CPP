#include <iostream.h>

class IncompleteAlgorithm {
public:
   void doIt() {       // this is the Template Method
      stepOne();       // invariant, standard
      stepTwo();       // invariant, standard
      stepThree();     // variable,  supplied by subclass
      stepFour(); }    // variable,  default provided
private:
   void stepOne() {
      cout << "IncompleteAlgorithm::stepOne" << endl; }
   void stepTwo() {
      cout << "IncompleteAlgorithm::stepTwo" << endl; }
   virtual void stepThree() = 0;
protected:
   virtual void stepFour() {
      cout << "IncompleteAlgorithm::stepFour" << endl; }
};

class FillInTheTemplate : public IncompleteAlgorithm {
   /* virtual */ void stepThree() {
      cout << "FillInTheTemplate::stepThree" << endl; }
   /* virtual */ void stepFour() {
      IncompleteAlgorithm::stepFour();
      cout << "FillInTheTemplate::stepFour" << endl; }
};

void main() {
   FillInTheTemplate  theThingToDo;
   theThingToDo.doIt();
}


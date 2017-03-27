#include <iostream.h>

class FSMstate { public:
   virtual void on()  { cout << "undefined combo" << endl; }
   virtual void off() { cout << "undefined combo" << endl; }
   virtual void ack() { cout << "undefined combo" << endl; } };

class FSM {
public:
   FSM();
   void on()   { states[current]->on();  current = next[current][0]; }
   void off()  { states[current]->off(); current = next[current][1]; }
   void ack()  { states[current]->ack(); current = next[current][2]; }
private:
   FSMstate*  states[3];
   int        current;
   int        next[3][3];
};

class A : public FSMstate { public:
   void on()  { cout << "A, on ==> A" << endl; }
   void off() { cout << "A, off ==> B" << endl; }
   void ack() { cout << "A, ack ==> C" << endl; }
};
class B : public FSMstate { public:
   void off() { cout << "B, off ==> A" << endl; }
   void ack() { cout << "B, ack ==> C" << endl; }
};
class C : public FSMstate { public:
   void ack() { cout << "C, ack ==> B" << endl; }
};

FSM::FSM() {
   states[0] = new A; states[1] = new B; states[2] = new C;
   current = 1;
   next[0][0] = 0; next[0][1] = 1; next[0][2] = 2;
   next[1][0] = 1; next[1][1] = 0; next[1][2] = 2;
   next[2][0] = 2; next[2][1] = 2; next[2][2] = 1; }

enum     Message { On, Off, Ack };
Message  messageArray[10] = { On,Off,Off,Ack,Ack,Ack,Ack,On,Off,Off };

void main( void ) {
   FSM  fsm;
   for (int i = 0; i < 10; i++) {
      if (messageArray[i] == On)        fsm.on();
      else if (messageArray[i] == Off)  fsm.off();
      else if (messageArray[i] == Ack)  fsm.ack(); }
}


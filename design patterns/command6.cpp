#include <iostream.h>

class Number {
public:
	Number( int value ) { _value = _copy = value; }
	int  getValue()     { return _value; }
	void increment()    { _copy = _value++; }
	void decrement()    { _copy = _value--; }
	void restore()      { _value = _copy; }
	void dubble()       { _copy = _value;  _value = 2 * _value; }
	void half()         { _copy = _value;  _value = _value / 2; }
	void square()       { _copy = _value;  _value = _value * _value; }
private:
	int _value;
	int _copy;
};


class Command {
public:
	virtual void execute() = 0;
	virtual void add( Command* ) { }
protected:
	Command() { }
};

class SimpleCommand : public Command {
public:
	typedef void (Number::* Action)();
	SimpleCommand( Number* receiver, Action action ) {
		_receiver = receiver;
		_action = action; }
	virtual void execute() { (_receiver->*_action)(); }
protected:
    Number* _receiver;
	Action  _action;
};

class MacroCommand : public Command {
public:
	MacroCommand() { _numCommands = 0; }
	void add( Command* cmd ) { _list[_numCommands++] = cmd; }
	virtual void execute();
private:
	Command* _list[10];
	int      _numCommands;
};

void MacroCommand::execute() {
	for (int i=0; i < _numCommands; i++)
		_list[i]->execute();
}

void main() {
	int i;
	cout << "Integer: ";
	cin >> i;
	Number*   object = new Number(i);

	Command*  commands[9];
	commands[1] = new SimpleCommand( object, &Number::increment );
	commands[2] = new SimpleCommand( object, &Number::decrement );
	commands[3] = new SimpleCommand( object, &Number::dubble );
	commands[4] = new SimpleCommand( object, &Number::half );
	commands[5] = new SimpleCommand( object, &Number::square );
	commands[6] = new SimpleCommand( object, &Number::restore );
	commands[7] = new MacroCommand;
	commands[7]->add( commands[1] );
	commands[7]->add( commands[3] );
	commands[7]->add( commands[5] );
	commands[8] = new MacroCommand;
	commands[8]->add( commands[7] );
	commands[8]->add( commands[7] );

	cout << "Exit[0], ++[1], --[2], x2[3], Half[4], Square[5], "
		<< "Undo[6], do3[7] do6[8]: ";
	cin >> i;

	while (i)
	{
		commands[i]->execute();
		cout << "   " << object->getValue() << endl;
		cout << "Exit[0], ++[1], --[2], x2[3], Half[4], Square[5], "
			<< "Undo[6], do3[7] do6[8]: ";
		cin >> i;
	}
}


// coins.c - friend member functions
#include <iostream.h>

class Account;											// forward reference

class Coin {
private:
	int price;
public:
	void purchase(Account &); 						// member function
	Coin(int p) { price = p; }
};

class Account {
friend void Coin::purchase(Account &);
private:
	int amount;
public:
	Account(int a) { amount = a; }
};

void Coin::purchase(Account & a) {				// member function
	cout << (a.amount -= price) << endl;
}

int main()
{
	Account bank(20000);								// bank account
	Coin c1(500);
	c1.purchase(bank);
	return 0;
}

/**********************************************************************

$ coins 
19500

*/

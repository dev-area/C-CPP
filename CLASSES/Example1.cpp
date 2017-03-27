  // Example C++ program

  #include <iostream.h> // header file for C++ streams
  #include <conio.h>    // header file for screen and keyboard functions

  float tax(float); // function prototype
  int main()
  {
	float purchase, tax_amt, total;
	clrscr();	// clearscreen
	cout << "\nAmount of purchase: ";
	cin >> purchase;
	tax_amt = tax(purchase);
	total = purchase + tax_amt;
	cout.precision(2);
	cout << "\nPurchase is: " << purchase;
	cout << "\nTax: " << tax_amt;
	cout << "\nTotal: " << total;

	getch();	// wait for keypress

	return 0;
  }
  float tax(float amount)
  {
	float rate = 0.065;
	return(amount*rate);
  }


	
#include "complex.h"	// It #includes <iostream.h> AND <math.h>

const unsigned MAX_VEC = 7;

int
main()
{ unsigned num;
  cout << "\n\nHow many complex numbers do you wish to enter ?" << endl;
  cout << "(no more than " << MAX_VEC <<  ")  ";
  if (!(cin >> num)) {
    cout << "Failed to input number of elements\n";
    return 1;
  }
  if (num > MAX_VEC)  { cout << "Ooops... "; num = MAX_VEC; }
  cout << "I will read "<< num << " complex numbers\n";
  cout << "Please type each complex number as two floating-point numbers\n";

  complex  c[MAX_VEC];
  for (unsigned i = 0; i < num; ++i) {		//  INPUT
    cout << "Type in a complex number (#" << i << ")\n";
    if (!(cin >> c[i]).good()) {
      cout << "Failed to input complex #" << i << " (I stop reading)\n";
      num = i; break;
    }
    cout << "Complex #" << i << " is "<< c[i] << endl;
  }

  complex  c1(2,-1), c2(2);
  int	   ioperand = 2;
  double   doperand = sqrt(2.);
  for (unsigned i = 0; i < num; ++i) {		//  OUTPUT
    if (i % 2) cout << "\f";
    cout << "\n\n\nCurrent number is  " << c[i] << endl;
    cout << "\t    Norm^2 value = " << c[i].rsq() << endl;
    cout << "\t       Abs value = " << c[i].abs() << endl;
    cout << "\t       Arg value = " << c[i].arg() << endl;
    cout << "\tConjugate number = " << c[i].cnj() << endl;
    cout << "\tInverse   number = " << c[i].inv() << endl;
    cout << "\tOpposite  number = " << -c[i]	  << endl << endl;

    cout << "\tRight int operand: "
	 << c[i] << " + " << ioperand << " = " << c[i]+ioperand << endl;
    cout << "\tLeft  int operand: "
	 << ioperand << " - " << c[i] << " = " << ioperand-c[i] << endl;
    cout << "\tRight double operand: "
	 << c[i] << " * " << doperand << " = " << c[i]*doperand << endl;
    cout << "\tLeft  double operand: "
	 << doperand << " / " << c[i] << " = " << doperand/c[i] << endl<<endl;

    c2 = ((i < num - 1) ? c[i+1] : c1);
    cout << "\t" << c[i] << " + " << c2 << " = " << c[i]+c2 << endl;
    cout << "\t" << c[i] << " - " << c2 << " = " << c[i]-c2 << endl;
    cout << "\t" << c[i] << " * " << c2 << " = " << c[i]*c2 << endl;
    cout << "\t" << c[i] << " / " << c2 << " = " << c[i]/c2 << endl;
    cout << "\t1/(" << c[i] << "/" << c2 << ") = " << (c[i]/c2).inv() << endl;
    cout << endl;
    cout << "\t" << c[i] << " += " << c2 << " is " << (c[i]+=c2) << endl;
    cout << "\t" << c[i] << " *= " << c2 << " is " << (c[i]*=c2) << endl;
    cout << "\t" << c[i] << " -= " << c2 << " is " << (c[i]-=c2) << endl;
    cout << "\t" << c[i] << " /= " << c2 << " is " << (c[i]/=c2) << endl;
    cout << "\t1/(" << c[i] << "/" << c2 << ") = " << (c[i]/c2).inv() << endl;
  }
  cout << '\n';
  return 0;
}

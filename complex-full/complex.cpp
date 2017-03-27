#include "complex.h"	
			// Printing control-switches
#define JUST_EQUAL	(0)	// 0 - Use epsilons for printing comparisons
#define NO_1i_PRINT	(1)	// 1 - Print `i' rather than `1i'
#define BEAUTY_PRINT	(1)	// 1 - Do not print zero coordinates
	// Recommending: BEAUTY_PRINT >= NO_1i_PRINT >= JUST_EQUAL

#if JUST_EQUAL
inline bool complex::
equal(double object, double other, int )
{ return object == other;
}
#else
bool complex::
equal(double object, double other, int precision)
{
  const double	eps	= pow(0.1, precision);
  if (object == 0)	return (other < eps && other > -eps);
  const double	sig_eps = (object < 0 ? -1 : 1) * eps,
		up_prec = 1 + sig_eps,
		lw_prec = 1 - sig_eps;
  return (other < object*up_prec && other > object*lw_prec);
}
#endif

inline void complex::
im_print(ostream& os) const
{
#if NO_1i_PRINT
  if(!equal(1,fabs(im),os.precision())) os << fabs(im);	// prints `i', not `1i'
#else
  os << fabs(im);
#endif
  os << 'i';	return;
}

inline ostream& complex::
stnd_print(ostream& os) const
{ const char *const pl = (im < 0 ? " - " : " + " );
  os << '(' << re << pl;
  im_print(os);
  os << ')';
  return os;
}


ostream& complex::
gnrl_print(ostream& os) const
{
#if BEAUTY_PRINT
  if (im == 0) {
	if (re < 0) os << '(';
	os << re;
	if (re < 0) os << ')';
  }else if (re == 0) {
	if (im < 0) os << "(-";
	im_print(os);
	if (im < 0) os << ')';
  }else {
	stnd_print(os);
  }
#else
  stnd_print(os);		// Always print the standard way
#endif
  return os;
}

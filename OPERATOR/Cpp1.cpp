#include<iostream.h>
#include<time.h>
class date{
	time_t  t;
	date& add(int days){t+=24*3600*days; return *this;}
public:
	date(){ time(&t); }
	static date today;
	date operator+(int i){ date d=*this; d.add(i) ;return d;}
	date& operator++(){ add(1);return(*this); } //prefix
	date& operator++(int){ add(1);return(*this); } // postfix
	date& operator--(){ add(-1);return(*this); }
//	friend ostream& operator<<(ostream& os,const date& d)
//	{cout << d;return os;}
};

int main()
{
date d;
cout << d << endl << --d << endl << d+7 << endl;
return 0;
}
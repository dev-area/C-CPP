include ../Makefile.h

PROGS    =	iter2 unique

OUTPROGS =	string1 string2 iter1 iter3 icstring1

HEADERS =	icstring.hpp

EXPORT =	string2.in


string1.out: string1.exe
	string1 prog.dat mydir hello. oops.tmp end.dat > string1.out

string2.in: string2.inttt
	sed -f ../bin/ttt2cpp.sed < $< > $@

string2.out: string2.exe string2.in
	string2 < string2.in > string2.out


include ../Makefile.h

OUTPROGS =	sort1tst genera1 genera2 foreach3 removeif \
	   	fopow1 \
	  	compose1 compose2 compose3 compose4

PROGS =		memfun1

MODULES =	sort1

HEADERS =	fopow.hpp compose11.hpp compose12.hpp compose21.hpp \
		compose22.hpp compose10.hpp nullary.hpp print.hpp


fopow1: fopow.hpp fopow1.cpp

memfun1.cpp: memfun1head.cpp memfun1a.cpp memfun1b.cpp memfun1tail.cpp
	cat memfun1head.cpp > memfun1.cpp
	echo "" >> memfun1.cpp
	cat memfun1a.cpp >> memfun1.cpp
	echo "" >> memfun1.cpp
	cat memfun1b.cpp >> memfun1.cpp
	echo "" >> memfun1.cpp
	cat memfun1tail.cpp >> memfun1.cpp

compose1: print.hpp compose11.hpp

compose2: injcomp.hpp

compose3: compose3.cpp compose22.hpp

sort1: sort1.cpp sort1.o sort1tst
	@echo "vollstaendiges exe for sort1 is sort1tst, so"
	@echo "check which lines of sort1 are not part of sort1tst"
	@echo "(there should be none):"
	@echo "------ start -----"
	@diff sort1.cpp sort1tst.cpp | grep '^<' | cat
	@echo "------ end -----"
	rm sort1.cpp


include ../Makefile.h

OUTPROGS = 	vector1 deque1 list1 set1 \
		mmap1 map1 algo1 riter1 \
		remove1 remove2 remove3 \
		foreach1 transform1 prime1 \
		sort1tst fo1

PROGS =		list2 find1 copy1 copy2 copy3 ioiter1 \
		remove4 foreach2 add1 iterbug1

MODULES = 	sort1

HEADERS =	print.hpp

sort1: sort1.cpp sort1.o sort1tst
	@echo "vollstaendiges exe for sort1 is sort1tst, so"
	@echo "check which lines of sort1 are not part of sort1tst"
	@echo "(there should be none):"
	@echo "------ start -----"
	@diff sort1.cpp sort1tst.cpp | grep '^<' | cat
	@echo "------ end -----"
	rm sort1.cpp


include ../Makefile.h

NONPROGS = tests distimpl

OUTPROGS = itercat advance1 distance swap1 \
		reviter1 reviter2 reviter3 reviter4 \
		backins frontins inserter \
		ostriter \
		assoiter

PROGS = 	istriter advance2 

HEADERS =	distance.hpp assoiter.hpp print.hpp

EXPORT =	istriter.in advance2.in

distimpl: distimpltest.o
	echo distimpl.ttt OK
	
assoiter: assoiter.hpp

istriter.in: istriter.inttt
	sed -f ../bin/ttt2cpp.sed < $< > $@
istriter.out: istriter.exe istriter.in
	istriter < istriter.in > istriter.out

advance2.in: advance2.inttt
	sed -f ../bin/ttt2cpp.sed < $< > $@
advance2.out: advance2.exe advance2.in
	advance2 < advance2.in > advance2.out


include ../Makefile.h

OUTPROGS =	vector1 deque1 list1 \
		set2 set1 mset1 setcmp \
		map1 mmap1 mapfind mapcmp \
		array1 carray1 refsem1 \
		stack1 stack2 queue1 queue2 pqueue1 \
		bitset2

PROGS =		sortset sortvec bitset1

HEADERS =	newkey.hpp carray.hpp countptr.hpp Stack.hpp Queue.hpp print.hpp


refsem1: countptr.hpp

carray1: carray.hpp carray1.cpp

stack2: Stack.hpp stack2.cpp
stack2.ott: stack2
	stack2 > tmp.out 2>&1 
	echo '\begin{tttzeile}' > $*.ott
	cat tmp.out >> $*.ott
	echo '\end{tttzeile}' >> $*.ott
	rm tmp.out

queue2: Queue.hpp queue2.cpp
queue2.ott: queue2
	queue2 > tmp.out 2>&1 
	echo '\begin{tttzeile}' > $*.ott
	cat tmp.out >> $*.ott
	echo '\end{tttzeile}' >> $*.ott
	rm tmp.out


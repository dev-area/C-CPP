include ../Makefile.h

PROGS	= io1 sum1 sum2 charcat1 \
	  ignore1 ignoreparam1 charset \
	  cat1 cat2 charcat2 \
	  inbuf1 \
	  copy1 copy2 \
	  countlines

OUTPROGS = rdbuf1 rdbuf2 redirect \
	   rw1 sstr1 \
	   outbuf1 outbuf1x outbuf2 outbuf3 

HEADERS = ignore.hpp ignoreparam.hpp \
          frac1out.hpp frac2out.hpp frac1in.hpp frac2in.hpp \
	  outbuf1.hpp outbuf1x.hpp outbuf2.hpp outbuf3.hpp \
	  inbuf1.hpp

all:: redirect.txt.ctt

sum1a.cpp: sum1a.ctt
sum2a.cpp: sum2a.ctt
summain.cpp: summain.ctt
sum1.cpp: sum1a.cpp summain.cpp
	cat summain.cpp > sum1.cpp
	echo "" >> sum1.cpp
	cat sum1a.cpp >> sum1.cpp

sum2.cpp: sum2a.cpp summain.cpp
	cat summain.cpp > sum2.cpp
	echo "" >> sum2.cpp
	cat sum2a.cpp >> sum2.cpp

flags2.ott flags2.out: flags2.cpp flags2main.cpp
	make flags2main.ott
	mv flags2main.ott flags2.ott

redirect.txt.ctt: redirect.out
	echo '\begin{ttt}' > $*.ctt;
	cat $* >> $*.ctt;
	echo '\end{ttt}' >> $*.ctt;

outbuf1: outbuf1.hpp outbuf1.cpp
	$(CXX) $(CXXFLAGS) $@.cpp $(LDFLAGS) -o $@
outbuf1x: outbuf1x.hpp outbuf1x.cpp
	$(CXX) $(CXXFLAGS) $@.cpp $(LDFLAGS) -o $@
outbuf2: outbuf2.hpp outbuf2.cpp
	$(CXX) $(CXXFLAGS) $@.cpp $(LDFLAGS) -o $@

ignoreparam1: ignoreparam1.cpp ignoreparam.hpp
	$(CXX) $(CXXFLAGS) $@.cpp $(LDFLAGS) -o $@

doexportold::
	rm export/flags[12]*.cpp
	rm export/ignore*.cpp
	rm export/redirect.txt.cpp
	rm export/seek[12].cpp
	rm export/strstr[123].cpp


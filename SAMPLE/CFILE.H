//	cfile.h
//
//	class header file for text file of contacts
//

#ifndef CFILE_H
#define CFILE_H

#include <iostream.h>
#include <fstream.h>	// header file for file I/O
#include <string.h>
#include "contact3.h"

const	FILENAMELEN = 16;	// format x:\xxxxxxxx.xxx

class	ContactFile {
public:

//	Constructor

	ContactFile(char *inFileName) {fileName = inFileName;}

//	Access functions

	char *getFileName() {return fileName;}

//      Manipulator functions

	int openFileRead();
	int openFileWrite();
	int closeFile();

	int endOfFile() {return theFile.eof();}
	void readContactRecord(Contact &inContact);
	void writeContactRecord(Contact &outContact);

private:
	char *fileName;
	fstream theFile;	// allow for both input & output
};

#endif

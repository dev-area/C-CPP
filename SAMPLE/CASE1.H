//	case1.h
//
//	Header file for functions called by main program

#ifndef CASE1_H
#define CASE1_H

#include "cdbase1.h"
#include "menu.h"

//	Prototypes for functions called by main program

void	initialiseMenu(Menu &inMenu);
void	processChoice(int inChoice);
void	openDatabase();
void	addContact();
void	displayAContact();
void	closeDatabase();

#endif
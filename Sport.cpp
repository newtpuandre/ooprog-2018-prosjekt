#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
#include "ConstEnum.h"
#include "Sport.h"
#include "Functions.h"

using namespace std;

Sport::Sport() {
	//Paramless constructor
    divisionList = new List(Sorted); //Is this the right way to make a divisionlist?

    char temp[STRLEN];

	do {
		read("What table type does this sport use? 1 (2-1-0), 2 (3-1-0), 3 (3-2-1-0)", temp, STRLEN); //Reads tabletype as a single letter.
		switch (atoi(temp)) {
		case 1: table = tableType(a); break;
		case 2: table = tableType(b); break;
		case 3: table = tableType(c); break;
		default: cout << "\nInvalid table type. Try again.."; break;
		}
	} while (atoi(temp) != 1 && atoi(temp) != 2 && atoi(temp) != 3);

};

Sport::~Sport() {
    delete[] text;
};

void Sport::display() {

};

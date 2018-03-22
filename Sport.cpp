#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
#include "ConstEnum.h"
#include "Sport.h"
#include "Functions.h"
#include "Division.h"

using namespace std;

Sport::Sport() {
	//Paramless constructor
	cout << "\nWHEN CREATING A NEW SPORT IS REQUIRES A NAME!!";
};

Sport::Sport(char* name):TextElement(name) {

	divisionList = new List(Sorted);
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

void Sport::newDiv() {
	char divName[STRLEN];
	read("Division name", divName, STRLEN);

	//TODO: If fila faktisk finnes -> de neste linjene..
	//KRAV: brukeren taster .dta (ellers må det stringcattes, før det sendes videre)
	Division* division;
	division = new Division(divName);
	divisionList->add(division);
    char divName[STRLEN];
    read("Division name", divName, STRLEN);
    
    //TODO: If fila faktisk finnes -> de neste linjene..
    //KRAV: brukeren taster .dta (ellers mÃ¥ det stringcattes, fÃ¸r det sendes videre)
    Division* division;
    division = new Division(divName);
    divisionList->add(division);
}

Sport::~Sport() {
	delete[] text;
};

void Sport::display() {

};

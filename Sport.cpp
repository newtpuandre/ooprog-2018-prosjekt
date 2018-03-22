#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include <iostream>
#include <fstream>
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
    char fileName[STRLEN];
    ifstream inn(fileName);
    
    read("Division name", divName, STRLEN);
    read("File name", fileName, STRLEN);
    
    if (inn) { //KRAV: brukeren taster .dta (ellers må det stringcattes, før det sendes videre)
	Division* division;
	division = new Division(divName);
    division->readFromFile(inn);
	divisionList->add(division);
    }
}

Sport::~Sport() {
	delete[] text;
};

void Sport::display() {
	cout << "\nName of the sport: " << text;
	switch (table) {
	case a: cout << "\nTable type: 2-1-0"; break;
	case b: cout << "\nTable type: 3-1-0"; break;
	case c: cout << "\nTable type: 3-2-1-0"; break;
	}
};

void Sport::displayTeam() {
	char divName[STRLEN];
	Division* tempDiv;
	read("What division", divName, STRLEN);
	if (divisionList->inList(divName)) {
		tempDiv = (Division*)divisionList->remove(divName);
		tempDiv->displayTeam();

	}
	else {
		cout << "\nThe division with name " << divName << " does not exist";
	}

	divisionList->add(tempDiv);

}
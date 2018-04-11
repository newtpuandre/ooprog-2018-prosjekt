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

Sport::Sport(char* name) :TextElement(name) {

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

	read("Division name", divName, STRLEN);
	read("File name (Including file extension)", fileName, STRLEN);

	ifstream inn(fileName);
	if (!divisionList->inList(divName)) {
		if (inn) {
			Division* tempDivision;
			tempDivision = new Division(divName);
			tempDivision->readFromFile(inn);
			divisionList->add(tempDivision);
		}
		else {
			cout << "\nCan't find the file with name: " << fileName;
		}

		numberOfDivisions++;
	}
	else {
		cout << "\nDivision already exist";
	}
}
 
Sport::~Sport() { //No need for this?? No ptr
	//delete[] text;
};

void Sport::display() {
	cout << "\nName of the sport: " << text;
	switch (table) {
	case a: cout << "\nTable type: 2-1-0"; break;
	case b: cout << "\nTable type: 3-1-0"; break;
	case c: cout << "\nTable type: 3-2-1-0"; break;
	}
	cout << "\nNumber of divisions: " << numberOfDivisions;
	//divisionList->displayList();
};

void Sport::displayOne() {
	Sport::display();
	divisionList->displayList();
}

void Sport::displayTeam() {
	char divName[STRLEN];
	Division* tempDiv;
	read("What division", divName, STRLEN);
	if (divisionList->inList(divName)) {
		tempDiv = (Division*)divisionList->remove(divName);
		tempDiv->displayTeam();
		divisionList->add(tempDiv);
	}
	else {
		cout << "\nThe division with name " << divName << " does not exist";
	}
}

void Sport::editPlayer() {
	char divName[STRLEN];
	Division* tempDiv;
	read("What division", divName, STRLEN);
	if (divisionList->inList(divName)) {
		tempDiv = (Division*)divisionList->remove(divName);
		tempDiv->editPlayer();
		divisionList->add(tempDiv);
	}
	else {
		cout << "\nThe division with name " << divName << " does not exist";
	}
}

void Sport::removeDiv() {
	char divName[STRLEN];
	char answ;

	read("What division", divName, STRLEN);

	if (divisionList->inList(divName)) { //If the desired division is in the divisionlist.
		cout << "\nAre you sure you want to delete this division? All data within will be permanently lost!! (y/N) ";
		answ = read();

		if (toupper(answ) == 'Y') {			//If the user confirms deletion..
			divisionList->destroy(divName); //.. the division is destroyed.
			numberOfDivisions--;
		}
		else {
			cout << "\nThe division " << divName << " was not deleted.";
		}
	}
	else {
		cout << "\nThe division with name " << divName << " does not exist!";
	}
}

void Sport::displayResults() {
	char divName[STRLEN];
	Division* tempDiv;

	read("What division", divName, STRLEN);
	tempDiv = (Division*)divisionList->remove(divName);
	tempDiv->displayResults();
	divisionList->add(tempDiv);
}

void Sport::schedule() {
    char divName[STRLEN];
    
    Division* tempDiv;
    
    read("Division", divName, STRLEN);
    
    if (divisionList->inList(divName)) {
        tempDiv = (Division*)divisionList->remove(divName);
        tempDiv->schedule();
        divisionList->add(tempDiv);
    }
    else {
        cout << "The division " << divName << " does not exist!";
    }
}

void Sport::writeTable() {
	char fileTemp[STRLEN];
	char divTemp[STRLEN];
	Division* tempDiv;
	read("Division name (Empty string for the whole sport)", divTemp);

	if (strlen(divTemp) == 0) { //Empty string, calculate for the whole sport

		read("Print to file or screen? (empty string = screen)", fileTemp);

		if (strlen(fileTemp) == 0) { //Print to screen
			cout << "yes";
			for (int i = 1; i > divisionList->noOfElements(); i++) {
				cout << i;
				tempDiv = (Division*)divisionList->removeNo(i);
				tempDiv->writeTable(table, fileTemp);
				divisionList->add(tempDiv);
			}
		}
		else { //Print to file
			cout << "no";
			for (int i = 1; i > divisionList->noOfElements(); i++) {
				cout << i;
				tempDiv = (Division*)divisionList->removeNo(i);
				tempDiv->writeTable(table, fileTemp);
				divisionList->add(tempDiv);
			}
		}

	}
	else { //Non-empty string, calculate for a division
		read("Print to file or screen? (empty string = screen)", fileTemp);

		if (strlen(fileTemp) == 0) { //Print to screen
			if (divisionList->inList(divTemp)) {//Is inList
				tempDiv = (Division*)divisionList->remove(divTemp);
				tempDiv->writeTable(table,fileTemp);
				divisionList->add(tempDiv);
			}
			else { //Was not found in the list
				cout << "\nNo division with name " << divTemp << " was found.";
			}

		}
		else { //Print to file
			if (divisionList->inList(divTemp)) {//Is inList
				tempDiv = (Division*)divisionList->remove(divTemp);
				tempDiv->writeTable(table,fileTemp);
				divisionList->add(tempDiv);
			}
			else { //Was not found in the list
				cout << "\nNo division with name " << divTemp << " was found.";
			}
		}


	}
}


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iomanip>
#include <iostream>
#include <fstream>

#include "Result.h"
#include "Sport.h"
#include "Functions.h"

Result::Result() {
	//Paramless constructor
};

Result::Result(char d[DATELEN]) {
    //date = d;
    //date = new char [strlen(d) + 1]; //Saves parameter as the result date.
    strcpy(date, d);
	
    //TEST SECTION BELOW!
    homeGoals = 0;
    awayGoals = 0;
}

Result::~Result() {
	//Deconstructor
}

void Result::display() {
	
}

void Result::readFromFile() {
    
}

void Result::displayResults() {
	cout << "\nthe results are"
		<< "\n" << homeGoals << " - " << awayGoals;
}

bool Result::cmpDate(char ddmm[]) {
	if (strcmp(date, ddmm) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Result::displayDate() {
    cout << date;
}

char Result::convertDate(char d[DATELEN]) { //Hacky code.. View just given cells instead? Still hacky..
	/*char shortDate[SHORTDATE];
	char format[SHORTDATE] = "/";
	
	// INPUT:	20181231
	// OUTPUT:	31/12

	for (int i = 7; i >= 6; i--) {		//Cell 7 and 6 from the long date format..
		for (int j = 0; j <= 1; i++) {	//.. is placed at cell 0 and 1.
			shortDate[j] = d[i];
		}
	}

	shortDate[2] = format[0];			//Adds '/' in cell 2 in shortdate for formatting.

	for (int i = 4; i <= 5; i++) {		//Cell 7 and 6 from the long date format..
		for (int j = 3; j <= 4; j++) {	//.. is place at cell 3 and 4.
			shortDate[j] = d[i];
		}
	}

	return shortDate;*/
	return 0; //MUST RETURN SOMETHING FIXES COMPILE ERROR
}

int Result::returnScore() { //Returns 0 if home won, 1 if away won, 2 if tie, 3 if not played
	//Remember to check for overtime
	if (homeGoals > awayGoals && overtime == false) {
		return 0; //Home won
	}
	else if (awayGoals < homeGoals && overtime == false) {
		return 1; //Away won
	}
	else if ( homeGoals == awayGoals && (homeGoals != 0 && awayGoals != 0) ) {
		return 2; //Tie
	}
	else { //Not played yet
		return 3;
	}
}

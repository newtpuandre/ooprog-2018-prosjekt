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
	

}

bool Result::cmpDate(char ddmm[]) {
	if (strcmp(date, ddmm) == 0) {
		return true;
	}
	else
		return false;
	//return (date == ddmm);
}
void Result::displayDate() {
    cout << date;
}

void Result::convertDate() { //Displays 'DD/MM' out of the 'ÅÅÅÅMMDD' date.
    cout << setw(10) << date[6] << date[7] << "/" << date[4] << date[5];
}

void Result::convertDate(ofstream &out) { //Displays 'DD/MM' out of the 'ÅÅÅÅMMDD' date.
    out << setw(10) << date[6] << date[7] << "/" << date[4] << date[5];
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

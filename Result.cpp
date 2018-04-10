#include <iomanip>
#include <iostream>
#include <fstream>

#include "Result.h"
#include "Sport.h"
#include "Functions.h"

Result::Result() {
	//Paramless constructor
};

Result::Result(char d[]) {
    //date = d;
    //date = new char [strlen(d) + 1]; //Saves parameter as the result date.
    strcpy(date, d);

    //TEST SECTION!
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
	if (strcmp(date,ddmm) == 0) {
		return true;
	}
	else 
		return false
	//return (date == ddmm);
}
void Result::displayDate() {
    cout << date;
}

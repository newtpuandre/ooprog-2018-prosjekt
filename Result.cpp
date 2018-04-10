#include <iomanip>
#include <iostream>
#include <fstream>

#include "Result.h"
#include "Sport.h"
#include "Functions.h"

Result::Result() {
	//Paramless constructor

};

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
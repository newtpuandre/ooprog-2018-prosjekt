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

Result::Result(char d[]) {
    //date = d;
    //date = new char [strlen(d) + 1]; //Saves parameter as the result date.
    strcpy(date, d);
	
    //TEST SECTION BELOW! Should reset all data in result.
    homeGoals = 0;
    awayGoals = 0;
    overtime = false;
    matchPlayed = false;
    
    for (int i = 0; i < MAXGOALS; i++) {
        homeScorers[i] = 0;
        awayScorers[i] = 0;
    }
    
}

Result::~Result() {
	//Deconstructor
}

void Result::display() {
	
}

void Result::readFromFile() {
    
}

void Result::displayResults() {
	cout << "\nThe results are"
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

void Result::convertDate() { //Displays 'DD/MM' out of the 'ÅÅÅÅMMDD' date.
    cout << setw(10) << date[6] << date[7] << "/" << date[4] << date[5];
}

void Result::convertDate(ofstream &out) { //Displays 'DD/MM' out of the 'ÅÅÅÅMMDD' date.
    out << setw(10) << date[6] << date[7] << "/" << date[4] << date[5];
}

int Result::returnScore() { //Returns 0 if home won, 1 if away won, 2 if tie, 3 if not played
							//4 if home won overtime, 5 if away won overtime, 6 if tie
	//Remember to check for overtime
	if (matchPlayed == false) {
		return 3;
	}
	else if (homeGoals > awayGoals && overtime == false) {
		return 0; //Home won
	}
	else if (awayGoals < homeGoals && overtime == false) {
		return 1; //Away won
	}
	else if ( homeGoals == awayGoals && overtime == false ) {
		return 2; //Tie
	}
	else if ( homeGoals == awayGoals && overtime == true ){ 
		return 6; //overtime tie
	}
	else if (homeGoals > awayGoals && overtime == true) {
		return 4; //Overtime Home won
	}
	else if (homeGoals < awayGoals && overtime == true) {
		return 5; //Overtime away won
	}
	else {//Not played yet
		return 3;
	}
}

void Result::readFromFile(ifstream &inn) {
	char tempDate[DATELEN];

	inn.getline(tempDate, STRLEN);
	strcpy(date, tempDate);
	inn >> homeGoals >> awayGoals; inn.ignore();
	inn >> overtime; inn.ignore();
}

void Result::writeToFile(ofstream &out) {
	out << date << '\n'			//Writes date of schedule out to file. 
		<< homeGoals << ' ' << awayGoals << '\n';

	if (homeGoals > 0) {
		for (int i = 0; i < homeGoals; i++) {
			out << homeScorers[i] << " ";
		}
		out << "\n";
	}
	else {
		out << "0\n";
	}

	if (awayGoals > 0) {
		for (int i = 0; i < awayGoals; i++) {
			out << awayScorers[i] << " ";
		}
		out << "\n";
	}
	else {
		out << "0\n";
	}

	out << overtime << '\n';
}

Result::Result(ifstream &inn) {
	int throwAway = 0;
	inn >> date; inn.ignore(); //Read date

	inn >> homeGoals; inn.ignore();
	inn >> awayGoals; inn.ignore();

	if (homeGoals != 0) {
		for (int i = 0; i < homeGoals; i++) {
			inn >> homeScorers[i]; inn.ignore();
		}
	}
	else {
		inn >> throwAway; inn.ignore();
	}

	if (awayGoals != 0) {
		for (int i = 0; i < awayGoals; i++) {
			inn >> awayScorers[i]; inn.ignore();
		}

	}
	else {
		inn >> throwAway; inn.ignore();
	}

	if (homeGoals > 0 || awayGoals > 0) {
		matchPlayed = true;
	}

	inn >> overtime; inn.ignore();

}

void Result::applyInfo(char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot) {
    //This function updates all info within result except date. Date is already set, checked and is correct.
    homeGoals = hGoals;
    awayGoals = aGoals;
    overtime = ot;
 
    for (int i = 0; i < hGoals; i++) { //Read all goalscoreres for hometeam.
        homeScorers[i] = hArr[i];
    }
    
    for (int j = 0; j < aGoals; j++) { //Read all goalscoreres for awayteam.
        awayScorers[j] = aArr[j];
    }
    
    matchPlayed = true;
 }

bool Result::returnPlayed() { //Return bool matchPlayed.
    return matchPlayed;
}

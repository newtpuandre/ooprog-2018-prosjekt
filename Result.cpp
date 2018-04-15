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
    strcpy(date, d); //Set date of result.
	
    //Reset all other data in result.
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

void Result::displayResults() { //Display the results - outputs only goals.
	cout << homeGoals << " - " << awayGoals;
}

void Result::displayResults(ofstream &out) { //Display the results - outputs only goals.
    out << homeGoals << " - " << awayGoals;
}

bool Result::cmpDate(char ddmm[]) { //Compare date of results with parameter.
	if (strcmp(date, ddmm) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Result::displayDate() { //Display date of the result.
    cout << date;
}

void Result::convertDate() { //Displays 'DD/MM' out of the 'YYYYMMDD' date.
    cout << setw(10) << date[6] << date[7] << "/" << date[4] << date[5];
}

void Result::convertDate(ofstream &out) { //Displays 'DD/MM' out of the 'YYYYMMDD' date.
    out << setw(10) << date[6] << date[7] << "/" << date[4] << date[5];
}

int Result::returnScore() { //Returns 0 if home won, 1 if away won, 2 if tie, 3 if not played
							//4 if home won overtime, 5 if away won overtime, 6 if tie
	if (matchPlayed == false) {
		return 3;
	}
	 if (homeGoals > awayGoals && (overtime == false && matchPlayed == true)) {
		return 0; //Home won
	}
	 if (awayGoals > homeGoals && (overtime == false && matchPlayed == true)) {
		return 1; //Away won
	}
	 if ( homeGoals == awayGoals && (overtime == false && matchPlayed == true)) {
		return 2; //Tie
	}
	 if ( homeGoals == awayGoals && (overtime == true && matchPlayed == true) ){
		return 6; //overtime tie
	}
	 if (homeGoals > awayGoals && (overtime == true && matchPlayed == true)) {
		return 4; //Overtime home won
	}
	 if (homeGoals < awayGoals && (overtime == true && matchPlayed == true)) {
		return 5; //Overtime away won
	}
	else {//Not played yet
		return 3;
	}
}

void Result::readFromFile(ifstream &inn) { //Reads result data from file.
	char tempDate[DATELEN];

	inn.getline(tempDate, STRLEN);  //Reads date.
	strcpy(date, tempDate);			//Copy date into results date.
	inn >> homeGoals >> awayGoals; inn.ignore(); //Reads home- and awaygoals.
	inn >> overtime; inn.ignore();	//Reads bool overtime.
}

void Result::writeToFile(ofstream &out) { //Writes result data to file.
	if (strlen(date) != 0) { //Don't write result to file if there is nothing to write!
		out << date << '\n'	 //Writes date of schedule out to file. 
			<< homeGoals << ' ' << awayGoals << '\n'; //Writes homegoals, awaygoals.

		if (homeGoals > 0) { //If there is any homegoals..
			for (int i = 0; i < homeGoals; i++) { //.. write all homescorers..
				out << homeScorers[i] << " ";	  //.. player IDs.
			}
			out << "\n";
		}
		else {				//Else write 0.
			out << "0\n";
		}

		if (awayGoals > 0) { //If there is any awaygoals..
			for (int i = 0; i < awayGoals; i++) { //.. write all awayscorers..
				out << awayScorers[i] << " ";	  //.. player IDs.
			}
			out << "\n";
		}
		else {				//Else write 0.
			out << "0\n";
		}
		out << matchPlayed << '\n'; //Write bool matchplayed.
		out << overtime << '\n';	//Write bool overtime.
	}
}

Result::Result(ifstream &inn) { //New result with data from readFromFile.
	int throwAway = 0; //Used for ints that needs to be read, but not saved.
	inn >> date; inn.ignore(); //Read date.

	inn >> homeGoals; inn.ignore(); //Read homegoals.
	inn >> awayGoals; inn.ignore(); //Read awaygoals.

	if (homeGoals != 0) { //If there is any homegoals..
		for (int i = 0; i < homeGoals; i++) { //.. read all homescorers player IDs.
			inn >> homeScorers[i]; inn.ignore();
		}
	}
	else { //Else read in throwaway and skip line. (Doesn't save the value)
		inn >> throwAway; inn.ignore();
	}

	if (awayGoals != 0) { //If there is any awaygoals..
		for (int i = 0; i < awayGoals; i++) { // readl all awayscorers player IDs.
			inn >> awayScorers[i]; inn.ignore();
		}

	}
	else { //Else read in throwaway and skip line (Doesn't save the value)
		inn >> throwAway; inn.ignore();
	}

	inn >> matchPlayed; inn.ignore(); //Read bool matchplayed.
	inn >> overtime; inn.ignore(); //Read bool overtime.

}

void Result::applyInfo(char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot) {
    homeGoals = hGoals;     //This function updates all info within result except date.
    awayGoals = aGoals;     //Date is already set, checked and is correct.
    overtime = ot;
 
    for (int i = 0; i < hGoals; i++) { //Read all goalscoreres for hometeam.
        homeScorers[i] = hArr[i];
    }
    
    for (int j = 0; j < aGoals; j++) { //Read all goalscoreres for awayteam.
        awayScorers[j] = aArr[j];
    }
    
    matchPlayed = true; //Updates matchplayeds status to true.
 }

bool Result::returnPlayed() { //Return bool matchPlayed.
    return matchPlayed;
}

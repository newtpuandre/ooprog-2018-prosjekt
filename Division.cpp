#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <iomanip>
#include <algorithm>

#include "Division.h"
#include "Functions.h"
#include "ListTool2B.h"
#include "Team.h"
#include "Result.h"


Division::Division() {
    //Must be made by reading from file!!
}

Division::Division(char* divName) :TextElement(divName) {
    text = new char [strlen(divName) + 1];
    strcpy(text, divName);
}

Division::~Division() {
    //Deconstructor
};

void Division::New() {
    
};

void Division::display() {
	cout << "\nDivisions name: " << text << '\n'
		 << "\nNumber of teams in the division: " << numberOfTeams << '\n';

	for (int i = 0; i < numberOfTeams; i++) {
		team[i]->display(false); //displays teams name, address and number of players. 
	}
};

void Division::readFromFile(ifstream &inn, bool startupRead) {
    
	Team* tempTeam; //Temporary team

    inn >> numberOfTeams; //Read number of teams from file.
	inn.ignore();

	if (!inn.eof()) {
		for (int i = 0; i < numberOfTeams; i++) {


			tempTeam = new Team(); //Create a new temp team
			tempTeam->readFromFile(inn); //Read team info from file
			team[i] = tempTeam; //Move temp team to array

		}
	}
	else {
		cout << "\nThe file is empty";
	}

	if (startupRead) {
		//Read Schedule from SPORTS.DTA HERE
		readScheduleStartup(inn);
	}
	else {
		readSchedule(inn);
	}

};

void Division::readScheduleStartup(ifstream &inn) {
	Result* tempRes;

	for (int x = 0; x < numberOfTeams; x++) { //Counts number of rows.

		vector<Result*> row; //CreatSe an empty row.

		for (int y = 0; y < numberOfTeams; y++) { //Counts number of colums.
			if (x != y) {
				tempRes = new Result(inn); //Creates new result with given date.
			}
			row.push_back(tempRes); //Add an element (column) to the row.
		}

		results.push_back(row); //Add the row to the main vector.
	}
}

void Division::displayTeam() {
	char teamName[STRLEN];
	bool found = false;
	read("What is the team name: ", teamName, STRLEN);
	for (int i = 0; i < numberOfTeams; i++) {

		if (*team[i] == teamName) {
			team[i]->display(true);
			found = true;
		}
	}
	if (found == false) {
		cout << "The team " << teamName << " does not exist";
	}
}

void Division::editPlayer() {
    char teamName[STRLEN];
	bool found = false;
    read("What is the team name: ", teamName, STRLEN);
    for (int i = 0; i < numberOfTeams; i++) {
        
        if (*team[i] == teamName) {
            team[i]->edit();
			found = true;
        }
    }
	if (found == false) {
		cout << "The team " << teamName << " does not exist";
	}
}

void Division::remove() {

}

void Division::matches() {
	char fileName[STRLEN];
	cout << "Filename (including file extension): ";
	cin.getline(fileName, STRLEN);

	if (fileName[0] == '\0') { //If no input is given
		displayMatches();      // display data to screen. 
	}
	else {
		writeMatches(fileName); //Else write to given filename. 
	}
}

void Division::displayMatches() {
	char date[DATELEN];
	Result* tempRes;

	read("What date", date, DATELEN);

	for (int x = 0; x < numberOfTeams; x++) { //Loops through the x-column in the matrix
		for (int y = 0; y < numberOfTeams; y++) { //Loops through the y-column in the matrix
			tempRes = results[x][y]; //Oppdaterer terminlista sånn at tempRes vet hvor i lista man er. 
			if (x != y) { //Team cannot play against itself. 
				if (tempRes->cmpDate(date)) { //Comparing dates.
					team[x]->displayName(); cout << " - "; team[y]->displayName(); //Displaying team vs. team at given date.
					cout << '\n';
					//	if (Teams already got results) {
					//tempRes->displayResults();
				}
			}
		}
	}
}

void Division::writeMatches(char fileName[]) {
	char date[DATELEN];
	Result* tempRes;

	read("What date", date, DATELEN);

	ofstream out(fileName);
	if (out) {                                    //If the file exists.
		for (int x = 0; x < numberOfTeams; x++) { //Loops through the x-column in the matrix
			for (int y = 0; y < numberOfTeams; y++) { //Loops through the y-column in the matrix
				tempRes = results[x][y]; //Oppdaterer terminlista sånn at tempRes vet hvor i lista man er. 
				if (tempRes != nullptr) { //Checks if tempRes points at anything or not. 
					if (tempRes->cmpDate(date)) { //Comparing dates.
						team[x]->displayName(out); out << " - "; team[y]->displayName(out); //Displaying team vs. team at given date.
						cout << '\n';
						//	if (Teams already got results) {
						//tempRes->displayResults();
						//	}

					}
				}
			}
		}
	}
	else {
		cout << "The file " << fileName << " does not exist.";
	}
}

void Division::schedule() {
    char fileName[STRLEN];
	cout << "Filename (including file extension): ";
	cin.getline(fileName, STRLEN);
    
    if(fileName[0] == '\0') {	//If no input is given..
        displaySchedule();		//..display schedule on screen.
    }
    else {
        writeSchedule(fileName);		//Else write to given filename. INSERT 'fileName' AS A PARAMETER!!!
    }
}

void Division::displaySchedule() {
    cout << "\n" << setw(5) << "Team:";			//Aestethic - The following four lines..
	for (int n = 1; n <= numberOfTeams; n++) {	//.. displays the teams index on y-axis.
		cout << setw(14) << n;
		if (n == numberOfTeams) { cout << "\n"; }
	}
    
    for (int x = 0; x < numberOfTeams; x++) { //Counts number of rows.
		cout << x+1 << ": ";	//Aestethic - Displays team index number.
		team[x]->displayName(); //Aestethic - Displays team name.
        
        for (int y = 0; y < numberOfTeams; y++) { //Counts number of colums.
            if (x != y) {
                results[x][y]->convertDate();	//Displays dates for each match
            }
            else {
                cout << setw(14) << "--";   //'--' is printed is the matrix when the team ..
            }                               //.. would play against themselves.
        }
        
		cout << endl;
    }
    
	/*			THE CODE BELOW SHOWS THE ADDRESS OF THE RESULT OBJECT POINTERS!

	cout << endl << endl << endl;

    for (int i = 0; i < results.size(); i++) { //Displays the rows
        for (int j = 0; j < results.size(); j++) { //Displays the columns.
            cout << results[i][j] << "\t";
        }
        cout << endl;

    }*/
}

void Division::writeSchedule(char fileName[STRLEN]) {
    
    ofstream out(fileName);
    
    out << setw(5) << "Team:";            //Aestethic - The following four lines..
    for (int n = 1; n <= numberOfTeams; n++) {    //.. displays the teams index on y-axis.
        out << setw(14) << n;
        if (n == numberOfTeams) { out << endl; }
    }
    
    for (int x = 0; x < numberOfTeams; x++) { //Counts number of rows.
        out << x+1 << ": ";    //Aestethic - Displays team index number.
        team[x]->displayName(out); //Aestethic - Displays team name.
        
        for (int y = 0; y < numberOfTeams; y++) { //Counts number of colums.
            if (x != y) {
                results[x][y]->convertDate(out);    //Displays dates for each match
            }
            else {
                out << setw(14) << "--";   //'--' is printed is the matrix when the team ..
            }                               //.. would play against themselves.
        }
        
        out << endl;
    }
    
}

void Division::readSchedule(ifstream &inn) {
	char tempDate[DATELEN];      
    Result* tempRes;
    
    for (int x = 0; x < numberOfTeams; x++) { //Counts number of rows.
		
		vector<Result*> row; //CreatSe an empty row.
        
        for (int y = 0; y < numberOfTeams; y++) { //Counts number of colums.
            if (x != y) {
            inn >> tempDate; //Reads the date from file.
			tempRes = new Result(tempDate); //Creates new result with given date.
            }
            row.push_back(tempRes); //Add an element (column) to the row.
        }
        
        results.push_back(row); //Add the row to the main vector.
        cout << endl;
    }
    
}

void Division::writeTable(tableType table,bool file,ofstream &out) {
	//Need to remember each teams points
	//Print the table to screen.
	teamTable* teamTableArr;
	teamTableArr = new teamTable[numberOfTeams];

	for (int i = 0; i < numberOfTeams; i++) { //Populate the structs with teamName.
		team[i]->returnName(teamTableArr[i].teamName);
	}

	
	for (int i = 0; i < numberOfTeams; i++) { //Double for loop to go through the matrix
		for (int j = 0; j < numberOfTeams; j++) {

			if (i != j) { //Teams cant be playing them selves..
				if (results[i][j]->returnScore() == 0) { //Home won
					teamTableArr[i].totalScore = TabletypeCalc(table, 1);
				}
				if (results[i][j]->returnScore() == 1) { //Away won
					teamTableArr[j].totalScore = TabletypeCalc(table, 1);
				}
				if (results[i][j]->returnScore() == 2) { //Tie
					teamTableArr[i].totalScore = TabletypeCalc(table, 3);
					teamTableArr[j].totalScore = TabletypeCalc(table, 3);
				}

				if (results[i][j]->returnScore() == 4) { //Overtime home win
					teamTableArr[i].totalScore = TabletypeCalc(table, 3);
				}

				if (results[i][j]->returnScore() == 5) { //Overtime away win
					teamTableArr[j].totalScore = TabletypeCalc(table, 3);
				}

				if (results[i][j]->returnScore() == 6) { //Overtime tie
					teamTableArr[i].totalScore = TabletypeCalc(table, 4);
					teamTableArr[j].totalScore = TabletypeCalc(table, 4);
				}

				//if overtime add special points
				
			}

		}
	}

	std::sort(&teamTableArr[0], &teamTableArr[numberOfTeams], //Sort by totalScore in descending order.
		[](teamTable left, teamTable right) {
		return left.totalScore > right.totalScore; // > = descending, < = ascending
	});
	
	if (file == false) { //Print to screen
		cout << "\nCurrent table standings for " << text << ":";
		for (int i = 0; i < numberOfTeams; i++) { //Print out to the screen
			cout << "\n" << teamTableArr[i].teamName << " " << teamTableArr[i].totalScore;
		}
	}
	else { //Write to file
		
		out << text << endl;
		for (int i = 0; i < numberOfTeams; i++) { //Write everY team to file
			writeTable(teamTableArr[i], out);
		}
	}

	cout << "\nCaclulations are done!";
}

void Division::writeTable(teamTable teamtable, ofstream &out) {
		out << teamtable.teamName << " " << teamtable.totalScore << endl;
}



int Division::TabletypeCalc(tableType table, int wlt) { //Finds the table type and returns the correct scoring, wlt, 1 win, 2 loss, 3 tie, 4 overtime
	switch (table) {

	case a: // a = "2-1-0
		if (wlt == 1) {
			return 2;
		}
		else if (wlt == 2) {
			return 0;
		}
		else if (wlt == 3) {
			return 1;
		}
		break;

	case b:// b = "3-1-0"
		if (wlt == 1) {
			return 3;
		}
		else if (wlt == 2) {
			return 0;
		}
		else if (wlt == 3) {
			return 1;
		}
		break;

	case c: // c= "3-2-1-0"
		if (wlt == 1) {
			return 3;
		}
		else if (wlt == 2) {
			return 0;
		}
		else if (wlt == 3) {
			return 2;
		}
		else { //wlt == 4
			return 1;
		}
		break;

	default: break;
	}
    return 0;
}

bool Division::checkInfo(char h[], char a[], char date[]) {
	//Team* tempTeam; //Create temp team.
	bool homeOK = false, awayOK = false/*, matchPlayed = false*/;

	homeOK = teamsExist(h);
	awayOK = teamsExist(a);

	//matchPlayed = matchPlayed(a, h, date);

	if (homeOK && awayOK/* && matchPlayed*/) {	//If both teams names exists and match is played, return true.
		cout << "Everything is inorder";
		return 1;
	}
	else {
		cout << "Things are on fire..";
		return 0;
	}
	
    //return 0;
}

bool Division::matchPlayed(char a[], char h[], char date[]) {
	/*
	bool buffer = false;
	
	for (int i = 0; i <= results.size(); i++) {
		for (int j = 0; j <= results.size(); j++) {

		}
	}
	*/
	return 0;
}

void Division::writeToFile(ofstream &out) {
	out << text << '\n';					//Writes out name of division to file. 
	out << numberOfTeams << '\n';			//Writes out number of teams to file.

	for (int i = 0; i < numberOfTeams; i++) {
		team[i]->writeToFile(out);
	}

	for (int x = 0; x < numberOfTeams; x++) { //Loops through the x-column in the matrix
		for (int y = 0; y < numberOfTeams; y++) { //Loops through the y-column in the matrix
			if (x != y) {
				results[x][y]->writeToFile(out);
			}
		}
	}
}

bool Division::teamsExist(char teamName[]) {
	bool found = false, allOK = false;
	for (int i = 0; i < numberOfTeams; i++) {
		found = team[i]->compareName(teamName); //Check if hometeams name exist.
		if (found == true) {
			allOK = true;
		}
	}

	return allOK;
}

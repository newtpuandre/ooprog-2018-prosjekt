#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <iomanip>

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

void Division::readFromFile(ifstream &inn) {
    
	Team* tempTeam; //Temporary team

    inn >> numberOfTeams; //Read number of teams from file.
	inn.ignore();

	if (!inn.eof()) {
		for (int i = 0; i < numberOfTeams; i++) {


			tempTeam = new Team(); //Create a new temp team
			tempTeam->readFromFile(inn); //Read team info from file
			team[i] = tempTeam; //Move temp team to array

								//This makes the file not read more than one team???
								//delete tempTeam; //Delete temp team

            
								//TODO: READ SCHEDULE (terminliste)
		}
	}
	else {
		cout << "\nThe file is empty";
	}
	
    readSchedule(inn);

};

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

void Division::displayResults() {
	char date[DATELEN];
	
	read("What date", date, DATELEN);

	/*for (int x = 0; i < ?; i++ ) {
		for (int y = 0; i < ?; y ++) {
			gå inn i en forloop som leter igjennom alle cellene i terminlista.
			Finnes da en dato med samme dato som er sendt inn så skal funksjonen gå inn i resultklassen og displaye data.

				if (*terminListe[i] == date){
				terminListe[i]->displayResults();
				}
			}

ni
	}*/
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

void Division::writeTable(tableType table) {
	//Need to remember each teams points
	//Print the table to screen.
	int* teamTable;
	teamTable = new int[numberOfTeams]; //[Index] is the same as they appear in the matrix. 1 is team 1. etc..

	
	for (int i = 0; i < numberOfTeams; i++) { //Double for loop to go through the matrix
		for (int j = 0; j < numberOfTeams; j++) {

			if (i != j) { //Teams cant be playing them selves..
				if (results[i][j]->returnScore() == 0) { //Home won
					teamTable[i] = TabletypeCalc(table, 1);
				}
				if (results[i][j]->returnScore() == 1) { //Away won
					teamTable[j] = TabletypeCalc(table, 1);
				}
				if (results[i][j]->returnScore() == 2) { //Tie
					teamTable[i] = TabletypeCalc(table, 3);
					teamTable[j] = TabletypeCalc(table, 3);
				}

				//if overtime add special points

			}

		}
	}

	cout << "\nCaclulations are done!";
}

void Division::writeTable(ifstream &inn) {

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

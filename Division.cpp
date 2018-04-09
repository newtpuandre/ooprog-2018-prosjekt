#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <vector>

#include "Division.h"
#include "Functions.h"
#include "ListTool2B.h"
#include "Team.h"

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


	}*/
}

void Division::schedule() {
    char fileName[STRLEN];
    read("Filename (including file extension)", fileName, STRLEN);
    
    if(fileName[0] == '\0') {
        displaySchedule();
    }
    else {
        writeSchedule();
    }
}

void Division::displaySchedule() { //This section is commented out, as nessacery testing is not done yet. Work will be resumed shortly. -S
    /*Result* tempRes;
    
    for (int x = 0; x < 3; x++) { //Counts number of rows. This must be dynamic and counted somewhere.
        vector<Result*> row; //Create an empty row.
        
        //cout << "rad";
        
        for (int y = 0; y < 5; y++) { //Counts number of colums. This must be dynamic and counted somewhere.
            row.push_back(tempRes); //Add an element (column) to the row.
            //cout << "kolonne";
        }
        
        results.push_back(row); //Add the row to the main vector.
    }
    
    for (int i = 0; i < results.size(); i++) { //Displays the rows
        for (int j = 0; j < results[j].size(); j++) { //Displays the columns.
            cout << results[i][j];
        }
        cout << endl;
    }
    */
}

void Division::writeSchedule() {
    cout << "Test2";
}



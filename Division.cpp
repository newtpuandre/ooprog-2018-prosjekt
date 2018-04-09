#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>

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
			g� inn i en forloop som leter igjennom alle cellene i terminlista.
			Finnes da en dato med samme dato som er sendt inn s� skal funksjonen g� inn i resultklassen og displaye data.

				if (*terminListe[i] == date){
				terminListe[i]->displayResults();
				}
			}


	}*/
}
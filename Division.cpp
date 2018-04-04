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
	//for (int i = 1; i <= numberOfTeams; i++) {
		//team[i]->display(); //displays teams name, address and number of players. 
	//}
};

void Division::readFromFile(ifstream &inn) {
    
	Team* tempTeam; //Temporary team

    inn >> numberOfTeams; //Read number of teams from file.
	inn.ignore();
    
	//TODO: CHECK IF FILE IS EMPTY?

	for (int i = 0; i < numberOfTeams; i++) {


		tempTeam = new Team(); //Create a new temp team
		tempTeam->readFromFile(inn); //Read team info from file
		team[i] = tempTeam; //Move temp team to array

		//This makes the file not read more than one team???
		//delete tempTeam; //Delete temp team


		//TODO: READ SCHEDULE (terminliste)
	}


};

void Division::displayTeam() {
    char teamName[STRLEN];
    read("What is the team name: ", teamName, STRLEN);
    for (int i = 0; i < numberOfTeams; i++) {
        
        if (*team[i] == teamName) {
            team[i]->display();
        }
    }
}

void Division::editPlayer() {
    char teamName[STRLEN];
    read("What is the team name: ", teamName, STRLEN);
    for (int i = 0; i < numberOfTeams; i++) {
        
        if (*team[i] == teamName) {
            team[i]->edit();
        }
    }
}

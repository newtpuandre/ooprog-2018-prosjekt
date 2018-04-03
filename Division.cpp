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
    
};

void Division::readFromFile(ifstream &inn) {
    int lastUsed = 1;
    
	Team* temp; //Temporary team

    inn >> numberOfTeams; //Read number of teams from file.
    
	//TODO: CHECK IF FILE IS EMPTY?


	for (int i = 0; i < numberOfTeams; i++) {

		temp = new Team(); //Create a new temp team
		temp->readFromFile(inn); //Read team info from file
		team[lastUsed++] = temp; //Move temp team to array
		delete temp; //Delete temp team

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

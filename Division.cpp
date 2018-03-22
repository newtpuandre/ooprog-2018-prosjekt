#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include "Division.h"
#include "Functions.h"
#include "ListTool2B.h"
#include <fstream>
#include "Team.h"

Division::Division() {
    //Must be made by reading from file!!
}

Division::Division(char* divName) {
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
    
    inn >> numberOfTeams;
    
    while (lastUsed <= numberOfTeams) {
        team[lastUsed++]->readFromFile();
        //result[lastUsed++]->readFromFile();     //READ SCHEDULE (terminliste)
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
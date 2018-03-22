#include "Division.h"
#include "Functions.h"
#include "ListTool2B.h"

Division::Division() {
    //Must be made with a name!!
}

Division::Division(char divName[]) {
    readFromFile(divName);
};

Division::~Division() {
	//Deconstructor
};

void Division::New() {

};

void Division::display() {
	
};

void Division::readFromFile(char divName[]) {
    
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
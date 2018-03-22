#include <iostream>
#include "Team.h"


Team::Team() {
	//Paramless constructor

};

Team::~Team() {
	//Deconstructor
};

void Team::display() {
	cout << "\nName of the team: " << name
		<< "\nTeam address: " << address
		<< "\nNumber of players on the team: " << numberOfPlayers;
	for (int i = 0; i < numberOfPlayers; i++) {
		//We need to print info about ever player here!
	}
};

bool Team::operator== (char* name) {
	if (strcmp(name, name) == 0) {
		return true;
	}
	else {
		return false;
	}

};
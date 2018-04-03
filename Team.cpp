#include <iostream>
#include "Team.h"
#include "Functions.h"
#include "Player.h"


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

bool Team::operator== (char* name1) {
	if (strcmp(name, name1) == 0) {
		return true;
	}
	else {
		return false;
	}

};

void Team::readFromFile() {
    
}

void Team::edit() {
    char answ;
    cout << "Would you like to add or remove a player (a)dd / (d)elete / (Q)uit";
    answ = read();
    int id;
    
    switch (answ) {
        case 'A':
            
            //TODO: CHECK IF THERE IS DUPLICATE NUMBERS
            
            id = read("Player ID", MINID, MAXID);
            
            numberOfPlayers++;
            playerNo.push_back(id);
            
            
            
            break;
            
        case 'D':
            id = read("Player ID", MINID, MAXID);
            
            for (int i = 0; i < numberOfPlayers; i++) {
                if (playerNo[i] == id) {
                    playerNo.erase(playerNo.begin(),playerNo.begin() + i);
                    numberOfPlayers--;
                }
            }
            
            break;
            
        case 'Q': break;
        default: cout << "\nInvalid command."; break;
            
    }
}

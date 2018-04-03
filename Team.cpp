#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include "Team.h"
#include "Functions.h"
#include "Player.h"


Team::Team() {
	//Paramless constructor

};

Team::~Team() {
	delete name;
	delete address;
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

void Team::readFromFile(ifstream &inn) {
	char buffer[STRLEN];
	int tempNumb;
    
	inn.getline(buffer,STRLEN); //Read team name from file
	name = new char[strlen(buffer) + 1]; //Create a new char array
	strcpy(name, buffer); //Copy over from buffer

	inn.getline(buffer, STRLEN); //Read team address from file
	address = new char[strlen(buffer) + 1]; //Create a new char array
	strcpy(address, buffer); //Copy over from buffer

	inn >> tempNumb;
	numberOfPlayers = tempNumb;

	for (int i = 0; i < numberOfPlayers; i++) {
		inn >> buffer;
		inn.ignore();

		if (atoi(buffer)) { //Must be a number
			playerNo.push_back(atoi(buffer));
		}
		else { //Must be a text
			char tempName[STRLEN];
			char tempAddress[STRLEN];

			strcpy(tempName, buffer);

			inn.getline(buffer, STRLEN);

			strcpy(tempAddress, buffer);


			Players* tempPlayers;
			tempPlayers = new Players(players.returnLastId() + 1 , tempName , tempAddress);
			delete tempPlayers;
		}
	}
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

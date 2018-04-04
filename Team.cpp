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
	delete[] name;
	delete[] address;
};

void Team::display() {
	cout << "\nName of the team: " << name
		<< "\nTeam address: " << address
		<< "\nNumber of players on the team: " << numberOfPlayers;
	for (int i = 0; i < numberOfPlayers; i++) {
		//We need to print info about ever player here!
	}
};

bool Team::operator== (char name1[]) {
	if (strcmp(name, name1) == 0) {
		return true;
	}
	else {
		return false;
	}

};

void Team::readFromFile(ifstream &inn) {
	char nameBuffer[STRLEN];
	char addressBuffer[STRLEN];
	char buffer[STRLEN];

	int tempNumb = 0;
    
	inn.getline(nameBuffer,STRLEN); //Read team name from file
	//name = new char[strlen(nameBuffer) + 1]; //Create a new char array
	strcpy(name, nameBuffer); //Copy over from buffer


	inn.getline(addressBuffer, STRLEN); //Read team address from file
	//address = new char[strlen(addressBuffer) + 1]; //Create a new char array
	strcpy(address, addressBuffer); //Copy over from buffer


	inn >> tempNumb;

	numberOfPlayers = tempNumb;
	inn.ignore();

	for (int i = 0; i < numberOfPlayers; i++) {

		inn >> buffer;

		inn.ignore();

		if (atoi(buffer)) { //Must be a number
			playerNo.push_back(atoi(buffer));
		}
		else { //Must be a text
			char tempName[STRLEN];
			char tempAddress[STRLEN];
			cout << endl << buffer;
			strcpy(tempName, buffer);

			inn.getline(buffer, STRLEN);

			strcpy(tempAddress, buffer);


			Player* tempPlayer;
			tempPlayer = new Player(players.returnLastId() + 1, tempName, tempAddress);
			players.addToList(tempPlayer);
			delete tempPlayer;
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

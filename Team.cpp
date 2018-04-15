#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Team.h"
#include "Functions.h"
#include "Player.h"
#include "Division.h"
#include "Players.h"

Team::Team() {
	//Paramless constructor
};

Team::~Team() {
	//Deconstructor
};

void Team::display(bool all) { //Display the team and its players
	cout << "\nName of the team: " << name
		<< "\nTeam address: " << address
		<< "\nNumber of players on the team: " << numberOfPlayers;
	if (all == true) { //Param is true, info about every player will be displayed
		for (int i = 0; i < numberOfPlayers; i++) {
			cout << "\nPlayer number: " << playerNo[i];
			players.displayId(playerNo[i]);
		}
	}
};

bool Team::operator== (char name1[]) { //Compare team name with param
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

	int tempNumb = 0, tempId = 0;
    
	inn.getline(nameBuffer,STRLEN); //Read team name from file
	strcpy(name, nameBuffer); //Copy over from buffer

	inn.getline(addressBuffer, STRLEN); //Read team address from file
	strcpy(address, addressBuffer); //Copy over from buffer

	inn >> tempNumb;

	numberOfPlayers = tempNumb; //Copy over number of players
	inn.ignore();

	for (int i = 0; i < numberOfPlayers; i++) {
		inn >> buffer;
		inn.ignore();
        
		if (atoi(buffer)) { //Must be a number
			playerNo.push_back(atoi(buffer)); //add the player id to the player ID vector
		}
		else { //Must be a text
			char tempName[STRLEN];
			char tempAddress[STRLEN];
			
            strcpy(tempName, buffer);
			inn.getline(buffer, STRLEN);
			strcpy(tempAddress, buffer);

			tempId = players.returnLastId();						//Return the last player ID used. lastID +1

			Player* tempPlayer;										//TempPlayer
			tempPlayer = new Player(tempId, tempName, tempAddress); //Create new player
			players.addToList(tempPlayer);							//And add it to the list

			playerNo.push_back(tempId);								//Add the player id to the Player ID vector
		}
	}

}

void Team::edit() { //Edit a player on the team.
    char answ;
    cout << "Would you like to add or remove a player (a)dd / (d)elete / (Q)uit";
    answ = read();
    int id;
    
    switch (answ) {
        case 'A': //Add a player
			if(playerNo.size() < MAXPLAYERS){ //Dont go over max team limit!
				bool found = false;
				id = read("Player ID", MINID, MAXID);

				for (int i = 0; i < numberOfPlayers; i++) { //Go through and check if ID already exists
					if (playerNo[i] == id) {
						found = true; //We found the player. Dont add another one.
					}
				}

				if (!found) {
					numberOfPlayers++; //Add another player to the team member counter
					playerNo.push_back(id); //Add the player to the player ID Vector
				}
				else {
					cout << "\nPlayer with ID " << id << " already exists on this team";
				}
			}
			else {
				cout << "\nThere are 20 players in the team which is the maximum capacity";
			}

            break;
            
        case 'D': //Delete a player
            id = read("Player ID", MINID, MAXID);
            
            for (int i = 0; i < numberOfPlayers; i++) { //Check to find the correct player id.
                if (playerNo[i] == id) {	//Id was found
                    playerNo.erase(playerNo.begin()+ i); //Go i out from the start in the vector and delete it
                    numberOfPlayers--; //Remove 1 from the team member counter
                }
            }
            break;
            
        case 'Q': break;
        default: cout << "\nInvalid command."; break;
    }
}

void Team::displayName() { //Prints team name to screen
	cout << name;
}

void Team::displayName(ofstream &out) { //Prints team name to file
	out << name;
}

void Team::returnName(char* pointName) { //Returns name to the param pointer
	strcpy(pointName, name);
}

bool Team::compareName(char n[]) { //Compares team name with param
	return (strcmp(name, n) == 0);
}

void Team::writeToFile(ofstream &out) {
	out << name << "\n"					//Writes name of team to file. 
		<< address << '\n'				//Writes name of adress to file.
		<< numberOfPlayers << '\n';		//Writes number of players to file.

	for (int i = 0; i < numberOfPlayers; i++) { //Loop through players in a team and write to file.
		out << playerNo[i] << "\n";				//Writes player number to file
	}
}

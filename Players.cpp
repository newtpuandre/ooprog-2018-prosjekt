#include <iostream>
#include <fstream>

#include "Players.h"
#include "Player.h"
#include "ConstEnum.h"
#include "Functions.h"

using namespace std;

Players::Players() {
	//Create the list containing Player objects. Set type to sorted.
	playerList = new List(Sorted);
};

Players::~Players() {
	Player* delPlayer;
	for (int i = playerList->noOfElements(); i >= 1; i--) { //Start from the back
		delPlayer = (Player*)playerList->removeNo(i); //Remove it from the list
		delete delPlayer; //Delete the current object
	}
}

void Players::New() {
    int playerId;

	playerId = read("Player id", MINID, MAXID);	//Read player ID of new player.

	if (!(playerList->inList(playerId))) {	//If ID is in playerlist..

		if (lastPlayerId < MAXID) {		//..and there is space for more players:
			lastPlayerId = playerId;	//Set ID to last player ID.

			Player* tempPlayer;			//Create temp player.
			tempPlayer = new Player(playerId); //Make it a new instance of a player.
			playerList->add(tempPlayer); //Add the player to the playerlist.
		}
		else { //Give feedback to the user.
			cout << "\nThere is no room for more players.";
		}
	}
	else { //Give feedback to the user.
		cout << "\nPlayer ID " << playerId << " already exist!";
	}
}

void Players::remove() {
	int playerId;
										//Read player ID of desired player.
	playerId = read("\nRemove what player ID?", MINID, MAXID); 

	if (playerList->inList(playerId)) {	//If the player exist in the list..
		playerList->destroy(playerId);	//.. destroy the desired player.
	}
	else { //Give feedback to the user.
		cout << "\n" << playerId << " does not exist in the list.";
	}

}

void Players::display() {
    char temp[STRLEN];
    bool found = false;
    
    cin.getline(temp, STRLEN); //Read a string.
    
    if ((temp[0] == 'A' && strlen(temp) == 1) || (temp[0] == 'a' && strlen(temp) == 1)) {    
	//Check if the first element in the string are an A and the strlen is 2 A + \0
        playerList->displayList();
    }
    
    else if (!atoi(temp)) { //Else if string is number..
        int listLength = playerList->noOfElements(); //Save length of playerlist.
        
        for (int i = 1; i <= listLength; i++) { //For the entire listlength..
            Player* tmpPlayer;	//Remove name 'i' from the list.
            tmpPlayer = (Player*)playerList->removeNo(i); 
            
            if (*tmpPlayer == temp) { //If temp name is equal to players name..
                tmpPlayer->display(); //..displays players data.
                found = true;
            }
            playerList->add(tmpPlayer); //Add the player back to the playerlist.
        }
        if (found == false) { //If the player is not found, give feedback.
            cout << "The name " << temp << " does not exist";
        }
    }
    
    else { //If none of the two checks is correct, it must be a array with numbers
        playerList->displayElement(atoi(temp)); //Display players data by given number.
    }
}

void Players::readFromFile() {	//This function will read player data from
	Player* tempPlayer;			//PLAYERS.DTA
	ifstream inn("PLAYERS.DTA");

	char nameBuffer[STRLEN],addressBuffer[STRLEN];
	int tempNumb, tempId;

	if (inn) {	//If the program is able to read the file..
		inn >> tempNumb; inn.ignore(); //Read number of players, ignore newline.

		for (int i = 0; i < tempNumb; i++) { //Read info for all players.
			inn >> tempId; inn.ignore();	 //PLAYER - PlayerID

			if (tempId > lastPlayerId) {	 //If ID > last ID, update last ID.
				lastPlayerId = tempId;
			}

			inn.getline(nameBuffer, STRLEN); //PLAYER - name
			inn.getline(addressBuffer, STRLEN); //PLAYER - address

			tempPlayer = new Player(tempId,nameBuffer,addressBuffer);
			playerList->add(tempPlayer); //Create a new player with parameters
		}								 //.. and add the player to the playerlist.
	}
	else { //Feedback to user - file not found.
		cout << "\nThe file PLAYERS.DTA does not exist..";
	}
}

int Players::returnLastId() { //Returns lastID+1
	return ++lastPlayerId;
}

void Players::addToList(Element *Element) { //Add player object to list.
	playerList->add(Element);
}

void Players::displayId(int playerId) { //Display a given player ID in playerlist.
	playerList->displayElement(playerId);
}

void Players::writeToFile() { //Write player data to PLAYERS.DTA
	ofstream out("PLAYERS.DTA"); //States filename (static)
	Player* tempPlayer;
	out << playerList->noOfElements(); //PLAYERS - number of players

	for (int i = 1; i <= playerList->noOfElements(); i++) { //Write info for all players
		tempPlayer = (Player*)playerList->removeNo(i); //Remove from list.
		tempPlayer->writeToFile(out); //Call each players write to file function.
		playerList->add(tempPlayer);  //Add player back into the playerlist.
	}
}
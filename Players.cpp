#include <iostream>
#include <fstream>
#include "Players.h"
#include "Player.h"
#include "ConstEnum.h"
#include "Functions.h"

using namespace std;

Players::Players() {
	//Paramless constructor
	//Create the list containing Player objects.
	//Set it to sorted.
	playerList = new List(Sorted);
};

Players::~Players() {
	//Go through the whole playerList and delete every object from the list;

}

void Players::New() {
	//TODO: CHECK IF THE INPUT ALREADY EXIST
    int playerId;
	playerId = read("Player id", MINID, MAXID);

	if (playerId > lastPlayerId && lastPlayerId < 1000) {
		lastPlayerId = playerId;

		Player* tempPlayer; //
		tempPlayer = new Player(playerId);

		playerList->add(tempPlayer);
	}
	else {
		//TODO: GIVE SOMETHING USEFUL FEEDBACK
	}

}

void Players::remove() {
	char playerId[STRLEN];
	cout << "\nWhich player would you like to remove by player id? : ";
	cin >> playerId;

	if (atoi(playerId)) { //Check if it is a number that is typed in.
		if (playerList->inList(atoi(playerId))) {	//Does the player exist in the list?

													//Display the player
													//if user want to remove it
													//Delete()
													//Else
													//Dont()
		}
		else { //Give feedback to the user
			cout << "\n" << playerId << " does not exist in the list.";
		}
	}
	else { //Give feedback to the user
		cout << "\n" << playerId << " is not a number id!";
	}

}

void Players::display() {
    char temp[STRLEN];
    bool found = false;
    
    cin.getline(temp, STRLEN);
    
    if ((temp[0] == 'A' && strlen(temp) == 1) || (temp[0] == 'a' && strlen(temp) == 1)) {    //Check if the first element in the array are an A
        //   and the strlen is 2 A + \0
        playerList->displayList();
    }
    
    else if (!atoi(temp)) {        //Must be a array with letters
        int listLength = playerList->noOfElements();
        
        for (int i = 1; i <= listLength; i++) {
            Player* tmpPlayer;
            tmpPlayer = (Player*)playerList->removeNo(i);    //Remove name 'i' from list.
            
            if (*tmpPlayer == temp) {        //checks if temp name is equal to players name.
                tmpPlayer->display();        //displays players data name by given name.
                found = true;
            }
            playerList->add(tmpPlayer);        //Add player back to list.
        }
        if (found == false) {
            cout << "The name " << temp << " does not exist";
        }
    }
    
    else { //Must be a array with numbers
        playerList->displayElement(atoi(temp));        //Displays players data by given number.
    }
}

void Players::readFromFile() {
	Player* tempPlayer;
	ifstream inn("PLAYERS.DTA");

	char nameBuffer[STRLEN],addressBuffer[STRLEN];
	int tempNumb, tempId;

	if (inn) {
		inn >> tempNumb; inn.ignore();

		for (int i = 0; i < tempNumb; i++) {
			inn >> tempId; inn.ignore();
			inn.getline(nameBuffer, STRLEN); //ReaD Name
			inn.getline(addressBuffer, STRLEN); //Read address

			tempPlayer = new Player(tempId,nameBuffer,addressBuffer);
			playerList->add(tempPlayer);
		}
	}
	else {
		cout << "\nThe file PLAYERS.DTA does not exist..";
	}
}

int Players::returnLastId() {
	return lastPlayerId;
}

void Players::addToList(Element *Element) {
	playerList->add(Element);
}

#include "Players.h"
#include "Player.h"
#include "ConstEnum.h"
#include <iostream>

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
    Player* tempPlayer; //
	tempPlayer = new Player;

    playerList->add(tempPlayer);
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
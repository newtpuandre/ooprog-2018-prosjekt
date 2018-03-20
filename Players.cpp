#include "Players.h"
#include "Player.h"
#include <iostream>

Players::Players() {
	//Paramless constructor
	//Create the list containing Player objects.
	//Set it to sorted.
	List*  playerList;
	playerList = new List(Sorted);
};

Players::~Players() {
	//Go through the whole playerList and delete every object from the list;

}

void Players::New() {
    Player tempPlayer;
    //tempPlayer.returnId();
    playerList->add(tempPlayer.returnId());
}

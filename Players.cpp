#include "Players.h"
#include "Player.h"
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

void Players::display() {
	
	Player* tempPlayer;
	char ch;

	cout << "What players do you want to display? (A | T(EXT) | N(UMBER)) ";
	cin >> ch;

	switch (toupper(ch)) {
		case 'A':   playerList->displayList();
		case 'T':	tempPlayer->display();
		case 'N':	tempPlayer->display();

	}

}

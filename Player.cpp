#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>

#include "Player.h"
#include "Functions.h"
#include "ConstEnum.h"

using namespace std;

Player::Player() {
	//Paramless constructor
	cout << "\nWHEN CREATING A NEW PLAYER IT REQUIRES A ID!!";
};

Player::Player(int id):NumElement(id) { //This function updates parameters..
	number = id;						//.. of a new player.
	char temp[STRLEN];

    read("What's the players name?", temp, STRLEN);
	strcpy(name, temp);

    read("What's the players address?", temp, STRLEN);
	strcpy(address, temp);
};

Player::Player(int id, char* name1, char* address1):NumElement(id) {
	//Constructor - reading from file with parameters.
	number = id;
	strcpy(name, name1);
	strcpy(address, address1);
}

Player::~Player() { //USELESS????
	//Deconstructor
    //delete name;
    //delete address;
}

void Player::display() { //Displays info about a player.
	cout << "\nPlayers name    : " << name << '\n'
		 << "Players address : " << address << '\n';
}

bool Player::operator == (char* objName) { //Compares parameter with the ..
    if (strcmp(name, objName) == 0) {	   //.. players name.
        return true;
    }
    else {
        return false;
    }
}

void Player::writeToFile(ofstream &out) { //Write player data to file 'PLAYERS.DTA'
	out << "\n" << number << "\n" << name << "\n" << address;
}
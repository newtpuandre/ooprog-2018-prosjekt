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

Player::Player(int id):NumElement(id) {

	number = id;

	char temp[STRLEN];

    read("What's the players name?", temp, STRLEN);
	//name = new char[strlen(temp) + 1];
	strcpy(name, temp);

    read("What's the players address?", temp, STRLEN);
	//address = new char[strlen(temp) + 1];
	strcpy(address, temp);
};

Player::Player(int id, char* name1, char* address1):NumElement(id) {
	//Constructor used when reading from file
	number = id;

	//name = new char[strlen(name1) + 1];
	strcpy(name, name1);

	//address = new char[strlen(address1) + 1];
	strcpy(address, address1);
}

Player::~Player() {
	//Deconstructor
    //delete name;
    //delete address;
}

void Player::display() {
	cout << "\nPlayers name    : " << name << '\n'
		 << "Players address : " << address << '\n';
}

bool Player::operator == (char* objName) {
    if (strcmp(name, objName) == 0) {
        return true;
    }
    else {
        return false;
    }
}

#include "Player.h"
#include "Functions.h"
#include "ConstEnum.h"

Player::Player() {
	//Paramless constructor
    read("What's the players name?", name, STRLEN);
    read("What's the players address?", address, STRLEN);
};

Player::~Player() {
	//Deconstructor
    delete[] name;
    delete[] address;
}

void Player::display() {
    
}
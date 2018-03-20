#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 
#include "Player.h"
#include "Functions.h"
#include "ConstEnum.h"
#include <iostream>

using namespace std;

Player::Player() {
	//Paramless constructor
	char temp[STRLEN];

    read("What's the players name?", temp, STRLEN);
	name = new char[strlen(temp) + 1];
	strcpy(name,temp);

    read("What's the players address?", temp, STRLEN);
	address = new char[strlen(temp) + 1];
	strcpy(address, temp);
};

Player::~Player() {
	//Deconstructor
    delete[] name;
    delete[] address;
}

void Player::display() {
	cout << "Players name    : " << name << '\n'
		 << "Players address : " << address << '\n';
}
#include "Sports.h"
#include "Sport.h"
#include "ListTool2B.h"
#include "Functions.h"

Sports::Sports() {
	//Paramless constructor
    //Create the list containing Sport objects.
    //Set it to sorted.
	sportList = new List(Sorted);
};

Sports::~Sports() {
	//Deconstructor
};

void Sports::New() {

	char newName[STRLEN];
	read("Name of the player", newName, STRLEN);

    Sport* tempSport;
    tempSport = new Sport(newName);
    
    sportList->add(tempSport);
};

void Sports::modify(char ch) {


};

void Sports::display() {

};
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
	read("Name of the team", newName, STRLEN);

    Sport* tempSport;
    tempSport = new Sport(newName);
    
    sportList->add(tempSport);
};

void Sports::newDiv() {
    char sportName[STRLEN];
    read("Sport name", sportName, STRLEN);
    
    Sport* tempSport;
    
    if (sportList->inList(sportName)) {
        tempSport = (Sport*)sportList->remove(sportName);
        tempSport->newDiv();
        sportList->add(tempSport);
    }
}

void Sports::modify(char ch) {


};

void Sports::display() {

};

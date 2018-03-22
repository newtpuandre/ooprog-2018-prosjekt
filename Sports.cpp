#include "Sports.h"
#include "Sport.h"
#include "ListTool2B.h"

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
	//TODO: Read in name and send up to textElement constructor

    Sport* tempSport;
    tempSport = new Sport;
    
    sportList->add(tempSport);
};

void Sports::modify(char ch) {


};

void Sports::display() {

};
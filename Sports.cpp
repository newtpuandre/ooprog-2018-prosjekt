#include "Sports.h"
#include "ListTool2B.h"

Sports::Sports() {
	//Paramless constructor
    //Create the list containing Sport objects.
    //Set it to sorted.
	sportList = new List(Sorted);
};

Sports::~Sports() {
	//Deconstructor
}

void Sports:New() {
    Sport* tempSport;
    tempSport = new Sport;
    
    sportList->add(tempSport);
}

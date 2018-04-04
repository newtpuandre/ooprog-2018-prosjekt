#include <iostream>

#include "Sports.h"
#include "Sport.h"
#include "Player.h"
#include "ListTool2B.h"
#include "Functions.h"

using namespace std;

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
    read("Name of the sport", newName, STRLEN);
    
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
    switch (ch) {
        case 'D': displayTeam();    break;
        case 'E': editPlayer();     break;
    }
};

void Sports::display() {
    char temp[STRLEN];
    cin.getline(temp, STRLEN);
    
    if ((temp[0] == 'A' && strlen(temp) == 1) || (temp[0] == 'a' && strlen(temp) == 1)) {//Check if the first element in the array are an A and the strlen is 2 A + \0
        sportList->displayList(); //Display all the elements
    }
    else {
        sportList->displayElement(temp); //Display the element with the name sent in the parameter
    }
};

void Sports::displayTeam() {
    char sport[STRLEN];
    
    Sport* tempSport;
    read("What is the name of the sport", sport, STRLEN);
    if (sportList->inList(sport)) {
        tempSport = (Sport*)sportList->remove(sport);
        tempSport->displayTeam();
        sportList->add(tempSport);
    }
    else {
        cout << "\nThe sport with name " << sport << " does not exist!";
    }
}

void Sports::editPlayer() {
    char sport[STRLEN];
    
    Sport* tempSport;
    read("What is the name of the sport", sport, STRLEN);
    if (sportList->inList(sport)) {
        tempSport = (Sport*)sportList->remove(sport);
        tempSport->editPlayer();
        sportList->add(tempSport);
    }
    else {
        cout << "\nThe sport with name " << sport << " does not exist!";
    }
}

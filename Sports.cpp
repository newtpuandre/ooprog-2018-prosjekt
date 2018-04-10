#include <iostream>
#include <cctype>

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
	if(!sportList->inList(newName)) {
		Sport* tempSport;
		tempSport = new Sport(newName);

		sportList->add(tempSport);

	}
	else {
		cout << "\nThe sport already exist!";
	}
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
		if (sportList->inList(temp)) {
			Sport* tempSport;
			tempSport = (Sport*)sportList->remove(temp);
			tempSport->displayOne();
			sportList->add(tempSport);
		}
		else {
			cout << "\nNo sport with name " << temp << " was found.";
		}
        //sportList->displayElement(temp); //Display the element with the name sent in the parameter
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

void Sports::remove() {
	char sport[STRLEN];
	char answ;

	read("what is the name of the sport", sport, STRLEN);

	if (sportList->inList(sport)) { //If the sport is in the sportslist.
		cout << "\nAre you sure you want to delete this sport? All data within will be permanently lost!! (y/N) ";
		answ = read();
		
		if (toupper(answ) == 'Y') {		//If the user confirms the deletion..
			sportList->destroy(sport);	//.. the sport is destroyed.
		}
		else {
			cout << "\nThe sport '" << sport << "' was not deleted.";
		}
	}
	else {
		cout << "\nThe sport with name " << sport << " does not exist!";
	}
}

void Sports::removeDiv() {
	char sport[STRLEN];

	Sport* tempSport;
	read("What is the name of the sport", sport, STRLEN);

	if (sportList->inList(sport)) {
		tempSport = (Sport*)sportList->remove(sport);
		tempSport->removeDiv();
		sportList->add(tempSport);
	}
	else {
		cout << "\nThe sport with name " << sport << " does not exist!";
	}
}

void Sports::displayResults() {
	char sport[STRLEN];
	Sport* tempSport;

	read("What is the name of the sport", sport, STRLEN);
	tempSport = (Sport*)sportList->remove(sport);
	tempSport->displayResults();
	sportList->add(tempSport);
}

void Sports::schedule() {
    char sport [STRLEN];
    
    Sport* tempSport;
    read("Sport", sport, STRLEN);
    
    if (sportList->inList(sport)) {
        tempSport = (Sport*)sportList->remove(sport); //Remove given sport from list
        tempSport->schedule(); //Display schedule or write schedule to file.
        sportList->add(tempSport); //Add the given sport back to the list.
    }
    else {
        cout << "\nThe sport " << sport << " does not exist!";
    }
}

void Sports::writeTable() {
	char temp[STRLEN];
	Sport* tempSport;

	read("Name of the sport", temp, STRLEN);
	if (sportList->inList(temp)) {
		tempSport = (Sport*) sportList->remove(temp);
		tempSport->writeTable();
		sportList->add(tempSport);
	}
	else {
		cout << "\nNo sport with name " << temp << " found.";
	}
	/*Pseudo code
	ask for sport name
	if inlist{
	remove from list.
	Ask for div name, if not blank remove division and calculate.
	else
	calculate for whole sport

	}
	ask for file name, if blank write to screen
	else
	write to file.

	
	
	*/

}
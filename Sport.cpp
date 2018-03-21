#include "Sport.h"

Sport::Sport() {
	//Paramless constructor
                            //divisionList = new List(Sorted); //Is this the right way to make a divisionlist?

    char temp[STRLEN];
    
    read("What's the name of the sport?", temp, STRLEN);
    text = new char[strlen(temp) + 1];
    strcpy(text, temp);
    
    cout << "What table type does this sport use? A (2-1-0), B (3-1-0), C (3-2-1-0)";
    temp = read(); //Reads tabletype as a single letter.
    tableType = new char[strlen(temp) + 1];
    strcpy(tableType, temp);
};

Sport::~Sport() {
    delete[] text;
    delete tableType; //Should this be reset in any other way?
};

void Sport::display() {

};

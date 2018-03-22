#include "Division.h"
#include "Functions.h"
#include "ListTool2B.h"
#include "Team.h"

Division::Division() {
    //Must be made by reading from file!!
}

Division::Division(char* divName) {
    text = new char [strlen(divName) + 1];
    strcpy(text, divName);
}

Division::~Division() {
	//Deconstructor
};

void Division::New() {

};

void Division::display() {

};

void Division::readFromFile(ifstream &inn) {
    int lastUsed = 1;
    
    inn >> numberOfTeams;
    
    while (lastUsed <= numberOfTeams) {
        team[lastUsed++]->readFromFile();
        //result[lastUsed++]->readFromFile();     //READ SCHEDULE (terminliste)
    }
};

#include <iostream>
#include <cctype>
#include <fstream>

#include "Sports.h"
#include "Sport.h"
#include "Player.h"
#include "ListTool2B.h"
#include "Functions.h"
#include "ConstEnum.h"

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
	else {
		cout << "\n" << sportName << " is not a valid sport.";
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

void Sports::matches() {
	char sport[STRLEN];
	char divi[STRLEN];
	char fileName[STRLEN];
	char date[STRLEN];
	Sport* tempSport;
	read("What is the name of the sport", sport, STRLEN);
	read("What is the name of the division", divi);
	read("Filename including extensions (blank = screen)", fileName);
	read("What date", date, STRLEN);


	if (sportList->inList(sport)) {
		tempSport = (Sport*)sportList->remove(sport);
		tempSport->matches(divi, fileName,	date);
		sportList->add(tempSport);
	}
	else {
		cout << "\nThe sport " << sport << " does not exist!";
	}
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
}

bool Sports::results(bool apply) { //Call from main is false first - will check format. If alright - will run again and apply info.
	char fileName[STRLEN] = "RESULTS.DTA";
    char sportName[STRLEN], divName[STRLEN], date[DATELEN], teamH[STRLEN], teamA[STRLEN];
    int noOfSports = 0, noOfDiv = 0, noOfMatches = 0, homeGoals = 0, awayGoals = 0, buffer = 0, success = 0;
    int homeScorers[STRLEN], awayScorers[STRLEN];
    bool overtime = false, alright = false;
    
    ifstream inn(fileName);

	if (inn) { //The file exists

	inn >> noOfSports;  inn.ignore();	//Read number of sports on file, ignore /n
    
		for (int s = 1; s <= noOfSports; s++) {		//Read results of 'noOfSports'-sports
			inn.getline(sportName, STRLEN);			//Read sportsname
			inn >> noOfDiv;			inn.ignore();	//Read number of divisions on file, ignore /n

			for (int d = 1; d <= noOfDiv; d++) {	//Read results of 'noOfDiv'-divisions within each sport
				inn.getline(divName, STRLEN);		//Read division name
				inn >> noOfMatches;		inn.ignore();	//Read number of matches on file, ignore /n

				for (int m = 1; m <= noOfMatches; m++) {//Read match results for 'noOfMatches'-matches within each divisions
					inn.getline(date, STRLEN);		//RESULT - date
					inn.getline(teamH, STRLEN);		//RESULT - HOMETEAM
					inn.getline(teamA, STRLEN);		//RESULT - AWAYTEAM
					inn >> homeGoals; inn.ignore(); //RESULT - HOMEGOALS
					inn >>awayGoals; inn.ignore();  //RESULT - AWAYGOALS
					inn >> overtime; inn.ignore();	//RESULT - BOOL OVERTIME

                    if (homeGoals != 0) {
						for (int h = 0; h < homeGoals; h++) {	//Read home scorers
							inn >> buffer; inn.ignore();		//HOME SCORERS - player ID
							homeScorers[h] = buffer;	        //HOME SCORERS - place player ID into tray 'j'
						}
					}
					else {
						inn >> buffer; inn.ignore();            //If homeGoals = 0, will read but not store info.
					}
					
					if (awayGoals != 0) {
						for (int a = 0; a < awayGoals; a++) {	//Read away scorers
							inn >> buffer;	inn.ignore();		//AWAY SCORERS - player ID
							awayScorers[a] = buffer;	        //AWAY SCORERS - place player ID into tray 'k'
						}
					}
					else {
						inn >> buffer; inn.ignore();            //If homeGoals = 0, will read but not store info.
					}
     
                    if (apply == false ) { //Used to check file format and contents.
                        alright = sports.checkInfo(sportName, divName, teamH, teamA, date); //return true = everything ok.

                        if (!alright){     //If there is any formatting of content error..
                            cout << "\nERROR IN FILE!!"; //..the program will tell the user..
                            return false;  //..and not update any results.
                        }
                        
                    } else { //If the check above is successful, this will be run to update results.
                        sports.applyInfo(sportName, divName, teamH, teamA, date, homeScorers, awayScorers, homeGoals, awayGoals, overtime);
                        success += 1; //Function above updates all parameters given. This line counts number of results successfully updated.
                        if (success == noOfMatches) { //If all results are successfully updated, the program will tell the user..
                            cout << "\nResults updated!"; // <-
                        }
                        
                    }
				}
			}
		}
	}
    
	else {
		cout << "Couldn't find the file " << fileName << " !!";
	}
    
     return (alright == true && apply == false); //Return to main true if file format and contents are alright AND results are not updated yet.
}

bool Sports::checkInfo(char s[], char d[], char h[], char a[], char date[]) {
	Sport* tempSport;		//Create temp sport.
	bool allGood = false;
    
	if (sportList->inList(s)) { //Returns true if sport exists, will then check..
        tempSport = (Sport*)sportList->remove(s); //Remove sportName from list to check info.
        allGood = tempSport->checkInfo(d, h, a, date); //Will check divName, homeTeams & awayTeams names, date.
        sportList->add(tempSport); //Add sportName back to the list.
		return allGood; //Returns wether or not everything was okey.
	}
    
	else { //If sportName is not in list.
		return allGood; //Return false as some of the data was not okey.
	}

}

void Sports::applyInfo(char s[], char d[], char h[], char a[], char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot) {
    Sport* tempSport;   //Create temp sport.
    
    tempSport = (Sport*)sportList->remove(s); //Remove sportName from list to check info.
    tempSport->applyInfo(d, h, a, date, hArr, aArr, hGoals, aGoals, ot); //Will apply divName, homeTeams & awayTeams names, date.
    sportList->add(tempSport);                //Add sportName back to the list.
    
}

void Sports::readFromFile() {
	Sport* tempSport;
	ifstream inn("SPORTS.DTA");
	int numberOfSports;
	char nameBuffer[STRLEN];

	if (inn) {
		inn >> numberOfSports;	inn.ignore();					//Number of sports are read from file.
        
		for (int i = 1; i <= numberOfSports; i++) {				//Loops through all sports ..
			inn.getline(nameBuffer, STRLEN);					//.. reads the name of the sport ..
			tempSport = new Sport(nameBuffer, inn);				//.. and add the sport to the sport list. 
			tempSport->readFromFile(inn);
			sportList->add(tempSport);
		}

	}
	else
		cout << "File not found";
}

void Sports::writeToFile() {
	Sport* tempSport;
	ofstream out("SPORTS.DTA");

	if (out) {
		
		out << sportList->noOfElements(); //Number of elements in sportlist (number of sports) are written to file. 
		out << '\n';
		for (int i = 1; i <= sportList->noOfElements(); i++) {		//Loops through all sports.
				tempSport = (Sport*)sportList->removeNo(i);			//Remove number i.
				tempSport->writeToFile(out);						//Sport object calls its writeToFile function.
				sportList->add(tempSport);							//Add number i.
		}

	}
	else
		cout << "File not found";
}

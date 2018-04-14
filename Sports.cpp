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
	Sport* tempSport;
	read("What is the name of the sport", sport, STRLEN);

	if (sportList->inList(sport)) {
		tempSport = (Sport*)sportList->remove(sport);
		tempSport->matches();
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

bool Sports::results(bool apply) {
	char fileName[STRLEN] = "RESULTS.DTA";
    char sportName[STRLEN], divName[STRLEN], date[DATELEN], teamH[STRLEN], teamA[STRLEN];
    int noOfSports = 0, noOfDiv = 0, noOfMatches = 0, homeGoals = 0, awayGoals = 0, buffer = 0;
    int homeScorers[STRLEN], awayScorers[STRLEN];
    bool overtime = false, alright = false;
    
    //char* charBuffer;
    //char* charBuffer2;
    
    ifstream inn(fileName);

	if (inn) { //The file exists

	inn >> noOfSports;		inn.ignore();	//Read number of sports on file, ignore /n
    
		for (int s = 1; s <= noOfSports; s++) {		//Read results of 'noOfSports'-sports
			inn.getline(sportName, STRLEN);			//Read sportsname
            //charBuffer = sportName;
			inn >> noOfDiv;			inn.ignore();	//Read number of divisions on file, ignore /n

			for (int d = 1; d <= noOfDiv; d++) {	//Read results of 'noOfDiv'-divisions within each sport
				inn.getline(divName, STRLEN);			//Read division name
                //charBuffer2 = divName;
				inn >> noOfMatches;		inn.ignore();	//Read number of matches on file, ignore /n

				for (int m = 1; m <= noOfMatches; m++) {//Read match results for 'noOfMatches'-matches within each divisions
					inn.getline(date, STRLEN);		//RESULT - date
					inn.getline(teamH, STRLEN);		//RESULT - HOMETEAM
					inn.getline(teamA, STRLEN);		//RESULT - AWAYTEAM
					inn >> homeGoals; inn.ignore();
					inn >>awayGoals; inn.ignore(); //RESULT - les inn hjemmemål og bortemål
					inn >> overtime; inn.ignore();				//RESULT - BOOL OVERTIME
													// ^ABOVE^ 1 = true. 0 = false.
					if (homeGoals != 0) {
						for (int h = 0; h < homeGoals; h++) {	//Read home scorers
							inn >> buffer; inn.ignore();			//HOME SCORERS - player ID
							homeScorers[h] = buffer;	//HOME SCORERS - place player ID into tray 'j'
						}
					}
					else {
						inn >> buffer; inn.ignore(); //Info still need to be read, but not stored.
					}
					
					if (awayGoals != 0) {
						for (int a = 0; a < awayGoals; a++) {	//Read away scorers
							inn >> buffer;	inn.ignore();			//AWAY SCORERS - player ID
							awayScorers[a] = buffer;	//AWAY SCORERS - place player ID into tray 'k'
						}
					}
					else {
						inn >> buffer; inn.ignore(); //Info still need to be read, but not stored.
					}

					//LAG NYE RESULTATER?? //lag nye resultat objekter..
     
                    if (apply == false ) {
                        alright = sports.checkInfo(sportName, divName, teamH, teamA, date); //return true = everything ok.
                        //alright = sports.checkInfo(charBuffer, charBuffer2, teamH, teamA, date); //return true = everything ok.

                        if (!alright){
                            //is false
                            cout << "\nERROR IN FILE!!";
                            return false;
                        }
                    } else {
                        //sports.applyInfo(sportName, divName, teamH, teamA, date);
                        cout << "\nApply == true. Her skal resultater oppdateres.";
                    }
				}
			}
		}
	}
	else {
		cout << "Couldn't find the file " << fileName << " !!";
	}
    
     return (alright == true && apply == false);
}

bool Sports::checkInfo(char s[], char d[], char h[], char a[], char date[]) {
	Sport* tempSport;		//Create temp sport.
	bool allGood = false;
	//bool sportExist = false;
	if (sportList->inList(s)) { //Returns true if sport exists, will then check..
		cout << s << endl;
        tempSport = (Sport*)sportList->remove(s);
        allGood = tempSport->checkInfo(d, h, a, date);	// .. d = divName, h = homeTeam, a = awayTeam
        sportList->add(tempSport);
		return allGood; // DENNE SKAL MULIGENS RETURNERE NOE ANNET..
	}
    
	else {
		return allGood;
	}
	
	//return allGood;
	//return 0;

}

	//Sjekk om følgende stemmer:
	// V 1) Sport, divisjon og lag (hjemme og borte) eksisterer
	// 2) De to lagene har spilt mot hverandre denne dagen
	// 3) Ikke registrert resultat mellom disse to lagene allerede


/*void Sports::readFromFile() {
char sport[STRLEN];
Sport* tempSport;
ifstream inn(SPORTSDTA);

for (int i = 0; i < sportList->noOfElements(); i++) {

if (sportList->inList(sport)) {
tempSport = (Sport*)sportList->remove(sport);
//tempSport->readFromFile();
sportList->add(tempSport);
}
else {
cout << "\nThe sport " << sport << " does not exist!";
}

}
*/

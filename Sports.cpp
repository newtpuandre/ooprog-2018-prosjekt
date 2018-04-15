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

Sports::~Sports() { //Destructor.
	Sport* delSport;
	for (int i = sportList->noOfElements(); i >= 1; i--) { //Start from the back
	delSport = (Sport*)	sportList->removeNo(i); //Remove it from the list
	delete delSport; //Delete the current object
	}
};

void Sports::New() { //Reads parameters for new sport object.
	char newName[STRLEN];

	read("Name of the sport", newName, STRLEN); //Read sportname.

	if (!sportList->inList(newName)) { //If not already inList..
		Sport* tempSport;
		tempSport = new Sport(newName); //Create new sport with given name.

		sportList->add(tempSport); //Add sport to sportsList.
	}
	else {
		cout << "\nThe sport already exist!";
	}
};

void Sports::newDiv() { //Asks what sport the new div will be created under.
	char sportName[STRLEN];

	Sport* tempSport;

	read("Sport name", sportName, STRLEN); //Read sportname.

	if (sportList->inList(sportName)) { //If sport is inList..
		tempSport = (Sport*)sportList->remove(sportName); //Remove it..
		tempSport->newDiv(); //Call for sports new division func..
		sportList->add(tempSport); //And add it back to the sportlist.
	}
	else {
		cout << "\n" << sportName << " is not a valid sport.";
	}
}

void Sports::modify(char ch) { //Extension of main. Directs based on the next char.
	switch (ch) {
	case 'D': displayTeam();    break;
	case 'E': editPlayer();     break;
	}
};

void Sports::display() { //Display all or one given sport.
	char temp[STRLEN];
	cin.getline(temp, STRLEN); //Get string of what to display

	//Check if the first element in the array are an A and the strlen is 2 A + \0
	if ((temp[0] == 'A' && strlen(temp) == 1) || (temp[0] == 'a' && strlen(temp) == 1)) {
		sportList->displayList(); //Display all the elements
	}
	else { //If not - must be a sportname.
		if (sportList->inList(temp)) { //Check if sportname is in sportlist
			Sport* tempSport;
			tempSport = (Sport*)sportList->remove(temp); //Remove sportname.
			tempSport->displayOne(); //Call the given sports displayOne func.
			sportList->add(tempSport); //Add back to the sportList.
		}
		else {
			cout << "\nNo sport with name " << temp << " was found.";
		}
	}
};

void Sports::displayTeam() { //Display a team.
	char sport[STRLEN];

	Sport* tempSport;

	read("What is the name of the sport", sport, STRLEN); //Read sportname.

	if (sportList->inList(sport)) { //If sport is inlist..
		tempSport = (Sport*)sportList->remove(sport); //Remove sport.
		tempSport->displayTeam(); //Call for sports displayTeam func.
		sportList->add(tempSport); //Add back to the sportlist.
	}
	else {
		cout << "\nThe sport with name " << sport << " does not exist!";
	}
}

void Sports::editPlayer() { //Edit a player.
	char sport[STRLEN];

	Sport* tempSport;

	read("What is the name of the sport", sport, STRLEN); //Read sportname.

	if (sportList->inList(sport)) { //If inlist..
		tempSport = (Sport*)sportList->remove(sport); //Remove.
		tempSport->editPlayer(); //Call for the given sports editPlayer func.
		sportList->add(tempSport); //Add back to the sportlist.
	}
	else {
		cout << "\nThe sport with name " << sport << " does not exist!";
	}
}

void Sports::remove() { //Remove a desired sport.
	char sport[STRLEN];
	char answ;

	read("what is the name of the sport", sport, STRLEN); //Read sportname.

	if (sportList->inList(sport)) { //If the sport is in the sportslist.
		cout << "\nAre you sure you want to delete this sport? All data within will be permanently lost!! (y/N) ";
		answ = read();

		if (toupper(answ) == 'Y') {		//Ask for confirmation, if yes..
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

void Sports::removeDiv() { //Remove a desired division.
	char sport[STRLEN];

	Sport* tempSport;

	read("What is the name of the sport", sport, STRLEN); //Read sportname.

	if (sportList->inList(sport)) { //If inlist..
		tempSport = (Sport*)sportList->remove(sport); //Remove sport.
		tempSport->removeDiv(); //Call for given sports removediv func.
		sportList->add(tempSport); //Add sport back to the sportlist.
	}
	else {
		cout << "\nThe sport with name " << sport << " does not exist!";
	}
}

void Sports::matches() { //Display results or write results to file.
	char sport[STRLEN];
	char divi[STRLEN];
	char fileName[STRLEN];
	char date[STRLEN];

	Sport* tempSport;

	read("What is the name of the sport", sport, STRLEN); //Read sport, div,
	read("What is the name of the division", divi);		  //filename and date.
	read("Filename including extensions (blank = screen)", fileName);
	read("What date", date, STRLEN);


	if (sportList->inList(sport)) { //If sport is inlist..
		tempSport = (Sport*)sportList->remove(sport); //Remove.
		tempSport->matches(divi, fileName, date); //Call for the sports matches func..
		sportList->add(tempSport); //.. with the read parameters. Then adds back to list.
	}
	else {
		cout << "\nThe sport " << sport << " does not exist!";
	}
}

void Sports::schedule() { //Display schedule or write schedule to file.
	char sport[STRLEN];

	Sport* tempSport;

	read("Sport", sport, STRLEN); //Read sportname.

	if (sportList->inList(sport)) { //If sport is inlist.
		tempSport = (Sport*)sportList->remove(sport); //Remove given sport from list.
		tempSport->schedule(); //Display schedule or write schedule to file.
		sportList->add(tempSport); //Add the given sport back to the list.
	}
	else {
		cout << "\nThe sport " << sport << " does not exist!";
	}
}

void Sports::writeTable() { //Write the result table to file or screen.
	char temp[STRLEN];

	Sport* tempSport;

	read("Name of the sport", temp, STRLEN); //Read sportname.

	if (sportList->inList(temp)) { //If sport is inlist.
		tempSport = (Sport*)sportList->remove(temp); //Remove it from list.
		tempSport->writeTable(); //Call for the sports writeTable func.
		sportList->add(tempSport); //Add back to the list.
	}
	else {
		cout << "\nNo sport with name " << temp << " found.";
	}
}

bool Sports::results(bool apply) { //Call from main is false first - will check format. 
	char fileName[STRLEN] = "RESULTS.DTA"; //If alright - will run again and apply info.
	char sportName[STRLEN], divName[STRLEN], date[DATELEN], teamH[STRLEN], teamA[STRLEN];
	int noOfSports = 0, noOfDiv = 0, noOfMatches = 0, homeGoals = 0, awayGoals = 0, buffer = 0, success = 0;
	int homeScorers[STRLEN], awayScorers[STRLEN]; //The function reads results from file.
	bool overtime = false, alright = false;

	ifstream inn(fileName);

	if (inn) { //If the file exists..

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
					inn >> awayGoals; inn.ignore(); //RESULT - AWAYGOALS
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

					if (apply == false) { //Used to check file format and contents.
						alright = checkInfo(sportName, divName, teamH, teamA, date); //return true = everything ok.

						if (!alright) {     //If there is any formatting of content error..
							cout << "\nERROR IN FILE!!"; //..the program will tell the user..
							return false;  //..and not update any results.
						}

					}
					else { //If the check above is successful, this will be run to update results.
						applyInfo(sportName, divName, teamH, teamA, date, homeScorers, awayScorers, homeGoals, awayGoals, overtime);
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
	Sport* tempSport;		//Function checks if file has corrupt data. True = everything ok.
	bool allGood = false;	//Create temp sport.

	if (sportList->inList(s)) { //Returns true if sport exists, will then check..
		tempSport = (Sport*)sportList->remove(s); //Remove sportName from list to check info.
		allGood = tempSport->checkInfo(d, h, a, date); //Will check divName, homeTeams & awayTeams names, date.
		sportList->add(tempSport); //Add sportName back to the list.
		return allGood; //Returns wether or not everything was okey.
	}

	else { //If sportName is not in list.
		return allGood; //Return false as some of the data was not ok.
	}

}

void Sports::applyInfo(char s[], char d[], char h[], char a[], char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot) {
	Sport* tempSport;   //Update results, will only pass info further in the data structure.
						//Create temp sport.
	tempSport = (Sport*)sportList->remove(s); //Remove sportName from list to check info.
	tempSport->applyInfo(d, h, a, date, hArr, aArr, hGoals, aGoals, ot); 
	sportList->add(tempSport);                //Will apply divName, homeTeams & awayTeams names, date.
											  //Add sportName back to the list.
}

void Sports::readFromFile() { //Reads sports data from file.
	char nameBuffer[STRLEN];

	Sport* tempSport;

	ifstream inn("SPORTS.DTA");
	int numberOfSports; //Reads numberOfSports.

	if (inn) {
		inn >> numberOfSports;	inn.ignore();		//Number of sports are read from file.

		for (int i = 1; i <= numberOfSports; i++) {	//Loops through all sports ..
			inn.getline(nameBuffer, STRLEN);		//.. reads the name of the sport ..
			tempSport = new Sport(nameBuffer, inn);	//.. and add the sport to the sport list. 
			tempSport->readFromFile(inn);
			sportList->add(tempSport);
		}

	}
	else
		cout << "File not found";
}

void Sports::writeToFile() { //Write sports data to file.
	Sport* tempSport;

	ofstream out("SPORTS.DTA");

	if (out) {
		out << sportList->noOfElements();  
		out << '\n'; //Number of elements in sportlist (number of sports) are written to file.
		for (int i = 1; i <= sportList->noOfElements(); i++) {	//Loops through all sports.
			tempSport = (Sport*)sportList->removeNo(i);	//Remove number i.
			tempSport->writeToFile(out);				//Sport object calls its writeToFile function.
			sportList->add(tempSport);					//Add number i.
		}
	}
	else
		cout << "File not found";
}
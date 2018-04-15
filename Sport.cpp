#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>

#include "ConstEnum.h"
#include "Sport.h"
#include "Functions.h"
#include "Division.h"

using namespace std;

Sport::Sport() {
	//Paramless constructor
	cout << "\nWHEN CREATING A NEW SPORT IS REQUIRES A NAME!!";
};

Sport::Sport(char* name) :TextElement(name) { //New sport, updates TextElement.
	divisionList = new List(Sorted); //New list - divisionList. Type - sorted.
	char temp[STRLEN];

	do { //Set tabletype for the sport.
		read("What table type does this sport use? 1 (2-1-0), 2 (3-1-0), 3 (3-2-1-0)", temp, STRLEN); //Reads tabletype as a single letter.
		switch (atoi(temp)) {
		case 1: table = tableType(a); break;
		case 2: table = tableType(b); break;
		case 3: table = tableType(c); break;
		default: cout << "\nInvalid table type. Try again.."; break;
		}
	} while (atoi(temp) != 1 && atoi(temp) != 2 && atoi(temp) != 3);

};

Sport::Sport(char* name, ifstream &inn) :TextElement(name) {
	divisionList = new List(Sorted); //New list - divisionList. Type - sorted.
	int tempTable;

	inn >> tempTable; inn.ignore();	//Read table type from file, ignores newline.
	switch (tempTable) {
	case 0: table = tableType(a); break;
	case 1: table = tableType(b); break;
	case 2: table = tableType(c); break;
	}

}

void Sport::newDiv() { //Creates new division within the sport.
	char divName[STRLEN];
	char fileName[STRLEN];

	read("Division name", divName, STRLEN); //Read divname and filename.
	read("File name (Including file extension)", fileName, STRLEN);

	ifstream inn(fileName);
	if (!divisionList->inList(divName)) { //If division not already in list..
		if (inn) { //.. and able to read from file..
			Division* tempDivision;
			tempDivision = new Division(divName); //Create new division.
			tempDivision->readFromFile(inn, false); //Read info from file..
			divisionList->add(tempDivision); //.. False = this is not on startup.
		}			//Add the division to the divisionList.
		else {
			cout << "\nCan't find the file with name: " << fileName;
		}

		numberOfDivisions++; //Increment number of divisions.
	}
	else {
		cout << "\nDivision already exist";
	}
}
 
Sport::~Sport() { //FIX
	//delete[] text;
};

void Sport::display() { //Display data for sport object.
	cout << "\n\nName of the sport: " << text;

	switch (table) {
	case a: cout << "\nTable type: 2-1-0"; break;
	case b: cout << "\nTable type: 3-1-0"; break;
	case c: cout << "\nTable type: 3-2-1-0"; break;
	}
	cout << "\nNumber of divisions: " << numberOfDivisions; //..and number of divisions.
	//divisionList->displayList();
};

void Sport::displayOne() { //Display one sport.
	Sport::display();
	divisionList->displayList();
}

void Sport::displayTeam() {//Displays team in a specific sport and division
	char divName[STRLEN];
	Division* tempDiv;

	read("What division", divName, STRLEN); //Read divisionName.

	if (divisionList->inList(divName)) { //If divisionName is in divisionList..
		tempDiv = (Division*)divisionList->remove(divName); //.. remove it..
		tempDiv->displayTeam(); //.. display it..
		divisionList->add(tempDiv);//.. and add it back to the divisionList.
	}
	else {
		cout << "\nThe division with name " << divName << " does not exist";
	}
}

void Sport::editPlayer() { //Add or remove a player.
	char divName[STRLEN];
	Division* tempDiv;

	read("What division", divName, STRLEN); //Read divisionName.

	if (divisionList->inList(divName)) { //If divisionName is in divisionList..
		tempDiv = (Division*)divisionList->remove(divName); //.. remove it..
		tempDiv->editPlayer(); //.. call on divisions editPlayer func..
		divisionList->add(tempDiv); //.. add division back to the divisionList.
	}
	else {
		cout << "\nThe division with name " << divName << " does not exist";
	}
}

void Sport::removeDiv() { //Remove a desired division.
	char divName[STRLEN];
	char answ;

	read("What division", divName, STRLEN); //Read divisionName.

	if (divisionList->inList(divName)) { //If the desired division is in the divisionlist..
		cout << "\nAre you sure you want to delete this division? All data within will be permanently lost!! (y/N) ";
		answ = read();

		if (toupper(answ) == 'Y') {			//Ask for confirmation, if yes..
			divisionList->destroy(divName); //.. the division is destroyed..
			numberOfDivisions--;			//.. and numberOfDivisions is decremented.
		}
		else {
			cout << "\nThe division " << divName << " was not deleted.";
		}
	}
	else {
		cout << "\nThe division with name " << divName << " does not exist!";
	}
}

void Sport::matches(char* divi, char* filename, char* date) { //Display results or write results to file.
	Division* tempDiv;
	
	if (divi[0] == '\0') { //Empty string, calculate for the whole sport.
		for (int i = 1; i <= divisionList->noOfElements(); i++) { 
			tempDiv = (Division*)divisionList->removeNo(i);
			cout << "\nMatches for division: "; tempDiv->displayName(); cout << "\n";
			tempDiv->matches(filename, date);
			divisionList->add(tempDiv);
		} //Loop through divisionList and display all matches in given sport

	}
	else { //Non-empty string, calculate for the given division.
		if (divisionList->inList(divi)) {
			tempDiv = (Division*)divisionList->remove(divi);
			tempDiv->matches(filename, date);
			divisionList->add(tempDiv);
		}
		else {
			cout << "The division " << divi << " does not exist!";
		}
	}
}

void Sport::schedule() { //Display schedule or write the schedule to file.
    char divName[STRLEN];
    
    Division* tempDiv;
    
    read("Division", divName, STRLEN); //Read divisionName.
    
    if (divisionList->inList(divName)) { //If inlist..
        tempDiv = (Division*)divisionList->remove(divName); //.. remove it..
        tempDiv->schedule(); //.. call for divisions schedule func..
        divisionList->add(tempDiv); //.. and add it back to the divisionList.
    }
    else {
        cout << "The division " << divName << " does not exist!";
    }
}

void Sport::writeTable() { //Write the result table to file or screen.
	char fileTemp[STRLEN];
	char divTemp[STRLEN];

	Division* tempDiv;

	read("Division name (Empty string for the whole sport)", divTemp);

	if (strlen(divTemp) == 0) { //Empty string, calculate for the whole sport

		read("Print to file or screen? (empty string = screen)", fileTemp);
		if (strlen(fileTemp) == 0) { //Print to screen
			ofstream out(fileTemp);

			for (int i = 0; i < divisionList->noOfElements(); i++) {
				tempDiv = (Division*)divisionList->removeNo(i + 1);
				tempDiv->writeTable(table, false, out);
				divisionList->add(tempDiv);
			}

		}
		else { //Print to file			
			ofstream out(fileTemp);
			for (int i = 0; i < divisionList->noOfElements(); i++) {
				tempDiv = (Division*)divisionList->removeNo(i + 1);
				tempDiv->writeTable(table, true, out);
				divisionList->add(tempDiv);
			}

		}

	}
	else { //Non-empty string, calculate for a division
		read("Print to file or screen? (empty string = screen)", fileTemp);

		if (strlen(fileTemp) == 0) { //Print to screen
			ofstream out(fileTemp);
			if (divisionList->inList(divTemp)) {//Is inList
				tempDiv = (Division*)divisionList->remove(divTemp);
				tempDiv->writeTable(table, false, out);
				divisionList->add(tempDiv);
			}
			else { //Was not found in the list
				cout << "\nNo division with name " << divTemp << " was found.";
			}

		}
		else { //Print to file
			ofstream out(fileTemp);
			if (divisionList->inList(divTemp)) {//Is inList
				tempDiv = (Division*)divisionList->remove(divTemp);
				tempDiv->writeTable(table, true ,out);
				divisionList->add(tempDiv);
			}
			else { //Was not found in the list
				cout << "\nNo division with name " << divTemp << " was found.";
			}
		}


	}
}

bool Sport::checkInfo(char d[], char h[], char a[], char date[]) { //Check if file has corrupt data.
	bool allGood = false;

	Division* tempDiv;		//Create temp division.
    
	if (divisionList->inList(d)) { //If divName exist, the following will be checked..
        tempDiv = (Division*)divisionList->remove(d);
        allGood = tempDiv->checkInfo(h, a, date); //.. h = homeTeam, a = awayTeam, d = date.
        divisionList->add(tempDiv);
		return allGood; //Returns true if tempDivs checkInfo returns true.
	}
	else {
		return allGood; //Return false
	}
}

void Sport::readFromFile(ifstream &inn) { //Reads data from file.
	char nameBuffer[STRLEN];
	int tempTable;

	Division* tempDiv; //Create temp division.

	inn >> numberOfDivisions; inn.ignore();
	if (numberOfDivisions > 0) { //If number of divisions is above 0.
		for (int i = 1; i <= numberOfDivisions; i++) { //Loops through number of divisions..
			inn.getline(nameBuffer, STRLEN);		//and call divisions readFromFile function.
			tempDiv = new Division(nameBuffer);		//Reads name of division from file..
			tempDiv->readFromFile(inn, true);		//.. and adding the name to division list. 
			divisionList->add(tempDiv);
		}
	}
}

void Sport::writeToFile(ofstream &out) { //Writes sport data to file.
	Division* tempDiv;

	out << text << '\n';				//Writes name of sport out to file. 
	out << table << '\n';				//Writes table type out to file.
	out << numberOfDivisions << '\n';	//Writes out number of divisions in sport. 

	if (numberOfDivisions > 0) { //If the sport has divisions..
		for (int i = 1; i <= numberOfDivisions; i++) { //For all divisions:
				tempDiv = (Division*)divisionList->removeNo(i); //Remove from list.
				tempDiv->writeToFile(out); //Call divisions writeToFile func..
				divisionList->add(tempDiv); //Add back to the list.
		}
	}
}

void Sport::applyInfo(char d[], char h[], char a[], char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot) {
    Division* tempDiv;  //Update results.
                        //Will not need to check inlist. Done in checkInfo.
    tempDiv = (Division*)divisionList->remove(d); //Remove divName from divisionList.
    tempDiv->applyInfo(h, a, date, hArr, aArr, hGoals, aGoals, ot); //Will update result with given parameters.
    divisionList->add(tempDiv);                   //Add the divName back to the divisionList.
    
}


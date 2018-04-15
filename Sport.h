#if !defined(__SPORT_H)
#define  __SPORT_H


#include "ListTool2B.h"
#include "ConstEnum.h"

class Sport : public TextElement {
private:
	int numberOfDivisions = 0; //Number of divisions
	tableType table; //TableType
	List* divisionList;

public:
	//Function declarations need to be here
	Sport();
	Sport(char* name);
	Sport(char* name, ifstream &inn);
	~Sport();
    void newDiv(); //Creates new division within the sport.
	void display();	//Displays data for sport object.
	void displayOne(); //Display one team.
	void displayTeam(); //Displays team in a specific sport and division
    void editPlayer(); //Add or remove a player.
	void removeDiv(); //Remove a desired division.
	void matches(char* divi, char* fileName, char* date); //Display results or write results to file.
    void schedule(); //Display schedule or write the schedule to file.
	void writeTable(); //Write the result table to file or screen.
	bool checkInfo(char d[], char h[], char a[], char date[]); //Check if file has corrupt data. True = everything ok.
	void readFromFile(ifstream &inn); //Reads data from file.
	void writeToFile(ofstream &out); //Write data to file.
    void applyInfo(char d[], char h[], char a[], char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot); //Update results, will only pass info further in the data structure.
};

#endif

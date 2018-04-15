#if !defined(__DIVISION_H)
#define  __DIVISION_H

#include <fstream>
#include <vector>

#include "ListTool2B.h"
#include "ConstEnum.h"
#include "Team.h"
#include "Result.h"

using namespace std;

struct teamTable { //Used when calculating the team standings.
	char teamName[STRLEN];
	int totalScore = 0;
};

class Division : public TextElement {

private:
	int numberOfTeams = 0;	//Number of teams in a division.
	Team* team[MAXTEAM];	//Array with Teams.
	vector< vector<Result*> > results; //Two-dimensional vector with results.

public:
	Division();     //Paramless constructor.
    Division(char* divName); //Sets name for TextElement.
	~Division();    //Destructor.
	void displayName(); //Display divisions name.
	void display(); //Displays data for division object.
	void displayTeam(); //Display info of a given team.
    void readFromFile(ifstream &inn, bool startupRead); //Make and read from desired file.
	void readScheduleStartup(ifstream &inn); //Reads schedule on startup.
    void editPlayer(); //Edit a given player.
	void matches(char* filename,char* date); //Display results or write results to file.
	void displayMatches(char* date); //Displays matches on given date.
	void writeMatches(char fileName[], char* date); //Write results to file. 
    void schedule(); //Display schedule or write schedule to file.
    void displaySchedule(); //Display schedule on screen.
    void writeSchedule(char fileName[STRLEN]); //Write schedule to file.
	void readSchedule(ifstream &inn); //Read schedule from NY_DIV.DTA
	void writeTable(tableType table, bool file, ofstream &out); //Writes a table with the current standings for this division
	void writeTable(teamTable teamtable, ofstream &out); //Writes a table to file with the current standings for this division
	int TabletypeCalc(tableType table, int wlt);  //Finds the table type and returns the correct scoring
	bool checkInfo(char h[], char a[], char date[]); //Check if file has corrupt data. True = everything ok.
	bool matchPlayed(char h[], char a[], char date[]); //Check if the match is played.
	void writeToFile(ofstream &out); //Write division data to file.
	bool teamsExist(char teamName[]); //Checks if a given teamname exists.
    void applyInfo(char h[], char a[], char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool overtime); //Updates results of the 2D result vector.
    int returnTeamNo(char teamName[]); //Return teamNo for a teamName.
};

#endif

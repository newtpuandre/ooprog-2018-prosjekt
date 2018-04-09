#if !defined(__DIVISION_H)
#define  __DIVISION_H

#include <fstream>
#include <vector>

#include "ListTool2B.h"
#include "ConstEnum.h"
#include "Team.h"
#include "Result.h"


class Division : public TextElement {

private:
	//Text derived
	int numberOfTeams = 0;	//Number of teams in a division
	Team* team[MAXTEAM];	//Array with Teams
	//Result** results;		//Matrix with results
    vector< vector<Result*> > results; //Two-dimensional vector with results.
    //vector<Result*> row; //For testing purposes only (!!)
public:
	//Function declarations need to be here
	Division();     //Paramless constructor
    Division(char* divName);
	~Division();    //Destructor
    void New();     //Reads parameters for division object.
	void display(); //Displays data for division object.
	void displayTeam(); //Display a team
    void readFromFile(ifstream &inn); //Make and read from desired file.
    void editPlayer();
	void remove(); //Remove a desired division.
	void displayResults();
    void schedule(); //Display schedule or write schedule to file.
    void displaySchedule(); //Display schedule.
    void writeSchedule(); //Write schedule to file.
};

#endif

#if !defined(__RESULT_H)
#define  __RESULT_H

#include "ConstEnum.h"

class Result {

private:
	//Need to add specific variables for this class
	char date[DATELEN]; //Match date
	int homeGoals = 0;  //Home team goals
	int awayGoals = 0;	//Away team goals
	bool overtime = false; //Did the match enter overtime?
	bool matchPlayed = false; //Is the match played?
	int homeScorers[MAXGOALS]; //Home team scorers Player ID
	int awayScorers[MAXGOALS]; //Away team scorers Player ID

public:
	//Function declarations need to be here
	Result(); //Paramless constructor
    Result(char d[DATELEN]); //New result with date sent as parameter.
	~Result(); //Destructor
	void display();	//Displays data for result object.
	void displayResults(); //Not sure if this is needed yet. 
	bool cmpDate(char ddmm[]); //Checks if the date sent as parameter is the same as its own. 
    void readFromFile(); //Reads schedule from list.
    void displayDate(); //Display the date of the result.
	void convertDate(); //Convert from ÂÂÂÂMMDD to DD/MM
    void convertDate(ofstream &out); //Convert from ÅÅÅÅMMDD to DD/MM
	int returnScore(); //Returns 0 if home won, 1 if away won, 2 if tie, 3 if not played
};

#endif

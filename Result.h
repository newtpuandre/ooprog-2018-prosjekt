#if !defined(__RESULT_H)
#define  __RESULT_H

#include "ConstEnum.h"

class Result {

private:
	//Need to add specific variables for this class
	char date[DATELEN]; //Match date
	int homeGoals = 0;  //Home team goals
	int awayGoals = 0;	//Away team goals
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
	char convertDate(char d[DATELEN]); //Convert from ååååmmdd to dd/mm
};

#endif

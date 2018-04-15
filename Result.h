#if !defined(__RESULT_H)
#define  __RESULT_H

#include "ConstEnum.h"

class Result {

private:
	char date[DATELEN]; //Match date
	int homeGoals = 0;  //Home team goals
	int awayGoals = 0;	//Away team goals
	bool overtime = false; //Did the match enter overtime?
	bool matchPlayed = false; //Is the match played?
	int homeScorers[MAXGOALS]; //Home team scorers Player ID
	int awayScorers[MAXGOALS]; //Away team scorers Player ID

public:
	Result(); //Paramless constructor
    Result(char d[]); //New result with date sent as parameter.
	Result(ifstream &inn); //New result with data from readFromFile.
	~Result(); //Destructor
	void displayResults(); //Display the result of a match
    void displayResults(ofstream &out); //Write the result of a match
	bool cmpDate(char ddmm[]); //Compare date of results with parameter.
    void displayDate(); //Display the date of the result.
	void convertDate(); //Convert date to 'DD/MM' and displays it.
    void convertDate(ofstream &out); //Convert date to 'DD/MM' and write date to file.
	int returnScore(); //Return score for the result, used in points calculation.
	void writeToFile(ofstream &out); //Writes result data to file. 
	void readFromFile(ifstream &inn); //Reads result data from file.
    void applyInfo(char date[], int hArr[], int aArr[], int hGoals, int aGoals, bool ot); //Update info of a result.
    bool returnPlayed(); //Return bool matchPlayed.
};

#endif

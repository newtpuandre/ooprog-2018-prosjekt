#if !defined(__DIVISION_H)
#define  __DIVISION_H

#include "ListTool2B.h"
#include "Team.h"
#include "Result.h"

class Division : public TextElement{

private:
	//Text derived
	int numberOfTeams = 0;	//Number of teams in a division
	Team* team[MAXTEAM];	//Array with Teams
	Result** results;		//Matrix with results
public:
	//Function declarations need to be here
	Division(); //Paramless constructor
	~Division(); //Destructor

	//Function for creating the matrix of results!
};

#endif
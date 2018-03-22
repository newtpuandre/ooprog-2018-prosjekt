#if !defined(__TEAM_H)
#define  __TEAM_H
#include "ConstEnum.h"

class Team {

private:
	char* name;					//Team name
	char* address;				//Team Address
	int numberOfPlayers = 0;	//Amount of players on the team
	int playerNo[MAXPLAYERS];	//Array with player numbers

public:
	//Function declarations need to be here
	Team(); //Paramless constructor
	~Team(); //Destructor
	void display();	//Displays data for team object.
    void readFromFile();
};

#endif

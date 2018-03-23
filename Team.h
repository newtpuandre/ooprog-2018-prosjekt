#if !defined(__TEAM_H)
#define  __TEAM_H
#include "ConstEnum.h"
#include <vector>

class Team {

private:
	char* name;					//Team name
	char* address;				//Team Address
	int numberOfPlayers = 0;	//Amount of players on the team
	//int playerNo[MAXPLAYERS];	//Array with player numbers
    vector<int> playerNo;

public:
	//Function declarations need to be here
	Team(); //Paramless constructor
	~Team(); //Destructor
	void display();	//Displays data for team object.
	bool operator== (char* name);
    void readFromFile();
    void edit();
};

#endif

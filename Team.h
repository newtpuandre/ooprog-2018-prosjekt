#if !defined(__TEAM_H)
#define  __TEAM_H

#include "ConstEnum.h"

#include <vector>

class Team {

private:
	//Char pointers give us memory read error????
	//char* name;					//Team name
	//char* address;				//Team Address

	char name[STRLEN];		//Team name
	char address[STRLEN];	//Team Address

	int numberOfPlayers = 0;	//Amount of players on the team
	//int playerNo[MAXPLAYERS];	//Array with player numbers
    vector<int> playerNo;

public:
	//Function declarations need to be here
	Team(); //Paramless constructor
	~Team(); //Destructor
	void display(bool all);	//Displays data for team object.
	bool operator== (char name1[]);
    void readFromFile(ifstream &inn);
	void edit();
	void displayName();
	void displayName(ofstream &out);
	void returnName(char* pointName);
	bool compareName(char n[]); //Compare parameter with teamname.
};

#endif

#if !defined(__PLAYER_H)
#define  __PLAYER_H

#include "ListTool2B.h"
#include "ConstEnum.h"

class Player : public NumElement {

private:
	char name[STRLEN];		//Player name
	char address[STRLEN];	//Player Address

public:
	Player(); //Paramless constructor.
	Player(int id); //Sets int to ID in NumElement. Reads other player info.
	Player(int id, char* name, char* address); //Constructor, read from file, updates player info.
	~Player(); //Destructor
	void display();	//Displays data for player object.
    bool operator == (char* objName); //Compare name of player with parameter.
	void writeToFile(ofstream &out); //Write player data to file.
};

#endif

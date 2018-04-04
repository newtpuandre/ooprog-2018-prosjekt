#if !defined(__PLAYER_H)
#define  __PLAYER_H

#include "ListTool2B.h"
#include "ConstEnum.h"

class Player : public NumElement {

private:
	//Pointers give a memory read error????????????
	//Need to add specific variables for this class
    //char* name;                   //Player name
    //char* address;                //Player Address


	char name[STRLEN];		//Player name
	char address[STRLEN];	//Player Address
    
public:
	//Function declarations need to be here
	Player(); //Paramless constructor
	Player(int id); //Takes an int and sets ID in NumElement
	Player(int id, char* name, char* address); 	//Constructor used when reading from file
	~Player(); //Destructor
	void display();	//Displays data for player object.;
    bool operator == (char* objName);
};

#endif

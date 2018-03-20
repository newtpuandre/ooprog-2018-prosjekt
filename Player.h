#if !defined(__PLAYER_H)
#define  __PLAYER_H

#include "ListTool2B.h"

class Player : public NumElement{

private:
	//Need to add specific variables for this class

public:
	//Function declarations need to be here
	Player(); //Paramless constructor
	~Player(); //Destructor
    void New(); //Reads parameters for player object.
	void display();	//Displays data for player object.
};

#endif

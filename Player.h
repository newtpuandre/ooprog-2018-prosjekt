#if !defined(__PLAYER_H)
#define  __PLAYER_H

#include "ListTool2B.h"

class Player : public NumElement{

private:
	//ID derived from NumElement
	char* name; //Pointer to name char array
	char* address; //pointer to address char array
public:
	//Function declarations need to be here
	Player(); //Paramless constructor
	~Player(); //Destructor

};

#endif
#if !defined(__PLAYERS_H)
#define  __PLAYERS_H
#include "ListTool2B.h"

class Players {

private:
	List* playerList;
public:
	Players(); //Paramless constructor
	~Players(); //Destructor
    void New(); //Reads parameters for new player object.
	void remove(); //Removes a user by id
};

#endif

#if !defined(__PLAYERS_H)
#define  __PLAYERS_H
#include "ListTool2B.h"

class Players {

private:
	int lastPlayerId;
	List* playerList;
public:
	Players(); //Paramless constructor
	Players(int id, char* name1, char* address1);
	~Players(); //Destructor

    void New(); //Reads parameters for player object.
	void display(); //Displays players.
	void remove();
	int returnLastId();
};

#endif

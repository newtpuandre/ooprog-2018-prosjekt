#if !defined(__PLAYERS_H)
#define  __PLAYERS_H

#include "ListTool2B.h"

class Players {

private:
	int lastPlayerId = 0;
	List* playerList;
public:
	Players(); //Paramless constructor
	~Players(); //Destructor

    void New(); //Reads parameters for player object.
	void display(); //Displays players.
	void remove(); //Remove a desired player.
	void addToList(Element *Element);
	void readFromFile();
	void displayId(int playerId);
	int returnLastId();
	void writeToFile(); //Write players to PLAYERS.DTA File
};

#endif

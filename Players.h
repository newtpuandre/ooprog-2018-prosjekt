#if !defined(__PLAYERS_H)
#define  __PLAYERS_H

#include "ListTool2B.h"

class Players {

private:
	int lastPlayerId = 0;
	List* playerList;

public:
	Players(); //Paramless constructor, creates new playerlist.
	~Players(); //Destructor
    void New(); //Creates new player object.
	void display(); //Displays players.
	void remove(); //Remove a desired player.
	void addToList(Element *Element); //Add player object to playerlist.
	void readFromFile(); //Read player data from 'PLAYERS.DTA'
	void displayId(int playerId); //Display info of player <ID>
	int returnLastId(); //Return last ID(+1)
	void writeToFile(); //Write player data to 'PLAYERS.DTA' File
};

#endif

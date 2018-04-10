#if !defined(__SPORT_H)
#define  __SPORT_H

#include "ListTool2B.h"
#include "ConstEnum.h"

class Sport : public TextElement {
private:
	//char* sportName; //Name of the sport

	int numberOfDivisions = 0; //Number of divisions
	tableType table; //TableType
	List* divisionList;

public:
	//Function declarations need to be here
	Sport();
	Sport(char* name);
	~Sport();
    void newDiv(); //Creates new division within the sport.
	void display();	//Displays data for sport object.
	void displayOne(); //Display one team.
	void displayTeam(); //Displays team in a specific sport and division
    void editPlayer(); //Add or remove a player.
	void removeDiv(); //Remove a desired division.
	void displayResults();
    void schedule(); //Display schedule or write the schedule to file.
	void writeTable(); //Write the result table to file or screen.
};

#endif

#if !defined(__SPORT_H)
#define  __SPORT_H

#include "ListTool2B.h"
#include "ConstEnum.h"

class Sport : public TextElement {
private:
	//char* sportName; //Name of the sport
	tableType table; //TableType
	List* divisionList;

public:
	//Function declarations need to be here
	Sport();
	Sport(char* name);
	~Sport();
	void display();	//Displays data for sport object.
};

#endif

#if !defined(__SPORTS_H)
#define  __SPORTS_H

#include "ListTool2B.h"

class Sports {

private:
	List* sportList;

public:
	//Function declarations need to be here
	Sports(); //Paramless constructor
	~Sports(); //Destructor
    void New(); //Reads parameters for new sport object.
    void newDiv(); //Asks what sport the new div will be created under.
	void modify(char ch);
	void display();
    void displayTeam();
    void editPlayer();
	void remove(); //Remove a desired sport.
	void removeDiv(); //Remove a desired division.
	void displayResults(); //.fdafd
    void schedule(); //Display schedule or write schedule to file.
};

#endif

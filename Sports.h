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
};

#endif

#if !defined(__DIVISION_H)
#define  __DIVISION_H

#include "ListTool2B.h"

class Division : public TextElement{

private:
	//Need to add specific variables for this class

public:
	//Function declarations need to be here
	Division(); //Paramless constructor
	~Division(); //Destructor
    void New(); //Reads parameters for division object.
	void display(); //Displays data for division object.
};

#endif

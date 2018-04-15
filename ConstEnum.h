#if !defined(__CONSTENUM_H)
#define  __CONSTENUM_H

//Constants
using namespace std;

const int STRLEN = 80; //Defined length for strings.
const int SHORTDATE = 6; //For use when four-digit dates are present. (DD/MM)
const int DATELEN = 9; //For use when eight-digit dates are present. (≈≈≈≈MMDD)
const int MAXTEAM = 20;
const int MAXPLAYERS = 50;
const int MAXGOALS = 50;
const int MINID = 1;		//Interval where player ID is defined.
const int MAXID = 1000;		//Interval where player ID is defined.

enum tableType {a,b,c}; //a = "2-1-0, b = "3-1-0", c= "3-2-1-0"
#endif

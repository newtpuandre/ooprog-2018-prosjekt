#if !defined(__CONSTENUM_H)
#define  __CONSTENUM_H

//Constants
/// Filenames are defined as consts for easier administration.

using namespace std;

const int NAMELEN = 80;
const int STRLEN = 80;
const int DATELEN = 9;
const int MAXTEAM = 20;
const int MAXPLAYERS = 50;
const int MAXGOALS = 50;
const int MINID = 1;
const int MAXID = 1000;

const char PLAYERSDTA[] = "PLAYERS.DTA";
const char SPORTSDTA[] = "SPORTS.DTA";
const char NEWDIVDTA[] = "NEWDIVISION.DTA";
const char RESULTSDTA[] = "RESULTS.DTA";
const char SCHEDULEDTA[] = "SCHEDULE.DTA";
const char MATCHDATEDTA[] = "MATCHDATE.DTA";
const char STANDINGSDTA[] = "STANDINGS.DTA";


enum tableType {a,b,c}; //a = "2-1-0, b = "3-1-0", c= "3-2-1-0"
#endif

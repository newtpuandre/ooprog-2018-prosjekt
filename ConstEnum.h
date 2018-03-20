#if !defined(__CONSTENUM_H)
#define  __CONSTENUM_H

//Constants
/// Filenames are defined as consts for easier administration.

const int NAMELEN = 80;
const int STRLEN = 80;
const int DATELEN = 9;
const int MAXTEAM = 20;
const int MAXPLAYERS = 50;
const int MAXGOALS = 50;

const char PLAYERS.DTA[] = "PLAYERS.DTA";
const char SPORTS.DTA[] = "SPORTS.DTA";
const char NEWDIV.DTA[] = "NEWDIVISION.DTA";
const char RESULTS.DTA[] = "RESULTS.DTA";
const char SCHEDULE.DTA[] = "SCHEDULE.DTA";
const char MATCHDATE.DTA[] = "MATCHDATE.DTA";
const char STANDINGS.DTA[] = "STANDINGS.DTA";


//Enum
enum tableType { 2-1-0, 3-1-0, 3-2-1-0 }

#endif

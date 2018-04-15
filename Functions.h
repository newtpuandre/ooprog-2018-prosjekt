#if !defined(__FUNCTIONS_H)
#define  __FUNCTIONS_H

#include "Players.h"
#include "Sports.h"

extern Players players;
extern Sports sports;

//Function declarations
void writeMenu(); //Write main menu and menu description.
char read(); //Reads a single char letter.
void read(const char t[], char s[], const int LEN); //Reads non-empty text.
void read(const char t[], char s[]); //Print text and allows for reading an empty text.
int read(const char t[], const int min, const int max); //Read int within interval.
void New(); //Creates new instance of desired object.
void remove(); //Removes a player.

#endif

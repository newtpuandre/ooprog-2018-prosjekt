#if !defined(__FUNCTIONS_H)
#define  __FUNCTIONS_H

//Function declarations
void writeMenu();
char read(); //Reads a single char letter.
void read(const char t[], char s[], const int LEN); //Reads non-empty text
int read(const char t[], const int min, const int max); //Read int in interval


#endif

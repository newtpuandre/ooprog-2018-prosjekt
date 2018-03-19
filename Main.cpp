/*
 NOTE: This is the initial version of main heavily influenced by Frode.
 Please note the comments below. In my opinion, we should discuss the brief setup shortly.
 
 xoxo,
 S <3

 EDIT: 19.03.2018:
 I commented out everything that is NYI so we can run the program compiles.
 We need to uncomment the NYI functions later.
 Should we restructure the switch and main?
 */


#include <iostream>
#include "ListTool2B.h"
#include "Sports.h"
#include "Players.h"
#include "Functions.h"

//Classes
Sports sports;
Players players;

using namespace std;

int main() {
    char ch;
    
   // players.readFromFile();
   // sports.readFromFile();
    
    writeMenu();
    ch = read();        // Reads one character
    while (ch != 'Q') {
        switch (ch) {   // Should we rename the switch cases as we are coding in english? Maybe we should ask the student assistants..?
            case 'S': /*players.display();  */      break;
            case 'I': /*sports.display();   */      break;
            case 'N':/* new();*/                    break;
            case 'F': /*remove(); */                break;
            case 'L':
            case 'K':
            case 'C':
            case 'T': /*sports.write(ch); */        break;
            case 'R':/* if (sports.results(false))
                          sports.results(true);*/ break;
            case 'D':
            case 'E': /*sports.modify(ch);*/        break;
            case 'B':                           break; //Isn't this an optional task?
            default: writeMenu();
        }
        ch = read();
    }
    // players.writeToFile();
    // sports.writeToFile();
    cout << "\n\n";
	return 0;
}
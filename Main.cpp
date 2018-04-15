#include <iostream>
#include <cctype>

#include "ListTool2B.h"
#include "Sports.h"
#include "Players.h"
#include "Functions.h"
#include "Result.h"

//Classes
Sports sports;
Players players;

using namespace std;

int main() {
    char ch;
    
   players.readFromFile();	//Read data about players from PLAYERS.DTA
   sports.readFromFile();	//Read data about sports from SPORTS.DTA

    writeMenu();			//Display menu with descriptions of each function.
    ch = read();			//Reads one character - menu choice
    ch = toupper(ch);
    while (ch != 'Q') {
        switch (toupper(ch)) {
            case 'S': players.display();            break;
            case 'I': sports.display();             break;
            case 'N': New();				        break;
            case 'F': remove();                     break;
            case 'L': sports.schedule();            break;
			case 'K': sports.matches();		        break;
			case 'C': /*Voluntary task*/            break;
            case 'T': sports.writeTable();          break;
			case 'R': if (sports.results(false))
						  sports.results(true);		break;
            case 'D':
            case 'E': sports.modify(ch);            break;
            default: writeMenu();
        }
		cout << "\nCommand:  ";
        ch = read();
    }
    players.writeToFile();	//Write data about players to PLAYERS.DTA
	sports.writeToFile();	//Write data about sports to SPORTS.DTA
    cout << "\n\n";

	return 0;
}

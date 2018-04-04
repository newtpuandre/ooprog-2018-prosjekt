#include <iostream>
#include <cctype>

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
    
   players.readFromFile();
   // sports.readFromFile();

    writeMenu();
    ch = read();        // Reads one character
    ch = toupper(ch);
    while (ch != 'Q') {
        switch (toupper(ch)) {   // Should we rename the switch cases as we are coding in english? Maybe we should ask the student assistants..?
            case 'S': players.display();    break;
            case 'I': sports.display();     break;
            case 'N': New();				break;
            case 'F': remove();             break;
            case 'L':
            case 'K':
            case 'C':
            case 'T': /*sports.write(ch); */        break;
            case 'R':/* if (sports.results(false))
                          sports.results(true);*/   break;
            case 'D':
            case 'E': sports.modify(ch);    break;
            case 'B':						break; //Isn't this an optional task?
            default: writeMenu();
        }
		cout << "\nCommand:  ";
        ch = read();
    }
    // players.writeToFile();
    // sports.writeToFile();
	
    cout << "\n\n";
	return 0;
}

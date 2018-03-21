#include <iostream>
#include "Functions.h"

using namespace std;

//Function definitions
void writeMenu() {
    cout << "\n\nAVAILABLE COMMANDS:"
         << "\n\tS A | <no> | <name> - Display all players | Display player no | Display name"
         << "\n\tI A | <name> - Display all sports | Display sport with name"
         << "\n\tN S | I | D - New player | New sport | New division"
         << "\n\tF S | I | D - Remove player | Remove sport | Remove division"
         << "\n\tL - Display schedule or write schedule to file"
         << "\n\tK - Display, or write to file, all the matches on a given date for a sport/ division"
         << "\n\tT - Display, or write to file, sport standings or league standings"
         << "\n\tR - Read reasults from file"
         << "\n\tD - Display data about a player, sport or division"
         << "\n\tE - Edit players within a team"
         << "\n\tQ - Quit / avslutt";
}

char read() { //Reads a single char letter.
    char ch;
    cout << "\n\nCommand:  ";
    cin >> ch;  cin.ignore();
    return (toupper(ch));
}

void read(const char t[], char s[], const int LEN) { //Print text and reads non-empty text.
    do {
        cout << t << ": "; cin.getline(s, LEN);
    } while (strlen(s) == 0);
}

int read(const char t[], const int min, const int max) { //Reads an int in given interval.
    int n;
    do {
        cout << '\t' << t << " (" << min << '-' << max << "): ";
        cin >> n; cin.ignore();
    } while (n < min || n > max);
    return n;
}

void New() { //Defines what object to create a new instance of.
    char ch;
	cin >> ch;
    switch (ch) {
	case 'S':	players.New();    break;
    case 'I':   sports.New();     break;
       // case 'D': divisions.new();  break;
    }
}

void remove() {
	char ch;
	cin >> ch;
	switch (ch) {
	case 'S': players.remove(); break;
	//case 'I': sports.remove(); break;
	//case 'D': divisions.remove(); break;
	}

}
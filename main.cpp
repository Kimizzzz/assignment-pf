#include <iostream>
#include <limits>

#include "includes/display.h"
#include "includes/helpers.h"
#include "includes/settingsLogic.h"
#include "includes/Alien.h"
#include "includes/Board.h"

using namespace std;

int main(){

    Alien a;
    
    clearScreen();

    bool flag = true;

    while(flag){ // sets the game loop
        
        setDisplay(); // sets the graphical diaplay of the game
        clearScreen();
        mainMenuDisplay();

        int choice;

        cin >> choice;  // gets user input

        cout << endl;

        while(cin.fail()) // checks for invalid input by user e.g. a character input by user when supposed to be integer
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            clearScreen();
            cout << "Bad entry. Please Enter A Number!  ";
            cout << endl;
            mainMenuDisplay();
            cin >> choice;
        }

        if(choice == 1){ // play game
            clearScreen();
            Board newGameBoard(stoi(boardRowCount()), stoi(boardColumnCount()));
            newGameBoard.createBoard();
            displayAlienAttributes();
            break;
        }
        else if(choice == 2){ // settings
            clearScreen();
            settingsDisplay();
            settingsInput();
        }
        else if(choice == 3){ // quit game
            resetDisplay();
            clearScreen();
            quitGameDisplay();
            flag = false;
            break;
        }
        else{ // checks for a valid input
            clearScreen();
            cout << "Please enter a valid response!";
            cout << endl;
        }
        
    }
    resetDisplay();
    return 0;
}
// to compile 
// g++ main.cpp includes/display.cpp includes/helpers.cpp includes/settingsLogic.cpp includes/Board.cpp includes/Alien.cpp includes/GameObject.cpp -o main
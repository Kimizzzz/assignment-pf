#include <iostream>
#include <limits>

#include "includes/display.h"
#include "includes/helpers.h"
#include "includes/settingsLogic.h"
#include "includes/Alien.h"
#include "Board.h"

using namespace std;

int main(){
    Alien a;
    cout << "Starting life: " << a.getLife() << endl;
    cout << "Starting attack: " << a.getAttack() << endl;

    // set new values for life and attack
    a.setLife(50);
    a.setAttack(25);

    cout << "New life: " << a.getLife() << endl;
    cout << "New attack: " << a.getAttack() << endl;
    
    clearScreen();

    bool flag = true;

    while(flag){ // game loop

        mainMenuDisplay();

        int choice;

        cin >> choice;  // gets user input

        cout << endl;

        while(cin.fail())
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

// to compile 
// g++ main.cpp includes/display.cpp includes/helpers.cpp includes/settingsLogic.cpp Board.cpp includes/Alien.cpp includes/GameObject.cpp -o main


    return 0;
}

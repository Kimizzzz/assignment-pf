#include <iostream>

#include "includes/display.h"
#include "includes/helpers.h"
#include "includes/settingsLogic.h"
#include "includes/Alien.h"
#include "includes/board.h"

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

        char choice;

        cin >> choice;  // gets user input

        cout << endl;

        if(choice == '1'){ // play game
            clearScreen();
            createBoard(stoi(boardRowCount()), stoi(boardColumnCount()));
            displayAlienAttributes();
            break;
        }
        else if(choice == '2'){ // settings
            clearScreen();
            settingsDisplay();
            settingsInput();
        }
        else if(choice == '3'){ // quit game
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
// g++ main.cpp includes/display.cpp includes/helpers.cpp includes/settingsLogic.cpp includes/board.cpp includes/Alien.cpp -o main


    return 0;
}

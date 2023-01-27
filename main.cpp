#include <iostream>

#include "includes/display.h"
#include "includes/helpers.h"
#include "includes/settingsLogic.h"


using namespace std;

int main(){
    
    clearScreen();

    bool flag = true;

    while(flag){ // game loop

        mainMenuDisplay();

        char choice;

        cin >> choice;  // gets user input

        cout << endl;

        if(choice == '1'){ // play game
            clearScreen();
            drawBoard(stoi(boardRowCount()), stoi(boardColumnCount()));
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
// g++ main.cpp includes/display.cpp includes/helpers.cpp includes/settingsLogic.cpp -o main

    return 0;
}

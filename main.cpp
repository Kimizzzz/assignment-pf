// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#include <iostream>
#include <limits>

#include "includes/display.h"
#include "includes/helpers.h"
#include "includes/settingsLogic.h"
#include "includes/Alien.h"
#include "includes/Board.h"
#include "includes/Zombie.h"

using namespace std;

int main(){
    
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

            // create necessary variables
            int gameBoardRow = stoi(boardRowCount());
            int gameBoardColumn = stoi(boardColumnCount());
            const int zombieCount = stoi(getZombieCount());

            // creates a Board object
            Board newGameBoard(gameBoardRow, gameBoardColumn);

            // creates an Alien instance
            Alien myAlien(newGameBoard.xCenter, newGameBoard.yCenter);

            // creates an array of Zombie class instances
            Zombie zombie[zombieCount + 1];
            for(int i = 1; i < zombieCount + 1; i++)
            {
                zombie[i];
            }
            
            // initializes an array of Zombie positions            
            int zombiePosArr[zombieCount][2];

            // fills in the array of Zombie positions
            setZombiePos(zombiePosArr, zombieCount, gameBoardRow, gameBoardColumn);

            // assigns each created Zombie their respective x position and y position
            for(int i = 1; i < zombieCount + 1; i++){
                for(int j = 0; j < 1; j++){
                    zombie[i].xPos = zombiePosArr[i - 1][j];
                    zombie[i].yPos = zombiePosArr[i - 1][j + 1];
                }
            }

            // creates a new gameboard
            newGameBoard.createBoard(zombiePosArr, zombieCount);
            
            // reassigns each Zombie char 'Z' with their respective number based on their positions
            for(int i = 1; i < zombieCount + 1; i++){
                for(int j = 0; j < 1; j++){
                    newGameBoard.paintBoard(zombie[i].xPos, zombie[i].yPos, i);
                }
            }

            cout << endl;
            
            // draws the final gameboard
            newGameBoard.drawBoard();
            
            cout << endl;

            // displays Alien attributes
            myAlien.displayAlienAttributes();

            cout << endl;
            
            // displays zombie attributes
            for(int i = 1; i < zombieCount + 1; i++){
                for(int j = 0; j < 1; j++){
                    zombie[i].displayZombieAttributes(i);
                }
            }
            // enters the game
            
            bool gameOver = false;
            while(!gameOver){

                clearScreen();

                cout << endl;
            
                // draws the final gameboard
                newGameBoard.drawBoard();
                
                cout << endl;

                // displays Alien attributes
                myAlien.displayAlienAttributes();

                cout << endl;
                
                // displays zombie attributes
                for(int i = 1; i < zombieCount + 1; i++){
                    for(int j = 0; j < 1; j++){
                        zombie[i].displayZombieAttributes(i);
                    }
                }
                cout << endl;

                // alien moves
                indent3();
                cout << "Alien has moved" << endl;
                cout << endl;
                indent3();
                system("pause");
                cout << endl;
                // code to make alien move goes here, to be added


                // zombie takes turn moving

                for(int i = 1; i < zombieCount + 1; i++){

                    int myArrX[zombieCount];
                    for(int i = 0; i < zombieCount; i++){
                        myArrX[i] = zombie[i + 1].xPos;
                    }

                    int myArrY[zombieCount];
                    for(int i = 0; i < zombieCount; i++){
                        myArrY[i] = zombie[i + 1].yPos;
                    }

                    int alienXPos = myAlien.alienXPos;
                    int alienYPos = myAlien.alienYPos;

                    char ch = '0' + i;
                    
                    int axis = Zombie::getRandomAxisMovement();  // determined what axis the zombie will move, X or Y

                    int oriX = zombie[i].xPos;
                    int oriY = zombie[i].yPos;

                    if(axis == 1){ // zombie moves along the X axis
                        clearScreen();
                        zombie[i].xPos = Zombie::randomXChange(zombie[i].xPos, zombie[i].yPos, alienXPos, alienYPos, myArrX, myArrY);  // moves the zombie left, right or no movement
                        newGameBoard.updateZombiePos(zombie[i].xPos, zombie[i].yPos, ch);  // updates the new zombie position to the gameboard
                        cout << endl;
                        newGameBoard.drawBoard(); // draws the gameboard
                        cout << endl;
                        myAlien.displayAlienAttributes(); // displays alien attributes
                        cout << endl;
                        for(int i = 1; i < zombieCount + 1; i++){ // displays zombie attributes
                            for(int j = 0; j < 1; j++){
                                zombie[i].displayZombieAttributes(i);
                            }
                        }
                        cout << endl;
                        indent3();
                        zombieMessageX(zombie[i].xPos, oriX, i);  // prints out message about where the zombie has moved
                        
                    }else if(axis == 2){ // zombie moves along the Y axis
                        clearScreen();
                        zombie[i].yPos = Zombie::randomYChange(zombie[i].xPos, zombie[i].yPos,alienXPos, alienYPos, myArrX, myArrY);  // moves the zombie up, down or no movement
                        newGameBoard.updateZombiePos(zombie[i].xPos, zombie[i].yPos, ch);  // updates the new zombie position to the gameboard
                        cout << endl;
                        newGameBoard.drawBoard();  // draws the gameboard
                        cout << endl;
                        myAlien.displayAlienAttributes();  // displays alien attributes
                        cout << endl;
                        for(int i = 1; i < zombieCount + 1; i++){  // displays zombie attributes
                            for(int j = 0; j < 1; j++){
                                zombie[i].displayZombieAttributes(i);
                            }
                        }
                        cout << endl;
                        indent3();
                        zombieMessageY(zombie[i].yPos, oriY, i);  // prints out message where the zombie has moved

                    }
                    cout << endl << endl;
                    indent3();
                    system("pause");
                }
            }
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
// g++ main.cpp includes/display.cpp includes/helpers.cpp includes/settingsLogic.cpp includes/Board.cpp includes/Alien.cpp includes/GameObject.cpp includes/Zombie.cpp includes/saveLoadQuit.cpp -o main
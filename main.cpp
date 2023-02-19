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

            // simulate a collision with a health pod
            myAlien.collisionWithHealth();

            // simulate a collision with arrow
            myAlien.collisionWithArrow('^');
            myAlien.collisionWithArrow('v');
            myAlien.collisionWithArrow('<');
            myAlien.collisionWithArrow('>');

            // simulate a collision with rock
            myAlien.collisionWithRock();

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

            string trophy;
            
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


                // receives player command

                string choice = prompt();
                if(choice == "up"){
                    int yLimit = (gameBoardRow * 2) + 1;
                    while(myAlien.alienYPos > 2){
                        myAlien.alienYPos = Alien::alienUpMove(myAlien.alienYPos);


                        ///////////////////////////////
                        // checks if collide with a zombie
                        if(Board::checkBoard(myAlien.alienXPos, myAlien.alienYPos)){
                            myAlien.alienYPos = myAlien.alienYPos + 2;

                            // gets which zombie the alien crashed into
                            int zombieNum = Board::checkZombie(myAlien.alienXPos, myAlien.alienYPos - 2) - '0';

                            // deducts the zombies health accordingly
                            int newZombieLife = deductZombieHealth(myAlien.attack, zombie[zombieNum].life);
                            zombie[zombieNum].life = newZombieLife;
                            cout << endl;
                            indent3();
                            cout << "Alien crashes into Zombie " << zombieNum << endl;
                            indent3();
                            cout << "Zombie " << zombieNum << " lost " << myAlien.attack << " life" << endl;


                            if(zombie[zombieNum].life <= 0){
                                indent3();
                                cout << "Zombie " << zombieNum << " is defeated!";
                                cout << endl;
                                zombie[zombieNum].status = "dead";
                                zombie[zombieNum].xPos = 0;
                                zombie[zombieNum].yPos = 0;
                                Board::removeZombie(zombieNum);
                            }

                            
                            cout << endl;
                            indent3();
                            system("pause");
                            break;
                        }
                        Board::alienTrail(myAlien.alienXPos, myAlien.alienYPos);


                    }
                }else if(choice == "down"){
                    int yLimit = (gameBoardRow * 2) + 1;
                    while(myAlien.alienYPos < yLimit - 2){
                        myAlien.alienYPos = Alien::alienDownMove(myAlien.alienYPos);

                        ///////////////////////////////
                        // checks if collide with a zombie
                        if(Board::checkBoard(myAlien.alienXPos, myAlien.alienYPos)){
                            myAlien.alienYPos = myAlien.alienYPos - 2;

                            // gets which zombie the alien crashed into
                            int zombieNum = Board::checkZombie(myAlien.alienXPos, myAlien.alienYPos + 2) - '0';

                            // deducts the zombies health accordingly
                            int newZombieLife = deductZombieHealth(myAlien.attack, zombie[zombieNum].life);
                            zombie[zombieNum].life = newZombieLife;
                            cout << endl;
                            indent3();
                            cout << "Alien crashes into Zombie " << zombieNum << endl;
                            indent3();
                            cout << "Zombie " << zombieNum << " lost " << myAlien.attack << " life" << endl;


                            if(zombie[zombieNum].life <= 0){
                                indent3();
                                cout << "Zombie " << zombieNum << " is defeated!";
                                cout << endl;
                                zombie[zombieNum].status = "dead";
                                zombie[zombieNum].xPos = 0;
                                zombie[zombieNum].yPos = 0;
                                Board::removeZombie(zombieNum);
                            }
                            
                            cout << endl;
                            indent3();
                            system("pause");
                            break;
                        }
                        Board::alienTrail(myAlien.alienXPos, myAlien.alienYPos);
                    }
                }else if(choice == "left"){
                    while(myAlien.alienXPos > 3){
                        myAlien.alienXPos = Alien::alienLeftMove(myAlien.alienXPos);
                        ///////////////////////////////
                        // checks if collide with a zombie
                        if(Board::checkBoard(myAlien.alienXPos, myAlien.alienYPos)){
                            myAlien.alienXPos = myAlien.alienXPos + 4;

                             // gets which zombie the alien crashed into
                            int zombieNum = Board::checkZombie(myAlien.alienXPos - 4, myAlien.alienYPos) - '0';

                            // deducts the zombies health accordingly
                            int newZombieLife = deductZombieHealth(myAlien.attack, zombie[zombieNum].life);
                            zombie[zombieNum].life = newZombieLife;
                            cout << endl;
                            indent3();
                            cout << "Alien crashes into Zombie " << zombieNum << endl;
                            indent3();
                            cout << "Zombie " << zombieNum << " lost " << myAlien.attack << " life" << endl;


                            if(zombie[zombieNum].life <= 0){
                                indent3();
                                cout << "Zombie " << zombieNum << " is defeated!";
                                cout << endl;
                                zombie[zombieNum].status = "dead";
                                zombie[zombieNum].xPos = 0;
                                zombie[zombieNum].yPos = 0;
                                Board::removeZombie(zombieNum);
                            }
                            
                            cout << endl;
                            indent3();
                            system("pause");
                            break;
                        }
                        Board::alienTrail(myAlien.alienXPos, myAlien.alienYPos);
                    }
                }else if(choice == "right"){
                    int xLimit = (gameBoardColumn * 4) + 1;
                    while(myAlien.alienXPos < xLimit - 2){
                        myAlien.alienXPos = Alien::alienRightMove(myAlien.alienXPos);
                        ///////////////////////////////
                        // checks if collide with a zombie
                        if(Board::checkBoard(myAlien.alienXPos, myAlien.alienYPos)){
                            myAlien.alienXPos = myAlien.alienXPos - 4;

                             // gets which zombie the alien crashed into
                            int zombieNum = Board::checkZombie(myAlien.alienXPos + 4, myAlien.alienYPos) - '0';

                            // deducts the zombies health accordingly
                            int newZombieLife = deductZombieHealth(myAlien.attack, zombie[zombieNum].life);
                            zombie[zombieNum].life = newZombieLife;
                            cout << endl;
                            indent3();
                            cout << "Alien crashes into Zombie " << zombieNum << endl;
                            indent3();
                            cout << "Zombie " << zombieNum << " lost " << myAlien.attack << " life" << endl;


                            if(zombie[zombieNum].life <= 0){
                                indent3();
                                cout << "Zombie " << zombieNum << " is defeated!";
                                cout << endl;
                                zombie[zombieNum].status = "dead";
                                zombie[zombieNum].xPos = 0;
                                zombie[zombieNum].yPos = 0;
                                Board::removeZombie(zombieNum);
                            }
                            
                            cout << endl;
                            indent3();
                            system("pause");
                            break;
                        }
                        Board::alienTrail(myAlien.alienXPos, myAlien.alienYPos);
                    }
                    
                }else{
                    gameOver = true;
                    break;
                }

                clearScreen();
                cout << endl;
                newGameBoard.drawBoard();
                cout << endl;
                newGameBoard.resetBoard();

                myAlien.displayAlienAttributes();
                cout << endl;
                for(int i = 1; i < zombieCount + 1; i++){
                    for(int j = 0; j < 1; j++){
                        zombie[i].displayZombieAttributes(i);
                    }
                }
                cout << endl;
                indent3();
                system("pause");


                bool allZombieDead;
                for(int y = 1; y < zombieCount + 1; y++){
                    if(zombie[y].status == "alive"){
                        allZombieDead = false;
                        break;
                    }else{
                        allZombieDead = true;
                    }
                }

                if(allZombieDead){
                    trophy = "win";
                    goto winCon;
                }

                // zombie takes turn moving

                for(int i = 1; i < zombieCount + 1; i++){

                    if(zombie[i].status == "alive"){
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
                            zombie[i].xPos = Zombie::randomXChange(zombie[i].xPos, zombie[i].yPos, myAlien.alienXPos, myAlien.alienYPos, myArrX, myArrY);  // moves the zombie left, right or no movement
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
                            zombie[i].yPos = Zombie::randomYChange(zombie[i].xPos, zombie[i].yPos, myAlien.alienXPos, myAlien.alienYPos, myArrX, myArrY);  // moves the zombie up, down or no movement
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


                        // zombie checks if it can attack alien
                        zombie[i].attackAlien(myAlien, ch);




                        // checks if alien is still alive
                        if(myAlien.life <= 0){
                            gameOver = true;

                            trophy = "lose";

                            gameOverDisplay();

                            system("pause");

                            break;
                        }
                    }else{
                        clearScreen();
                        cout << endl;
                        newGameBoard.drawBoard(); 
                        cout << endl;
                        myAlien.displayAlienAttributes(); 
                        cout << endl;
                        for(int i = 1; i < zombieCount + 1; i++){ 
                            for(int j = 0; j < 1; j++){
                                zombie[i].displayZombieAttributes(i);
                            }
                        }
                        cout << endl;
                        indent3();
                        cout << "Zombie " << i << " has been defeated and shall not move" << endl;
                        cout << endl;
                    }
                    indent3();
                    system("pause");
                }
            }
            winCon:
            


            if(trophy == "win"){
                cout << endl;
                indent3();
                cout << "All Zombies Have Been Defeated!" << endl;
                cout << endl;
                indent3();
                cout << "You Have Won The Game";
                cout << endl;
                cout << endl;
                indent3();
                system("pause");
            }



            



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



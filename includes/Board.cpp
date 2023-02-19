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
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

#include "Board.h"
#include "GameObject.h"
#include "helpers.h"


// creates a Game Board object with attributes of the board's row and column as well as getting its x and y coordinates center point

Board::Board(int inputRow, int inputColumn){ 
    row = (2 * inputRow) + 1;
    column = (4 * inputColumn) + 1;
    xCenter = ceil(column / 2) + 1;
    yCenter = ceil(row / 2) + 1;
}


// creates a gameboard

char gameBoard[1000][1000];


// creates and gets a random game object

char getRandomObject(){
    int randomNumber = (rand() % 5) + 1;
    char gameObject;
    switch(randomNumber){
        case 1:
            gameObject = Game_Object::health();
            break;
        case 2:
            gameObject = Game_Object::arrow();
            break;
        case 3:
            gameObject = Game_Object::pod();
            break;
        case 4:
            gameObject = Game_Object::empty();
            break;
        case 5:
            gameObject = Game_Object::rock();
            break;
    }
    return gameObject;
}


// this generates a random bool, 1/0 which is used to determine if a particular tile on the board will have a game object or not

char randomBool(){
    char ch;
    int random = (rand() % 10) + 1;
    if (random % 2 == 0){
        ch = getRandomObject();
    }else{
        ch = Game_Object::empty();
    }
    return ch;
}


// this checks if the passed in number is a whole number or not

bool isWhole(double i){
    double subject = i;
    int num = subject;
    bool flag;
    if (subject == num){
        flag = true;
    }else{
        flag = false;
    }
    return flag;
}


// creates Alien character

char Board::alienPos(){
    return 'A';
}


// creates temporary Zombie character

char Board::zombiePos(){
    return 'Z';
}


// creates the game board

char Board::createBoard(int n[][2], int zombieCount){
    
    int xPos, yPos;
    int zombieNum = 1;

    for(int i = 1; i <= row; i++){
        if(i % 2 != 0){
            for(int j = 1; j <= column; j++){
                double res = (j + 3.0) / 4;
                if(isWhole(res)){
                    gameBoard[i][j] = '+';
                }else{
                    gameBoard[i][j] = '-';
                } 
            }          
        }else{
            for(int j = 1; j <= column; j++){
                    for(int f = 0; f < zombieCount; f++){
                        for(int g = 0; g < 1; g++){
                            xPos = n[f][g];
                            yPos = n[f][g + 1];
                            if(i == yPos && j == xPos){
                                gameBoard[i][j] = zombiePos();
                                goto endLoop;
                            }else{
                                double res = (j + 3.0) / 4;
                                if(isWhole(res)){
                                    gameBoard[i][j] = '|';
                                }else{
                                    if(j == xCenter && i == yCenter){
                                        gameBoard[i][j] = alienPos();
                                    }else{
                                        if((floor(res) + 0.5) == res){
                                            // gameBoard[i][j] = randomBool();
                                            gameBoard[i][j] = Game_Object::empty();
                                        }else{
                                            gameBoard[i][j] = Game_Object::empty();
                                        }
                                    }
                                }
                            }
                        }
                    }      
                endLoop:
                int noValueHere;
            }
        }
    }
    return gameBoard[1000][1000];
}


// draws the gameboarad

void Board::drawBoard(){
    int num = 1;
    for(int i = 1; i <= row; i++){
        indent10();       
        if(i % 2 == 0){
            cout << num;
            indent15();
            for(int j = 1; j <= column; j++){
                if(gameBoard[i][j] == 'A'){
                    cout << "\x1b[38;5;33m";
                    cout << gameBoard[i][j];
                    cout << "\x1b[38;5;228m";
                }else{
                    cout << gameBoard[i][j];    
                }
            }
            num++;
        }else{
            indent15();
            for(int j = 1; j <= column; j++){
                cout << gameBoard[i][j];
            }
        }
        cout << endl;
    }
    indent15();
    int numnum = 1;
    for(double i = 1; i <= column; i++){
        double res = (i + 1) / 4;
        int intgr = res;
        if(res == intgr){
            cout << numnum;
            numnum++;
        }
        else{
            if(numnum > 10){
                cout << "  ";
                int k = (column - 1) / 4;
                for(int j = 10; j < k ; j++){
                    cout << numnum << "  ";
                    numnum++;
                }
                goto label;
            }else{
                cout << " ";
            }
            ;
        }
    }
    label:
    cout << endl;
    cout << endl;
}


// replaces the Zombie character 'Z' with their actual zombie number

void Board::paintBoard(int xPos, int yPos, int num){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            if(i == yPos && j == xPos){
                string stringNum = to_string(num);
                char ch = stringNum[0];
                gameBoard[i][j] = ch;
            }
        }
    }
}


// checks for Alien movement

void Board::updateBoard(int alienXPos, int alienYPos){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){

            if(gameBoard[i][j] == alienPos()){
                gameBoard[i][j] = Game_Object::trail();
            }
            
            if(i == alienYPos && j == alienXPos){
                gameBoard[i][j] = alienPos();
            }
        }
    }
}


void Board::updateZombiePos(int xPos, int yPos, char zombieChar){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){

            if(gameBoard[i][j] == zombieChar){
                gameBoard[i][j] = Game_Object::empty();
            }
            
            if(i == yPos && j == xPos){
                gameBoard[i][j] = zombieChar;
            }
        }
    }
}



void Board::alienTrail(int alienXPos, int alienYPos){ // draws new alien pos and alien trail

    int gameBoardRow = stoi(boardRowCount());
    int gameBoardColumn = stoi(boardColumnCount());

    int row = (gameBoardRow * 2) + 1;
    int column = (gameBoardColumn * 4) + 1;

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){

            if(gameBoard[i][j] == 'A'){
                gameBoard[i][j] = Game_Object::empty();
                // gameBoard[i][j] = Game_Object::trail();
            }
            
            if(i == alienYPos && j == alienXPos){
                gameBoard[i][j] = 'A';
            }
        }
    }
}

void Board::resetBoard(){
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= column; j++){
            if(gameBoard[i][j] == Game_Object::trail()){
                gameBoard[i][j] = randomBool();
            }
        }
    }
}
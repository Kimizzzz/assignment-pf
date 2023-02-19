// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#include "Zombie.h"
#include "Board.h"
#include "helpers.h"
#include <iostream>


Zombie::Zombie() {
    life = rand() % 100 + 1;
    attack = rand() % life + 1;
    range = rand() % 10 + 1;
}
Zombie::Zombie(int inputLife, int inputAttack, int inputRange, Board board) {
    life = inputLife;
    attack = inputAttack;
    range = (inputRange > board.row || inputRange > board.column) ? 
            min(board.row, board.column) : inputRange;
}
void Zombie::setLife(int l) {
    life = l;
}

void Zombie::setAttack(int a) {
    if (a > life) {
        attack = life;
    } else {
        attack = a;
    }
}

void Zombie::setRange(int r) {
    range = r;
}

int Zombie::getLife() {
    return life;
}

int Zombie::getAttack() {
    return attack;
}

int Zombie::getRange() {
    return range;
}


void Zombie::displayZombieAttributes(int number){
    indent3();
    cout << "Zombie " << number << " =>  ";
    cout << "Life: " << life << " | ";
    cout << "Attack: " << attack << " | ";
    cout << "Range: " << range << " | ";
    cout << "Row: " << yPos / 2 << " | ";
    cout << "Column: " << (xPos + 1) / 4 << endl;
    cout << endl;
}


int Zombie::getRandomAxisMovement(){
    int choice = rand() % 2 + 1;
    return choice;
}

int Zombie::randomXChange(int xPosition, int yPosition, int alienXPos, int alienYPos, int xArr[], int yArr[]){
    int choice;

    int randomInteger = rand() % 2 + 1;

    choice = randomInteger;

    int gameBoardRow = stoi(boardRowCount());
    int gameBoardColumn = stoi(boardColumnCount());

    int yLimit = (gameBoardRow * 2) + 1;
    int xLimit = (gameBoardColumn * 4) + 1;

    const int zombieCount = stoi(getZombieCount());

    if(choice == 1){
        xPosition  = xPosition + 4;
        for(int i = 0; i < zombieCount; i++){
            if((xPosition == xArr[i]) && (yPosition == yArr[i])){
                xPosition = xPosition - 4;
                goto end;
            }
        }
        if(xPosition <= 0 || xPosition >= xLimit || ((xPosition == alienXPos) && (yPosition == alienYPos))){
            xPosition = xPosition - 4;
        }
    }
    else if(choice == 2){
        xPosition  = xPosition - 4;
        for(int i = 0; i < zombieCount; i++){
            if((xPosition == xArr[i]) && (yPosition == yArr[i])){
                xPosition = xPosition + 4;
                goto end;
            }
        }
        if(xPosition <= 0 || xPosition >= xLimit || ((xPosition == alienXPos) && (yPosition == alienYPos))){
            xPosition = xPosition + 4;
        }
    }
    
    end:
    return xPosition;
}

int Zombie::randomYChange(int xPosition, int yPosition, int alienXPos, int alienYPos, int xArr[], int yArr[]){
    int choice;

    int randomInteger = rand() % 2 + 1;

    choice = randomInteger;

    int gameBoardRow = stoi(boardRowCount());
    int gameBoardColumn = stoi(boardColumnCount());

    int yLimit = (gameBoardRow * 2) + 1;
    int xLimit = (gameBoardColumn * 4) + 1;

    const int zombieCount = stoi(getZombieCount());

    if(choice == 1){
        yPosition  = yPosition + 2;
        for(int i = 0; i < zombieCount; i++){
            if((xPosition == xArr[i]) && (yPosition == yArr[i])){
                yPosition = yPosition - 2;
                goto end;
            }
        }
        if(yPosition <= 0 || yPosition >= yLimit || ((xPosition == alienXPos) && (yPosition == alienYPos))){
            yPosition = yPosition - 2;
        }
    }
    else if(choice == 2){
        yPosition  = yPosition - 2;
        for(int i = 0; i < zombieCount; i++){
            if((xPosition == xArr[i]) && (yPosition == yArr[i])){
                yPosition = yPosition + 2;
                goto end;
            }
        }
        if(yPosition <= 0 || yPosition >= xLimit || ((xPosition == alienXPos) && (yPosition == alienYPos))){
            yPosition = yPosition + 2;
        }
    }

    end:
    return yPosition;
}



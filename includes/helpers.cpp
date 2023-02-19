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
#include <fstream>

#include "settingsLogic.h"

using namespace std;


// using ansi characters to clear the screen and places the cursor back at the original spot

void clearScreen(){
    cout << "\x1B[2J\x1B[H";
}


// sets the text colour and background colour that will be used in the game

void setDisplay(){
    cout << "\x1b[48;5;232m"; // for background colour
    cout << "\x1b[38;5;228m"; // for text colour
}


// resets all graphical changes of the console output back to original

void resetDisplay(){
    cout << "\x1b[0m";
}


// creates horizontal indentation

void indent15(){
    cout << "\x1b[15G";
}

void indent3(){
    cout << "\x1b[3G";
}

void indent10(){
    cout << "\x1b[10G";
}

void indent17(){
    cout << "\x1b[17G";
}

void indent6(){
    cout << "\x1b[6G";
}


// prompts user for input action

string prompt(){
    indent3();
    cout << "ACTION >> ";
    string action;
    cin >> action;
    return action;
}


// gets current zombie count

string getZombieCount(){
    string count;
    string res;
    ifstream zombieCount("zombieCount.txt");
    while(getline(zombieCount, count)){
        res = count;
    }
    return res;
}


// gets the current board row saved 

string boardRowCount(){
    string count;
    string res;
    ifstream rowCount("boardRow.txt");
    while(getline(rowCount, count)){
        res = count;
    }
    return res;
}


// gets the current board column saved 

string boardColumnCount(){
    string count;
    string res;
    ifstream ColumnCount("boardColumn.txt");
    while(getline(ColumnCount, count)){
        res = count;
    }
    return res;
}


// checks if Zombie position is a duplicate or not

bool mainCheck(int x, int y, int arr[][2], int zombieCount){
    bool flag;
    for(int i = 0; i < zombieCount; i++){
        for(int j = 0; j < 1; j++){
            if(arr[i][j] == x && arr[i][j + 1] == y){
                flag = true;
                return flag;
            }else{
                flag = false;
            }
        }
    }
    return flag;
}


// creates a 2D array of Zombie positions

int setZombiePos(int arr[][2], int zombieCount, int gameBoardRow, int gameBoardColumn){

    int maxIntRow = gameBoardRow;
    int maxIntCol = gameBoardColumn;

    for(int i = 0; i < zombieCount; i++){

        int randomX = rand() % maxIntCol + 1;
        int randomY = rand() % maxIntRow + 1;

        randomX = (4 * randomX) + 1 - 2;
        randomY = (2 * randomY);

        for(int j = 0; j < 1; j++){        
            arr[i][j] = randomX;
            arr[i][j + 1] = randomY;
        }

        bool flag = mainCheck(randomX, randomY, arr, zombieCount);

        while(flag){
            randomX = rand() % maxIntCol + 1;
            randomY = rand() % maxIntRow + 1;
            randomX = (4 * randomX) + 1 - 2;
            randomY = (2 * randomY); 
            flag = mainCheck(randomX, randomY, arr, zombieCount);
        }
        for(int j = 0; j < 1; j++){        
            arr[i][j] = randomX;
            arr[i][j + 1] = randomY;
        }
    }    
    return arr[zombieCount][2];
}


void zombieMessageX(int newXPos, int oriXPos, int i){
    if(newXPos > oriXPos){
        cout << "Zombie " << i << " moved to the right";
    }else if(newXPos < oriXPos){
        cout << "Zombie " << i << " moved to the left";
    }else{
        cout << "Zombie " << i << " did not move";
    }
}

void zombieMessageY(int newYPos, int oriYPos, int i){
    if(newYPos > oriYPos){
        cout << "Zombie " << i << " moved down";
    }else if(newYPos < oriYPos){
        cout << "Zombie " << i << " moved up";
    }else{
        cout << "Zombie " << i << " did not move";
    }
}



int deductZombieHealth(int alienAttack, int zombieHealth){
    return zombieHealth - alienAttack;
}


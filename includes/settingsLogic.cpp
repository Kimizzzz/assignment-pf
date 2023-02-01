#include <iostream>
#include <fstream>
#include <limits>

#include "settingsLogic.h"
#include "helpers.h"
#include "display.h"

using namespace std;

// gets the current amount of zombie saved

string currentZombieCount(){
    string count;
    string res;
    ifstream zombieCount("zombieCount.txt");
    while(getline(zombieCount, count)){
        res = count;
    }
    return res;
}


//sets a new zombie count and saves it

void setNewZombieCount(int newZombieCount){
    ofstream zombieCount("zombieCount.txt");
    zombieCount << newZombieCount;
    zombieCount.close();
}


// displays the menu setting to change zombie count

void zombieCountDisplay(){
    cout << "                                   " << endl;
    cout << "    =-----------------------------=" << endl;
    cout << "    |       Zombie Settings       |" << endl;
    cout << "    =-----------------------------=" << endl;
    cout << endl;

    cout << "Current zombies count --> " << currentZombieCount() << endl << endl;
    cout << "Enter Number Of Zombies (max 9) : ";

}


// checks if new zombie amount is a sensible amount

bool countCheck(int newZombieCount){
    bool flag;
    if (newZombieCount > 9 || newZombieCount < 1){
        flag = false;
    }else{
        flag = true;
    }
    return flag;
}


// logic behind how to receive new zombie count intake

void zombieCountLogic(){

    int newZombieCount;
    cin >> newZombieCount;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        clearScreen();
        cout << "Bad entry. Please Enter A Number!  ";
        cout << endl;
        zombieCountDisplay();
        cin >> newZombieCount;
    }
    if(countCheck(newZombieCount)){
        setNewZombieCount(newZombieCount);
    }else{
        clearScreen();
        cout << "Please Enter A Valid Response!";
        cout << endl;
        zombieCountDisplay();
        zombieCountLogic();
    }
}


// returns the current game board column

string gameBoardColumn(){
    string count;
    string res;
    ifstream zombieCount("boardColumn.txt");
    while(getline(zombieCount, count)){
        res = count;
    }
    return res;
}


// returns the current game board row

string gameBoardRow(){
    string count;
    string res;
    ifstream zombieCount("boardRow.txt");
    while(getline(zombieCount, count)){
        res = count;
    }
    return res;
}


// displays menu to change game board dimensions

void gameBoardDimensionsDisplay(){
    cout << "                                   " << endl;
    cout << "    =-----------------------------=" << endl;
    cout << "    |        Board Settings       |" << endl;
    cout << "    =-----------------------------=" << endl;
    cout << endl;
    cout << "Current Board Row --> " << gameBoardRow() << endl << endl;
    cout << "Current Board Column --> " << gameBoardColumn() << endl << endl;
}


// sets the new board row

void setBoardRow(int newBoardRow){
    ofstream boardDimensions("boardRow.txt");
    boardDimensions << newBoardRow;
    boardDimensions.close();
}


// sets the new column row

void setBoardColumn(int newBoardColumn){
    ofstream boardDimensions("boardColumn.txt");
    boardDimensions << newBoardColumn;
    boardDimensions.close();
}


// check for valid board dimensions inputs

bool boardCheck(int newBoardDimension){
    bool flag;
    if(newBoardDimension % 2 != 0 && newBoardDimension > 0){
        flag = true;
    }else{
        flag = false;
    }
    return flag;
}


// logic to change game board row

void boardLogicRow(){

    gameBoardDimensionsDisplay();

    int newBoardRow;

    cout << "Enter New Board Row: " ;
    cin >> newBoardRow;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        clearScreen();
        cout << "Bad entry. Please Enter A Number!  ";
        cout << endl;
        gameBoardDimensionsDisplay();
        cout << "Enter New Board Row: " ;
        cin >> newBoardRow;
    }
    if(boardCheck(newBoardRow)){
        setBoardRow(newBoardRow);
    }else{
        clearScreen();
        cout << "Please Make Sure New Value Is Appropiate!";
        cout << endl;
        boardLogicRow();
    }
}


// logic to change game board column

void boardLogicColumn(){

    gameBoardDimensionsDisplay();

    int newBoardColumn;

    cout << "Enter New Board Column: " ;
    cin >> newBoardColumn;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        clearScreen();
        cout << "Bad entry. Please Enter A Number!  ";
        cout << endl;
        gameBoardDimensionsDisplay();
        cout << "Enter New Board Column: " ;
        cin >> newBoardColumn;
    }
    if(boardCheck(newBoardColumn)){
        setBoardColumn(newBoardColumn);
    }else{
        clearScreen();
        cout << "Please Make Sure New Value Is Appropiate!";
        cout << endl;
        boardLogicColumn();
    }
}


// main setting logic on how to handle user inputs

void settingsInput(){

    int choice;
    cin >> choice;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        clearScreen();
        cout << "Bad entry. Please Enter A Number!  ";
        cout << endl;
        settingsDisplay();
        settingsInput();
        cin >> choice;
    }

    if (choice == 1){
        clearScreen();
        gameBoardDimensionsDisplay();
        clearScreen();
        boardLogicRow();
        clearScreen();
        boardLogicColumn();
        clearScreen();
        settingsDisplay();
        settingsInput();
    }else if (choice == 2){
        clearScreen();
        zombieCountDisplay();
        zombieCountLogic();
        clearScreen();
        settingsDisplay();
        settingsInput();
    }else if(choice == 3){
        clearScreen();
        return;
    }else{
        clearScreen();
        cout << "Please Enter A Valid Response!";
        cout << endl;
        settingsDisplay();
        settingsInput();
    }
    
}
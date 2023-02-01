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


// sets the font type, text colour and background colour that will be used in the game

void setDisplay(){
    cout << "\x1b[1m"; // for font
    cout << "\x1b[48;5;230m"; // for background colour
    cout << "\x1b[38;5;232m"; // for text colour
}


// resets all graphical changes of the console output back to original

void resetDisplay(){
    cout << "\x1b[0m";
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

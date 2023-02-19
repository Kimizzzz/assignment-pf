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

#include "display.h"
#include "helpers.h"
#include "Alien.h"
#include "Zombie.h"
using namespace std;

// main menu display

void mainMenuDisplay(){
    cout << "\x1b[?251";
    cout << endl;
    indent6();
    cout << "    =-----------------------------=" << endl;
    indent6();
    cout << "    |       Alien VS Zombies      |" << endl;
    indent6();
    cout << "    =-----------------------------=" << endl;
    cout << endl;
    indent3();
    cout << "(1) Start" << endl;
    indent3();
    cout << "(2) Settings" << endl;
    indent3();
    cout << "(3) Quit" << endl;
    cout << endl;
    indent3();
    cout << "Enter Your Selection: ";
};


// settings display

void settingsDisplay(){
    cout << endl;
    indent6();
    cout << "    =-----------------------------=" << endl;
    indent6();
    cout << "    |           Settings          |" << endl;
    indent6();
    cout << "    =-----------------------------=" << endl;
    cout << endl;
    indent3();
    cout << "(1) Change Board Dimension" << endl;
    indent3();
    cout << "(2) Change Zombie Count" << endl;
    indent3();
    cout << "(3) Back" << endl;
    cout << endl;
    indent3();
    cout << "Enter Your Selection: ";
};


// display for when the player quits the game

void quitGameDisplay(){
    cout << "                                   " << endl;
    cout << "    =-----------------------------=" << endl;
    cout << "    |    Thank You For Playing!   |" << endl;
    cout << "    =-----------------------------=" << endl;
    cout << endl;
};


// display when the game is over

void gameOverDisplay(){
    indent3();
    cout << "    =-----------------------------=" << endl;
    indent3();
    cout << "    |       Game Over,            |" << endl;
    indent3();
    cout << "    |           You Lose          |" << endl;
    indent3();
    cout << "    =-----------------------------=" << endl;
}

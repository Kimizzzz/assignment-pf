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
    cout << "                                   " << endl;
    cout << "    =-----------------------------=" << endl;
    cout << "    |       Alien VS Zombies      |" << endl;
    cout << "    =-----------------------------=" << endl;
    cout << endl;
    cout << "(1) Start" << endl;
    cout << "(2) Settings" << endl;
    cout << "(3) Quit" << endl;
    cout << endl;
    cout << "Enter Your Selection: ";
};


// settings display

void settingsDisplay(){
    cout << "                                   " << endl;
    cout << "    =-----------------------------=" << endl;
    cout << "    |           Settings          |" << endl;
    cout << "    =-----------------------------=" << endl;
    cout << endl;
    cout << "(1) Change Board Dimension" << endl;
    cout << "(2) Change Zombie Count" << endl;
    cout << "(3) Back" << endl;
    cout << endl;
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


// displays the Alien attributes

void displayAlienAttributes() {
    Alien a;
    int life = a.getLife();
    int attack = a.getAttack();
    cout << "Alien's life: " << life << endl;
    cout << "Alien's attack: " << attack << endl;
}

// displays the Zombie attributes

void displayZombieAttributes(){
    Zombie z;
    cout << "Zombie's Life: " << z.getLife() << endl;
    cout << "Zombie' Attack: " << z.getAttack() << endl;
    cout << "Zombie's Range: " << z.getRange() << endl;
    cout << endl;
}

#include <iostream>

#include "display.h"
#include "helpers.h"
#include "Alien.h"
using namespace std;

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

void quitGameDisplay(){
    clearScreen();
    cout << "                                   " << endl;
    cout << "    =-----------------------------=" << endl;
    cout << "    |    Thank You For Playing!   |" << endl;
    cout << "    =-----------------------------=" << endl;
    cout << endl;
};

void displayAlienAttributes() {
    Alien a;
    int life = a.getLife();
    int attack = a.getAttack();
    cout << "Alien's life: " << life << endl;
    cout << "Alien's attack: " << attack << endl;
}
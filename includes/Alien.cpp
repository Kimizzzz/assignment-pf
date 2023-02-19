// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#include "Alien.h"
#include "Zombie.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include "helpers.h"
#include "Board.h"
#include "GameObject.h"

Alien::Alien(int xCenter, int yCenter){
    // seed the random number generator with the current time
    srand(time(0));

    // set life and attack to random values between 1 and 100
    life = rand() % 100 + 1;
    attack = 0;
    
    // sets Alien x position and Y position
    alienXPos = xCenter;
    alienYPos = yCenter;
}

void Alien::setLife(int newLife) {
    life = newLife;
}

void Alien::setAttack(int newAttack) {
    attack = newAttack;
}

int Alien::getLife() {
    return life;
}

int Alien::getAttack() {
    return attack;
}

void Alien::addLife(int newLife) {
    life += newLife;
    if (life > 100) {
        life = 100;
    }
}

void Alien::displayAlienAttributes() {
    indent3();
    cout << "Alien's Life: " << life;
    cout << "  |  ";
    cout << "Alien's Attack: " << attack << endl;
}


void Alien::receiveAttack(Zombie& zombie) {
    int distance = abs(alienXPos - zombie.xPos) + abs(alienYPos - zombie.yPos);
    if (distance <= zombie.getRange()) {
        life -= zombie.getAttack();
    }
}

int Alien::alienUpMove(int yPos){
    yPos = yPos - 2;
    return yPos;
}

int Alien::alienDownMove(int yPos){
    yPos = yPos + 2;
    return yPos;
}

int Alien::alienLeftMove(int xPos){
    xPos = xPos - 4;
    return xPos;
}

int Alien::alienRightMove(int xPos){
    xPos = xPos + 4;
    return xPos;
}

// Method to handle collision with a health pod
void Alien::collisionWithHealth() {
int healthToAdd = 20 ; // Add between 1 and 5 health points
addLife(healthToAdd);
cout << "Alien collided with a health pod and gained " << healthToAdd << " life points!" << endl;
}

// add a new method to handle alien collision with game objects

void Alien::collisionWith(Game_Object& gameObject) {
    char objectType = gameObject.getType();
    switch (objectType) {
        case 'h': // health pod
            collisionWithHealth();
            break;
        case '^': // arrow
            // do something if alien collides with an arrow
            break;
        case 'r': // rock
            // do something if alien collides with a rock
            break;
        case 'p': // pod
            // do something if alien collides with a pod
            break;
        default:
            break;
    }
}

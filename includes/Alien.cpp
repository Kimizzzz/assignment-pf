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
int healthToAdd = 20 ; 
addLife(healthToAdd);
cout << "Alien collided with a health pod and gained " << healthToAdd << " life points!" << endl;
}

void Alien::collisionWithArrow(char arrowDirection){
    // update alien's attack by adding 20
        attack += 20;
    switch(arrowDirection){
        case '^': // up arrow
            alienYPos = alienUpMove(alienYPos);
            break;
        case 'v': // down arrow
            alienYPos = alienDownMove(alienYPos);
            break;
        case '<': // left arrow
            alienXPos = alienLeftMove(alienXPos);
            break;
        case '>': // right arrow
            alienXPos = alienRightMove(alienXPos);
            break;
    }
}

// Method to handle collision with a rock
void Alien::collisionWithRock() {
    // Stop the Alien's movement
    alienXPos = alienXPos;
    alienYPos = alienYPos;
    cout << "Alien collided with a rock and stopped moving!" << endl;
}

bool Alien::checkCollision(Game_Object& obj1, Game_Object& obj2) {
    int obj1XPos = obj1.getXPos();
    int obj1YPos = obj1.getYPos();
    int obj1Width = obj1.getWidth();
    int obj1Height = obj1.getHeight();

    int obj2XPos = obj2.getXPos();
    int obj2YPos = obj2.getYPos();
    int obj2Width = obj2.getWidth();
    int obj2Height = obj2.getHeight();

    if (obj1XPos + obj1Width >= obj2XPos && obj1XPos <= obj2XPos + obj2Width &&
        obj1YPos + obj1Height >= obj2YPos && obj1YPos <= obj2YPos + obj2Height) {
        return true; // collision detected
    } else {
        return false; // no collision
    }
}



// add a new method to handle alien collision with game objects
void Alien::collisionWith(Game_Object& gameObject) {
    char objectType = gameObject.getType();
    switch (objectType) {
        case 'h': // health pod
            collisionWithHealth();
            break;
        case '^': // arrow pointing up
        case 'v': // arrow pointing down
        case '<': // arrow pointing left
        case '>': // arrow pointing right
            collisionWithArrow(objectType);
            break;
        case 'r': // rock
            collisionWithRock();
            break;
        case 'p': // pod
            // do something if alien collides with a pod
            break;
        default:
            break;
    }
}

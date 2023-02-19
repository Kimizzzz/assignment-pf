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


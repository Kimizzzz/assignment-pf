#include "Alien.h"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

Alien::Alien(){
    // seed the random number generator with the current time
    srand(time(0));

    // set life and attack to random values between 1 and 100
    life = rand() % 100 + 1;
    attack = 0;
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
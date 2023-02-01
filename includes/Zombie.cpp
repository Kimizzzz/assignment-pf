#include "Zombie.h"
#include "Board.h"
#include <iostream>


Zombie::Zombie() {
    life = rand() % 100 + 1;
    attack = rand() % life + 1;
    range = rand() % 10 + 1;
}
Zombie::Zombie(int inputLife, int inputAttack, int inputRange, Board board) {
    life = inputLife;
    attack = inputAttack;
    range = (inputRange > board.row || inputRange > board.column) ? 
            min(board.row, board.column) : inputRange;
}
void Zombie::setLife(int l) {
    life = l;
}

void Zombie::setAttack(int a) {
    if (a > life) {
        attack = life;
    } else {
        attack = a;
    }
}

void Zombie::setRange(int r) {
    range = r;
}

int Zombie::getLife() {
    return life;
}

int Zombie::getAttack() {
    return attack;
}

int Zombie::getRange() {
    return range;
}
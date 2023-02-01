// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

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
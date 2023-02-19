// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#ifndef ALIEN_H
#define ALIEN_H

#include <random>
#include <string>
#include "Zombie.h"
#include "GameObject.h"
using namespace std;

class Alien {
    private:
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;

    public:
        int life;
        int attack;
        int alienXPos;
        int alienYPos;
        Alien(int, int); // constructor
        void setLife(int);
        void setAttack(int);
        int getLife();
        int getAttack();
        void addLife(int life);
        void displayAlienAttributes();
        void collisionWithHealth();
        void collisionWith(Game_Object& gameObject);

        void receiveAttack(Zombie& zombie); // method to handle the zombie attack

        static int alienUpMove(int);
        static int alienDownMove(int);
        static int alienLeftMove(int);
        static int alienRightMove(int);

};

#endif
#ifndef ALIEN_H
#define ALIEN_H

#include <random>

class Alien {
    private:
        int life;
        int attack;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;

    public:
        Alien(); // constructor
        void setLife(int);
        void setAttack(int);
        int getLife();
        int getAttack();
        void addLife(int life);
};

#endif
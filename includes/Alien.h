#ifndef ALIEN_H
#define ALIEN_H

class Alien {
    private:
        int life;
        int attack;
    public:
        Alien(); // constructor
        void setLife(int);
        void setAttack(int);
        int getLife();
        int getAttack();
};

#endif
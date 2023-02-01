#ifndef ZOMBIE_H
#define ZOMBIE_H

class Board;

class Zombie {
    private:
        int life;
        int attack;
        int range;
    public:
        Zombie(); // Default constructor
        Zombie(int, int, int, Board); // Additional constructor
        void setLife(int);
        void setAttack(int);
        void setRange(int);
        int getLife();
        int getAttack();
        int getRange();
        
};

#endif

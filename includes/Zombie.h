// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Board;
class Alien;

class Zombie {
    private:
        int attack;
        int range;
    public:
        int life;
        int xPos;
        int yPos;
        Zombie(); // Default constructor
        Zombie(int, int, int, Board); // Additional constructor
        void setLife(int);
        void setAttack(int);
        void setRange(int);
        int getLife();
        int getAttack();
        int getRange();
        void displayZombieAttributes(int);

        static int getRandomAxisMovement();
        static int randomXChange(int, int, int, int, int[], int[]);
        static int randomYChange(int, int, int, int, int[], int[]);

        void attackAlien(Alien& alien, char); // Function to attack an Alien
        
};

#endif

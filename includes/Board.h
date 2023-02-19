// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#ifndef BOARD
#define BOARD

#include <iostream>
using namespace std;

class Board{
    
    public:
        // attributes of the board class
        int row;
        int column;
        int xCenter;
        int yCenter;

        // the constructor
        Board(int inputRow, int inputColumn); 

        // member functions
        char createBoard(int[][2], int);
        void paintBoard(int, int, int);
        void drawBoard();
        void updateBoard(int alienXPos, int alienYPos);
        char alienPos();
        char zombiePos();

        void updateZombiePos(int, int, char);
        static bool checkBoard(int, int);

        static void alienTrail(int, int);
        void resetBoard();

        static int checkZombie(int, int);

        static void removeZombie(int zombieNum);
        void setRandomObject(int x, int y, char arrow);

};
#endif




#ifndef BOARD
#define BOARD

#include <iostream>
using namespace std;

class Board{
    
    public:

        int row;
        int column;
        Board(int inputRow, int inputColumn);
        void createBoard();

};
#endif




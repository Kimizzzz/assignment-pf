#ifndef BOARD
#define BOARD

#include <iostream>
using namespace std;

class Board{
    
    public:

        int row;
        int column;
        int xCenter;
        int yCenter;
        Board(int inputRow, int inputColumn);
        void createBoard();
        char alienPos();

};
#endif




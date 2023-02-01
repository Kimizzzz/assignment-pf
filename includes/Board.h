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
        void createBoard();
        char alienPos();

};
#endif




#include <iostream>
#include <cmath>
using namespace std;

#include "Board.h"
#include "GameObject.h"

Board::Board(int inputRow, int inputColumn){
    row = (2 * inputRow) + 1;
    column = (4 * inputColumn) + 1;
    xCenter = ceil(column / 2) + 1;
    yCenter = ceil(row / 2) + 1;
}

char getRandomObject(){
    int randomNumber = (rand() % 5) + 1;
    char gameObject;
    switch(randomNumber){
        case 1:
            gameObject = Game_Object::health();
            break;
        case 2:
            gameObject = Game_Object::arrow();
            break;
        case 3:
            gameObject = Game_Object::pod();
            break;
        case 4:
            gameObject = Game_Object::empty();
            break;
        case 5:
            gameObject = Game_Object::rock();
            break;
    }
    return gameObject;
}

char randomBool(){
    char ch;
    int random = (rand() % 10) + 1;
    if (random % 2 == 0){
        ch = getRandomObject();
    }else{
        ch = Game_Object::empty();
    }
    return ch;
}


bool isWhole(double i){
    double subject = i;
    int num = subject;
    bool flag;
    if (subject == num){
        flag = true;
    }else{
        flag = false;
    }
    return flag;
}

char Board::alienPos(){
    return 'A';
}

void Board::createBoard(){

    cout << endl;
    
    char gameBoard[row][column];

    for(int i = 1; i <= row; i++){

        if(i % 2 != 0){
            for(int j = 1; j <= column; j++){

                double res = (j + 3.0) / 4;
                if(isWhole(res)){
                    gameBoard[i][j] = '+';
                    cout << gameBoard[i][j];
                }else{
                    gameBoard[i][j] = '-';
                    cout << gameBoard[i][j];
                } 

            }
        }else{
            for(int j = 1; j <= column; j++){

                double res = (j + 3.0) / 4;
                if(isWhole(res)){
                    gameBoard[i][j] = '|';
                    cout << gameBoard[i][j];
                }else{
                    if(j == xCenter && i == yCenter){
                        gameBoard[i][j] = alienPos();
                        cout << gameBoard[i][j]; 
                    }else{
                        if((floor(res) + 0.5) == res){
                            gameBoard[i][j] = randomBool();
                            cout << gameBoard[i][j];  
                        }else{
                            gameBoard[i][j] = Game_Object::empty();
                            cout << gameBoard[i][j];
                        }
                    }
                } 
            }
        }
        cout << endl;
    }

}







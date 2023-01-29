#include <iostream>


#include "board.h"

using namespace std;

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


void createBoard(int inputRow, int inputColumn){

            int row = (2 * inputRow) + 1;
            int column = (4 * inputColumn) + 1;
            
            char gameBoard[row][column];

            for(int i = 1; i <= row; i++){

                if(i % 2 != 0){
                    for(int j = 1; j <= column; j++){

                        double res = (j + 3.0) / 4;
                        if(isWhole(res)){
                            gameBoard[i][j] = '+';
                        }else{
                            gameBoard[i][j] = '-';
                        } 
                    }
                }else{
                    for(int j = 1; j <= column; j++){

                        double res = (j + 3.0) / 4;
                        if(isWhole(res)){
                            gameBoard[i][j] = '|';
                        }else{
                            gameBoard[i][j] = ' ';
                        } 
                    }
                }
            }

            for(int i = 1; i <= row; i++){
                for(int j = 1; j <= column; j++){
                    cout << gameBoard[i][j];
                }
                cout << endl;
            }
}
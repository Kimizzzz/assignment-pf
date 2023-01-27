#include <iostream>
#include <fstream>

#include "settingsLogic.h"

using namespace std;

void clearScreen(){
    cout << "\x1B[2J\x1B[0;0f";
}

string boardRowCount(){
    string count;
    string res;
    ifstream rowCount("boardRow.txt");
    while(getline(rowCount, count)){
        res = count;
    }
    return res;
}

string boardColumnCount(){
    string count;
    string res;
    ifstream ColumnCount("boardColumn.txt");
    while(getline(ColumnCount, count)){
        res = count;
    }
    return res;
}


// draws the game board 
void drawBoard(int row, int column){


    for(int k = 0; k < row; k++){

        for(int i = 0; i < (column + 1); i++){
        cout << '+';
        if(i != column){
            for(int j = 0; j < 3; j++){
            cout << '-';
            }
        }
        }

        cout << endl; 

        for(int i = 0; i < (column + 1); i++){
            cout << '|';
            if(i != column){
                for(int j = 0; j < 3; j++){
                cout << ' ';
                }
            }
        }

        cout << endl;
    }

    for(int i = 0; i < (column + 1); i++){
        cout << '+';
        if(i != column){
            for(int j = 0; j < 3; j++){
            cout << '-';
            }
        }
    }
}
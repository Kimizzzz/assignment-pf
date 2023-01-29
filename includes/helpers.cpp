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

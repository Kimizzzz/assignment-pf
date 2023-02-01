// *************************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT2L
// Names: Syed Thahir Alhabshi Bin Sayed Ahmad | Muhammad Ismail Bin Suhaini | Muhammad Azhan Hakimi Bin Zulhani
// IDs: 1211101155 | 1211101375 | 1211104234
// Emails: 1211101155@student.mmu.edu.my | 1211101375@student.mmu.edu.my | 1211104234@student.mmu.edu.my
// Phones: 0122025093 | 0198627626 | 0103139361
// *************************************************************************************************************

#include <iostream>
#include <string>

#include "GameObject.h"

using namespace std;

// all of these below are used to create the various game objects


char Game_Object::arrow(){
    int randomNumber = (rand() % 4) + 1;
    char arrow;
    switch(randomNumber){
        case 1:
            arrow = '^';
            break;
        case 2:
            arrow = '<';
            break;
        case 3:
            arrow = '>';
            break;
        case 4:
            arrow = 25;
            break;
    }
    return arrow;
}

char Game_Object::health(){
    return 'h';
}

char Game_Object::pod(){
    return 'p';
}

char Game_Object::empty(){
    return ' ';
}

char Game_Object::trail(){
    return '.';
}

char Game_Object::rock(){
    return 'r';
}






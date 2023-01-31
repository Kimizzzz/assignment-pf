#include <iostream>
#include <string>

#include "GameObject.h"

using namespace std;

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






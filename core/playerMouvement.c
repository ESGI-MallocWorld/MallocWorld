//
// Created by wuchi on 2021/11/13.
//

#include "playerMouvement.h"

void addResource();


void mapInterReaction();

int* getPlayerLocation(){
    return player->location;
}

void goUp();


void goRight();


void goDown();


void goLeft();


void move(){

    int direction ;
    //ask to go

    printf(" /n");
    switch (direction) {
        case 1: // go up        ↑
            goUp();
            break;
        case 2: // go right     →
            goRight();
            break;
        case 3: // go down      ↓
            goDown();
            break;
        case 4: // go left      ←
            goLeft();
            break;
    }
}


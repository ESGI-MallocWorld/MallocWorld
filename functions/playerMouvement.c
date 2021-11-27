//
// Created by wuchi on 2021/11/13.
//
#ifndef MALLOCWORLD_PLAYERMOUVEMENT_H
#define MALLOCWORLD_PLAYERMOUVEMENT_H

#include "./mapInterReaction.h"

#include "playerMouvement.h"
#include "mapAction.h" // have been included in Action

void addResource();

void mapInterReaction();



int* getPlayerLocation(Player *this){
    return player->location;
}

void goUp(playerData){
    if(isRoad())
}

void goRight();


void goDown();


void goLeft();


void move(Player playerData){
    int direction ;

    scanf("%d" ,&direction)

    printf(" /n");
    switch (direction) {
        case 1: // go up        ↑
            goUp(playerData);
            break;
        case 2: // go right     →
            goRight(playerData);
            break;
        case 3: // go down      ↓
            goDown(playerData);
            break;
        case 4: // go left      ←
            goLeft(playerData);
            break;
    }
}


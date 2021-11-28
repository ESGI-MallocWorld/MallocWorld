//
// Created by wuchi on 2021/10/13.
//
#ifndef MALLOCWORLD_PLAYERMOUVEMENT_H
#define MALLOCWORLD_PLAYERMOUVEMENT_H

//#include "../core/mapInterReaction.h"
//#include "../Units/Player.h"

#include "playerMouvement.h"
#include "mapAction.h" // have been included in Action

int UpElement(int X , int Y ,int ** mapData);

int RightElement(int X , int Y ,int ** mapData);

int DownElement(int X , int Y ,int ** mapData);

int LeftElement(int X , int Y ,int ** mapData);

int getElement(int *location ,map* mapData ,int direction);

void movementDialogue();

int move(int* playerLoc , map *mapData);


#endif //MALLOCWORLD_PLAYERMOUVEMENT_H

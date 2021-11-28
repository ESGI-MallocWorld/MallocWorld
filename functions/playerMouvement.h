//
// Created by wuchi on 2021/10/13.
//
#ifndef MALLOCWORLD_PLAYERMOUVEMENT_H
#define MALLOCWORLD_PLAYERMOUVEMENT_H

//#include "../core/mapInterReaction.h"
//#include "../Units/Player.h"

#include "mapAction.h" // have been included in Action

int UpElement(int X , int Y ,int *targetLocation,int ** mapData);

int RightElement(int X , int Y ,int *targetLocation,int ** mapData);

int DownElement(int X , int Y ,int *targetLocation,int ** mapData);

int LeftElement(int X , int Y ,int *targetLocation,int ** mapData);

int getElement(int *location ,map* mapData ,int direction,int *targetLocation);

void movementDialogue();

int checkVoid(int direction,map *map ,int *location);

void warning(int error);

int move(int* playerLoc , map *mapData,int *targetLocation);


#endif //MALLOCWORLD_PLAYERMOUVEMENT_H

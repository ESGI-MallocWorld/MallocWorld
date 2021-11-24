#ifndef MALLOCWORLD_LEVEL_H
#define MALLOCWORLD_LEVEL_H

#include<stdlib.h>
#include<stdio.h>

typedef struct level {
    int levelID;
    int maxHp;
    int minExp;
    int maxExp; //if exp of player > maxEsp then the player's level will be upgraded

} level;

level* createLevel(int);

void setLevel(int);


#endif
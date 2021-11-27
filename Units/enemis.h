//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_ENEMIS_H
#define MALLOCWORLD_ENEMIS_H

#include <stdlib.h>

typedef struct Enemy{
    int id;
    char* name;
    int zone;
    int life;
    int damage;
    int expGained; 
} Enemy;

Enemy** createMonsters();

Enemy* initializeMonster(int, char*, int, int, int, int);

int* getListofMonsterID(Enemy**, int);

Enemy* createMonsterfromID(int);

void displayCharacteristicsMonster(int);

#endif //MALLOCWORLD_ENEMIS_H

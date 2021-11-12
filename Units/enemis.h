//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_ENEMIS_H
#define MALLOCWORLD_ENEMIS_H

#include <stdlib.h>

typedef struct Enemy{
    int id;
    char* name;
    int life;
    int expGained; 
} Enemy;

struct Enemy * Goblins;
Goblins->id=15;
Goblins->name = "Goblin";
Goblins->life=50;
Goblins->expGained=25;

struct Enemy * Trolls;
Trolls->id=25;
Trolls->name = "Troll";
Trolls->life=110;
Trolls->expGained=60;

struct Enemy * Undead;
Undead->id=35;
Undead->name = "Undead";
Undead->life=200;
Undead->expGained=200;

struct Enemy * FinalBoss;
FinalBoss->id=99;
FinalBoss->name = "FinalBoss";
FinalBoss->life=800;
FinalBoss->expGained=500;


#endif //MALLOCWORLD_ENEMIS_H

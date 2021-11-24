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

#endif //MALLOCWORLD_ENEMIS_H

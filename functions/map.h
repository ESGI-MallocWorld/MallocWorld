//
// Created by wuchi on 2021/10/12.
//

#ifndef MALLOCWORLD_MAP_H
#define MALLOCWORLD_MAP_H

#include "./mapParam.h"

typedef struct map {
    int ** map;
    int level;
    mapParam* mapInformation;
}map;

int getMapRowSize(map* map){
    return map->mapInformation->row_size;
}

int getMapColSize(map* map){
    return map->mapInformation->col_size
}

int getMapMaxEnemies(map* map){
    return map->mapInformation->max_enemies;
}

int getMapMaxRocks(map* map){
    return map->mapInformation->max_rocks;
}

int getMapMaxPlants(map* map){
    return map->mapInformation->max_plants;
}

int getMapMaxTrees(map* map){
    return map->mapInformation->max_trees;
}

int getLevel(map* map){
    return map->level;
}

#endif //MALLOCWORLD_MAP_H

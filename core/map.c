//
// Created by wuchi on 2021/11/24.
//

include "./map.h"

int getRowSize(mapParam* mapInformation){
    return mapInformation->row_size;
}

int getColSize(mapParam* mapInformation){
    return mapInformation->col_size;
}

int getMaxEnemies(mapParam* mapInformation){
    return mapInformation->max_enemies;
}

int getMaxRocks(mapParam* mapInformation){
    return mapInformation->max_rocks;
}

int getMaxPlants(mapParam* mapInformation){
    return mapInformation->max_plants;
}

int getMaxTrees(mapParam* mapInformation){
    return mapInformation->max_trees;
}

int getMapRowSize(map* map){
    return map->mapInformation->row_size;
}

int getMapColSize(map* map){
    return map->mapInformation->col_size;
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
//
// Created by wuchi on 2021/10/12.
//

#ifndef MALLOCWORLD_MAPPARAM_H
#define MALLOCWORLD_MAPPARAM_H

typedef struct mapParam {
    int row_size;
    int col_size;
    int max_enemies;
    int max_rocks;
    int max_plants;
    int max_trees;
}mapParam;

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

#endif //MALLOCWORLD_MAPPARAM_H

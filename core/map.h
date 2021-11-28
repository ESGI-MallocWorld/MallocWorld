//
// Created by wuchi on 2021/10/12.
//

#ifndef MALLOCWORLD_MAP_H
#define MALLOCWORLD_MAP_H

/**
 * MAP setting
 */
typedef struct mapParam mapParam ;

typedef struct mapParam {
    int row_size;
    int col_size;
    int max_enemies;
    int max_rocks;
    int max_plants;
    int max_trees;
}mapParam;

int getRowSize(mapParam* mapInformation);

int getColSize(mapParam* mapInformation);

int getMaxEnemies(mapParam* mapInformation);

int getMaxRocks(mapParam* mapInformation);

int getMaxPlants(mapParam* mapInformation);

int getMaxTrees(mapParam* mapInformation);

/**
 * MAP
 */
typedef struct map map ;

typedef struct map {
    int ** mapData;
    int level;
    mapParam* mapInformation;
}map;


int getMapRowSize(map* map);

int getMapColSize(map* map);

int getMapMaxEnemies(map* map);

int getMapMaxRocks(map* map);

int getMapMaxPlants(map* map);

int getMapMaxTrees(map* map);

int getLevel(map* map);

int** getMapData(map* map);

/**
 * This function need Location and then X and Y pass by reference and val will be assign on the X and Y
 * @param location
 * @param X
 * @param Y
 */
void assignLocation(int* location , int *X ,int *Y);

#endif //MALLOCWORLD_MAP_H

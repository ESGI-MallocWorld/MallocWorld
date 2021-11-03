//
// Created by wuchin on 2021/10/12.
//

#ifndef MALLOCWORLD_MAPBUILDER_H
#define MALLOCWORLD_MAPBUILDER_H

#include "./mapParam.h"
#include "./map.h"
#include <stdlib.h>

/**
 * generate random location [X,Y]
 * use only in getValideLocation
 * @param max_X
 * @param max_Y
 * @return [0-max_X , 0-max_Y]
 */
void randLocation(int *loc,map *map){
    printf(" Progress : Generate random resource location  ... ");

    int max_X ;
    int max_Y ;
    int X_location;
    int Y_location;

    max_X       = getMapRowSize(map);
    max_Y       = getMapColSize(map);
    X_location  = rand() % max_X ;
    Y_location  = rand() % max_Y ;

    loc[0] =X_location;
    loc[1] =Y_location;

}

/**
 * Generate a valid location can be accessible all path
 * @param map
 * @return
 */
void getValidLocation(map *map , int *loc ){

    int max_X = getMapRowSize(map);
    int max_Y = getMapColSize(map);
    int side_available  = 0;
    int side_occurrence = 0;
    bool valid = false;
    int **mapData;
    while (!valid) {
        randLocation(loc,map);
        mapData = map->mapData ;
        int x = loc[0];
        int y = loc[1];
        if (mapData[x][y] == 0) {

            if (x != 0) { //check left
                side_available++;
                if (mapData[x - 1][y] != 0) {
                    side_occurrence++;
                }
            }

            if (x != max_X) { //check right
                side_available++;
                if (mapData[x + 1][y] != 0) {
                    side_occurrence++;
                }
            }

            if (y != 0) { //check top
                side_available++;
                if (mapData[x][y - 1] != 0) {
                    side_occurrence++;
                }
            }

            if (y != max_Y) { //check bottom
                side_available++;
                if (mapData[x][y + 1] != 0) {
                    side_occurrence++;
                }
            }

            if (side_occurrence < side_available) {
                valid = true;
            }

        }
    }
}

/**
 * add portal travel between zone depend on map and map param
 * @param map
 */
void addPortal(map* map){
    printf(" Progress : generate Portal ... ");

    int level ;
    int *loc = malloc(sizeof(int)* 2);

    level = getLevel(map);

    //add portal travel between zone1-2
    if(level == 1 || level == 2){
        getValidLocation(map,loc);
        int x = loc[0];
        int y = loc[1];

        map->mapData[x][y] = -1;
    }

    //add portal travel between zone2-3
    if(level == 2 || level == 3){
        getValidLocation(map,loc);
        int x = loc[0];
        int y = loc[1];

        map->mapData[x][y] = -2;
    }

}

/**
 * add plants on map (mini 3)
 * @param map
 */
void addPlants(map* map){
    printf(" Progress : generate Plants ... ");

    int limit  ;
    int level ;
    int * loc = malloc(sizeof(int)* 2);
    int ** zone1 ;

    int x = loc[0];
    int y = loc[1];

    limit = getMapMaxPlants(map);
    level = getLevel(map);
    zone1 = map->mapData;
    getValidLocation(map,loc);

    for (int i = 0; i < limit; ++i) {
        zone1[x][y] = level*3+0 ;
    }
    printf(" Progress : %d Plants have been generate... ",limit );
}

/**
 * add rocks on map
 * @param map
 */
void addRocks(map* map){
    printf(" Progress : generate Rocks ... ");
    int limit  ;
    int level ;
    int * loc = malloc(sizeof(int)* 2);
    int ** zone1 ;
    int x = loc[0];
    int y = loc[1];


    limit = getMapMaxRocks(map);
    level = getLevel(map);
    zone1 = map->mapData;
    getValidLocation(map,loc);

    for (int i = 0; i < limit; ++i) {
        x=loc[0];
        y=loc[1];
        zone1[x][y] = level*3+1 ;
    }
    printf(" Progress : %d Rocks have been generate... ",limit );

}

/**
 * add trees on maps
 * @param map
 */
void addTrees(map* map){
    printf(" Progress : generate Trees ... ");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **zone1 ;
    int x = loc[0];
    int y = loc[1];


    limit = getMapMaxTrees(map);
    level = getLevel(map);
    zone1 = map->mapData;
    getValidLocation(map,loc);

    for (int i = 0; i < limit; ++i) {
        zone1[x][y] = level*3+2 ;
    }
    printf(" Progress : %d tree have been generate... ",limit );

}

/**
 * add enemies on map
 * @param map
 */
void addEnemies(map* map) {
    printf(" Progress : generate enemies ... ");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **zone1 ;
    int x = loc[0];
    int y = loc[1];

    //add monster list and zone;
    limit = getMapMaxEnemies(map);
    zone1 = map->mapData;
    getValidLocation(map,loc);

    for (int i = 0; i < limit; ++i) {
        zone1[x][y] = 15 ;
    }
    printf(" Progress : %d enemies have been generate... ",limit );

}

/**
 * insert Elements on map
 * @param map
 */
void insertElements(map* map){
    printf(" Progress : Insert element ... ");
    addPortal(map);
    addPlants(map);
    addRocks(map);
    addTrees(map);
    addEnemies(map);

}

/**
 * generate a 2 dimension array use as map fill with '0' // 0 = path
 * @param row
 * @param col
 * @return empty map
 */
int** init_empty_map(int row , int col){
    printf(" Progress : generate empty map .. ");

    int** map =  malloc(sizeof(int*) * row);

    for (int i = 0; i < row; ++i) {
        map[i]=  malloc(sizeof(int) * col);
    }

    // fill map with path
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col ; ++y) {
            map[x][y] = 0;
        }
    }

    return map;

}

/**
 * random max recourse val
 * @return [ Max_enemies,Max_rocks ,Max_plants , Max_trees]
 */
int* randResources(){
    printf("Progress : Setting resources limit amount  ...");
    int randRatio = 3;
    int* rand_Resource = malloc(sizeof(int)*4);
    rand_Resource[0] = rand() % randRatio +10;   //enemies
    rand_Resource[1] = rand() % randRatio +3;    //rocks
    rand_Resource[2] = rand() % randRatio +3;    //plants
    rand_Resource[3] = rand() % randRatio +3;    //trees

    return rand_Resource;

}

void printMap(map *map){
    int row , col;
    row = getMapRowSize(map);
    col = getMapColSize(map);
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col; ++y) {
            printf(" %d ",map->mapData[x][y]);
        }
    }

}

/**
 * init map by level zone
 * @param zone_level
 * @return map*
 */
map* initMapConfiguration(int zone_level){
    printf("init map default configuration ...");
    int *randResourcesVal = malloc(sizeof(int));
    int row , col;

    map *map = malloc(sizeof(map));
    map->mapInformation = malloc(sizeof(mapParam));
//    map->level = malloc(sizeof(int));

    randResourcesVal = randResources();
    insertElements(map);

    printMap(map);


    map->level = zone_level;

    map->mapInformation->row_size    = 10;
    map->mapInformation->col_size    = 10;
    map->mapInformation->max_enemies = randResourcesVal[0]+10;
    map->mapInformation->max_rocks   = randResourcesVal[1]+3;
    map->mapInformation->max_plants  = randResourcesVal[2]+3;
    map->mapInformation->max_trees   = randResourcesVal[3]+3;

    row = map->mapInformation->row_size;
    col = map->mapInformation->col_size;

    map->mapData = init_empty_map(row,col);

    return map;

}

/**
 * init
 * @param row
 * @param col
 * @return
 */
int** init_zone1(){
    map* map_zone1 ;
    int **map;

    map_zone1 = initMapConfiguration(1);

    map = map_zone1->mapData;

    return map;
}

int** init_zone2(){
    map* map_zone2 ;
    int **map;

    map_zone2 = initMapConfiguration(2);

    map = map_zone2->mapData;

    return map;
}

int** init_zone3(){
    map* map_zone3 ;
    int **map;

    map_zone3 = initMapConfiguration(3);

    map = map_zone3->mapData;

    return map;
}


#endif //MALLOCWORLD_MAPBUILDER_H

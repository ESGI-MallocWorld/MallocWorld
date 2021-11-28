//
// Created by wuchin on 2021/10/12.
//

#ifndef MALLOCWORLD_MAPBUILDER_H
#define MALLOCWORLD_MAPBUILDER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "../core/map.c"

/**
 * generate random location [X,Y]
 * use only in getValideLocation
 * @param max_X
 * @param max_Y
 * @return [0-max_X , 0-max_Y]
 */
int * randLocation(map *map){
//    printf(" Progress : Generate random resource location  ... \n");
    int *loc = malloc(sizeof(int)* 2);

    int max_X ;
    int max_Y ;
    int X_location;
    int Y_location;

    max_X       = getMapRowSize(map);
    max_Y       = getMapColSize(map);

    srand ( time(NULL) );
//    printf("Max x : %d, Max y : %d \n ", max_X , max_Y);
    X_location  = rand() % max_X ;
//    printf("rand val %d \n",rand());
    Y_location  = rand() % max_Y ;

    loc[0] =X_location;
    loc[1] =Y_location;

    return loc;
}

/**
 * Generate a valid location can be accessible all path
 * @param map
 * @return
 */
int * getValidLocation(map *map  ){
//    printf("Processe : getting valide location \n");

    int * loc;
    int max_X = getMapRowSize(map);
    int max_Y = getMapColSize(map);
    int side_available  = 0;
    int side_occurrence = 0;
    bool valid = false;
    int **mapData;

    while (valid == false) {

        loc = randLocation(map);
        int x = loc[0];
        int y = loc[1];
        if (map->mapData[x][y] == 0) {
            valid = true;
        }
    }
//    printf("im outside while \n");

    return loc;
}

/**
 * add portal travel between zone depend on map and map param
 * @param map
 */
void addPortal(map* map){
    printf("Progress : generate Portal ... \n");

    int level ;
    int *loc = malloc(sizeof(int)* 2);

    level = getLevel(map);
    printf("Get map level :%d \n",level);
    //add portal travel between zone1-2
    if(level == 1 || level == 2){
        loc = getValidLocation(map);
        int x = loc[0];
        int y = loc[1];

        map->mapData[x][y] = -2;
    }

    //add portal travel between zone2-3
    if(level == 2 || level == 3){
        loc= getValidLocation(map);
        int x = loc[0];
        int y = loc[1];

        map->mapData[x][y] = -3;
    }

}

/**
 * add plants on map (mini 3)
 * @param map
 */
void addPlants(map* map){
    printf("Progress : generate Plants ... \n");

    int limit  ;
    int level ;
    int * loc = malloc(sizeof(int)* 2);
    int ** zone1 ;
    int x;
    int y;


    limit = getMapMaxPlants(map);
    level = getLevel(map);
    zone1 = map->mapData;

    for (int i = 0; i < limit; ++i) {
        loc = getValidLocation(map);
        x = loc[0];
        y = loc[1];
        zone1[x][y] = level*3+0 ;
    }
    printf("Progress : %d Plants have been generate... \n",limit );
}

/**
 * add rocks on map
 * @param map
 */
void addRocks(map* map){
    printf("Progress : generate Rocks ... \n");
    int limit  ;
    int level ;
    int * loc = malloc(sizeof(int)* 2);
    int ** zone1 ;
    int x ;
    int y ;


    limit = getMapMaxRocks(map);
    level = getLevel(map);
    zone1 = map->mapData;
    for (int i = 0; i < limit; ++i) {
        loc = getValidLocation(map);
        x = loc[0];
        y = loc[1];
        zone1[x][y] = level*3+1 ;
    }
    printf("Progress : %d Rocks have been generate... \n",limit );

}

/**
 * add trees on maps
 * @param map
 */
void addTrees(map* map){
    printf("Progress : generate Trees ... \n");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **zone1 ;
    int x ;
    int y ;


    limit = getMapMaxTrees(map);
    level = getLevel(map);
    zone1 = map->mapData;

    for (int i = 0; i < limit; ++i) {
        loc = getValidLocation(map);
        x = loc[0];
        y = loc[1];
        zone1[x][y] = level*3+2 ;
    }
    printf("Progress : %d tree have been generate... \n",limit );

}

/**
 * add enemies on map
 * @param map
 */
void addEnemies(map* map) {
    printf("Progress : generate enemies ... \n");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **zone1 ;
    int x ;
    int y ;

    //add monster list and zone;
    limit = getMapMaxEnemies(map);
    zone1 = map->mapData;

    for (int i = 0; i < 1; ++i) {
        loc = getValidLocation(map);
        x = loc[0];
        y = loc[1];
        zone1[x][y] = 15 ;
    }
    printf("Progress : %d enemies have been generate... \n",limit );

}

/**
 * Add boss ID 99 in zone 3
 * @param map
 */
void addBoss(map* map){
    printf("Progress : generate Boss ... \n");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **mapData ;
    int x ;
    int y ;

    mapData = map->mapData;


    loc = getValidLocation(map);
    x = loc[0];
    y = loc[1];
    mapData[x][y] = 1 ;

    printf("Progress : Boss have been add... \n");

};

/**
 * add enemies on map
 * @param map
 */
void addPlayer(map* map) {
    printf("Progress : generate Player ... \n");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **zone1 ;
    int x ;
    int y ;

    zone1 = map->mapData;

    loc = getValidLocation(map);
    x = loc[0];
    y = loc[1];
    zone1[x][y] = 1 ;

    printf("Progress : Player have been add... \n");

}

/**
 * add enemies on map
 * @param map
 */
void addNPC(map* map) {
    printf("Progress : generate NPC ... \n");
    int limit  ;
    int level ;
    int *loc = malloc(sizeof(int)* 2);
    int **zone1 ;
    int x ;
    int y ;

    //add monster list and zone;
    zone1 = map->mapData;

    loc = getValidLocation(map);
    x = loc[0];
    y = loc[1];
    zone1[x][y] = 2 ;

    printf("Progress : NPC have been add ... \n");

}

/**
 * add border on map
 * @param map
 */
void addBorder(map* map) {
    printf("Progress : add border  ... \n");
    int **zone1 ;
    int max_X = getMapRowSize(map);
    int max_Y = getMapColSize(map);
    int min_y = 0;
    int min_x = 0;

    zone1 = map->mapData;

    for (int i = 0; i < max_Y; ++i) {
        zone1[min_x][i] = -1 ;
        zone1[max_X-1][i] = -1 ;
    }

    for (int i = 0; i < max_X; ++i) {
        zone1[i][min_y] = -1 ;
        zone1[i][max_Y-1] = -1 ;
    }

    printf("Progress : border have been add ... \n");

}
/**
 * insert Elements on map
 * @param map
 */
void insertElements(map* map){
    printf("Progress : Insert element ... \n");

//    addBorder(map);
    addPlayer(map);
    addNPC(map);
    addPortal(map);
    addPlants(map);
    addRocks(map);
    addTrees(map);
    addEnemies(map);

    if(3 == getLevel(map)){
        addBoss(map);
    }
}

/**
 * generate a 2 dimension array use as map fill with '0' // 0 = path
 * @param row
 * @param col
 * @return empty map
 */
int** init_empty_map(int row , int col){
    printf("Progress : generate empty map ... \n");

    int** map =  malloc(sizeof(int*) * row);

    for (int i = 0; i < row; ++i) {
        map[i]=  malloc(sizeof(int) * col);
    }

    // fill map with path
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col ; ++y) {
            map[x][y] = 0;
//            printf("%d ",map[x][y]);
        }
//        printf("\n");
    }
    printf("Progress : end generate empty map ... \n");

    return map;

}




/**
 * random max recourse val
 * @return [ Max_enemies,Max_rocks ,Max_plants , Max_trees]
 */
int* randResources(){
    printf("Progress : Setting resources limit amount  ... \n");
    int randRatio = 3;
    int* rand_Resource = malloc(sizeof(int)*4);

    rand_Resource[0] = rand() % randRatio +10;   //enemies
    rand_Resource[1] = rand() % randRatio +3;    //rocks
    rand_Resource[2] = rand() % randRatio +3;    //plants
    rand_Resource[3] = rand() % randRatio +3;    //trees

    return rand_Resource;

}


void printColorCode(int locationCode){

    switch (locationCode) {
        case -3:// portal
        case -2:
        case -50: // reset
            printf("\033[1;37m");break;
        case -1: // wall
            printf("\033[0;30m");break;
        case 1: // player
        case 2: // NPC
            printf("\033[0;36m"); break;
        case 3: // plant
        case 6:
        case 9:
            printf("\033[0;33m"); break;
        case 4: // Rock
        case 7: // Rock
        case 10: // Rock
            printf("\033[0;38m"); break;
        case 5: // tree
        case 8: // tree
        case 11: // tree
            printf("\033[0;32m"); break;
        case 0: // road
            printf("\033[1;30m"); break;
        default:
            if(locationCode >=12 && locationCode <= 98){
                printf("\033[0;31m");
            }else if(locationCode == 99){
                printf("\033[0;35m");
                break;
            }
    }
}

void printMap(map *map){
    int row , col;
    row = getMapRowSize(map);
    col = getMapColSize(map);
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col; ++y) {
            printColorCode(map->mapData[x][y]);
            printf("%3d ",map->mapData[x][y]);
        }
        printf("\n");
    }
    printColorCode(-50);
}

/**
 * init map by level zone
 * @param zone_level
 * @return map*
 */
map* initMapConfiguration(int zone_level){
    printf("init map default configuration ... \n");
    int *randResourcesVal = malloc(sizeof(int));
    int row , col;

    map *map = malloc(sizeof(map));
    map->mapInformation = malloc(sizeof(mapParam));

    map->level = zone_level;

    map->mapInformation->row_size    = 20;
    map->mapInformation->col_size    = 20;
    map->mapInformation->max_enemies = randResourcesVal[0]+10;
    map->mapInformation->max_rocks   = randResourcesVal[1]+3;
    map->mapInformation->max_plants  = randResourcesVal[2]+3;
    map->mapInformation->max_trees   = randResourcesVal[3]+3;

    row = map->mapInformation->row_size;
    col = map->mapInformation->col_size;
    map->mapData = init_empty_map(row,col);

    randResourcesVal = randResources();
    insertElements(map);
    return map;

}

/**
 * init
 * @param row
 * @param col
 * @return
 */
map* init_zone1(){
    map* map_zone1 ;

    map_zone1 = initMapConfiguration(1);

    return map_zone1;
}

map* init_zone2(){
    map* map_zone2 ;

    map_zone2 = initMapConfiguration(2);

    return map_zone2;
}

map* init_zone3(){
    map* map_zone3 ;

    map_zone3 = initMapConfiguration(3);

    return map_zone3;
}


#endif //MALLOCWORLD_MAPBUILDER_H

//
// Created by wuchi on 2021/10/12.
//

#ifndef MALLOCWORLD_GENEARTORMAP_H
#define MALLOCWORLD_GENEARTORMAP_H

#include "./mapParam.h"
#include ""

typedef struct map {
    int ** map;
    mapParam* mapInformation;
}map;

map* initMap(){

}

/**
 * generate a 2 dimension array use as map fill with '0' // 0 = path
 * @param row
 * @param col
 * @return empty map
 */

int** gen_empty_map(int row , int col){
    int** map = (int*) malloc(sizeof(int*) * row);

    for (int i = 0; i < row; ++i) {
        map[i]= (int*) malloc(sizeof(int) * col);
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
 * generate random location [X,Y]
 * @param max_X
 * @param max_Y
 * @return [0-max_X , 0-max_Y]
 */
int* randLocation(int max_X , int max_Y){
    int* loc = (int) malloc(sizeof(int)* 2);
    int X_location= rand() % max_X ;
    int Y_location= rand() % max_Y ;

    loc[0] =X_location;
    loc[1] =Y_location;

    return loc;
}
/**
 * random max recourse val
 * @return [ Max_enemies,Max_rocks ,Max_plants , Max_trees]
 */
int* randResources(){
    randRatio = 3;
    int* rand_Resources = (int)malloc(sizeof(int)*4);
    rand_Ressource[0] = rand % randRatio +10;   //enemies
    rand_Ressource[1] = rand % randRatio +3;    //rocks
    rand_Ressource[2] = rand % randRatio +3;    //plants
    rand_Ressource[3] = rand % randRatio +3;    //trees

    return rand_Ressource;

}

void addRocks(int** map ,mapParam mapInformation){

    for (int x = 0; x < ; ++x) {

    }
    
}
void addPlants(int** map ,mapParam mapInformation){

}
void addTrees(int** map ,mapParam mapInformation){

}

void addEnemies(int** map ,mapParam mapInformation) {

}

int* insertResource(int** map ,mapParam mapInformation){

}

int** gen_zone1(){

    int** map = gen_empty_map(row,col);
    int* randResources = randResources();
    mapParam* mapInformation = (mapParam) malloc(sizeof(mapParam));

    mapInformation->col_size    = col;
    mapInformation->row_size    = row;
    mapInformation->max_enemies = randResources[0];
    mapInformation->max_rocks   = randResources[1];
    mapInformation->max_plants  = randResources[2];
    mapInformation->max_trees   = randResources[3];

}

int** gen_zone2(){

}

int** genere_zone3(){

}

#endif //MALLOCWORLD_GENEARTORMAP_H

//
// Created by wuchi on 2021/10/12.
//

#ifndef MALLOCWORLD_MAPACTION_H
#define MALLOCWORLD_MAPACTION_H

#include "./mapBuilder.h"

/**
 *
 * @return maps
 */

map* gen_map(int zone_number){
    map *map;
    switch (zone_number) {
        case 1:
        default:
            printf("Progress : init zone 1 ... \n");
            map = init_zone1();
            break;
        case 2:
            printf("Progress : init zone 2 ... \n");
            map = init_zone2();
            break;
        case 3:
            printf("Progress : init zone 3 ... \n");
            map = init_zone3();
            break;
    }

    return map;
}

int* PlayerLocalize(map *map){
    int row , col;
    int *localisation = malloc(sizeof (int) *2);
//    printf(" 3 \n");
    row = getMapRowSize(map);
    col = getMapColSize(map);
    printf(" 1 \n");
    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col; ++y) {
            if(map->mapData[x][y] == 1 ){
                localisation[0] = x;
                localisation[1] = y;
                return localisation;
            }
        }
    }
}

int isPortal(int element){
    return (element == -2 || element == -3) ;
}

int isWall(int element){
    return element == -1 ;
}

int isRoad(int element){
    return element == 0 ;
}

int isNPC(int element){
    return element == 2 ;
}

int isPlant(int element){
    return (element == 3 || element == 6 || element == 9 ) ;
}

int isRock(int element){
    return (element == 4 || element == 7 || element == 10 ) ;
}

int isTree(int element){
    return (element == 5 || element == 8 || element == 11 ) ;
}

int isMonster(int element){
    return (element >=12 && element <=99) ;
}

int isBoss(int element){
    return element == 99 ;
}

int isResource(int element){
    return (isPlant(element) || isTree(element) || isRock(element));
}

#endif //MALLOCWORLD_MAPACTION_H

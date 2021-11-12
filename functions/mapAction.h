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
            printf("init zone 1 ... \n");
            map = init_zone1();
            break;
        case 2:
            printf("init zone 2 ... \n");
            map = init_zone2();
            break;
        case 3:
            printf("init zone 3 ... \n");
            map = init_zone3();
            break;
    }

    return map;
}

#endif //MALLOCWORLD_MAPACTION_H

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

int** gen_map(int zone_number){

    switch (zone_number) {
        case 1:
        default:
            map = init_zone1();
            break;
        case 2:
            map = init_zone2();
            break;
        case 3:
            map = init_zone3();
            break;
    }

    return map;
}

#endif //MALLOCWORLD_MAPACTION_H

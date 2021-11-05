//
// Created by wuchi on 2021/10/22.
//

#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H

#include <stdlib.h>
#include "items.h"

typedef struct invInfo{
    int item_id;
    int stock;
}invInfo;

typedef struct inventory{
    invInfo* inv;
    struct inventory* next_item;
}inventory;



/**
 * add tool in inventory
 * @param val
 * @return
 */

void addToolInv(int val){

    switch (val) {
        case '2':

            break;


    }

}

void initStartKits(){

}

/**
 *
 * @param val
 */




#endif //MALLOCWORLD_INVENTORY_H

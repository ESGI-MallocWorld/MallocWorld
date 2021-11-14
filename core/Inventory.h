//
// Created by wuchi on 2021/10/22.
//

#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H

#include <stdlib.h>
#include "items.h"

/*
* The inventory of the player can  have a maximum stock of 20 for the resources and only 1 for the other items
* The inventory of the player can be a linked list with a maximum length of 10 
* The inventory of the PNJ has no such limits
*/

typedef struct invInfo{
    int item_id;
    int durability;
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

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
 * Create add in inventory
 * @param val
 * @return
 */


void initStartKits(){

}

/**
 *
 * @param val
 */
void addToolInv(int val){

    switch (val) {
        case '2':

            break;


    }



}



#endif //MALLOCWORLD_INVENTORY_H

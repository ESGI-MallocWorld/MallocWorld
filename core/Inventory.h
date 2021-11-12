//
// Created by wuchi on 2021/10/22.
//

#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H

#include <stdlib.h>

typedef struct invInfo{
    int item_id;
    int stock;
}invInfo;

typedef struct inventory{
    invInfo* inv;
    struct inventory* next_item;
}inventory;

typedef struct Tools{
    int id;
    char* name;
    int durability;
    int** craftResources; //2 rows and 2 columns; First column = resource id, second column=quantity
} Tools;

/**
 * Create tool and add in inventory
 * @param val
 * @return
 */
Tools* addTool(int val){
    Tools *tool;
    tool = malloc(sizeof(Tools));

    tool->id = val;
    tool->durability = 10; // all tools durability is 10

    switch (val) {
        case 2: // wooden pickaxe
            tool->name  = "Pioche en bois";
            break;
        case 3: // wooden machete
            tool->name  = "Serpe en bois";
            break;
        case 4: // wooden axe
            tool->name  = "Hache en bois";
            break;
        case 12:// stone pickaxe
            tool->name  = "Pioche en pierre";
            break;
        case 13:// stone machete
            tool->name  = "Serpe en pierre";
            break;
        case 14:// stone axe
            tool->name  = "Hache en pierre";
            break;
        case 23:// iron pickaxe
            tool->name  = "Pioch en fer";
            break;
        case 24:// iron machete
            tool->name  = "Serpe en fer";
            break;
        case 25:// iron axe
            tool->name  = "Hachen en fer";
            break;

    }
    return tool;
}

void initStartKits(){

}

/**
 *
 * @param val
 */
void createTool(int val){

    switch (val) {
        case '2':

            break;


    }



}



#endif //MALLOCWORLD_INVENTORY_H

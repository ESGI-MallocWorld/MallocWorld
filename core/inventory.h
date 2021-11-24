//
// Created by wuchi on 2021/10/22.
//

#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H

#include <stdlib.h>


/*
* The inventory of the player can  have a maximum stock of 20 for the resources and only 1 for the other items
* The inventory of the player can be a linked list with a maximum length of 10 
* The inventory of the PNJ has no such limits
*/

/*
typedef struct invInfo{
    int item_id;
    int durability;
    int stock;
}invInfo;
*/
typedef struct invInfo invInfo;
typedef struct inventory inventory;

typedef struct invInfo{
    Item* item;
    int stock;
}invInfo;


typedef struct inventory{
    invInfo* inv;
    struct inventory* next;
}inventory;

inventory* checkIfItemPresent(Item*,inventory*);

inventory* newElement(Item*, int);

int getSizeInv(inventory*);

/**
 * add tool in inventory
 * @param val
 * @return
 */

int addItemInvPlayer(Item*, inventory*, int);

void addItemInvPNJ(Item*, inventory*, int);

void displayInventory(Type, inventory*);

void displayEntireInv(inventory*);

void moveItemFromInvPlayerToInvPNJ(Item*, inventory*, inventory*);

void moveItemFromInvPNJToInvPlayer(Item*, int, inventory*, inventory*);

int getStockItem(int, inventory*);

int deleteItemFromInv(Item*, inventory*, int);

void deleteElFromLinkedList(inventory*, Item*);

void initStartKits();


#endif

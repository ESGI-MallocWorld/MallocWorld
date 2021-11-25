//
// Created by wuchi on 2021/10/22.
//

#ifndef MALLOCWORLD_INVENTORY_H
#define MALLOCWORLD_INVENTORY_H

#include <stdlib.h>
#include "itemsUnified.h"


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

void displayInvPerType(Type, inventory*);

void displayEntireInv(inventory*);

void moveItemFromInvPlayerToInvPNJ(Item*, int, inventory*, inventory*);

void moveItemFromInvPNJToInvPlayer(Item*, int, inventory*, inventory*);

int getStockItem(int, inventory*);

int deleteItemFromInv(Item*, inventory*, int);

void deleteElFromLinkedList(inventory*, Item*);

/**
 * function that returns the item the player wants to craft if he/she has enough resources
 * choise 1 = player wants to add the item to his own inventory || choise 2 = player wants to add the item to the PNJ's inventory
 * @param itemID
 * @param invPlayer
 * @param invPNJ
 * @param choiseAdd
 */

void craftItem(int, inventory*, inventory*, int);

int checkResources (int, inventory*, inventory*);

/**
 * function that adds the given resource to the given inventory if the player's inventory contains the required resource with the required durability
 * The function also decreases the durability of the tool with which the player harvest the resource.
 * @param resource
 * @param inv
 */
void addResourcetoInv(Item*, inventory*);

/**
 * function that adds the resource (linked to the item ID given as a parameter) to the inventory of the player
 * @param val
 * @param inv
 */
void harvestResource (int, inventory*);

/**
 * function that returns the asked for tool, if the player has it in its inventory
 * @return
 */
Item* isToolInInv(Item* ,inventory*);


#endif

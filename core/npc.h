#include"inventory.h"


#ifndef MALLOCWORLD_NPC_H
#define MALLOCWORLD_NPC_H


inventory* newInventory();

int getSize(inventory* inv1);

void printInventory(inventory* inv1);

inventory* browseItem(inventory* inv1,int number);

inventory* newItem(inventory* inv1);

void addItem(inventory* itemAdded, inventory* inv1);

void deleteItem(inventory* inv1, int number);

void depositItems(inventory* inv1, inventory* inv2);

void takeItems(inventory* inv2, inventory* inv1);

void verifyNotTypeResource(int val);

inventory* deleteNode(inventory* inv1);

int deleteItemFromCraft(inventory* inv1, int id, int amount);

int verifyInInventory(inventory* inv1, int id, int amount);

int verifyResources(inventory* inv1, int val,int ressourceNumber);

inventory* newItemFromCraft(int val);

void addItemFromCraft(inventory* newItem, inventory* inv1);

void craft(inventory* inv1,int val);

void craftItems(inventory* invPlayer);

void startNPC(inventory* invPlayer, inventory* invNPC);


#endif //MALLOCWORLD_NPC_H

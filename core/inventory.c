#include<stdio.h>
#include<stdlib.h>
#include"inventory.h"
#include"itemsUnified.h"

inventory* checkIfResourcePresent(Item* item,inventory* inv){
    inventory* newInv = malloc(sizeof(inventory));
    while(inv != NULL){
        if(inv->invInfo->item == item){
            newInv = inv;
            return newInv;
        }
        inv = inv->next;
    }
}

int getSizeInv(inventory* inv){
    int size = 0;
    while (inv != 0){
        size+=1;
        inv = inv->next;
    }
}

inventory* newElement(Item* item){ //function that creates a new element in a linked list
    inventory* inv = malloc(sizeof(inventory));
    inv->invInfo->item = item;
    inv->invInfo->stock = 1;
    inv->next = NULL;
    return inv;
}

void addItemInvPlayer(Item* item, inventory* inv){
    int size = getSizeInv(inv);
    inventory* invExistingResource = checkIfResourcePresent(item, inv);
    if ( size == 20){ //checks if player's inventory isn't full
        printf("Sorry your inventory is full. You cannot add another item");
        return NULL;
    }
    if(item->itemType == Resource){ //checks if item is a resource
        if(invExistingResource != NULL){ // checks if the resource is already present in the inventory
            invExistingResource->invInfo->stock +=1; 
        }
    }else{ //Adds the item as a new element of the linked list inventory
        while(inv->next!=NULL){
            inv = inv->next;
        }
        inv->next = newElement(item);        
    }    



}

void addItemInvPNJ(Item* item, inventory* inv){
}
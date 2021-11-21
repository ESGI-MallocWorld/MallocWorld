#include<stdio.h>
#include<stdlib.h>
#include "inventory.h"
#include "itemsUnified.h"

inventory* checkIfItemPresent(Item* item,inventory* inv){
    inventory* newInv = malloc(sizeof(inventory));
    while(inv != NULL){
        if(inv->inv->item->id == item->id){
            newInv = inv;
            return newInv;
        }
        inv = inv->next;
    }
    return NULL;
}

int getSizeInv(inventory* inv){
    int size = 0;
    while (inv != 0){
        size+=1;
        inv = inv->next;
    }
}

inventory* newElement(Item* item, int newStock){ //function that creates a new element in a linked list
    inventory* inv = malloc(sizeof(inventory));
    inv->inv->item = item;
    inv->inv->stock = newStock; //initialises the stock to the number given as parameter;
    inv->next = NULL;
    return inv;
}

void addItemInvPlayer(Item* item, inventory* inv, int newStock){
    if(item == NULL){
      break;  
    }
    int size = getSizeInv(inv);
    inventory* invExistingResource = checkIfItemPresent(item, inv);
    if(item->itemType == Resource && invExistingResource != NULL){ //checks if item is a resource && checks if the resource is already present in the inventory
        if(invExistingResource->inv->stock < 20){ //checks if the player's resource inventory isn't full
            invExistingResource->inv->stock += newStock; 
        }
        else if(size<10){ //if the inventory is not full yet, the resource can be added ad the end of the linked list
            while(inv->next!=NULL){
            inv = inv->next;
            }
            inv->next = newElement(item,newStock);//adds the resource and its stock to the next pointer of the last case of the linked list
            if (newStock == 1){
                printf("%d %s has been added to your inventory ", newStock, item->name);
            }else{
                printf("%d pieces of %s have been added to your inventory ", newStock, item->name);  
            }  
        }
        else{
            printf("Sorry your inventory space for %s is full. You cannot add another %s. Go find the PNJ to empty your inventory", item->name);
        }
        
    }else{ //Adds the item as a new element of the linked list inventory if size <10
        if ( size == 10){ //checks if player's inventory isn't full
            printf("Sorry your inventory is full. You cannot add another item");
        }
        else{
            while(inv->next!=NULL){
                inv = inv->next;
            }
            inv->next = newElement(item,newStock);//add the item to the next pointer of the last case of the linked list
            printf("%d %s has been added to your inventory ", newStock, item->name);
        }         
    }    

}

void addItemInvPNJ(Item* item, inventory* inv,int newStock){
    if(item == NULL){
      break;  
    int size = getSizeInv(inv);
    inventory* invExistingResource = checkIfItemPresent(item, inv);
    if(invExistingResource != NULL){ //checks if the item is already present in the inventory
        invExistingResource->inv->stock += newStock;
        if (newStock == 1){
            printf("%d %s has been added to your inventory ", newStock, item->name);
        }
        else{
            printf("%d pieces of %s have been added to your inventory ", newStock, item->name);
        }
    }
    else{//if the item isn't present in the inventory
        while(inv->next!=NULL){
            inv = inv->next;
        }
        inv->next = newElement(item,newStock);//add the item to the next pointer of the last case of the linked list
        printf("%d %s has been added to your inventory ", newStock, item->name)         
    } 
}

void deleteItemFromInv(Item* item, inventory* inv, int quantity){
    *inventory newInv = checkIfItemPresent(item, inv);
    *inventory temp;
    if(newInv == NULL){
        printf("%s is not present in the inventory", item->name);
    }
    else if(newInv->inv->stock > quantity){//if the stock of the item is larger than the quantity the player wants to retract
        newInv->inv->stock = newInv->inv->stock - quantity;
    }
    else if(newInv->inv->stock == quantity){ //if the stock of the item is exactly the same as the amount of items the player wants to retract
        if(inv->inv->item == item){ // if item is stocked in the first case of the inventory 
          temp = inv; 
          inv = inv->next;
          free(temp);
        }
        else{
            while(inv->next != NULL){
                if(inv->next->inv->item == item){
                    temp = inv->next;
                    inv->next = inv->next->next;
                    free(temp);
                }
            inv = inv->next;
            }  
        }              

    }
    else{//if the amount of items the player wants to retract is larger than the actual stock in the inventory

    }


}

void moveItemFromInvPNJToInvPlayer(Item* item, int quantity, inventory* invPNJ, inventory* invPlayer){
deleteItemFromInv(item, invPNJ, quantity);
addItemInvPlayer(item,invPlayer,quantity);
}

void moveItemFromInvPlayerToInvPNJ(Item* item, int quantity, inventory* invPlayer, inventory* invPNJ){
deleteItemFromInv(item, invPlayer, quantity);
addItemInvPNJ(item,invPNJ,quantity);
}

void displayEntireInv(inventory* inv){
    while(inv!=NULL){
            if(inv->inv->stock == 1){
                printf("You have %d %s", inv->inv->stock, inv->inv->item->name);
            }
            else{
                printf("You have %d %ss", inv->inv->stock, inv->inv->item->name); 
            }
        inv = inv->next;
    }
}

void displayInvPerType(Type type, inventory* inv){
    while(inv!=NULL){
        if(inv->inv->item->itemType == type){
            if(inv->inv->stock == 1){
                printf("You have %d %s", inv->inv->stock, inv->inv->item->name);
            }
            else{
                printf("You have %d %ss", inv->inv->stock, inv->inv->item->name); 
            }
        }
        inv = inv->next;
    }
}
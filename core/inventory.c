#include<stdio.h>
#include<stdlib.h>
#include "inventory.h"
#include "itemsUnified.c"

inventory* newInventory(){
    inventory* invData = malloc(sizeof(inventory));
    return invData;
}

int getStockAmount(inventory *inventoryData){
    return inventoryData->inv->stock ;
}


inventory* getInventoryByItem(Item* item,inventory* inv){
    inventory* newInv = newInventory();
    while(inv != NULL){
        if(inv->inv->item->id == item->id){
            invData = inv;
            return invData;
        }
        inv = inv->next;
    }
    return NULL;
}

int checkIfItemPresent(Item* item,inventory* inv){
    if(getInventoryByItem(item,inv) != NULL){
        return 1;
    }
    return 0;
}

int getSizeInv(inventory* inv){
    int size = 0;
    while (inv != 0){
        size+=1;
        inv = inv->next;
    }
}

int getStockItem(int itemID, inventory* inv){
    inventoryData = getInventoryByItem(itemID,inv);
    return getStockAmount(inventoryData);
}


inventory* newElement(Item* item, int newStock){ //function that creates a new element in a linked list
    inventory* inv = newInventory();
    inv->inv->item = item;
    inv->inv->stock = newStock; //initialises the stock to the number given as parameter;
    inv->next = NULL;
    return inv;
}

int addItemInvPlayer(Item* item, inventory* inv, int newStock){
    int size = getSizeInv(inv);
    inventory* invExistingResource = checkIfItemPresent(item, inv);
    if((item->itemType == Resource || item->itemType == Potion) && invExistingResource != NULL){ //checks if item is a resource && checks if the resource is already present in the inventory
        if(invExistingResource->inv->stock < 20){ //checks if the player's resource inventory isn't full
            invExistingResource->inv->stock += newStock; 
        }else if(size<10){ //if the inventory is not full yet, the resource can be added ad the end of the linked list
            while(inv->next!=NULL){
                inv = inv->next;
            }
            inv->next = newElement(item,newStock);//adds the resource and its stock to the next pointer of the last case of the linked list
            if (newStock == 1){
                printf("%d %s has been added to your inventory \n", newStock, item->name);
            }else{
                printf("%d pieces of %s have been added to your inventory \n", newStock, item->name);  
            }
            return 1;  
        }
        else{
            printf("Sorry your inventory is full. Go find the PNJ to empty your inventory \n");
            return 0;
        }
        
    }else{ //Adds the item as a new element of the linked list inventory if size <10
        if ( size == 10){ //checks if player's inventory isn't full
            printf("Sorry your inventory is full. You cannot add another item. Go find the PNJ to empty your inventory \n");
            return 0;
        }
        else{
            while(inv->next!=NULL){
                inv = inv->next;
            }
            inv->next = newElement(item,newStock);//add the item to the next pointer of the last case of the linked list
            printf("%d %s has been added to your inventory \n", newStock, item->name);
            return 1;
        }         
    }    

}

void addItemInvPNJ(Item* item, inventory* inv,int newStock){
    if(item == NULL){
      break;  
    int size = getSizeInv(inv);
    inventory* invExistingItem = checkIfItemPresent(item, inv);
    if(invExistingItem != NULL){ //checks if the item is already present in the inventory
        invExistingItem->inv->stock += newStock;
        if (newStock == 1){
            printf("%d %s has been added to the PNJ's inventory \n", newStock, item->name);
        }else{
            printf("%d pieces of %s have been added to the PNJ's inventory \n", newStock, item->name);
        }
    }else{//if the item isn't present in the inventory
        while(inv->next!=NULL){
            inv = inv->next;
        }
        tempItem = initItem(item->id);
        item->durability = tempItem->durability;//items are automatically repared when they are moved to the PNJ's inventory
        inv->next = newElement(item,newStock);//add the item to the next pointer of the last case of the linked list
        printf("%d %s has been added to the PNJ's inventory \n", newStock, item->name)
        free(tempItem);
    } 
}

void deleteElFromLinkedList(inventory* inv, Item* item){
    *inventory temp;
    if(inv->inv->item->id == item->id){ // if item is stocked in the first case of the inventory 
        temp = inv; 
        inv = inv->next;
        free(temp);
    }
    else{
        while(inv->next != NULL){
            if(inv->next->inv->item->id == item->id){
                temp = inv->next;
                inv->next = inv->next->next;
                free(temp);
                }
            inv = inv->next;
        }  
    }              
}

int deleteItemFromInv(Item* item, inventory* inv, int quantity){
    int stockInInv = getStockItem(item->id, inv);
    int amount = quantity;
    if(stockInInv > 0 && stockInInv < amount){ //if the inventory hasn't enough pieces of the looked for item
        printf("You only have %d pieces of %s in the inventory \n", stockInInv, item->name);
        return 0;
    } 
    else if(stockInInv == 0){ //if the item is not present in the inventory
        printf("There is no %s present in the inventory\n", item->name);
        return 0;
    }
    else{
        *inventory temp;
        int difference = amount - inv->inv->stock;
        if(inv->inv->item->id == item->id){ // if item is stocked in the first case of the inventory
            if(difference==0){//if the demanded quantity is equal to the stock present in the first item's case
                temp = inv; 
                inv = inv->next;
                free(temp);
                printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                return 1;
            }
            if else (difference>0){ //if the demanded amount is higher than the stock present in the first item's case
                amount -= inv->inv->stock; 
                temp = inv; 
                inv = inv->next;
                free(temp);
                 
            }
            else{//if the stock in the inventory of the first item's case is higher than the demanded amount
                inv->inv->stock -= amount;
                printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                return 1;
            }       
        }
        //if item is not stocked in the first case or if the demanded amount is higher than what has already been withdrawn and the item is stocked in multiple cases 
        while(inv->next != NULL){
            difference = amount - inv->next->inv->stock;
            if(inv->next->inv->item->id == item->id){//checks if the item can be found in the next case
                if(difference==0){//if the demanded quantity is equal to the stock present in the next item's case
                    temp = inv->next;
                    inv->next = inv->next->next;
                    free(temp);
                    printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                    return 1;
                }
                if else (difference>0){//if the demanded amount is higher than the stock present in the next item's case
                    amount -= inv->next->inv->stock; 
                    temp = inv->next;
                    inv->next = inv->next->next;
                    free(temp);
                }
                else{//if the stock in the inventory of the next item's case is higher than the demanded amount
                    inv->next->inv->stock -= amount;
                    return 1;
                    printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                }

                
            }
        inv = inv->next;
        }  
        
    }

}

void moveItemFromInvPNJToInvPlayer(Item* item, int quantity, inventory* invPNJ, inventory* invPlayer){
    deleteItemFromInv(item, invPNJ, quantity);
    if (deleteItemFromInv == 1){
        addItemInvPlayer(item,invPlayer,quantity);
    }
}

void moveItemFromInvPlayerToInvPNJ(Item* item, int quantity, inventory* invPlayer, inventory* invPNJ){
    deleteItemFromInv(item, invPlayer, quantity);
    if (deleteItemFromInv == 1){
        addItemInvPNJ(item,invPNJ,quantity);
    }
}

void displayEntireInv(inventory* inv){
    while(inv!=NULL){
            if(inv->inv->stock == 1){
                printf("You have %d %s \n", inv->inv->stock, inv->inv->item->name);
            }
            else{
                printf("You have %d %s \ns", inv->inv->stock, inv->inv->item->name); 
            }
        inv = inv->next;
    }
}

void displayInvPerType(Type type, inventory* inv){
    while(inv!=NULL){
        if(inv->inv->item->itemType == type){
            if(inv->inv->stock == 1){
                printf("You have %d %s \n", inv->inv->stock, inv->inv->item->name);
            }
            else{
                printf("You have %d %s \ns", inv->inv->stock, inv->inv->item->name); 
            }
        }
        inv = inv->next;
    }
}
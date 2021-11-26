#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "inventory.h"

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
      exit(0);
    }
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
        Item *tempItem = initItem(item->id);
        item->durability = tempItem->durability;//items are automatically repared when they are moved to the PNJ's inventory
        inv->next = newElement(item,newStock);//add the item to the next pointer of the last case of the linked list
        printf("%d %s has been added to the PNJ's inventory \n", newStock, item->name);
        free(tempItem);
    } 
}

void deleteElFromLinkedList(inventory* inv, Item* item){
    inventory* temp;
    if(inv->inv->item->id == item->id){ // if item is stocked in the first case of the inventory 
        temp = inv; 
        inv = inv->next;
        free(temp);
    }else{
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


void deleteItemFromInv(Item* item, inventory* inv, int quantity){
    int stockInInv = getStockItem(item->id, inv);
    int newAmount = stockInInv - quantity;

    inventory *inventoryData = getInventoryByItem(item , inv);

    inventoryData->inv->stock = newAmount;

    if(newAmount == 0 ){
            temp = inv;
            inv = inv->next;
            free(temp);
    }
    else{
        inventory* temp;
        int difference = amount - inv->inv->stock;
        if(inv->inv->item->id == item->id){ // if item is stocked in the first case of the inventory
            if(difference==0){//if the demanded quantity is equal to the stock present in the first item's case
                temp = inv; 
                inv = inv->next;
                free(temp);
                printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name );
                return 1;
            }
            else if (difference>0){ //if the demanded amount is higher than the stock present in the first item's case
                amount -= inv->inv->stock; 
                temp = inv; 
                inv = inv->next;
                free(temp);
                 
            }
            else{//if the stock in the inventory of the first item's case is higher than the demanded amount
                inv->inv->stock -= amount;
                printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name );
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
                    printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name);
                    return 1;
                }
                else if (difference>0){//if the demanded amount is higher than the stock present in the next item's case
                    amount -= inv->next->inv->stock; 
                    temp = inv->next;
                    inv->next = inv->next->next;
                    free(temp);
                }
                else{//if the stock in the inventory of the next item's case is higher than the demanded amount
                    inv->next->inv->stock -= amount;
                    return 1;
                    printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name);
                }
            } while (inv->next != NULL);

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

void deleteItemFromInv2(Item* item, inventory* inv, int quantity) {
    int stockInInv = getStockItem(item->id, inv);
    int newAmount = stockInInv - quantity;

    inventory *inventoryData = getInventoryByItem(item, inv);

    inventoryData->inv->stock = newAmount;

    if (newAmount == 0) {
        temp = inv;
        inv = inv->next;
        free(temp);
    }
}

void moveItemFromInvPNJToInvPlayer(Item* item, int quantity, inventory* invPNJ, inventory* invPlayer){
    int res = deleteItemFromInv(item, invPNJ, quantity);
    if (res == 1){ // créer une function qui controle les donner et puis appelle cette function
        addItemInvPlayer(item,invPlayer,quantity);
    }
}

void moveItemFromInvPlayerToInvPNJ(Item* item, int quantity, inventory* invPlayer, inventory* invPNJ){
    int res = deleteItemFromInv(item, invPlayer, quantity);
    if (res == 1){
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

//function that checks if the inventory of the player contains the required resources for the item he wants to create
int checkResources (int itemId, inventory* invPlayer, inventory* invPNJ){
    Item* item;
    item = initItem(itemId);
    int idCraftRes1 = item->craftResources[0][0];
    int idCraftRes2 = item->craftResources[1][0];
    int stockCraftRes1 = item->craftResources[0][1];
    int stockCraftRes2 = item->craftResources[1][1];
    int stockInvPlayerRes1 = getStockItem(idCraftRes1, invPlayer);
    int stockInvPlayerRes2 = getStockItem(idCraftRes2, invPlayer);
    int stockInvPNJRes1 = getStockItem(idCraftRes1, invPNJ);
    int stockInvPNJRes2 = getStockItem(idCraftRes2, invPNJ);
    int stockInvTotRes1 = stockInvPlayerRes1 + stockInvPNJRes1;
    int stockInvTotRes2 = stockInvPlayerRes2 + stockInvPNJRes2;
    if (stockCraftRes1 > stockInvTotRes1 || stockCraftRes2 > stockInvTotRes2){//player and PNJ do not have enough resources in their inventories combined
        return 0;
    }
    else{
        return 1;
    }
}

void craftItem(int itemID, inventory* invPlayer, inventory* invPNJ, int choiseAdd){
    Item* item;
    // check if the required resources are present in the player's or the PNJ's inventory 
    if(checkResources(itemID, invPlayer, invPNJ) == 1 ){ 
        item = initItem(itemID);
        int idCraftRes1 = item->craftResources[0][0];
        Item* itemCraft1 = initItem(idCraftRes1);
        int idCraftRes2 = item->craftResources[1][0];
        Item* itemCraft2 = initItem(idCraftRes2);
        int stockCraftRes1 = item->craftResources[0][1];
        int stockCraftRes2 = item->craftResources[1][1];
        int stockInvPlayerRes1 = getStockItem(idCraftRes1, invPlayer);
        int stockInvPlayerRes2 = getStockItem(idCraftRes2, invPlayer);
        int stockInvPNJRes1 = getStockItem(idCraftRes1, invPNJ);
        int stockInvPNJRes2 = getStockItem(idCraftRes2, invPNJ);
       switch(choiseAdd){
        case 1://player chooses to add the item to his own inventory
            if(addItemInvPlayer(item, invPlayer, 1) == 1){
                addItemInvPlayer(item, invPlayer, 1);
                if (stockInvPlayerRes1 >= stockCraftRes1){//player's inventory has the necessary amount of stock for Craft resource 1
                    deleteItemFromInv(itemCraft1, invPlayer,stockCraftRes1);
                }
                else{//if the player's inventory doesn't have the nessecary stock, the rest of the resources will be deducted from the PNJ's inventory
                    int difference1 = stockCraftRes1 - stockInvPlayerRes1;
                    deleteItemFromInv(itemCraft1, invPlayer, stockInvPlayerRes1);
                    deleteItemFromInv(itemCraft1, invPNJ, difference1);
                }
                if (stockInvPlayerRes2 >= stockCraftRes2){//player's inventory has the necessary amount of stock for Craft resource 2
                    deleteItemFromInv(itemCraft2, invPlayer,stockCraftRes2);
                }
                else{
                    int difference2 = stockCraftRes2 - stockInvPlayerRes2;
                    deleteItemFromInv(itemCraft2, invPlayer, stockInvPlayerRes2);
                    deleteItemFromInv(itemCraft2, invPNJ, difference2);
                }
            free(itemCraft1);
            free(itemCraft2);
            break;
            } 
            else{
                printf("%s will be added to the PNJ's inventory", item->name);
                choiseAdd = 2;//if the player's inventory is full the item is automatically added to the PNJ's inventory
            } 
        case 2://player chooses to add the item to the PNJ's inventory or there isn't enough space in the player's inventory
            addItemInvPNJ(item, invPNJ, 1) ;
            if (stockInvPlayerRes1 >= stockCraftRes1){//player's inventory has the necessary amount of stock for Craft resource 1
                deleteItemFromInv(itemCraft1, invPlayer,stockCraftRes1);
            }
            else{
                int difference1 = stockCraftRes1 - stockInvPlayerRes1;
                deleteItemFromInv(itemCraft1, invPlayer, stockInvPlayerRes1);
                deleteItemFromInv(itemCraft1, invPNJ, difference1);
            }
            if (stockInvPlayerRes2 >= stockCraftRes2){//player's inventory has the necessary amount of stock for Craft resource 2
                deleteItemFromInv(itemCraft2, invPlayer,stockCraftRes2);
            }
            else{
                int difference2 = stockCraftRes2 - stockInvPlayerRes2;
                deleteItemFromInv(itemCraft2, invPlayer, stockInvPlayerRes2);
                deleteItemFromInv(itemCraft2, invPNJ, difference2);
            }
            free(itemCraft1);
            free(itemCraft2);
            break;
       }
    }else{
        // get resource name by id in the feature and add it in the message
        printf("Sorry u don\'t have the required resources in your inventory nor the inventory of the PNJ\n");
    }

}

Item* isToolInInv(Item* resource,inventory* inv){
    Item* item = malloc(sizeof(Item));
    while(inv!=NULL){
        if(inv->inv->item->id == resource->harvestTool->id){
            item = inv->inv->item;
            return item;
        }
        inv = inv->next;
    }
    return NULL;
}

void addResourcetoInv(Item* resource, inventory* inv){
    Item *toolinInv = isToolInInv(resource, inv);
    if (toolinInv != NULL && toolinInv->durability > 0){
        toolinInv->durability = toolinInv->durability - (resource->harvestTool->durability * ((double)resource->toolUsuryByResource / 100));
        int stock = (rand() % 4) + 1;
        addItemInvPlayer(resource, inv, stock);
    }
    else if (toolinInv != NULL && toolinInv->durability == 0){
        printf("The %s in your inventory needs to be fixed \n", resource->harvestTool->name);
    }
    else{
        printf("You don't have a %s in your inventory to harvest %s \n", resource->harvestTool->name, resource->name);
    }
}

void harvestResource (int val, inventory* inv){
    Item* resource;
    srand ( time(NULL) ); 
    switch(val){
        case 3:
            resource = initItem(7);
            addResourcetoInv(resource,inv);
            break;
        case 4:
            resource = initItem(6);
            addResourcetoInv(resource,inv);
            break;
        case 5:
            resource = initItem(5);
            addResourcetoInv(resource,inv);
            break;
        case 6:
            resource = initItem(18);
            addResourcetoInv(resource,inv);
            break;
        case 7:
            resource = initItem(17);
            addResourcetoInv(resource,inv);
            break;
        case 8:
            resource = initItem(16);
            addResourcetoInv(resource,inv);
            break;
        case 9:
            resource = initItem(29);
            addResourcetoInv(resource,inv);
            break;
        case 10:
            resource = initItem(28);
            addResourcetoInv(resource,inv);
            break;
        case 11:
            resource = initItem(27);
            addResourcetoInv(resource,inv);
            break;
    }
}

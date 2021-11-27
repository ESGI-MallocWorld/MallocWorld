#include<stdio.h>
#include<stdio.h>
#include "itemsUnified.h"
#include "inventory.h"
#include<string.h>
#include<time.h>


Item* initAttributes(Type type, int id, char* name,int zone,int durability, int craftResource1, int amount1, int craftResource2, int amount2, int toolUsuryByResource,Item* harvestTool, int damage, int resistance, int restoredHP){
    Item *item = malloc(sizeof(Item));

    item->itemType = type;
    item->id = id;
    item->name = name;
    item->zone = zone;
    item->durability = durability;

    item->craftResources = malloc (sizeof(int*)*2);
    for (int i = 0; i < 2; i++)
    {
        item->craftResources[i]=malloc (sizeof(int)*2);
    }

    item->craftResources[0][0] = craftResource1;
    item->craftResources[0][1] = amount1;
    item->craftResources[1][0] = craftResource2;
    item->craftResources[1][1] = amount2;
    item->toolUsuryByResource = toolUsuryByResource;
    item->harvestTool = harvestTool;
    item->damage = damage;
    item->resistance = resistance; //percentage
    item->restoredHP = restoredHP;

    return item;
}

//Function that creates a item when item ID is given as a parameter
Item* initItem(int val){
    Item *item = malloc(sizeof(Item));
    switch (val) {
        /*Tools*/
        case 2: // wooden pickaxe
            item = initAttributes(Tool, val, "Pioche en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 0, 0, 0);
            break;
        case 3: // wooden machete
            item = initAttributes(Tool, val, "Serpe en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 0, 0, 0);
            break;
        case 4: // wooden axe
            item = initAttributes(Tool, val, "Hache en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 0, 0, 0);
            break;
        case 12:// stone pickaxe
            item = initAttributes(Tool, val, "Pioche en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 0, 0, 0);
            break;
        case 13:// stone machete
            item = initAttributes(Tool, val, "Serpe en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 0, 0, 0);
            break;
        case 14:// stone axe
            item = initAttributes(Tool, val, "Hache en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 0, 0, 0);
            break;
        case 23:// iron pickaxe
            item = initAttributes(Tool, val, "Pioche en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 0, 0, 0);
            break;
        case 24:// iron machete
            item = initAttributes(Tool, val, "Serpe en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 0, 0, 0);
            break;
        case 25:// iron axe
            item = initAttributes(Tool, val, "Hachen en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 0, 0, 0);
            break;

        /*Resources*/
        case 7:
            item = initAttributes(Resource, val, "Herbe", 1, 0, 0, 0, 0, 0, 10, initItem(3), 0, 0, 0);
            break;
        case 6:
            item = initAttributes(Resource, val, "Pierre", 1, 0, 0, 0, 0, 0, 10, initItem(2), 0, 0, 0);
            break;
        case 5:
            item = initAttributes(Resource, val, "Sapin", 1, 0, 0, 0, 0, 0, 10, initItem(4), 0, 0, 0);
            break;
        case 18:
            item = initAttributes(Resource, val, "Lavande", 2, 0, 0, 0, 0, 0, 20, initItem(13), 0, 0, 0);
            break;
        case 17:
            item = initAttributes(Resource, val, "Fer", 2, 0, 0, 0, 0, 0, 20, initItem(12), 0, 0, 0);
            break;
        case 16:
            item = initAttributes(Resource, val, "Hêtre", 2, 0, 0, 0, 0, 0, 20, initItem(14), 0, 0, 0);
            break;
        case 29:
            item = initAttributes(Resource, val, "Chanvre", 3, 0, 0, 0, 0, 0, 40, initItem(24), 0, 0, 0);
            break;
        case 28:
            item = initAttributes(Resource, val, "Diamant", 3, 0, 0, 0, 0, 0, 40, initItem(23), 0, 0, 0);
            break;
        case 27:
            item = initAttributes(Resource, val, "Chêne", 3, 0, 0, 0, 0, 0, 40, initItem(25), 0, 0, 0);
            break;

        /*Weapons*/
        case 1:
            item = initAttributes(Weapon, val, "Epée en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 1, 0, 0);
            break;
        case 8:
            item = initAttributes(Weapon, val, "Epée en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 2, 0, 0);
            break;
        case 9:
            item = initAttributes(Weapon, val, "Lance en pierre", 1, 8, 5, 3, 6, 4, 0, NULL, 3, 0, 0);
            break;
        case 10:
            item = initAttributes(Weapon, val, "Marteau en pierre", 1, 5, 5, 2, 6, 6, 0, NULL, 4, 0, 0);
            break;
        case 19:
            item = initAttributes(Weapon, val, "Epée en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 5, 0, 0);
            break;
        case 20:
            item = initAttributes(Weapon, val, "Lance en fer", 2, 8, 16, 3, 17, 5, 0, NULL, 7, 0, 0);
            break;
        case 21:
            item = initAttributes(Weapon, val, "Marteau en fer", 2, 5, 16, 2, 17, 7, 0, NULL, 10, 0, 0);
            break;  
        case 30:
            item = initAttributes(Weapon, val, "Epée en diamant", 3, 10, 27, 2, 28, 5, 0, NULL, 10, 0, 0);
            break;
        case 31:
            item = initAttributes(Weapon, val, "Lance en diamant", 3, 8, 27, 3, 28, 6, 0, NULL, 15, 0, 0);
            break;
        case 32:
            item = initAttributes(Weapon, val, "Marteau en diamant", 3, 5, 27, 2, 28, 8, 0, NULL, 20, 0, 0);
            break; 

        /*Armors*/
        case 11:
            item = initAttributes(Armor, val, "Plastron en pierre", 1, 0, 6, 10, 0, 0, 0, NULL, 0, 10, 0);
            break;
        case 22:
            item = initAttributes(Armor, val, "Plastron en fer", 2, 0, 17, 12, 0, 0, 0, NULL, 0, 20, 0);
            break;
        case 33:
            item = initAttributes(Armor, val, "Plastron en diamant", 3, 0, 28, 16, 0, 0, 0, NULL, 0, 40, 0);
            break;
        
        /*Potions*/
        case 15:
            item = initAttributes(Potion, val, "Potion de vie 1", 1, 0, 7, 2, 0, 0, 0, NULL, 0, 0, 30);
            break;
        case 26:
            item = initAttributes(Potion, val, "Potion de vie 2", 2, 0, 18, 2, 0, 0, 0, NULL, 0, 0, 80);
            break;
        case 34:
            item = initAttributes(Potion, val, "Potion de vie 3", 3, 0, 29, 2, 0, 0, 0, NULL, 0, 0, 200);
            break;

    }
    return item;
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

char* getItemName(int val){
    Item* item;
    item = initItem(val); 
    int size = strlen(item->name);  
    char* name = malloc(sizeof(char)*size);
    name = item->name;
    return name;
}


//function that returns the item the player wants to craft if he/she has enough resources
//choise 1 = player wants to add the item to his own inventory || choise 2 = player wants to add the item to the PNJ's inventory
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

//function that returns the asked for tool, if the player has it in its inventory
Item* isToolinInv(Item* resource,inventory* inv){
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

//function that adds the given resource to the given inventory if the player's inventory contains the required resource with the required durability
//The function also decreases the durability of the tool with which the player harvest the resource. 
void addResourcetoInv(Item* resource, inventory* inv){
    Item *toolinInv = isToolinInv(resource, inv);
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

//function that adds the resource (linked to the item ID given as a parameter) to the inventory of the player
void harvestResource (int val, inventory* inv){
    Item* resource;
    srand ( time(NULL) ); 
    switch(val){
        case 3:
            resource = initItem(7);
            void addResourcetoInv(resource,inv);
            break;
        case 4:
            resource = initItem(6);
            void addResourcetoInv(resource,inv);
            break;
        case 5:
            resource = initItem(5);
            void addResourcetoInv(resource,inv);
            break;
        case 6:
            resource = initItem(18);
            void addResourcetoInv(resource,inv);
            break;
        case 7:
            resource = initItem(17);
            void addResourcetoInv(resource,inv);
            break;
        case 8:
            resource = initItem(16);
            void addResourcetoInv(resource,inv);
            break;
        case 9:
            resource = initItem(29);
            void addResourcetoInv(resource,inv);
            break;
        case 10:
            resource = initItem(28);
            void addResourcetoInv(resource,inv);
            break;
        case 11:
            resource = initItem(27);
            void addResourcetoInv(resource,inv);
            break;
    }
}


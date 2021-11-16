#include<stdio.h>
#include<stdio.h>
#include "itemsUnified.h"
#include "Inventory.h"

Item* initAttributes(Type type, int id, char* name,int maxZone,int durability, int craftResource1, int amount1, int craftResource2, int amount2, int toolUsuryByResource,Item* harvestTool, int damage, int resistance, int restoredHP){
    Item *item;
    item = malloc(sizeof(Item));

    item->itemType = type;
    item->id = id;
    item->name = name;
    item->maxZone = maxZone;
    item->durability = durability;
    item->craftResources[0][0] = craftResource1;
    item->craftResources[0][1] = amount1;
    item->craftResources[1][0] = craftResource2;
    item->craftResources[1][1] = amount2;
    item->toolUsuryByResource = toolUsuryByResource;
    item->harvestTool = harvestTool;
    item->damage = damage;
    item->resistance = resistance;
    item->restoredHP = restoredHP;

    return item;
}


//Function that creates a tool when tool ID is given as a parameter
Item* initTool(int val){
    Item* tool;
    switch (val) {
        case 2: // wooden pickaxe
            tool = initAttributes(Tool, val, "Pioche en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 0, 0, 0);
            break;
        case 3: // wooden machete
            tool = initAttributes(Tool, val, "Serpe en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 0, 0, 0);
            break;
        case 4: // wooden axe
            tool = initAttributes(Tool, val, "Hache en bois", 1, 10, 5, 3, 0, 0, 0, NULL, 0, 0, 0);
            break;
        case 12:// stone pickaxe
            tool = initAttributes(Tool, val, "Pioche en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 0, 0, 0);
            break;
        case 13:// stone machete
            tool = initAttributes(Tool, val, "Serpe en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 0, 0, 0);
            break;
        case 14:// stone axe
            tool = initAttributes(Tool, val, "Hache en pierre", 1, 10, 5, 2, 6, 3, 0, NULL, 0, 0, 0);
            break;
        case 23:// iron pickaxe
            tool = initAttributes(Tool, val, "Pioche en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 0, 0, 0);
            break;
        case 24:// iron machete
            tool = initAttributes(Tool, val, "Serpe en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 0, 0, 0);
            break;
        case 25:// iron axe
            tool = initAttributes(Tool, val, "Hachen en fer", 2, 10, 16, 2, 17, 4, 0, NULL, 0, 0, 0);
            break;

    }
    return tool;
}


int checkResources (int toolId, inventory* inv){
    Item* tool;
    tool = initTool(toolId);
    inventory* invNext = inv->next;
    while (inv != 0){
        while(invNext != NULL) {
            if((inv->inv->item->id == tool->craftResources[0][0] && invNext->inv->item->id == tool->craftResources[1][0])){
                if((inv->inv->item->stock == tool->craftResources[0][1] && invNext->inv->item->stock == tool->craftResources[1][1])){
                    return 1;
                    }
            }
            if((invNext->inv->item->id == tool->craftResources[0][0] && inv->inv->item->id == tool->craftResources[1][0])){
                if((invNext->inv->item->stock == tool->craftResources[0][1] && inv->inv->item->stock == tool->craftResources[1][1])){
                    return 1;
                }
            }
            invNext = invNext->next;
        }
        
        inv = inv->next;
    }
    return 0;
}



Item* addTool(int toolId, inventory* inv ){
    Item* tool;
    // try to create tools
    tool = initTool(toolId);
    if(checkResources(toolId, inv) == 1){ // check if player has this type resource in inventory or not
       tool = initTool(toolId);
       return tool;
    }else{
        // get resource name by id in the feature and add it in the message
        printf("Sorry u don\'t have the required resources");
        return NULL;
    }

}

Item* harvestResource (int val){
    Item* resource; 
    switch(val){
        case 3:
            resource = initAttributes(Resource, 7, "Herbe", 1, 0, 0, 0, 0, 0, 10, initTool(3), 0, 0, 0);
            break;
        case 4:
            resource = initAttributes(Resource, 6, "Pierre", 1, 0, 0, 0, 0, 0, 10, initTool(2), 0, 0, 0);
            break;
        case 5:
            resource = initAttributes(Resource, 5, "Sapin", 1, 0, 0, 0, 0, 0, 10, initTool(4), 0, 0, 0);
            break;
        case 6:
            resource = initAttributes(Resource, 18, "Lavande", 2, 0, 0, 0, 0, 0, 20, initTool(13), 0, 0, 0);
            break;
        case 7:
            resource = initAttributes(Resource, 17, "Fer", 2, 0, 0, 0, 0, 0, 20, initTool(12), 0, 0, 0);
            break;
        case 8:
            resource = initAttributes(Resource, 16, "Hêtre", 2, 0, 0, 0, 0, 0, 20, initTool(14), 0, 0, 0);
            break;
        case 9:
            resource = initAttributes(Resource, 29, "Chanvre", 3, 0, 0, 0, 0, 0, 40, initTool(24), 0, 0, 0);
            break;
        case 10:
            resource = initAttributes(Resource, 28, "Diamant", 3, 0, 0, 0, 0, 0, 40, initTool(23), 0, 0, 0);
            break;
        case 11:
            resource = initAttributes(Resource, 27, "Chêne", 3, 0, 0, 0, 0, 0, 40, initTool(25), 0, 0, 0);
            break;
    }
    return resource;
}

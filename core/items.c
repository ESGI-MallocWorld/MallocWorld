#include "items.h"
#include<stdio.h>
#include<stdio.h>

//Function that creates a tool when tool ID is given as a parameter
Tools* initTool(int val){
    Tools *tool;
    tool = malloc(sizeof(Tools));

    tool->id = val;
    tool->durability = 10; // all tools durability is 10

    switch (val) {
        case 2: // wooden pickaxe
            tool->name  = "Pioche en bois";
            tool->craftResources[0][0] = 5;
            tool->craftResources[0][1] = 3;
            tool->craftResources[1][0] = 0;
            tool->craftResources[1][1] = 0;
            break;
        case 3: // wooden machete
            tool->name  = "Serpe en bois";
            tool->craftResources[0][0] = 5;
            tool->craftResources[0][1] = 3;
            tool->craftResources[1][0] = 0;
            tool->craftResources[1][1] = 0;
            break;
        case 4: // wooden axe
            tool->name  = "Hache en bois";
            tool->craftResources[0][0] = 5;
            tool->craftResources[0][1] = 3;
            tool->craftResources[1][0] = 0;
            tool->craftResources[1][1] = 0;
            break;
        case 12:// stone pickaxe
            tool->name  = "Pioche en pierre";
            tool->craftResources[0][0] = 5;
            tool->craftResources[0][1] = 2;
            tool->craftResources[1][0] = 6;
            tool->craftResources[1][1] = 3;
            break;
        case 13:// stone machete
            tool->name  = "Serpe en pierre";
            tool->craftResources[0][0] = 5;
            tool->craftResources[0][1] = 2;
            tool->craftResources[1][0] = 6;
            tool->craftResources[1][1] = 3;
            break;
        case 14:// stone axe
            tool->name  = "Hache en pierre";
            tool->craftResources[0][0] = 5;
            tool->craftResources[0][1] = 2;
            tool->craftResources[1][0] = 6;
            tool->craftResources[1][1] = 3;
            break;
        case 23:// iron pickaxe
            tool->name  = "Pioch en fer";
            tool->craftResources[0][0] = 16;
            tool->craftResources[0][1] = 2;
            tool->craftResources[1][0] = 17;
            tool->craftResources[1][1] = 4;
            break;
        case 24:// iron machete
            tool->name  = "Serpe en fer";
            tool->craftResources[0][0] = 16;
            tool->craftResources[0][1] = 2;
            tool->craftResources[1][0] = 17;
            tool->craftResources[1][1] = 4;
            break;
        case 25:// iron axe
            tool->name  = "Hachen en fer";
            tool->craftResources[0][0] = 16;
            tool->craftResources[0][1] = 2;
            tool->craftResources[1][0] = 17;
            tool->craftResources[1][1] = 4;
            break;

    }
    return tool;
}

/*
 * TypeID's :
 * Weapon = 1
 * Tool = 2
 * Armor = 3
 * Resource = 4
 * Potion = 5
 */

int* createListItems(){

    int ListItemsSize = 34;
    //array[itemID][typeID]
    int *ListItems = malloc(sizeof (int) * ListItemsSize);
    ListItems[0] = 1;
    ListItems[1] = 2;
    ListItems[2] = 2;
    ListItems[3] = 2;
    ListItems[4] = 4;
    ListItems[5] = 4;
    ListItems[6] = 4;
    ListItems[7] = 1;
    ListItems[8] = 1;
    ListItems[9] = 1;
    ListItems[10] = 3;
    ListItems[11] = 2;
    ListItems[12] = 2;
    ListItems[13] = 2;
    ListItems[14] = 5;
    ListItems[15] = 4;
    ListItems[16] = 4;
    ListItems[17] = 4;
    ListItems[18] = 1;
    ListItems[19] = 1;
    ListItems[20] = 1;
    ListItems[21] = 3;
    ListItems[22] = 2;
    ListItems[23] = 2;
    ListItems[24] = 2;
    ListItems[25] = 5;
    ListItems[26] = 4;
    ListItems[27] = 4;
    ListItems[28] = 4;
    ListItems[29] = 1;
    ListItems[30] = 1;
    ListItems[31] = 1;
    ListItems[32] = 3;
    ListItems[33] = 5;

    return ListItems;

}

int getItemTypeByID(int ItemID){
    int* itemlist ;
    itemlist = createListItems();
    return itemlist[ItemID-1];
}



Tools* addTool(int toolId){
    Tools *tool;
    char *msg;
    msg = '';

    // try to create tools
    tool = getToolInformation(toolId);
    if(false){ // check if player have this type resource in inventory or not
        if(false){
        }else{
            // get resource name by id in the feature and add it in the message
            msg ='Sorry u don\'t the required resources ';
        }
    }else{
        // get resource name by id in the feature and add it in the message
        msg ='Sorry u don\'t the required resources ';
    }

}

Resource* harvestResource (int value){
    Resource* resource = malloc(sizeof(Resource));
    switch(value){
        case 3:
            resource->id = 7;
            resource->name = "Herbe";
            resource->usury = 10;
            resource->tool = createTool(3);
            break;

        case 4:
            resource->id = 6;
            resource->name = "Pierre";
            resource->usury = 10;
            resource->tool = createTool(2);
            break;

        case 5:
            resource->id = 5;
            resource->name = "Sapin";
            resource->usury = 10;
            resource->tool = createTool(4);
            break;

        case 6:
            resource->id = 18;
            resource->name = "Lavande";
            resource->usury = 20;
            resource->tool = createTool(13);
            break;

        case 7:
            resource->id = 17;
            resource->name = "Fer";
            resource->usury = 20;
            resource->tool = createTool(12);
            break;

        case 8:
            resource->id = 16;
            resource->name = "Hêtre";
            resource->usury = 20;
            resource->tool = createTool(14);
            break;

        case 9:
            resource->id = 29;
            resource->name = "Chanvre";
            resource->usury = 40;
            resource->tool = createTool(24);
            break;

        case 10:
            resource->id = 28;
            resource->name = "Diamant";
            resource->usury = 40;
            resource->tool = createTool(23);
            break;

        case 11:
            resource->id = 27;
            resource->name = "Chêne";
            resource->usury = 40;
            resource->tool = createTool(25);
            break;


    }
    return resource;
}

#include "items.h"
#include<stdio.h>
#include<stdio.h>

//Function that creates a tool when tool ID is given as a parameter
Tools* createTool(int val){
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

Resource* harvestResource (int value){
    Resource* resource = malloc(sizeof(Resource));
    switch(value){
        case 3:
            resource->value = 7;
            resource->name = "Herbe";
            resource->usury = 10;
            resource->tool = createTool(3);
        break;

        case 4:
            resource->value = 6;
            resource->name = "Pierre";
            resource->usury = 10;
            resource->tool = createTool(2);  
        break;

        case 5:
            resource->value = 5;
            resource->name = "Sapin";
            resource->usury = 10;
            resource->tool = createTool(4);
        break;

        case 6:
            resource->value = 18;
            resource->name = "Lavande";
            resource->usury = 20;
            resource->tool = createTool(13);             
        break;  

        case 7:
            resource->value = 17;
            resource->name = "Fer";
            resource->usury = 20;
            resource->tool = createTool(12);             
        break;  

        case 8:
            resource->value = 16;
            resource->name = "Hêtre";
            resource->usury = 20;
            resource->tool = createTool(14);             
        break;  

        case 9:
            resource->value = 29;
            resource->name = "Chanvre";
            resource->usury = 40;
            resource->tool = createTool(24);             
        break;  

        case 10:
            resource->value = 28;
            resource->name = "Diamant";
            resource->usury = 40;
            resource->tool = createTool(23);             
        break;  

        case 11:
            resource->value = 27;
            resource->name = "Chêne";
            resource->usury = 40;
            resource->tool = createTool(25);             
        break;            
        

    }
    return resource;
}


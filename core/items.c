#include "items.h"
#include<stdio.h>
#include<stdio.h>

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
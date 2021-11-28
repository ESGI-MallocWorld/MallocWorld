#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "itemsUnified.h"


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



char* getItemName(int val){
    Item* item;
    item = initItem(val); 
    int size = strlen(item->name);  
    char* name = malloc(sizeof(char)*size);
    name = item->name;
    free(item);
    return name;
}

Item* getItemfromID (int itemID){
    Item* item;
    item = initItem(itemID);
    return item;
}





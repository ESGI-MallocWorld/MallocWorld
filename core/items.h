#ifndef MALLOCWORLD_ITEMS_H
#define MALLOCWORLD_ITEMS_H

enum ToolIdList{2,3,4,12,13,14,23,24,25};

typedef struct Tools{
    int id;
    char* name;
    int durability;
    int craftResources[2][2]; //2 rows and 2 columns; First column = resource id, second column=quantity
} Tools;

int* createListItems();
int getItemTypeByID();

/**
 *
 * @return
 */
Tools* initTool(int);

/**
 * Check if player has enough resource or not
 * if player has enough resource add tools in inventory if not free tools
 *
 * @param toolId
 * @return
 */
Tools* addTool(int);

typedef struct Resource {
    
    int id;
    char* name;
    int usury;  // pourcentage durability on tools
    Tools* tool; //outil avec lequel la ressource doit être recolté
    
} Resource;

Resource* harvestResource(int);

typedef struct Weapon {
    int id;
    char* name;
    int zone; // 1=ZONE 1/2/3 2=ZONE 2/3 3=ZONE 3
    int damage;
    int durability;
    int** resource; // ARRAY[9][2]
    
} Weapon;

typedef struct Armor {
    int id;
    char* name;
    int zone;
    int resistance;
    int** resource;
    
} Armor ;

typedef struct Potion {
    int id;
    char* name;
    int zone;
    int hp_restored;
    int** ressource;


} Potion ;

void toString()

#endif
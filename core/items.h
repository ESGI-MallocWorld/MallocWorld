#ifndef MALLOCWORLD_ITEMS_H
#define MALLOCWORLD_ITEMS_H

typedef struct Tools{
    int id;
    char* name;
    int durability;
    int craftResources[2][2]; //2 rows and 2 columns; First column = resource id, second column=quantity
} Tools;

Tools* createTool(int);

typedef struct Ressource {
    
    int value;
    char* name;
    int quantity; // MAX QUANTITY
    
} Ressource;

typedef struct Weapon {
    
    
    int value;
    char* name;
    int zone; // 1=ZONE 1/2/3 2=ZONE 2/3 3=ZONE 3
    int damage;
    int durability;
    int** ressource; // ARRAY[9][2]
    
} Weapon;


typedef struct Armor {
    
    
    int value;
    char* name;
    int zone;
    int resistance;
    int** ressource;
    
} Armor ;

typedef struct Potion {
    
    
    int value;
    char* name;
    int zone;
    int hp_restored;
    int** ressource;
    
} Potion ;

#endif
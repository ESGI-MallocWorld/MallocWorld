#ifndef MALLOCWORLD_ITEMSUNIFIED_H
#define MALLOCWORLD_ITEMSUNIFIED_H

#include"inventory.h"

typedef enum itemName{
    EpeeEnBois = 1,
    PiocheEnBois,
    SerpeEnBois,
    HacheEnBois,
    Sapin,
    Pierre,
    Herbe,
    EpeeEnPierre,
    LanceEnPierre,
    MarteauEnPierre,
    PlastronEnPierre,
    PiocheEnPierre,
    SerpeEnPierre,
    HackeEnPierre,
    PotionDeVie1,
    Hetre,
    Fer,
    Lavande,
    EpeeEnFer,
    LanceEnFer,
    MarteauEnFer,
    PlastronEnFer,
    PiocheEnFer,
    SerpeEnFer,
    HackeEnFer,
    PotionDeVie2,
    Chene,
    Diamant,
    Chanvre,
    EpeeEnDiamant,
    LanceEnDiamant,
    MarteauEnDiamant,
    PlastronEnDiamant,
    PotionDeVie3
} itemName;


typedef enum Type {
    Resource = 1,
    Tool,
    Weapon,
    Armor,
    Potion
} Type;

typedef struct Item{
    /*
    * Common attributes
    */
    Type itemType; // Resource = 1; Tool = 2; Weapon = 3; Armor = 4; Potion = 5
    int id;
    char* name;
    int zone; // 1=ZONE 1/2/3 2=ZONE 2/3 3=ZONE 3 

    /*
    * Specific attributes
    */
    int durability; // Tools & Weapons
    int** craftResources; //2 rows and 2 columns; First column = resource id, second column=quantity //Tools, weapons, armors & potions
    int toolUsuryByResource; //// pourcentage of damage on tools when resource collected //Resource
    Item* harvestTool; //Tool with which the resource has to harvested //Resource
    int damage; //Weapon
    int resistance; //Armor (percentage)
    int restoredHP; //Potion

} Item;

Item* initAttributes(Type, int , char* ,int ,int , int , int , int , int , int ,Item* , int , int , int );

char* getItemName(int); //returns the name of the item which's ID is the integer given as a parameter


Item* initItem(int);

void craftItem(int, inventory*, inventory*, int);

void addResourcetoInv(Item*, inventory* );

void harvestResource(int, inventory*);

Item* isToolinInv(Item*,inventory*);

void toString()

#endif
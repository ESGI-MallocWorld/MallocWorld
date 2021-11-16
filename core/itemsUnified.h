#ifndef MALLOCWORLD_ITEMSUNIFIED_H
#define MALLOCWORLD_ITEMSUNIFIED_H

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
    Weapon = 1,
    Tool,
    Armor,
    Resource,
    Potion
} Type;

typedef struct Item{
    /*
    * Common attributes
    */
    Type itemType; // Weapon = 1; Tool = 2; Armor = 3; Resource = 4; Potion = 5
    int id;
    char* name;
    int maxZone; // 1=ZONE 1/2/3 2=ZONE 2/3 3=ZONE 3 

    /*
    * Specific attributes
    */
    int durability; // Tools & Weapons
    int** craftResources; //2 rows and 2 columns; First column = resource id, second column=quantity //Tools, weapons, armors & potions
    int toolUsuryByResource; //// pourcentage of damage on tools when resource collected //Resource
    Item* harvestTool; //Tool with which the resource has to harvested //Resource
    int damage; //Weapon
    int resistance; //Armor
    int restoredHP; //Potion

} Item;

Item* initAttributes(Type, int , char* ,int ,int , int , int , int , int , int ,Item* , int , int , int );


/**
 *
 * @return
 */
Item* initTool(int);

/**
 * Check if player has enough resource or not
 * if player has enough resource add tools in inventory if not free tools
 *
 * @param toolId
 * @return
 */
Item* addTool(int);


Item* harvestResource(int);


void toString()

#endif
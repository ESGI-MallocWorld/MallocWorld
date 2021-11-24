#ifndef MALLOCWORLD_ITEMSUNIFIED_H
#define MALLOCWORLD_ITEMSUNIFIED_H

typedef struct Item Item;

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

Item* initAttributes(Type type, int id, char* name,int zone,int durability, int craftResource1, int amount1, int craftResource2, int amount2, int toolUsuryByResource,Item* harvestTool, int damage, int resistance, int restoredHP);

/**
 * returns the name of the item which's ID is the integer given as a parameter
 * @param val
 * @return
 */
char* getItemName(int val);

/**
 * Function that creates a item when item ID is given as a parameter
 * @param val
 * @return
 */
Item* initItem(int val);

/**
 * function that returns the item the player wants to craft if he/she has enough resources
 * choise 1 = player wants to add the item to his own inventory || choise 2 = player wants to add the item to the PNJ's inventory
 * @param itemID
 * @param invPlayer
 * @param invPNJ
 * @param choiseAdd
 */

void craftItem(int itemID, inventory* invPlayer, inventory* invPNJ, int choiseAdd);

/**
 * function that adds the given resource to the given inventory if the player's inventory contains the required resource with the required durability
 * The function also decreases the durability of the tool with which the player harvest the resource.
 * @param resource
 * @param inv
 */
void addResourcetoInv(Item* resource, inventory* inv);

/**
 * function that adds the resource (linked to the item ID given as a parameter) to the inventory of the player
 * @param val
 * @param inv
 */
void harvestResource (int val, inventory* inv);

/**
 * function that returns the asked for tool, if the player has it in its inventory
 * @return
 */
Item* isToolInInv(Item* resource,inventory* inv);

void toString()

#endif
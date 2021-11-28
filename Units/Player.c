//
// Created by wuchi on 2021/11/13.
//
#include "../functions/playerMouvement.h"
#include "../core/level.c"
#include "./Player.h"
/**
 *  GETTER
 */

int getPlayerCurrentHp(Player *this){
    return this->currentHp;
}
int getPlayerMaxHp(Player *this){
    return this->maxHp;
}
int getPlayerExp(Player *this){
    return this->exp;
}
int getPlayerMaxExp(Player *this){
    return this->level->maxExp;
}
int* getPlayerLocation(Player *this){
    return this->location;
}
inventory* getPlayerInventory(Player *this){
    return this->inventory;
}
int getPlayerLevel(Player *this){
    return this->level->levelID;
}

/**
 *  SETTER
 */

void setPlayerCurrentHp(Player *this, int newVal){
    this->currentHp = newVal;
}
void setPlayerMaxHp(Player *this , int newVal){
    this->maxHp = newVal;
}
void setPlayerExp(Player *this, int newVal){
    this->exp = newVal;
}
void setPlayerMaxExp(Player *this , int newVal){
    this->level->maxExp = newVal;
}

void setPlayerLevel(Player *this , level *levelData){
    this->level = levelData;
}
void setPlayerLocation(Player *this, int *newVal){
    this->location[0] = newVal[0];
    this->location[1] = newVal[1];
}

void setPlayerInventory(Player *this , inventory *inventoryData){
    this->inventory = inventoryData;
}



void playerLevelUp(Player *this){

    printf("You discover a mysterious power in your body\n");
    int newLevel = this->getLevel(this) +1 ;
    level *newLevelData = createLevel(newLevel);

    printf("The player's max hp have been Increased \n");
    printf("The player's hp have been restore to max\n");

    this->setMaxHp(this,newLevelData->maxHp);
    this->setCurrentHp(this,newLevelData->maxHp);

    this->setLevel(this,newLevelData);
    printf("Player level UP !!\n");

}

void displayPlayerStats(Player *this){
    // add frame display in feature
    printf("| Player Information  \n");
    printf("| -----  \n");
    printf("| Level : %11d  \n",this->getLevel(this));
    printf("| HP    : %4d / %4d \n",this->getCurrentHp(this),this->getMaxHp(this));
    printf("| Exp   : %4d / %4d \n",this->getExp(this),this->getMaxExp(this));
    printf("| -----  \n");
}

Player* newPlayer(){

    printf("Progress : init default player stats ");
    Player* playerData = malloc(sizeof (Player));
    level* levelData = createLevel(1);

    printf(" .");

    // init default default val
    playerData->currentHp = levelData->maxHp;
    playerData->maxHp = levelData->maxHp;
    playerData->exp = 0;
    playerData->level = levelData;
    playerData->location = malloc(sizeof (int)*2);
    playerData->inventory = malloc(sizeof (inventory));
    printf(" .");

    // getter
    playerData->getCurrentHp = getPlayerCurrentHp;
    playerData->getMaxHp = getPlayerMaxHp;
    playerData->getExp = getPlayerExp;
    playerData->getMaxExp = getPlayerMaxExp;
    playerData->getLevel = getPlayerLevel;
    playerData->getLocation = getPlayerLocation;
    playerData->getInventory = getPlayerInventory;
    printf(" . \n");

    // setter
    playerData->setCurrentHp = setPlayerCurrentHp;
    playerData->setMaxHp = setPlayerMaxHp;
    playerData->setExp = setPlayerExp;
    playerData->setMaxExp = setPlayerMaxExp;
    playerData->setLevel = setPlayerLevel;
    playerData->setLocation = setPlayerLocation;
    playerData->setInventory = setPlayerInventory;

    //method
    playerData->levelUp= playerLevelUp;
    playerData->displayStats = displayPlayerStats;

    printf("Progress : Player data have been init \n");
    return playerData;
}


//
// Created by wuchi on 2021/11/13.
//
#include "../core/playerMouvement.h"
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

void setPlayerLocation(Player *this, int *newVal){
    this->location[0] = newVal[0];
    this->location[1] = newVal[2];
}
void LevelUp(Player *this){

    printf("You discover a mysterious power in your body\n");
    int newLevel = this->getLevel(this) +1 ;
    level *newLevelData = createLevel(newLevel);

    printf("The player's max hp have been Increased \n");
    printf("The player's hp have been restore to max\n");

    this->setMaxHp(this,newLevelData->maxHp);
    this->setCurrentHp(this,newLevelData->maxHp);

    this->level = newLevelData;
    printf("Player level UP !!\n");

}

void displayPlayerStats(Player *this){
    // add frame display in feature
    printf("| Player Information  \n");
    printf("| -----  \n");
    printf("| Level : %d  \n",this->getLevel(this));
    printf("| HP    : %d / %d \n",this->getCurrentHp(this),this->getMaxHp(this));
    printf("| Exp   : %d / %d \n",this->getExp(this),this->getMaxExp(this));
    printf("| -----  \n");
}




Player* newPlayer(){

    printf("init default player stats ");
    Player* playerData = malloc(sizeof (Player));
    level* levelData = createLevel(1);

    printf(" .");

    // init default default val
    playerData->currentHp = levelData->maxHp;
    playerData->maxHp = levelData->maxHp;
    playerData->exp = 0;
    playerData->level = levelData;
    // init player inventory
//    playerData->inventory = inventoryData;
    printf(" .");

    // getter
    playerData->getCurrentHp = getPlayerCurrentHp;
    playerData->getMaxHp = getPlayerMaxHp;
    playerData->getExp = getPlayerExp;
    playerData->getMaxExp = getPlayerMaxExp;
    playerData->getLevel = getPlayerLevel;
    playerData->getLocation = getPlayerLocation;
    printf(" . \n");

    // setter
    playerData->setCurrentHp = setPlayerCurrentHp;
    playerData->setMaxHp = setPlayerMaxHp;
    playerData->setExp = setPlayerExp;
    playerData->setMaxExp = setPlayerMaxExp;
    playerData->setLocation = setPlayerLocation;

    printf("Player data have been init \n");
    return playerData;
}


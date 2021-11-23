//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_PLAYMENU_H
#define MALLOCWORLD_PLAYMENU_H

#include "../core/playerMouvement.h"
#include "../core/inventory.h"
#include "../core/level.h"


typedef struct Player{
    
     int currentHp;
     int maxHp;
     int exp;
     level* level;
     inventory* inventory;
     int* location;

}Player;


/**
 * player Menu action possible
 * @param action
 */
void playerMenu(Player,int);

int getCurrentHp(Player);
int getMaxHp(Player);
int getExp(Player);
int getMaxExp(Player);

level* getLevel();

inventory* getInventory(Player);

/**
 * Display different type depending the usage
 *
 * 0 All
 * 1 Combat (weapons, potions, armors)
 * 2 Resources
 * 3 Tools
 *
 * @param player
 * @param type
 */

void displayInventoryByType(Player , int );

/**
 *  use in player movement
 * @return
 */
int getLocation();



#endif 

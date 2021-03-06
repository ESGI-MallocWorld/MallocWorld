//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_PLAYMENU_H
#define MALLOCWORLD_PLAYMENU_H

#include "../core/inventory.h"
#include "../core/level.h"

typedef struct Player Player;

typedef struct Player{
    
     int currentHp;
     int maxHp;
     int exp;
     level* level;
     inventory* inventory;
     int* location;

     // getter
     int (*getCurrentHp)(Player *this);
     int (*getMaxHp)(Player *this);
     int (*getExp)(Player *this);
     int (*getMaxExp)(Player *this);
     int* (*getLocation)(Player *this);
     int (*getLevel)(Player *this);
     inventory* (*getInventory)(Player *this);


     // setter
     void (*setCurrentHp)(Player *this, int val);
     void (*setMaxHp)(Player *this, int val);
     void (*setExp)(Player *this, int val);
     void (*setMaxExp)(Player *this, int val);
     void (*setLevel)(Player *this, level *levelData);
     void (*setLocation)(Player *this, int *val);
     void (*setInventory)(Player *this ,inventory *Inventory);


     //method
     void (*levelUp)(Player *this );
     void (*displayStats)(Player *this);
}Player;

int getPlayerCurrentHp(Player *this);
int getPlayerMaxHp(Player *this);
int getPlayerExp(Player *this);
int getPlayerMaxExp(Player *this);
int* getPlayerLocation(Player *this);
int getPlayerLevel(Player *this);
inventory* getPlayerInventory(Player *this);


void setPlayerCurrentHp(Player *this ,  int newVal);
void setPlayerExp(Player *this , int newVal);
void setPlayerMaxHp(Player *this , int newVal);
void setPlayerMaxExp(Player *this , int newVal);
void setPlayerLocation(Player *this , int *newVal);
void setPlayerLevel(Player *this , level *levelData);

void playerLevelUp(Player *this);
void displayPlayerStats(Player *this);


Player* newPlayer();
#endif 

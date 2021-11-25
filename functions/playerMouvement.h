//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_PLAYERMOUVEMENT_H
#define MALLOCWORLD_PLAYERMOUVEMENT_H

#include "../core/mapInterReaction.h"

//import player data etc ....

void addResource();

/**
 * Called when mean a enemies or resource
 *
 */
void mapInterReaction();

/**
 * called by goUp , goRight , goDown, goLeft
 * @return PlayerLocation
 */
int* getPlayerLocation();

/**
 * Check target location if not null call function mapInterReaction
 */
void goUp();
void goRight();
void goDown();
void goLeft();

/**
 * function called when user chose to move
 */
void move();


#endif //MALLOCWORLD_PLAYERMOUVEMENT_H

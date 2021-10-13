//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_PLAYERMOUVEMENT_H
#define MALLOCWORLD_PLAYERMOUVEMENT_H

//import player data etc ....


void addResource();

void combat();

void claimResource();

/**
 * Called when mean a enemies or resource
 *
 */
void mapInterReaction();

/**
 * called by goUp , goRight , goDown, goLeft
 * @return PlayerLocation
 */
int* getPlayerLocation(){
    return player->location;
}

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
void move(){

    int direction ;

    //ask to go

    switch (direction) {
        case 1: // go up        ↑
            goUp();
            break;
        case 2: // go right     →
            goRight();
            break;
        case 3: // go down      ↓
            goDown();
            break;
        case 4: // go left      ←
            goLeft();
            break;
    }
}



#endif //MALLOCWORLD_PLAYERMOUVEMENT_H

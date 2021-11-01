//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_PLAYERMOUVEMENT_H
#define MALLOCWORLD_PLAYERMOUVEMENT_H

#include " ./inventory.h"
//import player data etc ....

inventory* newItems(resourceID){
    inventory current_item = (inventory *) ;

}

/**
 *  function add resource in the player inventory
 * @param resourceID
 */
void addResource(int resourceID){
    int counter =0;
    inventory current_item = Player->inventory;
    while (current_item->item_id != resourceID){
        current_item = current_item->next_item;
        if(counter >= 10 ){
            break;
        }else if(counter < 10 && current_item == NULL){
            current_item = newItems(resourceID);
            current_item->item_id = ;
            break;
        }
        counter++;
    }

    current_item


    //add resource in the player inventory



}

void combat();

void claimResource(){
    switch (mapEntityID) {
        case '5': //bois zone 1
            addResource(5);
            break;
        case '8' // bois zone 2
            addResource(16);
            break;



    }



}

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
 *
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

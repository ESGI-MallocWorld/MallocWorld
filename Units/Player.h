//
// Created by wuchi on 2021/10/13.
//

#ifndef MALLOCWORLD_PLAYMENU_H
#define MALLOCWORLD_PLAYMENU_H

#include "../core/playerMouvement.h"

typedef struct Player(){
    /**
     * hp
     * atk
     * inventory
     * level
     * exp
     */
     int* location;
}Player;


/**
 * player Menu action possible
 * @param action
 */
void playerMenu(Player player,int action){
    //

    switch (action) {
        case 1:
            move();



    }

}
#endif //MALLOCWORLD_PLAYMENU_H

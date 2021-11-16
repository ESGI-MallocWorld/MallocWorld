//
// Created by wuchi on 2021/11/13.
//

#include "Player.h"

void playerMenu(Player player,int action){
    //

    switch (action) {
        case 1:
            move();

    }

}

int getCurrentHp(Player *player){
    return player->currentHp;

}
int getMaxHp(Player *player){
    return player->maxHp;

}
int getExp(Player *player){
    return player->exp;

}
int getMaxExp(Player *player){
    return player->level->

}



//inventory* getInventory(Player player){
//
//}
//
void displayInventoryByType(Player *player , int type){

    switch (type) {
        case 0:


            while(player->inventory != NULL){
                printf("%d ", player->inventory->inv->item_id->);
                //print item ID
                printf("%d \n", player->inventory->inv->stock);

            }








    }

    if()


}



//
// Created by wuchi on 2021/11/24.
//

//#include "../Units/Player.c"
#include "Action.h"
#include "./mapAction.h"
#include "./playerMouvement.h"
//#include "../core/inventory.h"

void addResource();

void mapInterReaction(int element){

    if(isResource(element)){
//        claimRessource();
    }else if(isMonster(element)){
        //combat(element)
    }else if(isNPC(element)){
//        startNPC()//
    }

}

void runGame(Player* player ,map *map,inventory* NPC_inventory ){
    //init val
    int GameProgress;
    int *playerLoc = malloc(sizeof (int)*2);

    // assign val
    player = newPlayer();
    map = gen_map(1);

    player->setLocation(player,PlayerLocalize(map));
    GameProgress = 1 ;
    playerLoc = player->getLocation(player);


    while (GameProgress == 1){
        printMap(map);
        GameProgress = 0;
    }



//    SendToNPC(player , map , NPC_inventory);



}



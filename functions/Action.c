//
// Created by wuchi on 2021/11/24.
//

//#include "../Units/Player.c"
#include "Action.h"
#include "./mapAction.h"
#include "./playerMouvement.h"

void runGame(){
    //init val
    Player* player;
    map *map;
    int GameProgress;
    int *plaLoc = malloc(sizeof (int)*2);

    // assign val
    player = newPlayer();
    map = gen_map(1);

    player->setLocation(player,PlayerLocalize(map));
    GameProgress = 1 ;
    plaLoc = player->getLocation(player);


    while (GameProgress == 1){
        printMap(map);
        GameProgress = 0;
    }

}
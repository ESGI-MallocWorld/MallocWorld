//
// Created by wuchi on 2021/11/24.
//

#include "Action.h"
#include "./mapAction.h"


void runGame(){
    //test
    Player* player;
    map *map;

    player = newPlayer();
    map = gen_map(1);

    while (GameProgress == 1){
        printMap(map);

    }

}
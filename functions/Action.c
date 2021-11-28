//
// Created by wuchi on 2021/11/24.
//

//#include "../Units/Player.c"
#include "Action.h"
#include "./mapAction.h"
#include "./playerMouvement.c"
#include "combat.h"

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

void runGame(Player* player ,map *map, inventory* NPC_inventory){
    //init val
    int GameProgress;
    int element ;
    int *targetLocation ;
    int *originLocation;
    int X, Y;

    // assign val
    player = newPlayer();
    map = gen_map(1);

    originLocation= malloc(sizeof (int)*2);
    targetLocation= malloc(sizeof (int)*2);

    player->setLocation(player,PlayerLocalize(map));
    GameProgress = 1 ;
    originLocation = player->getLocation(player);

    while (GameProgress == 1){

        int res = 0;
        printMap(map);
        element = move(originLocation , map , targetLocation);
        if(element == -99){
            GameProgress = 0;
        }else if( isRoad(element) ){
            assignLocation(originLocation,&Y,&X);
            map->mapData[X][Y] = 0;
            assignLocation(targetLocation,&Y,&X);
            map->mapData[X][Y] = 1;
            originLocation[0] = targetLocation[0];
            originLocation[1] = targetLocation[1];
        }else if(isMonster(element)){
            Enemy* monster = createMonsterfromID(element);
            res = fight(player, monster);
            if(res == 2){
                GameProgress = 0;
            }
        }else if(isResource(element)){
            //claim
        }else if(isNPC(element)){
            //startNPC( player->inventory,player->inventory);
        }

        printf("target location X : %d , Y : %d , Element :%d \n",Y,X,element);

    }



//    SendToNPC(player , map , NPC_inventory);



}



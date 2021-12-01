//
// Created by wuchi on 2021/11/24.
//

//#include "../Units/Player.c"
#include "Action.h"
#include "./mapAction.h"
#include "./playerMouvement.c"
#include "../Units/enemis.h"
//#include "../core/inventory.h"
//#include "combat.h"
//#include "../core/npc.c"

void addResource();

void mapInterReaction(int element){

    if(isResource(element)){
//        claimRessource();
    }else if(isMonster(element)){

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
    Enemy *monster ;

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
          /*  monster = createMonsterfromID(element);
            fight(player,monster);*/
        }else if(isResource(element)){
            //claim
        }else if(isNPC(element)){
//            startNPC(player->getInventory(player),NPC_inventory);
        }

        printf("target location X : %d , Y : %d , Element :%d \n",Y,X,element);

    }



//    SendToNPC(player , map , NPC_inventory);



}



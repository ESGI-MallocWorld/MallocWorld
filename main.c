#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./core/inventory.h"
#include "./functions/mapAction.h"
#include "./Units/Player.c"

bool gameAction();//return value "false" only when save

void main(int argc, char *argv[]){
    int action;
    int gameProgress;

    printf("Chose on action to do \n");
    printf("1 : load save\n");
    printf("2 : New game\n");
    printf("3 : test environnement\n");
//    scanf("%d \n",action);

    switch (3) {
        case 1:
            if(false){     //check if user have save file
                if(false){ // chose = 0 , overrider save
                }else{ // chose = 1 , load current profile
                }
            }
        case 2:
            // run game
            gameProgress = 0;
            while(gameProgress){
                // gameProgress = gameAction();
            }
            break;
        case 3:
            //test
            printf("test player \n");
            Player* player;
            player = newPlayer();
            printf("Action : display player information\n");
            displayPlayerStats(player);
            LevelUp(player);
            displayPlayerStats(player);

            //generation map
//            printf("test main \n");
//            map *map;
//            map = gen_map(1);
//            printMap(map);

            break;
    }
    printf("end programme\n");
}

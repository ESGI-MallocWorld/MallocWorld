#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./functions/mapAction.h"


bool gameAction();//return value "false" only when save

int main(int argc, char *argv[]){
    if(false){     //check if user have save file
        if(false){ // chose = 0 , overrider save

        }else{ // chose = 1 , load current profile

        }

    }
    //test
    printf("test main \n");
    gen_map(1);

    //generation map

    //other action

    // run game
    int gameProgress ;
    gameProgress = false;
    while(gameProgress){
//        gameProgress = gameAction();
    }

    return 0;

}

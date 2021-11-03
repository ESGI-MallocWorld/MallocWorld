#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool gameAction();//return value "false" only when save

int main(int argc, char *argv[]){

    if(false){     //check if user have save file
        if(!chose){ // chose = 0 , overrider save

        }else{ // chose = 1 , load current profile

        }

    }

    //generation map

    //other action

    // run game
    bool gameProgress ;
    gameProgress = true;
    while(gameProgress){
        gameProgress = gameAction();
    }

    return 0;

}

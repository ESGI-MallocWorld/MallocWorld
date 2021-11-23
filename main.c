#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./functions/mapAction.h"
#include "./core/Inventory.h"

void echo(char *string){
    printf("%s \n",string);
}

bool gameAction();//return value "false" only when save

void main(int argc, char *argv[]){
    int action;
    int gameProgress ;
    echo("Chose on action to do ");
    echo("1 : load save");
    echo("2 : New game");
    echo("3 : test environnement");
    scanf("%d",&action);
    
    switch (action) {
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

            //generation map
            printf("test main \n");
            map *map;
            map = gen_map(1);
            printMap(map);

            break;
    }

}

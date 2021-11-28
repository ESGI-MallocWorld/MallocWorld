#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./core/importExport.c"
#include "./core/inventory.h"
#include "./Units/Player.c"
#include "./functions/Action.c"

int main(int argc, char *argv[]){
    
    int action;
    int validAction;

    Player* player;
    map *map;
    inventory* NPC_inventory = malloc(sizeof(inventory));
    NPC_inventory = newInventory();

    do {
        validAction = 1;
        printf("Chose on action to do \n");
        printf("1 : load save\n");
        printf("2 : New game\n");
        scanf("%d",&action);
        if(action > 2 || action < 1 ){
            printf("|| Warning : Action invalid || \n");
            validAction = 0;
        }
    } while (validAction == 0 );


    switch (action) {
        case 1:
            
            break;
        case 2:

            runGame(player,map,NPC_inventory);
            break;

    }
    printf("end programme\n");

    return 0;
}

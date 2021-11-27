#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "./core/inventory.h"
#include "./Units/Player.c"
#include "./functions/Action.c"

bool gameAction();//return value "false" only when save

void main(int argc, char *argv[]){
    int action;
    int validAction;

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
            if(false){     //check if user have save file
                if(false){ // chose = 0 , overrider save
                }else{ // chose = 1 , load current profile
                }
            }
            break;
        case 2:
            runGame();
            break;

    }
    printf("end programme\n");
}

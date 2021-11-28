//
// Created by wuchi on 2021/10/13.
//

#include "playerMouvement.h"
#include "mapAction.h" // have been included in Action
#include<stdio.h>

int UpElement(int X , int Y ,int* targetLocation,int ** mapData){

    targetLocation [0] = X;
    targetLocation [1] = Y-1;

    return mapData[Y-1][X];
}

int RightElement(int X , int Y ,int* targetLocation,int ** mapData){
    targetLocation [0] = X+1;
    targetLocation [1] = Y;

    return mapData[Y][X+1];
}

int DownElement(int X , int Y ,int* targetLocation,int ** mapData){
    targetLocation [0] = X;
    targetLocation [1] = Y+1;

    return mapData[Y+1][X];
}

int LeftElement(int X , int Y ,int* targetLocation,int ** mapData){
    targetLocation [0] = X-1;
    targetLocation [1] = Y;

    return mapData[Y][X-1];
}

int getElement(int *location ,map* map ,int direction ,int *targetLocation){

    int X , Y;
    int element ;
    int **mapData ;

    X = location[0];
    Y = location[1];

//    assignLocation(location,&X,&Y);

    mapData = getMapData(map);

    switch (direction) {
        case 1: // go up        ↑
            element = UpElement(X,Y,targetLocation,mapData);
            break;
        case 2: // go right     →
            element = RightElement(X,Y,targetLocation,mapData);
            break;
        case 3: // go down      ↓
            element = DownElement(X,Y,targetLocation,mapData);
            break;
        case 4: // go left      ←
            element = LeftElement(X,Y,targetLocation,mapData);
            break;
    }
    return element ;
}

void movementDialogue(){
    printf("Chose on action to do \n");
    printf("0 : Leave Game  \n");
    printf("1 : Go up    ↑  \n");
    printf("2 : Go Right →  \n");
    printf("3 : Go down  ↓  \n");
    printf("4 : Go left  ←  \n");
}

int checkVoid(int direction,map *map ,int *location){
    int X , Y;
    assignLocation(location,&X,&Y);

    int isVoid = 0;

    if(direction == 1 && Y == 0){
        isVoid = 1;
    }else if(direction == 2 && X == (getMapColSize(map)-1) ){
        isVoid = 1;
    }else if(direction == 3 && Y == (getMapRowSize(map)-1) ){
        isVoid = 1;
    }else if(direction == 4 && X == 0){
        isVoid = 1;
    }
    return isVoid;
}

void warning(int error){
    if(error != 0)printf("|| Warning : Action invalid || \n");

    if( error == 1 ){
        printf("|| Choice a number between 0 to 4 || \n");
    }else if (error == 2){
        printf("|| You tried walk into the void || \n");
    }

}

int move(int* playerLoc , map *map , int *targetLocation){
    int direction ;
    int element ;
    int *location;
    int error = 0 ;

    do {
        movementDialogue();
        scanf("%d" ,&direction);
        error = 0;
        if(direction ==0){
            continue;
        }else if (direction > 5 || direction < 0){
            error = 1 ;
        }else if( checkVoid(direction , map , playerLoc) == 1){
            error = 2;
        }
        warning(error);
    } while (error != 0);

    if(direction == 0){
        element = -99;
    } else {
        element = getElement(playerLoc ,map,direction , targetLocation);
    }
    return element;




}

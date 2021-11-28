//
// Created by wuchi on 2021/10/13.
//

#include "playerMouvement.h"
#include "mapAction.h" // have been included in Action

int UpElement(int X , int Y ,int ** mapData){
    return mapData[X][Y-1];
}

int RightElement(int X , int Y ,int ** mapData){
    return mapData[X+1][Y];
}

int DownElement(int X , int Y ,int ** mapData){
    return mapData[X][Y+1];
}

int LeftElement(int X , int Y ,int ** mapData){
    return mapData[X-1][Y];
}

int getElement(int *location ,map* mapData ,int direction){

    int X , Y;
    int element ;
    assignLocation(location,&X,&Y);

    switch (direction) {
        case 1: // go up        ↑
            element = UpElement(X,Y,mapData);
            break;
        case 2: // go right     →
            element = RightElement(X,Y,mapData);
            break;
        case 3: // go down      ↓
            element = DownElement(X,Y,mapData);
            break;
        case 4: // go left      ←
            element = LeftElement(X,Y,mapData);
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

int move(int* playerLoc , map *mapData){
    int direction ;
    int element ;
    int *location;
    int **mapData ;

    int **enemyR = malloc((int*)*15);
    int **resourceR = malloc((int*)*10);
    int roundCounter = 0;
    int first_time = 1 ;

    mapData = getMapData(map);



    do {
        if(first_time == 1 ) printf("|| Warning : Action invalid || \n");
        movementDialogue();
        scanf("%d" ,&direction);
        element = getElement(playerLoc ,mapData,direction);

        first_time = 0;
    } while (direction > 6 || direction < 0);

    return element;




}

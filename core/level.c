#include "level.h"

/*
In order to upgrade a level, the experience of the player needs to be incremented by 10.
Table of experience needed per level:
level 1: 10 
level 2: 20
level 3: 30
level 4: 40
level 5: 50
level 6: 60
level 7: 70
level 8: 80
level 9: 90
level 10: 100
*/

//function to create an instance of the structure level
level* createLevel(int levelID){
    level* level = malloc(sizeof(level));
    switch(levelID){
        case 1:
            level->levelID = levelID;
            level->maxHP = 100;
            level->minExp = 0;
            level->maxExp = 10;
            break;
        case 2:
            level->levelID = levelID;
            level->maxHP = 110;
            level->minExp = 10;
            level->maxExp = 20;
            break;
        case 3:
            level->levelID = levelID;
            level->maxHP = 130;
            level->minExp = 20;
            level->maxExp = 30;
            break;
        case 4:
            level->levelID = levelID;
            level->maxHP = 160;
            level->minExp = 30;
            level->maxExp = 40;
            break;
        case 5:
            level->levelID = levelID;
            level->maxHP = 200;
            level->minExp = 40;
            level->maxExp = 50;
            break;
        case 6:
            level->levelID = levelID;
            level->maxHP = 250;
            level->minExp = 50;
            level->maxExp = 60;
            break;
        case 7:
            level->levelID = levelID;
            level->maxHP = 300;
            level->minExp = 60;
            level->maxExp = 70;
            break;
        case 8:
            level->levelID = levelID;
            level->maxHP = 350;
            level->minExp = 70;
            level->maxExp = 80;
            break;
        case 9:
            level->levelID = levelID;
            level->maxHP = 425;
            level->minExp = 80;
            level->maxExp = 90;
            break;
        case 10:
            level->levelID = levelID;
            level->maxHP = 500;
            level->minExp = 90;
            level->maxExp = 100;
            break;

    }
    return level;
}

//add all the levels to the game
void addLevels(){
    createLevel(1);
    createLevel(2);
    createLevel(3);
    createLevel(4);
    createLevel(5);
    createLevel(6);
    createLevel(7);
    createLevel(8);
    createLevel(9);
    createLevel(10);
}
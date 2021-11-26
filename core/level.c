#include "level.h"

/*
Table of experience needed per level:
level 1: 10 
level 2: 20
level 3: 30
level 4: 100
level 5: 200
level 6: 300
level 7: 1000
level 8: 2000
level 9: 3000
level 10: 40000
*/

//function to create an instance of the structure level
level* createLevel(int levelID){
    level* level = malloc(sizeof(level));
    switch(levelID){
        case 1:
            level->levelID = levelID;
            level->maxHp = 100;
            level->maxExp = 10;
            break;
        case 2:
            level->levelID = levelID;
            level->maxHp = 110;
            level->maxExp = 20;
            break;
        case 3:
            level->levelID = levelID;
            level->maxHp = 130;
            level->maxExp = 30;
            break;
        case 4:
            level->levelID = levelID;
            level->maxHp = 160;
            level->maxExp = 100;
            break;
        case 5:
            level->levelID = levelID;
            level->maxHp = 200;
            level->maxExp = 200;
            break;
        case 6:
            level->levelID = levelID;
            level->maxHp = 250;
            level->maxExp = 300;
            break;
        case 7:
            level->levelID = levelID;
            level->maxHp = 300;
            level->maxExp = 1000;
            break;
        case 8:
            level->levelID = levelID;
            level->maxHp = 350;
            level->maxExp = 2000;
            break;
        case 9:
            level->levelID = levelID;
            level->maxHp = 425;
            level->maxExp = 3000;
            break;
        case 10:
            level->levelID = levelID;
            level->maxHp = 500;
            level->maxExp = 4000;
            break;

    }
    return level;
}

//add all the levels to the game
void setLevel(int level){
    createLevel(level);
}


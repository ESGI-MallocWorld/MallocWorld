#include "enemis.h"

void main(int argc, char *argv[]){

Enemy * Goblins= malloc(sizeof(Enemy));
Goblins->id=15;
Goblins->name = "Goblin";
Goblins->life=50;
Goblins->expGained=25;

Enemy * Trolls= malloc(sizeof(Enemy));
Trolls->id=25;
Trolls->name = "Troll";
Trolls->life=110;
Trolls->expGained=60;

Enemy * Undead= malloc(sizeof(Enemy));
Undead->id=35;
Undead->name = "Undead";
Undead->life=200;
Undead->expGained=200;

Enemy * FinalBoss= malloc(sizeof(Enemy));
FinalBoss->id=99;
FinalBoss->name = "FinalBoss";
FinalBoss->life=800;
FinalBoss->expGained=500;

}
#include "enemis.h"
#include<stdio.h>
#include<stdlib.h>

/*
*ZONE 1 : 12-40 
*ZONE 2 : 41-69
*ZONE 3 : 70-89
*/

Enemy* initializeMonster(int id, char* name, int zone, int life, int damage, int expGained ){
    Enemy* en = malloc(sizeof(Enemy));
    en->id = id;
    en->name = name;
    en->zone = zone;
    en->life = life;
    en->damage = damage;
    en->expGained = expGained;

    return en;
}

Enemy** createMonsters(){

Enemy** listofMonsters = calloc(29,sizeof(Enemy*));
for (int i=0; i<29; i+= 1){
    listofMonsters [i] = malloc(sizeof(Enemy));
}

Enemy* Hulk = initializeMonster(12,"Hulk", 1, 10, 5, 25);
listofMonsters [12] = Hulk;

Enemy* Goblin= initializeMonster(15,"Goblin", 1, 10, 5, 25);
listofMonsters [15] = Goblin;

Enemy* Troll= initializeMonster(25,"Troll", 1, 10, 5, 25);
listofMonsters [25] = Troll;

Enemy* Cruella = initializeMonster(41,"Cruella", 2, 25, 15, 60);
listofMonsters [41] = Cruella;

Enemy* Joker = initializeMonster(50,"Joker", 2, 25, 15, 60);
listofMonsters [50] = Joker;

Enemy* Devil = initializeMonster(69,"Devil", 2, 25, 15, 60);
listofMonsters [69] = Devil;

Enemy* Voldemort = initializeMonster(70,"Voldemort", 3, 50, 40, 150);
listofMonsters [70] = Voldemort;

Enemy* Zombie = initializeMonster(80,"Zombie", 3, 50, 40, 150);
listofMonsters [80] = Zombie;

Enemy * Sauron = initializeMonster(98,"Sauron", 3, 50, 40, 150);
listofMonsters [98] = Sauron;

return listofMonsters;

}

int* getListofMonsterID(Enemy** monsterList, int size){
    int* listID = malloc(sizeof(int)*size);
    int cpt = 0;
    for (int i=0;i<29;i+=1){
        if (monsterList[i]!= 0){
            listID[cpt] = i;
            cpt+=1;
        }
    }
    return listID;
}

Enemy* createMonsterfromID(int enemyID){
    Enemy* monster = malloc(sizeof(Enemy));
    Enemy** list = createMonsters();
    monster = list[enemyID];
    for (int i = 0; i<29; i+=1){
        free(list[i]);
    }
    free(list);
    return monster;
}

void displayCharacteristicsMonster(int monsterID){
    Enemy** list = createMonsters();
    Enemy* monster = list[monsterID];
    printf("ID : %d \n", monster->id);
    printf("Name : %s \n", monster->name);
    printf("Life points : %d \n", monster->life);
    printf("Damage : %d \n", monster->damage);
    printf("Experience you will gain if you defeat %s : %d \n", monster->name, monster->expGained);
    for (int i = 0; i<29; i+=1){
        free(list[i]);
    }
    free(list);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "combat.h"

void round(Player* player, Enemy* monster){
    
}

void fight(Player* player, Enemy* monster){
    int weaponID = 0;
    int armorID = 0;
    int potionID = 0;
    printf("This is the monster you will fight: \n")
    displayCharacteristicsMonster(monster->id);
    displayInvPerType(Weapon, player->inventory);
    prinf("Pick the weapon with which you want to fight the monster and insert its number");
    scanf("%d", weaponID );
    displayInvPerType(Armor, player->inventory);
    prinf("Pick the armor with which you want to fight the monster and insert its number");
    scanf("%d", armorID);



    
    
}
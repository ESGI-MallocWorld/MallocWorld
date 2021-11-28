#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "combat.h"


Item* checkDurabilityofWeapon (int weaponID, Player* player, Enemy* monster){
    inventory* invPlayer = player->inventory;
    Item* weapon = malloc(sizeof(Item));
    while(invPlayer != NULL){
        if(invPlayer->inv->item->id == weaponID){
            //the durability of the weapon has to be larger than the life points of the monster devided by the damage the weapon causes
            if (invPlayer->inv->item->durability >= (float)(monster->life/invPlayer->inv->item->damage)){
                weapon = invPlayer->inv->item;
                return weapon;
            }  
        }
        invPlayer = invPlayer->next;
    }
    printf("You don't seem to have a weapon of this kind with enough durability to fight the monster.\n Please pick another weapon.\n");
    return NULL;
}

Item* chooseWeapon(Player* player, Enemy* monster){
    Item* weapon;
    int check = 0;
    int weaponID = 0;
    while(check == 0){
        displayInvPerType(Weapon, player->inventory);
        printf("Pick the weapon with which you want to fight the monster and insert its number\n");
        scanf("%d", weaponID );
        weapon = checkDurabilityofWeapon(weaponID, player, monster);
        if (weapon != NULL) {
            check = 1;
            return weapon;
        }
    }
    printf("You don't seem to have a usefull weapon in your inventory\n");
    return NULL;
}

Item* chooseArmor(Player* player){
    int armorID = 0;
    Item* armor = NULL;
    while (armor == NULL)
    {
        displayInvPerType(Armor, player->inventory);
        printf("Pick the armor with which you want to fight the monster and insert its number\n");
        scanf("%d", armorID);
        Item* armorTemp = getItemfromID(armorID);
        inventory* armorInv = getInventoryByItem(armorTemp, player->inventory);
        armor = armorInv->inv->item;
        free(armorTemp);
        if(armor->itemType != Armor){
            printf("The ID you entered is not the one of an armor.\n");
            armor = NULL;            
        }
       
    }
    
    return armor;
}

Item* choosePotion(Player* player){
    int PotionID = 0;
    Item* potion = NULL;
    while (potion == NULL){
        displayInvPerType(Potion, player->inventory);
        printf("Pick the potion you want to drink and enter its ID\n");
        scanf("%d", PotionID);
        Item* potionTemp = getItemfromID(PotionID);
        inventory* potionInv = getInventoryByItem(potionTemp, player->inventory);
        potion = potionInv->inv->item;
        if(potion->itemType != Potion){
            printf("The ID you entered is not the one of a potion.\n");
            potion = NULL;
        }

        free(potionTemp);
    }
 

    return potion;
}

int roundPlayer(Player* player, Item* weapon, Enemy* monster){
    /*return options:
    * 0: fight contintues
    * 1: game ends well (player beats the monster or manages to flee)
    * 2: player dies
    */
   int roundStatus = 0;
   while (roundStatus == 0)
   {
     printf("What do you want to do now ?\n 1. Attack\n 2. Take a potion\n 3. Try to flee\n Pick a number !\n");
    int actionID;
    scanf("%d", actionID);
    Item* potion;
    switch(actionID){
        case 1:
            printf("BAM !\n");
            monster->life -= weapon->damage;
            printf("%s has %d life points left.\n", monster->name, monster->life);
            weapon->durability -= 1;
            printf("Durability of you weapon after the attach: %d\n", weapon->durability);
            if(monster->life <= 0){
                player->exp += monster->expGained;
                printf("Congrats! You've killed %s!\n", monster->name);
                printf("You gain %d points of experience\n", monster->expGained);
                roundStatus = 1;
                return 1;
            }
            else {
                roundStatus = 1;
                return 0;
            }
            break;
        case 2:
            if (checkifTypePresent(Potion, player->inventory) == 0){
                printf("You do not have a potion in your inventory");
                
            }
            else {
                Item* potion = choosePotion(player);
                player->currentHp += potion->restoredHP;
                printf("You have %d life points now\n", player->currentHp);
                roundStatus = 1;
                return 0;
            }
            break;
        case 3:
            srand ( time(NULL) ); 
            int randomnumber;
            randomnumber = rand() % 10;
            if (randomnumber > 2){
                printf("You attempt to flee failed. %s killed you\n", monster->name);
                roundStatus = 1;
                return 2;
            }
            else{
                printf("You managed to flee %s. Good Job!\n", monster->name);
                roundStatus = 1;
                return 1;
            }
            break;
    }       
   }
   
   
}

int roundMonster(Player* player, Item* armor, Enemy* monster){
    if (armor == NULL){
        player->currentHp -= monster->damage;
        if (player->currentHp <= 0){
            printf("Too bad, you just got killed by %s\n", monster->name);
            return 2;
        }
        else{
            return 0;
        }
    }
    else{
        player->currentHp -= (int)(monster->damage*(float)(1 - armor->resistance/100 ));
        if (player->currentHp <= 0){
            printf("Too bad, you just got killed by %s\n", monster->name);
            return 2;
        }
        else{
            return 0;
        }       
    }
}

int fight(Player* player, Enemy* monster){//returns 1 if player wins, returns 2 if monster wins (=end of game)
    int potionID = 0;
    int gameStatus = 0;
    inventory* weaponInv;
    Item* weapon;
    Item* armor;
    printf("This is the monster you will fight: \n");
    displayCharacteristicsMonster(monster->id);
    weapon = chooseWeapon(player, monster);
    int damage = weapon->damage;
    if(checkifTypePresent(Armor, player->inventory) != 0) {
        armor = chooseArmor(player);
    }
    else {
        armor = NULL;
    }
    
    while (gameStatus == 0){
        gameStatus = roundPlayer(player, weapon, monster);
        if (gameStatus == 0){
            gameStatus = roundMonster(player, armor, monster);
        }
    }
    return gameStatus; // 1 if player wins, 2 if monster wins (=end of game)
       
}
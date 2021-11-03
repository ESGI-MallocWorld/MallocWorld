
//
//  Created by Adrian Barquero on 16/10/2021.
//

#ifndef MALLOCWORLD_PLAYER_H
#define MALLOCWORLD_PLAYER_H

typedef struct Level{
    
    int value;
    int upgrade;
    int exp_next;
    Level next;

} Level;

typedef struct Inventory{
    
    int* value;
    Inventory next;

} Inventory;

typedef struct Pnj{
    
    int* value;
    Inventory first;

} Pnj;

typedef struct Player{
    
    int exp;
    int* level;
    int hp;
    int hp_max;
    Inventory object;
    int* location;

} Player;

int * upgrade_level(int exp,int monster_exp,Level* test) {
    
    int x=exp+monster_exp;
    
    while (x>=test.exp_next) {
        test=test.next;
    }
    
    return test.value;
    
}

int * level = upgrade_level();

Player.level = level;

#endif /* MALLOCWORLD_PLAYER_H */

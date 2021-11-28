//
// Created by wuchi on 2021/10/14.
//

#ifndef MALLOCWORLD_COMBAT_H
#define MALLOCWORLD_COMBAT_H

#include "../core/inventory.h"
#include "../Units/enemis.h"
#include "../Units/Player.h"

Item* checkDurabilityofWeapon (int, Player*, Enemy*);

Item* chooseWeapon(Player*, Enemy*);

Item* chooseArmor(Player*);

Item* choosePotion(Player*);

int roundPlayer(Player*, Item*, Enemy*);

int roundMonster(Player*, Item*, Enemy*);

int fight(Player*, Enemy*);

#endif //MALLOCWORLD_COMBAT_H

//
// Created by wuchi on 2021/10/14.
//

#ifndef MALLOCWORLD_COMBAT_H
#define MALLOCWORLD_COMBAT_H

#include "../core/inventory.h"
#include "../Units/enemis.h"
#include "../Units/Player.h"

void round(Player*, Enemy*);

void fight(Player* player, Enemy* monster);

#endif //MALLOCWORLD_COMBAT_H

#ifndef DEFENSE_H
#define	DEFENSE_H

#include "../Structures/defense_struct.h"
#include "../Structures/game_struct.h"
#include "includes.h"
#include "notify.h"

Defense init_defense(int c, char *desc);
int enough_defense(Game *game, Defense defense);
int buy_defense(Game *game, Defense defense);
void description_defense(Game *game, Defense defense);

#endif	/* DEFENSE_H */


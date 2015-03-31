#ifndef CASERNE_H
#define	CASERNE_H

#include "../Structures/caserne_struct.h"
#include "../Structures/game_struct.h"
#include "../Structures/player_struct.h"
#include "includes.h"
#include "notify.h"

Caserne init_caserne(int c, char *desc);
int enough_caserne(Game *game, Caserne caserne);
int buy_caserne(Game *game, Caserne caserne);
void description_caserne(Game *game, Caserne caserne);

#endif	/* CASERNE_H */


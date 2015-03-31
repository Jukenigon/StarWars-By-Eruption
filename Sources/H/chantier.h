#ifndef CHANTIER_H
#define	CHANTIER_H

#include "../Structures/chantier_struct.h"
#include "../Structures/game_struct.h"
#include "includes.h"
#include "notify.h"

Chantier init_chantier(int c, char *desc);
int enough_chantier(Game *game, Chantier chantier);
int buy_chantier(Game *game, Chantier chantier);
void description_chantier(Game *game, Chantier chantier);

#endif	/* CHANTIER_H */


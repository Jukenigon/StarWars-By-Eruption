#ifndef BATIMENT_H
#define BATIMENT_H

#include "../Structures/batiment_struct.h"
#include "../Structures/player_struct.h"
#include "../Structures/game_struct.h"
#include "../H/notify.h"

Batiment init_batiment(int c, char *desc);
int enough_batiment(Game *game, Batiment batiment);
int buy_batiment(Game *game, Batiment batiment);
void description_batiment(Game *game, Batiment batiment);

#endif	/* BATIMENT_H */


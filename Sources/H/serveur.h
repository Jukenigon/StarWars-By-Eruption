#ifndef SERVEUR_H
#define SERVEUR_H

#include "../Structures/game_struct.h"
#include "../H/includes.h"

void server(Game *game);
int receive(Game *game, char *message);

#endif	/* SERVEUR_H */


#ifndef OPTIONS_H
#define OPTIONS_H

#include "../H/includes.h"
#include "../Structures/game_struct.h"

void options(Game *game);
void afficher_options(Game *game);
void free_options(Game *game);
void options_event(Game *game);
void save(Game *game);

#endif	/* OPTIONS_H */


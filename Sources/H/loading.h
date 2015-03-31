#ifndef LOADING_H
#define LOADING_H

#include "../Structures/game_struct.h"
#include "../Structures/login_struct.h"
#include "../Structures/loading_struct.h"

void loading(Game *game, void (*p)(Game *));
void unloading(Game *game, void (*p)(Game *));
void free_loading(SDL_Surface *);

#endif
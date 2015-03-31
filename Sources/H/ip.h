#ifndef IP_H
#define	IP_H

#include "../Structures/game_struct.h"

void ip_input(Game *game);
void ip_event(Game *game);
void free_ip(Game *game);
void entry_key(Game *game, SDL_Event event);
void afficher_ip(Game *game);

#endif	/* IP_H */


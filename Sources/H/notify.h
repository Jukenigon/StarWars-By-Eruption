#ifndef NOTIFY_H
#define	NOTIFY_H

#include "../Structures/game_struct.h"

void notify(Game *game, char *message, int sec);
void free_notify(Game *game);

#endif	/* NOTIFY_H */


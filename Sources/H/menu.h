#include "../Structures/menu_struct.h"
#include "../Structures/game_struct.h"
#include "../Structures/box_struct.h"

#include "includes.h"

void init_menu(Game *game);
int menu(Game *game);
void free_menu(Game *game);
void afficher(Game *game);
int event_menu(Game *game);

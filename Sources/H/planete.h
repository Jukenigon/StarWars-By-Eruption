#include "../Structures/planete_struct.h"
#include "../Structures/game_struct.h"

Planete init_planete(char *n, char *d, int c, int df);
int enough_planete(Game *game, Planete planete);
int combat(Game *game, Planete planete);
int buy_planete(Game *game, Planete planete);
int verification_gagnant(Game *game, int nb);

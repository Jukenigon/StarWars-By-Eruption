#include "../H/timer.h"

int timer(Game *game)
{
    game->timer.tempsActuel = SDL_GetTicks();
    if (game->timer.tempsActuel - game->timer.tempsPrecedent > 30000)
    {
                     
                 game->timer.tempsPrecedent = game->timer.tempsActuel;
                 return 1;
        }
    else return 0;
}

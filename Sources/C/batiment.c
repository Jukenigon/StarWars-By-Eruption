#include "../H/batiment.h"
#include <stdlib.h>

Batiment init_batiment(int c, char *desc)
{
    Batiment bat;
    
    bat.cout = c;
    bat.description = desc;
    
    return bat;
}

int enough_batiment(Game *game, Batiment batiment)
{
    if(batiment.cout > game->player[game->srv].credits)
        return 0;
    
    else return 1;
}

int buy_batiment(Game *game, Batiment batiment)
{
    if(enough_batiment(game, batiment))
    {
        char *c = (char*)malloc(10 * sizeof(char));
        game->player[game->srv].credits -= batiment.cout;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
        free(c);
        return 1;
    }

        notify(game, "Credit insuffisant", 1);
        return 0;
}
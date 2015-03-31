#include "../H/chantier.h"

Chantier init_chantier(int c, char *desc)
{
    Chantier chant;
    
    chant.cout = c;
    chant.description = desc;
    
    return chant;
}

int enough_chantier(Game *game, Chantier chantier)
{
    if(chantier.cout > game->player[game->srv].credits)
        return 0;
    
    else return 1;
}

int buy_chantier(Game *game, Chantier chantier)
{
    if(enough_chantier(game, chantier))
    {
        char *c = (char*)malloc(10 * sizeof(char));
        game->player[game->srv].credits -= chantier.cout;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
        free(c);
        return 1;
    }

        notify(game, "Credit insuffisant", 1);
        return 0;
}


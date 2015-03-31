#include "../H/caserne.h"

Caserne init_caserne(int c, char *desc)
{
    Caserne cas;
    
    cas.cout = c;
    cas.description = desc;
    
    return cas;
}

int enough_caserne(Game *game, Caserne caserne)
{
    if(caserne.cout > game->player[game->srv].credits)
        return 0;
    
    else return 1;
}

int buy_caserne(Game *game, Caserne caserne)
{
    if(enough_caserne(game, caserne))
    {
        char *c = (char*)malloc(10 * sizeof(char));
        game->player[game->srv].credits -= caserne.cout;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
        free(c);
        return 1;
    }

        notify(game, "Credit insuffisant", 1);
        return 0;
}


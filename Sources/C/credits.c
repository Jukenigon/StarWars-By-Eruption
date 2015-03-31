#include "../H/credits.h"

void new_credits(Game *game)
{
    if(game->player[game->srv].lvl_mine > 0)
    {
        char *c = (char*)malloc(10 * sizeof(char));
        game->player[game->srv].credits += game->player[game->srv].credits / 2;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
    }
}

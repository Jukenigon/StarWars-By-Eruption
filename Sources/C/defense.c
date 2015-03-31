#include "../H/defense.h"

Defense init_defense(int c, char *desc)
{
    Defense def;
    
    def.cout = c;
    def.description = desc;
    
    return def;
}

int enough_defense(Game *game, Defense defense)
{
    if(game->player[game->srv].credits < defense.cout )
        return 0;
    
    else return 1;
}

int buy_defense(Game *game, Defense defense)
{
    if(enough_defense(game, defense))
    {
        char *c = (char*)malloc(10 * sizeof(char));
        game->player[game->srv].credits -= defense.cout;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
        free(c);
        return 1;
    }

        notify(game, "Credit insuffisant", 1);
        return 0;
}

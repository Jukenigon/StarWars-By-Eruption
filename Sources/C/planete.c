#include "../H/planete.h"
#include <stdlib.h>
#include <string.h>

Planete init_planete(char *n, char *d, int c, int df)
{
    Planete p;
    
    p.nom = n;
    p.type = d;
    p.cout = c;
    p.defense = df;
    
    return p;
}

int enough_planete(Game *game, Planete planete)
{
    if(planete.cout > game->player[game->srv].credits)
        return 0;
    
    else return 1;
}

int buy_planete(Game *game, Planete planete)
{
    if(enough_planete(game, planete))
    {
        char *c = (char*)malloc(10 * sizeof(char));
        game->player[game->srv].credits -= planete.cout;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
        free(c);
        return 1;
    }

        notify(game, "Vous ne pouvez pas acheter cette planete pour le moment...", 1);
        return 0;
}

int combat(Game *game, Planete planete)
{
    if(game->player[game->srv].attaque > planete.defense)
    {
        return 1;
    }
    
    else
    {
        char *c = (char*)malloc(10 * sizeof(char));
        notify(game, "Suite a cette bataille, vous perdez de l'argent", 1);
        game->player[game->srv].credits -= game->player[game->srv].credits / 2;
        sprintf(c, "%d", game->player[game->srv].credits);
        game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
        free(c);
        return 0;
    }
}

int verification_gagnant(Game *game, int nb)
{
    if(nb == game->nb_planete)
        return 1;
    
    else return 0;
}
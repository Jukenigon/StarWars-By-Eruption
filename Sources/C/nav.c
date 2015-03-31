#include "../H/section.h"
#include "../H/includes.h"
#include "../H/notify.h"
#include "../H/listener.h"

void nav(Game *game, SDL_Event event)
{
             if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        if(on_mouse_click(&game->choice.button[0].box, event))
                        {
                                game->choice.group = 1;
                                game->choice.nav = 0;
                                game->choice.section = 1;  
                        }
                        if(on_mouse_click(&game->choice.button[1].box, event))
                        {
                                game->choice.group = 1;
                                game->choice.nav = 0;
                                 game->choice.section = 2;
                        }
                        if(on_mouse_click(&game->choice.button[2].box, event))
                        {
                                game->choice.group = 1;
                                game->choice.nav = 0;
                                 game->choice.section = 3;
                        }
                        if(on_mouse_click(&game->choice.button[3].box, event))
                        {
                                game->choice.group = 0;
                                game->choice.nav = 0;
                                 game->choice.section = 4;
                        }
                        if(on_mouse_click(&game->choice.button[4].box, event))
                        {
                                game->choice.group = 1;
                                game->choice.nav = 0;
                                 game->choice.section = 5;
                        }

                        
                         if(on_mouse_click(&game->choice.button[5].box, event))
                         {
                                game->choice.nav = 1;
                                game->choice.section = 6;
                         }
                        
                        if(on_mouse_click(&game->choice.button[7].box, event))
                            if(game->srv) 
                            {
                                sender(game, "0x00");
                                game->choice.loop = 0;
                            }
             }
}

void afficher_nav(Game *game)
{
    SDL_BlitSurface(game->choice.background[1], NULL, game->screen, &game->choice.pbackground);
    SDL_BlitSurface(game->choice.button[26].img, NULL, game->screen, &game->choice.button[26].pbutton);
    
    for(game->choice.i = 0; game->choice.i < game->nb_planete; game->choice.i++)
    {
        if(game->choice.i  % 2)
        {
            game->choice.button[27].pbutton.x = game->choice.button[26].pbutton.x;
            game->choice.button[27].pbutton.y = game->choice.i * 31 + 100;
            SDL_BlitSurface(game->choice.button[27].img, NULL, game->screen, &game->choice.button[27].pbutton);
        }
        
        else
        {
            game->choice.button[28].pbutton.x = game->choice.button[26].pbutton.x;
            game->choice.button[28].pbutton.y = game->choice.i * 31 + 100;
            SDL_BlitSurface(game->choice.button[28].img, NULL, game->screen, &game->choice.button[28].pbutton);
        }
        
         if(game->planete[game->choice.i].owner == 0)
                SDL_BlitSurface(game->sith, NULL, game->screen, &game->planete[game->choice.i].embleme.pos);
            
            if(game->planete[game->choice.i].owner == 1)
                SDL_BlitSurface(game->jedi, NULL, game->screen, &game->planete[game->choice.i].embleme.pos);
        
        SDL_BlitSurface(game->planete[game->choice.i].text.text, NULL, game->screen, &game->planete[game->choice.i].text.ptext);
        SDL_BlitSurface(game->choice.action[game->choice.i][0].tmp, NULL, game->screen, &game->choice.action[game->choice.i][0].pbutton);
        SDL_BlitSurface(game->choice.action[game->choice.i][1].tmp, NULL, game->screen, &game->choice.action[game->choice.i][1].pbutton);
        SDL_BlitSurface(game->choice.action[game->choice.i][2].tmp, NULL, game->screen, &game->choice.action[game->choice.i][2].pbutton);
        SDL_BlitSurface(game->choice.action[game->choice.i][3].tmp, NULL, game->screen, &game->choice.action[game->choice.i][3].pbutton);
    }
}

void event_navigation(Game *game, SDL_Event event)
{
    for(game->choice.i = 0; game->choice.i < game->nb_planete; game->choice.i++)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            buy(game, event);
            fight(game, event);
        }
    }
}

void buy(Game *game, SDL_Event event)
{
    if(on_mouse_click(&game->choice.action[game->choice.i][3].box, event))
            {
                if(game->srv)
                {
                    switch(game->planete[game->choice.i].owner)
                    {
                        case 1:
                            notify(game, "Vous possedez deja cette planete", 1);
                            break;                        
                        default:
                                if(buy_planete(game, game->planete[game->choice.i]))
                                {
                                        char tmp[512];
                                        notify(game, "Planete achetee", 1);
                                        game->planete[game->choice.i].owner = 1;
                                        sprintf(tmp, "1x0%d", game->choice.i);
                                        sender(game, tmp);
                                        game->player[1].planete++;
                                }
                         break;
                    }
                    if(verification_gagnant(game, game->player[1].planete))
                    {                        
                        sender(game, "2x00");
                        notify(game, "Vous avez gagne", 1);
                        game->choice.loop = 0;
                    }
                }
        
        if(!game->srv)
        {
            switch(game->planete[game->choice.i].owner)
            {
                case  0:
                    notify(game, "Vous possedez deja cette planete", 1);
                    break;
                default:
                        if(buy_planete(game, game->planete[game->choice.i]))
                         {
                                char tmp[512];
                                 notify(game, "Planete achetee", 1);
                                game->planete[game->choice.i].owner = 0;
                                sprintf(tmp, "1x0%d", game->choice.i);
                                sender(game, tmp);
                                game->player[0].planete++;
                        }
                        break;
            }
            
            if(verification_gagnant(game, game->player[0].planete))
            {
                        sender(game, "2x00");
                        notify(game, "Vous avez gagne", 1);
                        game->choice.loop = 0;
            }
        }
                                
            }
}

void fight(Game *game, SDL_Event event)
{
    if(on_mouse_click(&game->choice.action[game->choice.i][2].box, event))
            {
                if(game->srv)
                {
                    switch(game->planete[game->choice.i].owner)
                    {
                        case 1:
                            notify(game, "Vous possedez deja cette planete", 1);
                            break;
                        
                        default:
                                if(combat(game, game->planete[game->choice.i]))
                                {
                                        char tmp[512];
                                        notify(game, "Planete achetee", 1);
                                        game->planete[game->choice.i].owner = 1;
                                        sprintf(tmp, "1x0%d", game->choice.i);
                                        sender(game, tmp);
                                        game->player[1].planete++;
                                }
                         break;
                    }
                    if(verification_gagnant(game, game->player[1].planete))
                    {                        
                        sender(game, "2x00");
                        notify(game, "Vous avez gagne", 1);
                        game->choice.loop = 0;
                    }
                }
        
        if(!game->srv)
        {
            switch(game->planete[game->choice.i].owner)
            {
                case  0:
                    notify(game, "Vous possedez deja cette planete", 1);
                    break;
                default:
                        if(combat(game, game->planete[game->choice.i]))
                         {
                                char tmp[512];
                                 notify(game, "Planete achetee", 1);
                                game->planete[game->choice.i].owner = 0;
                                sprintf(tmp, "1x0%d", game->choice.i);
                                sender(game, tmp);
                                game->player[0].planete++;
                        }
                        break;
            }
            
            if(verification_gagnant(game, game->player[0].planete))
            {
                        sender(game, "2x00");
                        notify(game, "Vous avez gagne", 1);
                        game->choice.loop = 0;
            }
        }
                                
            }
}
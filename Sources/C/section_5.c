#include "../H/section.h"

void event_section_5(Game *game, SDL_Event event)
{
     if(!game->player[game->srv].lvl_caserne)
    {
        notify(game, "La caserne est requise pour acceder a cette zone...", 1);
        game->choice.section = 2;
    }
     
    if(event.button.button == SDL_BUTTON_LEFT)
    {
         if(on_mouse_click(&game->choice.button[22].box, event))
                            if(buy_caserne(game, game->ressources.droides))
                            {
                                game->player[game->srv].lvl_droides++;
                                notify(game, "Level Droides++", 1);
                                game->player[game->srv].attaque += 10;
                            }
         if(on_mouse_click(&game->choice.button[23].box, event))
                            if(buy_caserne(game, game->ressources.clones))
                            {
                                game->player[game->srv].lvl_clones++;
                                notify(game, "Level Clones++", 1);
                                game->player[game->srv].attaque += 100;
                            }
         if(on_mouse_click(&game->choice.button[24].box, event))
                            if(buy_caserne(game, game->ressources.commando))
                            {
                                game->player[game->srv].lvl_commando++;
                                notify(game, "Level Commando++", 1);
                                game->player[game->srv].attaque += 500;
                            }
         if(on_mouse_click(&game->choice.button[25].box, event))
                            if(buy_caserne(game, game->ressources.jedi))
                            {
                                game->player[game->srv].lvl_jedi++;
                                notify(game, "Level Jedi++", 1);
                                game->player[game->srv].attaque += 1000;
                            }
    }
    
    else
     {
                            if(on_mouse_click(&game->choice.button[22].box, event))
                                 print_description(game, game->ressources.droides.description);
                           if(on_mouse_click(&game->choice.button[23].box, event))
                                 print_description(game, game->ressources.clones.description);
                           if(on_mouse_click(&game->choice.button[24].box, event))
                                 print_description(game, game->ressources.commando.description);
                            if(on_mouse_click(&game->choice.button[25].box, event))
                                 print_description(game, game->ressources.jedi.description);
    }
    
}


#include "../H/section.h"

void event_section_2(Game *game, SDL_Event event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
         if(on_mouse_click(&game->choice.button[8].box, event))
                            if(buy_batiment(game, game->ressources.senat))
                            {
                                game->player[game->srv].lvl_senat++;
                                notify(game, "Level Senat++", 1);
                            }
         if(on_mouse_click(&game->choice.button[9].box, event))
                            if(buy_batiment(game, game->ressources.mine))
                            {
                                game->player[game->srv].lvl_mine++;
                                notify(game, "Level Mine++", 1);
                            }
         if(on_mouse_click(&game->choice.button[10].box, event))
                            if(buy_batiment(game, game->ressources.mine))
                            {
                                game->player[game->srv].lvl_chantier++;
                                notify(game, "Level Chantier++", 1);
                            }
         if(on_mouse_click(&game->choice.button[11].box, event))
                            if(buy_batiment(game, game->ressources.mine))
                            {
                                game->player[game->srv].lvl_caserne++;
                                notify(game, "Level Caserne++", 1);
                            }
    }
    
    else
     {
                            if(on_mouse_click(&game->choice.button[8].box, event))
                                 print_description(game, game->ressources.senat.description);
                           if(on_mouse_click(&game->choice.button[9].box, event))
                                 print_description(game, game->ressources.mine.description);
                           if(on_mouse_click(&game->choice.button[10].box, event))
                                 print_description(game, game->ressources.chantier.description);
                            if(on_mouse_click(&game->choice.button[11].box, event))
                                 print_description(game, game->ressources.caserne.description);
             }
    }

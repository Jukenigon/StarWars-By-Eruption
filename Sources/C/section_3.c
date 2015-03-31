#include "../H/section.h"

void event_section_3(Game *game, SDL_Event event)
{    
    if(game->player[game->srv].lvl_senat == 0)
    {
        notify(game, "Le senat est requis pour acceder a cette zone", 1);
        game->choice.section = 2;
    }
    
    if(event.button.button == SDL_BUTTON_LEFT)
    {
         if(on_mouse_click(&game->choice.button[12].box, event))
                            if(buy_defense(game, game->ressources.canon))
                            {
                                game->player[game->srv].lvl_canon++;
                                notify(game, "Level Canon++", 1);
                                game->player[game->srv].attaque += 10;
                            }
         if(on_mouse_click(&game->choice.button[13].box, event))
                            if(buy_defense(game, game->ressources.tourelle))
                            {
                                game->player[game->srv].lvl_mine++;
                                notify(game, "Level Tourelle++", 1);
                                game->player[game->srv].attaque += 20;
                            }
         if(on_mouse_click(&game->choice.button[14].box, event))
                            if(buy_defense(game, game->ressources.drone))
                            {
                                game->player[game->srv].lvl_chantier++;
                                notify(game, "Level Drone++", 1);
                                game->player[game->srv].attaque += 30;
                            }
         if(on_mouse_click(&game->choice.button[15].box, event))
                            if(buy_defense(game, game->ressources.puit))
                            {
                                game->player[game->srv].lvl_caserne++;
                                notify(game, "Level Puit++", 1);
                                game->player[game->srv].attaque += 40;
                            }
    }
    
    else
     {
                            if(on_mouse_click(&game->choice.button[12].box, event))
                                 print_description(game, game->ressources.canon.description);
                           if(on_mouse_click(&game->choice.button[13].box, event))
                                 print_description(game, game->ressources.tourelle.description);
                           if(on_mouse_click(&game->choice.button[14].box, event))
                                 print_description(game, game->ressources.drone.description);
                            if(on_mouse_click(&game->choice.button[15].box, event))
                                 print_description(game, game->ressources.puit.description);
      }
}

#include "../H/section.h"

void event_section_4(Game *game, SDL_Event event)
{
     if(!game->player[game->srv].lvl_chantier)
    {
        notify(game, "Le chantier spatial est requis pour acceder a cette zone...", 1);
        game->choice.section = 2;
    }
     
    if(event.button.button == SDL_BUTTON_LEFT)
    {
         if(on_mouse_click(&game->choice.button[16].box, event))
                            if(buy_chantier(game, game->ressources.chasseur))
                            {
                                game->player[game->srv].lvl_chasseur++;
                                notify(game, "Level Chasseur++", 1);
                                game->player[game->srv].attaque += 100;
                            }
         if(on_mouse_click(&game->choice.button[17].box, event))
                            if(buy_chantier(game, game->ressources.chasseur2))
                            {
                                game->player[game->srv].lvl_chasseur2++;
                                notify(game, "Level Chasseur 2++", 1);
                                game->player[game->srv].attaque += 200;
                            }
         if(on_mouse_click(&game->choice.button[18].box, event))
                            if(buy_chantier(game, game->ressources.transport))
                            {
                                game->player[game->srv].lvl_transport++;
                                notify(game, "Level Transport++", 1);
                                game->player[game->srv].attaque += 300;
                            }
         if(on_mouse_click(&game->choice.button[19].box, event))
                            if(buy_chantier(game, game->ressources.croiseur))
                            {
                                game->player[game->srv].lvl_croiseur++;
                                notify(game, "Level Croiseur++", 1);
                                game->player[game->srv].attaque += 500;
                            }
         
         if(on_mouse_click(&game->choice.button[20].box, event))
                            if(buy_chantier(game, game->ressources.destroyer))
                            {
                                game->player[game->srv].lvl_destroyer++;
                                notify(game, "Level Destroyer++", 1);
                                game->player[game->srv].attaque += 800;
                        }
          if(on_mouse_click(&game->choice.button[21].box, event))
                            if(buy_chantier(game, game->ressources.etoile))
                            {
                                game->player[game->srv].lvl_etoile++;
                                notify(game, "Level Etoile de la mort++", 1);
                                game->player[game->srv].attaque += 1000;
                        }
    }
    
    else
     {
                            if(on_mouse_click(&game->choice.button[16].box, event))
                                 print_description(game, game->ressources.chasseur.description);
                           if(on_mouse_click(&game->choice.button[17].box, event))
                                 print_description(game, game->ressources.chasseur2.description);
                           if(on_mouse_click(&game->choice.button[18].box, event))
                                 print_description(game, game->ressources.transport.description);
                            if(on_mouse_click(&game->choice.button[19].box, event))
                                 print_description(game, game->ressources.croiseur.description);
                            if(on_mouse_click(&game->choice.button[20].box, event))
                                 print_description(game, game->ressources.destroyer.description);
                            if(on_mouse_click(&game->choice.button[21].box, event))
                                 print_description(game, game->ressources.etoile.description);
             }
    }


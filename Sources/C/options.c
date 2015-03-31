#include "../H/includes.h"

#include "../H/options.h"
#include "../H/init_position.h"
#include "../H/box.h"
#include "../H/mouse.h"
#include "../H/checkbox.h"

void options(Game *game)
{
    game->options.page = 1;
    game->options.background = NULL,  game->options.opt[0] = NULL, game->options.opt[1] = NULL;
    
    game->options.background = IMG_Load("Res/Pictures/background.png");
    game->options.opt[0] = IMG_Load("Res/Pictures/options/options_a.png");
    game->options.opt[1] = IMG_Load("Res/Pictures/options/options_b.png");
    
    game->options.close[0] = IMG_Load("Res/Pictures/options/close_a.png");
    game->options.close[1] = IMG_Load("Res/Pictures/options/close_b.png");
    
    game->options.checkbox[0] = init_checkbox(247, 467, 35, 33);
    game->options.checkbox[1] = init_checkbox(207, 557, 35, 33);
    game->options.checkbox[2] = init_checkbox(297, 627, 35, 33);
    
   game->options.loop = 1;
   
   game->options.pbackground = init_position(0, 0, -1, -1);
   game->options.popt = init_position(37, 337, -1, -1);
   
   game->options.pclose = init_position(693, 340, -1, -1);   
   game->options.close_box = init_box(693, 340, 32, 32);
   
   game->options.page_box[0] = init_box(37, 330, 237, 30);
   game->options.page_box[1] = init_box(237, 330, 260, 30);
   
   options_event(game);
   
   save(game);
   //unloading(game, afficher_options);
   free_options(game);
}

void options_event(Game *game)
{  
    SDL_Event event;
    int i;
    
    while(game->options.loop)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    if(on_mouse_over(&game->options.close_box, event))
                        game->options.tmp = game->options.close[1];                    
                    else game->options.tmp = game->options.close[0];
                             
                    for(i = 0; i < 3; i++)
                    {
                        if(on_mouse_over(&game->options.checkbox[i].box, event) && game->options.checkbox[i].isActive)
                            game->options.checkbox[i].tmp = game->options.checkbox[i].img_active_b;
                        
                        if(!on_mouse_over(&game->options.checkbox[i].box, event) && game->options.checkbox[i].isActive)
                            game->options.checkbox[i].tmp = game->options.checkbox[i].img_active;
                        
                        if(on_mouse_over(&game->options.checkbox[i].box, event) && game->options.checkbox[i].isActive == 0)
                            game->options.checkbox[i].tmp = game->options.checkbox[i].img_non_active_b;
                        
                        if(!on_mouse_over(&game->options.checkbox[i].box, event) && game->options.checkbox[i].isActive == 0)
                                game->options.checkbox[i].tmp = game->options.checkbox[i].img_non_active;
                    }

                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(on_mouse_click(&game->options.close_box, event))
                        game->options.loop = 0;
                    
                    if(on_mouse_click(&game->options.page_box[0], event))
                        game->options.page = 1;
                    
                     if(on_mouse_click(&game->options.page_box[1], event))
                        game->options.page = 2;
                    
                    for(i = 0; i < 3; i++)
                    {
                        if(on_mouse_click(&game->options.checkbox[i].box, event) && game->options.checkbox[i].isActive )
                        {
                            game->options.checkbox[i].isActive = 0;
                            game->options.checkbox[i].tmp = game->options.checkbox[i].img_non_active;
                            break;
                        }
                        
                         if(on_mouse_click(&game->options.checkbox[i].box, event) && game->options.checkbox[i].isActive == 0)
                        {
                             game->options.checkbox[i].isActive = 1;
                            game->options.checkbox[i].tmp = game->options.checkbox[i].img_non_active;
                            break;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        afficher_options(game);
        update(game);
    }
}

void save(Game *game)
{
    FILE *fp = NULL;
    fp = fopen("Saves/config.sw", "w");
    
    if(fp != NULL)
    {
        fprintf(fp, "Sound:%d\nEffect:%d\nAll:%d", game->options.checkbox[0].isActive, game->options.checkbox[1].isActive, game->options.checkbox[2].isActive);    
        fclose(fp);
    }
    
    else notify(game, "Impossible d'ecrire le fichier config.sw", 2);
}

void afficher_options(Game *game)
{
    SDL_BlitSurface(game->options.background, NULL, game->screen, &game->options.pbackground);
    
    if(game->options.page == 1)
    {
        SDL_BlitSurface(game->options.opt[0], NULL, game->screen, &game->options.popt);
    }
    
    else
    {
        SDL_BlitSurface(game->options.opt[1], NULL, game->screen, &game->options.popt);
        SDL_BlitSurface(game->options.checkbox[0].tmp, NULL, game->screen, &game->options.checkbox[0].pos);
        SDL_BlitSurface(game->options.checkbox[1].tmp, NULL, game->screen, &game->options.checkbox[1].pos);
        SDL_BlitSurface(game->options.checkbox[2].tmp, NULL, game->screen, &game->options.checkbox[2].pos);
    }
    
     SDL_BlitSurface(game->options.tmp, NULL, game->screen, &game->options.pclose);
}

void free_options(Game *game)
{
    SDL_FreeSurface(game->options.background);
    SDL_FreeSurface(game->options.opt[0]);
    SDL_FreeSurface(game->options.opt[1]);
    SDL_FreeSurface(game->options.close[0]);
    SDL_FreeSurface(game->options.close[1]);
}
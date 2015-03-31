#include "../H/includes.h"
#include "../H/settings.h"

#include "../H/init_position.h"
#include "../H/box.h"
#include "../H/first_screen.h"
#include "../Structures/planete_struct.h"
#define PAS 10000
#define MIN_NB_CREDITS 1
#define MAX_NB_CREDITS 10
#define MAX_NB_PLANETE 10
#define MIN_NB_PLANETE 2
#define SERVEUR 1

void settings(Game *game)
{
    game->settings.nb_credit =  MIN_NB_CREDITS ;
    game->settings.text[0].font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 16);
    game->settings.text[0].color.r = 0;
    game->settings.text[0].color.g = 0;
    game->settings.text[0].color.b = 0;
    
    game->settings.nb_planete =  MIN_NB_PLANETE ;
    sprintf(game->settings.cred, "%d", game->settings.nb_credit * PAS);
    game->settings.text[0].text = TTF_RenderText_Blended(game->settings.text[0].font, game->settings.cred, game->settings.text[0].color);    
    game->settings.text[0].ptext = init_position(750, 452, -1, -1);
    
    sprintf(game->settings.nbp, "%d", game->settings.nb_planete);
    game->settings.text[1].text = TTF_RenderText_Blended(game->settings.text[0].font, game->settings.nbp, game->settings.text[0].color);
    game->settings.text[1].ptext = init_position(550, 452, -1, -1);
    
    
    game->settings.background = IMG_Load("Res/Pictures/background.png");
    game->settings.pos = init_position(0, 0, -1, -1);
    
    game->settings.reglage = IMG_Load("Res/Pictures/settings/reglages.png");
    game->settings.preglage = init_position(400, 361, -1, -1);
    
    for(game->settings.i = 0; game->settings.i < 4; game->settings.i++)
    {
        if(game->settings.i % 2 != 0)
        {
            game->settings.arrow[game->settings.i].img = IMG_Load("Res/Pictures/settings/droite_a.png");
            game->settings.arrow[game->settings.i].img2 = IMG_Load("Res/Pictures/settings/droite_b.png");
            game->settings.arrow[game->settings.i].tmp = game->settings.arrow[game->settings.i].img;
        }
        
        else
        {
            game->settings.arrow[game->settings.i].img = IMG_Load("Res/Pictures/settings/gauche_a.png");
            game->settings.arrow[game->settings.i].img2 = IMG_Load("Res/Pictures/settings/gauche_b.png");
            game->settings.arrow[game->settings.i].tmp = game->settings.arrow[game->settings.i].img;
        }
    }
    
    game->settings.arrow[0].pbutton = init_position(520, 445, -1, -1);
    game->settings.arrow[0].box = init_box(520, 445, 26, 30);
    game->settings.arrow[2].pbutton= init_position(710, 445, -1, -1);
    game->settings.arrow[2].box = init_box(710, 445, 26, 30);
    
    game->settings.arrow[1].pbutton= init_position(630, 445, -1, -1);
    game->settings.arrow[1].box = init_box(630, 445, 26, 30);
    game->settings.arrow[3].pbutton= init_position(820, 445, -1, -1);
    game->settings.arrow[3].box = init_box(820, 445, 26, 30);
    
    settings_event(game);
    game->player[SERVEUR].credits = game->settings.nb_credit * PAS;
    game->nb_planete = game->settings.nb_planete;
    free_settings(game);
    make_a_choice(game);
}

void settings_event(Game *game)
{
    int loop = 1;
    
    SDL_Event event;
    
    while(loop)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    for(game->settings.i = 0; game->settings.i < 4; game->settings.i++)
                    {
                        if(on_mouse_over(&game->settings.arrow[game->settings.i].box, event))
                            game->settings.arrow[game->settings.i].tmp = game->settings.arrow[game->settings.i].img2;
                        
                        else game->settings.arrow[game->settings.i].tmp = game->settings.arrow[game->settings.i].img;
                    }
                    break;
                    case SDL_MOUSEBUTTONDOWN:
                        
                     if(on_mouse_click(&game->settings.arrow[0].box, event))
                         if(game->settings.nb_planete > MIN_NB_PLANETE)
                                game->settings.nb_planete-=2;
                     if(on_mouse_click(&game->settings.arrow[1].box, event))
                         if(game->settings.nb_planete< MAX_NB_PLANETE)
                                game->settings.nb_planete+=2;
                     
                     if(on_mouse_click(&game->settings.arrow[2].box, event))
                         if(game->settings.nb_credit > MIN_NB_CREDITS)
                                game->settings.nb_credit--;
                     if(on_mouse_click(&game->settings.arrow[3].box, event))
                         if(game->settings.nb_credit < MAX_NB_CREDITS)
                                game->settings.nb_credit++;                                    
                     
                     sprintf(game->settings.cred, "%d", game->settings.nb_credit * PAS);
                     game->settings.text[0].text = TTF_RenderText_Blended(game->settings.text[0].font, game->settings.cred, game->settings.text[0].color);
                     
                     sprintf(game->settings.nbp, "%d", game->settings.nb_planete);
                     game->settings.text[1].text = TTF_RenderText_Blended(game->settings.text[0].font, game->settings.nbp, game->settings.text[0].color);
                     break;
                case SDL_KEYDOWN:
                    loop = 0;
                    break;
            }
        }
        afficher_settings(game);
        update(game);
    }
}

void afficher_settings(Game *game)
{
    SDL_BlitSurface(game->settings.background, NULL, game->screen, &game->settings.pos);
    SDL_BlitSurface(game->settings.reglage, NULL, game->screen, &game->settings.preglage);
    
    SDL_BlitSurface(game->settings.text[0].text, NULL, game->screen, &game->settings.text[0].ptext);
    SDL_BlitSurface(game->settings.text[1].text, NULL, game->screen, &game->settings.text[1].ptext);
    
    for(game->settings.i = 0; game->settings.i < 4; game->settings.i++)
    {
        SDL_BlitSurface(game->settings.arrow[game->settings.i].tmp, NULL, game->screen, &game->settings.arrow[game->settings.i].pbutton);
    }
}

void free_settings(Game *game)
{
    SDL_FreeSurface(game->settings.background);
    SDL_FreeSurface(game->settings.reglage);
}

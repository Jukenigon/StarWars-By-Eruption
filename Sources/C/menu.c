#include "../Structures/menu_struct.h"
#include "../Structures/box_struct.h"

#include "../H/includes.h"
#include "../H/menu.h"
#include "../H/box.h"
#include "../H/mouse.h"
#include "../H/choice.h"
#include "../H/init_position.h"
#include "../H/serveur.h"
#include "../H/quit.h"
#include "../H/ip.h"

void init_menu(Game *game)
{    
    game->menu.background = IMG_Load("Res/Pictures/background.png");
    
    game->menu.icone[0] = IMG_Load("Res/Pictures/Rechercher_une_partie_A.png");
    game->menu.icone[1] = IMG_Load("Res/Pictures/Creer_une_partie_A.png");
    game->menu.icone[2] = IMG_Load("Res/Pictures/Options_A.png");
    game->menu.icone[3] = IMG_Load("Res/Pictures/Quitter_le_jeu_A.png");
    
    game->menu.icone_b[0] = IMG_Load("Res/Pictures/Rechercher_une_partie_B.png");
    game->menu.icone_b[1] = IMG_Load("Res/Pictures/Creer_une_partie_B.png");
    game->menu.icone_b[2] = IMG_Load("Res/Pictures/Options_B.png");
    game->menu.icone_b[3] = IMG_Load("Res/Pictures/Quitter_le_jeu_B.png");
    
    game->menu.icone_actuelle[0] = game->menu.icone[0];
    game->menu.icone_actuelle[1] = game->menu.icone[1];
    game->menu.icone_actuelle[2] = game->menu.icone[2];
    game->menu.icone_actuelle[3] = game->menu.icone[3];
    
    game->menu.pbackground = init_position(0, 0, -1, -1);
    
    game->menu.picone[0] = init_position(100 ,400, -1, -1);
    game->menu.picone[1] = init_position(100, 480, -1, -1);
    game->menu.picone[2] = init_position(100, 560, -1, -1);  
    game->menu.picone[3] = init_position(100, 640, -1, -1); 
       
    game->menu.box[0] = init_box(100,400,304,62);
    game->menu.box[1] = init_box(100,480,304,62);
    game->menu.box[2] = init_box(100,560,304,62);
    game->menu.box[3] = init_box(100,640,304,62);
}

int menu(Game *game)
{
    int m;
    SDL_FillRect(game->screen, NULL, SDL_MapRGB(game->screen->format, 0, 0, 0));

    init_menu(game);
    
    loading(game, afficher);

    m = event_menu(game);
    free_menu(game);
    
    return m;
}

int event_menu(Game *game)
{
    int quit = 1;
    SDL_Event event;

    while(quit)
    {        
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    if(on_mouse_over(&game->menu.box[0], event))
                    {
                        game->menu.icone_actuelle[0] = game->menu.icone_b[0];  
                        Mix_PlayChannel(1, game->sound[1].son, 0);
                    }
                    
                    else game->menu.icone_actuelle[0] = game->menu.icone[0];
                    
                    if(on_mouse_over(&game->menu.box[1], event))    
                    {
                        game->menu.icone_actuelle[1] = game->menu.icone_b[1];
                        Mix_PlayChannel(1, game->sound[1].son, 0);
                    }
                    else game->menu.icone_actuelle[1] = game->menu.icone[1];
                    
                    if(on_mouse_over(&game->menu.box[2], event))
                    {
                        game->menu.icone_actuelle[2] = game->menu.icone_b[2];
                        Mix_PlayChannel(1, game->sound[1].son, 0);
                    }
                    else game->menu.icone_actuelle[2] = game->menu.icone[2];
                    
                    if(on_mouse_over(&game->menu.box[3], event))
                    {
                        game->menu.icone_actuelle[3] = game->menu.icone_b[3];
                        Mix_PlayChannel(1, game->sound[1].son, 0);
                    }
                    else game->menu.icone_actuelle[3] = game->menu.icone[3];
                    
                break;    
                case SDL_MOUSEBUTTONDOWN:
                    if(on_mouse_click(&game->menu.box[0], event))
                    {
                        Mix_PlayChannel(0, game->sound[0].son, 0);
                        unloading(game, afficher);
                        game->srv = 0;
                        ip_input(game);
                        client(game);
                    }
                    if(on_mouse_click(&game->menu.box[1], event))
                    {
                        Mix_PlayChannel(0, game->sound[0].son, 0);
                        unloading(game, afficher);
                        game->srv = 1;
                        server(game);
                        //SDLNet_FreePacket(game->serveur.p);
                    }
                     if(on_mouse_click(&game->menu.box[2], event))
                    {
                         Mix_PlayChannel(0, game->sound[0].son, 0);
                        options(game); 
                    }
                    if(on_mouse_click(&game->menu.box[3], event))
                    {
                        if(!quit_game(game)) 
                        {
                            Mix_PlayChannel(0, game->sound[0].son, 0);
                            unloading(game, afficher);
                            return 0;
                        }
                        else break;
                    }
                break;                
            }
        }
        if(quit!= 0)afficher(game);
        update(game);
    }
    return 0;
}

void afficher(Game *game)
{
    SDL_BlitSurface(game->menu.background, NULL, game->screen, &game->menu.pbackground);
    
    SDL_BlitSurface(game->menu.icone_actuelle[0], NULL, game->screen, &game->menu.picone[0]);
    SDL_BlitSurface(game->menu.icone_actuelle[1], NULL, game->screen, &game->menu.picone[1]);
    SDL_BlitSurface(game->menu.icone_actuelle[2], NULL, game->screen, &game->menu.picone[2]);
    SDL_BlitSurface(game->menu.icone_actuelle[3], NULL, game->screen, &game->menu.picone[3]);
}

void free_menu(Game *game)
{
    int i;
    SDL_FreeSurface(game->menu.background);
    
    for(i = 0; i < 4; i++)
    {
        SDL_FreeSurface(game->menu.icone[i]);
        SDL_FreeSurface(game->menu.icone_b[i]);
    }
}
#include "../H/includes.h"
#include "../H/ip.h"
#include "../H/init_position.h"
#include "../H/first_screen.h"

void ip_input(Game *game)
{
    int i;
    game->ip.posstr = 0;
    game->ip.background = IMG_Load("Res/Pictures/ip/background.png");
    game->ip.pos[0] = init_position(0, 0, -1, -1);
    
    game->ip.ip_img = IMG_Load("Res/Pictures/ip/ip.png");
    game->ip.pos[1] = init_position(402, 312, -1, -1);
    
    for(i = 0; i < 21; i++)
        game->ip.remote_ip[i] = 0;
    
    game->ip.color.r = 206;
    game->ip.color.g = 133;
    game->ip.color.b = 0;
    
    game->ip.font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 16);
    game->ip.text = TTF_RenderText_Blended(game->ip.font, game->ip.remote_ip, game->ip.color);
    game->ip.pos[2] = init_position(592, 392, -1, -1);
    
    ip_event(game);
    free_ip(game);
}

void ip_event(Game *game)
{
    int loop = 1;
    SDL_Event event;
    
    while(loop)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                            entry_key(game, event);
                    switch(event.key.keysym.sym)
                    {                 
                         case SDLK_BACKSPACE:
                             if(game->ip.posstr > 0)
                                 game->ip.remote_ip[--game->ip.posstr] = ' ';
                            break;
                        case SDLK_RETURN:
                            loop = 0;
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }
        game->ip.text = TTF_RenderText_Blended(game->ip.font, game->ip.remote_ip, game->ip.color);
        afficher_ip(game);
        update(game);
    }
}

void entry_key(Game *game, SDL_Event event)
{
    if(game->ip.posstr > 14) return;
    
    switch(event.key.keysym.sym)
    {
    case SDLK_KP0:
           game->ip.remote_ip[game->ip.posstr++] = '0';
    break;
     case SDLK_KP1:
                            game->ip.remote_ip[game->ip.posstr++] = '1';
                            break;
                        case SDLK_KP2:
                            game->ip.remote_ip[game->ip.posstr++] = '2';
                            break;
                        case SDLK_KP3:
                            game->ip.remote_ip[game->ip.posstr++] = '3';
                            break;
                        case SDLK_KP4:
                            game->ip.remote_ip[game->ip.posstr++] = '4';
                            break;
                        case SDLK_KP5:
                            game->ip.remote_ip[game->ip.posstr++] = '5';
                            break;
                        case SDLK_KP6:
                            game->ip.remote_ip[game->ip.posstr++] = '6';
                            break;
                        case SDLK_KP7:
                            game->ip.remote_ip[game->ip.posstr++] = '7';
                            break;
                        case SDLK_KP8:
                            game->ip.remote_ip[game->ip.posstr++] = '8';
                            break;
                        case SDLK_KP9:
                            game->ip.remote_ip[game->ip.posstr++] = '9';
                            break;
                         case SDLK_KP_PERIOD:
                             if(game->ip.posstr < 21)
                             game->ip.remote_ip[game->ip.posstr++] = '.';
                            break;
    }
}

void afficher_ip(Game *game)
{
    SDL_BlitSurface(game->ip.background, NULL, game->screen, &game->ip.pos[0]);
    SDL_BlitSurface(game->ip.ip_img, NULL, game->screen, &game->ip.pos[1]);
    SDL_BlitSurface(game->ip.text, NULL, game->screen, &game->ip.pos[2]);
}

void free_ip(Game *game)
{
    TTF_CloseFont(game->ip.font);
    SDL_FreeSurface(game->ip.background);
    SDL_FreeSurface(game->ip.text);
    SDL_FreeSurface(game->ip.ip_img);
}
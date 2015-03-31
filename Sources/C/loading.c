#include <SDL/SDL.h>
#include "../H/loading.h"
#include "../Structures/game_struct.h"
#include "../Structures/login_struct.h"

void loading(Game *game, void (*p)(Game *))
{
    int i = 255;
    SDL_Surface *loading = SDL_CreateRGBSurface(SDL_HWSURFACE, game->screen->w, game->screen->h, 32, 0, 0, 0, 0);
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    
    SDL_FillRect(loading, NULL, SDL_MapRGB(game->screen->format, 0, 0, 0));
    
    for(i = 250; i != 0; i-=10)
    {
        SDL_SetAlpha(loading, SDL_SRCALPHA, i);
        (*p)(game); //Pointeurs de fonctions
        SDL_BlitSurface(loading, NULL, game->screen, &pos);
        update(game);
        SDL_Delay(5);
    }
    free_loading(loading);
    SDL_ShowCursor(1);
}

void unloading(Game *game, void (*p)(Game *))
{
    SDL_ShowCursor(0);
    int i;
    SDL_Surface *loading = SDL_CreateRGBSurface(SDL_HWSURFACE, game->screen->w, game->screen->h, 32, 0, 0, 0, 0);
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;
    
    SDL_FillRect(loading, NULL, SDL_MapRGB(game->screen->format, 0, 0, 0));
    
    for(i = 0; i < 255; i+=20)
    {
        SDL_SetAlpha(loading, SDL_SRCALPHA, i);
        (*p)(game); //Pointeurs de fonctions
        SDL_BlitSurface(loading, NULL, game->screen, &pos);
        update(game);
        SDL_Delay(10);
    }
    free_loading(loading);
    SDL_ShowCursor(1);
}

void free_loading(SDL_Surface *surface)
{
    SDL_FreeSurface(surface);
}
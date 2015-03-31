#include <SDL/SDL_video.h>

#include "../H/notify.h"
#include "../H/init_position.h"

void notify(Game *game, char* message, int sec)
{    
    game->notify.bg = SDL_CreateRGBSurface(SDL_HWSURFACE, game->screen->w, game->screen->h, 32, 0, 0, 0, 0);    
    SDL_FillRect(game->notify.bg, NULL, SDL_MapRGB(game->screen->format, 0, 0, 0));
    SDL_SetAlpha(game->notify.bg, SDL_SRCALPHA, 200);
    game->notify.pbg = init_position(0, 0, -1, -1);
    
    game->notify.notify = IMG_Load("Res/Pictures/notify/infos.png");
    game->notify.pnotify = init_position(0, 361, -1, -1);
    game->notify.ptext = init_position(200, 450, -1, -1);
    
    game->notify.color.r = 206;
    game->notify.color.g= 133;
    game->notify.color.b = 0;
    
    game->notify.font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 16);
    game->notify.text = TTF_RenderText_Blended(game->notify.font, message, game->notify.color);
    
    SDL_BlitSurface(game->notify.bg, NULL, game->screen, &game->notify.pbg);
    SDL_BlitSurface(game->notify.notify, NULL, game->screen, &game->notify.pnotify);
    SDL_BlitSurface(game->notify.text, NULL, game->screen, &game->notify.ptext);
    SDL_Flip(game->screen);
    
    SDL_Delay(sec * 1000);
    
    update(game);
    
    free_notify(game);
}

void free_notify(Game *game)
{
    SDL_FreeSurface(game->notify.bg);
    SDL_FreeSurface(game->notify.notify);
    SDL_FreeSurface(game->notify.text);
}
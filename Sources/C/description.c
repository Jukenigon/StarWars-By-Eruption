#include "../H/description.h"
#include "../H/init_position.h"


void init_description(Game *game)
{    
    game->description.desc = IMG_Load("Res/Pictures/notify/description.png");
    game->description.pdesc = init_position(399, 10, -1, -1);    
    game->description.ptext = init_position(420, 83, -1, -1);    
    game->description.color.r = 206;
    game->description.color.g= 133;
    game->description.color.b = 0;    
    game->description.font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 16);
}

void print_description(Game *game, char *note)
{
    game->description.text = TTF_RenderText_Blended(game->description.font, note, game->description.color);
    SDL_BlitSurface(game->description.desc, NULL, game->screen, &game->description.pdesc);
    SDL_BlitSurface(game->description.text , NULL, game->screen, &game->description.ptext);
    update(game);
    SDL_Delay(1000);
}

void free_description(Game *game)
{
    SDL_FreeSurface(game->description.desc);
    SDL_FreeSurface(game->description.text);
}
#ifndef MENU_STRUCT_H
#define MENU_STRUCT_H

#include "../H/includes.h"
#include "../Structures/box_struct.h"

typedef struct Menu
{
    SDL_Surface *background;
    SDL_Surface *icone[4];
    SDL_Surface *icone_b[4];
    SDL_Surface *icone_actuelle[4];
    SDL_Rect pbackground;
    SDL_Rect picone[4];
    Box box[4];
}Menu;

#endif

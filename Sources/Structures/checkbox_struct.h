#ifndef CHECKBOX_STRUCT_H
#define CHECKBOX_STRUCT_H

#include "../H/includes.h"
#include "../Structures/box_struct.h"

typedef struct
{
    SDL_Surface *img_active;
    SDL_Surface *img_active_b;
    SDL_Surface *img_non_active;
    SDL_Surface *img_non_active_b;
    SDL_Surface *tmp;
    SDL_Rect pos;
    Box box;
    int  isActive;
}Checkbox;

#endif

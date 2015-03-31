#ifndef OPTIONS_STRUCT_H
#define	OPTIONS_STRUCT_H

#include "../Structures/box_struct.h"

#include "../Structures/checkbox_struct.h"

typedef struct
{
    SDL_Surface *background;
    SDL_Surface *opt[2];
    SDL_Surface *close[2];
    SDL_Surface *tmp;
    SDL_Rect pbackground;
    SDL_Rect popt;
    SDL_Rect pclose;
    Box close_box;
    Box page_box[2];
    Checkbox checkbox[3];
    int loop;
    int page;
}Options;

#endif


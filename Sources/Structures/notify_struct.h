#ifndef NOTIFY_STRUCT_H
#define	NOTIFY_STRUCT_H

#include "../H/includes.h"

typedef struct
{
    SDL_Surface *bg;
    SDL_Rect pbg;
    SDL_Surface *notify;
    SDL_Rect pnotify;
    SDL_Surface *text;
    SDL_Rect ptext;
    SDL_Color color;
    TTF_Font *font;
}Notify;

#endif	/* NOTIFY_STRUCT_H */


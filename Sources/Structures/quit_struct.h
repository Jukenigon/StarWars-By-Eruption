#ifndef QUIT_STRUCT_H
#define	QUIT_STRUCT_H

#include "../H/includes.h"
#include "../Structures/box_struct.h"

typedef struct QuitWindow
{
    int ok;
    SDL_Surface *quit[2];
    SDL_Rect pquit[2];
    SDL_Surface *yes[2];
    SDL_Surface *no[2];
    SDL_Surface *tmp[2];
    SDL_Rect pos[2];    
    Box choice[2];
}QuitWindow;

#endif	/* QUIT_STRUCT_H */


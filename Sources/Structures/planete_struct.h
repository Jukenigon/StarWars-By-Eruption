#ifndef PLANETE_H
#define	PLANETE_H

#include "../H/includes.h"

typedef struct
{
    SDL_Surface *text;
    SDL_Rect ptext;
    SDL_Color color;
    TTF_Font *font;
}Text;

typedef struct
{
    SDL_Rect pos;
}Embleme;

typedef struct
{
    char *nom;
    char *type;
    int defense;
    int cout;
    int owner;
    Text text;
    Embleme embleme;
}Planete;

#endif	/* PLANETE_H */


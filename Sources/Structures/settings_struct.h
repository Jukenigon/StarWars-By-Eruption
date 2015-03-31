#ifndef SETTINGS_STRUCT_H
#define	SETTINGS_STRUCT_H

#include "../Structures/button_struct.h"
#include "../Structures/planete_struct.h"

typedef struct
{
    SDL_Surface *background;
    SDL_Surface *reglage;
    Button arrow[4];
    int nb_credit;
    int nb_planete;
    char cred[5];
    char nbp[2]; //nombre de planete
     Text text[2];
    SDL_Rect pos;
    SDL_Rect preglage;
    int i;
}Settings;

#endif	/* SETTINGS_STRUCT_H */


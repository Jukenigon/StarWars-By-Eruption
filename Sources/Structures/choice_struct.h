#ifndef CHOICE_STRUCT_H
#define CHOICE_STRUCT_H

#include "box_struct.h"
#include "button_struct.h"

typedef struct Choice
{
    int i;
    int j; //Utilise pour les actions
    int loop;
    int group;
    int nav;
    int section;
    SDL_Surface *background[2];
    SDL_Rect pbackground;
    SDL_Surface *player_credit;
    SDL_Rect pcred;
    TTF_Font *font;
    SDL_Color color;
    Button button[29];
    Button action[10][4];
}Choice;

#endif

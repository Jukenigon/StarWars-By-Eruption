#ifndef LOGIN_STRUCT_H
#define LOGIN_STRUCT_H
#include "../H/includes.h"

typedef struct Login
{
    int loop;
    int i;
    int tempsPrecedent;
    int tempsActuel;
    int croissant;
    SDL_Surface *background;
    SDL_Surface *gotomenu;
    SDL_Rect pgotomenu;
    SDL_Rect pbackground;
    TTF_Font *tnw_font;
    Mix_Music *empire_theme;
}Login;

#endif

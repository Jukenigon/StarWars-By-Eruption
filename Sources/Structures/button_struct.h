/* 
 * File:   button_struct.h
 * Author: jukenigon
 *
 * Created on 22 octobre 2014, 12:37
 */

#ifndef BUTTON_STRUCT_H
#define	BUTTON_STRUCT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "box_struct.h"

typedef struct Button
{
    SDL_Surface *img;
    SDL_Surface *img2;
    SDL_Surface *tmp;
    SDL_Rect pbutton;
    Box box;
    int id;
}Button;
#endif	/* BUTTON_STRUCT_H */


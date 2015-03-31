#ifndef DESCRIPTION_H
#define	DESCRIPTION_H

typedef struct
{
    SDL_Surface *desc;
    SDL_Rect pdesc;
    SDL_Surface *text;
    SDL_Rect ptext;
    TTF_Font *font;
    SDL_Color color ;
}Description;

#endif	/* DESCRIPTION_H */


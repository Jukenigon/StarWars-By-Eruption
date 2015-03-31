#ifndef IP_STRUCT_H
#define	IP_STRUCT_H

typedef struct
{
    SDL_Surface *background;
    SDL_Surface *ip_img;
    SDL_Surface *text;
    SDL_Rect pos[3];
    char remote_ip[21];
    TTF_Font *font;
    int posstr;
    SDL_Color color;
}IP;

#endif	/* IP_STRUCT_H */


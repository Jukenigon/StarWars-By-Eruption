#include <SDL/SDL.h>
#include "../H/init_position.h"

SDL_Rect init_position(int x, int y, int w, int h)
{
    SDL_Rect pos;
    
    pos.x = x;
    pos.y = y;
    
    if(w != -1)
    {
        pos.w = w;
        pos.h = h;
    }
    
    return pos;
}

#include "../H/mouse.h"

int on_mouse_over(Box *box, SDL_Event event)
{
    if(event.motion.x > box->x && event.motion.x < box->x + box->w)
    {
        if(event.motion.y > box->y && event.motion.y < box->y + box->h)
            return 1;
    }

    return 0;
}

int on_mouse_click(Box *box, SDL_Event event)
{
    if(event.button.x > box->x && event.button.x < box->x + box->w)
    {
        if(event.button.y > box->y && event.button.y < box->y + box->h)
            return 1;
    }

    return 0;
}
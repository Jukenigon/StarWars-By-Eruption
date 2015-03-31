#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../Structures/game_struct.h"
#include "../Structures/button_struct.h"
#include "../H/box.h"

#include "../H/init_position.h"
#include "../H/quit.h"
#include "../H/button.h"

int quit_game(Game *game)
{
    int ok = 1;
    
    game->quitwindow.quit[0] = IMG_Load("Res/Pictures/quit/quit.png");
    game->quitwindow.pquit[0] = init_position(0, 0, -1, -1);
    
    game->quitwindow.quit[1] = IMG_Load("Res/Pictures/quit/quit_a.png");
    game->quitwindow.pquit[1] = init_position(402, 312, -1, -1);
    
    game->quitwindow.yes[0] = IMG_Load("Res/Pictures/quit/yes_a.png");
    game->quitwindow.yes[1] = IMG_Load("Res/Pictures/quit/yes_b.png");
    
    game->quitwindow.no[0] = IMG_Load("Res/Pictures/quit/no_a.png");
    game->quitwindow.no[1] = IMG_Load("Res/Pictures/quit/no_b.png");
    
    game->quitwindow.pos[0] = init_position(605, 395, -1, -1);
    game->quitwindow.pos[1] = init_position(700, 395, -1, -1);
    
    game->quitwindow.choice[0] = init_box(605, 395, 69, 42);
    game->quitwindow.choice[1] = init_box(700, 395, 69, 42);
    
    game->quitwindow.tmp[0] = game->quitwindow.yes[0];
    game->quitwindow.tmp[1] = game->quitwindow.no[0];
    
    ok = event_quit(game);
    
    free_quit(game);
    
    return ok;
}

int event_quit(Game *game)
{
    int loop = 1;
    SDL_Event event;
    while(loop)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    if(on_mouse_over(&game->quitwindow.choice[0], event))
                        game->quitwindow.tmp[0] = game->quitwindow.yes[1];
                    else game->quitwindow.tmp[0] = game->quitwindow.yes[0];
                    
                    if(on_mouse_over(&game->quitwindow.choice[1], event))
                        game->quitwindow.tmp[1] = game->quitwindow.no[1];
                    else game->quitwindow.tmp[1] = game->quitwindow.no[0];
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(on_mouse_click(&game->quitwindow.choice[0], event))
                    {
                        return  0;
                    }
                    if(on_mouse_click(&game->quitwindow.choice[1], event))
                    {
                        return 1;
                    }
                break;
                default:
                break;
            }
            print_quit(game);
            update(game);
        }
    }
    return game->quitwindow.ok;
}

void print_quit(Game *game)
{
    SDL_BlitSurface(game->quitwindow.quit[0], NULL, game->screen, &game->quitwindow.pquit[0]);
    SDL_BlitSurface(game->quitwindow.quit[1], NULL, game->screen, &game->quitwindow.pquit[1]);
    SDL_BlitSurface(game->quitwindow.tmp[0], NULL, game->screen, &game->quitwindow.pos[0]);
    SDL_BlitSurface(game->quitwindow.tmp[1], NULL, game->screen, &game->quitwindow.pos[1]);
}

void free_quit(Game *game)
{
    SDL_FreeSurface(game->quitwindow.quit[0]);
    SDL_FreeSurface(game->quitwindow.quit[1]);
    SDL_FreeSurface(game->quitwindow.yes[0]);
    SDL_FreeSurface(game->quitwindow.yes[1]);
    SDL_FreeSurface(game->quitwindow.no[0]);
    SDL_FreeSurface(game->quitwindow.no[1]);
}
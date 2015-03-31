#include "../H/includes.h"
#include "../H/first_screen.h"
#include "../H/menu.h"

void init_first_screen(Game *game)
{
    FILE *fp = NULL;
    
    fp = fopen("Saves/config.sw", "r");
    
    if(fp != NULL)
    {
        fscanf(fp, "Sound:%d\nEffect:%d\nAll:%d", &game->options.checkbox[0].isActive, &game->options.checkbox[1].isActive, &game->options.checkbox[2].isActive);
        fclose(fp);
    }
    
    else notify(game, "Impossible de lire le fichier config.sw");
    
    game->login.loop = 1;
    game->login.background = IMG_Load("Res/Pictures/background.png");
    SDL_Color white = {255, 255, 255};
    game->login.tnw_font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 20);
    game->login.gotomenu = TTF_RenderText_Blended(game->login.tnw_font, "Appuyer sur Entree pour continuer...", white);
    game->login.pgotomenu.x = 410;
    game->login.pgotomenu.y = 700;
    
    game->login.empire_theme = Mix_LoadMUS("Res/Musics/menu_theme.mp3");
    game->sound[0].son  = Mix_LoadWAV("Res/Musics/Effet/clic.wav");
    game->sound[1].son  = Mix_LoadWAV("Res/Musics/Effet/survole.wav");
    
    if(game->options.checkbox[0].isActive)
    Mix_PlayMusic(game->login.empire_theme, -1);
    game->login.pbackground.x = 0;
    game->login.pbackground.y = 0;
    
    loading(game, first_screen);//Ecran de chargement

    event_first_screen(game);
}

int event_first_screen(Game *game)
{
    game->login.i = 0;
    game->login.croissant = 1;
    game->login.tempsActuel = 0;
    game->login.tempsPrecedent = 0;

    while(game->login.loop)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
            {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RETURN:
                    unloading(game, first_screen);
                    menu(game);
                    game->login.loop = 0;
                    break;
                    default:
                    break;
                }
            }
        }
        if(game->login.loop == 0)
            return 0;

        first_screen(game);
        update(game);
    }
    return 1;
}

void first_screen(Game *game)
{
    SDL_BlitSurface(game->login.background, NULL, game->screen, &game->login.pbackground);
    SDL_BlitSurface(game->login.gotomenu, NULL, game->screen, &game->login.pgotomenu);
}

void free_login(Game *game)
{
    SDL_FreeSurface(game->login.background);
    SDL_FreeSurface(game->screen);
    SDL_FreeSurface(game->login.gotomenu);

    TTF_CloseFont(game->login.tnw_font);

    Mix_FreeMusic(game->login.empire_theme);
}

void update(Game *game)
{
    SDL_Flip(game->screen);
}
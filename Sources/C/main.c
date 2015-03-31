#include "../H/includes.h"
#include "../H/init.h"
#include "../Structures/login_struct.h"
#include "../Structures/game_struct.h"
#include "../H/first_screen.h"

int main(int argc, char **argv)
{
    Game game;
    int i;

    init(&game);
    init_first_screen(&game);

    TTF_Quit();
    SDL_Quit();
    Mix_CloseAudio();
    SDLNet_Quit();

    return EXIT_SUCCESS;
}



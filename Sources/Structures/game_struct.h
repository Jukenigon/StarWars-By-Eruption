#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

#include "../H/includes.h"
#include "../Structures/login_struct.h"
#include "../Structures/menu_struct.h"
#include "../Structures/choice_struct.h"
#include "../Structures/quit_struct.h"
#include "../Structures/options_struct.h"
#include "../Structures/ip_struct.h"
#include "../Structures/client_struct.h"
#include "../Structures/serveur_struct.h"
#include "../Structures/settings_struct.h"
#include "../Structures/notify_struct.h"
#include "../Structures/player_struct.h"
#include "../Structures/ressources_struct.h"
#include "../Structures/description_struct.h"
#include "../Structures/planete_struct.h"
#include "../Structures/timer_struct.h"
#include "../Structures/sound_struct.h"

typedef struct Game
{
    SDL_Surface *screen;
    SDL_Surface *sith;
    SDL_Surface *jedi;
    Login login;
    Menu menu;
    Choice choice;
    Options options;
    Client client;
    Settings settings;
    Serveur serveur;
    Notify notify;
    IP ip;
    int connect;
    QuitWindow quitwindow;
    Player player[2];
    Ressources ressources;
    Description description;
    Planete *planete;
    Timer timer;
    Sound sound[2];
    int nb_planete;
    int srv;
}Game;

#endif

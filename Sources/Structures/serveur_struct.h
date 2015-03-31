#include "../H/includes.h"
#include <SDL/SDL_net.h>

#include "../Structures/game_struct.h"
#include "../Structures/player_struct.h"

typedef struct 
{
    UDPsocket sd;
    UDPpacket *p;
    IPaddress cltadd;
    Player player;
}Serveur;


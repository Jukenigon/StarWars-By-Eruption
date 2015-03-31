#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <SDL/SDL_net.h>
#include "../Structures/game_struct.h"

#include "../H/serveur.h"
#include "../H/choice.h"
#include "../H/notify.h"
 
void server(Game *game)
{  
                game->connect = 0;
	/* Open a socket */
	if (!(game->serveur.sd = SDLNet_UDP_Open(1999)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Make space for the packet */
	if (!(game->serveur.p = SDLNet_AllocPacket(512)))
	{
		fprintf(stderr, "SDLNet_AllocPacket: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
        
                 settings(game);
 
	//SDLNet_FreePacket(game->serveur.p);
}

int receive(Game *game, char *message)
{
    if(SDLNet_UDP_Recv(game->serveur.sd, game->serveur.p))
                if(!strcmp((char*)game->serveur.p->data,  message))
                {
                    return 1;
                }
}
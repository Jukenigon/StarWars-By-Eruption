#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../H/client.h"
#include "../H/choice.h"
#include "../H/includes.h"
#include "../H/notify.h"
 
void client(Game *game)
{ 
    int ok = 1;
    game->connect = 0;
	/* Open a socket on random port */
	if (!(game->client.sd = SDLNet_UDP_Open(0)))
	{
                        notify(game, "Impossible d'etablir une connexion...", 3);
                        ok = 0;
	}
 
                 /* Resolve server name  */
	if (SDLNet_ResolveHost(&game->client.srvadd, game->ip.remote_ip, 1999) == -1)
                {
		notify(game, "Impossible d'etablir une connexion...", 3);
                                        ok = 0;
                }
        
                  /* Allocate memory for the packet */
	if (!(game->client.p = SDLNet_AllocPacket(512)))
	{
		notify(game, "Impossible de creer les paquets...", 3);
                                    ok = 0;
	}       
   
                   if(ok != 0) make_a_choice(game);
    
                   else return;
}

int send_message(Game *game, char *message)
{
        sscanf((char*)game->client.p->data, message);
        game->client.p->address.host = game->client.srvadd.host;	/* Set the destination host */
        game->client.p->address.port = game->client.srvadd.port;/* And destination port */
        game->client.p->len = strlen((char *)game->client.p->data);        
        if(SDLNet_UDP_Send(game->client.sd, -1, game->client.p) == 0) 
        {
            return 0;
        } 
        return 1;
}
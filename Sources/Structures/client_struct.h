#ifndef CLIENT_STRUCT_H
#define	CLIENT_STRUCT_H

#include "../H/includes.h"
#include "../Structures/player_struct.h"

typedef struct
{
    UDPsocket sd;
    UDPpacket *p;
    IPaddress srvadd;
    int quit;
    Player player;
}Client;

#endif	/* CLIENT_STRUCT_H */


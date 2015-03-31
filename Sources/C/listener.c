#include "../H/listener.h"
#include "../H/choice.h"
#include "../H/notify.h"
#include "../H/planete.h"

void listener(Game *game)
{      
    if(game->srv)
    {
         if(SDLNet_UDP_Recv(game->serveur.sd, game->serveur.p))
                {
                        if(!strcmp((char*)game->serveur.p->data,  "1x00"))
                        {
                                 notify(game, "Alderaan est conquise par les sith", 1);
                                 game->planete[0].owner = 0;
                        }
                        
                         if(!strcmp((char*)game->serveur.p->data,  "1x01"))
                        {
                                 notify(game, "Bespin est conquise par les sith", 1);
                                 game->planete[1].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x02"))
                        {
                                 notify(game, "Coruscant est conquise par les sith", 1);
                                 game->planete[2].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x02"))
                        {
                                 notify(game, "Dantooine est conquise par les sith", 1);
                                 game->planete[3].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x04"))
                        {
                                 notify(game, "Endo est conquise par les sith", 1);
                                 game->planete[4].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x05"))
                        {
                                 notify(game, "Feluciaest conquise par les sith", 1);
                                 game->planete[5].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x06"))
                        {
                                 notify(game, "Kamino est conquise par les sith", 1);
                                 game->planete[6].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x07"))
                        {
                                 notify(game, "Mygeeto est conquise par les sith", 1);
                                 game->planete[7].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x08"))
                        {
                                 notify(game, "Ossus est conquise par les sith", 1);
                                 game->planete[8].owner = 0;
                        }
                         if(!strcmp((char*)game->serveur.p->data,  "1x09"))
                        {
                                 notify(game, "Ryloth est conquise par les sith", 1);
                                 game->planete[9].owner = 0;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "2x00"))
                        {
                                 notify(game, "Vous avez perdu, l'empire gagne", 1);
                                 game->choice.loop = 0;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x00"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[0].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x01"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[1].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x02"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[2].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x03"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[3].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x04"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[4].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x05"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[5].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x06"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[6].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x07"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[7].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x08"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[8].owner = 0;
                                 game->player[1].planete--;
                        }
                        if(!strcmp((char*)game->serveur.p->data,  "3x09"))
                        {
                                 notify(game, "L'empire s'empare d'une de vos planetes", 1);
                                 game->planete[9].owner = 0;
                                 game->player[1].planete--;
                        }
                }
    }
    
    if(!game->srv)
        {
                if(SDLNet_UDP_Recv(game->client.sd, game->client.p))
                {
                        if(!strcmp((char*)game->client.p->data,  "0x00"))
                        {
                                 notify(game, "Connexion avec le serveur perdue", 1);
                                 game->choice.loop = 0;
                        }
                        
                        if(!strcmp((char*)game->client.p->data,  "1x00"))
                        {
                                 notify(game, "Alderaan est conquise par les jedi", 1);
                                 game->planete[0].owner = 1;
                        }
                        
                         if(!strcmp((char*)game->client.p->data,  "1x01"))
                        {
                                 notify(game, "Bespin est conquise par les jedi", 1);
                                 game->planete[1].owner = 1;
                        }
                        
                         if(!strcmp((char*)game->client.p->data,  "1x02"))
                        {
                                 notify(game, "Coruscant est conquise par les jedi", 1);
                                 game->planete[2].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x02"))
                        {
                                 notify(game, "Dantooine est conquise par les jedi", 1);
                                 game->planete[3].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x04"))
                        {
                                 notify(game, "Endo est conquise par les jedi", 1);
                                 game->planete[4].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x05"))
                        {
                                 notify(game, "Feluciaest conquise par les jedi", 1);
                                 game->planete[5].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x06"))
                        {
                                 notify(game, "Kamino est conquise par les jedi", 1);
                                 game->planete[6].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x07"))
                        {
                                 notify(game, "Mygeeto est conquise par les jedi", 1);
                                 game->planete[7].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x08"))
                        {
                                 notify(game, "Ossus est conquise par les jedi", 1);
                                 game->planete[8].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "1x09"))
                        {
                                 notify(game, "Ryloth est conquise par les jedi", 1);
                                 game->planete[9].owner = 1;
                        }
                         if(!strcmp((char*)game->client.p->data,  "2x00"))
                        {
                                 notify(game, "Vous avez perdu, la republique l'emporte", 1);
                                 game->choice.loop = 0;
                        }
                        if(!strcmp((char*)game->client.p->data,  "3x00"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[0].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x01"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[1].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x02"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[2].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x03"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[3].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x04"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[4].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x05"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[5].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x06"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[6].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x07"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[7].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x08"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[8].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "3x09"))
                        {
                                 notify(game, "La republique s'empare d'une de vos planete", 2);
                                 game->planete[9].owner = 1;
                                 game->player[0].planete--;
                        }
                         if(!strcmp((char*)game->client.p->data,  "4x00"))
                        {
                                 notify(game, "Les credits sont renouvelles", 1);
                                 new_credits(game);
                        }
                }
        }
}

void sender(Game *game, char *message)
{
    if(game->srv)
    {
            game->serveur.p->data = message;                
            game->serveur.p->address.host = game->serveur.cltadd.host;
            game->serveur.p->address.port =game->serveur.cltadd.port;
            game->serveur.p->len = strlen(message) + 1;
            SDLNet_UDP_Send(game->serveur.sd, -1, game->serveur.p);
     }
    
    if(!game->srv)
    {
        game->client.p->data = message;
        game->client.p->address.host = game->client.srvadd.host;
        game->client.p->address.port = game->client.srvadd.port;
        game->client.p->len = strlen(message) + 1;        
        SDLNet_UDP_Send(game->client.sd, -1, game->client.p);
     }
}

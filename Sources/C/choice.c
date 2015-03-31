#include "../H/includes.h"
#include "../H/init_position.h"
#include "../H/choice.h"
#include "../H/box.h"
#include "../H/serveur.h"
#include "../H/mouse.h"
#include "../H/client.h"
#include "../H/init.h"
#include "../H/description.h"
#include "../H/section.h"
#include "../H/actions.h"
#include "../H/listener.h"
#include "../H/planete.h"

void make_a_choice(Game *game)
{
    init_description(game);
    
    if(!game->srv && game->connect == 0)
    {
        if(send_message(game, "con") != 1)
        {
            notify(game, "Impossible d'etablir la connexion", 1);
            return;
        }
        game->connect = 1;
        notify(game, "Connexion au serveur...", 3);
    }
    
    if(game->srv && game->connect == 0)
    {
        char *str = (char*)malloc(sizeof(char) * 512);
        notify(game, "Attente de connexion", 3);
        do{
            if(receive(game, "con"))
                        game->connect = 1;
        }while(!game->connect);
        game->serveur.cltadd.host = game->serveur.p->address.host;
        game->serveur.cltadd.port = game->serveur.p->address.port;
        sprintf(str, "Client connecte a %s", SDLNet_ResolveIP(&game->serveur.cltadd));
        notify(game, str, 3);
        free(str);
    }
    
    if(game->srv)
    {
        char nb[6];
        sprintf(nb, "%d", game->player[1].credits);
        sender(game, nb);
    }
    
    else
    {
        do
        {
        if(SDLNet_UDP_Recv(game->client.sd, game->client.p))
            game->player[0].credits = atoi(game->client.p->data);                
        }while(game->player[0].credits == 0);
    }
    
    if(game->srv)
    {
        char nb[2];
        sprintf(nb, "%d", game->settings.nb_planete);
        sender(game, nb);
    }
    
    else
    {
        do
        {
        if(SDLNet_UDP_Recv(game->client.sd, game->client.p))
            game->nb_planete= atoi(game->client.p->data);                
        }while(game->nb_planete == 0);
    }
    
    game->choice.font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 16);
    game->choice.color.r = 206;
    game->choice.color.g = 133;
    game->choice.color.b = 0;
    char c[10];
    sprintf(c, "%d", game->player[game->srv].credits);
    game->choice.player_credit = TTF_RenderText_Blended(game->choice.font, c, game->choice.color);
    game->choice.pcred = init_position(60, 70, -1, -1);
    
    game->choice.group = 1;
    game->choice.nav = 0;
    game->choice.section = 1;
    
    game->choice.background[0] = IMG_Load("Res/Pictures/template.png");    
    game->choice.background[1] = IMG_Load("Res/Pictures/template_nav.png");
    
    for(game->choice.i = 0; game->choice.i < 29; game->choice.i++)
        game->choice.button[game->choice.i].img2 = NULL;
    
    game->choice.button[0].img = IMG_Load("Res/Pictures/generale_a.png");
    game->choice.button[1].img = IMG_Load("Res/Pictures/batiment_a.png");
    game->choice.button[2].img = IMG_Load("Res/Pictures/defense_a.png");
    game->choice.button[3].img = IMG_Load("Res/Pictures/chantier_a.png");
    game->choice.button[4].img = IMG_Load("Res/Pictures/caserne_a.png");
    game->choice.button[5].img = IMG_Load("Res/Pictures/navigation_a.png");
    game->choice.button[6].img = IMG_Load("Res/Pictures/rapport_a.png");
    game->choice.button[7].img = IMG_Load("Res/Pictures/home_a.png");
    
    game->choice.button[8].img = IMG_Load("Res/Pictures/batiment/01_a.png");
    game->choice.button[9].img = IMG_Load("Res/Pictures/batiment/02_a.png");
    game->choice.button[10].img = IMG_Load("Res/Pictures/batiment/03_a.png");
    game->choice.button[11].img = IMG_Load("Res/Pictures/batiment/04_a.png");
    
    game->choice.button[12].img = IMG_Load("Res/Pictures/defense/01_a.png");
    game->choice.button[13].img = IMG_Load("Res/Pictures/defense/02_a.png");
    game->choice.button[14].img = IMG_Load("Res/Pictures/defense/03_a.png");
    game->choice.button[15].img = IMG_Load("Res/Pictures/defense/04_a.png");
    
    game->choice.button[16].img = IMG_Load("Res/Pictures/chantier/01_a.png");
    game->choice.button[17].img = IMG_Load("Res/Pictures/chantier/02_a.png");
    game->choice.button[18].img = IMG_Load("Res/Pictures/chantier/03_a.png");
    game->choice.button[19].img = IMG_Load("Res/Pictures/chantier/04_a.png");
    game->choice.button[20].img= IMG_Load("Res/Pictures/chantier/05_a.png");
    game->choice.button[21].img = IMG_Load("Res/Pictures/chantier/06_a.png");
    
    game->choice.button[22].img = IMG_Load("Res/Pictures/caserne/01_a.png");
    game->choice.button[23].img = IMG_Load("Res/Pictures/caserne/02_a.png");
    game->choice.button[24].img= IMG_Load("Res/Pictures/caserne/03_a.png");
    game->choice.button[25].img= IMG_Load("Res/Pictures/caserne/04_a.png");
    
    game->choice.button[26].img= IMG_Load("Res/Pictures/navigation/tableau.png");
    
    game->choice.button[27].img= IMG_Load("Res/Pictures/navigation/ligne_a.png");
    game->choice.button[28].img= IMG_Load("Res/Pictures/navigation/ligne_b.png");
    
    game->choice.button[0].img2 = IMG_Load("Res/Pictures/generale_b.png");    
    game->choice.button[1].img2 = IMG_Load("Res/Pictures/batiment_b.png");    
    game->choice.button[2].img2 = IMG_Load("Res/Pictures/defense_b.png");    
    game->choice.button[3].img2 = IMG_Load("Res/Pictures/chantier_b.png");
    game->choice.button[4].img2 = IMG_Load("Res/Pictures/caserne_b.png");
    game->choice.button[5].img2 = IMG_Load("Res/Pictures/navigation_b.png");  
    game->choice.button[6].img2= IMG_Load("Res/Pictures/rapport_b.png");
    game->choice.button[7].img2= IMG_Load("Res/Pictures/home_b.png");
    
    game->choice.button[8].img2 = IMG_Load("Res/Pictures/batiment/01_b.png");
    game->choice.button[9].img2 = IMG_Load("Res/Pictures/batiment/02_b.png");
    game->choice.button[10].img2 = IMG_Load("Res/Pictures/batiment/03_b.png");
    game->choice.button[11].img2 = IMG_Load("Res/Pictures/batiment/04_b.png");
    
    game->choice.button[12].img2 = IMG_Load("Res/Pictures/defense/01_b.png");
    game->choice.button[13].img2 = IMG_Load("Res/Pictures/defense/02_b.png");
    game->choice.button[14].img2 = IMG_Load("Res/Pictures/defense/03_b.png");
    game->choice.button[15].img2 = IMG_Load("Res/Pictures/defense/04_b.png");
   
    game->choice.button[16].img2 = IMG_Load("Res/Pictures/chantier/01_b.png");
    game->choice.button[17].img2= IMG_Load("Res/Pictures/chantier/02_b.png");
    game->choice.button[18].img2 = IMG_Load("Res/Pictures/chantier/03_b.png");
    game->choice.button[19].img2= IMG_Load("Res/Pictures/chantier/04_b.png");
    game->choice.button[20].img2= IMG_Load("Res/Pictures/chantier/05_b.png");
    game->choice.button[21].img2= IMG_Load("Res/Pictures/chantier/06_b.png");
    
    game->choice.button[22].img2 = IMG_Load("Res/Pictures/caserne/01_b.png");
    game->choice.button[23].img2 = IMG_Load("Res/Pictures/caserne/02_b.png");
    game->choice.button[24].img2 = IMG_Load("Res/Pictures/caserne/03_b.png");
    game->choice.button[25].img2= IMG_Load("Res/Pictures/caserne/04_b.png");  
     
    game->choice.button[0].pbutton = init_position(0, 200, 206, 62);
    game->choice.button[0].box = init_box(0, 200, 206, 62);    
    game->choice.button[1].pbutton = init_position(-10, 300, 206, 62);
    game->choice.button[1].box = init_box(-10, 300, 206, 62);    
    game->choice.button[2].pbutton = init_position(-10, 400, 206, 62);
    game->choice.button[2].box = init_box(-10, 400, 206, 62);    
    game->choice.button[3].pbutton = init_position(-10, 500, 206, 62);
    game->choice.button[3].box = init_box(-10, 500, 206, 62);    
    game->choice.button[4].pbutton = init_position(-10, 600, 206, 62);
    game->choice.button[4].box = init_box(-10, 600, 206, 62);    
    game->choice.button[5].pbutton = init_position(1150, 600, 206, 62);
    game->choice.button[5].box = init_box(1150, 600, 206, 62);    
    game->choice.button[6].pbutton = init_position(1150, 670,206, 62);  
    game->choice.button[6].box= init_box(1150, 670, 206, 62);    
    game->choice.button[7].pbutton = init_position(20, 650,206, 62);  
    game->choice.button[7].box = init_box(20, 650, 206, 62);
    
    game->choice.button[8].pbutton = init_position(270, 480, -1, -1);
    game->choice.button[8].box = init_box(270, 480, 209, 166);
    game->choice.button[9].pbutton = init_position(470, 480, -1, -1);
    game->choice.button[9].box = init_box(470, 480, 209, 166);
    game->choice.button[10].pbutton = init_position(670, 480, -1, -1);
    game->choice.button[10].box = init_box(670, 480, 209, 166);
    game->choice.button[11].pbutton = init_position(870, 480, -1, -1);
    game->choice.button[11].box = init_box(870, 480, 209, 166);
    
    game->choice.button[12].pbutton = init_position(270, 480, -1, -1);
    game->choice.button[12].box = init_box(270, 480, 209, 166);
    game->choice.button[13].pbutton = init_position(470, 480, -1, -1);
    game->choice.button[13].box = init_box(470, 480, 209, 166);
    game->choice.button[14].pbutton = init_position(670, 480, -1, -1);
    game->choice.button[14].box = init_box(670, 480, 209, 166);
    game->choice.button[15].pbutton = init_position(870, 480, -1, -1);
    game->choice.button[15].box = init_box(870, 480, 209, 166);
    
    game->choice.button[16].pbutton = init_position(310, 430, -1, -1);
    game->choice.button[16].box= init_box(310, 430, 194, 152);
    game->choice.button[17].pbutton = init_position(600, 430, -1, -1);
    game->choice.button[17].box= init_box(600, 430, 194, 152);
    game->choice.button[18].pbutton = init_position(870, 430, -1, -1);
    game->choice.button[18].box = init_box(870, 430, 194, 152);
    game->choice.button[19].pbutton = init_position(310, 600, -1, -1);
    game->choice.button[19].box= init_box(310, 600, 194, 152);
    game->choice.button[20].pbutton = init_position(600, 600, -1, -1);
    game->choice.button[20].box = init_box(600, 600, 194, 152);
    game->choice.button[21].pbutton = init_position(870, 600, -1, -1);
    game->choice.button[21].box = init_box(870, 600, 194, 152);
    
    game->choice.button[22].pbutton = init_position(270, 480, -1, -1);
    game->choice.button[22].box = init_box(270, 480, 209, 166);
    game->choice.button[23].pbutton = init_position(470, 480, -1, -1);
    game->choice.button[23].box = init_box(470, 480, 209, 166);
    game->choice.button[24].pbutton= init_position(670, 480, -1, -1);
    game->choice.button[24].box = init_box(670, 480, 209, 166);
    game->choice.button[25].pbutton = init_position(870, 480, -1, -1);
    game->choice.button[25].box = init_box(870, 480, 209, 166);
    
    game->choice.button[26].pbutton = init_position(295, 5,  -1, -1);
    
    for(game->choice.i = 0; game->choice.i < 29; game->choice.i++)
        game->choice.button[game->choice.i].tmp= game->choice.button[game->choice.i].img;
    
    init_action(game);
    
    game->choice.pbackground.x = 0;
    game->choice.pbackground.y = 0;
    
    loading(game, afficher_choice);
    event_choice(game);
    //free_choice(game);
    //unloading(game, afficher_choice);
}

void event_choice(Game *game)
{       
   game->choice.loop = 1;
    SDL_Event event;    

    while(game->choice.loop)
    {         
        listener(game);
         
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    for(game->choice.i = 0; game->choice.i < 26; game->choice.i++)
                    {
                        if(on_mouse_over(&game->choice.button[game->choice.i].box, event))
                        {
                            game->choice.button[game->choice.i].tmp = game->choice.button[game->choice.i].img2;
                            Mix_PlayChannel(1, game->sound[1].son, 0);
                        }
                        
                        else game->choice.button[game->choice.i].tmp = game->choice.button[game->choice.i].img;
                    }
                   for(game->choice.i = 0; game->choice.i < 10; game->choice.i++)
                            for(game->choice.j = 0; game->choice.j < 4; game->choice.j++)
                            {
                                if(on_mouse_over(&game->choice.action[game->choice.i][game->choice.j].box, event))
                                    game->choice.action[game->choice.i][game->choice.j].tmp = game->choice.action[game->choice.i][game->choice.j].img2;
                                
                                else game->choice.action[game->choice.i][game->choice.j].tmp = game->choice.action[game->choice.i][game->choice.j].img;
                            } 
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    nav(game, event);
                    switch(game->choice.section)
                    {
                        case 1:
                            event_section_1(game, event);
                            break;
                        case 2:
                            event_section_2(game, event);
                            break;
                        case 3:
                            event_section_3(game, event);
                            break;
                        case 4:
                            event_section_4(game, event);
                            break;
                        case 5:
                            event_section_5(game, event);
                            break;
                        case 6:
                            event_navigation(game, event);
                            break;
                    }

                    break;
                 }
                    
                    }
        
         if(game->srv)
            if(timer(game))
            {
                new_credits(game);
                sender(game, "4x00");
                notify(game, "Les credits sont renouvelles", 1);
            }
                
                afficher_choice(game);
                update(game);
            }
        }

void afficher_choice(Game *game)
{
    if(game->choice.nav)
    {
        afficher_nav(game);
    }
    
    else
    {
        SDL_BlitSurface(game->choice.background[0], NULL, game->screen, &game->choice.pbackground);
         
         switch(game->choice.section)
         {
             case 2:
                     SDL_BlitSurface(game->choice.button[8].tmp, NULL, game->screen, &game->choice.button[8].pbutton);
                     SDL_BlitSurface(game->choice.button[9].tmp, NULL, game->screen, &game->choice.button[9].pbutton);
                     SDL_BlitSurface(game->choice.button[10].tmp, NULL, game->screen, &game->choice.button[10].pbutton);
                     SDL_BlitSurface(game->choice.button[11].tmp, NULL, game->screen, &game->choice.button[11].pbutton);
                 break;    
             case 3:
                     SDL_BlitSurface(game->choice.button[12].tmp, NULL, game->screen, &game->choice.button[12].pbutton);
                     SDL_BlitSurface(game->choice.button[13].tmp, NULL, game->screen, &game->choice.button[13].pbutton);
                     SDL_BlitSurface(game->choice.button[14].tmp, NULL, game->screen, &game->choice.button[14].pbutton);
                     SDL_BlitSurface(game->choice.button[15].tmp, NULL, game->screen, &game->choice.button[15].pbutton);
                     break;
             case 4:
                     SDL_BlitSurface(game->choice.button[16].tmp, NULL, game->screen, &game->choice.button[16].pbutton);
                     SDL_BlitSurface(game->choice.button[17].tmp, NULL, game->screen, &game->choice.button[17].pbutton);
                     SDL_BlitSurface(game->choice.button[18].tmp, NULL, game->screen, &game->choice.button[18].pbutton);
                     SDL_BlitSurface(game->choice.button[19].tmp, NULL, game->screen, &game->choice.button[19].pbutton);
                     SDL_BlitSurface(game->choice.button[20].tmp, NULL, game->screen, &game->choice.button[20].pbutton);
                     SDL_BlitSurface(game->choice.button[21].tmp, NULL, game->screen, &game->choice.button[21].pbutton);
                 break;
             case 5:
                     SDL_BlitSurface(game->choice.button[22].tmp, NULL, game->screen, &game->choice.button[22].pbutton);
                     SDL_BlitSurface(game->choice.button[23].tmp, NULL, game->screen, &game->choice.button[23].pbutton);
                     SDL_BlitSurface(game->choice.button[24].tmp, NULL, game->screen, &game->choice.button[24].pbutton);
                     SDL_BlitSurface(game->choice.button[25].tmp, NULL, game->screen, &game->choice.button[25].pbutton);
                 break;
             default:
                 break;
         }
    }
    
    for(game->choice.i = 0; game->choice.i < 8; game->choice.i++)
                         SDL_BlitSurface(game->choice.button[game->choice.i].tmp, NULL, game->screen, &game->choice.button[game->choice.i].pbutton);
    
    SDL_BlitSurface(game->choice.player_credit, NULL, game->screen, &game->choice.pcred);

}

void free_choice(Game *game)
{       
    for(game->choice.i = 0; game->choice.i < 28; game->choice.i++)
    {
        SDL_FreeSurface(game->choice.button[game->choice.i].img);
        if(game->choice.button[game->choice.i].img2 != NULL)
                SDL_FreeSurface(game->choice.button[game->choice.i].img2);
    }
    
    SDL_FreeSurface(game->choice.background[0]); 
    SDL_FreeSurface(game->choice.background[1]); 
    
    free_description(game);
}

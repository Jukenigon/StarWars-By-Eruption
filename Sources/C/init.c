#include "../H/includes.h"
#include "../H/init.h"
#include "../Structures/game_struct.h"
#include "../H/planete.h"
#include "../H/batiment.h"
#include "../H/defense.h"
#include "../H/chantier.h"
#include "../H/caserne.h"
#include "../H/init_position.h"
#include "../Structures/player_struct.h"

void init(Game *game)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_AllocateChannels(10);
    SDLNet_Init();
    game->screen = SDL_SetVideoMode(1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    game->connect = 0;
    game->timer.tempsPrecedent = 0;
    game->timer.tempsActuel = 0;
    
    init_player(game);
}

void init_player(Game *game)
{
    int i;
    game->player[0].credits = 0;
    
    for(i = 0; i < 2; i++)
    {        
        game->player[i].id = i;
        game->player[i].attaque = 1000000;
        game->player[i].lvl_senat = 0;   
        game->player[i].lvl_mine = 0;
        game->player[i].lvl_chantier = 0;
        game->player[i].lvl_caserne= 0;
        game->player[i].lvl_canon = 0;
        game->player[i].lvl_tourelle = 0;
        game->player[i].lvl_drone = 0;
        game->player[i].lvl_puit = 0;
        game->player[i].lvl_chasseur = 0;
        game->player[i].lvl_chasseur2 = 0;
        game->player[i].lvl_transport = 0;
        game->player[i].lvl_croiseur = 0;
        game->player[i].lvl_destroyer = 0;
        game->player[i].lvl_etoile = 0;
        game->player[i].lvl_droides = 0;
        game->player[i].lvl_clones = 0;
        game->player[i].lvl_commando = 0;
        game->player[i].lvl_jedi = 0;
        game->player[i].planete = 0;
    }    
    init_ressources(game);
}

void init_ressources(Game *game)
{
    game->ressources.senat = init_batiment(1000, "Permet d'acceder a la zone de defense");
    game->ressources.mine = init_batiment(2000, "Rapporte 2000 x level ");
    game->ressources.chantier = init_batiment(5000, "Permet d'acceder au chantier spatial");
    game->ressources.caserne = init_batiment(3000, "Permet d'acceder a la caserne");
    game->ressources.canon = init_defense(500, "Canon");
    game->ressources.tourelle = init_defense(800, "Tourelle");
    game->ressources.drone = init_defense(1000, "Drone");
    game->ressources.puit = init_defense(1200, "Puit");
    game->ressources.chasseur = init_chantier(500, "Chasseur 1");
    game->ressources.chasseur2= init_chantier(550, "Chasseur 2");
    game->ressources.transport = init_chantier(650, "Transport");
    game->ressources.croiseur = init_chantier(1500, "Croiseur");
    game->ressources.destroyer = init_chantier(2000, "Destroyer");
    game->ressources.etoile = init_chantier(50000, "Etoile de la mort");
    game->ressources.droides = init_caserne(100, "Droides");
    game->ressources.clones = init_caserne(500, "Clones");
    game->ressources.commando = init_caserne(1000, "Commando");
    game->ressources.jedi = init_caserne(5000, "Jedi");
    
    init_world(game);
}

void init_world(Game *game)
{
    int i;
    Text t;
    game->nb_planete = 0;
    t.font = TTF_OpenFont("Res/Fonts/starcraft.ttf", 16);
    t.color.r = 255;
    t.color.g = 255;
    t.color.b = 255;
    
    game->planete = NULL;    
    game->planete = (Planete*)malloc(sizeof(Planete) * 10);    
    if(game->planete == NULL)exit(0);
    
    game->sith = IMG_Load("Res/Pictures/navigation/sith.png");
    game->jedi = IMG_Load("Res/Pictures/navigation/jedi.png");
    
    game->planete[0] = init_planete("Alderaan", "Marais", 5, 1000);
    game->planete[0].text.text = TTF_RenderText_Blended(t.font, "Alderan", t.color);
    game->planete[0].text.ptext = init_position(490, 100, -1, -1);
    game->planete[0].owner = 2;
    game->planete[0].embleme.pos = init_position(884, 100, -1,-1);
    
    game->planete[1] = init_planete("Bespin", "Desert", 500, 1100);
    game->planete[1].text.text = TTF_RenderText_Blended(t.font, "Bespin", t.color);
    game->planete[1].text.ptext = init_position(490, 131, -1, -1);
    game->planete[1].owner = 2;
    game->planete[1].embleme.pos = init_position(884, 131, -1,-1);
    
    game->planete[2] = init_planete("Coruscant", "Ville", 500, 1200);
    game->planete[2].text.text = TTF_RenderText_Blended(t.font, "Coruscant", t.color);
    game->planete[2].text.ptext = init_position(490, 162, -1, -1);
    game->planete[2].owner = 2;
    game->planete[2].embleme.pos = init_position(884, 162, -1,-1);
    
    game->planete[3] = init_planete("Dantooine", "Ville", 500, 1300);
    game->planete[3].text.text = TTF_RenderText_Blended(t.font, "Dantooine", t.color);
    game->planete[3].text.ptext = init_position(490, 193, -1, -1);
    game->planete[3].owner = 2;
    game->planete[3].embleme.pos = init_position(884, 193, -1,-1);
    
    game->planete[4] = init_planete("Endo", "Ville", 500, 1400);
    game->planete[4].text.text = TTF_RenderText_Blended(t.font, "Endo", t.color);
    game->planete[4].text.ptext = init_position(490, 224, -1, -1);
    game->planete[4].owner = 2;
    game->planete[4].embleme.pos = init_position(884, 224, -1,-1);
    
    game->planete[5] = init_planete("Felucia", "Ville", 500, 1500);
    game->planete[5].text.text = TTF_RenderText_Blended(t.font, "Felucia", t.color);
    game->planete[5].text.ptext = init_position(490, 255, -1, -1);
    game->planete[5].owner = 2;
    game->planete[5].embleme.pos = init_position(884, 255, -1,-1);
    
    game->planete[6] = init_planete("Kamino", "Ville", 500, 1700);
    game->planete[6].text.text = TTF_RenderText_Blended(t.font, "Kamino", t.color);
    game->planete[6].text.ptext = init_position(490, 286, -1, -1);
    game->planete[6].owner = 2;
    game->planete[6].embleme.pos = init_position(884, 286, -1,-1);
    
    game->planete[7] = init_planete("Mygeeto", "Ville", 500, 1800);
    game->planete[7].text.text = TTF_RenderText_Blended(t.font, "Mygeeto", t.color);
    game->planete[7].text.ptext = init_position(490, 317, -1, -1);
    game->planete[7].owner = 2;
    game->planete[7].embleme.pos = init_position(884, 317, -1,-1);
    
    game->planete[8] = init_planete("Ossus", "Ville", 500, 1900);
    game->planete[8].text.text = TTF_RenderText_Blended(t.font, "Ossus", t.color);
    game->planete[8].text.ptext = init_position(490, 348, -1, -1);    
    game->planete[8].owner = 2;
    game->planete[8].embleme.pos = init_position(884, 348, -1,-1);
    
    game->planete[9] = init_planete("Ryloth", "Ville", 500, 2000);
    game->planete[9].text.text = TTF_RenderText_Blended(t.font, "Ryloth", t.color);
    game->planete[9].text.ptext = init_position(490, 379, -1, -1);
    game->planete[9].owner = 2;
    game->planete[9].embleme.pos = init_position(884, 379, -1,-1);
}

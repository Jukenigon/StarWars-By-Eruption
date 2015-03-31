#include "../H/actions.h"
#include "../H/init_position.h"
#include "../H/box.h"

void init_action(Game *game)
{
    for(game->choice.i = 0; game->choice.i < 10; game->choice.i++)
    {
        game->choice.action[game->choice.i][0].img = IMG_Load("Res/Pictures/navigation/espionnage_a.png");
        game->choice.action[game->choice.i][0].img2 = IMG_Load("Res/Pictures/navigation/espionnage_b.png");
        game->choice.action[game->choice.i][0].pbutton = init_position(930, game->choice.i * 31 + 100, -1, -1);
        game->choice.action[game->choice.i][0].box = init_box(930, game->choice.i * 31 + 100, 27, 27);
        game->choice.action[game->choice.i][0].tmp = game->choice.action[game->choice.i][0].img;
        
        game->choice.action[game->choice.i][1].img = IMG_Load("Res/Pictures/navigation/attaque_a.png");
        game->choice.action[game->choice.i][1].img2 = IMG_Load("Res/Pictures/navigation/attaque_b.png");
        game->choice.action[game->choice.i][1].pbutton = init_position(960, game->choice.i * 31 + 100, -1, -1);
        game->choice.action[game->choice.i][1].box = init_box(960, game->choice.i * 31 + 100, 27, 27);
        game->choice.action[game->choice.i][1].tmp = game->choice.action[game->choice.i][1].img;
        
        game->choice.action[game->choice.i][2].img = IMG_Load("Res/Pictures/navigation/simulation_a.png");
        game->choice.action[game->choice.i][2].img2 = IMG_Load("Res/Pictures/navigation/simulation_b.png");
        game->choice.action[game->choice.i][2].pbutton = init_position(990, game->choice.i * 31 + 100, -1, -1);
        game->choice.action[game->choice.i][2].box = init_box(990, game->choice.i * 31 + 100, 27, 27);
        game->choice.action[game->choice.i][2].tmp = game->choice.action[game->choice.i][2].img;
        
        game->choice.action[game->choice.i][3].img = IMG_Load("Res/Pictures/navigation/achat_a.png");
        game->choice.action[game->choice.i][3].img2 = IMG_Load("Res/Pictures/navigation/achat_b.png");
        game->choice.action[game->choice.i][3].pbutton = init_position(1020, game->choice.i * 31 + 100, -1, -1);
        game->choice.action[game->choice.i][3].box = init_box(1020, game->choice.i * 31 + 100, 27, 27);
        game->choice.action[game->choice.i][3].tmp = game->choice.action[game->choice.i][3].img;
    }
}

#ifndef GAME_HPP
# define GAME_HPP

#include "../vendor/raylib/src/raylib.h"
#include "../vendor/raylib/src/raymath.h"
#include "../myIncludes/props.hpp"
#include "menu.hpp"

#include <string>
#include <iostream>

#define G 800
#define PLAYER_JUMP_SPD 600.0f
#define PLAYER_HOR_SPD 200.0f

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
}   EnvItem;

typedef struct Game {
    const int   screenWidth = 1200;
    const int   screenHeight = 800;
    int         characterSelection = 0;
    int         ct_action = 0;

    void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int);
}   Game;

/**------------------------->> Fonctions <<-------------------------**/

/**----------------------------> Menu <-----------------------------**/
void	ftMenuChooseCharacter(Player * player, Menu *menu);
void	ftChooseCharacter(Menu *menu);
void	ftChooseMenu(Menu *menu);

/**----------------------------> Game <-----------------------------**/

void 	ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems,
		int envItemsLength, float delta, int width, int height);
void 	ftUpdatePlayer(Game *Game, Player *player, EnvItem *envItems, int envItemsLength, float delta);
void	ftImgsGestion(Game *Game, Player *player);

void	ftRoutine(Game *Game, Player *player, Camera2D *camera, Props *blocks);
void	ftKeyGestion(Game *Game, Player *player, float delta);

#endif
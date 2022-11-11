#ifndef GAME_HPP
# define GAME_HPP

# include "../vendor/raylib/src/raylib.h"
# include "../vendor/raylib/src/raymath.h"
# include "./class2D/player.hpp"
# include "./class2D/props.hpp"
# include "./class2D/menu.hpp"
# include "./class2D/envitems.hpp"
# include "../vendor/raylib/src/rlgl.h"

# include <string>
# include <iostream>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define G 800
# define PLAYER_JUMP_SPD 600.0f
# define PLAYER_HOR_SPD 200.0f
#define MAX_INPUT_CHARS 12

#define DARKGRAY1   CLITERAL(Color){ 60, 60, 60, 255 }
#define DARKGRAY2   CLITERAL(Color){ 140, 140, 140, 255 }

// typedef struct EnvItem {
// 	Rectangle rect;
// 	int blocking;
// 	Color color;
// }   EnvItem;

typedef struct Mouse{
	Vector2	pos;
}	Mouse;

typedef struct Game {
	const int   screenWidth = 1500;
	const int   screenHeight = 800;
	float		delta;
	int         characterSelection = 0;
	int         ct_action = 0;
	bool		ctCollision = false;

	Mouse		mouse;
	Font		font1;

	char rotation[MAX_INPUT_CHARS + 1] = "\0";

	void (*cameraUpdaters[])(Game *, Camera2D *, Player *, int, float, int, int);
}   Game;


/**----------------------------> Menu <-----------------------------**/
void	ftMenuChooseCharacter(Player * player, Menu *menu);
void	ftChooseCharacter(Menu *menu);
void	ftChooseMenu(Menu *menu);

//**********************************************************************************//
//										2D											//
//**********************************************************************************//

void	ftMode2D(Game *Game, Menu *menu);
/**----------------------->> Control Panel <<-----------------------**/

void	ftSideDownMenu2D(Game *Game, Player *player, Menu *menu);
void	ftSideUpMenu2D(Game *Game, Player *player, Menu *menu);
void	ftUpMenu2D(Game *Game, Player *player, Menu *menu);
void	ftDrawBoarders(Game *Game);

/**----------------------------> Game <-----------------------------**/

void 	ftUpdateCameraCenter(Game *Game, Camera2D *camera, Player *player,
		int envItemsLength, float delta, int width, int height);
void 	ftUpdatePlayer(Game *Game, Player *player, EnvItems *envItems, int envItemsLength, float delta);
void	ftImgsGestion(Game *Game, Player *player);

void	ftGestionProps(Game *Game, Props *blocks, EnvItems *envItems, float deltaTime, int envItemsLength);
void	ftRoutine(Game *Game, Player *player, Camera2D *camera, Props *blocks, EnvItems *envItems);
void	ftKeyGestion(Game *Game, Player *player, float delta);

/**---------------------------> Utility <----------------------------**/

void	ftUsePlayerGravity(Player *player, EnvItems *envItems, float delta, int envItemsLength);
void	ftUseGravity(SquareProps *prop, EnvItems *envItems, float delta, int envItemsLength);
void	ftGravityGestion(Game *Game, Player *player, Props *blocks);

//**********************************************************************************//
//										3D											//
//**********************************************************************************//

/**------------------------->> Fonctions <<-------------------------**/

void 	ftMode3D(Game *Game);

#endif
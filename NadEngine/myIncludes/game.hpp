#ifndef GAME_HPP
# define GAME_HPP

# include "../vendor/raylib/src/raylib.h"
# include "../vendor/raylib/src/raymath.h"
# include "../myIncludes/class2D/player.hpp"
# include "../myIncludes/class2D/props.hpp"
# include "../myIncludes/class2D/menu.hpp"
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

typedef struct EnvItem {
	Rectangle rect;
	int blocking;
	Color color;
}   EnvItem;

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
	char rotation[MAX_INPUT_CHARS + 1] = "\0";

	void (*cameraUpdaters[])(Game *, Camera2D *, Player *, EnvItem *, int, float, int, int);
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

void	ftSideMenu(Game *Game, Player *player, Menu *menu);

/**----------------------------> Game <-----------------------------**/

void 	ftUpdateCameraCenter(Game *Game, Camera2D *camera, Player *player, EnvItem *envItems,
		int envItemsLength, float delta, int width, int height);
void 	ftUpdatePlayer(Game *Game, Player *player, EnvItem *envItems, int envItemsLength, float delta);
void	ftImgsGestion(Game *Game, Player *player);

void	ftGestionProps(Game *Game, Props *blocks, EnvItem *envItems, float deltaTime, int envItemsLength);
void	ftRoutine(Game *Game, Player *player, Camera2D *camera, Props *blocks);
void	ftKeyGestion(Game *Game, Player *player, float delta);

/**---------------------------> Utility <----------------------------**/

void	ftUsePlayerGravity(Player *player, EnvItem *envItems, float delta, int envItemsLength);
void	ftUseGravity(SquareProps *prop, EnvItem *envItems, float delta, int envItemsLength);
void	ftGravityGestion(Game *Game, Player *player, Props *blocks);

//**********************************************************************************//
//										3D											//
//**********************************************************************************//

/**------------------------->> Fonctions <<-------------------------**/

void ftMode3D(void);

#endif
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
# include <sys/wait.h>
# include <fcntl.h>

# define G 800
# define PLAYER_JUMP_SPD 600.0f
# define PLAYER_HOR_SPD 200.0f
#define MAX_INPUT_CHARS 12

#define DARKGRAY1   CLITERAL(Color){ 60, 60, 60, 255 }
#define DARKGRAY2   CLITERAL(Color){ 140, 140, 140, 255 }
struct MultipleCam2D;

typedef struct Mouse{
	Vector2	pos;
	float	camZoom;
}	Mouse;

typedef struct NeedBy2DCam{
	Camera2D 		camera;
	RenderTexture 	textForCam;
	Rectangle		rectForCam;
}	NeedBy2DCam;

typedef struct MultipleCam2D{
	NeedBy2DCam	camera00;
	NeedBy2DCam camera01;
	NeedBy2DCam camera02;
	NeedBy2DCam camera03;
	NeedBy2DCam camera04;
	NeedBy2DCam camera05;
	NeedBy2DCam camera06;
	NeedBy2DCam camera07;
	NeedBy2DCam camera08;
	NeedBy2DCam camera09;
}	MultipleCam2D;

typedef struct Select
{
	int			type = 0;	// Select witch
	int			nbr = 0;		// Nbr of prop
	Player		*player;	// 1
	SquareProps	*prop;		// 2
	EnvItem	*item;		// 3
}	Select;

class Game {
	public:
	
	const int   screenWidth = 1500;
	const int   screenHeight = 800;
	float		delta;
	int         characterSelection = 0;
	int         ct_action = 0;
	bool		ctCollision = false;
	int			ctPlayStop = 1;
	int			ctImgBuildGame = 1;
	int			ctMode = 1;

	Mouse			mouse;
	Font			font1;
	Vector2			posCam = {650, 300};
	Select			selected2D;

	// MultipleCam2D	allCameras;

	char rotation[MAX_INPUT_CHARS + 1] = "\0";

	void (*cameraUpdaters[])(Game *, Camera2D *, Player *, int, float, int, int);
};


/**----------------------------> Menu <-----------------------------**/
void	ftMenuChooseCharacter(Game *Game, Player * player, Menu *menu);
void	ftChooseCharacter(Menu *menu);
void	ftChooseMenu(Menu *menu);

//**********************************************************************************//
//										2D											//
//**********************************************************************************//

void	ftMode2D(Game *Game, Menu *menu);
/**----------------------->> Control Panel <<-----------------------**/

void	ftSideDownMenu2D(Game *Game, Player *player, Menu *menu);
void	ftSideUpMenu2D(Game *Game, Player *player, Menu *menu);
void	ftUpMenu2D(Game *Game, Camera2D *camera, EnvItems *play, EnvItems *stop);
void	ftSelectItemsTop(Game *game, Camera2D *camera, EnvItems *play, EnvItems *stop);
void	ftDrawBoarders(Game *Game);
void	ftControlItems(Game *game, Player *player, EnvItems *envItems, Props *blocks);

/**-------------------------> Build Game <--------------------------**/

// void	ftRunBuildMode(Game *Game,Stop *buildGame);
void	ftRunBuildMode(Game *game, Player *player, EnvItems *envItems,
			Props *blocks, Camera2D *camera);
void	ftMoveScreen(Game *game, Camera2D *camera);

/**----------------------------> Game <-----------------------------**/

void 	ftUpdateCameraCenter(Game *Game, Camera2D *camera, Player *player,
			int envItemsLength, float delta, int width, int height);
void 	ftUpdatePlayer(Game *Game, Player *player, EnvItems *envItems, int envItemsLength, float delta);
void	ftImgsGestion(Game *Game, Player *player);

void	ftGestionProps(Game *Game, Props *blocks, EnvItems *envItems, float deltaTime, int envItemsLength);
void	ftRoutine(Game *Game, Player *player, Camera2D *camera, Props *blocks, EnvItems *envItems);
void	ftKeyGestion(Game *Game, Player *player, float delta);

void	ftRunGameMode(Game *Game, Menu menu, Player player, EnvItems envItems,
			Props blocks, MultipleCam2D allCameras, EnvItems *play, EnvItems *stop);

/**---------------------------> Utility <----------------------------**/

void	ftUsePlayerGravity(Player *player, EnvItems *envItems, float delta, int envItemsLength);
void	ftUseGravity(SquareProps *prop, EnvItems *envItems, float delta, int envItemsLength);
void	ftGravityGestion(Game *Game, Player *player, Props *blocks);
// void	ftKeyGestionBuildMode(Game *Game);

//**********************************************************************************//
//										3D											//
//**********************************************************************************//

/**------------------------->> Fonctions <<-------------------------**/

void 	ftMode3D(Game *Game);

#endif
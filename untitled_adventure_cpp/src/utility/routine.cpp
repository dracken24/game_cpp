#include "../../myIncludes/class/player.hpp"
#include "../../myIncludes/class/menu.hpp"
#include "../../myIncludes/class/props.hpp"
#include "../../myIncludes/game.hpp"

void ftRoutine(Game *Game, Player *player, Camera2D *camera, Props *blocks)
{
	// static int i;
	static int lastAction;
	static int cameraOption = 0;

	EnvItem envItems[] = {
		{{0, 0, 1000, 400}, 0, LIGHTGRAY},
		{{0, 400, 1000, 200}, 1, GRAY},
		{{300, 150, 400, 10}, 1, GRAY},
		{{250, 250, 100, 10}, 1, GRAY},
		{{650, 250, 100, 10}, 1, GRAY},
		{{-850, 350, 700, 205}, 1, GRAY},
		{{1100, 380, 400, 13}, 1, GRAY},
		{{700, 100, 150, 10}, 1, GRAY},
		{{450, 500, 180, 15}, 1, GRAY}};

	int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

	lastAction = player->ftReturnCt();
	if (Game->ct_action >= 60 || lastAction != player->ftReturnCt())
		Game->ct_action = 0;
	Game->delta = GetFrameTime();

	Game->cameraUpdaters[cameraOption](camera, player, envItems, envItemsLength, Game->delta, Game->screenWidth, Game->screenHeight);

	ftUpdatePlayer(Game, player, envItems, envItemsLength, Game->delta);
	if (lastAction != player->ftReturnCt())
		Game->ct_action = 0;

	camera->zoom += ((float)GetMouseWheelMove() * 0.05f);
	if (camera->zoom > 3.0f)
		camera->zoom = 3.0f;
	else if (camera->zoom < 0.25f)
		camera->zoom = 0.25f;

	/*********************************************** Gravity ***************************************************/

	ftGravityGestion(Game, player, blocks);
	for (int i = 0; i < blocks->ftReturnNbr(); i++)
	{
		ftUseGravity(blocks->ftReturnSquareProp(i), envItems, Game->delta, envItemsLength);
	}

	/********************************************** Collision **************************************************/

	Rectangle	plyCollBox = player->ftReturnCollisionBox();
	Vector2		AdjCollBox = player->ftReturnAjustCollisionBox();
	Vector2		plyPos = player->ftReturnPlayerPosition();

	ftGestionProps(blocks, envItems, Game->delta, envItemsLength);
	player->ftSetCollosionBox((Vector2){plyPos.x + AdjCollBox.x, plyPos.y - AdjCollBox.y},
							  (Vector2){plyCollBox.width, plyCollBox.height}, (Vector2){AdjCollBox.x, AdjCollBox.y});
	// DrawRectangleRec(plyCollBox, BLACK); 	// Player collision box
	if (player->ftReturnFace() == 0) 		// Weapon collision box use
	{
		player->ftNewWeaponCollBoxPos(plyCollBox.x + plyCollBox.width, 'X');
		player->ftNewWeaponCollBoxPos(plyCollBox.y, 'Y');
	}
	else if (player->ftReturnFace() == 1) 	// Weapon collision box use
	{
		player->ftNewWeaponCollBoxPos(plyCollBox.x - plyCollBox.width, 'X');
		player->ftNewWeaponCollBoxPos(plyCollBox.y, 'Y');
	}
	// DrawRectangleRec(player->ftReturnWeaponCollRect(), PURPLE); // Weapon collision box
	ftImgsGestion(Game, player);

	/***********************************************************************************************************/

	if (IsKeyPressed(KEY_R))
	{
		float dist = 0;
		for (int i = 0; i < blocks->ftReturnNbr(); i++)
		{
			blocks->ftSetPosSquareProp((Vector2){200, 200 - dist}, i);
			blocks->ftSetPosSquareProp((Vector2){200 - dist, 200}, i);
			dist += 50;
		}
	}
	if (IsKeyPressed(KEY_P))
	{
		float dist = 0;
		camera->zoom = 1.0f;
		player->ftSetPosition((Vector2){500.0f, 300.0f});
		for (int i = 0; i < blocks->ftReturnNbr(); i++)
		{
			blocks->ftSetPosSquareProp((Vector2){200 - dist, 200}, i);
			blocks->ftSetSpeed(0, i);
			blocks->ftSetSpeedModifier(0, 'X', i);

			dist += 50;
		}
	}
	else if (IsKeyDown(KEY_I))
	{
		DrawText("Controls:", 20, 20, 10, BLACK);
		DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
		DrawText("- Space to jump", 40, 60, 10, DARKGRAY);
		DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY);
		DrawText("- Mouse Button Left to Attack", 40, 100, 10, DARKGRAY);
	}
}

/*******************************************************************************************
	Gestion Des objets (Plateforms wlakable, objets du decor ...)
*******************************************************************************************/
void	ftGestionProps(Props *blocks, EnvItem *envItems, float deltaTime, int envItemsLength)
{
	static int k;
	if (!k || k > 360)
		k = 0;
	for (int i = 0; i < envItemsLength; i++)
		DrawRectangleRec(envItems[i].rect, envItems[i].color);
	
	for (int i = 0; i < blocks->ftReturnNbr(); i++)
	{
		Rectangle	block = blocks->ftReturnRectangleSqPr(i);

		blocks->ftMoveSquareProp((Vector2){blocks->ftReturnSpeedModifier('X', i) + block.width / 2, blocks->ftReturnSpeedModifier('Y', i) + block.height / 2}, i);
		block = blocks->ftReturnRectangleSqPr(i);
		DrawRectanglePro(block, (Vector2){block.width / 2, block.height / 2}, 0, blocks->ftReturnRecColorSqPr(i));
		blocks->ftMoveSquareProp((Vector2){-block.width / 2, -block.height / 2}, i);
		blocks->ftSetSpeedModifier(blocks->ftReturnSpeedModifier('X', i) / 1.01, 'X', i);
	}
	k += 5;
}
/******************************************************************************************/

void	ftUpdatePlayer(Game *Game,Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
	player->ftChangeLastY(player->ftReturnPlayerPositionY());

	ftKeyGestion(Game, player, delta);
	ftUsePlayerGravity(player, envItems, delta, envItemsLength);

	if (player->ftReturnLastY() < player->ftReturnPlayerPositionY() && player->ftReturnAttackCt() == 0)
	{
		player->ftChangeCt(5);
	}
	else if (player->ftReturnLastY() == player->ftReturnPlayerPositionY() && player->ftReturnCt() == 5 && player->ftReturnAttackCt() == 0)
	{
		player->ftChangeCt(0);
	}
}

void ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
{
	camera->offset = (Vector2){width / 2.0f, height / 2.0f};
	camera->target = player->ftReturnPlayerPosition();
}

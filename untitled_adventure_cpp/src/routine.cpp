#include "../myIncludes/player.hpp"
#include "../myIncludes/game.hpp"
#include "../myIncludes/menu.hpp"
#include "../myIncludes/props.hpp"

void ftRoutine(Game *Game, Player *player, Camera2D *camera, Props *blocks)
{
	// static int i;
	static int lastAction;
	static int cameraOption = 0;

	EnvItem envItems[] = {
		{{0, 0, 1000, 400}, 0, LIGHTGRAY},
		{{0, 400, 1000, 200}, 1, GRAY},
		{{300, 200, 400, 10}, 1, GRAY},
		{{250, 300, 100, 10}, 1, GRAY},
		{{650, 300, 100, 10}, 1, GRAY},
		{{-850, 550, 700, 25}, 1, GRAY},
		{{1100, 380, 400, 13}, 1, GRAY},
		{{700, 100, 150, 10}, 1, GRAY},
		{{450, 500, 180, 15}, 1, GRAY}};

	int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

	lastAction = player->ftReturnCt();
	if (Game->ct_action >= 60 || lastAction != player->ftReturnCt())
		Game->ct_action = 0;
	float deltaTime = GetFrameTime();

	Game->cameraUpdaters[cameraOption](camera, player, envItems, envItemsLength, deltaTime, Game->screenWidth, Game->screenHeight);

	ftUpdatePlayer(Game, player, envItems, envItemsLength, deltaTime);
	if (lastAction != player->ftReturnCt())
		Game->ct_action = 0;

	camera->zoom += ((float)GetMouseWheelMove() * 0.05f);
	if (camera->zoom > 3.0f)
		camera->zoom = 3.0f;
	else if (camera->zoom < 0.25f)
		camera->zoom = 0.25f;

	if (IsKeyPressed(KEY_R))
	{
		camera->zoom = 1.0f;
		player->ftSetPosition({500.0f, 300.0f});
		blocks->ftSetPosSquareProp({200, 200}, 0);
	}

	ftGestionProps(blocks, envItems, deltaTime, envItemsLength);
	// DrawRectangle(player->ftReturnPlayerPositionX() + 25, player->ftReturnPlayerPositionY() - 98, player->ftReturnCollBoxSize('W'), player->ftReturnCollBoxSize('H'), BLACK);
	player->ftSetCollosionBox({player->ftReturnPlayerPositionX() + player->ftReturnAjustCollBox('X'), player->ftReturnPlayerPositionY() - player->ftReturnAjustCollBox('Y')},
							  {(float)player->ftReturnCollBoxSize('W'), (float)player->ftReturnCollBoxSize('H')}, {player->ftReturnAjustCollBox('X'), player->ftReturnAjustCollBox('Y')});
	DrawRectangleRec(player->ftReturnCollisionBox(), BLACK);
	ftImgsGestion(Game, player);

	if (IsKeyDown(KEY_I))
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
	for (int i = 0; i < envItemsLength; i++)
		DrawRectangleRec(envItems[i].rect, envItems[i].color);

	DrawRectangleRec(blocks->ftReturnRectangleSqPr(0), blocks->ftReturnRecColorSqPr(0));
	DrawRectangleRec(blocks->ftReturnRectangleSqPr(1), blocks->ftReturnRecColorSqPr(1));
	DrawRectangleRec(blocks->ftReturnRectangleSqPr(2), blocks->ftReturnRecColorSqPr(2));
	ftUseGravity(blocks->ftReturnSquareProp(0), envItems, deltaTime, envItemsLength);
}
/******************************************************************************************/

void	ftImgsGestion(Game *Game, Player *player)
{
	player->ftMovePosition(-player->ftReturnCtMoveX(), 0);

	if (player->ftReturnAttackCt() == 0)
	{
		if (player->ftReturnCt() == 0 && player->ftReturnFace() == 0) // Idle right
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Idle"));
			DrawTextureEx(player->ftReturnGoodImage("Idle Ri", Game->ct_action / player->ftReturnCtIdle()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Idle"));
		}
		else if (player->ftReturnCt() == 0 && player->ftReturnFace() == 1) // Idle left
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Idle"));
			DrawTextureEx(player->ftReturnGoodImage("Idle Lft", Game->ct_action / player->ftReturnCtIdle()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Idle"));
		}
		else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 0) // move right
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
			DrawTextureEx(player->ftReturnGoodImage("Move Ri", Game->ct_action / player->ftReturnCtMove()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
		}
		else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 1) // move lft
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
			DrawTextureEx(player->ftReturnGoodImage("Move Lft", Game->ct_action / player->ftReturnCtMove()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
		}
		else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 0) // Jump right
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
			DrawTextureEx(player->ftReturnGoodImage("Jump Ri", Game->ct_action / player->ftReturnCtJump()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
		}
		else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 1) // Jump left
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
			DrawTextureEx(player->ftReturnGoodImage("Jump Lft", Game->ct_action / player->ftReturnCtJump()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
		}
		else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 0) // Fall right
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
			DrawTextureEx(player->ftReturnGoodImage("Fall Ri", Game->ct_action / player->ftReturnCtFall()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
			if (Game->ct_action >= 19)
				Game->ct_action = 0;
		}
		else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 1) // Fall left
		{
			player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
			DrawTextureEx(player->ftReturnGoodImage("Fall Lft", Game->ct_action / player->ftReturnCtFall()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
			player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
			if (Game->ct_action >= 19)
				Game->ct_action = 0;
		}
	}

	if (player->ftReturnAttackCt() == 1 && player->ftReturnFace() == 1) // Attack left
	{
		player->ftMovePosition(-player->ftReturnMoveAttackLftX(), -player->ftReturnMoveAttackY());
		DrawTextureEx(player->ftReturnGoodImage("Attack 00 Lft", Game->ct_action / player->ftReturnCtAttack()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(player->ftReturnMoveAttackLftX(), player->ftReturnMoveAttackY());
		if (Game->ct_action >= 35)
		{
			player->ftChangeAttackCt(0);
			player->ftChangeCt(0);
			Game->ct_action = 0;
		}
	}
	else if (player->ftReturnAttackCt() == 1 && player->ftReturnFace() == 0) // Attack right
	{
		player->ftMovePosition(-player->ftReturnMoveAttackRiX(), -player->ftReturnMoveAttackY());
		DrawTextureEx(player->ftReturnGoodImage("Attack 00 Ri", Game->ct_action / player->ftReturnCtAttack()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(player->ftReturnMoveAttackRiX(), player->ftReturnMoveAttackY());
		if (Game->ct_action >= 35)
		{
			player->ftChangeAttackCt(0);
			player->ftChangeCt(0);
			Game->ct_action = 0;
		}
	}

	player->ftMovePosition(player->ftReturnCtMoveX(), 0);
	Game->ct_action += 1;
}

void	ftKeyGestion(Game *Game, Player *player, float delta)
{
	if (IsKeyDown(KEY_A)) // Move left
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5 && player->ftReturnAttackCt() == 0)
		{
			player->ftChangeCt(1);
		}
		if (player->ftReturnAttackCt() == 0)
		{
			player->ftChangeFace(1);
		}
		player->ftMoveCollisionBox({-(PLAYER_HOR_SPD * delta), 0});
		player->ftMovePosition(-(PLAYER_HOR_SPD * delta), 0);
	}
	if (IsKeyDown(KEY_D)) // Move right
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5 && player->ftReturnAttackCt() == 0)
		{
			player->ftChangeCt(1);
		}
		if (player->ftReturnAttackCt() == 0)
		{
			player->ftChangeFace(0);
		}
		player->ftMoveCollisionBox({PLAYER_HOR_SPD * delta, 0});
		player->ftMovePosition(PLAYER_HOR_SPD * delta, 0);
	}
	if (IsKeyDown(KEY_SPACE) && player->ftReturnJump()) // Jump
	{
		if (player->ftReturnAttackCt() == 0)
			player->ftChangeCt(4);
		player->ftSetSpeed(-PLAYER_JUMP_SPD);
		player->ftChangeJump(false);
	}
	if ((IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D)) && player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5 && player->ftReturnAttackCt() == 0)
			player->ftChangeCt(0);
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) // Attack 1
	{
		if (player->ftReturnAttackCt() == 0)
		{
			Game->ct_action = 0;
			player->ftChangeAttackCt(1);
		}
	}
}

void	ftUpdatePlayer(Game *Game,Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
	static float		lastY;

	if (!lastY)
		lastY = 0;
	lastY = player->ftReturnPlayerPositionY();

	ftKeyGestion(Game, player, delta);
	ftUsePlayerGravity(player, envItems, delta, envItemsLength);

	if (lastY < player->ftReturnPlayerPositionY() && player->ftReturnAttackCt() == 0)
	{
		player->ftChangeCt(5);
	}
	else if (lastY == player->ftReturnPlayerPositionY() && player->ftReturnCt() == 5 && player->ftReturnAttackCt() == 0)
	{
		player->ftChangeCt(0);
	}
}

void ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
{
	camera->offset = (Vector2){width / 2.0f, height / 2.0f};
	camera->target = player->ftReturnPlayerPosition();
}

#include "../myIncludes/player.hpp"
#include "../myIncludes/game.hpp"
#include "../myIncludes/menu.hpp"

int main(void)
{
	Game 	Game;
	Player	*player;
	Menu	menu;

	InitWindow(Game.screenWidth, Game.screenHeight, "raylib [core] example - 2d camera");

	player = new Player;
	player->ftSetPosition({500, 300});

	Camera2D camera = {0};
	camera.target = player->ftReturnPlayerPosition();
	camera.offset = (Vector2){Game.screenWidth / 2.0f, Game.screenHeight / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Multiple camera
	// void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
	// 	ftUpdateCameraCenter};
	Game.cameraUpdaters[0] = {ftUpdateCameraCenter};

	int cameraUpdatersLength = sizeof(1) / sizeof(Game.cameraUpdaters[0]);

	// SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())
	{
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		BeginMode2D(camera);

		if (menu.ftReturnStart() == 0) // Meni intro
		{
			ftChooseMenu(&menu);
			DrawText("Untitled Adventure Game", 150, 100, 40, BLACK);
			DrawText("Choose Your Character", 150, 200, 20, DARKGRAY);
			DrawText("Start Game", 150, 250, 20, DARKGRAY);
		}
		else if (menu.ftReturnStart() == 1)// Menu choose character
		{
			ftMenuChooseCharacter(player, &menu);
		}
		else // Main loop
		{
			ftRoutine(&Game, player, &camera);
		}

		EndMode2D();
		EndDrawing();
	}
	CloseWindow();
	delete player;
	//--------------------------------------------------------------------------------------
	return 0;
}

void	ftImgsGestion(Player *player, int *i)
{
	player->ftMovePosition(-player->ftReturnCtMoveX(), 0);

	if (player->ftReturnCt() == 0 && player->ftReturnFace() == 0) // Idle right
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Idle"));
		DrawTextureEx(player->ftReturnGoodImage("Idle Ri", *i / player->ftReturnCtIdle()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Idle"));
	}
	else if (player->ftReturnCt() == 0 && player->ftReturnFace() == 1) // Idle left
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Idle"));
		DrawTextureEx(player->ftReturnGoodImage("Idle Lft", *i / player->ftReturnCtIdle()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Idle"));
	}
	else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 0) // move right
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
		DrawTextureEx(player->ftReturnGoodImage("Move Ri", *i / player->ftReturnCtMove()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
	}
	else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 1) // move lft
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
		DrawTextureEx(player->ftReturnGoodImage("Move Lft", *i / player->ftReturnCtMove()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
	}
	else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 0) // Jump right
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
		DrawTextureEx(player->ftReturnGoodImage("Jump Ri", *i / player->ftReturnCtJump()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
	}
	else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 1) // Jump left
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
		DrawTextureEx(player->ftReturnGoodImage("Jump Lft", *i / player->ftReturnCtJump()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
	}
	else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 0) // Fall right
	{
		player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
		DrawTextureEx(player->ftReturnGoodImage("Fall Ri", *i / player->ftReturnCtFall()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
		if (*i >= 19)
			*i = 0;
	}
	else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 1) // Fall left
	{
		// std::cout << "FALL L" << std::endl;
		player->ftMovePosition(0, -player->ftReturnctMoveY("Move"));
		DrawTextureEx(player->ftReturnGoodImage("Fall Lft", *i / player->ftReturnCtFall()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, player->ftReturnctMoveY("Move"));
		if (*i >= 19)
			*i = 0;
	}

	player->ftMovePosition(player->ftReturnCtMoveX(), 0);
	*i += 1;
}

void	ftKeyGestion(Player *player, float delta)
{
	if (IsKeyDown(KEY_A))
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
			player->ftChangeCt(1);
		player->ftChangeFace(1);
		player->ftMovePosition(-(PLAYER_HOR_SPD * delta), 0);
	}
	if (IsKeyDown(KEY_D))
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
			player->ftChangeCt(1);
		player->ftChangeFace(0);
		player->ftMovePosition(PLAYER_HOR_SPD * delta, 0);
	}
	if (IsKeyDown(KEY_SPACE) && player->ftReturnJump())
	{
		player->ftChangeCt(4);
		player->ftSetSpeed(-PLAYER_JUMP_SPD);
		player->ftChangeJump(false);
	}
	if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D))
	{
		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
			player->ftChangeCt(0);
	}
}

void	ftUpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
{
	static float		lastY;

	if (!lastY)
		lastY = 0;
	lastY = player->ftReturnPlayerPositionY();
	ftKeyGestion(player, delta);
	int hitObstacle = 0;
	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = player->ftReturnPlayerPositionPtr();
		if (ei->blocking &&
			ei->rect.x <= p->x &&
			ei->rect.x + ei->rect.width >= p->x &&
			ei->rect.y >= p->y &&
			ei->rect.y <= p->y + player->ftReturnSpeed() * delta)
		{
			hitObstacle = 1;
			player->ftSetSpeed(0);
			p->y = ei->rect.y;
		}
	}
	if (!hitObstacle)
	{
		player->ftMovePosition(0, player->ftReturnSpeed() * delta);
		player->ftChangeSpeed(G * delta);
		player->ftChangeJump(false);
		std::cout << player->ftReturnSpeed() << std::endl;
	}
	else
		player->ftChangeJump(true);

	if (lastY < player->ftReturnPlayerPositionY())
	{
		player->ftChangeCt(5);
	}
	else if (lastY == player->ftReturnPlayerPositionY() && player->ftReturnCt() == 5)
	{
		player->ftChangeCt(0);
	}
}

void ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
{
	camera->offset = (Vector2){width / 2.0f, height / 2.0f};
	camera->target = player->ftReturnPlayerPosition();
}

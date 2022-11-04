#include "../includes/player.hpp"
#include "../includes/game.hpp"
#include "../includes/menu.hpp"

#include <string>
#include <iostream>

void	ftChooseMenu(Menu *menu)
{
	static int	ct;

	if (!ct)
		ct = 1;
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_S))
	{
		ct *= -1;
	}
	if (IsKeyDown(KEY_ENTER))
	{
		if (ct == 1)
			menu->ftChangeStart(1);
		if (ct == -1 && menu->ftReturnPlayer() != 0)
			menu->ftChangeStart(2);
	}

	if (ct == 1)
	{
		DrawText("<---*", 420, 200, 20, DARKGRAY);
	}
	else if (ct == -1)
	{
		DrawText("<---*", 420, 250, 20, DARKGRAY);
	}
}

int	ftChooseCharacter(Menu *menu)
{
	static int ct;

	if (!ct)
		ct = 1;
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_S))
	{
		ct *= -1;
	}
	if (IsKeyDown(KEY_ENTER))
	{
		if (ct == 1)
			menu->ftChangePlayer(1);
		if (ct == -1)
			menu->ftChangePlayer(2);
	}

	if (ct == 1)
	{
		DrawText("<---*", 400, 200, 20, DARKGRAY);
	}
	else if (ct == -1)
	{
		DrawText("<---*", 400, 250, 20, DARKGRAY);
	}
}

int main(void)
{
	const int	screenWidth = 1200;
	const int	screenHeight = 800;
	// int			menuCt = 0;
	int			characterSelection = 0;
	int			i = 0;
	int			k;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

	Player	*player;
	Menu	menu;

	player = new Player;
	player->ftSetPosition({400, 200});

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

	Camera2D camera = {0};
	camera.target = player->ftReturnPlayerPosition();
	camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Multiple camera
	void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
		ftUpdateCameraCenter};

	int cameraOption = 0;
	int cameraUpdatersLength = sizeof(cameraUpdaters) / sizeof(cameraUpdaters[0]);

	// SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())
	{
		k = player->ftReturnCt();
		if (i >= 60 || k != player->ftReturnCt())
			i = 0;
		float deltaTime = GetFrameTime();

		if (menu.ftReturnStart() == 0)
		{
			SetTargetFPS(5);
		}
		else if (menu.ftReturnStart() == 1)
		{
			SetTargetFPS(5);
		}
		else
		{
			SetTargetFPS(60);
			ftUpdatePlayer(player, envItems, envItemsLength, deltaTime);
			if (k != player->ftReturnCt())
				i = 0;

			camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

			if (camera.zoom > 3.0f)
				camera.zoom = 3.0f;
			else if (camera.zoom < 0.25f)
				camera.zoom = 0.25f;
			if (IsKeyPressed(KEY_R))
			{
				camera.zoom = 1.0f;
				player->ftSetPosition({400.0f, 280.0f});
			}
		}

		// if (IsKeyPressed(KEY_C))
		// 	cameraOption = (cameraOption + 1) % cameraUpdatersLength;
		// Update camera
		cameraUpdaters[cameraOption](&camera, player, envItems, envItemsLength, deltaTime, screenWidth, screenHeight);

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		BeginMode2D(camera);
		// std::cout << "E:" << player->ftReturnPlayerPositionX() << std::endl;
		if (menu.ftReturnStart() == 0)
		{
			ftChooseMenu(&menu);
			DrawText("Untitled Adventure Game", 150, 100, 40, BLACK);
			DrawText("Choose Your Character", 150, 200, 20, DARKGRAY);
			DrawText("Start Game", 150, 250, 20, DARKGRAY);
		}
		else if (menu.ftReturnStart() == 1)
		{
			menu.ftChangePlayer(0);
			ftChooseCharacter(&menu);
			DrawText("Choose Your Character", 150, 100, 40, BLACK);
			DrawText("Edward Elric", 150, 200, 20, DARKGRAY);
			DrawText("Ichigo Kurosaki", 150, 250, 20, DARKGRAY);
			if (menu.ftReturnPlayer() == 1)
			{
				player->ftInitPlayerImgs(1);
				player->ftChangeCtIdle(15);
				player->ftChangeCtMove(10);
				player->ftChangeCtJump(30);
				player->ftChangeCtFall(10);
				menu.ftChangeStart(0);
			}
			else if (menu.ftReturnPlayer() == 2)
			{
				player->ftInitPlayerImgs(2);
				player->ftChangeCtIdle(15);
				player->ftChangeCtMove(8);
				player->ftChangeCtJump(20);
				player->ftChangeCtFall(10);
				menu.ftChangeStart(0);
			}
		}
		else
		{
			for (int i = 0; i < envItemsLength; i++)
				DrawRectangleRec(envItems[i].rect, envItems[i].color);

			ftImgsGestion(player, &i);

			DrawText("Controls:", 20, 20, 10, BLACK);
			DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
			DrawText("- Space to jump", 40, 60, 10, DARKGRAY);
			DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY);
			// std::cout << "F:" << player->ftReturnPlayerPositionX() << std::endl;

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
	player->ftMovePosition(-25, 0);

	if (player->ftReturnCt() == 0 && player->ftReturnFace() == 0) // Idle right
	{
		player->ftMovePosition(0, -100);
		DrawTextureEx(player->ftReturnGoodImage("Idle Ri", *i / player->ftReturnCtIdle()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 100);
	}
	else if (player->ftReturnCt() == 0 && player->ftReturnFace() == 1) // Idle left
	{
		player->ftMovePosition(0, -100);
		DrawTextureEx(player->ftReturnGoodImage("Idle Lft", *i / player->ftReturnCtIdle()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 100);
	}
	else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 0) // move right
	{
		player->ftMovePosition(0, -95);
		DrawTextureEx(player->ftReturnGoodImage("Move Ri", *i / player->ftReturnCtMove()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 95);
	}
	else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 1) // move lft
	{
		player->ftMovePosition(0, -95);
		DrawTextureEx(player->ftReturnGoodImage("Move Lft", *i / player->ftReturnCtMove()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 95);
	}
	else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 0) // Jump right
	{
		player->ftMovePosition(0, -95);
		DrawTextureEx(player->ftReturnGoodImage("Jump Ri", *i / player->ftReturnCtJump()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 95);
	}
	else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 1) // Jump left
	{
		player->ftMovePosition(0, -95);
		DrawTextureEx(player->ftReturnGoodImage("Jump Lft", *i / player->ftReturnCtJump()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 95);
	}
	else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 0) // Fall right
	{
		player->ftMovePosition(0, -95);
		DrawTextureEx(player->ftReturnGoodImage("Fall Ri", *i / player->ftReturnCtFall()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 95);
		if (*i >= 19)
			*i = 0;
	}
	else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 1) // Fall left
	{
		// std::cout << "FALL L" << std::endl;
		player->ftMovePosition(0, -95);
		DrawTextureEx(player->ftReturnGoodImage("Fall Lft", *i / player->ftReturnCtFall()), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
		player->ftMovePosition(0, 95);
		if (*i >= 19)
			*i = 0;
	}

	player->ftMovePosition(+25, 0);
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

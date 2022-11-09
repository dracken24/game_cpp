#include "../myIncludes/class/player.hpp"
#include "../myIncludes/class/menu.hpp"
#include "../myIncludes/class/props.hpp"
#include "../myIncludes/game.hpp"

int main(void)
{
	Game 	Game;
	Player	*player;
	Menu	menu;
	Props	blocks(5);

	// for (int i = 0; i < blocks.ftReturnNbr(); i++)
	// {
	// 	blocks.ftAddSquareProps({200, 200}, {24, 24}, BLUE, 0);
	// }
	blocks.ftAddSquareProps((Vector2){200, 200}, (Vector2){24, 24}, BLUE, 0);
	blocks.ftAddSquareProps((Vector2){160, 200}, (Vector2){24, 24}, RED, 1);
	blocks.ftAddSquareProps((Vector2){120, 200}, (Vector2){24, 24}, YELLOW, 2);
	blocks.ftAddSquareProps((Vector2){240, 200}, (Vector2){24, 24}, PINK, 3);
	blocks.ftAddSquareProps((Vector2){80, 200}, (Vector2){24, 24}, PURPLE, 4);

	// blocks.ftAddSquareProps({200, 200}, {24, 24}, BLUE, 0);
	// blocks.ftAddSquareProps({200, 100}, {24, 24}, RED, 1);
	// blocks.ftAddSquareProps({200, 0}, {24, 24}, YELLOW, 2);
	// blocks.ftAddSquareProps({200, -100}, {24, 24}, PINK, 3);
	// blocks.ftAddSquareProps({200, -200}, {24, 24}, PURPLE, 4);

	InitWindow(Game.screenWidth, Game.screenHeight, "raylib [core] example - 2d camera");

	player = new Player;
	player->ftSetPosition((Vector2){500, 300});

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
			DrawText("Untitled Adventure Game", 250, 100, 40, BLACK);
			DrawText("Choose Your Character", 250, 200, 20, DARKGRAY);
			DrawText("Start Game", 250, 250, 20, DARKGRAY);
		}
		else if (menu.ftReturnStart() == 1)// Menu choose character
		{
			ftMenuChooseCharacter(player, &menu);
		}
		else // Main loop
		{
			ftRoutine(&Game, player, &camera, &blocks);
		}

		EndMode2D();
		EndDrawing();
	}
	CloseWindow();
	delete player;
	//--------------------------------------------------------------------------------------
	return 0;
}

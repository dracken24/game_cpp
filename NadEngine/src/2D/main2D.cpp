#include "../../myIncludes/game.hpp"

void	ftMode2D(Game *Game, Menu *menu)
{
	Player	*player;
	Props	blocks;

	// for (int i = 0; i < blocks.ftReturnNbr(); i++)
	// {
	// 	blocks.ftAddSquareProps({200, 200}, {24, 24}, BLUE, 0);
	// }
	blocks.ftInitSquareProps(5);
	blocks.ftAddSquareProps((Vector2){200, 200}, (Vector2){24, 24}, BLUE, 0);
	blocks.ftAddSquareProps((Vector2){160, 200}, (Vector2){24, 24}, RED, 1);
	blocks.ftAddSquareProps((Vector2){120, 200}, (Vector2){24, 24}, YELLOW, 2);
	blocks.ftAddSquareProps((Vector2){240, 200}, (Vector2){24, 24}, PINK, 3);
	blocks.ftAddSquareProps((Vector2){80, 200}, (Vector2){24, 24}, PURPLE, 4);

	// blocks.ftAddSquareProps({200, 200}, {24, 24}, BLUE, 5);
	// blocks.ftAddSquareProps({200, 100}, {24, 24}, RED, 6);
	// blocks.ftAddSquareProps({200, 0}, {24, 24}, YELLOW, 7);
	// blocks.ftAddSquareProps({200, -100}, {24, 24}, PINK, 8);
	// blocks.ftAddSquareProps({200, -200}, {24, 24}, PURPLE, 9);

	player = new Player;
	player->ftSetPosition((Vector2){500, 300});

//--------------------------------------------------------------------------------------//
	// Init Camera and windows
	Camera2D camera = {0};
	camera.target = player->ftReturnPlayerPosition();
	camera.offset = (Vector2){Game->screenWidth / 2.0f, Game->screenHeight / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
	RenderTexture playing = LoadRenderTexture(Game->screenWidth - 300, Game->screenHeight);
	Rectangle splitScreenRectPlay = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};

	Camera2D menuCam = {0};
	menuCam.target = {0, 0};
	menuCam.offset = (Vector2){0.0f, 0.0f};
	menuCam.rotation = 0.0f;
	menuCam.zoom = 1.0f;
	RenderTexture menuText = LoadRenderTexture(300, Game->screenHeight);
	Rectangle splitScreenRectPan = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};

	// Multiple camera
	// void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
	// 	ftUpdateCameraCenter};
	Game->cameraUpdaters[0] = {ftUpdateCameraCenter};

	int cameraUpdatersLength = sizeof(1) / sizeof(Game->cameraUpdaters[0]);

//--------------------------------------------------------------------------------------
	// SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())
	{
		//** Drawning **//

		//Draw Play screen
		BeginTextureMode(playing);
		ClearBackground(LIGHTGRAY);
		BeginMode2D(camera);

		if (menu->ftReturnStart() == 0) // Meni intro
		{
			ftChooseMenu(menu);
			DrawText("Untitled Adventure Game", 100, 100, 40, BLACK);
			DrawText("Choose Your Character", 100, 200, 20, DARKGRAY);
			DrawText("Start Game", 100, 250, 20, DARKGRAY);
		}
		else if (menu->ftReturnStart() == 1)// Menu choose character
		{
			ftMenuChooseCharacter(player, menu);
		}
		else // Main loop
		{
			ftRoutine(Game, player, &camera, &blocks);
		}
		EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw Control Panel
		BeginTextureMode(menuText);
		ClearBackground(DARKGRAY);
		BeginMode2D(menuCam);

		ftSideMenu2D(Game, player, menu);

		EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw both views render textures to the screen side by side
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTextureRec(playing.texture, splitScreenRectPlay, (Vector2){0, 0}, WHITE);
		DrawTextureRec(menuText.texture, splitScreenRectPan, (Vector2){Game->screenWidth - 300.0f, 0}, WHITE);
		EndDrawing();
	}
//--------------------------------------------------------------------------------------//
	// CloseWindow();
	UnloadRenderTexture(playing);
	UnloadRenderTexture(menuText);
	// blocks.ftKillSquareProps();
	delete player;
}
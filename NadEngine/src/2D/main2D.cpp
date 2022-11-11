#include "../../myIncludes/game.hpp"
#include "../../myIncludes/class2D/squareProps.hpp"

void	ftRoutine(Game *Game, Player *player, Camera2D *camera, SquareProps *blocks, SquareProps *platforms);


void	ftMode2D(Game *Game, Menu *menu)
{
	Player	*player;
	Props	blocks;

	blocks.ftInitSquareProps(5);
	blocks.ftAddSquareProps((Vector2){200, 200}, (Vector2){24, 24}, BLUE, 0);
	blocks.ftAddSquareProps((Vector2){160, 200}, (Vector2){24, 24}, RED, 1);
	blocks.ftAddSquareProps((Vector2){120, 200}, (Vector2){24, 24}, YELLOW, 2);
	blocks.ftAddSquareProps((Vector2){240, 200}, (Vector2){24, 24}, PINK, 3);
	blocks.ftAddSquareProps((Vector2){80, 200}, (Vector2){24, 24}, PURPLE, 4);
	// SquareProps	*blocks;
	// std::cout << "Help 1" << std::endl;
	// blocks = new SquareProps[5];
	// blocks[0].ftInitSquareprops((Vector2){200, 200}, (Vector2){24, 24}, BLUE, "Blue", true, 0);
	// blocks[1].ftInitSquareprops((Vector2){160, 200}, (Vector2){24, 24}, RED, "Red", true, 1);
	// std::cout << "Help 2" << std::endl;
	// blocks[2].ftInitSquareprops((Vector2){120, 200}, (Vector2){24, 24}, YELLOW, "Yellow", true, 2);
	// blocks[3].ftInitSquareprops((Vector2){240, 200}, (Vector2){24, 24}, PINK, "Pink", true, 3);
	// blocks[4].ftInitSquareprops((Vector2){80, 200}, (Vector2){24, 24}, PURPLE, "Purple", true, 4);

	// SquareProps	*platforms;

	// platforms = new SquareProps[9];
	// platforms[0].ftInitSquareprops({0, 0}, {1000, 400}, LIGHTGRAY, "Back", 0, 0);
	// platforms[1].ftInitSquareprops({0, 400}, {1000, 200}, GRAY, "Platform 00", 1, 1);
	// platforms[2].ftInitSquareprops({300, 150}, {400, 10}, GRAY, "Platform 01", 1, 2);
	// platforms[3].ftInitSquareprops({250, 250}, {100, 10}, GRAY, "Platform 02", 1, 3);
	// platforms[4].ftInitSquareprops({650, 250}, {100, 10}, GRAY, "Platform 03", 1, 4);
	// platforms[5].ftInitSquareprops({-850, 350}, {700, 205}, GRAY, "Platform 04", 1, 5);
	// platforms[6].ftInitSquareprops({1100, 380}, {400, 13}, GRAY, "Platform 05", 1, 6);
	// platforms[7].ftInitSquareprops({700, 100}, {150, 10}, GRAY, "Platform 06", 1, 7);
	// platforms[8].ftInitSquareprops({450, 500}, {180, 15}, GRAY, "Platform 07", 1, 8);

	player = new Player;
	player->ftSetPosition((Vector2){500, 300});
//--------------------------------------------------------------------------------------//
	// Init Camera and windows
	// Camera player
	Camera2D camera = {0};
	camera.target = player->ftReturnPlayerPosition();
	camera.offset = (Vector2){Game->screenWidth / 2.0f, Game->screenHeight / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
	RenderTexture playing = LoadRenderTexture(Game->screenWidth - 300, Game->screenHeight);
	Rectangle splitScreenRectPlay = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};

	// Camera panel side up
	Camera2D menuCamSideUp = {0};
	menuCamSideUp.target = {0, 0};
	menuCamSideUp.offset = (Vector2){0.0f, 0.0f};
	menuCamSideUp.rotation = 0.0f;
	menuCamSideUp.zoom = 1.0f;
	RenderTexture menuTextSideUp = LoadRenderTexture(300, Game->screenHeight / 3);
	Rectangle splitScreenRectPanSideUp = {0.0f, 0.0f, (float)menuTextSideUp.texture.width, (float)-menuTextSideUp.texture.height};

	// Camera panel side down
	Camera2D menuCamSideDown = {0};
	menuCamSideDown.target = {0, 0};
	menuCamSideDown.offset = (Vector2){0.0f, 0.0f};
	menuCamSideDown.rotation = 0.0f;
	menuCamSideDown.zoom = 1.0f;
	RenderTexture menuTextSideDown = LoadRenderTexture(300, Game->screenHeight / 3 * 2);
	Rectangle splitScreenRectPanSideDown = {0.0f, 0.0f, (float)menuTextSideDown.texture.width, (float)-menuTextSideDown.texture.height};

	// Multiple camera
	// void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
	// 	ftUpdateCameraCenter};
	Game->cameraUpdaters[0] = {ftUpdateCameraCenter};

	int cameraUpdatersLength = sizeof(1) / sizeof(Game->cameraUpdaters[0]);
	std::cout << "Help 3" << std::endl;
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
					DrawTextEx(Game->font1 ,"Untitled Adventure Game", {100, 100}, 40, 2, BLACK);
					// DrawText("Untitled Adventure Game", 100, 100, 40, BLACK);
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

		// Draw Control Panel side up
		BeginTextureMode(menuTextSideUp);
			ClearBackground(DARKGRAY);
			BeginMode2D(menuCamSideUp);

				ftSideUpMenu2D(Game, player, menu);

			EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw Control Panel side down
		BeginTextureMode(menuTextSideDown);
		ClearBackground(DARKGRAY2);
		BeginMode2D(menuCamSideDown);

		ftSideDownMenu2D(Game, player, menu);

		EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw both views render textures to the screen side by side
		BeginDrawing();
			ClearBackground(BLACK);
			DrawTextureRec(playing.texture, splitScreenRectPlay, (Vector2){0, 0}, WHITE);
			DrawTextureRec(menuTextSideUp.texture, splitScreenRectPanSideUp, (Vector2){(float)Game->screenWidth - 300.0f, 0}, WHITE);
			DrawTextureRec(menuTextSideDown.texture, splitScreenRectPanSideDown, (Vector2){(float)Game->screenWidth - 300.0f, (float)Game->screenHeight / 3}, WHITE);
			ftDrawBoarders(Game);
		EndDrawing();
	}
//--------------------------------------------------------------------------------------//
	// CloseWindow();
	UnloadRenderTexture(playing);
	UnloadRenderTexture(menuTextSideUp);
	UnloadRenderTexture(menuTextSideDown);
	// blocks.ftKillSquareProps();
	delete player;
	// delete blocks;
}

void	ftDrawBoarders(Game *Game)
{
	DrawLineEx({(float)Game->screenWidth - 302, 0}, {(float)Game->screenWidth - 302, (float)Game->screenHeight}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 2, 0}, {(float)Game->screenWidth - 2, (float)Game->screenHeight}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, (float)Game->screenHeight / 3}, {(float)Game->screenWidth, (float)Game->screenHeight / 3}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, + 2}, {(float)Game->screenWidth, + 2}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, (float)Game->screenHeight - 2}, {(float)Game->screenWidth, (float)Game->screenHeight - 2}, 5, DARKGRAY1);
}

void	ftSideUpMenu2D(Game *Game, Player *player, Menu *menu)
{
	DrawText("Test up", 10, 10, 20, BLACK);
}

void	ftSideDownMenu2D(Game *Game, Player *player, Menu *menu)
{
	DrawText("Test down", 10, 10, 20, BLACK);
}
#include "../../myIncludes/game.hpp"
#include "../../myIncludes/class2D/squareProps.hpp"
#include "../../myIncludes/class2D/envitems.hpp"
#include "../../myIncludes/class2D/stopGame.hpp"

// void	ftRoutine(Game *Game, Player *player, Camera2D *camera, SquareProps *blocks, SquareProps *platforms);
void	ftRunBuildMode(Game *Game,Stop *buildGame, Camera2D *camera);

void	ftInitBlocks(Props *blocks, EnvItems *envItems)
{
	Texture tmp;

	blocks->ftInitSquareProps(5, "blocks");
	blocks->ftAddProps((Vector2){200, 200}, (Vector2){24, 24}, BLUE, true, 0, "blocks");
	blocks->ftAddProps((Vector2){160, 200}, (Vector2){24, 24}, RED, true, 1, "blocks");
	blocks->ftAddProps((Vector2){120, 200}, (Vector2){24, 24}, YELLOW, true, 2, "blocks");
	blocks->ftAddProps((Vector2){240, 200}, (Vector2){24, 24}, PINK, true, 3, "blocks");
	blocks->ftAddProps((Vector2){80, 200}, (Vector2){24, 24}, PURPLE, true, 4, "blocks");

	envItems->ftNewEnvItem(9);
	envItems->ftInitEnvitem((Vector2){0, 0}, (Vector2){1000, 400}, 0, LIGHTGRAY, tmp, 0);
	envItems->ftInitEnvitem((Vector2){0, 400}, (Vector2){1000, 200}, 1, GRAY, tmp, 1);
	envItems->ftInitEnvitem((Vector2){300, 150}, (Vector2){400, 10}, 1, GRAY, tmp, 2);
	envItems->ftInitEnvitem((Vector2){250, 250}, (Vector2){100, 10}, 1, GRAY, tmp, 3);
	envItems->ftInitEnvitem((Vector2){650, 250}, (Vector2){100, 10}, 1, GRAY, tmp, 4);
	envItems->ftInitEnvitem((Vector2){-850, 350}, (Vector2){700, 205}, 1, GRAY, tmp, 5);
	envItems->ftInitEnvitem((Vector2){1100, 380}, (Vector2){400, 13}, 1, GRAY, tmp, 6);
	envItems->ftInitEnvitem((Vector2){700, 100}, (Vector2){150, 10}, 1, GRAY, tmp, 7);
	envItems->ftInitEnvitem((Vector2){450, 500}, (Vector2){180, 15}, 1, GRAY, tmp, 8);
}

void	ftMode2D(Game *Game, Menu *menu)
{
	static Stop	saveGame;
	Player	*player;
	player = new Player;
	player->ftSetPosition((Vector2){500, 300});

	Props	blocks;
	EnvItems *envItems;
	envItems = new EnvItems;
	ftInitBlocks(&blocks, envItems);

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
	RenderTexture menuTextSideDown = LoadRenderTexture(300, Game->screenHeight / 3 * 2 - 40);
	Rectangle splitScreenRectPanSideDown = {0.0f, 0.0f, (float)menuTextSideDown.texture.width, (float)-menuTextSideDown.texture.height};

	// Camera panel up
	Camera2D menuCamUp = {0};
	menuCamUp.target = {0, 0};
	menuCamUp.offset = (Vector2){0.0f, 0.0f};
	menuCamUp.rotation = 0.0f;
	menuCamUp.zoom = 1.0f;
	RenderTexture menuTextUp = LoadRenderTexture(Game->screenWidth, 40);
	Rectangle splitScreenRectPanUp = {0.0f, 0.0f, (float)menuTextUp.texture.width, (float)-menuTextUp.texture.height};

	// Multiple camera
	// void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
	// 	ftUpdateCameraCenter};
	Game->cameraUpdaters[0] = {ftUpdateCameraCenter};

	int cameraUpdatersLength = sizeof(1) / sizeof(Game->cameraUpdaters[0]);
//--------------------------------------------------------------------------------------
	
	saveGame.ftSaveBlocks(&blocks);
	saveGame.ftSaveEnvItems(envItems);
	saveGame.ftSavePlayer(player);

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
					ftMenuChooseCharacter(Game, player, menu);
				}
				else // Main loop
				{
					if (Game->ctMode == 1)
					{
						// player->ftSetPosition((Vector2){430, 200});
						ftRunBuildMode(Game, &saveGame, &camera);
						camera.target = Game->posCam;
					}
					else if (Game->ctMode == -1)
					{
						pid_t pid;
						int fd[2];

						if (pipe(fd) == -1)
						{
							std::cout << "error, pipe <main2D>" << std::endl;
							exit (-1);
						}
						pid = fork();
						if (pid == -1)
						{
							std::cout << "error, fork <main2D>" << std::endl;
							exit(-1);
						}
						if (pid == 0)
						{
							close(fd[0]);
							dup2(fd[1], STDOUT_FILENO);
							ftRoutine(Game, player, &camera, &blocks, envItems);
						}
						else
						{
							close(fd[1]);
							dup2(fd[0], STDIN_FILENO);
							waitpid(pid, NULL, 0);
						}

						// ftRoutine(Game, player, &camera, &blocks, envItems);
					}
					ftKeyGestionBuildMode(Game);
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

		// Draw Control Panel Up
		BeginTextureMode(menuTextUp);
			ClearBackground(DARKGRAY1);
			BeginMode2D(menuCamUp);

				ftUpMenu2D(Game, player, menu);

			EndMode2D();
		EndTextureMode();

		//--------------------------------------------------------------------------------------//

		// Draw both views render textures to the screen side by side
		BeginDrawing();
			ClearBackground(BLACK);
			DrawTextureRec(playing.texture, splitScreenRectPlay, (Vector2){0, 40}, WHITE);
			DrawTextureRec(menuTextSideUp.texture, splitScreenRectPanSideUp, (Vector2){(float)Game->screenWidth - 300.0f, 40}, WHITE);
			DrawTextureRec(menuTextSideDown.texture, splitScreenRectPanSideDown, (Vector2){(float)Game->screenWidth - 300.0f, (float)Game->screenHeight / 3 + 40}, WHITE);
			DrawTextureRec(menuTextUp.texture, splitScreenRectPanUp, (Vector2){0, 0}, WHITE);
			ftDrawBoarders(Game);
		EndDrawing();
	}
//--------------------------------------------------------------------------------------//
	// CloseWindow();
	UnloadRenderTexture(playing);
	UnloadRenderTexture(menuTextSideUp);
	UnloadRenderTexture(menuTextSideDown);
	UnloadRenderTexture(menuTextUp);
	delete player;
	delete envItems;
}

void	ftKeyGestionBuildMode(Game *Game)
{
	if (IsKeyPressed(KEY_M))
	{
		Game->ctMode *= -1;
	}
}

void	ftDrawBoarders(Game *Game)
{
	DrawLineEx({(float)Game->screenWidth - 302, 40}, {(float)Game->screenWidth - 302, (float)Game->screenHeight}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 2, 0}, {(float)Game->screenWidth - 2, (float)Game->screenHeight}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, (float)Game->screenHeight / 3 + 40}, {(float)Game->screenWidth, (float)Game->screenHeight / 3 + 40}, 5, DARKGRAY1);
	DrawLineEx({0, 40}, {(float)Game->screenWidth, 40}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, (float)Game->screenHeight - 2}, {(float)Game->screenWidth, (float)Game->screenHeight - 2}, 5, DARKGRAY1);
}

void	ftUpMenu2D(Game *Game, Player *player, Menu *menu)
{
	static Texture play;
	static Texture stop;
	if (Game->ctPlayStop == 1)
	{
		play = LoadTexture("./imgs/buttons/play_00.png");
		stop = LoadTexture("./imgs/buttons/stop_00.png");
		Game->ctPlayStop = 0;
	}
	DrawTextureEx(play,{(float)Game->screenWidth - 300, 5}, 0, 1, WHITE);
	DrawTextureEx(stop,{(float)Game->screenWidth - 260, 5}, 0, 1, WHITE);
	DrawText("Panel Up", 10, 10, 20, WHITE);
}

void	ftSideDownMenu2D(Game *Game, Player *player, Menu *menu)
{
	DrawText("Panel Side down", 10, 10, 20, BLACK);
}

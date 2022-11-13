#include "../../myIncludes/game.hpp"
#include "../../myIncludes/class2D/squareProps.hpp"
#include "../../myIncludes/class2D/envitems.hpp"
#include <string.h>

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

void	ftMode2D(Game *game, Menu *menu)
{
	// static Stop	saveGame;
	Player	*player;
	player = new Player;
	player->ftSetPosition((Vector2){500, 300});
	player->ftInitRectanglePlayer(player->ftReturnPlayerPosition(),
		{(float)player->ftReturnCollBoxSize('X'), (float)player->ftReturnCollBoxSize('Y')});

	Props	*blocks;
	EnvItems *envItems;
	blocks = new Props;
	envItems = new EnvItems;
	ftInitBlocks(blocks, envItems);

	//--------------------------------------------------------------------------------------//
	// Init Camera and windows
	MultipleCam2D	*allCameras = new MultipleCam2D;
	// Camera player
	allCameras->camera00.camera = {0};
	allCameras->camera00.camera.target = player->ftReturnPlayerPosition();
	allCameras->camera00.camera.offset = (Vector2){game->screenWidth / 2.0f, game->screenHeight / 2.0f};
	allCameras->camera00.camera.rotation = 0.0f;
	allCameras->camera00.camera.zoom = 1.0f;
	allCameras->camera00.textForCam = LoadRenderTexture(game->screenWidth - 300, game->screenHeight - 40);
	allCameras->camera00.rectForCam = {0.0f, 0.0f, (float)allCameras->camera00.textForCam.texture.width, (float)-allCameras->camera00.textForCam.texture.height};

	// Camera panel side up
	allCameras->camera01.camera = {0};
	allCameras->camera01.camera.target = {0, 0};
	allCameras->camera01.camera.offset = (Vector2){0.0f, 0.0f};
	allCameras->camera01.camera.rotation = 0.0f;
	allCameras->camera01.camera.zoom = 1.0f;
	allCameras->camera01.textForCam = LoadRenderTexture(300, game->screenHeight / 3);
	allCameras->camera01.rectForCam = {0.0f, 0.0f, (float)allCameras->camera01.textForCam.texture.width, (float)-allCameras->camera01.textForCam.texture.height};

	// Camera panel side down
	allCameras->camera02.camera = {0};
	allCameras->camera02.camera.target = {0, 0};
	allCameras->camera02.camera.offset = (Vector2){0.0f, 0.0f};
	allCameras->camera02.camera.rotation = 0.0f;
	allCameras->camera02.camera.zoom = 1.0f;
	allCameras->camera02.textForCam = LoadRenderTexture(300, game->screenHeight / 3 * 2 - 40);
	allCameras->camera02.rectForCam = {0.0f, 0.0f, (float)allCameras->camera02.textForCam.texture.width, (float)-allCameras->camera02.textForCam.texture.height};

	// Camera panel up
	allCameras->camera03.camera = {0};
	allCameras->camera03.camera.target = {0, 0};
	allCameras->camera03.camera.offset = (Vector2){0.0f, 0.0f};
	allCameras->camera03.camera.rotation = 0.0f;
	allCameras->camera03.camera.zoom = 1.0f;
	allCameras->camera03.textForCam = LoadRenderTexture(game->screenWidth, 40);
	allCameras->camera03.rectForCam = {0.0f, 0.0f, (float)allCameras->camera03.textForCam.texture.width, (float)-allCameras->camera03.textForCam.texture.height};

	// Multiple camera
	// void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
	// 	ftUpdateCameraCenter};
	game->cameraUpdaters[0] = {ftUpdateCameraCenter};

//--------------------------------------------------------------------------------------//
	// buttons top
	EnvItems	play;
	EnvItems	stop;

	play.ftInitOneEnvitem({(float)game->screenWidth - 300, 5}, {30, 30}, 0, WHITE,
		LoadTexture("./imgs/buttons/play_00.png"));
	stop.ftInitOneEnvitem({(float)game->screenWidth - 260, 5}, {30, 30}, 0, WHITE,
		LoadTexture("./imgs/buttons/stop_00.png"));


//--------------------------------------------------------------------------------------//
	int cameraUpdatersLength = sizeof(1) / sizeof(game->cameraUpdaters[0]);
	
	// saveGame.ftSaveBlocks(&blocks);
	// saveGame.ftSaveEnvItems(envItems);
	// saveGame.ftSavePlayer(player);

	// Main game loop
	while (!WindowShouldClose())
	{
		//** Drawning **//

		//Draw Play screen
		BeginTextureMode(allCameras->camera00.textForCam);
			ClearBackground(LIGHTGRAY);
			BeginMode2D(allCameras->camera00.camera);

				if (menu->ftReturnStart() == 0) // Menu intro
				{
					ftChooseMenu(menu);
					DrawTextEx(game->font1 ,"Untitled Adventure Game", {100, 100}, 40, 2, BLACK);
					// DrawText("Untitled Adventure Game", 100, 100, 40, BLACK);
					DrawText("Choose Your Character", 100, 200, 20, DARKGRAY);
					DrawText("Start Game", 100, 250, 20, DARKGRAY);
				}
				else if (menu->ftReturnStart() == 1)// Menu choose character
				{
					ftMenuChooseCharacter(game, player, menu);
				}
				else // Main loop
				{
					// std::cout << "Help 00" << std::endl;
					if (game->ctMode == 1)
					{
						allCameras->camera00.camera.target = game->posCam;
						ftRunBuildMode(game, player, envItems, blocks, &allCameras->camera00.camera);
					}
					else if (game->ctMode == -1)
					{
						Menu			tmpMenu;
						Player			tmpPlayer;
						EnvItems		tmpEnvItems;
						Props			tmpBlocks;
						MultipleCam2D	tmpAllCameras;

						tmpMenu = *menu;
						tmpPlayer = *player;
						tmpEnvItems = *envItems;
						tmpBlocks = *blocks;
						tmpAllCameras = *allCameras;

						// pid_t pid;
						// pid = fork();
						// if (pid == -1)
						// {
						// 	std::cout << "error" << std::endl;
						// 	exit(-1);
						// }
						// if (pid == 0)
						// {
						// 	allCameras->camera00.camera.target = player->ftReturnPlayerPosition();
						// 	ftRunGameMode(game, tmpMenu, tmpPlayer, tmpEnvItems, tmpBlocks, tmpAllCameras);
						// }
						// else
						// {
						// 	close(fd[1]);
						// 	dup2(fd[0], STDIN_FILENO);
						// 	waitpid(pid, NULL, 0);
						// }
						
						allCameras->camera00.camera.target = player->ftReturnPlayerPosition();
						ftRunGameMode(game, tmpMenu, tmpPlayer, tmpEnvItems,
							tmpBlocks, tmpAllCameras, &play, &stop);

						game->ctMode = 1;
					}
					// ftKeyGestionBuildMode(game);
				}
			EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw Control Panel side up
		BeginTextureMode(allCameras->camera01.textForCam);
			ClearBackground(DARKGRAY);
			BeginMode2D(allCameras->camera01.camera);

				ftSideUpMenu2D(game, player, menu);

			EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw Control Panel side down
		BeginTextureMode(allCameras->camera02.textForCam);
			ClearBackground(DARKGRAY2);
			BeginMode2D(allCameras->camera02.camera);

				ftSideDownMenu2D(game, player, menu);

			EndMode2D();
		EndTextureMode();

//--------------------------------------------------------------------------------------//

		// Draw Control Panel Up
		BeginTextureMode(allCameras->camera03.textForCam);
			ClearBackground(DARKGRAY1);
			BeginMode2D(allCameras->camera03.camera);

				ftUpMenu2D(game, &allCameras->camera03.camera, &play, &stop);

			EndMode2D();
		EndTextureMode();

		//--------------------------------------------------------------------------------------//

		// Draw both views render textures to the screen side by side
		BeginDrawing();
			ClearBackground(BLACK);
			DrawTextureRec(allCameras->camera00.textForCam.texture, allCameras->camera00.rectForCam,
				(Vector2){0, 40}, WHITE);
			DrawTextureRec(allCameras->camera01.textForCam.texture, allCameras->camera01.rectForCam,
				(Vector2){(float)game->screenWidth - 300.0f, 40}, WHITE);
			DrawTextureRec(allCameras->camera02.textForCam.texture, allCameras->camera02.rectForCam,
				(Vector2){(float)game->screenWidth - 300.0f, (float)game->screenHeight / 3 + 40}, WHITE);
			DrawTextureRec(allCameras->camera03.textForCam.texture, allCameras->camera03.rectForCam,
				(Vector2){0, 0}, WHITE);
			ftDrawBoarders(game);
		EndDrawing();
	}
//--------------------------------------------------------------------------------------//
	// CloseWindow();
	UnloadRenderTexture(allCameras->camera00.textForCam);
	UnloadRenderTexture(allCameras->camera00.textForCam);
	UnloadRenderTexture(allCameras->camera00.textForCam);
	UnloadRenderTexture(allCameras->camera00.textForCam);
	delete player;
	delete blocks;
	delete envItems;
	delete allCameras;
}

// void	ftKeyGestionBuildMode(Game *Game)
// {
// 	if (IsKeyPressed(KEY_M))
// 	{
// 		Game->ctMode *= -1;
// 	}
// }

void	ftDrawBoarders(Game *Game)
{
	DrawLineEx({(float)Game->screenWidth - 302, 40}, {(float)Game->screenWidth - 302, (float)Game->screenHeight}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 2, 0}, {(float)Game->screenWidth - 2, (float)Game->screenHeight}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, (float)Game->screenHeight / 3 + 40}, {(float)Game->screenWidth, (float)Game->screenHeight / 3 + 40}, 5, DARKGRAY1);
	DrawLineEx({0, 40}, {(float)Game->screenWidth, 40}, 5, DARKGRAY1);
	DrawLineEx({(float)Game->screenWidth - 300, (float)Game->screenHeight - 2}, {(float)Game->screenWidth, (float)Game->screenHeight - 2}, 5, DARKGRAY1);
}

void	ftSelectItemsTop(Game *game, Camera2D *camera, EnvItems *play, EnvItems *stop)
{
	Vector2 mousePos = game->mouse.pos;
	Vector2 rayPos = GetScreenToWorld2D(mousePos, *camera);

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		Rectangle item = play->ftReturnOneRectangle();
		if (CheckCollisionPointRec(rayPos, item) && game->ctMode != -1)
		{
			game->ctMode = -1;
		}
		item = stop->ftReturnOneRectangle();
		if (CheckCollisionPointRec(rayPos, item) && game->ctMode != 1)
		{
			game->ctMode = 1;
		}
	}
}

void	ftUpMenu2D(Game *Game, Camera2D *camera, EnvItems *play, EnvItems *stop)
{
	ftSelectItemsTop(Game, camera, play, stop);
	DrawTextureEx(play->ftReturnOneEnviTexture(),{(float)Game->screenWidth - 300, 5}, 0, 1, WHITE);
	DrawTextureEx(stop->ftReturnOneEnviTexture(),{(float)Game->screenWidth - 260, 5}, 0, 1, WHITE);
	DrawText("Panel Up", 10, 10, 20, WHITE);
}

void	ftSideDownMenu2D(Game *Game, Player *player, Menu *menu)
{
	DrawText("Panel Side down", 10, 10, 20, BLACK);
}

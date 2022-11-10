#include "../../myIncludes/game.hpp"

static void ftDrawGrid(int slices, float spacing)
{
	int halfSlices = slices / 2;

	rlBegin(RL_LINES);
	for (int i = -halfSlices; i <= halfSlices; i++)
	{
		if (i == 0)
		{
			rlColor3f(100.5f, 100.5f, 100.5f);
			rlColor3f(100.5f, 100.5f, 100.5f);
			rlColor3f(100.5f, 100.5f, 100.5f);
			rlColor3f(100.5f, 100.5f, 100.5f);
		}
		else
		{
			rlColor3f(50.75f, 50.75f, 50.75f);
			rlColor3f(50.75f, 50.75f, 50.75f);
			rlColor3f(50.75f, 50.75f, 50.75f);
			rlColor3f(50.75f, 50.75f, 50.75f);
		}

		rlVertex3f((float)i * spacing, 0.0f, (float)-halfSlices * spacing);
		rlVertex3f((float)i * spacing, 0.0f, (float)halfSlices * spacing);

		rlVertex3f((float)-halfSlices * spacing, 0.0f, (float)i * spacing);
		rlVertex3f((float)halfSlices * spacing, 0.0f, (float)i * spacing);
	}
	rlEnd();
}

void	ftSideMenu3D(Game *Game)
{
	// ftMouseControl(Game);
	DrawText("Side menu 3D", 10, 10, 14, LIGHTGRAY);
}

void ftMode3D(Game *Game)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1500;
	const int screenHeight = 800;

	// Init Camera and windows
	// Define the camera to look into our 3d world
	Camera3D camera = { 0 };
	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type
	RenderTexture playing = LoadRenderTexture(Game->screenWidth - 300, Game->screenHeight);
	Rectangle splitScreenRectPlay = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};

	Camera2D menuCam = {0};
	menuCam.target = {0, 0};
	menuCam.offset = (Vector2){0.0f, 0.0f};
	menuCam.rotation = 0.0f;
	menuCam.zoom = 1.0f;
	RenderTexture menuText = LoadRenderTexture(300, Game->screenHeight);
	Rectangle splitScreenRectPan = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};



	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

	// //--------------------------------------------------------------------------------------//
	// // Init Camera and windows
	// Camera2D camera = {0};
	// camera.target = player->ftReturnPlayerPosition();
	// camera.offset = (Vector2){Game->screenWidth / 2.0f, Game->screenHeight / 2.0f};
	// camera.rotation = 0.0f;
	// camera.zoom = 1.0f;
	// RenderTexture playing = LoadRenderTexture(Game->screenWidth - 300, Game->screenHeight);
	// Rectangle splitScreenRectPlay = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};

	// Camera2D menuCam = {0};
	// menuCam.target = {0, 0};
	// menuCam.offset = (Vector2){0.0f, 0.0f};
	// menuCam.rotation = 0.0f;
	// menuCam.zoom = 1.0f;
	// RenderTexture menuText = LoadRenderTexture(300, Game->screenHeight);
	// Rectangle splitScreenRectPan = {0.0f, 0.0f, (float)playing.texture.width, (float)-playing.texture.height};

	// // Multiple camera
	// // void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
	// // 	ftUpdateCameraCenter};
	// Game->cameraUpdaters[0] = {ftUpdateCameraCenter};

	// int cameraUpdatersLength = sizeof(1) / sizeof(Game->cameraUpdaters[0]);

	// //--------------------------------------------------------------------------------------
	// // SetTargetFPS(60);

	// // Main game loop
	// while (!WindowShouldClose())
	// {
	// 	//** Drawning **//

	// 	// Draw Play screen
	// 	BeginTextureMode(playing);
	// 	ClearBackground(LIGHTGRAY);
	// 	BeginMode2D(camera);

	// 	if (menu->ftReturnStart() == 0) // Meni intro
	// 	{
	// 		ftChooseMenu(menu);
	// 		DrawText("Untitled Adventure Game", 100, 100, 40, BLACK);
	// 		DrawText("Choose Your Character", 100, 200, 20, DARKGRAY);
	// 		DrawText("Start Game", 100, 250, 20, DARKGRAY);
	// 	}
	// 	else if (menu->ftReturnStart() == 1) // Menu choose character
	// 	{
	// 		ftMenuChooseCharacter(player, menu);
	// 	}
	// 	else // Main loop
	// 	{
	// 		ftRoutine(Game, player, &camera, &blocks);
	// 	}
	// 	EndMode2D();
	// 	EndTextureMode();

	// 	//--------------------------------------------------------------------------------------//

	// 	// Draw Control Panel
	// 	BeginTextureMode(menuText);
	// 	ClearBackground(DARKGRAY);
	// 	BeginMode2D(menuCam);

	// 	ftSideMenu(Game, player, menu);

	// 	EndMode2D();
	// 	EndTextureMode();

	// 	//--------------------------------------------------------------------------------------//

	// 	// Draw both views render textures to the screen side by side
	// 	BeginDrawing();
	// 	ClearBackground(BLACK);
	// 	DrawTextureRec(playing.texture, splitScreenRectPlay, (Vector2){0, 0}, WHITE);
	// 	DrawTextureRec(menuText.texture, splitScreenRectPan, (Vector2){Game->screenWidth - 300.0f, 0}, WHITE);
	// 	EndDrawing();
	// }
	// //--------------------------------------------------------------------------------------//
	// // CloseWindow();
	// UnloadRenderTexture(playing);
	// UnloadRenderTexture(menuText);

	SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())        // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		UpdateCamera(&camera);

		if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
		//----------------------------------------------------------------------------------

			// Draw Workspace
		BeginTextureMode(playing);
			ClearBackground(LIGHTGRAY);

			BeginMode3D(camera);

				DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, PURPLE);
				DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

				ftDrawGrid(10, 1.0f);

			EndMode3D();

			DrawRectangle(10, 10, 320, 133, Fade(DARKGRAY, 0.5f));
			DrawRectangleLines(10, 10, 320, 133, DARKGRAY);

		EndTextureMode();

		//----------------------------------------------------------------------------------
		// Splitscreen Draw Control Panel
		BeginTextureMode(menuText);

			ClearBackground(DARKGRAY);

			BeginMode2D(menuCam);

				ftSideMenu3D(Game);

			EndMode2D();
		EndTextureMode();

		//----------------------------------------------------------------------------------
		BeginDrawing();

			ClearBackground(BLACK);
			DrawTextureRec(playing.texture, splitScreenRectPlay, (Vector2){0, 0}, WHITE);
			DrawTextureRec(menuText.texture, splitScreenRectPan, (Vector2){Game->screenWidth - 300.0f, 0}, WHITE);

			DrawText("Free camera default controls:", 20, 20, 10, BLACK);
			DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, BLACK);
			DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, BLACK);
			DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, BLACK);
			DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, BLACK);
			DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, BLACK);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	// CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}

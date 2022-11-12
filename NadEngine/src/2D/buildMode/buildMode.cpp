#include "../../../myIncludes/game.hpp"

void	ftDrawAll(Game *oldGame, Player *_player, EnvItems *_envItems, Props *_blocks);

// nt main(void)
// {
// 	// Initialization
// 	//--------------------------------------------------------------------------------------
// 	const int screenWidth = 800;
// 	const int screenHeight = 450;

// 	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d picking");

// 	// Define the camera to look into our 3d world
// 	Camera camera = {0};
// 	camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
// 	camera.target = (Vector3){0.0f, 0.0f, 0.0f};	  // Camera looking at point
// 	camera.up = (Vector3){0.0f, 1.0f, 0.0f};		  // Camera up vector (rotation towards target)
// 	camera.fovy = 45.0f;							  // Camera field-of-view Y
// 	camera.projection = CAMERA_PERSPECTIVE;			  // Camera mode type

// 	Vector3 cubePosition = {0.0f, 1.0f, 0.0f};
// 	Vector3 cubeSize = {2.0f, 2.0f, 2.0f};

// 	Ray ray = {0}; // Picking line ray

// 	RayCollision collision = {0};

// 	SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

// 	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
// 	//--------------------------------------------------------------------------------------

// 	// Main game loop
// 	while (!WindowShouldClose()) // Detect window close button or ESC key
// 	{
// 		// Update
// 		//----------------------------------------------------------------------------------
// 		UpdateCamera(&camera);

// 		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
// 		{
// 			if (!collision.hit)
// 			{
// 				ray = GetMouseRay(GetMousePosition(), camera);

// 				// Check collision between ray and box
// 				collision = GetRayCollisionBox(ray,
// 											   (BoundingBox){(Vector3){cubePosition.x - cubeSize.x / 2, cubePosition.y - cubeSize.y / 2, cubePosition.z - cubeSize.z / 2},
// 															 (Vector3){cubePosition.x + cubeSize.x / 2, cubePosition.y + cubeSize.y / 2, cubePosition.z + cubeSize.z / 2}});
// 			}
// 			else
// 				collision.hit = false;
// 		}
// 		//----------------------------------------------------------------------------------

// 		// Draw
// 		//----------------------------------------------------------------------------------
// 		BeginDrawing();

// 		ClearBackground(RAYWHITE);

// 		BeginMode3D(camera);

// 		if (collision.hit)
// 		{
// 			DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RED);
// 			DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, MAROON);

// 			DrawCubeWires(cubePosition, cubeSize.x + 0.2f, cubeSize.y + 0.2f, cubeSize.z + 0.2f, GREEN);
// 		}
// 		else
// 		{
// 			DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, GRAY);
// 			DrawCubeWires(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, DARKGRAY);
// 		}

// 		DrawRay(ray, MAROON);
// 		DrawGrid(10, 1.0f);

// 		EndMode3D();

// 		DrawText("Try selecting the box with mouse!", 240, 10, 20, DARKGRAY);

// 		if (collision.hit)
// 			DrawText("BOX SELECTED", (screenWidth - MeasureText("BOX SELECTED", 30)) / 2, (int)(screenHeight * 0.1f), 30, GREEN);

// 		DrawFPS(10, 10);

// 		EndDrawing();
// 		//----------------------------------------------------------------------------------
// 	}

	// // De-Initialization
	// //--------------------------------------------------------------------------------------
	// CloseWindow(); // Close window and OpenGL context
	// //--------------------------------------------------------------------------------------

	// return 0;

	void ftSelectItems()
	{
		Ray ray = {0}; // Picking line ray

		RayCollision collision = {0};
	}

	void ftMoveScreen(Game * oldGame, Camera2D * camera)
	{
		Vector2 mousePos = GetMousePosition();
		Vector2 lastPos = oldGame->mouse.pos;
		Vector2 forMove = {lastPos.x - mousePos.x, lastPos.y - mousePos.y};

		if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
		{
			oldGame->posCam.x += forMove.x / camera->zoom;
			oldGame->posCam.y += forMove.y / camera->zoom;
		}
		camera->zoom += ((float)GetMouseWheelMove() * 0.05f);
		if (camera->zoom > 3.0f)
			camera->zoom = 3.0f;
		else if (camera->zoom < 0.25f)
			camera->zoom = 0.25f;
	}

	void ftRunBuildMode(Game * oldGame, Stop * buildGame, Camera2D * camera)
	{
		static Player *_player = buildGame->ftReturnPlayer();
		static EnvItems *_envItems = buildGame->ftReturnEnvItems();
		static Props *_blocks = buildGame->ftReturnBlocks();
		static int cameraOption = 0;

		ftMoveScreen(oldGame, camera);
		ftSelectItems();

		oldGame->ctImgBuildGame = 0;
		ftDrawAll(oldGame, _player, _envItems, _blocks); // Draw all imgs
		oldGame->cameraUpdaters[cameraOption](oldGame, camera, _player, _envItems->ftReturnEnviAllNbr(),
											  oldGame->delta, oldGame->screenWidth, oldGame->screenHeight);
	}

	void ftDrawAll(Game * oldGame, Player * _player, EnvItems * _envItems, Props * _blocks)
	{
		for (int i = 0; i < _envItems->ftReturnEnviAllNbr(); i++)
			DrawRectangleRec(_envItems->ftReturnRectangle(i), _envItems->ftReturnEnviColor(i));

		for (int i = 0; i < _blocks->ftReturnNbr(); i++)
		{
			Rectangle block = _blocks->ftReturnRectangleSqPr(i);
			DrawRectanglePro(block, (Vector2){block.width / 2, block.height / 2},
							 0, _blocks->ftReturnRecColorSqPr(i));
		}

		DrawTextureEx(_player->ftReturnGoodImage("Idle Ri", oldGame->ct_action / _player->ftReturnCtIdle()),
					  _player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
	}

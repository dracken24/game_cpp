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

void ftMode3D(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1500;
	const int screenHeight = 800;

	// InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

	// Define the camera to look into our 3d world
	Camera3D camera = { 0 };
	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

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

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

			ClearBackground(LIGHTGRAY);

			BeginMode3D(camera);

				DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, PURPLE);
				DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

				ftDrawGrid(10, 1.0f);

			EndMode3D();

			DrawRectangle( 10, 10, 320, 133, Fade(DARKGRAY, 0.5f));
			DrawRectangleLines( 10, 10, 320, 133, DARKGRAY);

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

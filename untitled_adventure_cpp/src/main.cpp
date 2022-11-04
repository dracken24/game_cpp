// #include "../includes/player.hpp"
// #include "raylib.h"
// #include "raymath.h"
// #include <string>
// #include <iostream>

// #define G 800
// #define PLAYER_JUMP_SPD 600.0f
// #define PLAYER_HOR_SPD 200.0f

// typedef struct EnvItem {
// 	Rectangle rect;
// 	int blocking;
// 	Color color;
// }	EnvItem;

// void 	ftUpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);
// void 	ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems,
// 		int envItemsLength, float delta, int width, int height);
// void	ftImgsGestion(Player *player, int *i);

// int main(void)
// {
// 	const int	screenWidth = 1200;
// 	const int	screenHeight = 800;
// 	int			i = 0;
// 	int			k;

// 	InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

// // Init imgs
// //-----------------------------------------------------------------------------------------------
	
// 	// ftInitImgs(&P1);

// //-----------------------------------------------------------------------------------------------
// 	Player *player;

// 	player = new Player;
// 	player->ftInitPlayerImgs(1);
// 	player->ftSetPosition({400, 200});

// 	EnvItem envItems[] = {
// 		{{0, 0, 1000, 400}, 0, LIGHTGRAY},
// 		{{0, 400, 1000, 200}, 1, GRAY},
// 		{{300, 200, 400, 10}, 1, GRAY}, 
// 		{{250, 300, 100, 10}, 1, GRAY},
// 		{{650, 300, 100, 10}, 1, GRAY},
// 		{{-850, 550, 700, 25}, 1, GRAY},
// 		{{1100, 380, 400, 13}, 1, GRAY},
// 		{{700, 100, 150, 10}, 1, GRAY},
// 		{{450, 500, 180, 15}, 1, GRAY}};

// 	int envItemsLength = sizeof(envItems) / sizeof(envItems[0]);

// 	Camera2D camera = {0};
// 	camera.target = player->ftReturnPlayerPosition();
// 	camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
// 	camera.rotation = 0.0f;
// 	camera.zoom = 1.0f;

// 	// Multiple camera
// 	void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
// 		ftUpdateCameraCenter};

// 	int cameraOption = 0;
// 	int cameraUpdatersLength = sizeof(cameraUpdaters) / sizeof(cameraUpdaters[0]);

// 	SetTargetFPS(60);
// 	//--------------------------------------------------------------------------------------

// 	// Main game loop
// 	while (!WindowShouldClose())
// 	{
// 		std::cout << "A:" << player->ftReturnPlayerPositionX() << std::endl;
// 		k = player->ftReturnCt();
// 		if (i >= 60 || k != player->ftReturnCt())
// 			i = 0;
// 		float deltaTime = GetFrameTime();

// 		ftUpdatePlayer(player, envItems, envItemsLength, deltaTime);
// 		std::cout << "B:" << player->ftReturnPlayerPositionX() << std::endl;

// 		if (k != player->ftReturnCt())
// 			i = 0;

// 		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

// 		if (camera.zoom > 3.0f)
// 			camera.zoom = 3.0f;
// 		else if (camera.zoom < 0.25f)
// 			camera.zoom = 0.25f;
// 		std::cout << "C:" << player->ftReturnPlayerPositionX() << std::endl;
// 		if (IsKeyPressed(KEY_R))
// 		{
// 			camera.zoom = 1.0f;
// 			player->ftSetPosition({400, 280});
// 		}
// 		// std::cout << "P1-ct: " << P1.ct << "  " << "R-or-L: " << P1.face << std::endl;

// 		// if (IsKeyPressed(KEY_C))
// 		// 	cameraOption = (cameraOption + 1) % cameraUpdatersLength;
// 		std::cout << "D:" << player->ftReturnPlayerPositionX() << std::endl;
// 		// Update camera
// 		cameraUpdaters[cameraOption](&camera, player, envItems, envItemsLength, deltaTime, screenWidth, screenHeight);

// 		// Draw
// 		//----------------------------------------------------------------------------------
// 		BeginDrawing();

// 		ClearBackground(LIGHTGRAY);

// 		BeginMode2D(camera);
// 		std::cout << "E:" << player->ftReturnPlayerPositionX() << std::endl;
// 		for (int i = 0; i < envItemsLength; i++)
// 			DrawRectangleRec(envItems[i].rect, envItems[i].color);

// 		ftImgsGestion(player, &i);

// 		// std::cout << P1.ct << std::endl;
// 		EndMode2D();

// 		DrawText("Controls:", 20, 20, 10, BLACK);
// 		DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
// 		DrawText("- Space to jump", 40, 60, 10, DARKGRAY);
// 		DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY);
// 		std::cout << "F:" << player->ftReturnPlayerPositionX() << std::endl;
// 		EndDrawing();
// 	}
// 	CloseWindow();
// 	delete player;
// 	//--------------------------------------------------------------------------------------
// 	return 0;
// }

// void	ftImgsGestion(Player *player, int *i)
// {
// 	player->ftMovePosition(-25, 0);

// 	if (player->ftReturnCt() == 0 && player->ftReturnFace() == 0) // Idle right
// 	{
// 		player->ftMovePosition(0, -100);
// 		DrawTextureEx(player->ftReturnGoodImage("Idle Ri", *i / 15), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 100);
// 	}
// 	else if (player->ftReturnCt() == 0 && player->ftReturnFace() == 1) // Idle left
// 	{
// 		player->ftMovePosition(0, -100);
// 		DrawTextureEx(player->ftReturnGoodImage("Idle Lft", *i / 15), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 100);
// 	}
// 	else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 0) // move right
// 	{
// 		player->ftMovePosition(0, -95);
// 		DrawTextureEx(player->ftReturnGoodImage("Move Ri", *i / 10), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 95);
// 	}
// 	else if (player->ftReturnCt() == 1 && player->ftReturnFace() == 1) // move lft
// 	{
// 		player->ftMovePosition(0, -95);
// 		DrawTextureEx(player->ftReturnGoodImage("Move Lft", *i / 10), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 95);
// 	}
// 	else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 0) // Jump right
// 	{
// 		// std::cout << "JUMP R" << std::endl;
// 		player->ftMovePosition(0, -95);
// 		DrawTextureEx(player->ftReturnGoodImage("Jump Ri", *i / 30), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 95);
// 	}
// 	else if (player->ftReturnCt() == 4 && player->ftReturnFace() == 1) // Jump left
// 	{
// 		// std::cout << "JUMP L" << std::endl;
// 		player->ftMovePosition(0, -95);
// 		DrawTextureEx(player->ftReturnGoodImage("Jump Lft", *i / 30), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 95);
// 	}
// 	else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 0) // Fall right
// 	{
// 		// std::cout << "FALL R" << std::endl;
// 		player->ftMovePosition(0, -95);
// 		DrawTextureEx(player->ftReturnGoodImage("Fall Ri", *i / 10), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 95);
// 		if (*i >= 19)
// 			*i = 0;
// 	}
// 	else if (player->ftReturnCt() == 5 && player->ftReturnFace() == 1) // Fall left
// 	{
// 		// std::cout << "FALL L" << std::endl;
// 		player->ftMovePosition(0, -95);
// 		DrawTextureEx(player->ftReturnGoodImage("Fall Lft", *i / 10), player->ftReturnPlayerPosition(), 0.0f, 2, WHITE);
// 		player->ftMovePosition(0, 95);
// 		if (*i >= 19)
// 			*i = 0;
// 	}
// 	player->ftMovePosition(+25, 0);
// 	*i += 1;
// }

// void	ftKeyGestion(Player *player, float delta)
// {
// 	if (IsKeyDown(KEY_A))
// 	{
// 		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
// 			player->ftChangeCt(1);
// 		player->ftChangeFace(1);
// 		player->ftMovePosition(-(PLAYER_HOR_SPD * delta), 0);
// 	}
// 	if (IsKeyDown(KEY_D))
// 	{
// 		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
// 			player->ftChangeCt(1);
// 		player->ftChangeFace(0);
// 		// std::cout << player->ftReturnPlayerPositionX() << std::endl;
// 		player->ftMovePosition(PLAYER_HOR_SPD * delta, 0);
// 		// std::cout << player->ftReturnPlayerPositionX() << std::endl;
// 	}
// 	if (IsKeyDown(KEY_SPACE) && player->ftReturnJump())
// 	{
// 		player->ftChangeCt(4);
// 		player->ftSetSpeed(-PLAYER_JUMP_SPD);
// 		player->ftChangeJump(false);
// 	}
// 	if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D))
// 	{
// 		if (player->ftReturnCt() != 4 && player->ftReturnCt() != 5)
// 			player->ftChangeCt(0);
// 	}
// }

// void	ftUpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
// {
// 	static float		lastY;

// 	if (!lastY)
// 		lastY = 0;
// 	ftKeyGestion(player, delta);
// 	int hitObstacle = 0;
// 	for (int i = 0; i < envItemsLength; i++)
// 	{
// 		EnvItem *ei = envItems + i;
// 		Vector2 *p = player->ftReturnPlayerPositionPtr();
// 		if (ei->blocking &&
// 			ei->rect.x <= p->x &&
// 			ei->rect.x + ei->rect.width >= p->x &&
// 			ei->rect.y >= p->y &&
// 			ei->rect.y <= p->y + player->ftReturnSpeed() * delta)
// 		{
// 			hitObstacle = 1;
// 			player->ftSetSpeed(0);
// 			player->ftChangePosition(0, ei->rect.y);
// 		}
// 	}

// 	if (!hitObstacle)
// 	{
// 		player->ftChangePosition(0, player->ftReturnSpeed() * delta);
// 		player->ftChangeSpeed(G * delta);
// 		player->ftChangeJump(false);
// 	}
// 	else
// 		player->ftChangeJump(true);

// 	if (lastY == player->ftReturnPlayerPositionY() && player->ftReturnCt() == 4)
// 	{
// 		player->ftChangeCt(5);
// 	}
// 	if (lastY < player->ftReturnPlayerPositionY())
// 	{
// 		// std::cout << "AA" << std::endl;
// 		player->ftChangeCt(5);
// 	}
// 	else if (lastY == player->ftReturnPlayerPositionY() && player->ftReturnCt() == 5)
// 	{
// 		player->ftChangeCt(0);
// 	}
// 	lastY = player->ftReturnPlayerPositionY();
// }

// void ftUpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
// {
// 	camera->offset = (Vector2){width / 2.0f, height / 2.0f};
// 	camera->target = player->ftReturnPlayerPosition();
// }



#include "raylib.h"
#include "raymath.h"
#include <string>
#include <iostream>

#define G 800
#define PLAYER_JUMP_SPD 600.0f
#define PLAYER_HOR_SPD 200.0f

typedef struct Player {
	Vector2 position;
	float speed;
	bool canJump;
}	Player;

typedef struct EnvItem {
	Rectangle rect;
	int blocking;
	Color color;
}	EnvItem;

typedef struct Ply1 {
	Texture2D	p1_idle_ri[4];
	Texture2D	p1_idle_lft[4];
	Texture2D	p1_runLft[6];
	Texture2D	p1_runRi[6];
	Texture2D	p1_jumpl[2];
	Texture2D	p1_jumpr[2];
	Texture2D	p1_falll[2];
	Texture2D	p1_fallr[2];
	int			ct = 0;
	int			face = 0;
}	Ply1;

void 	UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta, Ply1 *P1);
void 	UpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems,
		int envItemsLength, float delta, int width, int height);
void	ftImgsGestion(Player *player, Ply1 *P1, int *i);
void	ftInitImgs(Ply1 *P1);

int main(void)
{
	const int	screenWidth = 1200;
	const int	screenHeight = 800;
	int			i = 0;
	int			k;
	Ply1		P1;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

// Init imgs
//-----------------------------------------------------------------------------------------------
	
	ftInitImgs(&P1);

//-----------------------------------------------------------------------------------------------
	Player player = {0};
	player.position = (Vector2){400, 280};
	player.speed = 0;
	player.canJump = false;
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
	camera.target = player.position;
	camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Multiple camera
	void (*cameraUpdaters[])(Camera2D *, Player *, EnvItem *, int, float, int, int) = {
		UpdateCameraCenter};

	int cameraOption = 0;
	int cameraUpdatersLength = sizeof(cameraUpdaters) / sizeof(cameraUpdaters[0]);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())
	{
		if (i >= 60 || k != P1.ct)
			i = 0;
		k = P1.ct;
		float deltaTime = GetFrameTime();

		UpdatePlayer(&player, envItems, envItemsLength, deltaTime, &P1);

		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

		if (camera.zoom > 3.0f)
			camera.zoom = 3.0f;
		else if (camera.zoom < 0.25f)
			camera.zoom = 0.25f;

		if (IsKeyPressed(KEY_R))
		{
			camera.zoom = 1.0f;
			player.position = (Vector2){400, 280};
		}

		// if (IsKeyPressed(KEY_C))
		// 	cameraOption = (cameraOption + 1) % cameraUpdatersLength;

		// Update camera
		cameraUpdaters[cameraOption](&camera, &player, envItems, envItemsLength, deltaTime, screenWidth, screenHeight);

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		BeginMode2D(camera);

		for (int i = 0; i < envItemsLength; i++)
			DrawRectangleRec(envItems[i].rect, envItems[i].color);

		ftImgsGestion(&player, &P1, &i);

		// std::cout << P1.ct << std::endl;
		EndMode2D();

		DrawText("Controls:", 20, 20, 10, BLACK);
		DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
		DrawText("- Space to jump", 40, 60, 10, DARKGRAY);
		DrawText("- Mouse Wheel to Zoom in-out, R to reset zoom", 40, 80, 10, DARKGRAY);

		EndDrawing();
	}
	CloseWindow();
	//--------------------------------------------------------------------------------------
	return 0;
}

void	ftImgsGestion(Player *player, Ply1 *P1, int *i)
{
	player->position.x -= 25;
	if (P1->ct == 0 && P1->face == 0) // Idle right
	{
		player->position.y -= 100;
		DrawTextureEx(P1->p1_idle_ri[*i / 15], player->position, 0.0f, 2, WHITE);
		player->position.y += 100;
	}
	else if (P1->ct == 0 && P1->face == 1) // Idle left
	{
		player->position.y -= 100;
		DrawTextureEx(P1->p1_idle_lft[*i / 15], player->position, 0.0f, 2, WHITE);
		player->position.y += 100;
	}
	else if (P1->ct == 1 && P1->face == 0) // move right
	{
		player->position.y -= 95;
		DrawTextureEx(P1->p1_runRi[*i / 10], player->position, 0.0f, 2, WHITE);
		player->position.y += 95;
	}
	else if (P1->ct == 1 && P1->face == 1) // move lft
	{
		player->position.y -= 95;
		DrawTextureEx(P1->p1_runLft[*i / 10], player->position, 0.0f, 2, WHITE);
		player->position.y += 95;
	}
	else if (P1->ct == 4 && P1->face == 0) // Jump right
	{
		player->position.y -= 95;
		DrawTextureEx(P1->p1_jumpr[*i / 15], player->position, 0.0f, 2, WHITE);
		player->position.y += 95;
	}
	else if (P1->ct == 4 && P1->face == 1) // Jump left
	{
		player->position.y -= 95;
		DrawTextureEx(P1->p1_jumpl[*i / 15], player->position, 0.0f, 2, WHITE);
		player->position.y += 95;
	}
	else if (P1->ct == 5 && P1->face == 0) // Fall right
	{
		player->position.y -= 95;
		DrawTextureEx(P1->p1_fallr[0], player->position, 0.0f, 2, WHITE);
		player->position.y += 95;
	}
	else if (P1->ct == 5 && P1->face == 1) // Fall left
	{
		player->position.y -= 95;
		DrawTextureEx(P1->p1_falll[0], player->position, 0.0f, 2, WHITE);
		player->position.y += 95;
	}
	*i += 1;
	player->position.x += 25;
}

void	ftInitImgs(Ply1 *P1)
{
	P1->p1_idle_ri[0] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_00.png");
	P1->p1_idle_ri[1] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_01.png");
	P1->p1_idle_ri[2] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_02.png");
	P1->p1_idle_ri[3] = LoadTexture("./imgs/edward_elric/ed_idle_ri/ed_idleri_03.png");

	P1->p1_idle_lft[0] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_00.png");
	P1->p1_idle_lft[1] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_01.png");
	P1->p1_idle_lft[2] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_02.png");
	P1->p1_idle_lft[3] = LoadTexture("./imgs/edward_elric/ed_idle_lft/ed_idlelft_03.png");

	P1->p1_jumpr[0] = LoadTexture("./imgs/edward_elric/ed_jumplft/ed_jumpr_00.png");
	P1->p1_jumpr[1] = LoadTexture("./imgs/edward_elric/ed_jumplft/ed_jumpr_01.png");

	P1->p1_jumpl[0] = LoadTexture("./imgs/edward_elric/ed_jumpri/ed_jumpl_00.png");
	P1->p1_jumpl[1] = LoadTexture("./imgs/edward_elric/ed_jumpri/ed_jumpl_01.png");

	P1->p1_falll[0] = LoadTexture("./imgs/edward_elric/ed_falllft/ed_falll_00.png");
	P1->p1_falll[1] = LoadTexture("./imgs/edward_elric/ed_falllft/ed_falll_01.png");

	P1->p1_fallr[0] = LoadTexture("./imgs/edward_elric/ed_fallri/ed_fallr_00.png");
	P1->p1_fallr[1] = LoadTexture("./imgs/edward_elric/ed_fall/ed_fallr_01.png");

	P1->p1_runRi[0] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_00.png");
	P1->p1_runRi[1] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_01.png");
	P1->p1_runRi[2] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_02.png");
	P1->p1_runRi[3] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_03.png");
	P1->p1_runRi[4] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_04.png");
	P1->p1_runRi[5] = LoadTexture("./imgs/edward_elric/ed_run_right/ed_runr_05.png");

	P1->p1_runLft[0] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_00.png");
	P1->p1_runLft[1] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_01.png");
	P1->p1_runLft[2] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_02.png");
	P1->p1_runLft[3] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_03.png");
	P1->p1_runLft[4] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_04.png");
	P1->p1_runLft[5] = LoadTexture("./imgs/edward_elric/ed_run_lft/ed_runl_05.png");
}

void	ftKeyGestion(Player *player, Ply1 *P1, float delta)
{
	if (IsKeyDown(KEY_A))
	{
		if (P1->ct != 4 && P1->ct != 5)
			P1->ct = 1;
		P1->face = 1;
		player->position.x -= PLAYER_HOR_SPD * delta;
	}
	if (IsKeyDown(KEY_D))
	{
		if (P1->ct != 4 && P1->ct != 5)
			P1->ct = 1;
		P1->face = 0;
		player->position.x += PLAYER_HOR_SPD * delta;
	}
	if (IsKeyDown(KEY_SPACE) && player->canJump)
	{
		P1->ct = 4;
		player->speed = -PLAYER_JUMP_SPD;
		player->canJump = false;
	}
	if (IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D))
	{
		if (P1->ct != 4 && P1->ct != 5)		
			P1->ct = 0;
	}
}

void	UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta, Ply1 *P1)
{
	int		lastY;

	ftKeyGestion(player, P1, delta);
	int hitObstacle = 0;
	for (int i = 0; i < envItemsLength; i++)
	{
		EnvItem *ei = envItems + i;
		Vector2 *p = &(player->position);
		if (ei->blocking &&
			ei->rect.x <= p->x &&
			ei->rect.x + ei->rect.width >= p->x &&
			ei->rect.y >= p->y &&
			ei->rect.y <= p->y + player->speed * delta)
		{
			hitObstacle = 1;
			player->speed = 0.0f;
			p->y = ei->rect.y;
		}
	}

	if (!hitObstacle)
	{
		player->position.y += player->speed * delta;
		player->speed += G * delta;
		player->canJump = false;
	}
	else
		player->canJump = true;
		
	lastY = player->position.y;
	if (lastY < player->position.y)
	{
		P1->ct = 5;
	}
	else if (lastY == player->position.y && P1->ct == 5)
	{
		P1->ct = 0;
	}
}

void UpdateCameraCenter(Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height)
{
	camera->offset = (Vector2){width / 2.0f, height / 2.0f};
	camera->target = player->position;
}

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
}

void	ftInitImgs(Ply1 *P1)
{
	P1->p1_idle_ri[0] = LoadTexture("./imgs/edward_elric/idle_ri/ed_idle_00.png");
	P1->p1_idle_ri[1] = LoadTexture("./imgs/edward_elric/idle_ri/ed_idle_01.png");
	P1->p1_idle_ri[2] = LoadTexture("./imgs/edward_elric/idle_ri/ed_idle_02.png");
	P1->p1_idle_ri[3] = LoadTexture("./imgs/edward_elric/idle_ri/ed_idle_03.png");

	P1->p1_idle_lft[0] = LoadTexture("./imgs/edward_elric/idle_lft/ed_idle_00_.png");
	P1->p1_idle_lft[1] = LoadTexture("./imgs/edward_elric/idle_lft/ed_idle_01_.png");
	P1->p1_idle_lft[2] = LoadTexture("./imgs/edward_elric/idle_lft/ed_idle_02_.png");
	P1->p1_idle_lft[3] = LoadTexture("./imgs/edward_elric/idle_lft/ed_idle_03_.png");

	P1->p1_jumpr[0] = LoadTexture("./imgs/edward_elric/jump/ed_jumpr_00.png");
	P1->p1_jumpr[1] = LoadTexture("./imgs/edward_elric/jump/ed_jumpr_01.png");

	P1->p1_jumpl[0] = LoadTexture("./imgs/edward_elric/jump/ed_jumpl_00.png");
	P1->p1_jumpl[1] = LoadTexture("./imgs/edward_elric/jump/ed_jumpl_01.png");

	P1->p1_falll[0] = LoadTexture("./imgs/edward_elric/fall/ed_falll_00.png");
	P1->p1_falll[1] = LoadTexture("./imgs/edward_elric/fall/ed_falll_01.png");

	P1->p1_fallr[0] = LoadTexture("./imgs/edward_elric/fall/ed_fallr_00.png");
	P1->p1_fallr[1] = LoadTexture("./imgs/edward_elric/fall/ed_fallr_01.png");

	P1->p1_runRi[0] = LoadTexture("./imgs/edward_elric/run_right/ed_runr_00.png");
	P1->p1_runRi[1] = LoadTexture("./imgs/edward_elric/run_right/ed_runr_01.png");
	P1->p1_runRi[2] = LoadTexture("./imgs/edward_elric/run_right/ed_runr_02.png");
	P1->p1_runRi[3] = LoadTexture("./imgs/edward_elric/run_right/ed_runr_03.png");
	P1->p1_runRi[4] = LoadTexture("./imgs/edward_elric/run_right/ed_runr_04.png");
	P1->p1_runRi[5] = LoadTexture("./imgs/edward_elric/run_right/ed_runr_05.png");

	P1->p1_runLft[0] = LoadTexture("./imgs/edward_elric/run_lft/ed_runl_00.png");
	P1->p1_runLft[1] = LoadTexture("./imgs/edward_elric/run_lft/ed_runl_01.png");
	P1->p1_runLft[2] = LoadTexture("./imgs/edward_elric/run_lft/ed_runl_02.png");
	P1->p1_runLft[3] = LoadTexture("./imgs/edward_elric/run_lft/ed_runl_03.png");
	P1->p1_runLft[4] = LoadTexture("./imgs/edward_elric/run_lft/ed_runl_04.png");
	P1->p1_runLft[5] = LoadTexture("./imgs/edward_elric/run_lft/ed_runl_05.png");
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

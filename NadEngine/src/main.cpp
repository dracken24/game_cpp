#include "../myIncludes/class2D/player.hpp"
#include "../myIncludes/class2D/menu.hpp"
#include "../myIncludes/class2D/props.hpp"
#include "../myIncludes/game.hpp"

//**************************************************************************************************//
//																									//
//**************************************************************************************************//

void	ftBigMenuControl(Menu *menu)
{
	DrawText("Welcome to NadEngine", 535, 200, 40, BLACK);
	DrawText("For 2D engine, press  2 ", 535, 300, 20, DARKGRAY);
	DrawText("For 3D engine, press  3 ", 535, 350, 20, DARKGRAY);
	if (IsKeyPressed(KEY_TWO))
	{
		menu->ftChangeStart(9);
	}
	else if (IsKeyPressed(KEY_THREE))
	{
		menu->ftChangeStart(8);
	}
}

int main(void)
{
	Game	Game;
	Menu	menu;

	InitWindow(Game.screenWidth, Game.screenHeight, "BANKAI");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		if (menu.ftReturnStart() == 10)
		{
			ftBigMenuControl(&menu);
		}
		if (menu.ftReturnStart() == 9)
		{
			menu.ftChangeStart(0);
			ftMode2D(&Game, &menu);
			menu.ftChangeStart(10);
		}
		if (menu.ftReturnStart() == 8)
		{
			ftMode3D();
			menu.ftChangeStart(10);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

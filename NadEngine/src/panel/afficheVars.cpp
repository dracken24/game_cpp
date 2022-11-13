#include "../../myIncludes/game.hpp"

//** Select Box **//              Collision Box   /    Visual Box     /                / Affichable / Variable Struct
void    ftSelectBox(Game *Game, Rectangle textBox1, Rectangle textBox2, Vector2 posText, char *name, char *varName)
{
	// static Rectangle textBox1;
	static bool mouseOnText = false;
	static int letterCount;
	static int framesCounter;
	if (!letterCount || !framesCounter)
	{
		letterCount = 0;
		framesCounter = 0;
	}
	// textBox = {1320, 70, 100, 20};
	if (CheckCollisionPointRec(Game->mouse.pos, textBox1))
		mouseOnText = true;
	else
		mouseOnText = false;
	if (mouseOnText)
	{
		// Set the window's cursor to the Box
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		while (key > 0)
		{
			if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
			{
				varName[letterCount] = (char)key;
				varName[letterCount + 1] = '\0';
				letterCount++;
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			letterCount--;
			if (letterCount < 0)
				letterCount = 0;
            varName[letterCount] = '\0';
        }
	}
	else
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	if (mouseOnText)
		framesCounter++;

	// Draw on screen
	// textBox2 = {125, 36, 100, 20};
    DrawText(name, posText.x, posText.y, 14, LIGHTGRAY);
    DrawRectangleRec(textBox2, LIGHTGRAY);
	if (mouseOnText)
		DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, RED);
	else
		DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, LIGHTGRAY);
    DrawText(varName, (int)textBox2.x + 5, (int)textBox2.y + 4, 14, MAROON);
    if (mouseOnText)
	{
		if (letterCount < MAX_INPUT_CHARS)
		{
			// Draw blinking underscore char
			if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int)textBox2.x + MeasureText(varName, 14), (int)textBox2.y + 12, 14, MAROON);
        }
	}
}

//*** Draw variables on side right down panel ***//
void	ftDrawVarsRiDownPanel(Game *game)
{
	if (game->selected2D.type == 1) // Player selected
	{
        VarChar     *varsPlayer = game->selected2D.player->ftReturnVarsChar();
        Rectangle   rec = game->selected2D.player->ftReturnCollisionBox();
        // char *tmp = ft_ftoa(rec.x, 0);
        // varsPlayer->plyPosX = tmp;
        // DrawTextEx(game->font1, "Pos X:", {10, 10}, 14, 1, BLACK);
        ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsPlayer->plyPosX);
        ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsPlayer->plyPosX);
    }
}
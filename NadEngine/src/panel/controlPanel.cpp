#include "../../myIncludes/game.hpp"

char	*ft_ftoa(float f, int *status)
{
	static char buf[17];
	char *cp = buf;
	unsigned long l, rem;

	if (f < 0)
	{
		*cp++ = '-';
		f = -f;
	}
	l = (unsigned long)f;
	f -= (float)l;
	rem = (unsigned long)(f * 1e6);
	sprintf(cp, "%lu.%6.6lu", l, rem);
	return (buf);
}

void	ftMousePos(Game *Game)
{
	char *ret;
	static Vector2 lastPos;
	Game->mouse.pos = GetMousePosition();

	if (Game->mouse.pos.x >= 0 && Game->mouse.pos.x <= Game->screenWidth && Game->mouse.pos.y >= 0 && Game->mouse.pos.y <= Game->screenHeight)
	{
		ret = ft_ftoa(Game->mouse.pos.x, 0);
		DrawText("Mouse pos X:", 10, 10, 14, LIGHTGRAY);
		DrawText(ret, 110, 10, 12, LIGHTGRAY);

		ret = ft_ftoa(Game->mouse.pos.y, 0);
		DrawText("Y:", 190, 10, 14, LIGHTGRAY);
		DrawText(ret, 210, 10, 12, LIGHTGRAY);

		lastPos = Game->mouse.pos;
	}
	else
	{
		ret = ft_ftoa(lastPos.x, 0);
		DrawText("Mouse pos X:", 10, 10, 14, LIGHTGRAY);
		DrawText(ret, 110, 10, 12, LIGHTGRAY);

		ret = ft_ftoa(lastPos.y, 0);
		DrawText("Y:", 190, 10, 14, LIGHTGRAY);
		DrawText(ret, 210, 10, 12, LIGHTGRAY);
	}
}


void	ftMouseControl(Game *Game)
{
	ftMousePos(Game);

//--------------------------------------------------------------------------------------//
//** Select Box **//

	static Rectangle textBox1;
	static bool mouseOnText = false;
	static int letterCount;
	static int framesCounter;
	if (!letterCount || !framesCounter)
	{
		letterCount = 0;
		framesCounter = 0;
	}
	textBox1 = {1320, 70, 100, 20};
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
				Game->rotation[letterCount] = (char)key;
				Game->rotation[letterCount + 1] = '\0';
				letterCount++;
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			letterCount--;
			if (letterCount < 0)
				letterCount = 0;
			Game->rotation[letterCount] = '\0';
		}
	}
	else
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	if (mouseOnText)
		framesCounter++;

	// Draw on screen
	textBox1 = {125, 36, 100, 20};
	DrawText("Blocks Rotation:", 10, 40, 14, LIGHTGRAY);
	DrawRectangleRec(textBox1, LIGHTGRAY);
	if (mouseOnText)
		DrawRectangleLines((int)textBox1.x, (int)textBox1.y, (int)textBox1.width, (int)textBox1.height, RED);
	else
		DrawRectangleLines((int)textBox1.x, (int)textBox1.y, (int)textBox1.width, (int)textBox1.height, LIGHTGRAY);
	DrawText(Game->rotation, (int)textBox1.x + 5 , (int)textBox1.y + 4, 14, MAROON);
	if (mouseOnText)
	{
		if (letterCount < MAX_INPUT_CHARS)
		{
			// Draw blinking underscore char
			if (((framesCounter / 20) % 2) == 0)
				DrawText("_", (int)textBox1.x + MeasureText(Game->rotation, 14), (int)textBox1.y + 12, 14, MAROON);
		}
	}
}

void	ftSideUpMenu2D(Game *Game, Player *player, Menu *menu)
{
	ftMouseControl(Game);
}

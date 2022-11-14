#include "../../myIncludes/game.hpp"

//** Select Box **//              Collision Box   /    Visual Box     /               / Affichable/ Variable Struct/ Nbr to put
void    ftSelectBox(Game *Game, Rectangle textBox1, Rectangle textBox2, Vector2 posText, char *name, char *varName, char *nbr, int ct)
{
	// static Rectangle textBox1;
	static bool mouseOnText[512];
	static int 	letterCount[512];
	static int 	framesCounter[512];
	char 		*plyPosX[512];

	// static char tmpText[512][MAX_INPUT_CHARS + 1];

	// tmpText[ct][MAX_INPUT_CHARS + 1] = '\0';
	// // YYYYYYYEEEESSSSSSSSSS //
	// if (!name && !varName && !nbr)
	// {
	// 	// std::cout << "NO" << std::endl;
	// 	tmpText[0][0] = '\0';
	// 	letterCount[0] = 0;
	// 	return;
	// }

	mouseOnText[ct] = false;
	if (!letterCount[ct] || !framesCounter[ct])
	{
		letterCount[ct] = 0;
		framesCounter[ct] = 0;
	}

	if (CheckCollisionPointRec(Game->mouse.pos, textBox1))
		mouseOnText[ct] = true;
	else
		mouseOnText[ct] = false;
	if (mouseOnText[ct])
	{
		// Set the window's cursor to the Box
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();
		while (key > 0)
		{
			if ((key >= 32) && (key <= 125) && (letterCount[ct] < MAX_INPUT_CHAR))
			{
				varName[letterCount[ct]] = (char)key;
				varName[letterCount[ct] + 1] = '\0';
				letterCount[ct]++;
			}
			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE))
		{
			letterCount[ct]--;
			if (letterCount[ct] < 0)
				letterCount[ct] = 0;
			varName[letterCount[ct]] = '\0';
		}
	}
	else
	{
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	}
	if (mouseOnText[ct])
		framesCounter[ct]++;

	// Draw on screen
	DrawText(name, posText.x, posText.y, 14, LIGHTGRAY);
	DrawRectangleRec(textBox2, LIGHTGRAY);
	if (mouseOnText[ct])
		DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, RED);
	else
		DrawRectangleLines((int)textBox2.x, (int)textBox2.y, (int)textBox2.width, (int)textBox2.height, LIGHTGRAY);
	DrawText(varName, (int)textBox2.x + 5, (int)textBox2.y + 4, 14, MAROON);
	if (mouseOnText[ct])
	{
		if (letterCount[ct] < MAX_INPUT_CHARS)
		{
			if (((framesCounter[ct] / 20) % 2) == 0)
				DrawText("_", (int)textBox2.x + MeasureText(varName, 14), (int)textBox2.y + 12, 14, MAROON);
		}
	}
	else if (varName[0] == '\0')
	{
		DrawText(nbr, (int)textBox2.x + MeasureText(varName, 14) + 2, (int)textBox2.y + 4, 14, MAROON);
	}
}

//*** Draw variables on side right down panel ***//
void	ftDrawVarsRiDownPanel(Game *game)
{
	int nbr = game->selected2D.nbr;

	if (game->selected2D.type == 1) // Player selected
	{
		VarChar     *varsPlayer = game->selected2D.player->ftReturnVarsChar();
		Rectangle   recPlayer = game->selected2D.player->ftReturnCollisionBox();

		char *tmp = ft_ftoa(recPlayer.x, 0);
		ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsPlayer->plyPosX, tmp, 0 + nbr);
		tmp = ft_ftoa(recPlayer.y, 0);
		ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsPlayer->plyPosY, tmp, 25 + nbr);
		tmp = ft_ftoa(recPlayer.width, 0);
		ftSelectBox(game, {1260, 347, 75, 20}, {60, 40, 75, 20}, {10, 44}, "Width:", varsPlayer->plyWidth, tmp, 50 + nbr);
		tmp = ft_ftoa(recPlayer.height, 0);
		ftSelectBox(game, {1400, 347, 75, 20}, {200, 40, 75, 20}, {150, 44}, "Height:", varsPlayer->plyHeight, tmp, 75 + nbr);
	}
	else if (game->selected2D.type == 2) // Items Blocks Props
	{
		VarCharPr	*varsProp = game->selected2D.prop->ftReturnVarsProp();
		Rectangle   recProp = game->selected2D.prop->ftReturnRectangle();

		char *tmp = ft_ftoa(recProp.x, 0);
		ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsProp->propPosX, tmp, 100 + nbr);
		tmp = ft_ftoa(recProp.y, 0);
		ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsProp->propPosY, tmp, 150 + nbr);
	}
	else if (game->selected2D.type == 3) // Platforms
	{
		VarCharEnvi	*varsEnvi = &game->selected2D.item->_varCharEnvi;
		Rectangle   recEnvi = game->selected2D.item->rect;

		char *tmp = ft_ftoa(recEnvi.x, 0);
		ftSelectBox(game, {1260, 317, 75, 20}, {60, 10, 75, 20}, {10, 14}, "Pos X:", varsEnvi->enviPosX, tmp, 200 + nbr);
		tmp = ft_ftoa(recEnvi.y, 0);
		ftSelectBox(game, {1400, 317, 75, 20}, {200, 10, 75, 20}, {150, 14}, "Pos Y:", varsEnvi->enviPosY, tmp, 250 + nbr);
	}
}